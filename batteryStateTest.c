#include "batteryStateCheck.h"

// Assert statement is encapsulated in a function 

void resultCheck(float *testTempList, float *testSOCList,float *testChargeRateList, batteryCondition *testResultarray,float *limitArray, int *resultBattStatus)

{

	for (int i=0;i<=1;i++)
	{
		int result = batteryIsOk(testTempList[i],testSOCList[i],testChargeRateList[i],limitArray);
			
				for (int j=0;j<3;j++)
				{
				assert(strcmp(batteryCond.parameter[j] , testResultarray[i].parameter[j])== 0);
				assert(strcmp(batteryCond.status[j] , testResultarray[i].status[j])== 0);
				
		assert(floorf(batteryCond.breachedValue[j] * 100) / 100 == testResultarray[i].breachedValue[j]);
		assert(result == resultBattStatus[i]);
				}
	}

}

int main() 
{
    float limitArray[] =   {0,45,20,80,0,0.8}; // Lower and Upper  Boundaries for all the 3 parametes 
	float testTempList[]  =      {20.5 , -1.5 , 50 , 40};         
	float testSOCList[] =        {19.5 , 40   , 80.5 , 40};
	float testChargeRateList[] = {0.9,   0.5,   -1 , 0.3};
	
 /*//batteryCondition testResultArray[] = {{"Temparature","OK",0},{"SOC","Low",0.5},{"ChargeRate","HIGH",0.1}},
 {{"Temparature","LOW",-1.5},{"SOC","OK",0},{"ChargeRate","OK",0}},
 {{"Temparature","HIGH",5},{"SOC","HIGH",0.5},{"ChargeRate","LOW",-1}},
 {{"Temparature","OK",0},{"SOC","OK",0},{"ChargeRate","OK",0}};*/
 batteryCondition testResultArray1[2];
  /*  batteryCondition testResultArray[3];
   ;

		testResultArray1 =  {{{"Temparature"},{"SOC"},{"ChargeRate"}},{{"OK"},{"LOW"},{"HIGH"}},{-1.5,0,0.1}};
		testResultArray[1] = {{"Temparature","SOC","ChargeRate"},{"LOW","OK","OK"},{5,0,0}};
		testResultArray[2] = {{"Temparature","SOC","ChargeRate"},{"HIGH","HIGH","LOW"},{5,0.5,-1}};
		testResultArray[3] = {{"Temparature","SOC","ChargeRate"},{"OK","OK","OK"},{0,0,0}};*/
	testResultArray1[0].parameter[0] = "Temparature";
	testResultArray1[0].parameter[1] = "Temparature";
	testResultArray1[0].parameter[2] = "Temparature";
	testResultArray1[0].status[2] = "LOW";
	testResultArray1[0].status[1] = "LOW";
	testResultArray1[0].status[0] = "LOW";
	testResultArray1[0].breachedValue[0] = 1;	
	testResultArray1[0].breachedValue[1] = 1;	
	testResultArray1[0].breachedValue[2] = 1;	
		testResultArray1[1].parameter[0] = "Temparature";
	testResultArray1[1].parameter[1] = "Temparature";
	testResultArray1[1].parameter[2] = "Temparature";
	testResultArray1[1].status[2] = "LOW";
	testResultArray1[1].status[1] = "LOW";
	testResultArray1[1].status[0] = "LOW";
	testResultArray1[1].breachedValue[0] = 1;	
	testResultArray1[1].breachedValue[1] = 1;	
	testResultArray1[1].breachedValue[2] = 1;	
	int resultBattStatus[] = {1,1,1,0};
	
    resultCheck(testTempList,testSOCList,testChargeRateList,testResultArray1,limitArray,resultBattStatus);
}

