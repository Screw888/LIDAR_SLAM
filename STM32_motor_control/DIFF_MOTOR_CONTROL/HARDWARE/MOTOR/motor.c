#include "motor.h"
#if 1
void Motor_TIM4_PWM_Init(u16 arr,u16 psc)
{		 
  RCC->APB1ENR|=1<<2;       //TIM4ʱ��ʹ��    
	RCC->APB2ENR|=1<<3;       //PORTBʱ��ʹ��   6 7��Ϊ���������� �������� PB6 -> BIN1 PB7 -> BIN2
	GPIOB->CRL&=0X00FFFFFF;   //PORTB6 7  8 9�������  
	GPIOB->CRL|=0XBB000000;   //PORTB6 7  8 9�������	 
	GPIOB->CRH&=0XFFFFFF00;   //PORTB6 7  8 9�������
	GPIOB->CRH|=0X000000BB;   //PORTB6 7  8 9�������
	
	TIM4->ARR=arr;//�趨�������Զ���װֵ 
	TIM4->PSC=psc;//Ԥ��Ƶ������Ƶ
	TIM4->CCMR1|=6<<4;//CH1 PWM1ģʽ	
	TIM4->CCMR1|=6<<12; //CH2 PWM1ģʽ	
	TIM4->CCMR2|=6<<4;//CH3 PWM1ģʽ	
	TIM4->CCMR2|=6<<12; //CH4 PWM1ģʽ	
	
	TIM4->CCMR1|=1<<3; //CH1Ԥװ��ʹ��	  
	TIM4->CCMR1|=1<<11;//CH2Ԥװ��ʹ��	 
	TIM4->CCMR2|=1<<3; //CH3Ԥװ��ʹ��	  
	TIM4->CCMR2|=1<<11;//CH4Ԥװ��ʹ��	 
	TIM4->CCER|=1<<0;  //CH1���ʹ��	
	TIM4->CCER|=1<<4;  //CH2���ʹ��	   
	TIM4->CCER|=1<<8;  //CH3���ʹ��	
	TIM4->CCER|=1<<12; //CH4���ʹ��	   
	TIM4->CR1=0x80;  //ARPEʹ�� 
	TIM4->CR1|=0x01;   //ʹ�ܶ�ʱ�� 							 
} 
#endif
#if 0
void Motor_PWM_Init(u16 arr,u16 psc)  //PA2 PA3 PB0 PB1
{		 
	//RCC->APB2ENR|=1<<11;       //ʹ��TIM1ʱ�� 
	RCC->APB1ENR|=1<<0; 	    //ʹ��TIM2ʱ��
	RCC->APB1ENR|=1<<1;	      //ʹ��TIM3ʱ��
	RCC->APB2ENR|=1<<3;       //PORTBʱ��ʹ�� 
	RCC->APB2ENR|=1<<2;        //PORTAʱ��ʹ��  

	GPIOB->CRL&=0XFFFFFF00;         //PORTB0 1 �������  TIM3_CH3 TIM3_CH4
	GPIOB->CRL|=0X000000BB;					//PORTB0 1 �������
//	GPIOB->ODR|=1<<0; //PB0 �����
//	GPIOB->ODR|=1<<1; //PB1 �����
	
	GPIOA->CRL&=0XFFFF00FF;   //PORTA2 3�������  TIM2_CH3 TIM2_CH4
	GPIOA->CRL|=0X0000BB00;   //PORTA2 3������� 
//	GPIOA->ODR|=1<<2; //PA2 �����
//	GPIOA->ODR|=1<<3; //PA3 �����
	
	TIM2->ARR=arr;             //�趨�������Զ���װֵ 
	TIM2->PSC=psc;             //Ԥ��Ƶ������Ƶ
	TIM3->ARR=arr;             //�趨�������Զ���װֵ 
	TIM3->PSC=psc;             //Ԥ��Ƶ������Ƶ
	
	
	TIM2->CCMR2|=6<<4;   	//CH3 PWM1ģʽ
	TIM2->CCMR2|=6<<12;   //CH4 PWM1ģʽ
	TIM2->CCMR2|=1<<3;		//CH3Ԥװ��ʹ��
	TIM2->CCMR2|=1<<11;		//CH4Ԥװ��ʹ��
	TIM2->CCER|=1<<8;			//CH3���ʹ��
	TIM2->CCER|=1<<12;		//CH4���ʹ��
	
	TIM3->CCMR2|=6<<4;    //CH3 PWM1ģʽ
	TIM3->CCMR2|=6<<12;		//CH4 PWM1ģʽ
	TIM3->CCMR2|=1<<3;		//CH3Ԥװ��ʹ��
	TIM3->CCMR2|=1<<11;		//CH4Ԥװ��ʹ��
	TIM3->CCER|=1<<8;			//CH3���ʹ��
	TIM3->CCER|=1<<12;		//CH4���ʹ��
	
	TIM2->CR1 = 0x80;           //ARPEʹ�� 
	TIM2->CR1|=0x01;          //ʹ�ܶ�ʱ��2
	
	TIM3->CR1 = 0x80;           //ARPEʹ�� 
	TIM3->CR1|=0x01;          //ʹ�ܶ�ʱ��3 
	/*
	TIM1->CCMR1|=6<<4;//CH1 PWM1ģʽ	
	TIM1->CCMR1|=6<<12; //CH1N PWM1ģʽ	
	TIM1->CCMR2|=6<<4;//CH2N PWM1ģʽ	
	TIM1->CCMR2|=6<<12; //CH3N PWM1ģʽ	
	
	TIM4->CCMR1|=6<<4;//CH1 PWM1ģʽ	
	TIM4->CCMR1|=6<<12; //CH2 PWM1ģʽ	
	TIM4->CCMR2|=6<<4;//CH3 PWM1ģʽ	
	TIM4->CCMR2|=6<<12; //CH4 PWM1ģʽ	
	
	TIM4->CCMR1|=1<<3; //CH1Ԥװ��ʹ��	  
	TIM4->CCMR1|=1<<11;//CH2Ԥװ��ʹ��	 
	TIM4->CCMR2|=1<<3; //CH3Ԥװ��ʹ��	  
	TIM4->CCMR2|=1<<11;//CH4Ԥװ��ʹ��	 
	TIM4->CCER|=1<<0;  //CH1���ʹ��	
	TIM4->CCER|=1<<4;  //CH2���ʹ��	   
	TIM4->CCER|=1<<8;  //CH3���ʹ��	
	TIM4->CCER|=1<<12; //CH4���ʹ��	   
  TIM1->CR1 = 0x80;           //ARPEʹ�� 
	TIM1->CR1|=0x01;          //ʹ�ܶ�ʱ��1 	
*/	
} 
#endif
#if 1
void Motor_TIM1_PWM_Init(u16 arr,u16 psc) //PA11 PA8
{
	RCC->APB2ENR|=1<<11;       //ʹ��TIM1ʱ��    
	RCC->APB2ENR|=1<<2;        //PORTAʱ��ʹ�� 
	
	GPIOA->CRH&=0XFFFFFFF0;    //PORTA8�������
	GPIOA->CRH|=0X0000000B;    //PORTA8�������	
	GPIOA->CRH&=0XFFFF0FFF;    //PORTA11�������
	GPIOA->CRH|=0X0000B000;    //PORTA11�������
	TIM1->ARR=arr;             //�趨�������Զ���װֵ 
	TIM1->PSC=psc;             //Ԥ��Ƶ������Ƶ
	
	TIM1->CCMR1|=6<<4;        //CH1 PWM1ģʽ	
	TIM1->CCMR1|=1<<3;        //CH1Ԥװ��ʹ��	
	TIM1->CCER|=1<<0;         //CH1���ʹ��	
	
	TIM1->CCMR2|=6<<12;        //CH4 PWM1ģʽ	
	TIM1->CCMR2|=1<<11;        //CH4Ԥװ��ʹ��	   
	TIM1->CCER|=1<<12;         //CH4���ʹ��	   
  TIM1->BDTR |= 1<<15;       //TIM1����Ҫ��仰�������PWM
	TIM1->CR1 = 0x80;          //ARPEʹ�� 
	TIM1->CR1|=0x01;           //ʹ�ܶ�ʱ��1 		
	TIM1->CCR1=0;
  TIM1->CCR4=0;	
		
}


#endif

/**************************************************************************
�������ܣ����PWM��ʼ��
��ڲ�������ڲ�����arr���Զ���װֵ  psc��ʱ��Ԥ��Ƶ�� 
����  ֵ����
**************************************************************************/
#if 0
void Servo_PWM_Init(u16 arr,u16 psc)	
{	 
	RCC->APB2ENR|=1<<11;       //ʹ��TIM1ʱ��    
	RCC->APB2ENR|=1<<2;        //PORTAʱ��ʹ�� 
	GPIOA->CRH&=0XFFFF0FFF;    //PORTA11�������
	GPIOA->CRH|=0X0000B000;    //PORTA11�������
	TIM1->ARR=arr;             //�趨�������Զ���װֵ 
	TIM1->PSC=psc;             //Ԥ��Ƶ������Ƶ
	TIM1->CCMR2|=6<<12;        //CH4 PWM1ģʽ	
	TIM1->CCMR2|=1<<11;        //CH4Ԥװ��ʹ��	   
	TIM1->CCER|=1<<12;         //CH4���ʹ��	   
  TIM1->BDTR |= 1<<15;       //TIM1����Ҫ��仰�������PWM
	TIM1->CR1 = 0x80;          //ARPEʹ�� 
	TIM1->CR1|=0x01;           //ʹ�ܶ�ʱ��1 		
  TIM1->CCR4=0;	
}
#endif
