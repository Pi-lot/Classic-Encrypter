#include "Caesar.h"

string Caesar::Encrypt(string message) {
	for (int i = 0; i < message.length(); i++) {
		for (int j = 0; j < size(ALPHABET); j++) {
			if (message[i] == ALPHABET[j]) {
				message[i] = ALPHABET[(j + key) % size(ALPHABET)];
			}
		}
	}
	return message;
}

string Caesar::Decrypt(string key, string message) {
	return string();
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
