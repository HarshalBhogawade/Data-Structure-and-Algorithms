#include <bits/stdc++.h>
using namespace std;


char nextGreatestLetter(vector<char> &letters, char target)
{
    int n = letters.size();
    int low = 0;
    int high = n; // Set high to n for a binary search on the range [0, n).

    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (letters[mid] > target)
        {
            // If mid is a possible answer, keep searching for a smaller one on the left.
            high = mid;
        }
        else
        {
            // If mid is not a possible answer, discard it and search on the right.
            low = mid + 1;
        }
    }
    // After the loop, low will point to the smallest element greater than target.
    // The modulo operator handles the wraparound case where no such letter is found.
    return letters[low % n];
}
int main() {
    vector<char>letters={'c','f','j'};
    char ch = 'c';
    cout<<"Answer: "<<nextGreatestLetter(letters,ch);
    return 0;
}