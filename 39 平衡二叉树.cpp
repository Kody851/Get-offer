知识点：
它是一 棵空树或它的左右两个子树的高度差的绝对值不超过1，并且左右两个子树都是一棵平衡二叉树。平衡二叉树的常用实现方法有红黑树、AVL、替罪羊树、Treap、伸展树等。 最小二叉平衡树的节点总数的公式如下 F(n)=F(n-1)+F(n-2)+1 这个类似于一个递归的数列，可以参考Fibonacci(斐波那契)数列，1是根节点，F(n-1)是左子树的节点数量，F(n-2)是右子树的节点数量
对每个节点计算左右子树的深度，每个节点会重复遍历多次，因此下面的直接法效率低：
class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(!pRoot) return true;
        if(depth(pRoot->left)-depth(pRoot->right)>1||depth(pRoot->left)-depth(pRoot->right)<-1)
            return false;
        else return IsBalanced_Solution(pRoot->left)&&IsBalanced_Solution(pRoot->right);
    }
    int depth(TreeNode* pRoot){
        if(!pRoot) return 0;
        return max(depth(pRoot->left),depth(pRoot->right))+1;
    }
};
每个节点遍历一次，后序遍历，遍历到一个节点，其左右子树已经遍历  依次自底向上判断，每个节点只需要遍历一次
class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        int dep=0;
        return IsBalanced(pRoot, dep);
    }
    bool IsBalanced(TreeNode* pRoot, int &dep){
        if(!pRoot){
            dep=0;
            return true;
        }
        int left=0,right=0;
        if(IsBalanced(pRoot->left,left)&&IsBalanced(pRoot->right,right)){//实际调用，此处left前不能加&
            if(abs(left-right)>1) return false;//根节点处进行一些判断和赋值操作
            else{
                dep=left>right ? left+1 : right+1;
                return true;
            }
        }
        return false;
    }
};
//更规范:
class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        int dep=0;
        return IsBalanced(pRoot, dep);
    }
    bool IsBalanced(TreeNode* pRoot, int &dep){//在递归中需要更改的参数一定要&引用
        if(!pRoot){
            dep=0;
            return true;
        }
        int left=0, right=0;
        if(IsBalanced(pRoot->left,left)&&IsBalanced(pRoot->right,right)){
            int dif=left-right;
            if(dif<=1&&dif>=-1){
                dep=dif>0 ? left+1 : right+1;
                return true;
            }
        }
        return false;
    }
};
