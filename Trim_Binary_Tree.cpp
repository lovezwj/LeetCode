/** Problem 669
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if(root == NULL || L > R) return NULL;
        if(root->val > R) return trimBST(root->left, L, R);
        else if(root->val < L) return trimBST(root->right, L, R);
        root->left = trimBST(root->left, L, root->val-1);
        root->right = trimBST(root->right, root->val+1, R);
        return root;
    }
};
