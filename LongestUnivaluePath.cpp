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
    int solution_res;
    int longestUnivaluePath(TreeNode* root) {
        if (root == NULL) return 0;
        solution_res = 0;
        vector<int> res = dfs(root);
        int cur_res = find_max(res);
        if(cur_res > solution_res) solution_res = cur_res;
        return solution_res - 1;
    }
    
    int find_max(vector<int> three_values) {
        int max_value = three_values[0];
        if (three_values[1] > max_value) max_value = three_values[1];
        if (three_values[2] > max_value) max_value = three_values[2];
        return max_value;
    }
    
    vector<int> dfs(TreeNode* root) { //root一定不是NULL，返回值有三个元素，res[0]表示包含root结点的结果，res[1]表示root左子树的结果，res[2]表示root右子树的结果
        vector<int> res(3,0);
        int same = 1;
        int left = 0;
        int right = 0;
        int left_same = 0, right_same = 0;
        if (root->left != NULL) {
            vector<int> tmp = dfs(root->left);
            if(root->val == root->left->val) {
                left_same = tmp[0];
            }
            left = find_max(tmp);
        }
        if (root->right != NULL) {
            vector<int> tmp = dfs(root->right);
            if(root->val == root->right->val) {
                right_same = tmp[0];
            }
            right = find_max(tmp);
        }
        res[0] = same + (left_same > right_same ? left_same : right_same);
        res[1] = left;
        res[2] = right;
        if (same + left_same + right_same > solution_res) solution_res = same + left_same + right_same;
        return res;
    }
};
