#pragma once
#include <iostream>
#include <iomanip>
#include "clsBank.h"
#include "clsScreen.h"
#include "clsPerson.h"
#include "../../utilety/clsInputValidate.h"
#include "clsUserListScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"
using namespace std;
class clsManageUser : protected clsScreen 
{
private:
	enum enOption { eListUser = 1, eAddUser = 2, eDeleteUser = 3, eUpUSer = 4, eFindUser = 5, eBack = 6 };
	static enOption _readOp()
	{
		return (enOption)clsInputValidate::ReadIntNumberBetween(1, 6);
	}
	static void _UserList()
	{
		clsUserListScreen::ShowUsersList();
	}
	static void _AddUser()
	{
		clsAddNewUserScreen::ShowAddNewUserScreen();
	}
	static void _DeleteUser()
	{
		clsDeleteUserScreen::ShowDeleteUserScreen();
	}
	static void _UpdateUser()
	{
		clsUpdateUserScreen::ShowUpdateUserScreen();
	}
	static void _FindUser()
	{
		clsFindUserScreen::ShowFindUserScreen();
	}
	static void _backToManageScreen()
	{
		cout << "\n\npress any key To back ..." << endl;
		system("pause>0");
		system("cls");
		ShowManageUser();
	}

	static void _perFromOption(enOption Option)
	{
		switch (Option)
		{
		case enOption::eListUser:
			system("cls");
			_UserList();
			_backToManageScreen();
			break;
		case enOption::eAddUser:
			system("cls");
			_AddUser();
			_backToManageScreen();
			break;
		case enOption::eDeleteUser:
			system("cls");
			_DeleteUser();
			_backToManageScreen();
			break;
		case enOption::eUpUSer:
			system("cls");
			_UpdateUser();
			_backToManageScreen();
			break;
		case enOption::eFindUser:
			system("cls");
			_FindUser();
			_backToManageScreen();
			break;

		case enOption::eBack:
			break;
		}
	}
public:
	static void ShowManageUser()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pManageUsers))
		{
			return;
		}
		_drawHeader("Manage User Screen");
		cout << "==================================" << endl;
		cout << "==================================" << endl;
		cout << "    [1] List user    ." << endl;
		cout << "    [2] Add New user ." << endl;
		cout << "    [3] Delete User  ." << endl;
		cout << "    [4] Update Usre  ." << endl;
		cout << "    [5] Find user    ." << endl;
		cout << "    [6] Back         ." << endl;
		cout << "==================================" << endl;
		cout << "==================================" << endl;
		_perFromOption(_readOp());
	}
};

