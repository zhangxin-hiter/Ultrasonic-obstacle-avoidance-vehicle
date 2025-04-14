#include "stm32f10x.h"                  // Device header
uint16_t rxflag;
uint8_t rxdata;
void serial_init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	USART_InitTypeDef USART_InitStructure;
	USART_InitStructure.USART_BaudRate=9600;
	USART_InitStructure.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode=USART_Mode_Rx|USART_Mode_Tx;
	USART_InitStructure.USART_Parity=0;
	USART_InitStructure.USART_StopBits=1;
	USART_InitStructure.USART_WordLength=8;
	USART_Init(USART1,&USART_InitStructure);
	
	USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);
	
	USART_Cmd(USART1,ENABLE);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel=USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=1;
	NVIC_Init(&NVIC_InitStructure);
}
void serial_sendbyte(uint8_t byte)
{
	USART_SendData(USART1,byte);
	while(USART_GetFlagStatus(USART1,USART_FLAG_TXE)==RESET);
}
void serial_sendarray(uint8_t *array,uint16_t lenth)
{
	uint16_t i;
	for(i=0;i<lenth;i++)
	{
		USART_SendData(USART1,array[i]);
		while(USART_GetFlagStatus(USART1,USART_FLAG_TXE)==RESET);
	}
}
void serial_sendstring(char *string)
{
	uint16_t i;
	for(i=0;string[i]!='\0';i++)
	{
		USART_SendData(USART1,string[i]);
		while(USART_GetFlagStatus(USART1,USART_FLAG_TXE)==RESET);
	}
}
uint32_t serial_pow(uint32_t X, uint32_t Y)
{
	uint32_t Result = 1;
	while (Y --)
	{
		Result *= X;
	}
	return Result;
}

void serial_sendNumber(uint32_t Number, uint8_t Length)
{
	uint8_t i;
	for (i = 0; i < Length; i ++)
	{
		serial_sendbyte(Number / serial_pow(10, Length - i - 1) % 10 + '0');
	}
}
uint8_t serial_getrxflag(void)
{
	if(rxflag==1)
	{
		rxflag=0;
		return 1;
	}
	return 0;
}
uint8_t serial_getrxdata(void)
{
	return rxdata;
}
void USART1_IRQHandler(void)
{
	if(USART_GetITStatus(USART1,USART_IT_RXNE)==SET)
	{
		rxdata=USART_ReceiveData(USART1);
		rxflag=1;
		USART_ClearITPendingBit(USART1,USART_IT_RXNE);
	}
}
	