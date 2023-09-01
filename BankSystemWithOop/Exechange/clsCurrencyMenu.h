#pragma once
#include <iostream>
#include <iomanip>
#include "ClsCurrncey.h"
#include "../../utilety/clsInputValidate.h"
//#include "D:/lib/stringLib/clsString.h"
#include <vector>
#include "clsListCurrnecy.h"
#include "clsFindCurr.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrnceyCalculator.h"
class clsCurrencyMenu //: protected clsScreen
{
private:
	enum enOption { eCurrncyList = 1, eFindCurrency = 2, eUpdateRate = 3, eCurrencyCalculator = 4, eBack = 5 };
	static enOption _ReadOption()
	{
		return (enOption)clsInputValidate::ReadIntNumberBetween(1, 5);
	}
	static void _CurrncyList()
	{
		//cout << "Comming Soon ..." << endl;
		clsListCurrnecy::ShowCurrenciesListScreen();
	}
	static void _FindCurrncy()
	{
		//cout << "Comming Soon ..." << endl;
		clsFindCurr::FindCurrnecy();
	}
	static void _UpdateRate()
	{
		clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
	}
	static void _CurrncyCalculator()
	{
		//cout << "Comming Soon ..." << endl;
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}
	static void _BackToMainMenu()
	{
		//cout << "Comming Soon ..." << endl;
	}
	static void _Return()
	{
		cout << "\n\n\n\tPerss any key to Return to Currency Menu" << endl;
		system("pause>0");
		system("cls");
		TheCurrencyMenu();
	}
	static void _performOption(enOption op)
	{
		switch (op)
		{
		case enOption::eCurrncyList:
			system("cls");
			_CurrncyList();
			_Return();
			break;

		case enOption::eFindCurrency:
			system("cls");
			_FindCurrncy();
			_Return();
			break;

		case enOption::eUpdateRate:
			system("cls");
			_UpdateRate();
			_Return();
			break;

		case enOption::eCurrencyCalculator:
			system("cls");
			_CurrncyCalculator();
			_Return();
			break;

		case enOption::eBack:

			break;
		}
	}
public:
	static void TheCurrencyMenu()
	{
		//clsScreen::_drawHeader("Currency Menu");
		cout << "=====================================" << endl;
		cout << "=====================================" << endl;
		cout << "     [1] Currency List ." << endl;
		cout << "     [2] Find Currency ." << endl;
		cout << "     [3] Update Rate   ." << endl;
		cout << "     [4] Currency Calculator ." << endl;
		cout << "     [5] Main Menu ." << endl;
		cout << "=====================================" << endl;
		cout << "=====================================" << endl;
		_performOption(_ReadOption());
	}
};

