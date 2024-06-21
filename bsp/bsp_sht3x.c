#include "bsp_sht3x.h"

#include "bsp_sw_i2c.h"

/* CRC�����ɶ���ʽ */
#define POLYNOMIAL 0x131 // P(x) = x^8 + x^5 + x^4 + 1 = 100110001

/**
 * @brief ʹ�ø�������ʽ����CRC8
 *
 * @param data ��������
 * @param len �������ݳ���
 * @return uint8_t CRC8У��ֵ
 */
static uint8_t sht3x_cal_crc(uint8_t *data, uint8_t len)
{
    uint8_t crc = 0xFF;

    for (uint8_t i = 0; i < len; i++) {
        crc ^= (data[i]);
        for (uint8_t bit = 8; bit > 0; --bit) {
            if (crc & 0x80) {
                crc = (crc << 1) ^ POLYNOMIAL;
            } else {
                crc = (crc << 1);
            }
        }
    }

    return crc;
}

/**
 * @brief �Խ��յ������ݽ���CRC8У��
 *
 * @param data ���յ������ݻ�����
 * @param len ���յ������ݳ���
 * @return uint8_t 0 ��ȡ�ɹ�
 *                 1 CRCУ��ʧ��
 *                 2 �������ݳ��Ȳ���3�ı���������Ϊ��
 */
static uint8_t sht3x_check_crc(uint8_t *data, uint8_t len)
{
    /* ����������ݳ����Ƿ�Ϊ3�������� ���Ƿ�Ϊ16λ����+8λCRCУ�� */
    if (len % 3 || len == 0) {
        return 2;
    }

    for (int i = 0; i < len; i += 3) {
        uint8_t crc = sht3x_cal_crc(data + i, 2);
        if (crc != data[i + 2]) {
            return 1;
        }
    }

    return 0;
}

/**
 * @brief ͨ��I2C������SHT3x�ļĴ���д������
 *
 * @param reg �Ĵ�����ַ
 * @return uint8_t 0 д��ɹ�
 *                 1 ͨѶʧ��
 */
static uint8_t sht3x_i2c_write_reg(uint16_t reg)
{
    i2c_start();
    if (i2c_write_byte((SHT3X_I2C_ADDR << 1) | 0)) {
        goto exit;
    }

    if (i2c_write_byte((reg >> 8) | 0)) {
        goto exit;
    }
    if (i2c_write_byte((reg & 0xFF) | 0)) {
        goto exit;
    }

    i2c_stop();
    return 0;

exit:
    i2c_stop();
    return 1;
}

/**
 * @brief ͨ��I2C���ߴ�SHT3x��ȡ����
 *
 * @param buf �洢��ȡ�����ݵĻ�����
 * @param len Ҫ��ȡ���ݵĳ���
 * @return uint8_t 0 ��ȡ�ɹ�
 *                 1 CRCУ��ʧ��
 *                 2 ͨ��ʧ��
 */
static uint8_t sht3x_i2c_read(uint8_t *buf, uint8_t len)
{
    i2c_start();
    if (i2c_write_byte((SHT3X_I2C_ADDR << 1) | 1)) {
        i2c_stop();
        return 2;
    }

    for (uint8_t i = 0; i < len - 1; i++) {
        buf[i] = i2c_read_byte(1); // ACK
    }
    buf[len - 1] = i2c_read_byte(0); // NAK

    i2c_stop();

    if (sht3x_check_crc(buf, len)) {
        return 1;
    }

    return 0;
}

/**
 * @brief �����¶�
 *
 * @param raw �¶ȼĴ���ԭʼֵ
 * @return int16_t �����¶ȵ�100��
 */
static int16_t sht3x_calc_temp(uint16_t raw) { return 17500l * (int32_t)raw / 65535 - 4500; }

/**
 * @brief �������ʪ��
 *
 * @param raw ʪ�ȼĴ���ԭʼֵ
 * @return uint16_t ���ʪ�ȵ�100��
 */
static int16_t sht3x_calc_humid(uint16_t raw) { return 10000l * (int32_t)raw / 65535; }

/**
 * @brief ��λSHT3x
 *
 * @return uint8_t 0 ��λ�ɹ�
 *                 1 ��λʧ��
 */
static uint8_t sht3x_soft_reset()
{
    /* д����λ�Ĵ��� */
    uint8_t error = sht3x_i2c_write_reg(0x30A2);

    if (error != 0) {
        PRINT("error while resetting sht3x\r\n"); //��λʧ��
    } else {
        // DelayMs(50); //��λ�ɹ�����ʱ50ms
    }

    return error;
}

/**
 * @brief ��ʼ��SHT3x
 *
 * @return uint8_t 0 ��ʼ���ɹ�
 *                 1 ��ʼ��ʧ��
 */
uint8_t sht3x_init()
{
    i2c_init();

    /* ��λSHT3x �����SHT3x�Ƿ���� */
    uint8_t error = sht3x_soft_reset();
    if (error != 0) {
        PRINT("error while initializing sht3x\r\n");
        return error;
    }

    PRINT("sht3x initialized\r\n");
    return error;
}

/**
 * @brief д��ת�����ڲ�����ת����ת������Խ�����ܺ�Խ�ߣ�������Խ�͡�
 * 
 * @param period ת������ѡ��
 * @return uint8_t 0 ��ȡ�ɹ�
 *                 1 ��ȡʧ��
 */
uint8_t sht3x_trigger(sht3x_conversion_period_t period)
{
    uint8_t error = sht3x_i2c_write_reg(period); 
    if (error != 0) {
        PRINT("sht3x error while starting measurement\r\n");
    }
}

/**
 * @brief ��SHT3x��ȡ��ʪ��
 *
 * @param temp [out]�¶�
 * @param humid [out]�¶�
 * @return uint8_t 0 ��ȡ�ɹ�
 *                 1 ��ȡʧ��
 */
uint8_t sht3x_fetch(int16_t *temp, int16_t *humid)
{
    uint8_t result_buf[6];

    /* ��ȡ��У�� */
    uint8_t error = sht3x_i2c_read(result_buf, sizeof(result_buf));

    if (error == 0) {
        /* �����¶���ʪ�� */
        *temp = sht3x_calc_temp(result_buf[0] << 8 | result_buf[1]);
        *humid = sht3x_calc_humid(result_buf[3] << 8 | result_buf[4]);
    } else if (error == 1) {
        PRINT("sht3x crc check error\r\n");
    } else if (error == 2) {
        PRINT("sht3x communication error\r\n");
    }

    return error;
}
