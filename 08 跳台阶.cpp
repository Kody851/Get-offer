题目描述
一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。

class Solution {
public:
    int jumpFloor(int number) {
        if(number<=0) return 0;
        if(number==1) return 1;
        if(number==2) return 2;
        int f1=1,f2=2,fn=0;
        for(int i=3;i<=number;i++){
            fn=f1+f2;
            f1=f2;
            f2=fn;
        }
        return fn;
    }
};

class Solution {
public:
    int jumpFloor(int number) {
        vector<int>dp(number+1);
        dp[1]=1; dp[2]=2;
        for(int i=3;i<=number;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[number];
    }
};
