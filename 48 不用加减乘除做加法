题目描述
写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。

class Solution {
public:
    int Add(int num1, int num2)
    {
        int sum, carry;
        while(num2!=0){//循环至无进位
            sum=num1^num2;//异或表示相加但不进位
            carry=(num1&num2)<<1;//与和左移，得到进位
            num1=sum;
            num2=carry;
        }
        return num1;
    }
};
