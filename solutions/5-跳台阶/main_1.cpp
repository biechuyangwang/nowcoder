/*
* author： 李俊
* time：2020/12/10
*
* 动态规划
*/

/*
* 注意事项
*/

/*
* 动归方程
* f(0) = 1
* f(1) = 1
* f(x) = f(x-1)+f(x-2);
*/

#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e9+7;
class Solution {
public:
    int jumpFloor(int number) {
        int n_2=1,n_1=1,result=0;
        if(number==0||number==1) return 1;
        else{
            for(int i=2;i<=number;i++){
                result = n_2+n_1;
                n_2 = n_1;
                n_1 = result;
            }
        }
        return result;
    }
    int recursionjumpFloor(int number) {
        if(number==0 || number==1) return 1;
        return jumpFloor(number-2) + jumpFloor(number-1);
    }
};

int main(){
    int input = 4;
    int res;

    Solution s;
    res = s.jumpFloor(input);
    // res = s.recursionjumpFloor(input);
    cout << res << endl;
    return 0;
}