#pragma once
#include <string>

using namespace std;

constexpr int SIZE = 2;

class Substitution {
public:
	string* Encrypt();
	string* Encrypt(string Key);
	string Decrypt(string message[SIZE]);
};