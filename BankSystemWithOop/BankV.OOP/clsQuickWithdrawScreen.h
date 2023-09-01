#pragma once
#include <iostream>
#include <iomanip>
#include "clsBank.h"
#include "clsScreen.h"
#include "D:/lib/utilety/clsInputValidate.h"
using namespace std;
class clsQuickWithdrawScreen : protected clsScreen
{
private :
	enum eQkWithdrawOption { efirsOp = 1, eSecondOp = 2, eThourdOp = 3, eFourthOp = 4 };
	static eQkWithdrawOption _ReadOption()
	{
		return (eQkWithdrawOption)clsInputValidate::ReadIntNumberBetween(1, 4);
	}
	static void _perFormOption(eQkWithdrawOption option)
	{
		switch (option)
		{
		case eQkWithdrawOption::efirsOp:
			break;

		case eQkWithdrawOption::eSecondOp:
			break;

		case eQkWithdrawOption::eThourdOp:
			break;

		case eQkWithdrawOption::eFourthOp:
			break;
		}
	}
public:
	static void quickWithdraw()
	{
		clsScreen::_drawHeader("Quick Withdraw screen");
		cout << "============================" << endl;
		cout << "============================" << endl;
		cout << "   [1] = 100   [2] = 200    " << endl;
		cout << "   [3] = 500   [4] = 1000   " << endl;
		cout << "============================" << endl;
		cout << "============================" << endl;
		_perFormOption(_ReadOption());
	}
};

