题目描述
输入一个链表，反转链表后，输出新链表的表头。
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(!pHead) return NULL;
        ListNode*cur=pHead;
        ListNode*pre=NULL;//设置前指针
        ListNode*aft=NULL;//aft其实功能只是tmp，临时存cur->next
        while(cur){
            aft=cur->next;
            cur->next=pre;
            pre=cur;
            cur=aft;
        }
        return pre;
    }
};

class Solution {//递归
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(!pHead||!pHead->next) return pHead;
        
        ListNode*res=ReverseList(pHead->next);
        pHead->next->next=pHead;
        pHead->next=NULL;
        return res;
        
        //可以这么理解：
        /*ListNode*cur=res;
        while(cur->next){//找到ReverseList(pHead->next)的末尾节点，其实就是输入的pHead->next
            cur=cur->next;
        }
        cur->next=pHead;
        pHead->next=NULL;
        return res;*/
    }
};
