#pragma once
#include <iostream>
#include "clsBank.h"
#include <iomanip>
#include "clsScreen.h"
class clsAddNewClient : protected clsScreen  
{
private:
	static void _readClient(clsBankClient& Client)
	{
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
	static void _addNewClient()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pAddNewClient))
		{
			return;
		}
		string AccountNumber = "";
		do
		{
			cout << "Enter account Number to add it : ";
			cin >> AccountNumber;
		} while (clsBankClient::isClientExist(AccountNumber));
		clsBankClient New = clsBankClient::getNewClientObject(AccountNumber);
		_readClient(New);
		clsBankClient::enSaveResult resultOfSaving = New.save();
		switch (resultOfSaving)
		{
		case clsBankClient::enSaveResult::faid:
			cout << "Sorry the is an error " << endl;
			break;
		case clsBankClient::enSaveResult::succes:
			cout << "Add Succefully" << endl;
			break;
		case clsBankClient::enSaveResult::itIsExist:
			cout << "the account number is aready exist" << endl;
			break;
		}
	}

};

