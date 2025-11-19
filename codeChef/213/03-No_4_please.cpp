#include <bits/stdc++.h>
using namespace std;

//if subsets equals 4 then remove elements with minimum deletion of elemtns 
//mostly 4 are formed by 3+1  either del all one or all 3 and 2+2
//so calc num and delete based on it
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int c1 = 0, c2 = 0,c3 =0;
	    for(int i = 0;i<n;i++){
	        int x;
	        cin>>x;
	        if(x==1) c1++;
	        else if(x==2) c2++;
	        else c3++;
	    }
    
	    int rem12 = min(c1,c3);//for cheap operation do this 
	    int rem2 = max(0,c2-1);// 0 or 1 is ok but not 2 2's so do -1 
        //[2,2,2] so 3 2's deloperationcnt = 3-1  = 2 means 2 two deleted
	    cout<<rem12+rem2<<endl;
	}

}
