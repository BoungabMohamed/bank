#pragma once
#include "clsBank.h"
#include "clsScreen.h"
#include <iomanip>
#include <iostream>
class clsShowClientList : protected clsScreen 
{
private:
	static void _PrintClientRecordLine(clsBankClient Client)
	{

		cout << "| " << setw(15) << left << Client.accountNumber();
		cout << "| " << setw(20) << left << Client.FirstName;
		cout << "| " << setw(12) << left << Client.PhoneNumber;
		cout << "| " << setw(20) << left << Client.Email;
		cout << "| " << setw(10) << left << Client.PinCode;
		cout << "| " << setw(12) << left << Client.Balance;

	}
public:
	static void _showClientList()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pListClients))
		{
			return;
		}
		clsScreen::_drawHeader("Show Client List");
		vector <clsBankClient> vClients = clsBankClient::getClientList();

		cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << "| " << left << setw(15) << "Accout Number";
		cout << "| " << left << setw(20) << "Client Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(10) << "Pin Code";
		cout << "| " << left << setw(12) << "Balance";
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (vClients.size() == 0)
			cout << "\t\t\t\tNo Clients Available In the System!";
		else

			for (clsBankClient Client : vClients)
			{

				_PrintClientRecordLine(Client);
				cout << endl;
			}

		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	}
};

