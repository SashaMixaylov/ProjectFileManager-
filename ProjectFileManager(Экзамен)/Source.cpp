#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<filesystem>
#include"FileInfo.h"
#include"Directory.h"
#include"FileManager.h"
#include"FileSystem.h"

using namespace std;

/*
Реализовать простейший файловый менеджер с использованием ООП (классы,
наследование и так далее).
Файловый менеджер должен иметь такие возможности:
■ показывать содержимое дисков;
■ создавать папки/файлы;
■ удалять папки/файлы;
■ переименовывать папки/файлы;
■ копировать/переносить папки/файлы;
■ вычислять размер папки/файла;
■ производить поиск по маске (с поиском по подпапкам) и так далее

*/

int main() {

    setlocale(LC_ALL, "Rus");

    FileDirectory Directory;
    Directory.Create("D:/РПО/test.txt");
    Directory.Rename("D:/РПО/test.txt", "D:/РПО/newTest.txt");
    Directory.copy("D:/РПО/newTest.txt", "D:/РПО/copiTest.txt");
    Directory.PrintDisk("D:/РПО/test.txt");

}