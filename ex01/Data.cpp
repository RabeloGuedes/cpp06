#include <Data.hpp>

Data::Data() : value(42) {}

Data::Data(const Data &obj) {
	*this = obj;
}

Data::Data(int value) : value(value) {}

Data &Data::operator=(const Data &obj) {
	value = obj.value;
	return *this;
}

Data::~Data() {}

int Data::getValue() {
	return value;
}