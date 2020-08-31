#include <iostream>
#include <filesystem>
#include <vector>

using namespace std;
using namespace std::filesystem;

long fileCounter = 0;
long dirCounter = 0;

void Search(const string&);

int main() {
	clock_t start = clock();
	Search("C:\\Program Files");
	clock_t end = clock();
	double seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Run time: %f seconds\n", seconds);
	cout << "files: " << fileCounter << " subdirectories: " << dirCounter;
	return 0;
}

//void Search(const string& parent_directory) {
//	for (const auto& dir_iterator : directory_iterator(parent_directory)) {
//		try {
//			if (is_directory(dir_iterator) && !std::filesystem::is_empty(dir_iterator)) {
//				Search(dir_iterator.path().string());
//			}
//			if (is_regular_file(dir_iterator)) {
//			}
//		}
//		catch (...) {}
//	}
//}

void Search(const string& parent_directory) {
	vector<directory_entry> files;
	vector<directory_entry> subDirs;
	for (const auto& dir_iterator : directory_iterator(parent_directory)) {

		try {
			if (is_directory(dir_iterator) && !std::filesystem::is_empty(dir_iterator)) {
				subDirs.push_back(dir_iterator);
				++dirCounter;
			}
			if (is_regular_file(dir_iterator)) {
				files.push_back(dir_iterator);
				++fileCounter;
			}
		}
		catch (...) {}
	}
	if (!subDirs.empty())
		for (const auto& recur : subDirs)
			Search(recur.path().string());
}