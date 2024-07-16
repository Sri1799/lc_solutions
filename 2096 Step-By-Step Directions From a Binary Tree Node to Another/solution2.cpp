/*
  - this impl has a better way of check for LCA
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

    TreeNode *getLCA(TreeNode *node, int s, int d, bool &lcaFound)
    {
        if (node == nullptr)
            return nullptr;
        
        // either lcaLeft is the lca itself OR it contains either s/d
        TreeNode *lcaLeft = getLCA(node->left, s, d, lcaFound);
        
        if (lcaFound)
            return lcaLeft;

        // node is lca
        if ((node->val == s || node->val == d) && lcaLeft)
        {
            lcaFound = true;
            return node;
        }

        // either lcaRight is the lca itself OR it contains either s/d
        TreeNode *lcaRite = getLCA(node->right, s, d, lcaFound);

        if (lcaFound)
            return lcaRite;

        // node is lca
        if ((node->val == s || node->val == d) && lcaRite)
        {
            lcaFound = true;
            return node;
        }

        // node doesn't have val, BUT it is lca
        if (lcaLeft && lcaRite)
        {
            lcaFound = true;
            return node;
        }

        if (lcaLeft)
            return lcaLeft;
    
        if (lcaRite)
            return lcaRite;

        // node (or any in its subtree) is not lca, lca is higher up the tree
        if (node->val == s || node->val == d)
            return node;
        
        return NULL;
    }

    int getLenOfPath(TreeNode *node, int val)
    {
        if (node == nullptr)
            return -1;
        
        if (node->val == val)
            return 0;
        
        int lplen = getLenOfPath(node->left, val);
        if (lplen != -1)
            return 1 + lplen;

        int rplen = getLenOfPath(node->right, val);
        if (rplen != -1)
            return 1 + rplen;

        return -1;
    }

    bool populatePathToDest(TreeNode *node, int destValue, string &ans)
    {
        if (node == nullptr)
            return false;
        
        if (node->val == destValue)
            return true;

        ans.push_back('L');
        if (populatePathToDest(node->left, destValue, ans))
            return true;
        ans.pop_back();

        ans.push_back('R');
        if (populatePathToDest(node->right, destValue, ans))
            return true;
        ans.pop_back();

        return false;
    }   

public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        bool lcaFound = false;
        TreeNode *lca = getLCA(root, startValue, destValue, lcaFound);

        // get LCA to startVal path
        int len = getLenOfPath(lca, startValue);      
        string ans(len, 'U');
        cout<<len<<endl;

        // get path
        populatePathToDest(lca, destValue, ans);

        return ans;
    }
};
