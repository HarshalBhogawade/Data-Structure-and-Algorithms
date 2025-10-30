#include <iostream>
#include <iomanip>
using namespace std;

// Function to convert Fahrenheit to Celsius
float FtoC(float F)
{   
    return (F - 32.0) * 5.0 / 9.0;
}

int main()
{
    float F = 68.0;

    cout << fixed << setprecision(2);
    cout << FtoC(F);

    return 0;
}