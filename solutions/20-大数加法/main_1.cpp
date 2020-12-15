/*
* author： 李俊
* time：2020/12/13
*
* 大数加法 
*/

/*
* 注意事项
*/

/*
* 归并的形式 
*/

#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e9+7;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 计算两个数之和
     * @param s string字符串 表示第一个整数
     * @param t string字符串 表示第二个整数
     * @return string字符串
     */
    string solve(string s, string t) {
        // write code here
        string res;
        int size_max = max(s.size(),t.size());
        int size_min = min(s.size(),t.size());
        int flag = 0;  //保存进位 
        int tmp = 0;  // 保存当前位的和 
        int i=s.size()-1,j=t.size()-1;
        while(i>=0 && j>=0){
        	tmp = s[i--]-'0' + t[j--]-'0' + flag;
        	flag = tmp/10;
        	tmp = tmp%10;
        	res.push_back(tmp+'0');
		}
		while(i>=0){
			tmp = s[i--]-'0' + flag;
			flag = tmp/10;
			tmp = tmp%10;
			res.push_back(tmp+'0');
		}
		while(j>=0){
			tmp = t[j--]-'0' + flag;
			flag = tmp/10;
			tmp = tmp%10;
			res.push_back(tmp+'0');
		}
		if(flag) res.push_back('1');
		reverse(res.begin(),res.end());
		return res;
    }
};


int main(){
	vector<string>input = {"1","99"};
	
	Solution ss;
    auto res = ss.solve(input[0],input[1]);

	cout << res;
	cout << endl;
	return 0;
}

/*
* output 1:
* 100
*/