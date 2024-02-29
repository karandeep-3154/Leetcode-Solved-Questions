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
    bool isEvenOddTree(TreeNode* root) {
        
        queue<TreeNode*> odd, even;

        even.push(root);

        if(root->left == NULL and root->right == NULL)
        return (root->val%2) ? true : false;

        while(odd.size() or even.size()){

            if(odd.size()){

                int last = 1e9;

                while(odd.size()){
        

                    auto top = odd.front();
                    odd.pop();

                    if(top->val%2 or top->val>=last)
                    return false;

                    last = top->val;

                    if(top->left)
                    even.push(top->left);

                    if(top->right)
                    even.push(top->right);

                }

            }

            else{

                int last = -1;

                while(even.size()){


                    auto top = even.front();

                    even.pop();
                    if(top->val%2 == 0 or top->val<=last)
                    return false;

                    last = top->val;

                    if(top->left)
                    odd.push(top->left);

                    if(top->right)
                    odd.push(top->right);

                }


            }

        }

        return true;

    }
};