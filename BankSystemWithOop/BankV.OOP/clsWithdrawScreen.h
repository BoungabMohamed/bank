#pragma once
#include <iostream>
#include <iomanip>
#include "clsTrransaction.h"
#include "clsScreen.h"
#include "clsBank.h"
#include "../../utilety/clsInputValidate.h"
class clsWithdrawScreen : protected clsScreen 
{
private:
	static string _readAccountNumber()
	{
		return clsInputValidate::readString();
	}
public:
	static void Withdraw()
	{
		clsScreen::_drawHeader("Deposit Screen");
		cout << "Enter account number : ";
		string accountNumber = _readAccountNumber();
		while (!clsBankClient::isClientExist(accountNumber))
		{
			cout << "enter again this is not Exist : ";
			accountNumber = _readAccountNumber();
		}
		clsBankClient Client = clsBankClient::find(accountNumber);
		Client.print();
		cout << "Enter the Amount : ";
		float amount;
		amount = (float)clsInputValidate::ReadDblNumberBetween(1 , Client.Balance , "You Dont Have this");
		char c = 'n';
		cout << "\nAre u sure To do this transaction y/N ? : ";
		cin >> c;
		if (c == 'Y' || c == 'y')
		{
			Client.Withdraw(amount);
			cout << "Withdraw is done your new balanca is : " << Client.Balance << endl;
		}
		else
		{
			cout << "Ok" << endl;
		}
		
	}
};

