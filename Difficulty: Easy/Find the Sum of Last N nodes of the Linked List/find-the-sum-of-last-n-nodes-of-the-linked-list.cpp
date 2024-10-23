//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends

  class Solution {
public:
    int sumOfLastN_Nodes(struct Node* head, int n) {
        Node* toBeRemoved = head;  // Pointer to track nodes to be removed from the sum
        Node* ptr = head;          // Pointer to iterate through the list
        
        int sum = 0;               // Variable to store the sum of last 'n' nodes
        
        // Traverse the list
        while (ptr) {
            sum += ptr->data;  // Add the current node's data to sum

            // Once `n` nodes are traversed, start subtracting from sum using `toBeRemoved`
            if (n == 0) {
                sum -= toBeRemoved->data;
                toBeRemoved = toBeRemoved->next;
            } else {
                n--;  // Decrease `n` until it reaches zero
            }
            
            ptr = ptr->next;  // Move to the next node
        }
        
        return sum;  // Return the final sum of the last 'n' nodes
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
        int n;
        cin >> n;
        cin.ignore();
        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        Solution ob;
        cout << ob.sumOfLastN_Nodes(head, n) << endl;
    }
    return 0;
}
// } Driver Code Ends