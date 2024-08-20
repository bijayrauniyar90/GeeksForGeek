//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
public:
    int minTime(Node* root, int target) {
        Node* targetNode = nullptr;
        std::unordered_map<Node*, Node*> parentMap;
        findTargetAndParents(root, target, nullptr, targetNode, parentMap);

        std::unordered_set<Node*> visited;
        return burnTree(targetNode, parentMap, visited) - 1;
    }

private:
    void findTargetAndParents(Node* node, int target, Node* parent, 
                              Node*& targetNode, 
                              std::unordered_map<Node*, Node*>& parentMap) {
        if (!node) return;
        
        if (node->data == target) {
            targetNode = node;
        }
        
        if (parent) {
            parentMap[node] = parent;
        }

        findTargetAndParents(node->left, target, node, targetNode, parentMap);
        findTargetAndParents(node->right, target, node, targetNode, parentMap);
    }

    int burnTree(Node* node, std::unordered_map<Node*, Node*>& parentMap, 
                 std::unordered_set<Node*>& visited) {
        if (!node || visited.count(node)) return 0;
        
        visited.insert(node);

        int leftTime = burnTree(node->left, parentMap, visited);
        int rightTime = burnTree(node->right, parentMap, visited);
        int parentTime = burnTree(parentMap[node], parentMap, visited);

        return 1 + std::max({leftTime, rightTime, parentTime});
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends