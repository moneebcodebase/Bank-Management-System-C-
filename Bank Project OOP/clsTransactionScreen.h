#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsInputValidation.h"
#include"clsDepositeScreen.h"
#include"clsWithdrawScreen.h"
#include"clsTotalBalancesScreen.h"
#include"clsTransferScreen.h"
#include"clsTransferLogScreen.h"
#include"Global.h"
#include"clsUser.h"
using namespace std;
class clsTransactionScreen:protected clsScreen
{
private:

	enum enTransactionMenueOptions{eDposite=1,eWithdraw,eShowTotalBalances,eTransfer,eTransferLog,eGoBacktoMainMenue};

	static void _PrintActiveUser()
	{
		cout << setw(38) << left << " " << "\tUsername: " << CurrentUser.UserName << endl;
	}

	static short _ReadTransactionMenueOption()
	{
		short Option = 0;
		cout << setw(40) << left << " " << "What do you want to do from [1-6]: ";
		Option = clsInputValidation::ReadNumberBetween(1, 6,"Wrong Input, Choose from 1 to 6: ");
		return Option;
	}

	 static void _ShowDepositeScreen()
	{
		clsDepositeScreen::ShowDepositeScreen();
	}

	static void _ShowWithdrawScreen()
	{
		clsWithdrawScreen::ShowWithdrawScreen();
	}

	static void _ShowTotalBalancesScreen()
	{
		clsTotalBalancesScreen::ShowTotalBalancesScreen();
	}

	static void _ShowTransferScreen()
	{
		clsTransferScreen::ShowTransferScreen();
	}

	static void _ShowTransferLogScreen()
	{
		clsTransferLogScreen::ShowTransferLogScreen();
	}

	static void _GoBackToTransactionMenue()
	{
		cout << " Press Any Key to Continue....\n";
		system("pause>0");
		ShowTransactionMenue();
	}

	static void _PreformTransactionMenueScreen(enTransactionMenueOptions TransactionMeneuOption)
	{
		switch (TransactionMeneuOption)
		{
		case enTransactionMenueOptions::eDposite:
		{
			system("cls");
			_ShowDepositeScreen();
			_GoBackToTransactionMenue();
			break;
		}
		case enTransactionMenueOptions::eWithdraw:
		{
			system("cls");
			_ShowWithdrawScreen();
			_GoBackToTransactionMenue();
			break;
		}
		case enTransactionMenueOptions::eShowTotalBalances:
		{
			system("cls");
			_ShowTotalBalancesScreen();
			_GoBackToTransactionMenue();
			break;
		}
		case enTransactionMenueOptions::eTransfer:
		{
			system("cls");
			_ShowTransferScreen();
			_GoBackToTransactionMenue();
			break;
		}
		case enTransactionMenueOptions::eTransferLog:
		{
			system("cls");
			_ShowTransferLogScreen();
			_GoBackToTransactionMenue();
			break;
		}
		case enTransactionMenueOptions::eGoBacktoMainMenue:
		{
			break;
		}
		}
	}

public:
	static void ShowTransactionMenue()
	{
		system("cls");
		if (!CkeckAccessRights(clsUser::enPermissions::pFindClient))
		{
			return;
		}
		_PrintActiveUser();
		_DrawScreenHeader("Transactions Menue");
		cout << setw(40) << left << " " << "============================================\n";
		cout << setw(40) << left << " " << "\t\t Transactions\n";
		cout << setw(40) << left << " " << "============================================\n";
		cout << setw(38) << left << " " << "\t[1] Deposite." << endl;
		cout << setw(38) << left << " " << "\t[2] Withdraw." << endl;
		cout << setw(38) << left << " " << "\t[3] Show Total Balances." << endl;
		cout << setw(38) << left << " " << "\t[4] Transfer." << endl;
		cout << setw(38) << left << " " << "\t[5] Transfer Log." << endl;
		cout << setw(38) << left << " " << "\t[6] Go Back to Main Menue." << endl;
		cout << setw(40) << left << " " << "============================================\n";
		_PreformTransactionMenueScreen((enTransactionMenueOptions)_ReadTransactionMenueOption());
	}
};

