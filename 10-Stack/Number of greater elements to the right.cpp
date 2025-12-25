#include <iostream>
using namespace std;
#include <vector>


// Time Complexity: O(q * n) where q = indices.size(), n = arr.size()
// Space Complexity: O(q) for result array
vector<int> count_NGE(vector<int> &arr, vector<int> &indices)
{
    int i = arr.size() - 1;
    vector<int> ans(indices.size(), 0);
    int q = indices.size();

    for (int k = 0; k < q; k++)
    {
        int idx = indices[k];
        int count = 0;

        // Count elements greater than arr[idx] to the right
        for (int j = idx + 1; j < arr.size(); j++)
        {
            if (arr[j] > arr[idx])
            {
                count++;
            }
        }
        ans[k] = count;
    }
    return ans;
}

int main()
{
    // Input array and indices
    vector<int> arr = {3, 4, 2, 7, 5, 8, 10, 6};
    vector<int> indices = {0, 5};
    
    vector<int> result = count_NGE(arr, indices);

    // Output results
    cout << "Results: ";
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    
    return 0;
}
