#include "task_broadcaster.h"

#include "bsp_config.h"
#include "bsp_led_key.h"
#include "task_sensor.h"

tmosTaskID broadcaster_task_id; //tmos����ID
/* �㲥���� */
static uint8_t conf_advertising_enable = FALSE;                  //���ù㲥
static uint8_t conf_adv_event_type = GAP_ADTYPE_ADV_NONCONN_IND; //��������
static uint16_t conf_adv_intervel = MS1_TO_SYSTEM_TIME(BLE_ADVERTISE_PERIOD*1000); //�㲥������ã�ʵ������Ϊ��ֵ*625us

/* �㲥���� ���31�ֽ� */
static uint8_t advertising_data[30] = {
    2,                                                               //�ֶγ���
    GAP_ADTYPE_FLAGS,                                                //�������Ա�־λ
    GAP_ADTYPE_FLAGS_BREDR_NOT_SUPPORTED | GAP_ADTYPE_FLAGS_GENERAL, //��֧��BR/EDR��General discoverable

    13,
    GAP_ADTYPE_LOCAL_NAME_COMPLETE, //�豸����
    'C', 'H', '5', '7', '3', '-', 'S', 'e', 'n', 's', 'o', 'r',

    12,
    GAP_ADTYPE_MANUFACTURER_SPECIFIC, //�����Զ�������
    'Y', 'Z', //����ID
    0x00, 0x02, 0x00, 0x00, 0x12, 0x00, 0x00, 0x21, 0x00
};

void broadcaster_gap_event_handler(gapRoleEvent_t *pmsg)
{
    /* �����㲥 */
    conf_advertising_enable = TRUE;
    GAPRole_SetParameter(GAPROLE_ADVERT_ENABLED, sizeof(uint8_t), &conf_advertising_enable);
}

void broadcaster_sensor_event_handler(sensor_event_data_t *pmsg)
{
    int16_t temp, humid;

    temp = ((sensor_event_data_t*)pmsg)->temp;
    humid = ((sensor_event_data_t*)pmsg)->humid;
    /* �ڸ��¹㲥����ǰ�رչ㲥 */
    conf_advertising_enable = FALSE;
    GAPRole_SetParameter(GAPROLE_ADVERT_ENABLED, sizeof(uint8_t), &conf_advertising_enable);

    /* �����µĴ��������� */
    advertising_data[23] = temp & 0xFF;
    advertising_data[24] = temp >> 8;
    advertising_data[26] = humid & 0xFF;
    advertising_data[27] = humid >> 8;
    /* ���¹㲥���� */
    bStatus_t error = GAP_UpdateAdvertisingData(
        broadcaster_task_id, TRUE, sizeof(advertising_data), advertising_data);
}

void broadcaster_adc_event_handler(tmos_event_hdr_t *pmsg)
{
    /* �ڸ��¹㲥����ǰ�رչ㲥 */
    conf_advertising_enable = FALSE;
    GAPRole_SetParameter(GAPROLE_ADVERT_ENABLED, sizeof(uint8_t), &conf_advertising_enable);

    advertising_data[29] = pmsg->status; //���µ�ص�ѹ��ֵ

    /* ���¹㲥���� */
    bStatus_t error = GAP_UpdateAdvertisingData(
        broadcaster_task_id, TRUE, sizeof(advertising_data), advertising_data);
}

uint16_t broadcaster_event_handler(uint8_t task_id, uint16_t events)
{
    if (events & SYS_EVENT_MSG) {
        uint8_t *pmsg = tmos_msg_receive(broadcaster_task_id);

        if (pmsg != NULL) {
            /* ������Ϣͷ����ͬ����Ϣ */
            switch (((tmos_event_hdr_t *)pmsg)->event) {
            case SENSOR_RESULT_EVENT: //��������ֵ�����¼�
                broadcaster_sensor_event_handler((sensor_event_data_t*)pmsg);
                break;

            case ADC_RESULT_EVENT: //ADC���������¼�
                broadcaster_adc_event_handler((tmos_event_hdr_t*)pmsg);
                break;

            case GAP_MSG_EVENT: //BLE GAP�¼�
                broadcaster_gap_event_handler((gapRoleEvent_t*)pmsg);
                break;

            default:
                break;
            }

            tmos_msg_deallocate(pmsg); //�ͷ���Ϣ
        }
        return events ^ SYS_EVENT_MSG;
    }
    return 0;
}

static void Broadcaster_StateNotificationCB(gapRole_States_t newState)
{
    switch (newState) {
    case GAPROLE_STARTED:
        PRINT("GAP started\r\n");
        break;

    case GAPROLE_ADVERTISING:
        PRINT("GAP advertising...\r\n");
        break;

    case GAPROLE_WAITING:
        PRINT("GAP waiting for advertising...\r\n");
        break;

    case GAPROLE_ERROR:
        PRINT("GAP error\r\n");
        break;

    default:
        break;
    }
}
static gapRolesBroadcasterCBs_t broadcaster_cbs = {Broadcaster_StateNotificationCB, NULL};

void broadcaster_task_init()
{
    /* ע��㲥���� */
    broadcaster_task_id = TMOS_ProcessEventRegister(broadcaster_event_handler); //ע���¼�������

    /* ����GAP��ɫ����  */
    GAPRole_SetParameter(GAPROLE_ADVERT_ENABLED, sizeof(uint8_t), &conf_advertising_enable); //�㲥����
    GAPRole_SetParameter(GAPROLE_ADV_EVENT_TYPE, sizeof(uint8_t), &conf_adv_event_type);     //�㲥ģʽ
    GAP_SetParamValue(TGAP_DISC_ADV_INT_MIN, conf_adv_intervel);
    GAP_SetParamValue(TGAP_DISC_ADV_INT_MAX, conf_adv_intervel); //��С�����㲥���
    /* ���ù㲥���� */
    GAPRole_SetParameter(GAPROLE_ADVERT_DATA, sizeof(advertising_data), advertising_data);

    /* ����Broadcaster */
    GAPRole_BroadcasterStartDevice(&broadcaster_cbs);
}
