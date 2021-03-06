题目：最长不含重复字符的子字符串 P236
请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。假设字符串中只包含从’a’到’z’的字符。
例如，在字符串中”arabcacfr”，最长非重复子字符串为”acfr”，长度为4。
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        if(n==0) return 0;
        vector<int>dp(n);
        dp[0]=1;
        vector<int>position(26,-1);//储存字母对应下标
        position[s[0]-'a']=0;
        int maxlen=0;
        for(int i=1;i<n;i++){
            if(position[s[i]-'a']==-1||i-position[s[i]-'a']>dp[i-1]){//该字符在前面没出现，或该字符位置与前面出现的位置（最近的）之差大于dp[i-1]
                dp[i]=dp[i-1]+1;
            }
            else{
                dp[i]=i-position[s[i]-'a'];//该字符位置与前面出现的位置（最近的）之差小于等于dp[i-1]
            }
            position[s[i]-'a']=i;
        }
        for(int i=0;i<n;i++){
            if(dp[i]>maxlen) maxlen=dp[i];
        }
        return maxlen;
    }
};
若要求出字符串：
class Solution {
public:
    vector<string> lengthOfLongestSubstring(string s) {
        vector<string>res;
        int n=s.size();
        if(n==0) return res;
        vector<int>dp(n);
        dp[0]=1;
        vector<int>position(26,-1);//储存字母对应下标
        position[s[0]-'a']=0;
        int maxlen=0;
        for(int i=1;i<n;i++){
            if(position[s[i]-'a']==-1||i-position[s[i]-'a']>dp[i-1]){//该字符在前面没出现，或该字符位置与前面出现的位置（最近的）之差大于dp[i-1]
                dp[i]=dp[i-1]+1;
            }
            else{
                dp[i]=i-position[s[i]-'a'];//该字符位置与前面出现的位置（最近的）之差小于等于dp[i-1]
            }
            position[s[i]-'a']=i;
        }
        for(int i=0;i<n;i++){
            if(dp[i]>maxlen) maxlen=dp[i];
        }
        for(int i=0;i<n;i++){
            if(dp[i]==maxlen){
                res.push_back(s.substr(i-maxlen+1,maxlen));//每个最大不重复子串
        }
        return res;
    }
};
