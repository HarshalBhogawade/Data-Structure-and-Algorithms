#include <bits/stdc++.h>
using namespace std;

/*
K-th Symbol in Grammar
Row generation:
Row 1: 0
Row 2: 01
Row 3: 0110
Row 4: 01101001
...

Recursive logic:
Each row doubles in size:
Row(n) length = 2^(n-1)

First half is same as previous row
Second half is inverse (~) of previous row

Visualization:
n=3, k=4

        kthGrammar(3,4)
                |
        k > mid -> inverse of kthGrammar(2,2)
                            |
                    k == mid -> kthGrammar(1,1)
                                returns 0
Inverse of 0 = 1

Therefore answer = 1
---------------------------------------------------------------
Recursion Tree Example for n=4, k=5:

                     f(4,5)
                     /    \
               mid=4      k>mid -> inverse f(3,1)
                               |
                             f(3,1)
                               |
                             mid=2 -> k<=mid
                               |
                             f(2,1)
                               |
                             base -> 0
So f(4,5) = inverse of 0 = 1
---------------------------------------------------------------
*/

class Solution {
public:
    int kthGrammar(int n, int k) {
        if (n == 1 && k == 1) return 0; // Base: first symbol is always 0
        
        int mid = pow(2, n - 1) / 2;   // Mid point of row
        
        if (k <= mid) {
            // Same as symbol in previous row
            return kthGrammar(n - 1, k);
        }
        // Opposite of symbol in previous row
        return !kthGrammar(n - 1, k - mid);
    }
};

int main() {
    Solution s;
    cout << s.kthGrammar(4,5); // Test example
    return 0;
}
