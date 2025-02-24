#pragma once
#include <list>
#include <vector>
#include <iostream>
#include <string>
#include <cassert>

using namespace std;

inline string* split(string str, int index)
{
	assert(index >= 0 && index < str.length());
	string* res = new string[2];
	int i = 0;
	while (i < str.length())
	{
		if (i < index)
		{
			res[0] += str[i];
		}
		if (i > index)
		{
			res[1] += str[i];
		}
		i++;
	}
	return res;
}

inline string uploadBufferFromFile(const char* path)
{
#pragma warning(disable : 4996)
	FILE* f = fopen(path, "r");
	fseek(f, 0, SEEK_END);
	int len = ftell(f);
	rewind(f);
	char* cbuffer = new char[len];
	size_t p = fread(cbuffer, 1, len, f);
	fclose(f);
	string buffer = split(string(cbuffer), p)[0];
	delete[] cbuffer;
	return buffer;
}

inline size_t split(const std::string& txt, std::vector<std::string>& strs, char ch)
{
	size_t pos = txt.find(ch);
	size_t initialPos = 0;
	strs.clear();

	// Decompose statement
	while (pos != std::string::npos) {
		strs.push_back(txt.substr(initialPos, pos - initialPos));
		initialPos = pos + 1;

		pos = txt.find(ch, initialPos);
	}

	// Add the last one
	strs.push_back(txt.substr(initialPos, std::min(pos, txt.size()) - initialPos + 1));

	return strs.size();
}
