//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    int maxDistance(vector<int>& arr) {
        unordered_map<int, int> map; // Map to store first occurrence of each element
        int dist = 0; // Initialize maximum distance

        for (int i = 0; i < arr.size(); i++) {
            // If the element is not in the map, store its index
            if (map.find(arr[i]) == map.end()) {
                map[arr[i]] = i;
            } else {
                // Calculate the distance between current index and first occurrence
                dist = max(dist, i - map[arr[i]]);
            }
        }
        
        return dist; // Return the maximum distance found
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

        stringstream s1(input);
        int num;
        while (s1 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.maxDistance(arr) << endl;
    }
    return 0;
}
// } Driver Code Ends