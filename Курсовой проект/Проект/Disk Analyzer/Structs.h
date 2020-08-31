#pragma once
#include <list>
#include <string>
#include <map>

using std::string, std::list, std::map;

struct File {
	const string path;
	const string name;
	const unsigned long long size;
	File(const string& path, const string& name, const unsigned long long& size) :
		path(path), name(name), size(size) {}
};

struct Category {
	const string name;
	unsigned long long size = 0;
	map<string, list<File>> mapOfFiles;
	Category(const string& name) :
		name(name) {}
};