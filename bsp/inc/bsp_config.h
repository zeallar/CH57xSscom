#ifndef __BSP_CONFIG_H
#define __BSP_CONFIG_H

#define	ID_CH573							0x73
#define CHIP_ID								ID_CH573

/*********************************************************************
 ��MAC��
 BLE_MAC											- �Ƿ��Զ�������Mac��ַ ( Ĭ��:FALSE - ʹ��оƬMac��ַ )����Ҫ��main.c�޸�Mac��ַ����

 ��DCDC��
 DCDC_ENABLE                  - �Ƿ�ʹ��DCDC ( Ĭ��:FALSE )

 ��SLEEP��
 HAL_SLEEP   									- �Ƿ���˯�߹��� ( Ĭ��:FALSE )
 WAKE_UP_RTC_MAX_TIME					- �ȴ�32M�����ȶ�ʱ�䣬���ݲ�ͬ˯������ȡֵ�ɷ�Ϊ�� ˯��ģʽ/�µ�ģʽ         -	45(Ĭ��)
                                                                                                                                                                                        ��ͣģʽ					-	45
                                                                                                                                                                                        ����ģʽ					-	5
 
 ��TEMPERATION��
 TEM_SAMPLE										- �Ƿ�򿪸����¶ȱ仯У׼�Ĺ��ܣ�����У׼��ʱС��10ms( Ĭ��:TRUE )
 
 ��CALIBRATION��
 BLE_CALIBRATION_ENABLE				- �Ƿ�򿪶�ʱУ׼�Ĺ��ܣ�����У׼��ʱС��10ms( Ĭ��:TRUE )
 BLE_CALIBRATION_PERIOD				- ��ʱУ׼�����ڣ���λms( Ĭ��:120000 ) 
 
 ��SNV��
 BLE_SNV    				          - �Ƿ���SNV���ܣ����ڴ������Ϣ( Ĭ��:TRUE )
 BLE_SNV_ADDR    					    - SNV��Ϣ�����ַ��ʹ��data flash���( Ĭ��:0x77E00 )

 ��RTC��
 CLK_OSC32K										- RTCʱ��ѡ�������������ɫ����ʹ���ⲿ32K( Ĭ��:0 �ⲿ(32768Hz)��1���ڲ�(32000Hz)��2���ڲ�(32768Hz) )

 ��MEMORY��
 BLE_MEMHEAP_SIZE  						- ����Э��ջʹ�õ�RAM��С����С��6K ( Ĭ��:(1024*6) )

 ��DATA��
 BLE_BUFF_MAX_LEN							- ����������������( Ĭ��:27 (ATT_MTU=23)��ȡֵ��Χ[27~251] )
 BLE_BUFF_NUM									- ����������İ�����( Ĭ��:5 )
 BLE_TX_NUM_EVENT							- ���������¼������Է����ٸ����ݰ�( Ĭ��:1 )
 BLE_TX_POWER									- ���书��( Ĭ��:LL_TX_POWEER_0_DBM (0dBm) )
 
 ��MULTICONN��
 PERIPHERAL_MAX_CONNECTION	  - ����ͬʱ�����ٴӻ���ɫ( Ĭ��:1 )
 CENTRAL_MAX_CONNECTION				- ����ͬʱ������������ɫ( Ĭ��:3 )
 **********************************************************************/

/*********************************************************************
 * Ĭ������ֵ
 */

/* �Ƿ���DC-DC����ҪӲ����·֧�� */
#define DCDC_ENABLE TRUE

/* �Ƿ����õ͹���˯�߹��ܣ�ʹ�ܺ��޷����� */
#define HAL_SLEEP TRUE

/* RTCʱ��ѡ�������������ɫ����ʹ���ⲿ32K��0���ⲿ(32768Hz)��1���ڲ�(32000Hz)��2���ڲ�(32768Hz) */
#define CLK_OSC32K  0

/* BLEЭ��ջ�ڴ��С */
#define BLE_MEM_POOL_SIZE (1024*6)

/* ������������ڣ���λΪ�� */
#define SENSOR_UPDATE_PERIOD 60

/* ��ص�ѹ������ڣ���λΪ�� */
#define ADC_UPDATE_PERIOD 60*30 //0.5h

/* �����㲥���ڣ���λΪ�� */
#define BLE_ADVERTISE_PERIOD 2

/* У׼������Ƶ���ڣ���λΪ�� */
#define BLE_CALIBRATION_PERIOD 300

/* �������书�� */
#define BLE_TX_POWER LL_TX_POWEER_0_DBM

#define WAKE_UP_RTC_MAX_TIME				45


#ifndef BLE_BUFF_MAX_LEN
#define BLE_BUFF_MAX_LEN						27
#endif
#ifndef BLE_BUFF_NUM
#define BLE_BUFF_NUM								5
#endif
#ifndef BLE_TX_NUM_EVENT
#define BLE_TX_NUM_EVENT						1
#endif


#ifndef PERIPHERAL_MAX_CONNECTION
#define PERIPHERAL_MAX_CONNECTION		1
#endif
#ifndef CENTRAL_MAX_CONNECTION
#define CENTRAL_MAX_CONNECTION			3
#endif

#endif

/******************************* endfile @ config ******************************/
