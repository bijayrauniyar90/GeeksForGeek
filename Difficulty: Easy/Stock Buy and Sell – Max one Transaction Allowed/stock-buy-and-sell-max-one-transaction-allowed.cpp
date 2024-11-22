//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   int maximumProfit(vector<int> &prices) {
    int maxProfit = 0;
    int minPrice = prices[0];

    for (int price : prices) {
        // Update the minimum price encountered so far
        minPrice = min(minPrice, price);

        // Calculate the potential profit and update the maximum profit
        maxProfit = max(maxProfit, price - minPrice);
    }

    return maxProfit;
}

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> prices;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            prices.push_back(number);
        }

        Solution ob;
        int ans = ob.maximumProfit(prices);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends