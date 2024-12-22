/**
* Dylan Strnad
* BIGINT
* CS 23001
*/

#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>

const int digitCapacity = 200;

class bigint {
private:
    int array[digitCapacity];
public:

    
    bigint(); // defualt constructor to initialize bigint to zero
    
    bigint(int providedValue);

    bigint(const char* providedValue);

    void debugPrint(std::ostream&) const;

    friend std::ostream& operator<<(std::ostream& out, const bigint& inputNumber);

    bool operator==(const bigint& otherNumber) const;

    bool operator==(int otherNumber) const;

    bool operator==(const char* number) const;

    bigint operator+(const bigint&) const;

    int operator[](int i) const;

    friend std::istream &operator>>(std::istream& in, bigint& inputNumber);

    bigint timesDigit(int) const;

    bigint times10(int) const;

    bigint operator*(bigint&);
    };




#endif 