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
	if (message.key == NULL) {
		cout << "Key Gen...";
		random_device rd;
		if (message.period == NULL) {
			do {
				message.period = rd() % message.message.length();
			} while (message.period <= 1 || message.message.length() % message.period != 0);
		}
		cout << "Period: " << message.period << "...";
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
		cout << "Done: ";
		for (int i = 0; i < message.period; i++) {
			cout << message.key[i];
		}
		cout << endl;
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
	return message;
}

string Transposition::Decrypt(MessageInfo message) {
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
	return message.message;
}
