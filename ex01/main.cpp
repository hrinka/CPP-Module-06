#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
    Data originalData;
    originalData.id = 42;
    originalData.name = "Sample Data";
    originalData.value = 3.14f;

    // シリアライズとデシリアライズのテスト
    uintptr_t serializedData = Serializer::serialize(&originalData);
    Data* deserializedData = Serializer::deserialize(serializedData);

    std::cout << "Original Data address: " << &originalData << std::endl;
    std::cout << "Deserialized Data address: " << deserializedData << std::endl;

    if (deserializedData == &originalData) {
        std::cout << "Success: The deserialized pointer is equal to the original pointer." << std::endl;
    } else {
        std::cout << "Error: The deserialized pointer is not equal to the original pointer." << std::endl;
    }

    std::cout << "Data ID: " << deserializedData->id << std::endl;
    std::cout << "Data Name: " << deserializedData->name << std::endl;
    std::cout << "Data Value: " << deserializedData->value << std::endl;

    return 0;
}
