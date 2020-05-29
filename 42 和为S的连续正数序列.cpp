和41题思路类似，双指针
class Solution {//双指针
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> >res;
        int i=1, j=2;
        while(i<(sum+1)/2){
            int SumiToj=(i+j)*(j-i+1)/2;//梯形公式
            vector<int>tmp;
            if(SumiToj==sum){
                for(int k=i;k<=j;k++){
                    tmp.push_back(k);
                }
                res.push_back(tmp);
                j++;//找完一组，找下一组。
            }
            else if(SumiToj<sum) j++;
            else i++;
        }
        return res;
    }
};
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> >res;
        if(sum<3) return res;
        int p1=1,p2=2;
        while(p1<p2 && p2<=(sum%2 ? sum/2+1 :sum/2)){//i<(sum+1)/2
            int s=(p1+p2)*(p2-p1+1)/2;
            if(s==sum){
                vector<int>tmp;
                for(int i=p1;i<=p2;i++)
                    tmp.push_back(i);
                res.push_back(tmp);
                p1++;//这里p1++和p2++都行
            }
            else if(s<sum) p2++;
            else p1++;
        }
        return res;
    }
};
