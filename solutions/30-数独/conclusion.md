# [数独](https://www.nowcoder.com/practice/5e6c424b82224b85b64f28fd85761280)
[题解](./main_1.cpp)

回溯遍历过程  

## 数独
```cpp
class Solution {
public:
	bool isValid(vector<string> &board, int x, int y, char ch){
		for(int i=0;i<9;++i){
			if(board[x][i]==ch) return false;
			if(board[i][y]==ch) return false;
			if(board[(x/3)*3+i/3][(y/3)*3+i%3]==ch) return false;  // 用i/3和i%3得到一个格子里所有位置 
		}
		return true;
	} 
	bool dfs(vector<string> &board, int x, int y){
		if(x==9) return true;  // 出口，表示已经遍历完毕 
		if(y==9) return dfs(board,x+1,0);  // 开始下一行的搜索
		if(board[x][y]!='.') return dfs(board, x, y+1);
		for(char ch='1';ch<='9';++ch){
			if(!isValid(board,x,y,ch)) continue;
			board[x][y]=ch;
			if(dfs(board,x,y+1)) return true;
			board[x][y] = '.';  // 发现冲突，还原，继续遍历 
		}
		return false;
	}
    void solveSudoku(vector<string> &board) {
        dfs(board,0,0);
    }
};
```