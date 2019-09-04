#pragma once
#include <string>
#include <random>
#include <iostream>

using namespace std;

const int SIZE = 2;
const char alphabet[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p'
		,'q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P'
		,'Q','R','S','T','U','V','W','X','Y','Z',' ' };
const int ksize = sizeof(alphabet);

class Substitution {
public:
	string *Encrypt(string message);
	string *Encrypt(string Key, string message);
	string Decrypt(string message[SIZE]);
};