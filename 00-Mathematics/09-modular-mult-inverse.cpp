#include <iostream>
using namespace std;

class Solution {
public:
    // Function to find modular inverse of a under modulo m
    int modInverse(int a, int m) {
        for (int i = 1; i < m; i++) { // start from 1, 0 cannot be inverse
            if ((a * i) % m == 1) {
                return i;
            }
        }
        return -1; // no inverse exists
    }
};

int main() {
    Solution sol;
    int a, m;
    
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter modulus m: ";
    cin >> m;

    int inverse = sol.modInverse(a, m);
    if (inverse == -1)
        cout << "Modular inverse does not exist." << endl;
    else
        cout << "Modular inverse of " << a << " modulo " << m << " is: " << inverse << endl;

    return 0;
}
