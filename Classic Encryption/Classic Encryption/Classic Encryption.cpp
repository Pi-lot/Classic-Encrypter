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
		cout << "Key: ";
		getline(cin, key);
		result = sub.Encrypt(key, message);
	}

	cout << "Key: |" << key << "|" << endl;
	cout << "Cipher Text: |" << message << "|" << endl;

	delete[] result;
}

void SubstitutionDecode() {

}

int main() {
	while (true) {
		cout << "Which cipher do you wish to use? (Substitution - s, Transposition -t, Caesar - c, Hill - h, Exit - e)" << endl;
		char cipher = getchar();
		cipher = tolower(cipher);

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
		}
	}
	cout << "Exited" << endl;
}