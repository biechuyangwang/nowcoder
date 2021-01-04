/*
* author： 李俊
* time：2020/12/30
*
* 数据流的中位数 
*/

/*
* 注意事项
*/

/*
* dp[i][j] = dp[i-1][j-1]+1 if s1[i]=s2[j]
* dp[i][j] = 0
* 注意空串返回"-1"
* dp开辟空间(m+1,n+1)，方便处理i-1的问题
*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    /**
     * longest common substring
     * @param str1 string字符串 the string
     * @param str2 string字符串 the string
     * @return string字符串
     */
    string LCS(string str1, string str2) {
        // write code here
        int m = str1.size();
        int n = str2.size();
        vector<vector<int> >dp(m+1, vector<int>(n+1,0));  // 由于需要和空串比较
        int maxlen = 0, end = 0;
        for(int i=1;i<=m;++i){
            for(int j=1;j<=n;++j){
                if(str1[i-1]==str2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=0;
                if(dp[i][j]>maxlen){
                    maxlen = dp[i][j];
                    end = j-1;
                }
            }
        }
        string r;
        if(maxlen==0) return "-1";
        else r = str2.substr(end-maxlen+1, maxlen);
        return r;
    }
};


int main(){
	string input1 = "1AB2345CD";
	string input2 = "12345EF";
	Solution ss;
    auto res = ss.LCS(input1,input2);
    cout << res;
	return 0;
}

/*
* output 1:
* "2345"
*/