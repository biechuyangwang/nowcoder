/*
* author： 李俊
* time：2020/12/17
*
* 在转动的有序数组中寻找目标值
*/

/*
* a[m]>=a[l]
*   a[l]<=t<a[m] -> r = m-1
*   other -> l = m+1
* a[m]<=a[r]
*   a[m]<=t<a[r] -> l= m+1
*   other -> r=m-1
* 可以通过一些方法去合并使代码简洁，但是逻辑就不简洁了，没有必要。
*/

/*
* 二分查找
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 
     * @param A int整型一维数组 
     * @param n int A数组长度
     * @param target int整型 
     * @return int整型
     */
    int search(int* A, int n, int target) {
        // write code here
        int l = 0,r = n-1;
        while(l<=r){
        	int m = l+r >> 1;
        	cout << A[l] << " " << A[m] << " " << A[r] << endl; 
        	if(A[m]==target) return m;
        	if(A[m]>=A[l]){
        		if(A[l]<=target && target < A[m]) r=m-1;
        		else l=m+1;
			}else if(A[m]<=A[r]){
				if(A[m]<=target && target<A[r]) l=m+1;
				else r=m-1;
			}
		}
		return -1;
    }
};

int main(){
	int input[] = {4,5,6,7,0,1,2};
	
	int n=7;
	int val=6;
	Solution ss;
    auto res = ss.search(input,n,val);
    cout << res;

	return 0;
}

/*
* output 1:
* 2
*/