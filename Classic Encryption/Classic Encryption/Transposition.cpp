#include "Transposition.h"

// Checks if the character is already in the key
bool InKey(int num, int period, int key[]) {
	bool contains = false;
	for (int i = 0; i < period; i++)
		if (key[i] == num) {
			contains = true;
			break;
		}
	return contains;
}

Transposition::MessageInfo Transposition::Encode(MessageInfo message) {
	if (message.key == NULL) {
		random_device rd;
		if (message.period == NULL) {
			do {
				message.period = rd() % message.message.length();
			} while (message.message.length() % message.period != 0);
		}

		message.key = new int[message.period];
		for (int i = 0; i < message.period; i++)
			message.key[i] = NULL;

		for (int i = 0; i < message.period; i++) {
			int num;
			do {
				num = rd() % message.period;
			} while (InKey(num, message.period, message.key));
		}
	}
	for (int i = 0; i < message.message.length(); i += message.period) {
		char *temp = new char[message.period];
		for (int j = 0; j < message.period; j++) {
			temp[j] = message.message[i + j];
		}
		for (int j = 0; j < message.period; j++) {
			message.message[i] = temp[message.key[j]];
		}
		delete[] temp;
	}
	delete[] message.key;
	return message;
}

string Transposition::Decode(MessageInfo message) {
	return string();
}
