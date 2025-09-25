#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int si;
        cin >> si;
        int s = 0;
        int arr[si];
        while (s < si)
        {
            int elem;
            cin >> elem;
            arr[s] = elem;
            s++;
        }
        int neg = 0;
        int zero = 0;
        for (int i = 0; i < si; i++)
        {
            if (arr[i] == 0)
            {
                zero++;
            }
            else if (arr[i] == -1)
            {
                neg++;
            }
        }
        int cost = zero;     // cost for zero to 1 is only 1 so dirctly add values
        if(neg % 2 != 0)        // if no even means directly do -1->0->1 which equals cost of 2
            cost += 2;  
        cout << cost << endl;
    }
}