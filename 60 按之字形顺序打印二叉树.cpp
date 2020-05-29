题目描述
请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。

层次遍历然后再翻转的思路，复杂度太大。
正确思路是用两个栈，当前层是奇数层的时候，栈2先存左子节点再存右子节点；当前层是偶数层的时候，栈1先存右子节点再存左子节点
02/17:
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int> >res;
        if(!pRoot) return res;
        stack<TreeNode*>stk1,stk2;
        stk1.push(pRoot);
        int num=1;
        vector<int>array;
        while(!stk1.empty()||!stk2.empty()){
            if((num&0x1)==1){
                int n=stk1.size();
                for(int i=0;i<n;i++){
                    TreeNode*tmp=stk1.top();
                    stk1.pop();
                    array.push_back(tmp->val);
                    if(tmp->left) stk2.push(tmp->left);
                    if(tmp->right) stk2.push(tmp->right);
                }
            }
            else{
                int n=stk2.size();
                for(int i=0;i<n;i++){
                    TreeNode*tmp=stk2.top();
                    stk2.pop();
                    array.push_back(tmp->val);
                    if(tmp->right) stk1.push(tmp->right);
                    if(tmp->left) stk1.push(tmp->left);
                }
            }
            res.push_back(array);
            num++;
            vector<int>().swap(array);
        }
        return res;
    }
};


class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int> >res;
        if(!pRoot) return res;
        stack<TreeNode*>stk1,stk2;
        int num=0;
        stk1.push(pRoot);
        while(!stk1.empty()||!stk2.empty()){
            num++;
            vector<int>node1,node2;
            int n1=stk1.size(), n2=stk2.size();
            if(num%2==1){//奇数层
                for(int i=0;i<n1;i++){
                    TreeNode* tmp=stk1.top();
                    node1.push_back(tmp->val);
                    stk1.pop();
                    if(tmp->left) stk2.push(tmp->left);
                    if(tmp->right) stk2.push(tmp->right);
                }
                res.push_back(node1);
            }
            else{//偶数层
                for(int i=0;i<n2;i++){
                    TreeNode* tmp=stk2.top();
                    node2.push_back(tmp->val);
                    stk2.pop();
                    if(tmp->right) stk1.push(tmp->right);
                    if(tmp->left) stk1.push(tmp->left);
                }
                res.push_back(node2);
            }
        }
        return res;
    }
};
