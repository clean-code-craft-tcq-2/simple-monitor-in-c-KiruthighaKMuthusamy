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

void printStatus( int parameter)
{
	printf(" %s is %s \n",batteryCond.parameter[parameter],batteryCond.status[parameter]);
	
}

bool limitCheck(float value, float *limit, int parameter)
{
	
int lowerResult = checkLowerLimit(value , limit[0]);
int higherResult = checkHigherLimit(value , limit[1]);
strcpy((batteryCond.parameter[parameter]), batteryParameters[parameter]);
strcpy(batteryCond.status[parameter], batteryStatus[lowerResult + higherResult]);
printStatus(parameter);
return (lowerResult || higherResult);
}

bool temperatureIsOk(float temperature, float *tempLimitArray)
{
bool result = limitCheck(temperature,tempLimitArray, 0);
  return result;
}

bool SOCIsOk(float soc, float *SOCLimitArray)
{
 
bool result = (limitCheck(soc, SOCLimitArray, 1));
return result;
  
}

bool chargeRateIsOk(float chargeRate, float *chargeRateLimitArray)
{  
bool result = limitCheck(chargeRate, chargeRateLimitArray, 2);
return result;
}

bool batteryIsOk(float temperature, float soc, float chargeRate, float *limitArray) 
{bool resultTemp,resultSoc,resultChargeRate;
resultTemp = temperatureIsOk(temperature,&limitArray[0]);
resultSoc = SOCIsOk(soc,&limitArray[2]);
resultChargeRate = chargeRateIsOk(chargeRate,&limitArray[4]);
return(resultTemp|| resultSoc||resultChargeRate);
	
}
