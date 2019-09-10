#include "Transposition.h"

// Checks if the character is already in the key
bool InKey(int num, int period, int current, int key[]) {
	bool contains = false;
	for (int i = 0; i < period; i++) {
		if (i == current)
			continue;
		if (key[i] == num) {
			contains = true;
			break;
		}
	}
	return contains;
}

Transposition::MessageInfo Transposition::Encrypt(MessageInfo message) {
	if (message.period == NULL) {
		random_device rd;
		do {
			message.period = rd() % message.message.length() + 1;
		} while (message.period <= 1 || message.message.length() % message.period != 0);
		message.key = new int[message.period];
		for (int i = 0; i < message.period; i++)
			message.key[i] = NULL;

		for (int i = 0; i < message.period; i++) {
			int num;
			do {
				num = rd() % message.period;
				message.key[i] = num;
			} while (InKey(num, message.period, i, message.key));
		}
	}
	string m = "";
	for (int i = 0; i < message.message.length(); i += message.period)
		for (int j = 0; j < message.period; j++)
			m += message.message[message.key[j] + i];
	message.message = m;
	return message;
}

string Transposition::Decrypt(MessageInfo message) {
	string m = "";
	for (int i = 0; i < message.message.length(); i += message.period)
		for (int j = 0; j < message.period; j++)
			m += message.message[message.key[j]];
	delete[] message.key;
	return message.message;
}
