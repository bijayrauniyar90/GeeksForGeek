//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
public:
    // Function to split a linked list into two lists alternately
    vector<Node*> alternatingSplitList(struct Node* head) {
        vector<Node*> result(2, nullptr);  // Result will contain two lists
        
        // Pointers for two new lists
        Node* list1 = nullptr;
        Node* list2 = nullptr;
        Node* tail1 = nullptr;
        Node* tail2 = nullptr;
        
        Node* current = head;
        int i = 0;
        
        while (current != nullptr) {
            if (i % 2 == 0) {
                // Add to list1
                if (!list1) {
                    list1 = current;
                    tail1 = list1;
                } else {
                    tail1->next = current;
                    tail1 = tail1->next;
                }
            } else {
                // Add to list2
                if (!list2) {
                    list2 = current;
                    tail2 = list2;
                } else {
                    tail2->next = current;
                    tail2 = tail2->next;
                }
            }
            current = current->next;
            i++;
        }
        
        // Make sure to terminate both lists
        if (tail1) tail1->next = nullptr;
        if (tail2) tail2->next = nullptr;
        
        result[0] = list1;
        result[1] = list2;
        return result;
    }
};



//{ Driver Code Starts.

void printList(struct Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

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

        struct Node* head = new Node(arr[0]);
        struct Node* tail = head;

        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }

        Solution ob;
        vector<Node*> result = ob.alternatingSplitList(head);
        printList(result[0]);
        printList(result[1]);
    }

    return 0;
}

// } Driver Code Ends