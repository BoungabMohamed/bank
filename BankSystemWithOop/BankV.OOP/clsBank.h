#pragma once
#include <iostream>
#include "clsPerson.h"
#include "../../dateLib/clsDate.h"
#include "../../stringLib/clsString.h"
#include "../../utilety/clsInputValidate.h"
#include "../../utilety/clsUtil.h"
#include <fstream>
using namespace std;
class clsBankClient : public clsPerson
{
private:
	enum enMode { emptyMode = 0, updateMode = 1 , addNew = 2};
	string _accountNumber, _pinCode;
	float _balance;
	enMode _mode;
	bool _flag;
	static clsBankClient _convecrtLineToClientObject(string line, string sepirator = "#//#")
	{
		vector <string> ClientInformation = clsString::Split(line, sepirator);
		return clsBankClient(enMode::updateMode, ClientInformation[0], ClientInformation[1], ClientInformation[2], ClientInformation[3], ClientInformation[4], ClientInformation[5], (float)stod(ClientInformation[6]));
	}
	static clsBankClient _EmptyClientObject()
	{
		return clsBankClient(enMode::emptyMode, "", "", "", "", "", "", 0);
	}
	static string _convertClientObjectToLine(clsBankClient Clinet , string sepirator = "#//#")
	{
		string line = "";
		return (line + Clinet.FirstName + sepirator + Clinet.LastName + sepirator + Clinet.Email
			+ sepirator + Clinet.PhoneNumber + sepirator + Clinet.accountNumber() + sepirator
			+ Clinet.PinCode + sepirator + to_string(Clinet.Balance));
	}
	static vector <clsBankClient> _loadDataFromFile()
	{
		vector <clsBankClient> vAllDataClients;
		fstream f;
		f.open("Clients.txt", ios::in);
		string line;
		if (f.is_open())
		{
			while (getline(f, line))
			{
				vAllDataClients.push_back(_convecrtLineToClientObject(line));
			}
			f.close();
			return vAllDataClients;
		}
		else
		{
			exit(1);
		}
	}
	static void _saveLinetoFile(string line)
	{
		fstream f;
		f.open("Clients.txt", ios::in | ios::app);
		if (f.is_open())
		{
			f << line << endl;
		}
		f.close();
	}
	static void _saveClientsToFile(vector <clsBankClient> vAllClients)
	{
		fstream f;
		f.open("Clients.txt", ios::out);
		if (f.is_open())
		{
			for (clsBankClient& one : vAllClients)
			{
				if (one._flag == false)
				{
					f << (_convertClientObjectToLine(one)) << endl;
				}
			}
		}
		f.close();
	}
	void _update()
	{
		vector <clsBankClient> vAllClients = _loadDataFromFile();
		for (clsBankClient& one : vAllClients)
		{
			if (one.accountNumber() == this->accountNumber())
			{
				one = *this;
			}
		}
		_saveClientsToFile(vAllClients);
	}
	void _add()
	{
		_saveLinetoFile(_convertClientObjectToLine(*this));
	}
	string _PrepareTransferLogRecord(float Amount, clsBankClient DestinationClient,
		string UserName, string Seperator = "#//#")
	{
		string TransferLogRecord = "";
		TransferLogRecord += clsDate::GetSystemDateTimeString() + Seperator;
		TransferLogRecord += accountNumber() + Seperator;
		TransferLogRecord += DestinationClient.accountNumber() + Seperator;
		TransferLogRecord += to_string(Amount) + Seperator;
		TransferLogRecord += to_string(Balance) + Seperator;
		TransferLogRecord += to_string(DestinationClient.Balance) + Seperator;
		TransferLogRecord += UserName;
		return TransferLogRecord;
	}

	void _RegisterTransferLog(float Amount, clsBankClient DestinationClient, string UserName)
	{

		string stDataLine = _PrepareTransferLogRecord(Amount, DestinationClient, UserName);

		fstream MyFile;
		MyFile.open("Trans.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << stDataLine << endl;

			MyFile.close();
		}

	}
public:
	struct stTrnsferLogRecord
	{
		string DateTime = "";
		string SourceAccountNumber = "";
		string DestinationAccountNumber = "";
		float Amount = 0.0;
		float srcBalanceAfter = 0.0;
		float destBalanceAfter = 0.0;
		string UserName = "";

	};
	clsBankClient(enMode Mode, string firstName, string lastName, string email, string phoneNumber
		, string accountNumber, string pinCode, float balace) :
		clsPerson(firstName, lastName, phoneNumber, email)
	{
		_mode = Mode;
		_accountNumber = accountNumber;
		_pinCode = pinCode;
		_balance = balace;
		_flag = false;
	}
	bool isEmpty()
	{
		return (_mode == enMode::emptyMode);
	}
	string accountNumber()
	{
		return _accountNumber;
	}
	void setPinCode(string pinCode)
	{
		_pinCode = pinCode;
	}
	string pinCode()
	{
		return _pinCode;
	}
	__declspec (property (get = pinCode, put = setPinCode)) string PinCode;
	void setBalance(float balance)
	{
		_balance = balance;
	}
	float balance()
	{
		return _balance;
	}
	__declspec (property (get = balance, put = setBalance)) float Balance;
	void print()
	{
		cout << "--------------------" << " Client Information " << "--------------------\n" << endl;
		cout << "First Name     : " << FirstName << endl;
		cout << "Last Name      : " << LastName << endl;
		cout << "Email          : " << Email << endl;
		cout << "Phone Number   : " << PhoneNumber << endl;
		cout << "Account Number : " << _accountNumber << endl;
		cout << "Pin Code       : " << _pinCode << endl;
		cout << "Balance        : " << _balance << endl;
		cout << "\n------------------------------------------------------------" << endl;
	}
	static clsBankClient find(string accountNumber)
	{
		fstream f;
		f.open("Clients.txt", ios::in);
		vector <clsBankClient> AllClients;
		if (f.is_open())
		{
			string line;
			while (getline(f, line))
			{
				clsBankClient Client = _convecrtLineToClientObject(line);
				if (Client.accountNumber() == accountNumber)
				{
					f.close();
					return Client;
				}
				AllClients.push_back(Client);
			}
			f.close();
		}
		return _EmptyClientObject();
	}
	static clsBankClient find(string accountNumber, string PinCode)
	{
		fstream f;
		f.open("Clients.txt", ios::in);
		vector <clsBankClient> AllClients;
		if (f.is_open())
		{
			string line;
			while (getline(f, line))
			{
				clsBankClient Client = _convecrtLineToClientObject(line);
				if (Client.accountNumber() == accountNumber && Client.pinCode() == PinCode)
				{
					f.close();
					return Client;
				}
				AllClients.push_back(Client);
			}
			f.close();
		}
		return _EmptyClientObject();
	}
	static bool isClientExist(string accountNumber)
	{
		clsBankClient Client = find(accountNumber);
		return (!Client.isEmpty());
	}
	enum enSaveResult { faid = 0, succes = 1 , itIsExist = 2 , deleteSave = 3};
	enSaveResult save()
	{
		switch (_mode)
		{
		case enMode::emptyMode:
			return enSaveResult::faid;
			break;
		case enMode::updateMode:
			_update();
			return enSaveResult::succes;
			break;
		case enMode::addNew:
			_add();
			_mode = enMode::updateMode;
			return enSaveResult::succes;
			break;
		
		}
		return enSaveResult::faid;
	}
	static clsBankClient getNewClientObject(string accountNumber)
	{
		return clsBankClient(enMode::addNew, "", "", "", "", accountNumber, "", 0);
	}
	bool Delete()
	{
		vector <clsBankClient> vClients = _loadDataFromFile();
		for (clsBankClient& one : vClients)
		{
			if (one.accountNumber() == this->accountNumber())
			{
				one._flag = true;
				break;
			}
		}
		_saveClientsToFile(vClients);
		string t = "";
		*this = _EmptyClientObject();
		return true;
	}
	static vector <clsBankClient> getClientList()
	{
		return _loadDataFromFile();
	}
	static double TotalBalance()
	{
		double total = 0.0;
		vector <clsBankClient> vClients = getClientList();
		if (vClients.size() == 0)
		{
			return 0;
		}
		for (clsBankClient& one : vClients)
		{
			total += one.Balance;
		}
		return total;
	}
	void Deposit(float amount)
	{
		_balance += amount;
		save();
	}
	void Withdraw(float amount)
	{
		_balance -= amount;
		save();
	}
	static double GetTotalBalances()
	{
		vector <clsBankClient> vClients = clsBankClient::getClientList();

		double TotalBalances = 0;

		for (clsBankClient Client : vClients)
		{

			TotalBalances += Client.Balance;
		}

		return TotalBalances;
	}
	bool Transfer(float Amount, clsBankClient& DestinationClient , string User)
	{
		if (Amount > Balance)
		{
			return false;
		}

		Withdraw(Amount);
		DestinationClient.Deposit(Amount);
		_RegisterTransferLog(Amount, DestinationClient,User);
		return true;
	}
	static stTrnsferLogRecord _ConvertTransferLogLineToRecord(string Line, string Seperator = "#//#")
	{
		stTrnsferLogRecord TrnsferLogRecord;

		vector <string> vTrnsferLogRecordLine = clsString::Split(Line, Seperator);
		TrnsferLogRecord.DateTime = vTrnsferLogRecordLine[0];
		TrnsferLogRecord.SourceAccountNumber = vTrnsferLogRecordLine[1];
		TrnsferLogRecord.DestinationAccountNumber = vTrnsferLogRecordLine[2];
		TrnsferLogRecord.Amount =(float) stod(vTrnsferLogRecordLine[3]);
		TrnsferLogRecord.srcBalanceAfter = (float)stod(vTrnsferLogRecordLine[4]);
		TrnsferLogRecord.destBalanceAfter = (float)stod(vTrnsferLogRecordLine[5]);
		TrnsferLogRecord.UserName = vTrnsferLogRecordLine[6];

		return TrnsferLogRecord;

	}
	static  vector <stTrnsferLogRecord> GetTransfersLogList()
	{
		vector <stTrnsferLogRecord> vTransferLogRecord;

		fstream MyFile;
		MyFile.open("Trans.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{

			string Line;

			stTrnsferLogRecord TransferRecord;

			while (getline(MyFile, Line))
			{

				TransferRecord = _ConvertTransferLogLineToRecord(Line);

				vTransferLogRecord.push_back(TransferRecord);

			}

			MyFile.close();

		}

		return vTransferLogRecord;

	}
};

