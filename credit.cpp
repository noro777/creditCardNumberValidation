
#include <iostream>

char * check(long int &number);
int quantityOfNumbers(long int number);
bool checkAMEX(int & quantity, long int & number);
bool checkMASTERCARD(int & quantity, long int & number);
bool checkVISA(int & quantity, long int & number);
bool isValid(long int & number);
int everSecDigMul2AndAdd(long int number);
int sumOfRem(long int number);
int add(int sum);


int main() {
    long int input; 
    std::cin >> input;
    std::cout << "Number: " << input<< std::endl;
    
    std::cout  << check(input);
}

char * check(long int &number){
    int quantity = quantityOfNumbers(number);
    
    if(checkAMEX(quantity,number)){
        if(isValid(number))return "AMEX";
        return "INVALID";
    }
    
    if(checkMASTERCARD(quantity,number)){
        if(isValid(number))return "MASTERCARD";
        return "INVALID";
    }
    
    if(checkVISA(quantity,number)){
        if(isValid(number))return "VISA";
        return "INVALID";
    }
    
    return "Unknown Card Type";
}

int quantityOfNumbers(long int number){
    int quantity = 0;
    while(number != 0){
        quantity++;
        number /= 10;
    }
    return quantity;
}

bool checkAMEX(int & quantity, long int & number){
    int twoDigits;
    if(quantity == 15){
        twoDigits = number / 10000000000000;
        if(twoDigits == 34 || twoDigits == 37)return true;
    }
    return false;
}

bool checkMASTERCARD(int & quantity, long int & number){
    int twoDigits;
    if(quantity == 16){
        twoDigits = number / 100000000000000;
        if(twoDigits == 51 
        || twoDigits == 52
        || twoDigits == 53
        || twoDigits == 54
        || twoDigits == 55
        )return true;
    }
    return false;
}

bool checkVISA(int & quantity, long int & number){
    int firstDigit;
    if(quantity == 13){
        firstDigit = number / 1000000000000;
        if(firstDigit == 4)return true;
    }else if(quantity == 16){
        firstDigit = number / 1000000000000000;
        if(firstDigit == 4)return true;
    }
    return false;
}

bool isValid(long int & number){
    int sumOfResults = everSecDigMul2AndAdd(number) + sumOfRem(number);
    if(sumOfResults % 10 == 0) return true;
    return false;
}

int everSecDigMul2AndAdd(long int number){
    long int sum = 0;
    
    while(number != 0){
        number /= 10;
        sum = sum * 10 + (number % 10) * 2; 
        number /= 10;
    }
    
    return add(sum);
}

int sumOfRem(long int number){
    int sum = 0;
    
    while(number != 0){
        sum += number % 10; 
        number /= 100;
    }
    
    return sum;
}

int add(int sum){
    int tmpSum = 0;
    
    while(sum != 0){
        tmpSum += sum % 10; 
        sum /= 10;
    }
    
    return tmpSum;
}



