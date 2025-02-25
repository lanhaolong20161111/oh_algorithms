class Solution {
public:
    void solveSudoku(vector<vector<char>> &board) {
        dfs(board,0,0);
    }
    bool dfs(vector<vector<char>> &board, int i,int j) {		//�����㷨
        if (j==9) {
            i=i+1;          //һ����������һ��
            j=0;
        }
        if (i==9) return true;     //����һ��Ҷ�ӽ��
        if (board[i][j]!='.')               //�����ǿյ�Ԫ
            return dfs(board,i,j+1);
        for (char ch='1';ch<='9';ch++) {        //�յ�Ԫ����'1'-'9'
            if (isValid(board,i,j,ch)) {
                board[i][j]=ch;
                if(dfs(board,i,j+1))
                    return true; 			//���ҵ�һ���ⷵ��true
                board[i][j]='.';            //����
            }
        }
        return false;
    }
    bool isValid(vector<vector<char>> &board,int i,int j,char val) {
        int starti=(i/3)*3;         //��(i,j)���ھŹ�������Ͻ�λ��
        int startj=(j/3)*3;
        for (int k=0;k<9;k++) {
            if(board[i][k]==val)      //ͬһ���ظ�����false
                return false;
            if(board[k][j]==val)      //ͬһ���ظ�����false
                return false;
            if(board[starti+k/3][startj+k%3]==val)
                return false;           //��ǰ�Ÿ����ظ�����false
        }
        return true;
    }
};

