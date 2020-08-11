#include "pch.h"
#include "FieldsAndCalc.h"

bool Comparator::operator()(const WhatToCompare &left, const WhatToCompare &right) const {
	if (left.nameHash + left.contHash == right.nameHash + right.contHash) 
		if (left.name == right.name && left.fileContent == right.fileContent)
			return (left.size + left.time) < (right.size + right.time);
	return left.nameHash + left.contHash < right.nameHash + right.contHash;
}

size_t Hash(const string &str) {
	hash<string> hash;
	return hash(str);
}

void FileContent(const string &path, string &content, size_t &contHash) {
	ifstream file(path);
	content.assign((istreambuf_iterator<char>(file)),
		(istreambuf_iterator<char>()));
	file.close();
	contHash = Hash(content);
}

void TimeCalc(const path &it, size_t &sec, string &userFormat) {
	// Блок расчёта времени, как для сравнения, так и для вывода пользователю
	auto writeTimePoint = last_write_time(it);
	// Создаём time_point (момент времени) для начала эпохи UNIX
	auto epochTimePoint = file_time_type::clock::from_time_t(0);
	// Измеряем число секунд между двумя моментами времени
	auto timestamp = duration_cast<seconds>(writeTimePoint - epochTimePoint);
	time_t endTime = system_clock::to_time_t(writeTimePoint);
	char str[26];
	ctime_s(str, sizeof str, &endTime);
	userFormat = string(str);
	sec = timestamp.count();
}

void CompareAndInsert(const path &it, map <WhatToCompare, list<File>, Comparator> &duplicates, const bool &nameCheck, const bool &sizeCheck, const bool &timeCheck, const bool &contCheck){
	string name = it.filename().string();
	size_t size = file_size(it);
	size_t lastChangeTimeInSec;
	string lastChangeTimeUserFormat;
	string path = it.string();
	TimeCalc(it, lastChangeTimeInSec, lastChangeTimeUserFormat);

	File whatToInsert(name, path, size, lastChangeTimeUserFormat);

	string content = "";
	size_t contHash = 0;
	size_t nameHash = 0;
	if (contCheck && it.extension().string() == ".txt") FileContent(it.string(), content, contHash);
	if (!nameCheck) name = ""; else nameHash = Hash(name);
	if (!sizeCheck) size = 0;
	if (!timeCheck) lastChangeTimeInSec = 0;

	duplicates[WhatToCompare(name, content, size, lastChangeTimeInSec, nameHash, contHash)].emplace_back(whatToInsert);
}

void Search(const string &path, map <WhatToCompare, list<File>, Comparator> &duplicates, const bool &nameCheck, const bool &sizeCheck, const bool &timeCheck, const bool &contCheck, const list<string> &fileTypes) {
	for (const auto &it : directory_iterator(path)) {
		if (is_directory(it) && !std::experimental::filesystem::is_empty(it))
			Search(it.path().string(), duplicates, nameCheck, sizeCheck, timeCheck, contCheck, fileTypes);
		if (is_regular_file(it)) {
			if (!fileTypes.empty()){
				auto extSearch = find(fileTypes.begin(), fileTypes.end(), it.path().extension().string());
				if (extSearch != fileTypes.end()) {
					CompareAndInsert(it, duplicates, nameCheck, sizeCheck, timeCheck, contCheck);
				}
			}
			else {
				CompareAndInsert(it, duplicates, nameCheck, sizeCheck, timeCheck, contCheck);
			}
		}
	}
}

File::File(const string &name, const string &path, const size_t &size, const string &lastChangeTime) : name(name), path(path), size(size),
lastChangeTime(lastChangeTime)
{}

WhatToCompare::WhatToCompare(const string &name, const string &fileContent, const size_t &size,
	const size_t &time, const size_t &nameHash, const size_t &contHash) : name(name),
fileContent(fileContent), size(size), time(time), nameHash(nameHash), contHash(contHash) {}