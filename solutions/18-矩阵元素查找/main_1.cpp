/*
* author： 李俊
* time：2020/12/12
*
* 有序二维数组查找，从左下或者右上开始 
*/

/*
* 注意事项
*/

/*
* 
*/

#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e9+7;
class Solution {
public:
    vector<int> findElement(vector<vector<int> > mat, int n, int m, int x) {
        // write code here
        vector<int>res;
        if(n==0 || m==0) return res; 
        int i=0,j=m-1;
        while(i<n&&j>=0){
        	if(mat[i][j] == x){
        		res = {i,j};
        		return res;
			}else if(mat[i][j] > x) j--;
			else i++;
		}
		return res;
    }
};


int main(){
	vector<vector<int>>input = {{1,2,3},{4,5,6}};
	int n = 2,m=3,s=6; 
	
	Solution ss;
    auto res = ss.findElement(input,n,m,s);

    for(auto val : res)
		cout << val << " ";
	cout << endl;
	return 0;
}

/*
* output 1:
* 1 2
*/