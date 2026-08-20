/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
    void parentassign(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent, TreeNode *par)
    {
        if (root == NULL)
            return;

        parent[root] = par;

        parentassign(root->left, parent, root);
        parentassign(root->right, parent, root);
    }

    void solve(TreeNode *root, int k, unordered_map<TreeNode *, TreeNode *> &parent, vector<int> &ans, unordered_map<TreeNode *, bool> &vis)
    {
        if (root == NULL || k < 0 || vis[root])
            return;

        if (k == 0)
        {
            ans.push_back(root->val);
            return;
        }

        vis[root] = true;
        solve(root->left, k - 1, parent, ans, vis);
        solve(root->right, k - 1, parent, ans, vis);
        solve(parent[root], k - 1, parent, ans, vis);
    }

public:
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        unordered_map<TreeNode *, TreeNode *> parent;

        parentassign(root, parent, NULL);

        vector<int> ans;
        unordered_map<TreeNode *, bool> vis;
        solve(target, k, parent, ans, vis);

        return ans;
    }
};