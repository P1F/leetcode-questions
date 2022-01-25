#include <iostream>
#include <queue>

using namespace std;

/*
116. Populating Next Right Pointers in Each Node

You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.
----------------------------------------------------------------------------------
Example 1:

Input: root = [1,2,3,4,5,6,7]
Output: [1,#,2,3,#,4,5,6,7,#]
Explanation: Given the above perfect binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.

Example 2:

Input: root = []
Output: []
--------------------------------------------------------------------------------- 
Constraints:

* The number of nodes in the tree is in the range [0, 212 - 1].
* -1000 <= Node.val <= 1000
--------------------------------------------------------------------------------- 
Follow up:

* You may only use constant extra space.
* The recursive approach is fine. You may assume implicit stack space does not count as extra space for this problem.
*/

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

// MY FIRST SOLUTION (Iterative - BFS with one loop)
// ANALYSIS:
// Time complexity - O(n)
// Space complexity - O(n) -> last level has N/2 nodes
class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        if (root) q.push(root);
        Node* cur = NULL;
        Node* prev = NULL;
        Node* last = root;
        while(!q.empty()){
             if (cur == last){
                last = q.back();
                cur->next = NULL;
                cur = NULL;
            }
            prev = cur;
            cur = q.front();
            q.pop();
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
            if (prev) prev->next = cur;
        }
            
        return root;
    }
};

// MY SECOND SOLUTION (Recursive DFS)
// ANALYSIS:
// Time complexity - O(n)
// Space complexity - O(1) -> not considering stack size
class Solution {
public:
    void connectChild(Node* node){
        if (!node->left) return;
        node->left->next = node->right;
        if(node->next) node->right->next = node->next->left;
        connectChild(node->left);
        connectChild(node->right);
    }
    Node* connect(Node* root) {
        if (root) connectChild(root);
        return root;
    }
};

// MY THIRD SOLUTION (Iterative - BFS with nested loops)
// ANALYSIS:
// Time complexity - O(n)
// Space complexity - O(n) -> last level has N/2 nodes
class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        if (root) q.push(root);
        while(!q.empty()){
            int sz = q.size();
            for (int i = 0; i < sz; i++){
                Node* cur = q.front();
                q.pop();
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
                if (i < sz-1)
                    cur->next = q.front();
            }
        }
            
        return root; 
    }
};

// LEETCODE BEST SOLUTION (Iterative - BFS & linked list)
// ANALYSIS:
// Time complexity - O(n)
// Space complexity - O(1)
class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return root;
        
        Node* leftmost = root;
        while(leftmost->left){
            Node* head = leftmost;
            while(head){
                head->left->next = head->right;
                if (head->next) head->right->next = head->next->left;
                head = head->next;
            }
            leftmost = leftmost->left;
        }
        
        return root;
    }
};

Node* listToBinTree(vector<string> treeList){
    if (treeList.size() == 0 || treeList[0] == "#") return NULL;

    int idx = 0;

    Node* root = &Node(stoi(treeList[idx]));
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()){
        int sz = q.size();
        for (int i = 0; i < sz; i++){
            Node* cur = q.front();
            q.pop();
            cur->left = (++idx >= treeList.size() || treeList[idx] == "#") ? NULL : &Node(stoi(treeList[idx]));
            cur->right = (++idx >= treeList.size() || treeList[idx] == "#") ? NULL : &Node(stoi(treeList[idx]));
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
    }
            
    return root; 
}

vector<string> binTreeToList(Node* root){
    vector<string> lst = {};
    queue<Node*> q;
    if(root) q.push(root);
    
    while(!q.empty()){
        int sz = q.size();
        for (int i = 0; i < sz; i++){
            Node* cur = q.front();
            q.pop();
            lst.push_back(to_string(cur->val));
            if (cur->left) q.push(cur->left);
            else lst.push_back("#");
            if (cur->right) q.push(cur->right);
            else lst.push_back("#");
        }
    }
            
    return lst; 
}

int main(){
    vector<string> inputTreeList1 = {"1","2","3","4","5","6","7"};
    vector<string> inputTreeList2 = {};

    Node* root1 = listToBinTree(treeList1);
    Node* root2 = listToBinTree(treeList2);

    vector<

    return 0;
}