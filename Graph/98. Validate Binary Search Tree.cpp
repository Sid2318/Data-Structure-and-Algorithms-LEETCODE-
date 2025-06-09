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
//     void dfs(TreeNode* root, bool& flag,int min , int max, int dir){
//         if(root == nullptr){
//             return;
//         }

//         cout<<"min = "<<min<<" max = "<<max<<" val = "<<root->val<<" dir = "<<dir<<endl;
//         // if(dir == 0){
//             if(max<=root->val || min>=root->val){
//                 flag = false;
//                 return;
//             }
//         // }
//         // if(dir == 1){
//         //     if(min>=root->val){
//         //         // cout<<"min = "<<min<<" max = "<<max<<" val = "<<root->val<<" dir = "<<dir<<endl;
//         //         flag = false;
//         //         return;
//         //     }
//         // }

//         dfs(root->right,flag,root->val,max,0);
//         dfs(root->left,flag,min, root->val,1); 
//     }

// public:
//     bool isValidBST(TreeNode* root) {
//         bool flag = true;
//         int mini = root->val;
//         int maxi = root->val;
//         int dir = 1;

//         //right = 1;
//         //left = 0
//         dfs(root->left,flag,INT_MIN,maxi,0);
//         dfs(root->right,flag,mini,INT_MAX,1);

//         return flag;
//     }
// };

class Solution {
private:
    bool dfs(TreeNode* root, long long minVal, long long maxVal) {
        if (!root) return true;

        if (root->val <= minVal || root->val >= maxVal)
            return false;

        return dfs(root->left, minVal, root->val) && dfs(root->right, root->val, maxVal);
    }

public:
    bool isValidBST(TreeNode* root) {
        return dfs(root, LONG_MIN, LONG_MAX);
    }
};
