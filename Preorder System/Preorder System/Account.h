#pragma once
#include "string"

using namespace std;

class Account
{
public:
	string key;
	string Username;
	int ID;
	string Email;
	int Edition;
	int Day;
	int Month;

	// Account constructor that defines the Account variables
	Account(string key, string Username, int ID, string Email, int Edition, int Day, int Month)
	{
		this->key = key;
		this->Username = Username;
		this->ID = ID;
		this->Email = Email;
		this->Edition = Edition;
		this->Day = Day;
		this->Month = Month;
	}
};