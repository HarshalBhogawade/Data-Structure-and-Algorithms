#include <bits/stdc++.h>
using namespace std;


//tc : O(2N) Sc : O(2N) can be minimized to N by using vector as a stack 
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;

        for (int a : asteroids) {
            if (a > 0) {
                st.push_back(a);  // positive asteroid, push directly
            } else {  // a < 0, handle collisions
                while (!st.empty() && st.back() > 0) {
                    if (abs(st.back()) < abs(a)) {
                        st.pop_back();  // right-moving asteroid destroyed
                        continue;       // recheck current asteroid
                    } else if (abs(st.back()) == abs(a)) {
                        st.pop_back();  // both destroyed
                        a = 0;          // mark current asteroid as destroyed
                        break;
                    }
                    break;  // current asteroid destroyed
                }

                if (a != 0 && (st.empty() || st.back() < 0)) {
                    st.push_back(a);  // push surviving left-moving asteroid
                }
            }
        }

        return st;  // surviving asteroids in order
    }
};

int main() {
    Solution sol;
    vector<int> ast = {10, 2, -5};
    vector<int> res = sol.asteroidCollision(ast);

    for (int x : res) cout << x << " ";
    return 0;
}
