//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *prev, *next;
};

struct Node* getNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

void printList(struct Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}


// } Driver Code Ends
/*structure of the node of the DLL is as
struct Node {
    int data;
    struct Node* prev, *next;
};
*/
// function should insert a new node in sorted way in
// a sorted doubly linked list
// Return the head after insertion
class Solution {
public:
    Node* sortedInsert(Node* head, int x) {
        // Create the new node to be inserted
        Node* newNode = getNode(x);

        // Case 1: The list is empty
        if (head == NULL) {
            return newNode;
        }

        // Case 2: Insert before the head if the new node's data is smaller
        if (head->data >= x) {
            newNode->next = head;
            head->prev = newNode;
            return newNode;
        }

        // Case 3: Traverse the list to find the correct insertion point
        Node* temp = head;
        while (temp->next != NULL && temp->next->data < x) {
            temp = temp->next;
        }

        // Insert the new node after 'temp'
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next = newNode;

        // If newNode is not the last node, adjust the next node's previous pointer
        if (newNode->next != NULL) {
            newNode->next->prev = newNode;
        }

        return head;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t

    while (t--) {
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        Node *head = nullptr, *tail = nullptr;
        int x;

        if (ss >> x) {
            head = getNode(x);
            tail = head;
        }

        while (ss >> x) {
            tail->next = getNode(x);
            tail->next->prev = tail;
            tail = tail->next;
        }

        int valueToInsert;
        cin >> valueToInsert;
        cin.ignore(); // Ignore the newline character after the value

        Solution obj;
        head = obj.sortedInsert(head, valueToInsert);
        printList(head);
    }

    return 0;
}

// } Driver Code Ends