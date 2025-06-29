#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <iostream>
#include <fstream>
#include <string>

class FileHandler
{
private:
	std::string inputFile;
	std::string outputFile;

public:
	FileHandler(std::string filename);
	void handleFile(const std::string &toFind, const std::string &replaceWith);
	~FileHandler();
};

#endif