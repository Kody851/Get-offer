题目描述
在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置, 如果没有则返回 -1（需要区分大小写）.
1、哈希表
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        int n=str.size();
        if(n==0) return -1;
        unordered_map<char,int>mp;//map不要指定大小，map(n,0)是错的！可以仅初始化mp(0)
        for(int i=0;i<n;i++){
            mp[str[i]]++;
        }
        for(int i=0;i<n;i++){
            if(mp[str[i]]==1) return i;
        }
        return -1;
    }
};
2、用数组实现哈希表
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        int n=str.size();
        if(n==0) return -1;
        unsigned int hash[256]={0};//字符(char)是一个长度为8的数据类型，共有256种可能。辅助数组大小1k为常数，可以认为空间复杂度为O(1)
        /*for(int i=0;i<256;i++){
            hash[i]=0;
        }*/
        for(int i=0;i<n;i++){
            hash[str[i]]++;//str[i]自动转为ASCII码数字
        }
        for(int i=0;i<n;i++){
            if(hash[str[i]]==1) return i;
        }
        return -1;
    }
};
