#include <iostream>
#include "Substitution.h"
#include "Caesar.h"
#include "Matrix.h"
#include "Transposition.h"

using namespace std;

// Method for calling encryption using the substitution cipher
void SubstitutionEncode() {
	cout << "Using Substitution Cipher Encode" << endl <<
		"Would you like to specify a key (y or n)? (n if you don't know)" << endl;
	string key;
	getline(cin, key);
	for (int i = 0; i < key.length(); i++) {
		key[i] = tolower(key[i]);
	}

	while (!key._Equal("n") && !key._Equal("no") && !key._Equal("y") && !key._Equal("yes")) {
		cout << "Didn't recongise that input" << endl;
		getline(cin, key);
	}

	string message;
	cout << "Message to encrypt: ";
	getline(cin, message);

	Substitution sub;
	string *result;

	if (key._Equal("n") || key._Equal("no")) {
		result = sub.Encrypt(message);
	} else {
		cout << "Key: ";
		getline(cin, key);
		result = sub.Encrypt(key, message);
	}

	key = result[0];
	message = result[1];

	cout << "Key: |" << key << "|" << endl;
	cout << "Cipher Text: |" << message << "|" << endl;

	delete[] result;
}

// Method for calling the decryption using the substitution cipher
void SubstitutionDecode() {
	cout << "Using Substitution Cipher Decode" << endl << "Key: ";
	string key;
	getline(cin, key);

	string message;
	cout << "Message to decrypt: ";
	getline(cin, message);

	Substitution sub;
	string plainText;
	string messagea[2];
	messagea[0] = key;
	messagea[1] = message;

	message = sub.Decrypt(messagea);
	cout << "Message reads: " << message << endl;
}

void TranspositionEncode() {

}

void TranspositionDecode() {

}

bool isInt(string key) {
	char ints[] = { '0','1','2','3','4','5','6','7','8','9' };
	int intchars = 0;
	for (int i = 0; i < key.length(); i++) {
		for (int j = 0; j < size(ints); j++) {
			if (key[i] == ints[j])
				intchars++;
		}
	}

	return (intchars == key.length());
}

void CaesarEncode() {
	cout << "Using Caesar Cipher Encode." << endl <<
		"Would you like to specify a key (y or n)? (n if you don't know)" << endl;
	string key;
	getline(cin, key);
	for (int i = 0; i < key.length(); i++) {
		key[i] = tolower(key[i]);
	}

	while (!key._Equal("n") && !key._Equal("no") && !key._Equal("y") && !key._Equal("yes")) {
		cout << "Didn't recongise that input" << endl;
		getline(cin, key);
	}

	Caesar cae;
	string result;

	if (key._Equal("n") || key._Equal("no")) {
		cae.RandomiseKey();
	} else {
		cout << "Key: ";
		do {
			getline(cin, key);
			if (!isInt(key))
				cout << "Invalid input. Try again: ";
		} while (!isInt(key));
		int Key = stoi(key, nullptr, 10);
		cae.SetKey(Key);
	}

	string message;
	cout << "Message to encrypt: ";
	getline(cin, message);

	result = cae.Encrypt(message);
	message = result;

	cout << "Key: " << cae.GetKey() << endl;
	cout << "Cipher Text = |" << message << "|" << endl;
}

void CaesarDecode() {
	cout << "Using Caesar Cipher Decode." << endl;
	string key;
	Caesar cae;
	string result;

	cout << "Key: ";
	do {
		getline(cin, key);
		if (!isInt(key))
			cout << "Invalid input. Try again: ";
	} while (!isInt(key));
	int Key = stoi(key, nullptr, 10);
	cae.SetKey(Key);

	string message;
	cout << "Message to decrypt: ";
	getline(cin, message);

	result = cae.Decrypt(message);
	message = result;

	cout << "Key: " << cae.GetKey() << endl;
	cout << "Cipher Text = |" << message << "|" << endl;
}

void HillEncode() {

}

void HillDecode() {

}

int main() {
	while (true) {
		cout << "Which cipher do you wish to use? (Substitution - s, Transposition -t, Ceasar - c, Hill - h, Exit - e)" << endl;
		char cipher = getchar();
		cipher = tolower(cipher);

		// CLI Navigation
		if (cipher == 'e')
			break;
		else if (cipher == 's') {
			cout << "Encode (e) or Decode (d)?" << endl;
			getchar();
			char ed = getchar();
			getchar();
			if (ed == 'e')
				SubstitutionEncode();
			else if (ed == 'd')
				SubstitutionDecode();
			else {
				cout << "Wrong charater" << endl;
			}
		} else if (cipher == 't') {
			cout << "Encode (e) or Decode (d)?" << endl;
			getchar();
			char ed = getchar();
			getchar();
			if (ed == 'e')
				TranspositionEncode();
			else if (ed == 'd')
				TranspositionDecode();
			else {
				cout << "Wrong charater" << endl;
			}
		} else if (cipher == 'c') {
			cout << "Encode (e) or Decode (d)?" << endl;
			getchar();
			char ed = getchar();
			getchar();
			if (ed == 'e')
				CaesarEncode();
			else if (ed == 'd')
				CaesarDecode();
			else {
				cout << "Wrong charater" << endl;
			}
		} else if (cipher == 'h') {
			cout << "Encode (e) or Decode (d)?" << endl;
			getchar();
			char ed = getchar();
			getchar();
			if (ed == 'e')
				HillEncode();
			else if (ed == 'd')
				HillDecode();
			else {
				cout << "Wrong charater" << endl;
			}
		}
	}
	cout << "Exited" << endl;
}