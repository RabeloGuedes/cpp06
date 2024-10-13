#include <Serializer.hpp>
#include <Data.hpp>
#include <iostream>

int main(void) {
    Data data;
    uintptr_t serialized = Serializer::serialize(&data);
    Data* deserialized = Serializer::deserialize(serialized);

    if (&data == deserialized && data.getValue() == 42)
        std::cout << "Serialization and deserialization successful." << std::endl;
	else
        std::cout << "Serialization and deserialization failed." << std::endl;
    return (0);
}