#include "batteryStateCheck".h

// Assert statement is encapsulated in a function 

void resultCheck(float *testTempList, float *testSOCList,float *testChargeRateList, batteryCondition *testResultArray,float *limitArray, bool *resultBattStatus)
{

for (int i=0,i<3,i++)
{
	    bool result = batteryIsOk(testTempList[i],testSOCList[i],testChargeRateList[i],limitArray);
		
		for (int j=0, j<2,j++)
		{
		asset(strcmp(batteryCond.parameter[j] , testResultarray[i].parameter[j]));
		}
	    asset(floorf(batteryCond.parameter[3] * 100 / 100 == testResultarray[i].parameter[j]);
		asset(result == resultBattStatus[i]);
}

}

int main() 
{
    const float limitArray[] = {0,45,20,80,0,0.8}; // Lower and Upper  Boundaries for all the 3 parametes 
	float testTempList[]  = {20.5 , -1.5 , 50 , 40};         
	float testSOCList[] = {19.5 , 40 , 80.5 , 40};
	float testChargeRateList[] = {0.9,0.5,-1} , 0.3;
	
    batteryCondition testResultArray[3] = {{"Temparature","OK",0},{"SOC","Low",0.5},{"ChargeRate","HIGH",0.1}},{{"Temparature","LOW",-1.5},{"SOC","OK",0},{"ChargeRate","OK",0}},{{"Temparature","HIGH",5},{"SOC","HIGH",0.5},{"ChargeRate","LOW",-1}},{{"Temparature","OK",0},{"SOC","OK",0},{"ChargeRate","OK",0}};
	bool resultBattStatus[3] = {1,1,1,0}
	
    resultCheck (testTempList,,testSOCList,testChargeRateList,testResultArray,resultBattStatus);
}

