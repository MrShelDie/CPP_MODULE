#ifndef _AMATERIA_H_
#define _AMATERIA_H_

#include <string>

class AMateria {

public:

	AMateria(const std::string& type);

	const std::string& getType() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);


protected:

	std::string type;

};

#endif