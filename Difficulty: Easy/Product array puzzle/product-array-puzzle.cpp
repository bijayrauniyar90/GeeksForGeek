//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {

  public:

    vector<int> productExceptSelf(vector<int>& arr) {

        // code here

        int p=1, c=0;

        vector<int> res;

        for(int i:arr){

            if(i!=0) p*=i;

            else c++;

        }

        for(int i=0; i<arr.size(); i++){

            if(c>=2) res.push_back({0});

            else if(arr[i]!=0 && c==0) res.push_back(p/arr[i]);

            else if(arr[i]!=0 && c>0) res.push_back({0});

            else res.push_back(p);

        }

        return res;

    } 

};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        while (ss >> number) {
            arr.push_back(number);
        }

        Solution obj;
        vector<int> res = obj.productExceptSelf(arr);

        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends