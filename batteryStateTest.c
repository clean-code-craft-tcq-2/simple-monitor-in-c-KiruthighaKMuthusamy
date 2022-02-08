#include "batteryStateCheck.h"


// Assert statement is encapsulated in a function 

void resultCheck(float *testTempList, float *testSOCList,float *testChargeRateList, batteryCondition *testResultarray,float *limitArray, int *resultBattStatus)

{

	for (int i=0;i<=3;i++)
	{
		int result = batteryIsOk(testTempList[i],testSOCList[i],testChargeRateList[i],limitArray);
			     //   assert(result == resultBattStatus[i]);
		 printf("\n NALLAPAARU \n %d %d",result , resultBattStatus[i]);
				for (int j=0;j<3;j++)
				{
				assert(strncmp(batteryCond.parameter[j] , testResultarray[i].parameter[j], 7)== 0);
				assert(strncmp(batteryCond.status[j] , testResultarray[i].status[j], 2)== 0);
				assert(batteryCond.breachedValue[j]  == testResultarray[i].breachedValue[j]);
		
					printf("\n NALLAPAARU \n %s,%s",batteryCond.parameter[j] , testResultarray[i].parameter[j] );
					       printf("\n NALLAPAARU \n %s,%s",batteryCond.status[j] , testResultarray[i].status[j]);
					 printf("\n NALLAPAARU \n %f,%f", batteryCond.breachedValue[j]  , testResultarray[i].breachedValue[j]);
					
				}
		
	}

}

int main() 
{
	
    float limitArray[] =   {0,45,20,80,0,0.8}; // Lower and Upper  Boundaries for all the 3 parametes 
	
		int result = batteryIsOk(50,10,0.5,limitArray);
	
	float testTempList[]  =      {20.5 , -1.5 , 50 , 40};         
	float testSOCList[] =        {19.5 , 40   , 80.5 , 40};
	float testChargeRateList[] = {0.9,   0.5,   -1 , 0.3};
	

 
 		  batteryCondition testResultArray[4] =  { {{"Temperature","StateCharge","ChaargeRate"},{"OK","LOW","HIGH"},{0,-0.5,0.1}},
		{{"Temperature","StateCharge","ChaargeRate"},{"LOW","OK","OK"},{-1.5,0,0}}
		,{{"Temperature","StateCharge","ChaargeRate"},{"HIGH","HIGH","LOW"},{5,0.5,-1}}
		, {{"Temperature","StateCharge","ChaargeRate"},{"OK","OK","OK"},{0,0,0}}};
		int resultBattStatus[] = {1,1,1,0};
	
    resultCheck(testTempList,testSOCList,testChargeRateList,testResultArray,limitArray,resultBattStatus);
}

