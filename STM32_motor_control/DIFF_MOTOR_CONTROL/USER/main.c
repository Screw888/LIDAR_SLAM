#include "sys.h"
u8 Flag_Way=0,Flag_Show=0,Flag_Stop=1;                 //ֹͣ��־λ�� ��ʾ��־λ Ĭ��ֹͣ ��ʾ��
int Encoder_Left,Encoder_Right;             //���ұ��������������
float th; //ƫ����
float Velocity,Velocity_Set,Turn,Angle_Set;
int Motor_A,Motor_B,Target_A,Target_B;  //�������������           
int Voltage;                                //��ص�ѹ������صı���
float Velocity_KP=62,Velocity_KI=62;	       //�ٶȿ���PID����
u8 Urxbuf[4],rxbuf[4],Usart_Flag;
u8 dir = 1;
u16 pwmvalA1 = 0;
u16 pwmvalA2 = 0;
u16 pwmvalB1 = 0;
u16 pwmvalB2 = 0;
int main(void)
{ 
	int ua_Encoder,ub_Encoder;
	Stm32_Clock_Init(9);            //=====ϵͳʱ������
	delay_init(72);                 //=====��ʱ��ʼ��
	JTAG_Set(JTAG_SWD_ENABLE);      //=====�ر�JTAG�ӿ�
	LED_Init();                     //=====��ʼ���� LED ���ӵ�Ӳ���ӿ�
	KEY_Init();                     //=====������ʼ��
	Encoder_Init_TIM2();            //=====�������ӿ�
	Encoder_Init_TIM3();            //=====��ʼ�������� 
	delay_ms(300);                  //=====��ʱ����
	uart_init(72,9600);           //=====��ʼ������1
  //Motor_TIM1_PWM_Init(7199,0);  				//=====��ʼ��PWM 10KHZ������������� 
	Motor_TIM4_PWM_Init(7199,0);
	//Adc_Init();                     //=====��ص�ѹ����adc��ʼ��
	uart2_init(36,115200); 				  //=====����3��ʼ�� ����
	Timer_Init(49,7199);            //=====��ʱ�жϳ�ʼ�� 
	while(1)
	{   	  
				/*           ����          */
				//PWMA1=0,PWMA2=6000;  //�ҵ��
				//PWMB1=5000,PWMB2=7200;  //����
				
//				pwmvalA1 = PWMA1;
//				pwmvalA2 = PWMA2;
//		    printf("PWMA1 = %d\n",pwmvalA1);
//				printf("PWMA2 = %d\n",pwmvalA2);
//				printf("=======================\n");
//				pwmvalB1 = PWMB1;
//				pwmvalB2 = PWMB2;
//		    printf("PWMB1 = %d\n",pwmvalB1);
//				printf("PWMB2 = %d\n",pwmvalB2);				
//				printf("\n\r-----------odom����������ڷ���--------------\n ");
				delay_ms(100);
				odom_pack_serial_send();
	}
}
