class Solution {
public:
    void inorder(TreeNode* root,vector<int>&res){
        if(root==NULL){
            return;
        }
        inorder(root->left,res);
        res.push_back(root);
        inorder(root->right,res);
        return;
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>root1Res,root2Res;
        inorder(root1,root1Res);
        inorder(root2,root2Res);
        vector<int>res;
        int i=0,j=0;
        while(i<root1Res.size()&&j<root2Res.size()){
            if(root1Res[i]<root2Res[j]){
                res.push_back(root1Res[i++]);
            }else{
                res.push_back(root2Res[j++]);
            }
        }
        while(i<root1Res.size()){
            res.push_back(root1Res[i++]);
        }
        while(j<root2Res.size()){
            res.push_back(root2Res[j++]);
        }
        return res;
    }
};