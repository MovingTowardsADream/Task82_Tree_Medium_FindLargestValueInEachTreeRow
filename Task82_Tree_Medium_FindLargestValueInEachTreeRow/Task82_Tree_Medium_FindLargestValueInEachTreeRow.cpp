#include <iostream>
#include <vector>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    std::vector<int> result;
    std::vector<int> largestValues(TreeNode* root) {
        MaxValue(root, 1);
        return result;
    }

    void MaxValue(TreeNode* node, int lvl) {
        if (node == nullptr) return;
        if (result.size() < lvl) result.push_back(node->val);
        else if (result[lvl - 1] < node->val) result[lvl - 1] = node->val;
        MaxValue(node->left, lvl + 1);
        MaxValue(node->right, lvl + 1);
    }
};