#include <bits/stdc++.h>
using namespace std;

vector<int> findXSum(vector<int>& nums, int k, int x)
{
    int n = nums.size();
    vector<int> answer;
    unordered_map<int, int> freq; // ✅ kept outside (used for sliding)

    int i = 0, j = 0;

    while (j < n)
    {
        // Add current element
        freq[nums[j]]++;

        // If window size < k, expand
        if (j - i + 1 < k)
        {
            j++;
            continue;
        }

        // When window size == k
        vector<pair<int, int>> freqVec(freq.begin(), freq.end());

        // Sort by frequency ↓ and value ↓
        sort(freqVec.begin(), freqVec.end(), [](auto &a, auto &b) {
            if (a.second == b.second)
                return a.first > b.first;
            return a.second > b.second;
        });

        // Pick top x elements
        unordered_set<int> topX;
        for (int idx = 0; idx < min(x, (int)freqVec.size()); idx++)
            topX.insert(freqVec[idx].first);

        // Compute x-sum
        int sum = 0;
        for (auto &[num, cnt] : freq)
            if (topX.count(num))
                sum += num * cnt;

        answer.push_back(sum);

        // Slide the window → remove nums[i]
        freq[nums[i]]--;
        if (freq[nums[i]] == 0)
            freq.erase(nums[i]);

        // Move window forward
        i++;
        j++;
    }

    return answer;
}

int main()
{
    vector<int> nums = {2, 3, 2, 4, 3};
    int k = 3, x = 2;

    vector<int> res = findXSum(nums, k, x);
    for (int val : res)
        cout << val << " ";
    cout << endl;

    return 0;
}
