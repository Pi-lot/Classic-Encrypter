#include "Substitution.h"

// Checks if the character is already in the key
bool InKey(int currentIndex, char key[]) {
	bool contains = false;
	for (int i = 0; i < size(alphabet); i++) {
		if (i == currentIndex)
			continue;
		if (alphabet[currentIndex] == key[i]) {
			contains = true;
			break;
		}
	}
	return contains;
}

// Ecryption that first generates a random key then encrypts and returns the message
string *Substitution::Encrypt(string message) {
	random_device rand;
	string *cipherText = new string[SIZE];
	char key[size(alphabet)];
	for (int i = 0; i < size(alphabet); i++)
		key[i] = NULL;
	for (int i = 0; i < size(alphabet); i++) {
		int index;
		do {
			index = rand() % size(alphabet);
		} while (InKey(index, key));
		key[i] = alphabet[index];
	}
	string keys = "";
	for (int i = 0; i < size(alphabet); i++)
		keys += key[i];
	cipherText[0] = keys;
	for (int i = 0; i < message.length(); i++) {
		for (int j = 0; j < size(key); j++) {
			if (message[i] == alphabet[j]) {
				message[i] = key[j];
				break;
			}
		}
	}
	cipherText[1] = message;
	return cipherText;
}

// Encryption that uses the specified key then returns the message
string *Substitution::Encrypt(string Key, string message) {
	string key = Key;
	while (key.length() != size(alphabet)) {
		cout << "Incorrect key size. Input: " << key.length() << ". Required: " << size(alphabet) << endl;
		getline(cin, key);
	}
	string *cipherText = new string[SIZE];
	cipherText[0] = key;
	for (int i = 0; i < message.length(); i++)
		for (int j = 0; j < key.length(); j++)
			if (message[i] == alphabet[j]) {
				message[i] = key[j];
				break;
			}
	cipherText[1] = message;
	return cipherText;
}

// Decryption that takes in the key and message and returns the decrypted message
string Substitution::Decrypt(string message[SIZE]) {
	cout << "Decrypting" << endl;
	string key = message[0];
	string plainText = message[1];
	for (int i = 0; i < plainText.length(); i++)
		for (int j = 0; j < key.length(); j++) {
			if (plainText[i] == key[j]) {
				plainText[i] = alphabet[j];
				break;
			}
		}
	return plainText;
}