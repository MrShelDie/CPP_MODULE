#include <iostream>
#include <cctype>

void printDefaultStr() {
	std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
}

void printUpperedStr(int argc, char *argv[]) {
	for (int i = 1; i < argc; ++i) {
		for (int j = 0; argv[i][j]; ++j) {
			char c = std::toupper(argv[i][j]);
			std::cout << c;
		}
	}
	std::cout << std::endl;
}

int main(int argc, char *argv[]) {
	if (argc == 1) {
		printDefaultStr();
	} else {
		printUpperedStr(argc, argv);
	}

	return 0;
}