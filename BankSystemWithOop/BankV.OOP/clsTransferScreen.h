#pragma once
#include <iostream>
#include <iomanip>
#include "../../dateLib/clsDate.h"
#include "../../utilety/clsInputValidate.h"
#include "../../stringLib/clsString.h"
#include "clsUser.h"
#include "clsScreen.h"
#include "clsBank.h"
#include "Global.h"
using namespace std;

class clsTransferScreen : protected clsScreen
{
private:
	static void _PrintClient(clsBankClient cl)
	{
		cout << "------------------------------" << endl;
		cout << "Account Number : " << cl.accountNumber() << endl;
		cout << "Full Name      : " << cl.FirstName + " " + cl.LastName << endl;
		cout << "Balance        : " << cl.Balance << endl;
		cout << "------------------------------" << endl;
	}
public:
	static void TransferScreen()
	{
		_drawHeader("Transfer Screen");
		string AccountNumber;
		cout << "Enter The Account Number To send from : ";
		AccountNumber = clsInputValidate::readString();
		while (!clsBankClient::isClientExist (AccountNumber))
		{
			cout << "This is not Exist enter another one : ";
			AccountNumber = clsInputValidate::readString();
		}
		cout << endl;
		clsBankClient Client1 = clsBankClient::find(AccountNumber);
		_PrintClient(Client1);
		cout << "Enter The Account Number send : ";
		AccountNumber = clsInputValidate::readString();
		while (!clsBankClient::isClientExist(AccountNumber))
		{
			cout << "This is not Exist enter another one : ";
			AccountNumber = clsInputValidate::readString();
		}
		clsBankClient Client2 = clsBankClient::find(AccountNumber);
		_PrintClient(Client2);
		float amount = 0;
		cout << "Enter the amoun : ";
		amount = (float)clsInputValidate::ReadDblNumberBetween (1 , Client1.Balance , "You dont have this amunt");
		char c = 'n';
		cout << "Do you Want to continue Y/n ? :";
		cin >> c;
		if (c == 'y' || c == 'Y')
		{
			Client1.Transfer(amount, Client2,CurrentUser.UserName);
			_PrintClient(Client1);
			_PrintClient(Client2);
		}
		else
		{
			cout << "Ok" << endl;
		}
	}
};
