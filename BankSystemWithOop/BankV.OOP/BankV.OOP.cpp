#include <iostream>
#include "clsBank.h"
#include "clsLoginScreen.h"
using namespace std;









int main()
{
	while (clsLoginScreen::showLogInScreen()){}
	return 0;
}