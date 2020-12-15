/*
* author： 李俊
* time：2020/12/14
*
* 超过一半的数字
*/

/*
* 注意事项
*/

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers){
    	int pre;
    	if(numbers.size()==0) return 0;
    	int cnt=0;
    	for(auto val : numbers){
    		if(cnt==0) pre = val;
			if(pre==val) cnt++;
			else cnt--;
		}
		cnt=0;
		for(auto val : numbers){
    		if(pre==val) cnt++;
		}
		if(cnt >numbers.size()/2) return pre;
		else return 0;
    }
};

int main(){
	vector<int>input = {1,2,3,2,2,2,5,4,2};
	
	Solution ss;
    auto res = ss.MoreThanHalfNum_Solution(input);
    cout << res;

	return 0;
}

/*
* output 1:
* 2
*/