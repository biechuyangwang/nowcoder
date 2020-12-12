# [两数之和](https://www.nowcoder.com/practice/20ef0972485e41019e39543e8e895b7f)
[题解](./main_1.cpp)

## 1 利用hash_map
利用hash_map来
```cpp
vector<int> twoSum(vector<int>& numbers, int target) {
    // write code here
    vector<int>res;
    unordered_map<int,int>ump;
    for(int i=0;i<numbers.size();++i){
        if(ump.count(target-numbers[i])==1){
            cout << target-numbers[i] << endl;
            cout << ump.at(target-numbers[i]) << endl; 
            res.push_back(1+ump.at(target-numbers[i]));
            res.push_back(1+i);
            return res; 
        } 
        ump[numbers[i]] = i;
    }
    return res;
}
```