#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include "ICharacter.hpp"

class Character : public ICharacter {

public:

	static const size_t NB_INVENTORY_SLOTS = 4;

	Character();
	Character(const std::string& name);
	Character(const Character& other);
	~Character();

	Character& operator=(const Character& other);

	const std::string& getName() const;
	AMateria* getMateria(int idx) const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);


private:

	std::string name;
	AMateria* inventory[NB_INVENTORY_SLOTS];

};

#endif