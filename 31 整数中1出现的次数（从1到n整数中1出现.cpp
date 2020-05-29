题目描述
求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次,
但是对于后面问题他就没辙了。ACMer希望你们帮帮他,并把问题更加普遍化,可以很快的求出任意非负整数区间中1出现的次数（从1 到 n 中1出现的次数）。
class Solution {//从1到n整数中1出现的次数：O(logn)算法 - yi_Afly的专栏 - CSDN博客 https://blog.csdn.net/yi_afly/article/details/52012593
public://《剑指offer》面试题32----从1到n整数中1出现的次数 - 一生不可自决 - 博客园 https://www.cnblogs.com/xuanxufeng/p/6854105.html
    int NumberOf1Between1AndN_Solution(int n)//求1~n整数中1出现的次数(《剑指offer》面试题43) - Excaliburer - 博客园 https://www.cnblogs.com/wangkundentisy/p/8946858.html
    {
        if(n<1) return 0;
        int count=0;
        int base=1, round=n;
        while(round){
            int weight=round%10;
            round/=10;
            count+=round*base;
            if(weight>1) count+=base;
            else if(weight==1) count+=n%base+1;
            base*=10;
             
        }
        return count;
    }
};
