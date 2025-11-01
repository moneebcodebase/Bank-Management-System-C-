#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsInputValidation.h"
#include"clsUser.h"
#include"clsListUsersScreen.h"
#include"clsAddNewUserScreen.h"
#include"clsDeleteUserScreen.h"
#include"clsUpdateUserScreen.h"
#include"clsFindUserScreen.h"
#include"Global.h"
using namespace std;

class clsManageUsersScreen:protected clsScreen
{
private:
	enum enManageUsersScreenOptions { eListUsers = 1, eAddNewUser, eDeleteUser, eUpdateUser, eFinduser, eMainMenue };
	
	static void _PrintActiveUser()
	{
		cout << setw(38) << left << " " << "\tUsername: " << CurrentUser.UserName << endl;
	}

	static short _ReadManageUsersScreenOption()
	{
		short Option = 0;
		cout << setw(40) << left << " " << "What do you want to do from [1-6]: ";
		Option = clsInputValidation::ReadNumberBetween(1, 6, "Wrong Input, Choose from 1 to 6: ");
		return Option;
	}

	static void _ShowListUsersScreen()
	{
		clsListUsersScreen::ShowUsersListScreen();
	}

	static void _ShowAddNewUserScreen()
	{
		clsAddNewUserScreen::ShowAddNewUserScreen();
	}

	static void _ShowDeleteUserScreen()
	{
		clsDeleteUserScreen::ShowDeleteUserScreen();
	}

	static void _ShowUpdateUserScreen()
	{
		clsUpdateUserScreen::ShowUpdateUserScreen();
	}

	static void _ShowFindUserScreen()
	{
		clsFindUserScreen::ShowFindUserScreen();
	}

	static void _GoBacktoManageUsersScreen()
	{
		cout << " Press Any Key to Continue....\n";
		system("pause>0");
		ShowManageUsersScreen();
	}
	static void _PreformManageUsersMenue(enManageUsersScreenOptions ManageUsersOption)
	{
		switch (ManageUsersOption)
		{
		case enManageUsersScreenOptions::eListUsers:
		{
			system("cls");
			_ShowListUsersScreen();
			_GoBacktoManageUsersScreen();
			break;
		}
		case enManageUsersScreenOptions::eAddNewUser:
		{
			system("cls");
			_ShowAddNewUserScreen();
			_GoBacktoManageUsersScreen();
			break;
		}
		case enManageUsersScreenOptions::eDeleteUser:
		{
			system("cls");
			_ShowDeleteUserScreen();
			_GoBacktoManageUsersScreen();
			break;
		}
		case enManageUsersScreenOptions::eUpdateUser:
		{
			system("cls");
			_ShowUpdateUserScreen();
			_GoBacktoManageUsersScreen();
			break;
		}
		case enManageUsersScreenOptions::eFinduser:
		{
			system("cls");
			_ShowFindUserScreen();
			_GoBacktoManageUsersScreen();
			break;
		}
		case enManageUsersScreenOptions::eMainMenue:
		{

		}
		}
	}
public:
	static void ShowManageUsersScreen()
	{
		system("cls");
		if (!CkeckAccessRights(clsUser::enPermissions::pManageUsers))
		{
			return;
		}
		_PrintActiveUser();
		_DrawScreenHeader("Mange Users Screen");
		cout << setw(40) << left << " " << "============================================\n";
		cout << setw(40) << left << " " << "\t\t Manage Users\n";
		cout << setw(40) << left << " " << "============================================\n";
		cout << setw(38) << left << " " << "\t[1] list Users." << endl;
		cout << setw(38) << left << " " << "\t[2] Add New User." << endl;
		cout << setw(38) << left << " " << "\t[3] Delete User." << endl;
		cout << setw(38) << left << " " << "\t[4] Update User." << endl;
		cout << setw(38) << left << " " << "\t[5] Find User." << endl;
		cout << setw(38) << left << " " << "\t[6] Go Back to Main Menue." << endl;
		cout << setw(40) << left << " " << "============================================\n";
		_PreformManageUsersMenue((enManageUsersScreenOptions)_ReadManageUsersScreenOption());
	}
};

