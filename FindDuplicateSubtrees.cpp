/**
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
    vector<TreeNode*> nums;
    unordered_map<string, int> unmp;
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        Search(root);
        return nums;
    }
    string Search(TreeNode* root) {
        if (root == NULL) return "#";
        string str = to_string(root->val) + ',' + Search(root->left) + ',' + Search(root->right);
        unmp[str]++;
        if (unmp[str] == 2) {
            nums.push_back(root);
        }
        return str;
    }
};
