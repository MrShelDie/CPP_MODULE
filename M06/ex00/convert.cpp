#include <cmath>
#include <cerrno>
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
	return  !end[0]
			&& value >= std::numeric_limits<int>::min()
			&& value <= std::numeric_limits<int>::max();
}

bool isFloat(const std::string& arg) {
	char* end;
	double value;

	value = std::strtod(arg.c_str(), &end);
	return arg == "nanf" || arg == "-inff" || arg == "+inff"
			|| (end[0] && std::string(end) == "f"
				       && std::abs(value) <= std::numeric_limits<float>::max());
}

bool isDouble(const std::string& arg) {
	char* end;

	std::strtod(arg.c_str(), &end);
	errno = 0;
	return arg == "nan" || arg == "-inf" || arg == "+inf" || (!end[0] && errno != ERANGE);
}

Type getType(const std::string& arg) {
	if (isChar(arg)) {
		return CHAR;
	} else if (isInt(arg)) {
		return INT;	
	} else if (isFloat(arg)) {
		return FLOAT;
	} else if (isDouble(arg)) {
		return DOUBLE;	
	} else {
		return OTHER;
	}
}

void printChar(const std::string& arg) {
	char c = arg[0];
	std::cout << "char: ";
	std::isprint(c) ? std::cout << c << "\n" : std::cout << "Non displayable\n";

	int	i = static_cast<int>(c);
	std::cout << "int: " << i << "\n";

	float f = static_cast<float>(c);
	std::cout << "float: " << f << ".0f" << "\n";

	double d = static_cast<double>(c);
	std::cout << "double: " << d << ".0" << "\n";
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
	std::cout << "float: " << f << ".0f" << "\n";
	
	double d = static_cast<double>(i);
	std::cout << "double: " << d << ".0" << "\n";
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

	double d = std::strtod(arg.c_str(), NULL);

	char c = static_cast<char>(d);
	std::cout << "char: ";
	if (d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max()) {
		std::cout << "impossible\n";
	} else if (!std::isprint(c)) {
		std::cout << "Non displayable\n";
	} else {
		std::cout << c << "\n";
	}

	int i = static_cast<int>(d);
	std::cout << "int: ";
	if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max()) {
		std::cout << "impossible\n";
	} else {
		std::cout << i << "\n";
	}

	float f = static_cast<float>(d);
	std::cout << "float: " << f;
	if (std::floor(f) == f) {
		std::cout << ".0f"; 
	}
	std::cout << "\n";

	std::cout << "double: " << d;
	if (std::floor(d) == d) {
		std::cout << ".0"; 
	}
	std::cout << "\n";
}

void printDouble(const std::string& arg) {
	if (arg == "-inf") {
		std::cout << "char: impossible\n"
				  << "int: impossible\n"
				  << "float: -inff\n"
				  << "double: -inf\n";
		return;
	}
	if (arg == "+inf") {
		std::cout << "char: impossible\n"
				  << "int: impossible\n"
				  << "float: +inff\n"
				  << "double: +inf\n";
		return;
	}
	if (arg == "nan") {
		std::cout << "char: impossible\n"
				  << "int: impossible\n"
				  << "float: nanf\n"
				  << "double: nan\n";
		return;
	}

	double d = std::strtod(arg.c_str(), NULL);
		
	char c = static_cast<char>(d);
	std::cout << "char: ";
	if (d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max()) {
		std::cout << "impossible\n";
	} else if (!std::isprint(c)) {
		std::cout << "Non displayable\n";
	} else {
		std::cout << c << "\n";
	}

	int i = static_cast<int>(d);
	std::cout << "int: ";
	if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max()) {
		std::cout << "impossible\n";
	} else {
		std::cout << i << "\n";
	}

	float f = static_cast<float>(d);
	std::cout << "float: "; 
	if (std::abs(d) > std::numeric_limits<float>::max()) {
		std::cout << "impossible\n";
	} else {
		std::cout << f;
		if (std::floor(f) == f) {
			std::cout << ".0f";
		}
		std::cout << "\n";
	}

	std::cout << "double: " << d;
	if (std::floor(d) == d) {
		std::cout << ".0"; 
	}
	std::cout << "\n";
}

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Usage: " << argv[0] << " <literal>\n";
		return 1;
	}

	std::string arg(argv[1]);
	Type type = getType(arg);
	switch (type) {
		case CHAR:
			printChar(arg);
			break;
		case INT:
			printInt(arg);
			break;
		case FLOAT:
			printFloat(arg);
			break;
		case DOUBLE:
			printDouble(arg);
			break;
		default:
			printDouble("nan");
	}

	return 0;
}
