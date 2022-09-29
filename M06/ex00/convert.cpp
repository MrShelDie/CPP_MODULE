#include <limits>
#include <cctype>
#include <cstdlib>
#include <iostream>

enum Type {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	OTHER
};

bool isChar(const std::string& arg) {
	return arg.length() == 1 && !std::isdigit(arg[0]);
}

bool isInt(const std::string& arg) {
	char* end;
	long int value;

	value = std::strtol(arg.c_str(), &end, 10);
	return !end
			&& value >= std::numeric_limits<int>::min()
			&& value <= std::numeric_limits<int>::max();
}

bool isFloat(const std::string& arg) {
	char* end;
	double value;

	value = std::strtod(arg.c_str(), &end);
	return arg == "nanf" || arg == "-inff" || arg == "+inff"
			|| (end && std::string(end) == "f"
				    && value >= std::numeric_limits<float>::min()
				    && value <= std::numeric_limits<float>::max());
}

bool isDouble(const std::string& arg) {
	char* end;

	std::strtod(arg.c_str(), &end);
	return arg == "nan" || arg == "-inf" || arg == "+inf" || !end;
}

Type getType(const std::string& arg) {
	if (isChar(arg)) {
		return Type::CHAR;
	} else if (isInt(arg)) {
		return Type::INT;	
	} else if (isFloat(arg)) {
		return Type::FLOAT;
	} else if (isDouble(arg)) {
		return Type::DOUBLE;	
	} else {
		return Type::OTHER;
	}
}

void printChar(const std::string& arg) {
	char c = static_cast<char>(std::strtol(arg.c_str(), NULL, 10));
	std::cout << "char: ";
	std::isprint(c) ? std::cout << c << "\n" : std::cout << "Non displayable\n";

	int	i = static_cast<int>(c);
	std::cout << "int: " << i << "\n";

	float f = static_cast<float>(c);
	std::cout << "float: " << f << "\n";

	double d = static_cast<double>(c);
	std::cout << "double: " << d << "\n";
}

void printInt(const std::string& arg) {
	int i = static_cast<int>(std::strtol(arg.c_str(), NULL, 10));

	char c = static_cast<char>(i);
	std::cout << "char: ";
	if (i < std::numeric_limits<char>::min() || i > std::numeric_limits<char>::max()) {
		std::cout << "impossible\n";
	} else if (!std::isprint(c)) {
		std::cout << "Non displayable\n";
	} else {
		std::cout << c << "\n";
	}

	std::cout << "int: " << i << "\n";

	float f = static_cast<float>(i);
	std::cout << "float: " << f << "\n"; 
	
	double d = static_cast<double>(i);
	std::cout << "double: " << d << "\n"; 
}

void printFloat(const std::string& arg) {
	if (arg == "-inff") {
		std::cout << "char: impossible\n"
				  << "int: impossible\n"
				  << "float: -inff\n"
				  << "double: -inf\n";
		return;
	}
	if (arg == "+inff") {
		std::cout << "char: impossible\n"
				  << "int: impossible\n"
				  << "float: +inff\n"
				  << "double: +inf\n";
		return;
	}
	if (arg == "nanf") {
		std::cout << "char: impossible\n"
				  << "int: impossible\n"
				  << "float: nanf\n"
				  << "double: nan\n";
		return;
	}

	float f = static_cast<float>(std::strtod(arg.c_str(), NULL));

	char c = static_cast<char>(f);
	std::cout << "char: ";
	if (f < std::numeric_limits<char>::min() || f > std::numeric_limits<char>::max()) {
		std::cout << "impossible\n";
	} else if (!std::isprint(c)) {
		std::cout << "Non displayable\n";
	} else {
		std::cout << c << "\n";
	}

	int i = static_cast<int>(f);
	std::cout << "int: ";
	if (f < std::numeric_limits<int>::min() || f > std::numeric_limits<int>::max()) {
		std::cout << "impossible\n";
	} else {
		std::cout << i << "\n";
	}

	std::cout << "float: " << f << "\n";

	double d = static_cast<double>(f);
	std::cout << "double: " << d << "\n";
}

void printDouble(const std::string& arg) {

}

void printOther() {

}

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Usage: " << argv[0] << " <literal>\n";
		return 1;
	}

	std::string arg(argv[1]);
	Type type = getType(arg);
	switch (type) {
		case Type::CHAR:
			printChar(arg);
			break;
		case Type::INT:
			printInt(arg);
			break;
		case Type::FLOAT:
			printFloat(arg);
			break;
		case Type::DOUBLE:
			printDouble(arg);
			break;
		default:
			printOther();
	}

	return 0;
}
