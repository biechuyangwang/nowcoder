# [找到字符串的最长无重复字符子串](https://www.nowcoder.com/practice/b56799ebfd684fb394bd315e89324fb4)

[双指针问题]()

[字符串子串问题汇总]()
## 1 滑动窗口
滑动窗口可以使用unordered_map(hash_map)去模拟，详情见[示例1](./main_1.cpp)

滑动窗口最大的问题是控制窗口的left和right，显然窗口每次只能向前滑一个位置，但是窗口的收缩却可以多样化操作。
