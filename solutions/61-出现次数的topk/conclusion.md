# [出现次数的topk](https://www.nowcoder.com/practice/fd711bdfa0e840b381d7e1b82183b3ee)
[题解](./main_1.cpp)

## 思路
```cpp
/*
* topk -> 堆（优先队列）
* 涉及频次 -> unordered_map
* 优先队列对词频排序 -> priority_queue<pair<string,int> ,vector<pair<string,int> >, decltype(cmp)>pq
* 上述为底层是vector实现的，元素类型为pair的优先队列，方便对key-value模式下的value排序（map不行）
* 
* 注意auto是会执行的
* decltype只推断不执行
* 对于const的变量，decltype会保留
* 对于引用的变量，auto会推导出原有类型，decltype只会得到引用
*/
```

## dfs
```cpp
vector<vector<string> > topKstrings(vector<string>& strings, int k) {
    // write code here
    vector<vector<string> >ans;
    if(strings.size()==0 || strings.size()<k) return ans;
    unordered_map<string,int>ump;
    for(const auto& str : strings) ump[str]++;  // hash表统计数量
    auto cmp = [](const pair<string,int>&p1, const pair<string,int>&p2){
        if(p1.second!=p2.second)
            return p1.second > p2.second;
        return p1.first < p2.first;
    };  // lambda函数
    // 用堆得到top k
    priority_queue<pair<string,int>, vector<pair<string, int> >,decltype(cmp)> max_heap(cmp);
    auto p_iter = ump.begin();
    for(;p_iter!=ump.end();p_iter++){
        max_heap.emplace(*p_iter);
        if(max_heap.size()>k)
            max_heap.pop();
    }
    while(!max_heap.empty()){
        pair<string,int>p=max_heap.top();
        max_heap.pop();
        ans.insert(ans.begin(), vector<string>{p.first, to_string(p.second)});
    }
    return ans;
}
```