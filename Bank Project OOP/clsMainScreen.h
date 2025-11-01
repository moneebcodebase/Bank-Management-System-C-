#pragma once
#include<iostream>
#include"clsDate.h"
#include"clsScreen.h"
#include"clsInputValidation.h"
#include"clsShowClientListScreen.h"
#include"clsAddNewClientScreen.h"
#include"clsDeleteClientScreen.h"
#include"clsUpdateClientScreen.h"
#include"clsFindClientScreen.h"
#include"clsTransactionScreen.h"
#include"clsManageUsersScreen.h"
#include"clsLoginRegisterScreen.h"
#include"Global.h"

using namespace std;
class clsMainScreen:protected clsScreen
{
private:
	enum enMainMenueoptions{eShowClients=1,eAddNewClient,eDeleteClient,eUpdateClient,eFindClient
	,eTransactions,eManageUsers,eRigster,eLogout};

	static void _GoBacktoMainMenue()
	{
		cout << "\n\n Press Any Key To Continue....";
		system("pause>0");
		ShowMainMenue();
	}

	static short _ReadMainMeneuOption()
	{
		short Option = 0;
		cout << setw(40) << left << " " << "What do you want to do from [1-9]: ";
		Option = clsInputValidation::ReadNumberBetween(1, 9,"Wrong Input, Choose from 1-9: ");
		return Option;
	}

	static void _ShowClientListScreen()
	{
		clsShowClientListScreen::ShowClientsList();
	}

	static void _AddNewClientScreen()
	{
		clsAddNewClientScreen::ShowAddNewClientScreen();
	}

	static void _DeleteClientScreen()
	{
		clsDeleteClientScreen::ShowDeleteClientScreen();
	}

	static void _UpdateClientScreen()
	{
		clsUpdateClientScreen::ShowUpdateClientScreen();
	}

	static void _FindClientScreen()
	{
		clsFindClientScreen::ShowFindClientScreen();
	}

	static void _TransactionsMenueScreen()
	{
		clsTransactionScreen::ShowTransactionMenue();
	}

	static void _ManageUsersMenueScreen()
	{
		clsManageUsersScreen::ShowManageUsersScreen();
	}

	static void _LoginRegisterScreen()
	{
		clsLoginRegisterScreen::ShowLoginRegisterScreen();
	}

	static void _Logout()
	{
		CurrentUser = clsUser::Find("", "");
	}

	static void _PreformMainMenueScreen(enMainMenueoptions MainMenueOption)
	{
		switch (MainMenueOption)
		{
		case enMainMenueoptions::eShowClients:
		{
			system("cls");
			_ShowClientListScreen();
			_GoBacktoMainMenue();
		}
		case enMainMenueoptions::eAddNewClient:
		{
			system("cls");
			_AddNewClientScreen();
			_GoBacktoMainMenue();
		}
		case enMainMenueoptions::eDeleteClient:
		{
			system("cls");
			_DeleteClientScreen();
			_GoBacktoMainMenue();
		}
		case enMainMenueoptions::eUpdateClient:
		{
			system("cls");
			_UpdateClientScreen();
			_GoBacktoMainMenue();
		}
		case enMainMenueoptions::eFindClient:
		{
			system("cls");
			_FindClientScreen();
			_GoBacktoMainMenue();
		}
		case enMainMenueoptions::eTransactions:
		{
			system("cls");
			_TransactionsMenueScreen();
			_GoBacktoMainMenue();
		}
		case enMainMenueoptions::eManageUsers:
		{    system("cls");
		_ManageUsersMenueScreen();
		_GoBacktoMainMenue();
		}
		case enMainMenueoptions::eRigster:
		{
			system("cls");
			_LoginRegisterScreen();
			_GoBacktoMainMenue();
		}
		case enMainMenueoptions::eLogout:
		{
			system("cls");
			_Logout();
			break;
		}
		}
	}

public:

	static void ShowMainMenue()
	{
		system("cls");
		_DrawScreenHeader("Main Menue");
		cout << setw(38) << left <<" "<<"\t[1] Show Client List." << endl;
		cout << setw(38) << left << " " << "\t[2] Add New Client." << endl;
		cout << setw(38) << left << " " << "\t[3] Delete Client." << endl;
		cout << setw(38) << left << " " << "\t[4] Update Client." << endl;
		cout << setw(38) << left << " " << "\t[5] Find Client." << endl;
		cout << setw(38) << left << " " << "\t[6] Transactions." << endl;
		cout << setw(38) << left << " " << "\t[7] Manage Users." << endl;
		cout << setw(38) << left << " " << "\t[8] Login Register." << endl;
		cout << setw(38) << left << " " << "\t[9] Logout." << endl;
		cout << setw(40) << left << " " << "============================================\n";
		_PreformMainMenueScreen((enMainMenueoptions)_ReadMainMeneuOption());
	}
};

