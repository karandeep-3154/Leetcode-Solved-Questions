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

    void solve(TreeNode* root, string p, int& ans){

        if(root == NULL)
        return;

        p = p+to_string(root->val);

        if(root->left == NULL and root->right == NULL)
        ans+= stoi(p);

        solve(root->left,p,ans);
        solve(root->right,p,ans);


    }

    int sumNumbers(TreeNode* root) {
        int ans = 0;
        solve(root,"",ans);
        return ans;
    }
};