#include "Substitution.h"

bool InKey(int currentIndex, char key[]) {
	bool contains = false;
	for (int i = 0; i < ksize; i++) {
		if (i == currentIndex)
			continue;
		if (alphabet[currentIndex] == key[i]) {
			contains = true;
			break;
		}
	}
	return contains;
}

string* Substitution::Encrypt(string message) {
	random_device rand;
	string* cipherText = new string[SIZE];
	char key[ksize];
	for (int i = 0; i < ksize; i++)
		key[i] = NULL;
	for (int i = 0; i < ksize; i++) {
		int index;
		do {
			index = rand() % ksize;
		} while (InKey(index, key));
		key[i] = alphabet[index];
	}
	string keys = "";
	for (int i = 0; i < ksize; i++)
		keys += key[i];
	cipherText[0] = keys;
	for (int i = 0; i < message.length(); i++) {
		for (int j = 0; j < sizeof(key); j++) {
			if (message[i] == alphabet[j]) {
				message[i] = key[j];
				break;
			}
		}
	}
	cipherText[1] = message;
	return cipherText;
}

string* Substitution::Encrypt(string Key, string message) {
	key = new char[ksize];
	strcat_s(key, sizeof(key), Key.c_str());
	while (sizeof(key) != ksize) {
		cout << "Key size is invalid please input a key of correct size (" << ksize;
		cout << " characters)" << endl;
		getline(cin, Key);
		strcpy_s(key, sizeof(key), Key.c_str());
	}
	string cipherText[SIZE];
	cipherText[0] = key;
	delete[] key;
	for (int i = 0; i < message.length(); i++) {
		for (int j = 0; j < sizeof(key); j++) {
			if (message[i] == alphabet[j]) {
				message[i] = key[j];
				break;
			}
		}
	}
	cipherText[1] = message;
	return cipherText;
}

string Substitution::Decrypt(string message[SIZE]) {
	return string();
}