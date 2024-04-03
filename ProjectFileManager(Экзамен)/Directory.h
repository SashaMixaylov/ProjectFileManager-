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

	void Create(const string& path) {   //�������� �����
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
			cerr << "���� �� ��������." << DiskA << endl;
		}
	}
	

	void Delete(const string& path) {      //�������� ������
		fs::remove(fs::path(path));
	}


	void Rename(const string& oldPath, const string& newPath) {     //�������������� �����
		fs::rename(fs::path(oldPath),fs::path(newPath));
	}

	

	void copy(const string& sourcePath, const string& destinationPath) {       //����������� ������
		fs::copy(fs::path(sourcePath), fs::path(destinationPath));
	}


	void Move(const string& originalPath, const string& path) {
		fs::path original(originalPath);
		fs::path target(path);

		try {
			fs::rename(original, target / original.filename());
			cout << "����" << originalPath << "��������� �" << target << endl;
		}
		catch (fs::filesystem_error& e) {
			cerr << "������" << originalPath << ":"<<e.what() << endl;
		}
	}

	void searchFileMask(const string& path, const string& mask) {  //����� �� �����
	
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