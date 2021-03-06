题目描述
请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一个格子开始，
每一步可以在矩阵中向左，向右，向上，向下移动一个格子。如果一条路径经过了矩阵中的某一个格子，则之后不能再次进入这个格子。 
例如 a b c e s f c s a d e e 这样的3 X 4 矩阵中包含一条字符串"bcced"的路径，但是矩阵中不包含"abcb"路径，
因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。

class Solution {//回溯法
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        if(matrix==NULL||rows<1||cols<1||str==NULL) return false;
        bool *visited=new bool[rows*cols];
        memset(visited, 0, rows*cols);//初始化
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(hasPathCore(matrix,rows,cols,str,i,j,0,visited)) return true;
            }
        }
        delete[] visited;
        return false;
    }
    bool hasPathCore(char* matrix, int rows, int cols, char* str, int i, int j, int k,bool *visited){
        if(str[k]=='\0') return true;
        bool flag=false;
        if(i>=0&&i<rows&&j>=0&&j<cols&&matrix[i*cols+j]==str[k]&&visited[i*cols+j]==false){
            k++;
            visited[i*cols+j]=true;
            flag=hasPathCore(matrix,rows,cols,str,i-1,j,k,visited)||hasPathCore(matrix,rows,cols,str,i+1,j,k,visited)
                ||hasPathCore(matrix,rows,cols,str,i,j-1,k,visited)||hasPathCore(matrix,rows,cols,str,i,j+1,k,visited);
            if(flag==false){
                k--;
                visited[i*cols+j]=false;
            }
        }
        return flag;
    }
};
