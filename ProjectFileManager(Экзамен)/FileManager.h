#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<filesystem>
#include<vector>

using namespace std;

class FileManager{

	string DiskA;
public:
	FileManager(const string& disk) : DiskA(disk) {}

	bool FileExist() {                    //��������� ������������� �����
		ifstream file(DiskA);
		return file.good();
	}

	vector<string> ReadFile() {          //������ ����������� �����
		vector<string> lines;
		ifstream file(DiskA);
		if (file.is_open()) {
			string line;
			while (getline(file, line)) {
				lines.push_back(line);
			}
			file.close();
		}
		return lines;
	}
};