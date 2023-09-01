#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBank.h"
class clsFindClient : protected clsScreen 
{
public:
	static void _findClient()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pFindClient))
		{
			return;
		}
		clsScreen::_drawHeader("Find Client Screen");
		string AccountNumber = "";
		do
		{
			cout << "Enter account Number to Delete it it : ";
			cin >> AccountNumber;
		} while (!clsBankClient::isClientExist(AccountNumber));
		clsBankClient Client = clsBankClient::find(AccountNumber);
		Client.print();
	}
};

