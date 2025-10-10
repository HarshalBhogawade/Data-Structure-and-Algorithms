#include <iostream>
using namespace std;

class Solution {
public:
    long long sumUnderModulo(long long a, long long b) {
        long long M = 1000000007;
        return (a % M + b % M) % M;
    }
};

int main() {
    Solution sol;

    long long a, b;
    cout << "Enter first number: ";
    cin >> a;
    cout << "Enter second number: ";
    cin >> b;

    long long result = sol.sumUnderModulo(a, b);
    cout << "The sum under modulo 1000000007 is: " << result << endl;

    return 0;
}
