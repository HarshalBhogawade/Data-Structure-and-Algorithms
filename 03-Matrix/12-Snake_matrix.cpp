#include<bits/stdc++.h>
using namespace std;

//tc: O(N^2) sc no 
class spiral{
    public:
    void spiraltraverse(vector<vector<int>>mat){
        int n = mat.size();
        int m = mat[0].size();
        int j = 0;
        int i = 0;
        while(i<n){
            if(i%2==0){
                for(j=0;j<m;j++){
                    cout<<mat[i][j]<<" ";
                }
            }else{
                for(j=m-1;j>=0;j--){
                    cout<<mat[i][j]<<" ";
                }
                
            }
            i++;
        }
    }
};
int main(){
    vector<vector<int>>mat = { {10, 20, 30, 40},
                            {15, 25, 35, 45},
                           {27, 29, 37, 48},
                           {32, 33, 39, 50}};
    spiral obj;
    obj.spiraltraverse(mat);
    return 0;
    
}