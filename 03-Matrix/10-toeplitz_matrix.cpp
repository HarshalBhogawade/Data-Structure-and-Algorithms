#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j]!=matrix[i-1][j-1]){
                    return false;
                }
            }
        }
        return true;
    }
};

int main(){
    vector<vector<int>>mat = {{1,2,3,4},{5,1,2,3},{9,5,1,2}};
    Solution obj;
    cout<<"Is toeplitz"<<obj.isToeplitzMatrix(mat);
}