题目描述P65
给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
知识点：尽量用上else，以防止情况复杂时有遗漏。  if中比较值前先判断是否存在。

/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        //若右子树存在：返回右子树的最左子树
        if(pNode->right){
            TreeLinkNode*tmp=pNode->right;
            while(tmp->left) tmp=tmp->left;
            return tmp;
        }
        else{
            //若右子树不存在，且它是其父节点的右子节点:沿着指向父节点的指针一直向上遍历，直到找到一个节点，它是其父节点的左子节点，返回其父节点
            if(pNode->next&&pNode==pNode->next->right){//前提是父节点存在啊
                while(pNode->next && pNode!=pNode->next->left) pNode=pNode->next;
                return pNode->next;//找到了那种节点；或者遍历到根节点了（输出NULL）
            }
            //若右子树不存在，且它是其父节点的左子节点（或者它没有父节点）:返回父节点； 
            else return pNode->next;
        }
    }
};
