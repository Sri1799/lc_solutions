/*
  tc - O(N) => inorder traversal of the tree followed by calling buildBalancedSearchTree 2^(h+1) - 1 times, but h is logN => hence total calls are multiple of N only. 
  sc - O(N + logN) => to store the nodes in 'order' and size of call stack can be maximum height of the binary search tree => logN
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
    vector<TreeNode *> order;

    void getOrder(TreeNode *root)
    {
        if (!root)
            return;

        getOrder(root->left);
        order.push_back(root);
        getOrder(root->right);
    }

    TreeNode *buildBalancedBST(int l, int r)
    {
        if (l>r)
            return NULL;
        
        int mid = l + (r-l)/2;
        TreeNode *node = order[mid];
        node->left = buildBalancedBST(l, mid-1);
        node->right = buildBalancedBST(mid + 1, r);
        return node;
    }

public:
    TreeNode* balanceBST(TreeNode* root) {
        
        getOrder(root);

        return buildBalancedBST(0, order.size() - 1);
    }
};
