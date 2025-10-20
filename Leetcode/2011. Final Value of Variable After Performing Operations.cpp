#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        for (auto op : operations) {
            if (op == "X++" || op == "++X")
                x++;
            else
                x--;
        }
        return x;
    }
};

int main() {
    Solution sol;
    vector<string> ops = {"--X", "X++", "X++"};
    cout << sol.finalValueAfterOperations(ops) << endl;  // Output: 1
    return 0;
}
