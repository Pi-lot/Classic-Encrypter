#include "Matrix.h"

int Matrix::CharToInt(char character) {
	for (int i = 0; i < size(ALPHABET); i++)
		if (ALPHABET[i] == character)
			return i;
}

char Matrix::IntToChar(int num) {
	return ALPHABET[num % size(ALPHABET)];
}

string Matrix::Encrypt(int *key, int keySize, string message) {
	string cipher;
	for (int i = 0; i < keySize; i++)
		cipher += IntToChar(key[i]);
	for (int i = 0; i < message.length(); i += sqrt(keySize)) {
		int *mNum = new int[sqrt(keySize)];
		for (int j = 0; j < sqrt(keySize); j++) {
			mNum[j] = CharToInt(message[i + j]);
		}
		int *nNum = new int[sqrt(keySize)];
		int index = 0;
		for (int k = 0; k < sqrt(keySize); k++) {
			nNum[k] = 0;
			for (int z = 0; z < sqrt(keySize); z++) {
				nNum[k] += ((key[index % keySize] * mNum[z]) % size(ALPHABET));
				index++;
			}
		}
		for (int j = 0; j < sqrt(keySize); j++)
			cipher += IntToChar(nNum[j]);
		delete[] mNum, nNum;
	}
	random_device rd;
	int extra;
	int extraf = message.length() % 2;
	do {
		extra = rd() % size(ALPHABET);
	} while (extra % 2 != extraf);
	if (extraf == 1)
		cipher += IntToChar(rd() % size(ALPHABET));
	cipher += IntToChar(extra);
	delete[] key;
	return cipher;
}

string Matrix::Decrypt(string ciphertext) {
	return string();
}
