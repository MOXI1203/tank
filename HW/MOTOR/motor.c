#include "motor.h"
#include "24l01.h"

extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim3;

extern QueueHandle_t NrfRecQueue_Queue;

uint8_t motor1state = 0;
uint8_t motor2state = 0;
uint8_t ServoState = 0;
uint8_t CtrlPar[CtrlParLen] = {100,100,100,100,100,100,100,100};
void  RxDataInit(uint8_t Rxdata[])	
{
	uint8_t i;
	for(i = 0;i<6;i++)
	{
		Rxdata[i] = 100;
	}
	Rxdata[0] = 200;
}

uint8_t Follow_Charge(uint8_t Target,uint8_t Value)
{
	if(Value>Target)
	{
		Value = Value - (Value-Target)/20-1;
	}else if(Value<Target)
	{
		Value = Value + (Target - Value)/20+1;
	}
	
	return Value;

}

int16_t Limit(int16_t input, int16_t min, int16_t max)
{
	
	if (input>max)
		input = max;
	if (input<min)
		input = min;
	
	return input;
}


void MotorCtrl(uint8_t uinput_x,uint8_t uinput_y)
{
	
	
	int16_t input_x, input_y,motor1s, motor2s;
	input_x = (int16_t)uinput_x-100;
	input_y = (int16_t)uinput_y-100;
	
	motor1s = input_x -input_y;
	motor2s = input_x +input_y;
	
	motor1s = Limit(motor1s ,-100,100);
	motor2s = Limit(motor2s ,-100,100);
	
	if(motor1s>0)
	{
		TIM1->CCR1 = 0;
		TIM1->CCR2 =  (uint16_t)motor1s;
		if(motor1state!=1)
		{	
			HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_1);
			HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_2);
			motor1state=1;
		}
	}else if(motor1s<0)
	{
		TIM1->CCR1 = (uint16_t)(-motor1s);
		TIM1->CCR2 = 0;
		if(motor1state!=1)
		{	
			HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_1);
			HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_2);
			motor1state=1;
		}
	}else
	{
		if(motor1state!=0)
		{
			TIM1->CCR1 = 0;
			TIM1->CCR2 = 0;
			HAL_TIM_PWM_Stop(&htim1,TIM_CHANNEL_1);
			HAL_TIM_PWM_Stop(&htim1,TIM_CHANNEL_2);
			motor1state=0;
		}
	}
	
	if(motor2s>0)
	{
		TIM1->CCR3 = 0;
		TIM1->CCR4 = (uint16_t)motor2s;
		if(motor2state!=1)
		{	
			HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_3);
			HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_4);
			motor2state=1;
		}
	}else if(motor2s<0)
	{
		TIM1->CCR3 = (uint16_t)(-motor2s);
		TIM1->CCR4 = 0;
		if(motor2state!=1)
		{	
			HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_3);
			HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_4);
			motor2state=1;
		}
	}else
	{
		TIM1->CCR3 = 0;
		TIM1->CCR4 = 0;
		if(motor2state!=0)
		{
			HAL_TIM_PWM_Stop(&htim1,TIM_CHANNEL_3);
			HAL_TIM_PWM_Stop(&htim1,TIM_CHANNEL_4);
			motor2state=0;
		}
		
	}
}

void ServoCtrl(uint8_t Input,uint8_t State)
{
	uint8_t inc;
    static uint8_t charge = 200;
	charge = Follow_Charge(Input,charge);
	if(State == 0)
	{
		inc = 0;
		TIM3->CCR1 = 1000+charge*5;
		if(ServoState ==0)
		{
			HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_1);
			
			ServoState = 1;
		}
	}else
	{
		inc++;
		if(inc ==100)
		{
			if(ServoState ==1)
			{
				HAL_TIM_PWM_Stop(&htim3,TIM_CHANNEL_1);
				ServoState = 0;
			}
		}
	}
}


void MotorCtrlTask(void const * argument)
{
	BaseType_t xReturn = pdTRUE;
	for(;;)
	{
		xReturn = xQueueReceive(NrfRecQueue_Queue,CtrlPar,200);
		if(pdTRUE != xReturn)
		{
			CtrlPar[4] = 100;
			CtrlPar[5] = 100;               
		}
		MotorCtrl(CtrlPar[4],CtrlPar[5]);
	}
}


