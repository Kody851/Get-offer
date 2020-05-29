题目描述
给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。

class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        int n=A.size();
        vector<int>B(n);
        if(A.empty()) return B;
        B[0]=1;
        for(int i=1;i<n;i++){//下三角
            B[i]=B[i-1]*A[i-1];
        }
        int tmp=1;
        for(int i=n-2;i>=0;i--){//上三角
            tmp*=A[i+1];//先用tmp过渡
            B[i]*=tmp;
        }
        return B;
    }
};
![image](https://github.com/Kody851/Get-offer/blob/master/images/51.jpg)

上三角与下三角分开：
class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        int n=A.size();
        if(n==0) return A;
        vector<int>B(n);
        vector<int>B1(n);
        vector<int>B2(n);
        B1[0]=1;
        for(int i=1;i<n;i++){
            B1[i]=B1[i-1]*A[i-1];
        }
        B2[n-1]=1;
        for(int i=n-2;i>=0;i--){
            B2[i]=B2[i+1]*A[i+1];
        }
        for(int i=0;i<n;i++){
            B[i]=B1[i]*B2[i];
        }
        return B;
    }
};
直接相乘（复杂度高）
class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        int n=A.size();
        if(n==0) return A;
        vector<int>B(n);
        for(int i=0;i<n;i++) B[i]=1;
        int i=0;
        while(i<n){
            for(int j=0;j<i;j++)
                B[i]*=A[j];
            for(int j=i+1;j<n;j++)
                B[i]*=A[j];
            i++;
        }
        
        return B;
    }
};
