题目描述
地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，上，下四个方向移动一格，但是不能进入行坐标和列坐标的数位之和大于k的格子。
例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？
@知识点
bool *visited=new bool[rows*cols];//新建一个bool型数组
memset(visited,false,rows*cols);//初始化，相当于：
for(int i=0;i<rows*cols;i++)
  visited[i]=false;

class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        if(threshold<0||rows<1||cols<1) return 0;
        bool *visited=new bool[rows*cols];
        memset(visited,false,rows*cols);
        /*for(int i=0;i<rows*cols;i++)
            visited[i]=false;*/
        int count=movingCountCore(threshold,rows,cols,0,0,visited);
        delete[] visited;
        return count;
    }
    //递归实现
    int movingCountCore(int threshold, int rows, int cols, int row, int col, bool *visited){
        int count=0;
        if(capable(threshold,rows,cols,row,col,visited)){
            visited[row*cols+col]=true;
            count=1+movingCountCore(threshold,rows,cols,row-1,col,visited)+movingCountCore(threshold,rows,cols,row+1,col,visited)
                 +movingCountCore(threshold,rows,cols,row,col-1,visited)+movingCountCore(threshold,rows,cols,row,col+1,visited);
        }
        return count;
    }
    
    //判断某个方格是否能够进入
    bool capable(int threshold, int rows, int cols, int row, int col, bool *visited){
        int sum=SumOfIndex(row)+SumOfIndex(col);
        if(row>=0&&row<rows&&col>=0&&col<cols&&sum<=threshold&&visited[row*cols+col]==false)
            return true;
        else return false;
    }
    //每位相加的和
    int SumOfIndex(int x){
        int sum=0;
        while(x){
            sum+=x%10;
            x/=10;
        }
        return sum;
    }
};
更统一、简洁：
class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        if(threshold<0||rows<1||cols<1) return 0;
        bool *visited=new bool[rows*cols];
        memset(visited,false,rows*cols);
        /*for(int i=0;i<rows*cols;i++)
            visited[i]=false;*/
        int count=movingCountCore(threshold,rows,cols,0,0,visited);
        delete[] visited;
        return count;
    }
    //递归实现
    int movingCountCore(int threshold, int rows, int cols, int row, int col, bool *visited){
        int count=0;
        if(row>=0&&row<rows&&col>=0&&col<cols&&!visited[row*cols+col]&&capable(threshold,row,col)){
            visited[row*cols+col]=true;
            count=1+movingCountCore(threshold,rows,cols,row-1,col,visited)+movingCountCore(threshold,rows,cols,row+1,col,visited)
                 +movingCountCore(threshold,rows,cols,row,col-1,visited)+movingCountCore(threshold,rows,cols,row,col+1,visited);
        }
        return count;
    }    
    //判断某个方格是否能够进入
    bool capable(int threshold, int row, int col){
        int sum=SumOfIndex(row)+SumOfIndex(col);
        if(sum<=threshold)
            return true;
        else return false;
    }
    //每位相加的和
    int SumOfIndex(int x){
        int sum=0;
        while(x){
            sum+=x%10;
            x/=10;
        }
        return sum;
    }
};
