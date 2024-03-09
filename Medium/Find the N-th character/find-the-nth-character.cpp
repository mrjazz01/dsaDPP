//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution{
  public:
    char nthCharacter(string s, int r, int n) {
        bool flip = 0;

        while (r-- && n > 0) {
            if (n % 2) flip = !flip; 
            n >>= 1;
        }

        return ((s[n] - '0') != flip) ? '1' : '0';
    }
};





//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, N;
        string S;
        cin >> S >> R >> N;
        Solution ob;
        cout << ob.nthCharacter(S, R, N) << endl;
    }
    return 0;
}
// } Driver Code Ends