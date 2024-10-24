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
    bool flipEquiv(TreeNode* r, TreeNode* p) {
        
        if (!r && !p)
            return true;

        if (!r || !p)
            return false;

        return r->val == p->val && (flipEquiv(r->left, p->right) || flipEquiv(r->left, p->left)) 
        && (flipEquiv(r->right, p->left) || flipEquiv(r->right, p->right));   
    }
};

/*
TC O(N)
SC O(N)
*/
