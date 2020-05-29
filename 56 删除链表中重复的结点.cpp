题目描述 P122
在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5

知识点：
if(p1->next&&p1->next->val!=p1->val)
在要用到取值时，先保证它存在。

02/16:
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(!pHead) return pHead;
        ListNode*res=new ListNode(-1);//新建
        ListNode*cur=res;
        ListNode*p1=pHead, *p2=pHead->next;
        while(p2){
            if(p1->val!=p2->val){
                cur->next=p1;
                cur=cur->next;
                p1=p1->next;
                p2=p2->next;
            }
            else{
                while(p2&&p1->val==p2->val) p2=p2->next;
                p1=p2;//p2不能添加到cur，还需继续验重，p2赋给p1
                if(p2) p2=p2->next;
            }
        }
        cur->next=p1;//最终，p2为NULL，p1为最后一个单数
        return res->next;
    }
};

class Solution {//边界要考虑细致
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(!pHead||!pHead->next) return pHead;
        ListNode* p1=pHead;
        ListNode* p2=pHead;
        ListNode* pNew=new ListNode(-1);//需要前指针
        pNew->next=pHead;
        ListNode* pNewCur=pNew;
        while(p1&&p1->next&&p2->next){//由最后的p1=p2;知，p1！=NULL需要判断
            if(p1->next&&p1->next->val!=p1->val){
                p1=p1->next;
                pNewCur=pNewCur->next;
            }
            else if(p1->next&&p1->next->val==p1->val){//p1是第一个重复的数
                p2=p1->next;
                while(p2->next&&p2->next->val==p2->val) p2=p2->next;
                p2=p2->next;//p2是重复数的下一个
                //pNewCur->next=deleteDuplication(p2);//递归 使用了超过限制的内存
                pNewCur->next=p2;
                p1=p2;
            }
        }
        return pNew->next;
    }
};
