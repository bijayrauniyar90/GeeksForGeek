//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    // Function to check if brackets are balanced or not
    bool ispar(string x) {
        stack<char> st;

        for (char bracket : x) {
            // If it's an opening bracket, push it onto the stack
            if (bracket == '(' || bracket == '{' || bracket == '[') {
                st.push(bracket);
            } 
            // If it's a closing bracket, check for a corresponding opening bracket
            else {
                if (st.empty()) return false;  // No opening bracket to match

                char topElement = st.top();
                st.pop();

                // Check if the top of the stack matches the current closing bracket
                if ((bracket == ')' && topElement != '(') ||
                    (bracket == '}' && topElement != '{') ||
                    (bracket == ']' && topElement != '[')) {
                    return false;
                }
            }
        }

        // If the stack is empty at the end, all brackets were balanced
        return st.empty();
    }
};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends