/**
* Dylan Strnad
* BIGINT
* CS 23001
*/

#include "bigint.hpp"

bigint::bigint() {
    for (int i = 0; i < digitCapacity; ++i) {
        array[i] = 0;
    }
}

bigint::bigint(int number) {
    for (int i = digitCapacity - 1; i >= 0; --i) {
        array[i] = number % 10;
        number /= 10;
    }
}

bigint::bigint(const char* number) {
    int length = 0;
    for(int i =0; number[i] != '\0'; ++i)  // gets length of the string
        ++length;

    // remove old array, initialize array to 0
    for (int i = 0; i < digitCapacity; ++i) {
        array[i] = 0;
    }

    // fills array starting from index of first digit to 199. number is reversed in array
    int firstDigitIndex = digitCapacity - length;
    for (int i = 0; i < length; ++i) {
            array[firstDigitIndex + i] = int(number[i]) - int('0');
    }
}

void bigint::debugPrint(std::ostream& out) const {
    int digitsInOutput = 0;
    for (int i = 0; i < digitCapacity; ++i) { // prints number in reverse order
        out << array[i] << " | ";
        ++digitsInOutput;

         if (digitsInOutput == 40){
            out << std::endl;
            digitsInOutput = 0;
        }
    }
    out << std::endl;
}

std::ostream& operator<<(std::ostream& out, const bigint& inputNumber) {
    bool digitNotZero = false;
    int digitsInOutput = 0;
    int size = 0;
    while(inputNumber.array[size] == 0){
        ++size;
    }

    for (int i = 0; i < digitCapacity; ++i) {
        if (inputNumber.array[i] != 0) {  // determines when array has found beginning of number
            digitNotZero = true;
        }
        if (digitNotZero) {  // once the leader zeros have been removed, prints out number in the array in order
            out << inputNumber.array[i];
            ++digitsInOutput;
        }
        if (digitsInOutput == 80){
            out << std::endl;
            digitsInOutput = 0;
        }
    }

    if (!digitNotZero) {  // if no non zero is found
        out << "0";
    }

    return out;
}

bool bigint::operator==(int otherNumber) const {
    int i = digitCapacity - 1;
    while (i >= 0 && otherNumber != 0) {
        if (array[i] != otherNumber % 10) { // if numbers are not equal, return false
            return false;
        }
        otherNumber /= 10; // remove last digit from number
        --i;
    }
    return true;
}


bool bigint::operator==(const bigint& otherNumber) const {
    int i = digitCapacity - 1;

    while (i >= 0 && array[i] == otherNumber.array[i]) {
        --i;
    }
    if(i < 0)// if while loops fully completes
        return true;
    else     // otherwise
        return false;
    
}


bool bigint::operator==(const char* number) const{
    int length = 0;
    for(int i =0; number[i] != '\0'; ++i)  // gets length of the string
        ++length;
        
    int firstDigitIndex = digitCapacity - length;  //get index of beginning of array number

    for (int i = 0; i < length; ++i) {
        if (array[firstDigitIndex + i] != (number[i] - '0')) {  // check if digits are equal
            return false;
        }
    }

    return true;
}


bigint bigint::operator+(const bigint& right) const{  // const prevents modification of original objects
    bigint result;
    int carry = 0;
    int sum = 0;

    for (int i = 0; i < digitCapacity; ++i){
        result.array[i] = 0;
    }

    for (int i = digitCapacity - 1; i >= 0; --i){   // (int i = digitCapacity -1; i >= 0; --i){

        sum = array[i] + right.array[i] + carry; // add values
        
        result.array[i] = sum % 10; //store digit in array

        carry = sum / 10; // if sum consists of mult digits, must carry over to sum on next loop
    }
    
    return result;
    
}

int bigint::operator[](int i) const {

    int leastSignificant = 199;

    int numberAtIndex = array[leastSignificant - i];
    
    return numberAtIndex;
}

std::istream& operator>>(std::istream& in, bigint& otherNumber) {
    char ch;
    char buffer[digitCapacity] = {0};

    for (int i = 0; i < digitCapacity; ++i) {  // Clear the bigint array before reading new input
        otherNumber.array[i] = 0;
    }

    int index = 0;
    while (in.get(ch)) {
        if (ch == ';') {
            break;
        }
        else if (ch >= '0' && ch <= '9') {
            buffer[index] = ch;
            ++index; 
        }
    }

    otherNumber = bigint(buffer);

    return in;
}

bigint bigint::timesDigit(int number) const{

bigint result;
int carry=0;

for(int i = digitCapacity -1; i >= 0; --i){   // start at end of array. least significant digit
    int product = (array[i] * number) + carry;  // add carry to product
    result.array[i] = product%10;  // store
    carry = product/10;  // carry will apply when product is greater than 10
}

return result;
}

bigint bigint::times10(int input) const{
    bigint shifted;

    for(int index = digitCapacity - 1 - input; index >= 0; --index){
        shifted.array[index] = array[index + input];
    }

    return shifted;
}


bigint bigint::operator*(bigint& rhs){
    bigint temp = 0;
    bigint product = 0;
    int startIndex = digitCapacity - 1;
    for(int i = startIndex; i >= 0; --i){
        temp = timesDigit(rhs.array[i]);
        product = product + temp.times10(startIndex-i);
    }

    return product;
}
