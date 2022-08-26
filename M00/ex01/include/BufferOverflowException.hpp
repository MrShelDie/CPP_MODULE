#ifndef BUFFER_OVERFLOW_EXCEPTION_HPP
# define BUFFER_OVERFLOW_EXCEPTION_HPP

# include <exception>
# include <string>

class BufferOverflowException : public std::exception {
public:
	BufferOverflowException(const std::string &msg);
	virtual ~BufferOverflowException() throw();

	virtual const char* what() const throw();

private:
	std::string msg;
};

#endif