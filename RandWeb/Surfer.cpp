#include "Surfer.h"
#include <random>
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include <Windows.h>
#include <shellapi.h>
#include "LinkUtils.h"

string Surfer::MakeLink(int min, int max, vector<string> elements, string BaseLink, vector<string> params) {
	srand((unsigned)time(0));

	int length = min + (rand() % max);
	string link = "";

	for (int i = 0; i < length; i++) {
		string next = elements[(int)(rand() % elements.size())];
		if ((int)(rand() % 2) == 1)
			transform(next.begin(), next.end(), next.begin(), ::toupper);

		link += next;
	}

	// handle params
	if (CheckParam(params, "lower-case"))
		transform(link.begin(), link.end(), link.begin(), ::tolower);
	if (CheckParam(params, "upper-case"))
		transform(link.begin(), link.end(), link.begin(), ::toupper);
	if (CheckParam(params, "no-nums"))
		link = LinkUtils::RemoveNumbers(link);
	if (CheckParam(params, "no-letters"))
		link = LinkUtils::RemoveLetters(link);

	link = BaseLink + link;
	link = LinkUtils::ResolveAdress(link);

	return link;
}

void Surfer::Surf(string url) {
	wstring wUrl = wstring(url.begin(), url.end());
	ShellExecute(0, 0, wUrl.c_str(), 0, 0, SW_SHOW);
}

bool Surfer::CheckParam(vector<string> params, string target) {
	bool hasParam = false;

	for (string& param : params) {
		if (param._Equal(target)) {
			hasParam = true;
			break;
		}
	}

	return hasParam;
}