#pragma once
#include <string>

using namespace std;

class Substitution {
public:
	string* Encrypt();
	string* Encrypt(string Key);
	string* Decrypt(string message);
};