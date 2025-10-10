#include <iostream>
using namespace std;

float CtoF(float C)
{   
    // using the conversion formula
    return ((C * 9.0 / 5.0) + 32.0);
}


int main()
{
    float C = 20.0;

    cout <<CtoF(C);
    return 0;
}