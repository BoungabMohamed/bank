#pragma once
#include <iostream>
#include "Global.h"
#include "clsUser.h"
#include "../../dateLib/clsDate.h"
using namespace std;

class clsScreen  
{  
protected:
	static void _drawHeader(string titel)
	{
		cout << "-------------------------------------------\n" << endl;
		cout << "             " << titel << endl;
        cout << "User is     :" << CurrentUser.FirstName << endl ;
        cout << "Date        :" << clsDate::DateToString(clsDate()) << endl;
		cout << "\n-------------------------------------------\n" << endl;
	}
    static bool CheckAccessRights(clsUser::enPermissions Permission)
    {

        if (!CurrentUser.CheckAccessPermission(Permission))
        {
            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
            cout << "\n\t\t\t\t\t______________________________________\n\n";
            return false;
        }
        else
        {
            return true;
        }

    }
};
