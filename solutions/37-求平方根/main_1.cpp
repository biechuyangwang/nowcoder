/*
* author： 李俊
* time：2020/12/16
*
* 求平方根
*/

/*
* 注意事项
*/

/*
* 二分查找
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int sqrt(int x) {
	    if(x < 0)
	        return -1;
	    long low = 0;
	    long high = x;
	    long mid = 0;
	    while(low <= high) {
	        mid = ((high + low) >> 1);
	        if((mid * mid <= x && (mid + 1) * (mid + 1) > x))
	            return mid;
	        else if(mid * mid > x)
	            high = mid - 1;
	        else
	            low = mid + 1;
	    }
	    return 0;
	}
};

int main(){
	int input = 101;
	
	Solution ss;
    auto res = ss.sqrt(input);
    cout << res;

	return 0;
}

/*
* output 1:
* 10
*/