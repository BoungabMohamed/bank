#pragma once
#include <iostream>
#include "clsMainMenu.h"
#include "clsScreen.h"
#include "../../utilety/clsInputValidate.h"
#include "clsUser.h"
#include "Global.h"
#include "../../utilety/clsUtil.h"
class clsLoginScreen : protected clsScreen
{
private:
	static bool _logIn()
	{
		bool faild = false;
		string userName, password;
		short _trys = 0;
		do
		{
			if (faild)
			{
				if (_trys == 2)
				{
					cout << "Faild :(" << endl;
					return false;
				}
				cout << "Invalid user Name / Pass Word \n" << endl;
				_trys++;
				
				cout << "Your have : " << 3 - _trys << " left" << endl;
			}
			//CurrentUser.RegisterLogIn();
			cout << "Enter User Name : ";
			userName = clsInputValidate::readString();
			cout << "Enter Pass Word : ";
			password = clsInputValidate::readString();
			CurrentUser = clsUser::Find(userName, password);
			faild = CurrentUser.IsEmpty();
		} while (faild);
		//
		//CurrentUser.RegisterLogIn();
		system("cls");
		clsMainMenu::MainMenuScreen();
		return true;
	}
public:
	static bool showLogInScreen()
	{
		system("cls");
		_drawHeader("show LogIn Screen");
		return _logIn();
	} 
};

