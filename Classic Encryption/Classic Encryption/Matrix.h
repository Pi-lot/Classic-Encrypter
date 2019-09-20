#pragma once
#include <iostream>
#include <random>
#include <math.h>

using namespace std;

class Matrix {
private:
	char ALPHABET[94]{ 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
		't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O',
		'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '\,', '\.', '\/', '\;', '\'', '[', ']', '\\', '0', '1',
		'2', '3', '4', '5', '6', '7','8', '9', '\`', '\~', '\!', '\@', '\#', '\$', '\%', '\^', '\&', '\*', '\(', '\)', '\-', '\_',
		'\+', '\|', '\<', '\>', '\?', '\:', '\"', '\{', '\}', '\ '};
public:
	int CharToInt(char character);
	char IntToChar(int num);
	string Encrypt(int *key, int keySize, string message);
	string Decrypt(string ciphertext);
};

