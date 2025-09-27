#include <bits/stdc++.h>
using namespace std;

//tc : O3N sc O3N
int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    vector<int> pse(n), nse(n);
    stack<int> st;

    // find previous smaller element (PSE)
    for (int i = 0; i < n; i++) {
        while (!st.empty() && heights[st.top()] > heights[i]) {
            st.pop();
        }
        pse[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    while (!st.empty()) st.pop();

    // find next smaller element (NSE)
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }
        nse[i] = st.empty() ? n : st.top();
        st.push(i);
    }

    // calculate max area
    int max_area = INT_MIN;
    for (int i = 0; i < n; i++) {
        int width = nse[i] - pse[i] - 1; // formula
        max_area = max(max_area, heights[i] * width); //main formula
    }

    return max_area;
}

int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << "Largest Rectangle Area = " << largestRectangleArea(heights) << endl;
    return 0;
}
