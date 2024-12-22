#include "bigint.hpp"
#include <iostream> 
#include <fstream>


int main() {
    std::ifstream in;            // Define input stream
    in.open("data1-2.txt");      // Open a file
    if(!in) {                    // Make sure file opened correctly
        std::cerr << "File not found: data1-1.txt" << std::endl;
        exit(1);
    }

    const int NUM_BIGINTS = 20;
    bigint bigints[NUM_BIGINTS];
    bigint bigintSum;
    int bigintsInFile = 0;
    
    for (int i = 0; i < NUM_BIGINTS && in >> bigints[i]; ++i){
        ++bigintsInFile;
    }
    
    for (int j = 0; j < bigintsInFile; j += 2) {
            std::cout << "bigint" << j+1 << ": " << bigints[j] << std::endl;
            std::cout << std::endl;
            std::cout << "bigint" << j+2 << ": " << bigints[j+1] << std::endl;
            std::cout << std::endl;

        bigintSum = bigints[j] * bigints[j+1];

        std::cout << "Product of bigints " << j+1 << " and " << j+2 << ": " << bigintSum << std::endl;
        std::cout << std::endl;
    }

    in.close();
    return 0;
}