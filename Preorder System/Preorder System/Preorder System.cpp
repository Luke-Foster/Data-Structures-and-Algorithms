// Preorder System.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "HashTable.h"
#include <algorithm>
#include <cctype>
#include <vector>
#include <time.h>
#include <numeric>
#include <stdlib.h>
#include <cstdio>
#include <ctime>

using namespace std;

// User input variables
string Inputkey;
string InputUsername;
string InputEmail;
int InputEdition;

// Cancel order variables
string CancelResponse;
bool CancelTransaction = false;
bool ContinueTransaction = false;

void TenSecondTimer()
{
	// Creates a ten second timer
	clock_t start;
	float duration = 0.0f;

	// Initialises Clock function
	start = clock();

	// Iterates the while loop until the timer duration has reached ten seconds
	while (duration < 10.0f)
	{
		duration = (clock() - start) / (float)CLOCKS_PER_SEC;
	}
}

void EnterAccountDetails()
{
	// Prompts and recieves user input
	cout << "Enter Username : ";
	cin >> InputUsername;
	cout << endl;

	cout << "Enter Email : ";
	cin >> InputEmail;
	cout << endl;

	cout << "Enter Edition : ";
	cin >> InputEdition;
	cout << endl;

	// Error handling for when the User enters any integer other than 1, 2 and 3 
	while (InputEdition != 1 && InputEdition != 2 && InputEdition != 3)
	{
		cout << "Error: You must enter an edition of either 1, 2 or 3" << endl;
		cout << "Enter Edition : ";
		cin >> InputEdition;
		cout << endl;
	}

	// Users input becomes key and key is transformed into lowercase 
	Inputkey = InputUsername;
	transform(Inputkey.begin(), Inputkey.end(), Inputkey.begin(), ::tolower);
}

int main()
{	
	// Calls function to retrieve user inputs 
	EnterAccountDetails();

	// Creates an instance of HashTable and assigns a maximum of 10 accounts
	HashTable * table = new HashTable(10);
	// Predefined accounts are inserted into the hash table 
	table->Insert(new Account("hariscross", "HarisCross", 101, "HarisCross@hotmale.com", 1, 21, 1));
	table->Insert(new Account("ryangarner", "RyanGarner", 102, "RyanGarner@outlook.com", 3, 10, 2));
	table->Insert(new Account("lloydburton", "LloydBurton", 103, "LloydBurton@bucks.ac.uk", 1, 20, 2));
	table->Insert(new Account("mattfoley", "MattFoley", 104, "MattFoley@aol.com", 2, 15, 3));
	table->Insert(new Account("lukefoster", "LukeFoster", 105, "lukefoster19@hotmail.co.uk", 3, 20, 3));
	// Users inputs are inserted into a new account
	table->Insert(new Account(Inputkey, InputUsername, 106, InputEmail, InputEdition, 25, 05));
	// All accounts are displayed in the natural hash table order 
	table->Display();
	cout << endl;

	// Calls the Sort function to enhance bubble sort the hash table
	table->Sort();
	// Displays the newly sorted hash table
	table->Display();

	cout << endl;

	// Prompts and recieves users decision to cancel their order 
	cout << "Would you like to cancel your order? (Y/N)" << endl;
	cin >> CancelResponse;
	cout << endl;

	// Checks Users response and will continously iterate for a new response if response is not y or n
	while(CancelTransaction == false && ContinueTransaction == false)
	{
		if (CancelResponse == "n" || CancelResponse == "N")
		{
			// Breaks while loop 
			ContinueTransaction = true;
		}
		else if (CancelResponse == "y" || CancelResponse == "Y")
		{
			// Breaks while loop
			CancelTransaction = true;
		}
		else
		{
			cout << "Please enter either Y or N" << endl;
			cin >> CancelResponse;
		}
	}

	if (ContinueTransaction == true)
	{
		cout << "10 seconds until your order is shipped" << endl;
		// Calls for a ten second timer
		TenSecondTimer();
		// Finds  and displays the users order from within hash table
		table->Find(Inputkey);
		cout << "Your order has been shipped" << endl;
	}

	if (CancelTransaction == true)
	{
		cout << "Your order has been cancelled" << endl;
		// Deletes the users account from the hash table
		table->Delete(Inputkey);
		cout << "The temporary account has been deleted" << endl;
	}

	system("PAUSE");
    return 0;
}