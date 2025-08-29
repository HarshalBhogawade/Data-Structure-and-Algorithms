#include <bits/stdc++.h>
using namespace std;

int totalFruit(vector<int>& fruits) {
    // TC: O(n), SC: O(1) since at most 2 types of fruits in map

    unordered_map<int,int> mp; 
    int i = 0, j = 0, result = 0;

    while (j < fruits.size()) {
        mp[fruits[j]]++;  // add current fruit to basket

        // valid window (at most 2 fruit types)
        if (mp.size() <= 2) {
            result = max(result, j - i + 1);
        }

        // shrink window if more than 2 fruit types
        while (mp.size() > 2) {
            mp[fruits[i]]--;
            if (mp[fruits[i]] == 0) mp.erase(fruits[i]);
            i++;
        }
        j++;
    }
    return result;
}

int main() {
    vector<int> fruits = {1, 2, 1, 2, 3};
    cout << totalFruit(fruits);  // Output: 4
    return 0;
}
