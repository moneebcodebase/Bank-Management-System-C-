#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsBankClient.h"
class clsTransferLogScreen:protected clsScreen
{
private:

	static void _PrintTransferLogLine(clsBankClient::stTransferLog TransferLogRecord)
	{
		cout << "| " << left << setw(22) << TransferLogRecord.Date_Time;
		cout << "| " << left << setw(10) << TransferLogRecord.FromAccount;
		cout << "| " << left << setw(10) << TransferLogRecord.ToAccount;
		cout << "| " << left << setw(15) << TransferLogRecord.Amount;
		cout << "| " << left << setw(15) << TransferLogRecord.s_Balance;
		cout << "| " << left << setw(15) << TransferLogRecord.d_Balance;
		cout << "| " << left << setw(15) << TransferLogRecord.User;
	}
public:
	static void ShowTransferLogScreen()
	{
		vector<clsBankClient::stTransferLog> vTransferLogRecords = clsBankClient::GetTransferLogList();
		string Title = "Transfer Log Screen";
		string SubTitle = "( " + to_string(vTransferLogRecords.size()) + " ) Opreations";
		_DrawScreenHeader(Title, SubTitle);

		cout << "\n----------------------------------------------------------------";
		cout << "-------------------------------------------\n";
		cout << "| " << left << setw(22) << "Date&Time";
		cout << "| " << left << setw(10) << "From";
		cout << "| " << left << setw(10) << "To";
		cout << "| " << left << setw(15) << "Amount";
		cout << "| " << left << setw(15) << "S.Balance";
		cout << "| " << left << setw(15) << "D.Balance";
		cout << "| " << left << setw(15) << "User";
		cout << "\n----------------------------------------------------------------";
		cout << "-------------------------------------------\n";

		if (vTransferLogRecords.size() == 0)
		{
			cout << "\t\t\t\t\t NO TRANSFER LOG IN THE SYSTEM\n";
		}
		else
		{
			for (clsBankClient::stTransferLog& Record : vTransferLogRecords)
			{
				_PrintTransferLogLine(Record);
				cout << endl;
			}
			cout << "\n----------------------------------------------------------------";
			cout << "-------------------------------------------\n";
		}
		

		cout << "\n\n";
	}
};

