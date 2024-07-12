//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};


// } Driver Code Ends
/* Link list Node
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
    
class Solution {
public:
    bool isCircular(Node *head) {
        if (head == nullptr) {
            return 1; 
        }

        Node *slow = head, *fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                return true; 
            }
        }
        return false; 
    }
};


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

/* Should return true if linked list is circular, else false */
class Solution {
  public:
    bool isCircular(Node *head) {
        if(head==NULL){
            return 1;
        }
        Node *slw=head,*fst=head;
        while(fst!=NULL && fst->next!=NULL){
           
            fst=fst->next->next;
            slw=slw->next;
             if(fst==slw){
                return 1;
            }
        }
        return 0;
    }
};


//{ Driver Code Starts.

// Driver program to test above function
int main() {
    int t, k;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t

    while (t--) {
        cin >> k;
        cin.ignore(); // Ignore the newline character after k

        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        Node *head = nullptr, *tail = nullptr;
        int x;

        if (ss >> x) {
            head = new Node(x);
            tail = head;

            while (ss >> x) {
                tail->next = new Node(x);
                tail = tail->next;
            }

            // Link the last node to the head if k is 1 to make it circular
            if (k == 1) {
                tail->next = head;
            }
        }

        Solution obj;
        cout << (obj.isCircular(head) ? "true" : "false") << endl;
    }
    return 0;
}

// } Driver Code Ends