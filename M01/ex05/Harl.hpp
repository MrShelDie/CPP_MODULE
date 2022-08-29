#pragma once
#ifndef __HARL_H__
#define __HARL_H__

#include <string>


class Harl {

public:

	Harl(void);

	void complain(std::string level);


private:

	typedef void (Harl::*FuncPtr)(void);

	static const size_t NB_LEVEL = 4;

	void debug(void);
	void info(void);
	void warning(void);
	void error(void);

	FuncPtr funcPtrs[NB_LEVEL];
	std::string levelStrings[NB_LEVEL];

};

#endif