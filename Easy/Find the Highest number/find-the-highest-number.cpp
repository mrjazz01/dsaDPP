//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
    int findPeakElement(vector<int>& a) 
    {
        // Code here.
        int left=0;
        int right=a.size()-1;
        
        while(left<right){
            int mid=left+(right-left)/2;
            if(a[mid]<a[mid+1])
            left=mid+1;
            else
            right=mid;
        }
        
        return a[left];
    }
};






//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n;
    	cin >> n;
    	vector<int>a(n);
    	for(int i = 0; i < n; i++)
    		cin>>a[i];
    	Solution ob;
    	int ans = ob.findPeakElement(a);
    	cout << ans << "\n";
    }
	return 0;
}


// } Driver Code Ends