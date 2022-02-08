#include "batteryStateCheck.h"

breachAndValue checkLowerLimit(float input, float lowLimit)       // Avioding Duplication
{
	breachAndValue result= {0,0.0};
	if (input  < lowLimit)
	{
	result.status = LOW;
	result.breachedValue = lowLimit - input ;	 // Calculate the breached value
	}
    return result;
}

breachAndValue checkHigherLimit(float input, float highLimit)        // Avioding Duplication
{
	breachAndValue result= {0,0.0};
	if (input  > highLimit)
	{
	result.status = HIGH;
	result.breachedValue = input - highLimit ;	 // Calculate the breached value
	}
	return result;
}

void printStatus(breachAndValue lowerResult , breachAndValue higherResult , int parameter)
{
	printf(" Lower Limit of %s is %s\n Higher Limit of %s is %s\n and the breached value is %0.2f",batteryCond.parameter[parameter],batteryStatus[lowerResult.status],batteryCond.parameter[parameter],batteryStatus[higherResult.status],(higherResult.breachedValue + lowerResult.breachedValue));
}

void limitCheck(float value, float *limit, int parameter)
{

breachAndValue lowerResult = checkLowerLimit(value , limit[0]);
breachAndValue higherResult = checkHigherLimit(value , limit[1]);

strcpy(batteryParameters[parameter], batteryCond.parameter[parameter]);
strcpy(batteryStatus[lowerResult.status + higherResult.status] , batteryCond.status[parameter]);  // Update the structure with HIGH\LOW status and  breached measure.
batteryCond.breachedValue[parameter] = higherResult.breachedValue + lowerResult.breachedValue;

printStatus(lowerResult,higherResult,parameter);

}

void temperatureIsOk(float temperature, float *tempLimitArray)
{
(limitCheck(temperature,tempLimitArray, 0));
  
}

void SOCIsOk(float soc, float *SOCLimitArray)
{
 
(limitCheck(soc, SOCLimitArray, 1));
  
}

void chargeRateIsOk(float chargeRate, float *chargeRateLimitArray)
{  
(limitCheck(chargeRate, chargeRateLimitArray, 2)); 
}



int batteryIsOk(float temperature, float soc, float chargeRate, float *limitArray) 
{
  temperatureIsOk(temperature,&limitArray[0]);
  SOCIsOk(soc,&limitArray[2]);
  chargeRateIsOk(chargeRate,&limitArray[4]);
  return(int)((batteryCond.breachedValue[0]) || (batteryCond.breachedValue[1]) || (batteryCond.breachedValue[2]));
}

