// File: add.cpp
//
// * Dylan Strnad
// * BIGINT
// * CS 23001
//
// Basics for openning a file for milestone 2
//

#include <iostream> 
#include <fstream>
#include <cstdlib>
#include "bigint.hpp"

int main() {
    std::ifstream in;            // Define input stream
    in.open("data1-1.txt");      // Open a file
    if(!in) {                    // Make sure file opened correctly
        std::cerr << "File not found: data1-1.txt" << std::endl;
        exit(1);
    }

    bigint bigint1, bigint2, bigint3, bigint4, bigint5, bigint6, bigintSum;

    in >> bigint1 >> bigint2 >> bigint3 >> bigint4 >> bigint5 >> bigint6;
    
    std::cout << "bigint1: " << bigint1 << std::endl;
    std::cout << std::endl;
    std::cout << "bigint2: " << bigint2 << std::endl;

    bigintSum = bigint1 + bigint2;

    std::cout << std::endl;
    std::cout << "Sum of bigints 1 and 2: " << bigintSum << std::endl;
    std::cout << std::endl;

    //

    std::cout << "bigint3: " << bigint3 << std::endl;
    std::cout << std::endl;
    std::cout << "bigint4: " << bigint4 << std::endl;

    bigintSum = bigint3 + bigint4;

    std::cout << std::endl;
    std::cout << "Sum of bigints 3 and 4: " << bigintSum << std::endl;
    std::cout << std::endl;

    //

    std::cout << "bigint5: " << bigint5 << std::endl;
    std::cout << std::endl;
    std::cout << "bigint6: " << bigint6 << std::endl;

    bigintSum = bigint5 + bigint6;

    std::cout << std::endl;
    std::cout << "Sum of bigints 5 and 6: " << bigintSum << std::endl;

    //

    
    in.close();
    return 0;
}

