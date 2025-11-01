#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsUser.h"
#include"clsInputValidation.h"
#include"Global.h"
#include"clsMainScreen.h"
using namespace std;
class clsLoginScreen:protected clsScreen
{
private:

	static bool _Login()
	{
		bool LoginFaild = false;
		string Username, Password;
		short FaildLoginCounter = 0;
		do
		{
			if (LoginFaild)
			{
				FaildLoginCounter++;
				cout << "\nLogin Faild Invalid Username/Password...\n";
				cout << "You have " << (3 - FaildLoginCounter) << " Trials to Login.\n\n"; 
			}
			if (FaildLoginCounter == 3)
			{
				system("cls");
				cout << "YOU ARE LOCKED FORM THE SYSTEM.";
				system("pause>0");
				return false;
			}
			cout << "Enter Username: ";
			Username = clsInputValidation::ReadString();
			cout << "Enter password: ";
			Password = clsInputValidation::ReadString();

			CurrentUser = clsUser::Find(Username, Password);
			LoginFaild = CurrentUser.IsEmpty();
			
				
		} while (LoginFaild);
		CurrentUser.RegisterLogIn();
		clsMainScreen::ShowMainMenue();
		return true;
	}

public:
	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("Login Screen");
		return _Login();
	}
};

