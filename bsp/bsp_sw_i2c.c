#include "bsp_sw_i2c.h"

/**
 * @brief I2Cͨ����ʱ����
 *
 */
void i2c_delay()
{
    __nop(); __nop(); __nop(); //Լ400kHz
}

/**
 * @brief ��ʼ��I2C����
 *
 */
void i2c_init()
{
    I2C_SDA_1();
    I2C_SCL_1();
    I2C_SCL_MODE_OUT();
    I2C_SDA_MODE_OUT();
}

/**
 * @brief ����I2C��ʼ�ź�
 *
 */
void i2c_start()
{
    I2C_SDA_MODE_OUT();
    I2C_SDA_1();
    I2C_SCL_1();
    i2c_delay();
    I2C_SDA_0();
    i2c_delay();
    I2C_SCL_0();
    i2c_delay();
}

/**
 * @brief ����I2Cֹͣ�ź�
 *
 */
void i2c_stop()
{
    I2C_SDA_MODE_OUT();
    I2C_SCL_0();
	I2C_SDA_0();
    i2c_delay();
	I2C_SCL_1();
	i2c_delay();
	I2C_SDA_1();
}

/**
 * @brief I2Cдʱ�ȴ��ӻ�ACK�ź�
 *
 * @return uint8_t 0 �ӻ���ȷ����ACK
 *                 1 �ȴ��ӻ�����ACK��ʱ
 */
static uint8_t i2c_wait_ack()
{
    uint16_t timeout = 0;

    I2C_SDA_MODE_IN(); //�ͷ�SDA

    I2C_SCL_0();
    i2c_delay();
    I2C_SCL_1(); //��9��λʱ��

    while(I2C_SDA_READ()) {
        timeout ++;
        if(timeout > 10000) {
            i2c_stop(); //��ʱ
            return 1;
        }
    }

    I2C_SCL_0();

    return 0;
} 

/**
 * @brief I2C��ʱ����ACK��NAK�ź�
 *
 * @param ack 0Ϊ����NAK�źţ�1Ϊ����ACK�ź�
 */
static void i2c_gen_ack(uint8_t ack)
{
    I2C_SCL_0();

    if(ack) {
        I2C_SDA_0(); //ACK
    } else {
        I2C_SDA_1(); //NAK
    }
    I2C_SDA_MODE_OUT();
    i2c_delay();
    I2C_SCL_1(); //��9��λʱ��
    i2c_delay();

    I2C_SCL_0();
}

/**
 * @brief ʹ��I2C����һ���ֽ�
 *
 * @param dat Ҫ���͵�����
 * @return uint8_t 0 �ӻ���ȷ����ACK
 *                 1 �ȴ��ӻ�����ACK��ʱ
 */
uint8_t i2c_write_byte(uint8_t dat)
{
    I2C_SDA_MODE_OUT();

    for(uint8_t i = 0; i < 8; i ++) {
        I2C_SCL_0();

        if(dat & 0x80) {
            I2C_SDA_1();
        }
        else {
            I2C_SDA_0();
        }
        dat <<= 1;
        i2c_delay();

        I2C_SCL_1();
        i2c_delay(); //������������Ч
    }

    I2C_SCL_0();

    return i2c_wait_ack();
}

/**
 * @brief ʹ��I2C����һ���ֽ�
 *
 * @param ack 0Ϊ������NAK�źţ�1Ϊ����ACK�ź�
 * @return uint8_t ��ȡ��������
 */
uint8_t i2c_read_byte(uint8_t ack)
{
    uint8_t receive;

    I2C_SDA_MODE_IN();

    for(uint8_t i = 0; i < 8; i ++) {
        I2C_SCL_0();
        i2c_delay();

        receive <<= 1;

        I2C_SCL_1();
        i2c_delay();

        if(I2C_SDA_READ()) {
            receive |= 0x01;
        } else {
            receive &= ~0x01; //��֤ʱ�ӵĸߵ�ʱ�����
        }
    }

    I2C_SCL_0();

    i2c_gen_ack(ack);

    return receive;
}

/**
 * @brief ���I2C��ĳ����ַ�Ƿ����
 *
 * @param addr Ҫ���ĵ�ַ
 * @return uint8_t 1 �õ�ַ�����豸
 *                 0 �õ�ַ�������豸
 */
uint8_t i2c_check(uint8_t addr)
{
    uint8_t res;

    i2c_start();
    res = i2c_write_byte(addr<<1 | 0);
    i2c_stop();

    return !res;
}
