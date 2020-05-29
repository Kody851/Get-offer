题目描述 P148
输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(!pRoot1||!pRoot2) return false;
        bool res=false;
        if(pRoot1&&pRoot2){//保证pRoot1->val,pRoot2->val,pRoot1->left,pRoot1->right是存在的
            if(pRoot1->val==pRoot2->val) res= HasSubtreeCore(pRoot1,pRoot2);
            if(!res) res=HasSubtree(pRoot1->left,pRoot2);//若res==false,可能是pRoot1->val==pRoot2->val，但下面的结构不同，需要继续遍历节点，
                                                         //找到下一个与pRoot2->val相同的
            if(!res) res=HasSubtree(pRoot1->right,pRoot2);
        }
        return res;
    }
    bool HasSubtreeCore(TreeNode* pRoot1, TreeNode* pRoot2){
        if(!pRoot2) return true;//pRoot2找到了头，pRoot1不用管
        if(!pRoot1&&pRoot2) return false;//pRoot1找到了头，pRoot2没找到头
        if(pRoot1&&pRoot2&&pRoot1->val!=pRoot2->val) return false;
        return HasSubtreeCore(pRoot1->left,pRoot2->left)&&HasSubtreeCore(pRoot1->right,pRoot2->right);
        
    }
};
更简洁：
class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(!pRoot1||!pRoot2) return false;
        bool flag=helper(pRoot1,pRoot2);
        if(!flag){
            flag=HasSubtree(pRoot1->left,pRoot2);
        }
        if(!flag){
            flag=HasSubtree(pRoot1->right,pRoot2);
        }
        return flag;
    }
    bool helper(TreeNode* pRoot1, TreeNode* pRoot2){
        if(!pRoot2) return true;
        if(!pRoot1) return false;
        if(pRoot1&&pRoot2&&pRoot1->val!=pRoot2->val) return false;
        else return helper(pRoot1->left,pRoot2->left)&&helper(pRoot1->right,pRoot2->right);
    }
};
