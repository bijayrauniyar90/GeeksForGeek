//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    string minSum(vector<int> &arr) {
        // code here
        sort(arr.begin(),arr.end());
        string s1,s2;
        for(int i=0;i<arr.size();i++) {
            if(arr[i]!=0) {
                if(i%2 == 0) {
                s1.push_back(arr[i] + '0');
                }
                else {
                    s2.push_back(arr[i]+'0');
                }
            }
        }
        reverse(s1.begin(),s1.end());
        reverse(s2.begin(),s2.end());
        string ans;
        int carry=0,p1=0,p2=0;
        while(p1<s1.size() && p2<s2.size()) {
            int d=s1[p1]-'0' + s2[p2]-'0' + carry;
            if(d>9) {
                carry=1;
                d=d%10;
            }
            else {
                carry=0;
            }
            ans.push_back(d+'0');
            p1++;
            p2++;
        }
        while(p1<s1.size()) {
            int d=s1[p1]-'0' + carry;
            if(d>9) {
                carry=1;
                d=d%10;
            }
            else {
                carry=0;
            }
            ans.push_back(d+'0');
            p1++;
        }
        while(p2<s2.size()) {
            int d=s2[p2]-'0' + carry;
            if(d>9) {
                carry=1;
                d=d%10;
            }
            else {
                carry=0;
            }
            ans.push_back(d+'0');
            p2++;
        }
        if(carry == 1) {
            ans.push_back('1');
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        string ans = ob.minSum(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends