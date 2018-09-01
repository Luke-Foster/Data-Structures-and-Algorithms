#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include "Account.h"

using namespace std;

class HashTable
{
private:
	// Variables
	int size;
	Account ** data;
public:
	// Functions
	HashTable(int size);
	int HashFunction(string key);
	Account * Find(string key);
	Account * Delete(string key);
	void Insert(Account *item);
	void Display();
	void Sort();
};

