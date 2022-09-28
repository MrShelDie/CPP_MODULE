#include <string>

#include "convert.hpp"

Literal convert(const std::string& arg);

bool operator==(const Literal& lhs, const Literal& rhs)
{
	return lhs.rawBits.d == rhs.rawBits.d && lhs.type == rhs.type;
}

void test(const std)

int main()
{

}
