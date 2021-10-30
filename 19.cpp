#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
19. Remove Nth Node From End of List

Given the head of a linked list, remove the nth node from the end of the list and return its head.
----------------------------------------------------------------------------------
Example 1:

Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:

Input: head = [1], n = 1
Output: []

Example 3:

Input: head = [1,2], n = 1
Output: [1]
--------------------------------------------------------------------------------- 
Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
--------------------------------------------------------------------------------- 
Follow up: Could you do this in one pass?
*/

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// MY FIRST SOLUTION (Two pass algorithm)
// ANALYSIS:
// Time complexity - O(n)
// Space complexity - O(1)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head || !head->next) return nullptr;
        ListNode* p = head;
        int sz = 1;
        while(p && p->next){
            p = p->next->next;
            sz += 2;
        }
        if (!p) sz -= 1;
        p = head;
        if (sz - n == 0){
            head = p->next;
            //free(p);
            return head;
        }
        for (int i = 1; i < sz - n; i++)
            p = p->next;
        ListNode* q = p->next;
        p->next = p->next->next;
        //free(q);
        return head;
    }
};

// MY FIRST SOLUTION (One pass algorithm)
// ANALYSIS:
// Time complexity - O(n)
// Space complexity - O(1)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head || !head->next) return nullptr;
        ListNode* p = head;
        ListNode* q = head;
        for (int i = 0; i < n; i++)
            p = p->next;
        if(!p) return head->next;
        p = p->next;
        while(p){
            p = p->next;
            q = q->next;
        }
        q->next = q->next->next;
        return head;
    }
};

// BEST SOLUTION (One pass algorithm with start node)
// ANALYSIS:
// Time complexity - O(n)
// Space complexity - O(1)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * start = new ListNode();
        start -> next = head;
        ListNode* fast = start;
        ListNode* slow = start;     

        for(int i = 1; i <= n; ++i)
            fast = fast->next;
    
        while(fast->next)
        {
            fast = fast->next;
            slow = slow->next;
        }
        
        slow->next = slow->next->next;
        
        return start->next;
    }
};

int main(){
    ListNode node5 = ListNode(5, nullptr);
    ListNode node4 = ListNode(4, &node5);
    ListNode node3 = ListNode(3, &node4);
    ListNode node2 = ListNode(2, &node3);
    ListNode node1 = ListNode(1, &node2);
    ListNode* head = &node1;

    ListNode* p = head;
    cout << "Exemplo 1" << endl;
    cout << "input: ";
    while(p){
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
    cout << "output: ";
    p = Solution().removeNthFromEnd(head, 2);
    while(p){
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl << endl;

    node1.val = 1; node1.next = nullptr;

    p = head;
    cout << "Exemplo 2" << endl;
    cout << "input: ";
    while(p){
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
    cout << "output: ";
    p = Solution().removeNthFromEnd(head, 1);
    while(p){
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl << endl;

    node2.val = 2; node2.next = nullptr;
    node1.val = 1; node1.next = &node2;

    p = head;
    cout << "Exemplo 3" << endl;
    cout << "input: ";
    while(p){
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
    cout << "output: ";
    p = Solution().removeNthFromEnd(head, 1);
    while(p){
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl << endl;

    return 0;
}