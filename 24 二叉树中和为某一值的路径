题目描述
输入一颗二叉树的跟节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
(注意: 在返回值的list中，数组长度大的数组靠前)
class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int> >res;
        if(!root) return res;
        vector<int>path;
        FindPathCore(root,expectNumber,res,path);
        return res;
    }
    void FindPathCore(TreeNode* root,int expectNumber, vector<vector<int>>&res, vector<int>&path){
        if(!root) return;
        path.push_back(root->val);
        if(root->val==expectNumber&&!root->left&&!root->right) res.push_back(path);//值为expectNumber，且是叶节点
        //不是叶节点
        if(root->left) FindPathCore(root->left,expectNumber-root->val,res,path);
        if(root->right) FindPathCore(root->right,expectNumber-root->val,res,path);//前序遍历
        //是叶节点了，但取值不对，则返回上一节点; 即使找到了满足的路径，也要删除节点，返回上一个。
        path.pop_back();
    }
};
