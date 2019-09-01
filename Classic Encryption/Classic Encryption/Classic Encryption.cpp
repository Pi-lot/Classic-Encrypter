#include <iostream>
#include "Substitution.h"
#include "Caesar.h"
#include "Matrix.h"
#include "Transposition.h"

using namespace std;

void SubstitutionEncode() {
	cout << "Using Substitution Cipher" << endl << "Would you like to specify a key? (no or n if you don't know)" << endl;
	string key;
	getline(cin, key);
	for (int i = 0; i < key.length(); i++) {
		key[i] = tolower(key[i]);
	}

	if (!key._Equal("n") && !key._Equal("no") && !key._Equal("y") && !key._Equal("yes")) {
		cout << "Didn't recongise that input" << endl;
		SubstitutionEncode();
	}

	string message;
	cout << "Message to encrypt: ";
	getline(cin, message);

	cout << "Encrypting: " << message << endl;

	Substitution sub;
	string* result;

	if (key._Equal("n") || key._Equal("no")) {
		result = sub.Encrypt(message);
		key = result[0];
		message = result[1];
	} else {
		getline(cin, key);
		result = sub.Encrypt(key);
	}

	delete result;
}

int main() {
	while (true) {
		cout << "Which cipher do you wish to use? (Substitution, Transposition, Caesar, Hill)" << endl;
		string cipher;
		getline(cin, cipher);
		for (int i = 0; i < cipher.length(); i++) {
			cipher[i] = tolower(cipher[i]);
		}

		if (cipher._Equal("exit"))
			break;
		//run = false;
	//else if (cipher._Equal("substitution"))
		SubstitutionEncode();
	}
	cout << "Exited" << endl;
}