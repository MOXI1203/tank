#include "power.h"
#include "cmsis_os.h"

VbusTypedef  VbusStruct; 
extern ADC_HandleTypeDef hadc1;
extern uint8_t NRFState;
void PowerTask(void const * argument)
{
	
	uint8_t i = 0;
	
	for(;;)
	{
		VbusStruct = GetVbusPar();
//		osDelay(100);
//		LED1_ON;
//		osDelay(100);
//		LED1_OFF;
		if(GPIO_PIN_RESET == PowerSin)
		{
			i++;
		}else
		{
			i = 0;
		}
//		if(NRFState == 0)
//		{
//			LED1_ON;
//		}else
//		{
//			LED1_OFF;
//		}
		
	}
}

void PowerInit(void)
{
	PowerOut_OFF;
	if(GPIO_PIN_RESET == PowerSin)
		osDelay(500);
	
	PowerOut_ON;
	Beep_ON;
	osDelay(500);
	Beep_OFF;
	while(GPIO_PIN_RESET == PowerSin);
	
	
}

VbusTypedef GetVbusPar(void)
{
	static uint32_t VbusPeTemp1;
	static uint32_t VbusPeTemp2 = 100;
	static uint8_t inc = 0;
	uint32_t Bus_V;
	VbusTypedef V_Bus;
	HAL_ADC_Start(&hadc1);
	HAL_ADC_PollForConversion(&hadc1, 10);
	Bus_V = HAL_ADC_GetValue(&hadc1);
	HAL_ADC_Stop(&hadc1);
	V_Bus.Bus_Vmv = Bus_V*3300*11/4096;
	if(Bus_V>934)
	{
		VbusPeTemp1 = 100;
	}else if(Bus_V < 812)
	{
		VbusPeTemp1 = 0;
	}else
	{
		VbusPeTemp1 = (Bus_V - 812)*100/122;
	}
	if(inc<10)
	{
		inc++;
	}else
	{
		if(VbusPeTemp2 > VbusPeTemp1)
		{
			VbusPeTemp2 = VbusPeTemp1;
		}
	}
	V_Bus.Bus_Vpe = VbusPeTemp1;
	return V_Bus;
	
}

