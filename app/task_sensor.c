#include "task_sensor.h"

#include "bsp_config.h"
#include "bsp_sht3x.h"
#include "bsp_led_key.h"
#include "task_broadcaster.h"

/* TMOS�¼����� */
#define SENSOR_FINISH_EVENT 0x01 //������ת������¼�
#define SENSOR_TRIGGER_EVENT 0x02 //��������ֵ��ʱ�����¼�
#define ADC_TRIGGER_EVENT 0x04 //��ص�ѹADCת����ʱ�����¼�

tmosTaskID sensor_task_id;
static int16_t adc_calib_offset;

void adc_init()
{
    /* ���ò���Ƶ�������� */
    ADC_InterBATSampInit(); //ʵ�ʲ���Ƶ����Ҫ����Լ18: 3.2MHz/18=178kHz��-12dB(1/4)����
    /* ����ADC�ֵ�ƫ��ֵ */
    adc_calib_offset = ADC_DataCalib_Rough();
    /* �ر�ADC��Դ */
    // R8_ADC_CFG &= ~RB_ADC_POWER_ON;
}

void adc_update()
{
    ADC_InterBATSampInit();

    uint16_t adc_val = ADC_ExcutSingleConver() + adc_calib_offset;
    float voltage = (((float)adc_val)/512 - 3) * 1.06; //-12dB(1/4��)

    /* ������Ϣ�ڴ� */
    tmos_event_hdr_t *pmsg = (tmos_event_hdr_t *)tmos_msg_allocate(sizeof(tmos_event_hdr_t));
    /* ��Ϣͷ��ָ����Ϣ����Ϊ������������Ϣ */
    pmsg->event = ADC_RESULT_EVENT; //��ص�ѹ�����¼�
    pmsg->status = 100*(voltage-2); //(��ص�ѹ-2V)��100��

    tmos_msg_send(broadcaster_task_id, (uint8_t*)pmsg);
    tmos_start_task(sensor_task_id, ADC_TRIGGER_EVENT, MS1_TO_SYSTEM_TIME(ADC_UPDATE_PERIOD*1000)); //һ��ʱ��������һ��ADCת��
}

void sensor_trigger()
{
    /* ����������ת�� */
    sht3x_trigger(sht3x_conversion_period_medium);
    /* ����ת������¼���ʱ�� */
    tmos_start_task(sensor_task_id, SENSOR_FINISH_EVENT, MS1_TO_SYSTEM_TIME(10));
}

void sensor_update()
{
    /* ������Ϣ�ڴ� */
    sensor_event_data_t *pmsg = (sensor_event_data_t *)tmos_msg_allocate(sizeof(sensor_event_data_t));
    /* ��Ϣͷ��ָ����Ϣ����Ϊ������������Ϣ */
    pmsg->hdr.event = SENSOR_RESULT_EVENT; //��������ֵ�����¼�
    pmsg->hdr.status = 0;
    /* ȡ�ش��������� */
    sht3x_fetch(&(pmsg->temp), &(pmsg->humid));
    tmos_msg_send(broadcaster_task_id, (uint8_t *)pmsg);
}

uint16_t sensor_event_handler(uint8_t task_id, uint16_t events)
{
    if(events & SYS_EVENT_MSG) //��ϵͳ��Ϣ
    {
        uint8_t *pMsg = tmos_msg_receive(sensor_task_id);

        if (pMsg != NULL) {
            //δ�������Ϣ�¼��Ĵ���
            tmos_msg_deallocate(pMsg); //�ͷ���Ϣ
        }

        return events ^ SYS_EVENT_MSG;
    }

    if(events & SENSOR_TRIGGER_EVENT) //���������´����¼�
    {
        /* �������������� */
        sensor_trigger();

        return events ^ SENSOR_TRIGGER_EVENT;
    }

    if(events & ADC_TRIGGER_EVENT) //ADCת�������¼�
    {
        /* ����ADCת�� */
        adc_update();

        return events ^ ADC_TRIGGER_EVENT;
    }

    if(events & SENSOR_FINISH_EVENT) //������ת������¼�
    {
        /* һ�����ں�ִ����һ�δ��������²��� */
        tmos_start_task(sensor_task_id, SENSOR_TRIGGER_EVENT, MS1_TO_SYSTEM_TIME(SENSOR_UPDATE_PERIOD*1000));
        /* ���´��������� */
        sensor_update();

        return events ^ SENSOR_FINISH_EVENT;
    }
    
    return 0; //������δ֪�¼�
}

void sensor_task_init()
{
    sensor_task_id = TMOS_ProcessEventRegister(sensor_event_handler);

    sht3x_init();
    adc_init();
    tmos_set_event(sensor_task_id, SENSOR_TRIGGER_EVENT); //����ִ��һ�δ�������ֵ���²���
    tmos_start_task(sensor_task_id, ADC_TRIGGER_EVENT, MS1_TO_SYSTEM_TIME(800)); //����ִ��һ��ADCת������
}
