题目描述
输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。

class Solution {//有几个1只需要循环几次
public:
     int  NumberOf1(int n) {
         int count=0;
         while(n){
             count++;
             n=(n-1)&n;
//n-1是把最右边的1变成0，若它右边还有0，则所有0变成1，它前面的数不变；
//(n-1)&n实现了把n最右边的1变成0
         }
         return count;
     }
};

//一般想法，32位整数需要循环32次
class Solution {
public:
     int  NumberOf1(int n) {
         unsigned int flag=1;
         int count=0;
         while(flag){
             if(n&flag) count++;
             flag=flag<<1;
         }
         return count;
     }
};
