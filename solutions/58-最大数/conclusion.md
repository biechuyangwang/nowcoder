# [最大数](https://www.nowcoder.com/practice/fc897457408f4bbe9d3f87588f497729)
[题解](./main_1.cpp)

## 思路
```cpp
/*
* 想对字符串按照首字母排序，就使用a+b > b+a的方式排序
*/
```

## 题解
```cpp
class Solution {
public:
    /**
     * 最大数
     * @param nums int整型vector 
     * @return string字符串
     */
    static bool cmp(string a, string b){
        return a+b > b+a;  // 利用字典排序（长度一致）
    }
    string solve(vector<int>& nums) {
        // write code here
        vector<string>v;
        for(int i=0;i<nums.size();++i){
            v.push_back(to_string(nums[i]));
        }
        sort(v.begin(),v.end(),cmp);
        if(v[0]=="0") return "0";
        string res="";
        for(int i=0;i<v.size();++i) res += v[i];
        return res;
    }
};
```
