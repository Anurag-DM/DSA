/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*This is O(height) space
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if((root->val>=p->val && root->val<=q->val) || (root->val<=p->val && root->val>=q->val))
            return root;
        else if(root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);
        else
            return lowestCommonAncestor(root->right, p, q);
    }
};*/

//below is O(1) space
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root!=NULL){
            if(root->val > p->val && root->val > q->val)
                root=root->left;
            else if(root->val < p->val && root->val < q->val)
                root=root->right;
            else
                return root;
        }
        return root;
    }
};