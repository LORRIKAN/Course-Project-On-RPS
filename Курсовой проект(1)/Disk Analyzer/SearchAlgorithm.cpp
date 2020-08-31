#include "Structs.h"
#include <filesystem>

using namespace std::filesystem;

void Insert(list<Category>& listOfCategories, const string& ext, const File& file) {
	bool inserted = false;
	for (auto& itCategories : listOfCategories)
		if (!itCategories.mapOfFiles.empty() && itCategories.mapOfFiles.count(ext) && itCategories.name != "Other") {
			itCategories.mapOfFiles.find(ext)->second.push_front(file);
			itCategories.size += file.size;
			inserted = true;
		}
	if (!inserted)
		for (auto& Other : listOfCategories)
			if (Other.name == "Other") {
				if (Other.mapOfFiles.count(ext))
					Other.mapOfFiles.find(ext)->second.push_front(file);
				else {
					list<File> newList;
					newList.push_front(file);
					Other.mapOfFiles.emplace(ext, newList);
				}
				Other.size += file.size;
				break;
			}
}

void Search(const string& parent_directory, list<Category>& listOfCategories) {
	for (const auto& dir_iterator : directory_iterator(parent_directory)) {
		try {
			if (is_directory(dir_iterator) && !std::filesystem::is_empty(dir_iterator)) {
				Search(dir_iterator.path().string(), listOfCategories);
			}
			if (is_regular_file(dir_iterator)) {
				const string& ext = dir_iterator.path().extension().string();
				File file(dir_iterator.path().string(), dir_iterator.path().filename().string(), file_size(dir_iterator));
				Insert(listOfCategories, ext, file);
			}
		}
		catch (...) {}
	}
}