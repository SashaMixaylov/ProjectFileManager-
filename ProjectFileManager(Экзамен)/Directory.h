#pragma once
#include<iostream>
#include<vector>
#include<fstream>
#include<filesystem>
#include<cstring>
#include"FileSystem.h"


using namespace std;

namespace fs = filesystem;


class FileDirectory : public FileSystem {

	vector<FileSystem> contents;
public:
	FileDirectory() {};
	FileDirectory(const string& name, const fs::path&mPath) : FileSystem(name, mPath){};
	string DiskA;

	void Create(const string& path) {   //Создание файла
		fs::path dir = fs::path(path).parent_path();
		if (!fs::exists(dir)) {
			fs::create_directories(dir);
		}
		ofstream file(path);
		if (file.is_open()) {
			file << path;
			file.close();
		}
		else {
			cerr << "Файл не создался." << DiskA << endl;
		}
	}
	

	void Delete(const string& path) {      //Удаление файлов
		fs::remove(fs::path(path));
	}


	void Rename(const string& oldPath, const string& newPath) {     //Переименование файла
		fs::rename(fs::path(oldPath),fs::path(newPath));
	}

	

	void copy(const string& sourcePath, const string& destinationPath) {       //Копирование файлов
		fs::copy(fs::path(sourcePath), fs::path(destinationPath));
	}


	void Move(const string& originalPath, const string& path) {
		fs::path original(originalPath);
		fs::path target(path);

		try {
			fs::rename(original, target / original.filename());
			cout << "файл" << originalPath << "перенесен в" << target << endl;
		}
		catch (fs::filesystem_error& e) {
			cerr << "Ошибка" << originalPath << ":"<<e.what() << endl;
		}
	}

	void searchFileMask(const string& path, const string& mask) {  //Поиск по маске
	
		for (const auto& entry : fs::recursive_directory_iterator(fs::path(path))) {
			if (entry.path().extension() == mask) {
				cout << entry.path() << endl;
			}
		}
	}

	void PrintDisk(const string& path) {
		for (const auto& entry : fs::directory_iterator("/")) {
			cout << entry.path() << endl;
		}
	}
};