#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<filesystem>
#include"Directory.h"

using namespace std;

namespace fs = filesystem;

class FileSystem {
protected:
	string name;
	fs::path path;

public:
	FileSystem() {};
	FileSystem(const string& name, const fs::path& mPath) : name(name), path(mPath) {}
	virtual ~FileSystem() = default;
	virtual void Create(const string& path) = 0;
	virtual void Delete(const string& path) = 0;
	virtual void Rename(const string& oldPath, const string& newPath) = 0;
	virtual void copy(const string& sourcePath, const string& destinationPath) = 0;
	virtual void Move(const string& originalPath, const string& path) = 0;
	virtual void searchFileMask(const string& path, const string& mask)   = 0;
	virtual void PrintDisk(const string& path)  = 0;
	
};
