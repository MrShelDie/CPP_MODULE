#include <iostream>
#include <fstream>
#include <string>

std::string readFile(const char* fileName) {
	std::ifstream file;
	file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	file.open(fileName);
	std::string result = std::string(
		std::istreambuf_iterator<char>(file),
		std::istreambuf_iterator<char>());
	file.close();
	return result;
}

std::string replaceAllOccurences(
	const std::string& str, const std::string& fromReplace, const std::string& toReplace)
{
	std::string result;
	size_t prevPos = 0;
	size_t pos = 0;
	while ((pos = str.find(fromReplace, pos)) != std::string::npos) {
		result += str.substr(prevPos, pos - prevPos) + toReplace;
		pos += fromReplace.size();
		prevPos = pos;
	}
	result += str.substr(prevPos, str.size());
	return result;
}

void writeFile(const char* fileName, const std::string& content) {
	std::ofstream file;
	file.exceptions(std::ofstream::failbit | std::ofstream::badbit);

	file.open(fileName);
	file << content;
	file.close();
}

int main(int argc, char *argv[]) {
	if (argc != 4) {
		std::cerr << "The number of arguments is not equal to 3\n";
		return 1;
	}

	try {
		std::string inputString = readFile(argv[1]);
		std::string replacedString = replaceAllOccurences(inputString, argv[2], argv[3]);
		const char* outfileName = (std::string(argv[1]) + ".replace").c_str();
		writeFile(outfileName, replacedString);
	} catch (const std::fstream::failure& e) {
		std::cerr << "Exception opening/reading/closing file\n";
	} catch (const std::exception& e) {
		std::cerr << e.what() << "\n";
	}

	return 0;
}