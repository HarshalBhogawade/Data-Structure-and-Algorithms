#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
Time Complexity: O(n)
  - Counting frequencies: O(n)
  - Summing elements with max frequency: O(n) in worst case

Space Complexity: O(n)
  - Unordered map stores frequency of up to n unique elements
*/
int maxFrequencyElements(vector<int>& nums) {
    unordered_map<int, int> freq;  
    int maxFreq = 0;

    // Count frequencies and track maximum frequency
    for (int i = 0; i < nums.size(); i++) {
        freq[nums[i]]++;
        if (freq[nums[i]] > maxFreq) maxFreq = freq[nums[i]];
    }

    int total = 0;
    // Sum counts of elements that have maximum frequency
    for (auto it : freq) {
        if (it.second == maxFreq) total += it.second;  // use it.second
    }

    return total;
}

int main() {
    vector<int> nums = {1, 2, 2, 3, 1, 4}; // Sample input

    int result = maxFrequencyElements(nums);
    cout << "Total frequency of elements with maximum frequency: " << result << endl;
    return 0;
}


