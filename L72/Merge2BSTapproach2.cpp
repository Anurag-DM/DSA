//this is time O(m+n) and space O(h1+h2)
/*************************************************************

    Binary Tree node structure:

    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right)
            : data(x), left(left), right(right) {}
    };

*************************************************************/

#include <bits/stdc++.h>
using namespace std;

/*---------------- STEP 1: BST to Sorted DLL ----------------*/

void bstToDLL(TreeNode* root, TreeNode* &head, TreeNode* &prev) {
    if (!root) return;

    bstToDLL(root->left, head, prev);

    if (!prev)
        head = root;
    else {
        root->left = prev;
        prev->right = root;
    }
    prev = root;

    bstToDLL(root->right, head, prev);
}

/*---------------- STEP 2: Merge Two Sorted DLLs ----------------*/

TreeNode* mergeDLL(TreeNode* head1, TreeNode* head2) {
    if (!head1) return head2;
    if (!head2) return head1;

    TreeNode* head = NULL;
    TreeNode* tail = NULL;

    while (head1 && head2) {
        TreeNode* temp;
        if (head1->data < head2->data) {
            temp = head1;
            head1 = head1->right;
        } else {
            temp = head2;
            head2 = head2->right;
        }

        temp->left = tail;
        if (tail) tail->right = temp;
        else head = temp;

        tail = temp;
    }

    TreeNode* remaining = head1 ? head1 : head2;
    while (remaining) {
        remaining->left = tail;
        tail->right = remaining;
        tail = remaining;
        remaining = remaining->right;
    }

    return head;
}

/*---------------- STEP 3: DLL to Balanced BST ----------------*/

int countNodes(TreeNode* head) {
    int cnt = 0;
    while (head) {
        cnt++;
        head = head->right;
    }
    return cnt;
}

TreeNode* DLLToBST(TreeNode* &head, int n) {
    if (n <= 0 || !head) return NULL;

    TreeNode* leftSubtree = DLLToBST(head, n / 2);

    TreeNode* root = head;
    root->left = leftSubtree;

    head = head->right;

    root->right = DLLToBST(head, n - n / 2 - 1);

    return root;
}

/*---------------- FINAL FUNCTION ----------------*/

TreeNode* mergeBST(TreeNode* root1, TreeNode* root2) {

    // Convert BSTs to DLLs
    TreeNode *head1 = NULL, *prev1 = NULL;
    TreeNode *head2 = NULL, *prev2 = NULL;

    bstToDLL(root1, head1, prev1);
    bstToDLL(root2, head2, prev2);

    // Merge DLLs
    TreeNode* mergedHead = mergeDLL(head1, head2);

    // Convert merged DLL to balanced BST
    int totalNodes = countNodes(mergedHead);
    return DLLToBST(mergedHead, totalNodes);
}
