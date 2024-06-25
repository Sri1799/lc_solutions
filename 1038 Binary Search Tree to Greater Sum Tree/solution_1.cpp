/*
  tc - O(N)
  sc - O(N)
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

    void solve(TreeNode* root, int &currSum)
    {
        if (!root)
            return;

        solve(root->right, currSum);
        root->val += currSum;
        currSum = root->val;
        solve(root->left, currSum);
    }

public:
    TreeNode* bstToGst(TreeNode* root) {
        /*
        - call right, than node, than left
        - pass in a currSum var by ref to keep track of the sums of greater elems read so far
        solve(rightnode, currSum)
        node->val += currSum
        currSum = node->val
        solve(leftnode, currSum)
        */
        int currSum = 0;
        solve(root, currSum);
        return root;
    }
};
