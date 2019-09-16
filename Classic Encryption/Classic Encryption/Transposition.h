#pragma once
#include <iostream>
#include <random>

using namespace std;

class Transposition {
public:
	struct MessageInfo {
		int *key;
		int period;
		string message;
	}; // Used to store encryption information
	MessageInfo Encrypt(MessageInfo message);
	string Decrypt(MessageInfo message);
};

