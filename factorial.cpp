 #include <iostream>

using namespace std; 

int factorial( int factorialNumber){
    if (factorialNumber > 1) {
        return factorialNumber * factorial(factorialNumber - 1 );
    }
    else {
        return 1;
    }
}

int main() {

int number;

cout << "Enter your number" << '\n';
cin >> number;

if (number < 0) {
    cout << "Enter an valid Number" << '\n';
} 
else {
    int result = factorial(number);
    cout << "The result is " << result << '\n';
}


    
};   


