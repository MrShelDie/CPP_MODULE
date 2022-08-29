#pragma once
#ifndef __HARL_H__
#define __HARL_H__

#include <string>


class Harl {

public:

	Harl(const std::string& level);

	void complain(void);


private:

	typedef void (Harl::*FuncPtr)(void);

	static const size_t NB_LEVEL = 4;

	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
	void other(void);

	FuncPtr funcPtrs[NB_LEVEL];
	std::string levelStrings[NB_LEVEL];
	int level;
};

#endif