#ifndef _ANIMAL_H_
#define _ANIMAL_H_

#include <string>

class AAnimal {

public:

	AAnimal();
	AAnimal(const AAnimal& other);
	virtual ~AAnimal();

	AAnimal& operator=(const AAnimal& other);

	std::string getType() const;

	virtual void makeSound() const = 0;


protected:

	AAnimal(const std::string& type);

	std::string type;

};

#endif