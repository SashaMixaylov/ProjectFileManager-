#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include"FileManager.h"

using namespace std;

class FileInfo : public FileManager {

public:
	FileInfo(const string& disk) : FileManager(disk), DiskA(disk) {};
	string DiskA;

	streamsize getFileSize(const string& disk) {           //Получение размера файла
		ifstream file(disk);
		if (file.is_open()) {
			return file.tellg();
		}
		else {
			cerr << "Файл не открылся." << DiskA << endl;
			return -1;
		}
	}

	string GetFileName() {   //Получение имени файла
		return DiskA;
	}
};