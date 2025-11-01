#include<iostream>
#include"clsLoginScreen.h"
#include"clsUtil.h"
using namespace std;


int main()
{
	while (true) //this solved the Circular Refrance issue
	{
		if (!clsLoginScreen::ShowLoginScreen())
			break;
		
	}
	
	return 0;

	
}