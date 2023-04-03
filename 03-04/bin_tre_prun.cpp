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
// public:
//     bool helper(TreeNode * root){
//         if(!root) return false;
//         if(!helper(root -> right)) root -> right = 0;
//         if(!helper(root -> left)) root -> left = 0; 
//         if(!(root -> right) and !(root -> left) and root -> val == 0)
//             return false;
//         return true;
//     }
//     TreeNode* pruneTree(TreeNode* root) {
//         if(helper(root))
//             return root;
//         return 0;
//     }
// };
class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(!root) return root;
        if(!pruneTree(root -> right)) root -> right = 0;
        if(!pruneTree(root -> left)) root -> left = 0; 
        if(!(root -> right) and !(root -> left) and root -> val == 0)
            return 0;
        return root;
    }
};