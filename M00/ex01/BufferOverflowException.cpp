#include "BufferOverflowException.hpp"

BufferOverflowException::BufferOverflowException(const std::string &msg) : msg(msg) {

}

BufferOverflowException::~BufferOverflowException() throw() {

}

const char* BufferOverflowException::what() const throw() {
	return msg.c_str();
}