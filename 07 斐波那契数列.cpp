题目描述
大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0）。n<=39
@知识点：斐波那契数列，f(0)=0,f(1)=1,f(n)=f(n-1)+f(n-2)
class Solution {
public:
    int Fibonacci(int n) {//循环，最优解
        int f1=0;
        int f2=1;
        if(n==0) return f1;
        if(n==1) return f2;
        int f=0;
        for(int i=2;i<=n;i++){
            f=f1+f2;
            f1=f2;
            f2=f;
        }
        return f;
    }
};
class Solution {//动态规划，需要辅助空间
public:
    int Fibonacci(int n) {
        vector<int>dp(n+1);//后续用到dp[x] 需要事前声明空间
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};
class Solution {//递归，复杂度大
public:
    int Fibonacci(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        return Fibonacci(n-1)+Fibonacci(n-2);
    }
};
