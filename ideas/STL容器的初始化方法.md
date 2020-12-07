# STL容器的初始化方法
## 1 vector
### 1.1 `vector<int>v;`
默认初始化，此时vector为空，size为0，capacity也是0，意味着没有分配内存空间。

适用：

元素个数未知，需要在程序中**动态添加**的情况。

### 1.2 `vector<int>v1(v2)或者vector<int>v1 = v2;`
拷贝初始化，两者必须类型相同，v2将与v1具有相同的容量和元素。

### 1.3 `vector<int>v = {1,2.0,3};`
列表元素的拷贝，相同类型直接拷贝，不同类型会进行类型转换，参考类型转换。

### 1.4 `vector<int> v1(v2.begin()+2, v2.end()-1);`
迭代器指定范围内的拷贝。

适用：

**获取一个序列的子序列。**

### `vector<int>v(5);`
默认值初始化，v将包含5个默认值的元素。

### `vector<int>(5,2);`
指定值初始化

## 2 map
### 2.1 `map<string, int>m;`
默认初始化，此时map为空。

适用：

元素个数未知，需要在程序中**动态添加**的情况。
```cpp
m["lijun"] = 1;
m.insert({"xingqiliudegushi, 2"});
m.insert(make_pair(string("biechuyangwang"), 3));
m.insert(pair<string, int>(string("gushi"), 4));
```

### 2.2 多类型嵌套map
```cpp
map<int, map<string, vector<double>>>  testmap;
testmap[3]["three"].push_back(3.75);
```