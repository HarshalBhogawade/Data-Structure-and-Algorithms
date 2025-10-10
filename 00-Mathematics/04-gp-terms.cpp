// CPP program to print GP.
#include <bits/stdc++.h>
using namespace std;

void printGP(int a, int r, int n)
{
    int curr_term;
    for (int i = 0; i < n; i++) {
        curr_term = a * pow(r, i);
        cout << curr_term << " ";
    }
}

// Driver code
int main()
{
    int a = 2; // starting number
    int r = 3; // Common ratio
    int n = 5; // N th term to be find
    printGP(a, r, n);
    return 0;
}
