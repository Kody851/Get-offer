题目描述
我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？

class Solution {//还是斐波那契数列，一般实用中，往往是f(1)=1,f(2)=2,f(n)=f(n-1)+f(n-2)
public:
    int rectCover(int number) {
        if(number<=0) return 0;
        vector<int>dp(number+1);
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=number;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[number];
    }
};
