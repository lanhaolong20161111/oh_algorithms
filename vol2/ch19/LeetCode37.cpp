class Solution {
public:
    void solveSudoku(vector<vector<char>> &board) {
        dfs(board,0,0);
    }
    bool dfs(vector<vector<char>> &board, int i,int j) {		//回溯算法
        if (j==9) {
            i=i+1;          //一行完后进入下一行
            j=0;
        }
        if (i==9) return true;     //到达一个叶子结点
        if (board[i][j]!='.')               //跳过非空单元
            return dfs(board,i,j+1);
        for (char ch='1';ch<='9';ch++) {        //空单元尝试'1'-'9'
            if (isValid(board,i,j,ch)) {
                board[i][j]=ch;
                if(dfs(board,i,j+1))
                    return true; 			//若找到一个解返回true
                board[i][j]='.';            //回溯
            }
        }
        return false;
    }
    bool isValid(vector<vector<char>> &board,int i,int j,char val) {
        int starti=(i/3)*3;         //求(i,j)所在九宫格的左上角位置
        int startj=(j/3)*3;
        for (int k=0;k<9;k++) {
            if(board[i][k]==val)      //同一行重复返回false
                return false;
            if(board[k][j]==val)      //同一列重复返回false
                return false;
            if(board[starti+k/3][startj+k%3]==val)
                return false;           //当前九格宫中重复返回false
        }
        return true;
    }
};

