/*
* author： 李俊
* time：2020/12/14
*
* 数独
*/

/*
* 注意事项
*/

#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e9+7;

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

int main(){
	vector<string > input={
	"53..7....",
	"6..195...",
	".98....6.",
	"8...6...3",
	"4..8.3..1",
	"7...2...6",
	".6....28.",
	"...419..5",
	"....8..79"
	};
	
	for(auto v : input){
		for(auto val : v) cout << val << " ";
		cout << endl;
	}
	cout << endl << "结果：" << endl;
	Solution ss;
	ss.solveSudoku(input);

	auto res = input;
	for(auto v : res){
		for(auto val : v) cout << val << " ";
		cout << endl;
	}

	cout << endl;
	return 0;
}

/*
* output 1:
* 
*/