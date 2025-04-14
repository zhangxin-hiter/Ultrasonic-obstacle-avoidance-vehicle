#ifndef __SERIAL_H
#define __SERIAL_H
void serial_init(void);
void serial_sendbyte(uint8_t byte);
void serial_sendarray(uint8_t *array,uint16_t lenth);
void serial_sendstring(char *string);
uint32_t serial_pow(uint32_t X, uint32_t Y);
void serial_sendNumber(uint32_t Number, uint8_t Length);
uint8_t serial_getrxdata(void);
uint8_t serial_getrxflag(void);
#endif