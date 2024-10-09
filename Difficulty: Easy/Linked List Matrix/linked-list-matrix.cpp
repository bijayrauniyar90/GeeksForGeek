//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *right, *down;

    Node(int x) {
        data = x;
        right = NULL;
        down = NULL;
    }
};


// } Driver Code Ends
/*structure of the node of the linked list is as

struct Node
{
    int data;
    Node* right, *down;

    Node(int x){
        data = x;
        right = NULL;
        down = NULL;
    }
};
*/

// function must return the pointer to the first element of the in linked list i.e. that
// should be the element at arr[0][0]
class Solution {
  public:
     Node* constructLinkedMatrix(vector<vector<int>>& mat) {
         Node* mainhead=new Node(mat[0][0]);
         int row=mat.size();
         int col=mat[0].size();
         Node* heads[row];
         
         //row=1 
         Node* temp=mainhead;
         for(int i=1;i<col;i++){
             Node* newnode=new Node(mat[0][i]);
             temp->right=newnode;
             temp=temp->right;
         }
         heads[0]=mainhead;
         //remaining row
         for(int j=1;j<row;j++){
            heads[j]=new Node(mat[j][0]);
             Node* temp1=heads[j];
             for(int k=1;k<col;k++){
                 Node* newnode=new Node(mat[j][k]);
             temp1->right=newnode;
             temp1=temp1->right; 
             }
         }
         
         //connect them
         for(int i=0;i<row-1;i++){
             Node* p=heads[i];
             Node* q=heads[i+1];
             while(p!=NULL && q!=NULL){
                 p->down=q;
                 p=p->right;
                 q=q->right;
             }
         }
         return mainhead;
    }
};

//{ Driver Code Starts.

void display(Node* head) {
    Node* Rp;
    Node* Dp = head;
    while (Dp) {
        Rp = Dp;
        while (Rp) {
            cout << Rp->data << " ";
            if (Rp->right)
                cout << Rp->right->data << " ";
            else
                cout << "null ";
            if (Rp->down)
                cout << Rp->down->data << " ";
            else
                cout << "null ";
            Rp = Rp->right;
        }
        Dp = Dp->down;
    }
}

// Driver program
int main() {
    int t;
    cin >> t;
    cin.ignore(); // To handle new line after integer input

    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;

        // Read the first row of the matrix
        while (ss >> num) {
            nums.push_back(num);
        }

        int n = nums.size();
        vector<vector<int>> mat(n, vector<int>(n));
        mat[0] = nums;

        // Read the remaining rows of the matrix
        for (int i = 1; i < n; i++) {
            string line;
            getline(cin, line);
            stringstream ss(line);
            vector<int> nums;
            int num;

            // Read the first row of the matrix
            while (ss >> num) {
                nums.push_back(num);
            }

            mat[i] = nums;
        }

        Solution ob;
        Node* head = ob.constructLinkedMatrix(mat);
        if (!head) {
            cout << "-1\n";
        } else {
            display(head);
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends