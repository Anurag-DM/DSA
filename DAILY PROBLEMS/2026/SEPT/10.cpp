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

 // 2265. Count Nodes Equal to Average of Subtree
 // Time complexity : O(n) where n is the no of nodes
 // Space Complexity : O(h) where h is the height of the tree
class Solution {
    pair<int, int> solve(TreeNode* root, int &ans){
        if(root == NULL)
            return {0, 0};
        
        pair<int, int> left = solve(root->left, ans);
        pair<int, int> right = solve(root->right, ans);

        //in the pair the first indicates sum and the second indicates count
        int count = left.second + right.second + 1;
        int sum = left.first + right.first + root->val;

        if(sum / count == root->val)
            ans++;
        
        return {sum, count};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};