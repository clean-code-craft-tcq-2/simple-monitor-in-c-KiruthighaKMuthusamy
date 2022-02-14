#ifndef batteryStateCheck_h
#define batteryStateCheck_h

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>


#define LOW 2
#define HIGH 1
#define OK 0

typedef struct batterycondition
{
	char parameter[3][15];
	char status[3][5];
		
}batteryCondition;
extern batteryCondition batteryCond;



int checkLowerLimit(float input, float lowLimit) ;
int checkHigherLimit(float input, float highLimit);
void printStatus(int lowerResult , int higherResult , int parameter);
bool limitCheck(float value, float *limit, int parameter);
bool temperatureIsOk(float temperature, float *tempLimitArray);
bool SOCIsOk(float soc, float *SOCLimitArray);
bool chargeRateIsOk(float chargeRate, float *chargeRateLimitArray);
bool batteryIsOk(float temperature, float soc, float chargeRate, float *limitArray) ;



#endif
