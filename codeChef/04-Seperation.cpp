#include <bits/stdc++.h>
using namespace std;
/*X is separated in array A if there exists some adjacent pair A[i], A[i+1] such that:
(A[i] < X  and A[i+1] > X) OR (A[i] > X  and A[i+1] < X)*/
int main() {
	// your code goes hereint
	int t;
	cin>>t;
	while(t--){
	    int n,x;
	    cin>>n>>x;
        
	    int less_x = 0,equal_x = 0, greater_x = 0;
	    for(int i=0;i<n;i++){
	        int a;
	        cin>>a;
	        if(a<x){
	            less_x++;//number of elements < X
	        }
	        else if(a>x){
	            greater_x++;//number of elements > X
	        }else{
	            equal_x++;//equal
	        }
	    }
	    
	    if(less_x == 0 || greater_x== 0){
	        cout<<"Yes"<<endl;
	    }else if(equal_x >0){
	        cout<<"Yes"<<endl;
	    }else{
	        cout<<"No"<<endl;
	    }
	    
	}

}