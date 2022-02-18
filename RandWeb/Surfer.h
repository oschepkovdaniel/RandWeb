#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Surfer
{
public:

	static string MakeLink(int min, int max, vector<string> elements, string BaseLink, vector<string> params);
	static void Surf(string url);
	static bool CheckParam(vector<string> params, string target);
};