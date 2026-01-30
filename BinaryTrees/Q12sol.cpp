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
class Solution {
public:
    void allnodes(TreeNode* root, vector<int>& nodes){
        if(root==NULL){
            return;
        }
        allnodes(root->left,nodes);
        nodes.push_back(root->val);
        allnodes(root->right, nodes);

        return;
    }
    bool findTarget(TreeNode* root, int k) {

        vector<int>nodes;
        allnodes(root, nodes);

        int left=0, right=nodes.size()-1;
        while(left<right){
            if(nodes[left]+nodes[right]==k){
                return true;
            }
            else if(nodes[left]+nodes[right]>k){
               right--;
            }
            else{
                left++;
            }

        }
        return false;

        
    }
};
