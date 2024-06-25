/*
  tc - O(N)
  sc - O(N)
  instead of passing currSum by reference each time - just made it a private variable. Saved a lot of time. 
  This solution beats 100%
*/

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

    int currSum = 0;

    void solve(TreeNode* root)
    {
        if (!root)
            return;

        solve(root->right);
        root->val += currSum;
        currSum = root->val;
        solve(root->left);
    }

public:
    TreeNode* bstToGst(TreeNode* root) {
        /*
        - call right, than node, than left
        - pass in a currSum var by ref to keep track of the sums of greater elems read so far
        solve(rightnode)
        node->val += currSum
        currSum = node->val
        solve(leftnode)
        */
        solve(root);
        return root;
    }
};
