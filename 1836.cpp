#include <iostream>
#include <vector>
#include <math.h>
#include <unordered_map>

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

// 1836. Remove Duplicates From an Unsorted Linked List

// MY FIRST SOLUTION
/*
    ANALYSIS:
    Time complexity: O(n) average | O(n^3) worst case
    Space complexity: O(n)
*/
class Solution
{
public:
    ListNode *deleteDuplicatesUnsorted(ListNode *head)
    {
        // SOLUTION BY P1F

        ListNode sentinel = ListNode(0, head);
        ListNode *prev = &sentinel;
        unordered_map<int, int> occurrences;

        while (head)
        {
            occurrences[head->val]++;
            head = head->next;
        }

        head = sentinel.next;

        while (head)
        {
            if (occurrences[head->val] > 1)
                prev->next = head->next;
            else
                prev = prev->next;
            head = head->next;
        }

        return sentinel.next;
    }
};
