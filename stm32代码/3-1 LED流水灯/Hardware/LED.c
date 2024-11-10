#include "LED.h"
#include "stm32f10x.h"                  // Device header


void LED_Init(void){
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	GPIO_InitTypeDef GPIO_InitSturcture;		
	GPIO_InitSturcture.GPIO_Mode=GPIO_Mode_Out_PP;;
	GPIO_InitSturcture.GPIO_Pin=GPIO_Pin_All;
	GPIO_InitSturcture.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitSturcture);	
}

void LED_All(BitAction BitVal){
		GPIO_WriteBit(GPIOA,GPIO_Pin_All,BitVal);
}

void LED_1(BitAction BitVal){
		GPIO_WriteBit(GPIOA,GPIO_Pin_1,BitVal);
}

void LED_2(BitAction BitVal){
		GPIO_WriteBit(GPIOA,GPIO_Pin_2,BitVal);
}

void LED_3(BitAction BitVal){
		GPIO_WriteBit(GPIOA,GPIO_Pin_3,BitVal);
}

void LED_4(BitAction BitVal){
		GPIO_WriteBit(GPIOA,GPIO_Pin_4,BitVal);
}

void LED_5(BitAction BitVal){
		GPIO_WriteBit(GPIOA,GPIO_Pin_5,BitVal);
}

void LED_6(BitAction BitVal){
		GPIO_WriteBit(GPIOA,GPIO_Pin_6,BitVal);
}

void LED_7(BitAction BitVal){
		GPIO_WriteBit(GPIOA,GPIO_Pin_7,BitVal);
}

void LED_All_Turn(void){
		if(GPIO_ReadOutputData(GPIOA) == 0){
			
			GPIO_SetBits(GPIOA,GPIO_Pin_All);
		}else{
			GPIO_ResetBits(GPIOA,GPIO_Pin_All);
		}
}
		
void LED_All_Turn2(void){
		if(GPIO_ReadOutputDataBit(GPIOA,GPIO_Pin_1) == 1){
			GPIO_ResetBits(GPIOA,GPIO_Pin_1);
		}
}

