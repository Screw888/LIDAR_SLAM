#ifndef __USRAT2_H
#define __USRAT2_H 
#include "sys.h"	  	
#define USARTBufferSize   64
//��������HEX���ٻ�ȡ
typedef union{
	float fv;
	uint8_t cv[4];
}float_union;

//�������ݽṹ
typedef	struct{

		float_union		linear_vx;//���ٶ�x
		float_union		linear_vy;//���ٶ�y
		float_union		angular_v;//���ٶ�
		
}rcv_data;

//�������ݽṹ
typedef	struct{
		
		float_union	v_left;//�����ٶ�
		float_union	v_right;//�����ٶ�
//		float_union	x_v;//x�����ٶ�
//		float_union	y_v;//y�����ٶ�
//		float_union	angular_v;//���ٶ�
//		float_union	pose_angular;//�Ƕ�
	
}send_data;
unsigned char getCrc8(unsigned char *ptr, unsigned short len);
void usart2_send(u8 data);
void uart2_init(u32 pclk2,u32 bound);
int USART2_IRQHandler(void);
void odom_pack_serial_send(void); //������̼�����
uint32_t unpack_cmd_vel_data(uint8_t	*pdata);//�������ݷ��� cmd_vel ->  V����  V����
#endif

