#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool scoreBalance(string s) {
        int total = 0;
        for(char ch : s){
            total += ch - 96; // 'a' -> 1, 'b' -> 2, ...
        }

        int left = 0;
        for(int i = 0; i < s.size() - 1; i++){ // only split before last character
            left += s[i] - 96;
            int right = total - left;
            if(left == right){
                return true;
            }
        }

        return false;
    }
};

int main() {
    Solution sol;

    string s1 = "adcb";
    cout << (sol.scoreBalance(s1) ? "true" : "false") << endl;

    string s2 = "bace";
    cout << (sol.scoreBalance(s2) ? "true" : "false") << endl;

    return 0;
}
