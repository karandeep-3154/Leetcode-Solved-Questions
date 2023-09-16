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

    void preorder(TreeNode* root, vector<int>& ans){

        if(root == NULL)
        return;

        stack<TreeNode*> s;

        s.push(root);

        while(s.size()){

            auto top = s.top();
            s.pop();

            ans.push_back(top->val);

            if(top->right)
            s.push(top->right);

            if(top->left)
            s.push(top->left);

        }

    }

    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int> ans;

        preorder(root, ans);

        return ans;

    }
};