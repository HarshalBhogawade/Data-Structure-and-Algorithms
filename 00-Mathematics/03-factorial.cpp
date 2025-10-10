#include <iostream>
using namespace std;

int factorial(int n)
{

    // Calculating factorial of number
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

int main()
{
    int num = 5;
    cout << factorial(num) << endl;
    return 0;
}