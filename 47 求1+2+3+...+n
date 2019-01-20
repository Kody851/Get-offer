class Solution {//&&的短路特性代替递归中的条件判断
public:
    int Sum_Solution(int n) {
        int ans = n;
        ans && (ans += Sum_Solution(n - 1));//递归到ans=0时，短路特性只计算左边，此时右边是ans+=Sum_Solution(-1)
        return ans;
    }
};
