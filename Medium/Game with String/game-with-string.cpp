//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++



class Solution{
public:
    int minValue(string s, int k){
        // code here
        int freq[26] = {0};
        priority_queue<int> pq;
        for(int i = 0; i < (int)s.size(); i++) {
            freq[s[i] - 'a']++;
        }
        for(int i = 0; i < 26; i++) {
            pq.push(freq[i]);
        }
        while(k > 0) {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            int dif = x - y + 1;
            if(k > dif) {
                pq.push(x-dif);
                k -= dif;
            }
            else {
                pq.push(x-k);
                k = 0;
            }
        }
        int ans = 0;
        while(pq.size() != 0) {
            ans = ans + (pq.top() * pq.top());
            pq.pop();
        }
        return ans;
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends