//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string roundToNearest(string str) {
        // Complete the function
        int n = str.length(), s = ( str[n-1] > '5' );
        str[n-1] = '0';
        for( int i=n-2; s && i>=0; i-- ) {
            s += ( str[i]-'0' );
            str[i] = ( s % 10 + '0' );
            s = s / 10;
        }
        return s ? '1' + str : str;
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.roundToNearest(str) << endl;
    }

    return 0;
}
// } Driver Code Ends