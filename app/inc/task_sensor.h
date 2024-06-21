#ifndef __SENSOR_H
#define __SENSOR_H

/* TMOS��Ϣ�¼����� */
#define SENSOR_RESULT_EVENT 0x77 //��������ֵ�����¼�
#define ADC_RESULT_EVENT 0x78 //��ص�ѹ�����¼�

#include "CH57xBLE_LIB.h"
#include "CH57x_common.h"

typedef struct {
    tmos_event_hdr_t hdr;
    int16_t temp;
    int16_t humid;
} sensor_event_data_t;

void sensor_task_init();

#endif
