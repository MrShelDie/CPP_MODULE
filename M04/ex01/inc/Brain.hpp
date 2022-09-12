#ifndef _BRAIN_H_
#define _BRAIN_H_

#include <string>

class Brain {

public:

	Brain();
	Brain(const Brain& other);
	~Brain();

	Brain& operator=(const Brain& other);

	static const size_t NB_IDEAS = 100;
	std::string ideas[NB_IDEAS];

};

#endif