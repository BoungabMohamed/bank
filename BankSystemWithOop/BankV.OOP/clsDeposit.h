#pragma once
#include <iostream>
#include <iomanip>
#include "clsTrransaction.h"
#include "clsScreen.h"
#include "clsBank.h"
#include "../../utilety/clsInputValidate.h"
class clsDeposit : protected clsScreen 
{
private:
	static void _PrintInformationClient(clsBankClient Client)
	{
		cout << "----------------------------------" << endl;
		cout << "Full Name      : " << Client.FirstName + " " + Client.LastName << endl;
		cout << "Email          : " << Client.Email << endl;
		cout << "Phone Number   : " << Client.PhoneNumber << endl;
		cout << "Account Number : " << Client.accountNumber() << endl;
		cout << "Pin Code       : " << Client.PinCode << endl;
		cout << "Balance        : " << Client.Balance << endl;
		cout << "----------------------------------" << endl;
	}
	static string _readAccountNumber()
	{
		return clsInputValidate::readString();
	}
public:
	static void depositScreen()
	{
		clsScreen::_drawHeader("Deposit Screen");
		cout << "Enter account number : ";
		string accountNumber = _readAccountNumber();
		while (!clsBankClient::isClientExist (accountNumber)) 
		{	
			cout << "enter again this is not Exist : ";
			accountNumber = _readAccountNumber();
		}
		clsBankClient Client = clsBankClient::find(accountNumber);
		Client.print();
		cout << "Enter the Amount : ";
		float amount;
		amount =(float)clsInputValidate::ReadDblNumber();
		char c = 'n';
		cout << "\nAre u sure To do this transaction y/N ? : ";
		cin >> c;
		if (c == 'Y' || c == 'y')
		{
			Client.Deposit(amount);
			cout << "Your New Balance is : " << Client.Balance << endl;
		}
		else
		{
			cout << "Ok" << endl;
		}
	}
};

