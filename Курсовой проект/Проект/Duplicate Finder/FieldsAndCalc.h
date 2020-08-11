#include "pch.h"
#pragma once

struct WhatToCompare {
	string name;
	string fileContent;
	size_t size;
	size_t time;
	size_t nameHash;
	size_t contHash;
	WhatToCompare(const string &name, const string &fileContent, const size_t &size, const size_t &time, const size_t &nameHash, const size_t &contHash);
};

struct File {
	const string name;
	const size_t size;
	const string path;
	const string lastChangeTime;
	File(const string &name, const string &path, const size_t &size, const string &lastChangeTime);
};

struct Comparator {
	bool operator()(const WhatToCompare &left, const WhatToCompare &right) const;
};

void Search(const string &path, map <WhatToCompare, list<File>, Comparator> &duplicates, const bool &nameCheck, const bool &sizeCheck, const bool &timeCheck, const bool &contCheck, const list<string> &fileTypes);