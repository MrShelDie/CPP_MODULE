#include <stdint.h>

#include <string>
#include <iostream>

struct Data {
	std::string name;
	int age;
};

uintptr_t serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}

int main() {
	Data data;
   	data.name = "John";
	data.age = 20;	

	uintptr_t uintptr = serialize(&data);
	Data* dataptr = deserialize(uintptr);

	std::cout << &data << "\n";
	std::cout << dataptr << "\n";

	std::cout << "name: " << dataptr->name << "\n";
	std::cout << "age: " << dataptr->age << "\n";

	return 0;
}
