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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return NULL;
        }
        if(root==p || root==q){
            return root;
        }

        TreeNode* leftSub=lowestCommonAncestor(root->left,p,q);
        TreeNode* rightSub=lowestCommonAncestor(root->right,p,q);

        if(leftSub!=NULL && rightSub!=NULL) return root;
        else if(leftSub!=NULL && rightSub==NULL) return leftSub;
        else if(leftSub==NULL && rightSub!=NULL) return rightSub;

        return NULL;

    }
};
