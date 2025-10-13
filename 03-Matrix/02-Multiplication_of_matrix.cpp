#include<bits/stdc++.h>
using namespace std;

//TC : O(n^3) SC : O(N)
void multmatrix(vector<vector<int>>&A , vector<vector<int>>&B , vector<vector<int>>&C){
    int r1 = A.size();
    int c1 = A[0].size();
    int r2 = B.size();
    int c2 = B[0].size();

    if(r1!=c2){
        cout<<"Invalid multiplication";
        return;
    }

    C.resize(r1,vector<int>(c2,0));

    for(int i=0;i<r1;i++){
        for(int j=0;j<c2;j++){
            for(int k=0;k<c1;k++){
                C[i][j]+=A[i][k]*B[k][j];
            }
        }
    }

    int s = C.size();
    int s1 = C[0].size();
    for(int i=0;i<s;i++){
        for(int j =0;j<s1;j++){
            cout<<C[i][j]<<" ";
        }
        cout<<endl;
    }

    
}
int main(){
    vector<vector<int>> m1 = { {1, 1}, {2, 2} };
    vector<vector<int>> m2 = { {1, 1}, {2, 2} };
    vector<vector<int>> res;

    multmatrix(m1, m2, res);
}