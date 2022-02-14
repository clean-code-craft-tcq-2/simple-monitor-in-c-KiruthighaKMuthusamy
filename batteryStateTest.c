#include "batteryStateCheck.h"



int main() 
{
	
    float limitArray[] =   {0,45,20,80,0,0.8}; // Lower and Upper  Boundaries for all the 3 parametes   
    bool result = batteryIsOk(20,40,0.5,limitArray);
    assert (result == false);
    result = batteryIsOk(50,90,0.9,limitArray);
    assert( result == true);
    result =  batteryIsOk(-1,10,0.1,limitArray);
    assert( result == true);
	
	
}


