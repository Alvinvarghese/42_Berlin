#include "FileHandler.h"

FileHandler::FileHandler(std::string filename) : inputFile(filename), outputFile(filename + ".replace")
{
}

FileHandler::~FileHandler() {}

void FileHandler::handleFile(const std::string &toFind, const std::string &replaceWith)
{
	std::ifstream input(inputFile);
	if (!input.is_open())
	{
		std::cerr << "Error opening file: " << inputFile << std::endl;
		return;
	}

	std::ofstream output(outputFile);
	if (!output.is_open())
	{
		std::cerr << "Error creating output file: " << outputFile << std::endl;
		return;
	}

	if (toFind.empty())
	{
		std::cerr << "Error: 'toFind' string cannot be empty." << std::endl;
		return;
	}

	std::string line;
	bool firstLine = true;
	while (std::getline(input, line))
	{
		size_t pos = 0;
		while ((pos = line.find(toFind, pos)) != std::string::npos)
		{
			// line.replace(pos, toFind.length(), replaceWith);
			line.erase(pos, toFind.length());
			line.insert(pos, replaceWith);
			pos += replaceWith.length();
		}
		// output << line << std::endl;
		if (!firstLine)
			output << std::endl; // Add newline before writing the next line
		output << line;
		firstLine = false;
	}

	input.close();
	output.close();
}