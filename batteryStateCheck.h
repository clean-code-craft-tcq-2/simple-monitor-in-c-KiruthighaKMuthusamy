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

struct breachAndValue
{
	int status;
	float breachedValue;
};


int checkLowerLimit(float input, float lowLimit);
int checkHigherLimit(float input, float highLimit);
printStatus(int lowerResult , int higherResult , int parameter);
limitCheck(float value, float &limit, int parameter);
int temperatureIsOk(float temperature, float &limitArray);
int SOCIsOk(float soc, float &limitArray);
int chargeRateIsOk(float chargeRate, float &limitArray);
bool batteryIsOk(float temperature, float soc, float chargeRate, float &limitArray) ;