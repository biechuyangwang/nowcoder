/*
* author： 李俊
* time：2020/12/14
*
* 二进制中1的个数
*/

/*
* 注意事项
*/

/*
* 位运算 掩码
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
     int  NumberOf1(int n) {
		int res=0;
		int mask=0x01;
		while(mask!=0){
			if(mask&n) res++;
			mask = mask << 1;
		}
		return res;
     }
};

int main(){
	int input = -1;

	Solution ss;
    auto res = ss.NumberOf1(input);
    
    cout << res;
	cout << endl;
	return 0;
}

/*
* output 1:
* 32
*/