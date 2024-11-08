#include "byte_array.h"

#include <iostream>

int main()
{
    ByteArray byteArray;
    byteArray.append("dkfjwethj");

    std::cout << byteArray.toUpper();

    return 0;
}