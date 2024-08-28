//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    // Custom comparison function for sorting.
    static bool condition(const pair<int, int>& p1, const pair<int, int>& p2) {
        // If frequencies are the same, compare elements
        return (p1.second == p2.second) ? p1.first < p2.first : p1.second > p2.second;
    }

    // Function to sort the array according to the frequency of elements.
    vector<int> sortByFreq(vector<int>& arr) {
        unordered_map<int, int> freqMap;

        // Step 1: Calculate frequency of each element.
        for (int num : arr) {
            freqMap[num]++;
        }

        // Step 2: Store elements and their frequencies as pairs in a vector.
        vector<pair<int, int>> freqVec(freqMap.begin(), freqMap.end());

        // Step 3: Sort the vector based on frequency and then value.
        sort(freqVec.begin(), freqVec.end(), condition);

        // Step 4: Generate the sorted array.
        vector<int> result;
        result.reserve(arr.size()); // Reserve space to optimize memory allocation
        for (const auto& p : freqVec) {
            result.insert(result.end(), p.second, p.first);
        }

        return result;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution obj;
        vector<int> v;
        v = obj.sortByFreq(arr);
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends