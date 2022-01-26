#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 83. Remove Duplicates from Sorted List

// MY SOLUTION
/*
    ANALYSIS:
    Time complexity: O(n)
    Space complexity: O(1)
*/
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *pred = head;
        ListNode *curr = head;

        while (curr != NULL)
        {
            if (curr->next && curr->val == curr->next->val)
            {
                pred = curr;
                while (curr->next && curr->val == curr->next->val)
                    curr = curr->next;
                pred->next = curr->next;
            }
            else
            {
                pred = pred->next;
            }
            curr = curr->next;
        }

        return head;
    }
};

// PADEIRO SOLUTION
/*
    ANALYSIS:
    Time complexity: O(n)
    Space complexity: O(1)
*/
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *pred = head;
        ListNode *curr = head;

        while (curr != NULL)
        {
            pred = curr;
            if (curr->next && curr->val == curr->next->val)
            {
                while (curr->next && curr->val == curr->next->val)
                    curr = curr->next;
                pred->next = curr->next;
            }
            curr = curr->next;
        }

        return head;
    }
};

// LEETCODE SOLUTION
/*
    ANALYSIS:
    Time complexity: O(n)
    Space complexity: O(1)
*/
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *curr = head;
        while (curr && curr->next)
        {
            if (curr->val == curr->next->val)
                curr->next = curr->next->next;
            else
                curr = curr->next;
        }

        return head;
    }
};

// CONCISE SOLUTION (https://leetcode.com/problems/remove-duplicates-from-sorted-list/discuss/28730/Concise-solution-and-memory-freeing)
/*
    ANALYSIS:
    Time complexity: O(n)
    Space complexity: O(1)
*/
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *curr = head;
        while (curr)
        {
            while (curr->next && curr->val == curr->next->val)
                curr->next = curr->next->next;
            curr = curr->next;
        }

        return head;
    }
};

// RECURSIVE SOLUTION (https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/discuss/28355/Simple-and-clear-c%2B%2B-recursive-solution)
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head)
            return 0;
        if (!head->next)
            return head;

        int val = head->val;
        ListNode *p = head->next;

        if (p->val != val)
        {
            head->next = deleteDuplicates(p);
            return head;
        }
        else
        {
            while (p && p->val == val)
                p = p->next;
            return deleteDuplicates(p);
        }
    }
};