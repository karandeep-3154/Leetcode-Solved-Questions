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

/*
DFS Function returns Number of coins given by root upwards to its immediate above parent.

We could have taken it to No. of coins required by root as well but in that case, we need to change our formula to 1+left+right-root->val

Updating count variable denotes at each nodes as from node a we are transeferring or accepting left coins from left subtree and right coins from right subtree

returning root->val - 1 + left + right as it denotes the total coins being returned or taken by current subtree including root

*/

    int dfs(TreeNode* root, int &count){

        if(!root)
        return 0;

        int left = dfs(root->left, count);
        int right = dfs(root->right, count);

        count += (abs(left) + abs(right));

        return root->val - 1 + left + right;

    }

    int distributeCoins(TreeNode* root) {

        int count = 0;

        dfs(root, count);

        return count;

    }
};