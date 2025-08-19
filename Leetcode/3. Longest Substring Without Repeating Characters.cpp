/*
Use a hashmap to store character frequencies in the current window.
Expand the window by moving the right pointer and add characters to the map.
If a character repeats (map size < window size), shrink the window from the left until all characters are unique again.
At each step, if the window is valid (unique characters), update the maximum length found.
Continue until the right pointer reaches the end of the string. 
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int j=0;
        int i=0;
        int maxsub = 0;
        unordered_map<int,int>mp;
        while(j<s.size()){
            mp[s[j]]++;
            if(mp.size()==j-i+1){
                maxsub = max(maxsub , j-i+1);
            }else if(mp.size()<j-i+1){
                while(mp.size()<j-i+1){
                    mp[s[i]]--;
                    if(mp[s[i]]==0){
                        mp.erase(s[i]);
                    }
                    i++;
                }
            }
            j++;
        }
        return maxsub;
    }
};
