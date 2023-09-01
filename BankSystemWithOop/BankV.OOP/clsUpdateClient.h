#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBank.h"
class clsUpdateClient : protected clsScreen 
{
private :
	static void _readClient(clsBankClient& Client)
	{
		clsScreen::_drawHeader("UpdateClient Screen ");
		cout << "------------------------------------------" << endl;
		cout << "    *Update Client information Screen*    " << endl;
		cout << "------------------------------------------" << endl;
		cout << "Enter First Name   : ";
		Client.FirstName = clsInputValidate::readString();
		cout << "Enter Last Name    : ";
		Client.LastName = clsInputValidate::readString();
		cout << "Enter Email        : ";
		Client.Email = clsInputValidate::readString();
		cout << "Enter Phone Number : ";
		Client.PhoneNumber = clsInputValidate::readString();
		cout << "Enter Pin code     : ";
		Client.PinCode = clsInputValidate::readString();
		cout << "Enter New balance  : ";
		Client.Balance = (float)clsInputValidate::ReadDblNumber();
	}
public:
	static void _updateClient()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pUpdateClients))
		{
			return;
		}
		string AccountNumber = "";
		do
		{
			cout << "Enter account Number to Update it : ";
			cin >> AccountNumber;
		} while (!clsBankClient::isClientExist(AccountNumber));
		system("cls");
		clsBankClient Client = clsBankClient::find(AccountNumber);
		Client.print();
		_readClient(Client);
		clsBankClient::enSaveResult saveResult = Client.save();
		if (saveResult == clsBankClient::enSaveResult::succes)
		{
			cout << "done saving" << endl;
			Client.print();
		}
		else
		{
			cout << "There is some think wrong :(" << endl;
		}
	}
};

