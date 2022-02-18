#include "LinkUtils.h"
#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <vector>
#include <random>
#include <ctime>
#include <stdio.h>
#include <cstdlib>
using namespace std;

string LinkUtils::RemoveNumbers(string src) {
	string result = src;
	vector<string> letters{ "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z" };

	for (int i = 0; i < 10; i++) {
		string number = to_string(i);
		result = regex_replace(result, regex(number), letters[(int)(rand() % letters.size())]);
	}

	return result;
}

string LinkUtils::ResolveAdress(string link) {
	string newlink = link;
	if (link.find("https://") == string::npos && link.find("http://") == string::npos) {
		newlink = "https://" + newlink;
	}
	return newlink;
}

string LinkUtils::RemoveLetters(string link) {
	string newlink = link;
	vector<char> nums{ '1', '2', '3', '4', '5', '6', '7', '8', '9', '0' };

	for (char& c : newlink) {
		c = nums[(int)(rand() % nums.size())];
	}

	return newlink;
}