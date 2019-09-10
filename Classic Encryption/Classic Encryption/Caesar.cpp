#include "Caesar.h"

string Caesar::Encrypt(string message) {
	string cipher = message;
	for (int i = 0; i < message.length(); i++)
		for (int j = 0; j < size(ALPHABET); j++)
			if (message[i] == ALPHABET[j]) {
				int index = j + key;
				cipher[i] = ALPHABET[index % size(ALPHABET)];
			}
	message = cipher;
	return message;
}

string Caesar::Decrypt(string message) {
	string plain = message;
	for (int i = 0; i < message.length(); i++)
		for (int j = 0; j < size(ALPHABET); j++)
			if (message[i] == ALPHABET[j]) {
				int index = (j - key);
				if (index < 0)
					index = size(ALPHABET) + index;
				plain[i] = ALPHABET[index];
			}
	message = plain;
	return message;
}

void Caesar::SetKey(int Key) {
	key = Key % size(ALPHABET);
}

void Caesar::RandomiseKey() {
	random_device rd;
	do {
		key = rd() % size(ALPHABET);
	} while (key == 0);
}

int Caesar::GetKey() {
	return key;
}
