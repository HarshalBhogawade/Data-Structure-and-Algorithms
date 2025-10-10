#include <iostream>
using namespace std;

class Solution {
public:
    int multiplicationUnderModulo(long long a, long long b) {
        long long m = 1000000007;
        return int(((a % m) * (b % m)) % m);
    }
};

int main() {
    Solution sol;

    long long a, b;
    cout << "Enter first number: ";
    cin >> a;
    cout << "Enter second number: ";
    cin >> b;

    int result = sol.multiplicationUnderModulo(a, b);
    cout << "The multiplication under modulo 1000000007 is: " << result << endl;

    return 0;
}
