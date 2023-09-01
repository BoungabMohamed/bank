#pragma once
#include <iostream>
#include <iomanip>
#include "ClsCurrncey.h"
#include "../../utilety/clsInputValidate.h"
//#include "D:/lib/stringLib/clsString.h"
#include <vector>
class clsFindCurr
{
private:
	enum enSearchOption{eByCode = 1 , eByConrty = 2};
	static enSearchOption readOption()
	{
		cout << "Do you want search By code [1] or by contry [2] ? : ";
		return (enSearchOption)clsInputValidate::ReadIntNumberBetween(1, 2);
	}
	static void _PrintCurrency(clsCurrency Currency)
	{
		cout << "\nCurrency Card:\n";
		cout << "_____________________________\n";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$) = : " << Currency.Rate();

		cout << "\n_____________________________\n";

	}

	static void _ShowResults(clsCurrency Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << "\nCurrency Found :-)\n";
			_PrintCurrency(Currency);
		}
		else
		{
			cout << "\nCurrency Was not Found :-(\n";
		}
	}
public:
	static void FindCurrnecy()
	{
		enSearchOption UserOption = readOption();
		string str;
		cout << "Eter name : ";
		str = clsInputValidate::readString();
		if (UserOption == enSearchOption::eByCode)
		{
			clsCurrency curr = clsCurrency::FindByCode(str);
			_ShowResults(curr);
		}
		else
		{	
			clsCurrency curr = clsCurrency::FindByCountry(str);
			_ShowResults(curr);
		}
	}
	
};

