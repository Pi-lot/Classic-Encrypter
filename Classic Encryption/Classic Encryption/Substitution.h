#pragma once
#include <string>
#include <random>

using namespace std;

const int SIZE = 2;
const int ALPHABETSIZE = 26;

class Substitution {
public:
	string* Encrypt(string message);
	string* Encrypt(string Key, string message);
	string Decrypt(string message[SIZE]);
};