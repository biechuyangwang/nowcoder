#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 
     * @param num int整型vector 
     * @return TreeNode类
     */
    void chessboard(vector<vector<int>> &board, int tr, int tc, int dr, int dc, int size){
    	if(size==1)
    		return;
    	int s = size/2;
    	int num = this->tile++;
        // 先填中间，再填四周，向外扩散
    	if(dr < tr + s && dc < tc + s){  // 左上 
    		this->chessboard(board,tr, tc, dr, dc, s);
		}else{
			board[tr + s - 1][tc + s - 1] = num;
			this->chessboard(board,tr,tc,tr+s-1,tc+s-1, s);
		}
		if(dr < tr + s && dc >= tc + s){  // 右上 
    		this->chessboard(board,tr, tc+s, dr, dc, s);
		}else{
			board[tr + s - 1][tc + s] = num;
			this->chessboard(board,tr,tc+s,tr+s-1,tc+s, s);
		}
		if(dr >= tr + s && dc < tc + s){  // 左下 
    		this->chessboard(board,tr+s, tc, dr, dc, s);
		}else{
			board[tr + s][tc + s - 1] = num;
			this->chessboard(board,tr+s,tc,tr+s,tc+s-1, s);
		}
		if(dr >= tr + s && dc >= tc + s){  // 右下 
    		this->chessboard(board,tr+s, tc+s, dr, dc, s);
		}else{
			board[tr + s][tc + s] = num;
			this->chessboard(board,tr+s,tc+s,tr+s,tc+s,s);
		}
	}
private:
	int tile=1;  // 开始的序号
};

int main(){
    int k=2;
	int dr = 1;
	int dc = 1;
	int size = pow(2,k);
	Solution ss;
	vector<vector<int>> board(size,vector<int>(size,0));
	ss.chessboard(board,0,0,dr,dc,size);
	board[dr][dc] = -1;

	for(auto v : board){
		for(auto val : v) cout << val << " ";
		cout << endl;
	}
    return 0;
}