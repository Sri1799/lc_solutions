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

    bool find(TreeNode *root, int val, deque<char> &q)
    {
        if (root == nullptr)
            return false;

        if (root->val == val)
            return true;
        
        q.push_back('L');
        if (find(root->left, val, q))
            return true;
        q.pop_back();

        q.push_back('R');
        if (find(root->right, val, q))
            return true;
        q.pop_back();

        return false;
    }

public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        /*
        - case 1: both start and dest in left/right subtree
        - case 2: start/dest is root but dest/start is in left/right subtree
        - case 3: start in right/left and dest in left/right subtree
        */
        deque<char> sq, dq;
        // find path to startValue
        find(root, startValue, sq);

        // find path to destValue
        find(root, destValue, dq);
    
        while (sq.size() && dq.size() && sq.front() == dq.front())
        {
            sq.pop_front();
            dq.pop_front();
        }

        string ans(sq.size(), 'U');

        while (dq.size())
        {
            ans += dq.front();
            dq.pop_front();
        }

        return ans;
    }
};
