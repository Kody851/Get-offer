将一个字符串转换成一个整数(实现Integer.valueOf(string)的功能，但是string不符合数字要求时返回0)，要求不能使用字符串转换整数的库函数。 
数值为0或者字符串不是一个合法的数值则返回0。

知识点：最大整数：INT_MAX   0x7FFFFFFF；最小整数：INT_MIN  0x80000000

//0210
class Solution {
public:
    int StrToInt(string str) {
        int n=str.size(),num=0;
        if(n==0) return 0;
        for(int i=0;i<n;i++){
            if((i!=0&&str[i]<'0')||(i!=0&&str[i]>'9')) return 0;
            if(i==0&&str[i]<'0'&&str[i]>'9'&&str[i]!='+'&&str[i]!='-') return 0;
            if((i==0&&str[i]=='+')||(i==0&&str[i]=='-')) continue;
            num=num*10+(str[i]-'0');
        }
        if(num>INT_MAX) return 0;
        return str[0]=='-' ? -num : num;
    }
//190414
class Solution {
public:
    int StrToInt(string str) {
        int n=str.size();
        if(n==0) return 0;
        int res=0;
        for(int i=0;i<n;i++){
            if(i==0&&str[i]!='+'&&str[i]!='-'&&(str[i]<'0'||str[i] >'9')){
                return 0;
            }
            if(i==0&&(str[i]=='+'||str[i]=='-')) continue;
            if(i>0&&(str[i]<'0'||str[i] >'9')) return 0;
            res=res*10+(str[i]-'0');
        }
        if(res>INT_MAX) return 0;
        return str[0]=='-' ? -res : res;
    }
};
class Solution {
public:
    int StrToInt(string str) {
        int n=str.size();
        bool Status=true;//Status为false表示输入格式有误
        if(n==0) {//if(str=="") return 0;
            Status=false;
            return 0;
        }
        for(int i=0;i<n;i++){//判断非法输入
            if(str[i]>'9'||str[i]<'0'){
                if(i==0 && str[i]=='+'||str[i]=='-') continue;
                Status=false;
                return 0;
            }
        }
        int res=0;
        if(str[0]!='+'&&str[0]!='-'){
            for(int i=0;i<n;i++){
                //res+=(str[i]-'0')*myPow(10,n-1-i);
                res=res*10+(str[i]-'0');
            }
            if(res>0x7FFFFFFF){//正溢出
                Status=false;
                return 0;
            }
            return res;
        }
        else{
            if(n==1) Status=false;
            for(int i=1;i<n;i++){
                //res+=(str[i]-'0')*myPow(10,n-1-i);
                res=res*10+(str[i]-'0');
            }
            if(str[0]=='+'){
                if(res>0x7FFFFFFF){//正溢出 res>INT_MAX
                    Status=false;
                    return 0;
                }
                else return res;
            }
            else{
                if(res<(signed int)0x80000000){//负溢出
                    Status=false;
                    return 0;
                }
                else return -res;
            }
        }
    }
    /*int myPow(int x, int n){
        if(n==0) return 1;
        int res=1;
        for(int i=n;i!=0;i/=2){
            if(i%2!=0) res*=x;
            x*=x;
        }
        return n>0 ? res : 1/res;
    }*/
};
