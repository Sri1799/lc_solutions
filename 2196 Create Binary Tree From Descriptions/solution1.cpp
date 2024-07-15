/*
  N is number of nodes, N ~= 2D
  tc - O(D)
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

    int getParVal(int p, unordered_map<int,int> &valToPar)
    {
        if (p == valToPar[p])
            return p;

        return valToPar[p] = getParVal(valToPar[p], valToPar);
    }

public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode *> valToNode;
        unordered_map<int,int> valToPar;
        int head_val = -1;

        for (auto &d:descriptions)
        {
            int p = d[0], c = d[1], left = d[2];
            TreeNode *pnode = valToNode[p];
            if (pnode == nullptr){
                pnode = new TreeNode(p);
                valToPar[p] = p;
                valToNode[p] = pnode;
            }

            TreeNode *cnode = valToNode[c];
            if (cnode == nullptr){
                cnode = new TreeNode(c);
                valToNode[c] = cnode;
            }

            head_val = valToPar[c] = getParVal(p, valToPar);
        
            if (left)
                pnode->left = cnode;
            else
                pnode->right = cnode;
        }

        return valToNode[head_val];
    }
};
