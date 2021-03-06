题目描述
输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。

class Solution {
public://递归
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(!pHead1) return pHead2;
        if(!pHead2) return pHead1;
        if(pHead1->val <= pHead2->val){
            pHead1->next=Merge(pHead1->next,pHead2);
            return pHead1;
        }
        else{
            pHead2->next=Merge(pHead1,pHead2->next);
            return pHead2;
        }
    }
};

（x）
class Solution {
public://递归
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(!pHead1) return pHead2;
        if(!pHead2) return pHead1;
        ListNode*res=NULL;//新建
        if(pHead1->val<=pHead2->val){
            res=pHead1;
            res->next=Merge(pHead1->next,pHead2);
        }
        else{
            res=pHead2;
            res->next=Merge(pHead1,pHead2->next);
        }
        return res;
    }
};

(x)
class Solution {
public://递归，此方法会改变原链表
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(!pHead1) return pHead2;
        if(!pHead2) return pHead1;
        if(pHead1->val<=pHead2->val){
            pHead2->next=Merge(pHead1->next,pHead2->next);//Merge(pHead1->next,pHead2->next)表示已经合并好的链表，后面只需确定前两个节点！
            pHead1->next=pHead2;
            return pHead1;
        }
        else{
            pHead1->next=Merge(pHead1->next,pHead2->next);
            pHead2->next=pHead1;
            return pHead2;
        }
    }
};

class Solution {
public://迭代
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(!pHead1) return pHead2;
        if(!pHead2) return pHead1;
        ListNode *cur1=pHead1, *cur2=pHead2;
        ListNode *res=new ListNode(-1);
        ListNode *tmp=res;
        while(cur1&&cur2){
            if(cur1->val<=cur2->val) {
                tmp->next=cur1;
                cur1=cur1->next;
                tmp=tmp->next;
            }
            else{
                tmp->next=cur2;
                cur2=cur2->next;
                tmp=tmp->next;
            }
        }
        while(cur1&&!cur2){
            tmp->next=cur1;
            cur1=cur1->next;
            tmp=tmp->next;
        }
        while(!cur1&&cur2){
            tmp->next=cur2;
            cur2=cur2->next;
            tmp=tmp->next;
        }
        return res->next;
    }
};
