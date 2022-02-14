#include "batteryStateCheck.h"

batteryCondition batteryCond;

const char* batteryParameters[] = {"Temperature", "StateofCharge", "ChargeRate"};
const char* batteryStatus[] = {"OK", "HIGH", "LOW"};

int checkLowerLimit(float input, float lowLimit)       
{   int result = OK;
	if (input  < lowLimit)
	{
	result = LOW;
	}
    return result;
}

int checkHigherLimit(float input, float highLimit)      
{
	int result = OK;
	if (input  > highLimit)
	{
	result = HIGH;	 
	}
	return result;
}

void printStatus(int lowerResult , int higherResult , int parameter)
{
	printf(" %s is %s \n",batteryCond.parameter[parameter],batteryCond.status[parameter]);
	
}

bool limitCheck(float value, float *limit, int parameter)
{
	
int lowerResult = checkLowerLimit(value , limit[0]);
int higherResult = checkHigherLimit(value , limit[1]);
strcpy((batteryCond.parameter[parameter]), batteryParameters[parameter]);
strcpy(batteryCond.status[parameter], batteryStatus[lowerResult + higherResult]);
printStatus(lowerResult,higherResult,parameter);
return (lowerResult || higherResult);
}

bool temperatureIsOk(float temperature, float *tempLimitArray)
{
return((limitCheck(temperature,tempLimitArray, 0)););
  
}

bool SOCIsOk(float soc, float *SOCLimitArray)
{
 
return((limitCheck(soc, SOCLimitArray, 1)););
  
}

bool chargeRateIsOk(float chargeRate, float *chargeRateLimitArray)
{  
return((limitCheck(chargeRate, chargeRateLimitArray, 2)); );
}

bool batteryIsOk(float temperature, float soc, float chargeRate, float *limitArray) 
{
return( temperatureIsOk(temperature,&limitArray[0]) ||  SOCIsOk(soc,&limitArray[2]) || chargeRateIsOk(chargeRate,&limitArray[4]) );
	
}

