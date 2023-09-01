#pragma once
#include <iostream>
using namespace std;
class clsPerson
{
private:
	string _firstName , _lastName , _phoneNumber , _email;
public :
	clsPerson(string firstName, string lastName, string phoneNumber, string email)
	{
		_firstName = firstName;
		_lastName = lastName;
		_phoneNumber = phoneNumber;
		_email = email;
	}
	clsPerson()
	{
		
	}
	void setFirstName(string firstName)
	{
		_firstName = firstName;
	}
	string firstName()
	{
		return _firstName;
	}
	__declspec (property (get = firstName, put = setFirstName)) string FirstName;
	void setLastName(string lastName)
	{
		_lastName = lastName;
	}
	string lastName()
	{
		return _lastName;
	}
	__declspec (property (get = lastName, put = setLastName)) string LastName;
	void setEmail(string email)
	{
		_email = email;
	}
	string email()
	{
		return _email;
	}
	__declspec (property (get = email, put = setEmail)) string Email;
	void setPhoneNumber(string phoneNumber)
	{
		_phoneNumber = phoneNumber;
	}
	string phoneNumber()
	{
		return _phoneNumber;
	}
	__declspec (property (get = phoneNumber, put = setPhoneNumber)) string PhoneNumber;
	void print()
	{
		cout << "----------------------------------\n" << endl;
		cout << "First Name   : " << _firstName << endl;
		cout << "Last Name    : " << _lastName << endl;
		cout << "Email        : " << _email << endl;
		cout << "Phone Number : " << _phoneNumber << endl;
		cout << "\n----------------------------------" << endl;

	}
};

