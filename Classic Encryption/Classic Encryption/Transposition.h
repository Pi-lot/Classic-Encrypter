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
	};
	MessageInfo Encode(MessageInfo message);
	string Decode(MessageInfo message);
};

