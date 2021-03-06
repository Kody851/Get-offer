题目描述
给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。

class Solution {
public:
    double Power(double base, int exponent) {
        bool invalid=false;//无效输入
        if(base==0&&exponent<0) {
            invalid=true;
            return 0.0;
        }
        if(exponent==0) return 1.0;
        double res=Power(base, exponent/2);//当为负数时，使用exponent>>1会出现死循环;也可在外部写函数：unsigned int(-exponent);
        if((exponent&0x1)==0) res*=res;//注意&与==的优先级
        else if(exponent>0) res=res*res*base;
        else res=res*res/base;
        return res;
    }
};

class Solution {//8 ms
public:
    double Power(double base, int exponent) {
        bool invalid=false;
        if(base==0&&exponent<0) {
            invalid=true;
            return 0.0;
        }
        else if(base==0 && exponent>=0) return 0.0;
        if(exponent==0) return 1.0;
        double res=1.0;
        for(int i=exponent;i!=0;i/=2){
            if((i&0x1)==1) res*=base;//初始若是奇数，则多乘以1个base；最后必是奇数，把累乘好的base赋给res。
            base*=base;
        }
        return exponent>0?res:1/res; 
    }
};
