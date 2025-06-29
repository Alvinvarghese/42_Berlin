#include "FileHandler.h"

int main(int argc, char **argv)
{
	std::string filename, toFind, replaceWith;
	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " <filename> <toFind> <replaceWith>" << std::endl;
		return 1;
	}
	filename = argv[1];
	toFind = argv[2];
	replaceWith = argv[3];

	FileHandler fileHandler(filename);
	fileHandler.handleFile(toFind, replaceWith);
	return 0;
}