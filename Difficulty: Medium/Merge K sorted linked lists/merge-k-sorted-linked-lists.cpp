/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/




class Solution {
public:
    struct Compare {
        bool operator()(Node* a, Node* b) {
            return a->data > b->data; // min-heap
        }
    };

    Node* mergeKLists(vector<Node*>& arr) {
        priority_queue<Node*, vector<Node*>, Compare> pq;

        // Push the head of each list into min-heap
        for (auto list : arr) {
            if (list) pq.push(list);
        }

        Node dummy(0);
        Node* tail = &dummy;

        while (!pq.empty()) {
            Node* smallest = pq.top();
            pq.pop();

            tail->next = smallest;
            tail = tail->next;

            if (smallest->next) {
                pq.push(smallest->next);
            }
        }

        return dummy.next;
    }
};
