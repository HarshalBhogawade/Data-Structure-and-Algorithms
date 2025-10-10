#include <iostream>
#include <vector>
using namespace std;

// function to count number of divisors of n
int exactly3Divisors(int n) {
    int count = 0;
    for (int i = 1; i <= n; i++) {
        
        // number n is divisible by i 
        if (n % i == 0) {
            count++; 
        }
    }
    return count;
}

// function to count numbers with 
// exactly 3 divisors up to n
int countDivisors(int n) {
    int total = 0;
    for (int i = 1; i <= n; i++) {
        if (exactly3Divisors(i) == 3) {
            total++;
        }
    }
    return total;
}

int main() {
    int n = 100;
    int ans = countDivisors(n);
    cout << ans << '\n';
    return 0;
}