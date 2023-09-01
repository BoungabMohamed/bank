#pragma once
#include <iostream>
#include <iomanip>
#include "clsBank.h"
#include "clsScreen.h"
class clsDeleteClient : protected clsScreen 
{
private:

public:

	static void _deleteClient()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pAddNewClient))
		{
			return;
		}
		clsScreen::_drawHeader("Delete Client Screen");
		string AccountNumber = "";
		do
		{
			cout << "Enter account Number to Delete it it : ";
			cin >> AccountNumber;
		} while (!clsBankClient::isClientExist(AccountNumber));
		clsBankClient Client = clsBankClient::find(AccountNumber);
		Client.print();
		cout << "\nDo you want to Delete it Y/n ? : ";
		char b = 'n';
		cin >> b;
		if (b == 'y' || b == 'Y')
		{
			if (Client.Delete())
			{
				cout << "Done" << endl;
			}
			Client.print();
		}
		else
		{
			cout << "Ok" << endl;
		}
	}
};

