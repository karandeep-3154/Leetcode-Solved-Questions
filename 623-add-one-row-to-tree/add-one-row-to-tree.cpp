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

 TreeNode* addRow(TreeNode* root, int curDepth, int val, int depth) {
        
        if (!root) return NULL;
        
        if (curDepth == depth - 1) {

            TreeNode* leftSubTree = root->left;
            TreeNode* rightSubTree = root->right;
            
            root->left = new TreeNode(val);
            root->left->left = leftSubTree;
            
            root->right = new TreeNode(val);
            root->right->right = rightSubTree;
            
            return root;

        }
        
        root->left = addRow(root->left, curDepth + 1, val, depth);
        root->right = addRow(root->right, curDepth + 1, val, depth);
        
        return root;

    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        if(depth == 1){

            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;

        }

        return addRow(root, 1, val, depth);

    }
};