#pragma once
#include "clsScreen.h"
#include "../../utilety/clsInputValidate.h"
#include "clsShowClientList.h"
#include "clsAddNewClient.h"
#include "clsDeleteClient.h"
#include "clsUpdateClient.h"
#include "clsFindClient.h"
#include "clsTrransaction.h"
#include "clsManageUser.h"
#include "Global.h"
#include "clsShowLogInScreen.h"
#include "../Exechange/clsCurrencyMenu.h"
class clsMainMenu : protected clsScreen
{
private:
	enum enOptionMenu {
		ShowClintList = 1, AddNewClient = 2, DeleteClien = 3, UpdateClient = 4, FindClient = 5, Transaction = 6, ManageUser = 7, ScreenLogIn = 8, LogOut = 10, Currency = 9
	};
	static enOptionMenu _ReadMainMenuOption()
	{
		cout << "Chose Your Option [1 to 10] : ";
		short op = clsInputValidate::ReadIntNumberBetween(1, 10);
		return (enOptionMenu)op;
	}
	static void _showClientList()
	{
		clsShowClientList::_showClientList();
	}
	static void _addNewClient()
	{
		clsAddNewClient::_addNewClient();
	}
	static void _deleteClient()
	{
		clsDeleteClient::_deleteClient();
	}
	static void _updateClient()
	{
		clsUpdateClient::_updateClient();
	}
	static void _findClient()
	{
		clsFindClient::_findClient();
	}
	static void _manageUser()
	{
		clsManageUser::ShowManageUser();
	}
	static void _ShowLogInScreen()
	{
		clsShowLogInScreen::ShowLoginRegisterScreen();
	}
	static void _ExchangeMenu()
	{
		clsCurrencyMenu::TheCurrencyMenu();
	}
	static void _BacktoMainMenu()
	{
		cout << "\n\n\n\n\tPress any key to Return to the main Menu ." << endl;
		system("pause>0");
		system("cls");
		MainMenuScreen();
	}
	static void _perFormOptionMenu(enOptionMenu option)
	{
		switch (option)
		{
		case enOptionMenu::ShowClintList:
			system("cls");
			_showClientList();
			_BacktoMainMenu();
			break;

		case enOptionMenu::AddNewClient:
			system("cls");
			_addNewClient();
			_BacktoMainMenu();
			break;

		case enOptionMenu::DeleteClien:
			system("cls");
			_deleteClient();
			_BacktoMainMenu();
			break;

		case enOptionMenu::UpdateClient:
			system("cls");
			_updateClient();
			_BacktoMainMenu();
			break;

		case enOptionMenu::FindClient:
			system("cls");
			_findClient();
			_BacktoMainMenu();
			break;

		case enOptionMenu::Transaction:
			system("cls");
			clsTrransaction::TransactionScreen();
			system("pause>0");
			system("cls");
			MainMenuScreen();
			break;

		case enOptionMenu::ManageUser:
			system("cls");
			_manageUser();
			//_BacktoMainMenu();
			system("pause>0");
			system("cls");
			MainMenuScreen();
			break;
		case enOptionMenu::ScreenLogIn:
			system("cls");
			_ShowLogInScreen();
			_BacktoMainMenu();
			break;
		case enOptionMenu::Currency:
			system("cls");
			_ExchangeMenu();
			system("pause>0");
			system("cls");
			MainMenuScreen();
			break;
		case enOptionMenu::LogOut:
			system("cls");
			CurrentUser = clsUser::Find("", "");
			break;
		}
	}
public :
	static void MainMenuScreen()
	{
		CurrentUser.RegisterLogIn();
		clsScreen::_drawHeader("Main Menu Screen");
		cout << "===================================" << endl;
		cout << "===================================" << endl;
		cout << "    t[1] Show Clients List ." << endl;
		cout << "    t[2] Add New Client    ." << endl;
		cout << "    t[3] Delete Client     ." << endl;
		cout << "    t[4] Update Client     ." << endl;
		cout << "    t[5] Find Client       ." << endl;
		cout << "    t[6] Transaction       ." << endl;
		cout << "    t[7] Manage User       ." << endl;
		cout << "    t[8] Show LogIn Screen ." << endl;
		cout << "    t[9] Exchang Menu      ." << endl;
		cout << "    t[10] Log out          ." << endl;
		cout << "===================================" << endl;
		cout << "===================================" << endl;
		_perFormOptionMenu(_ReadMainMenuOption());
	}
};

