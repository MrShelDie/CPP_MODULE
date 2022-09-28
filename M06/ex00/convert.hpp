#ifndef CONVERT_HPP
#define CONVERT_HPP

struct Literal
{
	union
	{
		char	c;
		int		i;
		float	f;
		double	d;	
	} rawBits;

	enum Type
	{
		ERROR,
		CHAR,
		INT,
		FLOAT,
		DOUBLE
	} type;
};

#endif
