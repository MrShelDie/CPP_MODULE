#ifndef _WRONG_ANIMAL_H_
#define _WRONG_ANIMAL_H_

#include <string>

class WrongAnimal {

public:

	WrongAnimal();
	WrongAnimal(const WrongAnimal& other);
	~WrongAnimal();

	WrongAnimal& operator=(const WrongAnimal& other);

	std::string getType() const;

	void makeSound() const;


protected:

	WrongAnimal(const std::string& type);

	std::string type;

};

#endif