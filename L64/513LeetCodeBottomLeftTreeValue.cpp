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
class Solution
{
    void solve(TreeNode *root, int lvl, int &maxlvl, int &ans)
    {
        if (root == NULL)
            return;

        if (lvl > maxlvl)
        {
            maxlvl = lvl;
            ans = root->val;
        }

        solve(root->left, lvl + 1, maxlvl, ans);
        solve(root->right, lvl + 1, maxlvl, ans);
    }

public:
    int findBottomLeftValue(TreeNode *root)
    {
        int ans = 0, maxlvl = -1;
        solve(root, 0, maxlvl, ans);
        return ans;
    }
};