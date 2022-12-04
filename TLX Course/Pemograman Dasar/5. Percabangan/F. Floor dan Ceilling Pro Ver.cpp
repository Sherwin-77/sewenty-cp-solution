#include <iostream>
#include <cstring>
#include <math.h>

// https://stackoverflow.com/questions/8377412/ceil-function-how-can-we-implement-it-ourselves
float myCeil(float f){
    unsigned input;
    memcpy(&input, &f, 4);
    int exponent = ((input >> 23) & 255) - 127;
    if (exponent < 0) return (f > 0);
    // small numbers get rounded to 0 or 1, depending on their sign

    int fractional_bits = 23 - exponent;
    if (fractional_bits <= 0) return f;
    // numbers without fractional bits are mapped to themselves

    unsigned integral_mask = 0xffffffff << fractional_bits;
    unsigned output = input & integral_mask;
    // round the number down by masking out the fractional bits

    memcpy(&f, &output, 4);
    if (f > 0 && output != input) ++f;
    // positive numbers need to be rounded up, not down

    return f;
}


// https://stackoverflow.com/questions/5122993/floor-int-function-implementaton
float myFloor(float x){
    if (x == 0.0)
        return 0;

    union
    {
        float input;   // assumes sizeof(float) == sizeof(int)
        int   output;
    } data;

    data.input = x;

    // get the exponent 23~30 bit    
    int exp = data.output & (255 << 23);
    exp = exp >> 23;

    // get the mantissa 0~22 bit
    int man = data.output & ((1 << 23) - 1);

    int pow = exp - 127;
    int mulFactor = 1;

    int i = abs(pow);
    while (i--)
        mulFactor *= 2;

    unsigned long long denominator = 1 << 23;
    unsigned long long numerator = man + denominator;

    // most significant bit represents the sign of the number
    bool negative = (data.output >> 31) != 0;

    if (pow < 0)
        denominator *= mulFactor;
    else
        numerator *= mulFactor;

    float res = 0.0;
    while (numerator >= denominator) {
        res++;
        numerator -= denominator;
    }

    if (negative) {
        res = -res;
        if (numerator != 0)
        res -= 1;
    }

    return res;
}

int main(){
    using namespace std;
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    float number;
    cin >> number;
    cout << myFloor(number) << ' ' << myCeil(number);
}