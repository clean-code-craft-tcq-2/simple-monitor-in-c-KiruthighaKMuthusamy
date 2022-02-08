#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <string.h>


#define LOW 2
#define HIGH 1
#define OK 0


const char* batteryParameters[] = {"Temperature", "SOC", "ChargeRate"};
const char* batteryStatus[] = {"OK", "HIGH", "LOW"};

struct batteryCondition
{
	char* parameter[3];
	char* status[3];
	float breachedValue[3];
	
}batteryCond;

typedef struct BreachAndValue
{
	int status;
	float breachedValue;
}breachAndValue;


breachAndValue checkLowerLimit(float input, float lowLimit);
breachAndValue checkHigherLimit(float input, float highLimit);
void printStatus(breachAndValue lowerResult , breachAndValue higherResult , int parameter);
void limitCheck(float value, float *limit, int parameter);
void temperatureIsOk(float temperature, float *limitArray);
void SOCIsOk(float soc, float *limitArray);
void chargeRateIsOk(float chargeRate, float *limitArray);
bool batteryIsOk(float temperature, float soc, float chargeRate, float *limitArray);
void resultCheck(testTempList,testSOCList,testChargeRateList,testResultArray,limitArray,resultBattStatus);
