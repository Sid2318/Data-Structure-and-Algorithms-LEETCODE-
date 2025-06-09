// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// private:
//     bool dfs(TreeNode* root, int targetSum){
//         if(root == nullptr){
//             if(targetSum == 0){
//                 return true;
//             }
//             else{
//                 return false;
//             }
//         }

//         return dfs(root->left,targetSum-root->val) || dfs(root->right,targetSum-root->val);
//     }
// public:
//     bool hasPathSum(TreeNode* root, int targetSum) {
//         if(root == nullptr){
//             return false;
//         }
//         return dfs(root,targetSum);
//     }
// };

class Solution {
private:
    bool dfs(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return false;
        }

        // Check if it's a leaf node
        if (root->left == nullptr && root->right == nullptr) {
            return (targetSum == root->val);
        }

        // Continue DFS on left and right subtrees
        return dfs(root->left, targetSum - root->val) || dfs(root->right, targetSum - root->val);
    }

public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return dfs(root, targetSum);
    }
};
