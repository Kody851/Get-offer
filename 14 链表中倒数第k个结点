题目描述
输入一个链表，输出该链表中倒数第k个结点。
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(!pListHead||k==0) return NULL;
        ListNode*cur1=pListHead;
        ListNode*cur2=pListHead;
        for(int i=0;i<k;i++){
            if(!cur1) return NULL; //这说明k超过了链表的长度
            cur1=cur1->next;
        }
        while(cur1){
            cur1=cur1->next;
            cur2=cur2->next;
        }
        return cur2;
    }
};
//从概念角度，写成for(int i=0;i<k-1;i++)  while(cur1->next)是更好理解的
