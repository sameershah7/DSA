#include <iostream>
using namespace std;

int minRotation(int input, int unlock_code){
    int rotation = 0;
    int input_digit, code_digit;
    
    // Iterate till input to unlock code become 0;
    while(input || unlock_code){
        // input and unlock last digit as reminder
        input_digit = input % 10;
        code_digit = unlock_code % 10;

        //find min rotation
        rotation += min(abs(input_digit - code_digit), 10 - abs(input_digit - code_digit));

        //update code and input 
        input /= 10;
        unlock_code /= 10;
    }
    return rotation;
}

int main(){
    int input = 28756;
    int unlock_code = 98234;
    cout<< "Minimum Rotation = "<<minRotation(input, unlock_code);   
    return 0; 
}