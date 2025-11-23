#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> mod1, mod2;
        long long sum = 0;

        // Collect the sum and separate based on mod
        for (int x : nums) {
            sum += x;
            if (x % 3 == 1) mod1.push_back(x);
            else if (x % 3 == 2) mod2.push_back(x);
        }

        // Sort to access smallest elements easily
        sort(mod1.begin(), mod1.end());
        sort(mod2.begin(), mod2.end());

        if (sum % 3 == 0) return sum;

        long long removeCost = LLONG_MAX;
        int r = sum % 3;

        if (r == 1) {
            if (!mod1.empty())
                removeCost = min(removeCost, (long long)mod1[0]);
            if (mod2.size() >= 2)
                removeCost = min(removeCost, (long long)mod2[0] + mod2[1]);
        }
        else { // r == 2
            if (!mod2.empty())
                removeCost = min(removeCost, (long long)mod2[0]);
            if (mod1.size() >= 2)
                removeCost = min(removeCost, (long long)mod1[0] + mod1[1]);
        }

        return sum - removeCost;
    }
};

int main() {
    Solution sol;

    int n;
    cin >> n;
    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << sol.maxSumDivThree(nums) << endl;

    return 0;
}
