/*
* author： 李俊
* time：2020/12/11
*
* 进制转换
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
    /**
     * 进制转换
     * @param M int整型 给定整数
     * @param N int整型 转换到的进制
     * @return string字符串
     */
	string solve(int M, int N) {
	    // write code here
	    string t = "0123456789ABCDEF"; 
	    string ret = "";
	    bool flag = true;
	    if((M<0)^(N<0)){  // 用来判断符号位 
	        flag = false;
	    }
	    M = abs(M);
	    N = abs(N);
	    while(M){
	        ret.push_back(t[M%N]);
	        M = M/N;
	    }
	    if(!flag) ret.push_back('-');
	    reverse(ret.begin(),ret.end());
	    return ret;
	}
};

int main(){
//	vector<int>input = {23,12};
//	vector<int>input = {-4,3};
	vector<int>input = {-100000000,16};
	string res;
	
	Solution s;
    res = s.solve(input[0],input[1]);
	cout << res << endl;
	return 0;
}

/*
* output 1:
* "1B"
* output 2:
* "-11"
* output 3:
* "-5F5E100"
*/