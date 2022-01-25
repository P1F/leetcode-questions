#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// MY FIRST SOLUTION - Recursive
class Solution {
private:
    vector<int> res;
public:
    void traverse(TreeNode* node){
        if (!node) return;
        traverse(node->left);
        res.push_back(node->val);
        traverse(node->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        res = {};
        traverse(root);
        return res;
    }
};

// MY SECOND SOLUTION - Iterative
class Solution {
private:
    vector<int> res;
public:
    vector<int> preorderTraversal(TreeNode* root) {
        res = {};
        stack<TreeNode*> s;
        if (root) s.push(root);
        TreeNode* aux;
        while(!s.empty()){
            aux = s.top();
            s.pop();
            res.push_back(aux->val);
            if(aux->right) s.push(aux->right);
            if(aux->left) s.push(aux->left);
        }        
        return res;
    }
};