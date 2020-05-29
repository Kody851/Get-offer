题目描述
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
@知识点：
取vector的一部分：
vector<int>a{1,2,3,4,5};
vector<int>b(a.begin(),a.begin()+2);//b={1,2}

class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.empty()||vin.empty()) return NULL;
        TreeNode* root=new TreeNode(pre[0]);
        int i=0;
        for(;i<vin.size();i++){
            if(vin[i]==pre[0]) break;
        }
        vector<int>pre_left(pre.begin()+1,pre.begin()+i+1);//包含到pre.begin()+i,共i个
        vector<int>vin_left(vin.begin(),vin.begin()+i);
        vector<int>pre_right(pre.begin()+i+1,pre.end());
        vector<int>vin_right(vin.begin()+i+1,vin.end());
        root->left=reConstructBinaryTree(pre_left,vin_left);
        root->right=reConstructBinaryTree(pre_right,vin_right);
        return root;
    }
};
