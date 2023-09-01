#pragma once
#include <iostream>
#include <iomanip>
#include "clsBank.h"
#include "clsScreen.h"
#include "../../utilety/clsInputValidate.h"
#include "clsMainMenu.h"
#include "clsBank.h"
#include "clsDeposit.h"
#include "clsWithdrawScreen.h"
#include "clsVeiwBalance.h"
#include "clsTransferScreen.h"
#include "clsTransLog.h"
using namespace std;
class clsTrransaction : protected clsScreen
{
private:
	enum _enTrasactionOption { _back = 6 , _eTransfer = 4 , TransLog = 5
		, _eNormalWithdraw = 1, _eDeposit = 2, _eBalance = 3 };
	static _enTrasactionOption ReadOption()
	{
		cout << "Enter Your Option [1 To 5] : ";
		return (_enTrasactionOption)clsInputValidate::ReadIntNumberBetween(1, 5);
	}
	static void _Withdraw()
	{
		clsWithdrawScreen::Withdraw();
	}
	static void _deposit()
	{
		clsDeposit::depositScreen();
	}
	static void _viewBalance()
	{
		clsVeiwBalance::ShowTotalBalances();
	}
	static void _goBackTransactionScreen()
	{
		cout << "\tpress any key to go to the Transaction screen ...";
		system("pause>0");
		system("cls");
		TransactionScreen();
	}
	static void _TransferScreen()
	{
		clsTransferScreen::TransferScreen();
	}
	static void TransLogScreen()
	{
		clsTransLog::ShowTransferLogScreen();
	}

	static void perFromOption(_enTrasactionOption option)
	{
		switch (option)
		{
		case _enTrasactionOption::_eNormalWithdraw:
			system("cls");
			_Withdraw();
			_goBackTransactionScreen();
			break;

		case _enTrasactionOption::_eDeposit:
			system("cls");
			_deposit();
			_goBackTransactionScreen();
			break;

		case _enTrasactionOption::_eBalance:
			system("cls");
			_viewBalance();
			_goBackTransactionScreen();
			break;
		case _enTrasactionOption::_eTransfer:
			system("cls");
			_TransferScreen();
			_goBackTransactionScreen();
			break;
		case _enTrasactionOption::TransLog:
			system("cls");
			TransLogScreen();
			_goBackTransactionScreen();
			break;
		case _enTrasactionOption::_back:
			break;
		}
	}
public:
	static void TransactionScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pTranaction))
		{
			return;
		}
		clsScreen::_drawHeader("Transaction Screen : ");
		cout << "===============================" << endl;
		cout << "===============================" << endl;
		cout << "    [1] Withdraw             ." << endl;
		cout << "    [2] deposit              ." << endl;
		cout << "    [3] total balance        ." << endl;
		cout << "    [4] Transfer             ." << endl;
		cout << "    [5] Transfer log         ." << endl;
		cout << "    [6] Back                 ." << endl;
		cout << "===============================" << endl;
		cout << "===============================" << endl;
		perFromOption(ReadOption());
	}
};