#include <iostream>       // std::cout
#include <queue>          // std::priority_queue
#include <vector>         // std::vector

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


struct compare {
    bool operator()(const ListNode* l, const ListNode* r) {
        return l->val > r->val;
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<ListNode*, std::vector<ListNode*>, compare> q(lists.begin(), lists.end()); 
        ListNode head(0);
        ListNode* curr  = &head;

        while(!q.empty()) {
             ListNode* n = q.top();
             q.pop();
             if (n->next)
                q.push(n->next);
            curr->next = n;
            n->next=nullptr;
        }

        return head.next; 
    }

