#include <iostream>
#include "Substitution.h"
#include "Caesar.h"
#include "Matrix.h"
#include "Transposition.h"

using namespace std;

// Method for calling encryption using the substitution cipher
void SubstitutionEncode() {
	cout << "Using Substitution Cipher Encode" << endl << "Would you like to specify a key (y or n)? (n if you don't know)" << endl;
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

void CeasarEncode() {

}

void CeasarDecode() {

}

void HillEncode() {
	Matrix hill;
	int *key = new int[4];
	key[0] = 5;
	key[1] = 4;
	key[2] = 3;
	key[3] = 6;
	string cipherText;
	cout << "|" << hill.Encrypt(key, 4, "Testing") << "|" << endl;
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
				CeasarEncode();
			else if (ed == 'd')
				CeasarDecode();
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