#include "stdafx.h"
#include "HashTable.h"

// Operator overloading > so that the sort function sorts by Account ID's
bool operator>(const Account& left, const Account right) 
{
	return left.ID > right.ID;
}

// Operator overloading < so that the sort function sorts by Account Date in Months
bool operator<(const Account& left, const Account right) 
{
	return left.Month < right.Month;
}

HashTable::HashTable(int size)
{
	this->size = size;
	// Defines data as a new set of accounts
	data = new Account*[size];

	for (int n = 0; n < size; n++) 
	{
		data[n] = NULL;
	}
}

int HashTable::HashFunction(string key)
{
	int sum = 0;

	for (int n = 0; n < key.length(); n++) 
	{
		// Increments sum based on key 
		sum += (int)key[n];
	}

	// Returns the size of the hash table 
	return sum % size;
}

Account * HashTable::Find(string key)
{
	int hash = HashFunction(key.c_str());

	// Iterates comparing Accounts to the key until no more Accounts remain
	while (data[hash] != NULL) 
	{
		// Compares an Account key with key passed to the Find function 
		if (data[hash]->key == key) 
		{
			// Outputs the Account data found
			cout << "ID " << data[hash]->ID << " : " << data[hash]->Username << " : " << data[hash]->Email << " : Edition " << data[hash]->Edition << " : Date " << data[hash]->Day << "/0" << data[hash]->Month << "/2018"<< endl;
			return data[hash];
		}
		// Moves onto next Account
		hash++;
		hash %= size;
	}

	return NULL;
}


void HashTable::Insert(Account * item)
{
	// Assigns key to new Account
	string key = item->key;
	// Calls to the hash function
	int hash = HashFunction(key.c_str());

	while (data[hash] != NULL) 
	{
		++hash;
		hash %= size;
	}

	// Assigns new item to the correct data hash location
	data[hash] = item;
}

Account * HashTable::Delete(string key)
{
	// Calls to hash function
	int hash = HashFunction(key.c_str());

	while (data[hash] != NULL) 
	{
		// Compares to see if key passed to function mataches a key in the hash table 
		if (data[hash]->key == key) 
		{
			Account * temp = data[hash];
			// Deletes account with matching key 
			data[hash] = NULL;
			// Returns a temp account to use to inform the user of the deleted account 
			return temp;
		}
		// Moves onto next account to compare
		++hash;
		hash %= size;
	}

	return NULL;
}


void HashTable::Display()
{
	for (int n = 0; n < size; n++) 
	{
		if (data[n] != NULL) 
		{
			// Displays the hash table
			cout << "ID " << data[n]->ID << " : " << data[n]->Username << " : " << data[n]->Email << " : Edition " << data[n]->Edition << " : Date " << data[n]->Day << "/0" << data[n]->Month << "/2018" << endl;
		}
	}
}

void HashTable::Sort()
{
	bool sorted = false;

	// Iterates comparing each account until they have all been compared 
	for (int i = 0; i < size; i++)
	{
		// Sorted modifys the algorithm to exit when no change needs to be made in the inner loop 
		if (sorted);
		sorted = true;
		for (int j = 0; j < (size - 1); j++)
		{
			// Swaps to sort ID using the > operator overloader 
			if (data[j] > data[j + 1])
			{
				Account* temp = data[j + 1];
				data[j + 1] = data[j];
				data[j] = temp;
				sorted = false;
			}

			// Swaps to sort Date using the < operator overloader 
			if (data[j + 1] < data[j])
			{
				Account* temp = data[j + 1];
				data[j + 1] = data[j];
				data[j] = temp;
				sorted = false;
			}
		}
	}

}