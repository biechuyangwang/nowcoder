# [将升序数组转化为平衡二叉搜索树](https://www.nowcoder.com/practice/7e5b00f94b254da599a9472fe5ab283d)
[题解](./main_1.cpp)


## 题解
```cpp
class Solution {
public:
    /**
     * 
     * @param num int整型vector 
     * @return TreeNode类
     */
    TreeNode* pre_Order(vector<int>& num, int start, int end){  // 先序遍历建树
        if(start > end) return nullptr;  // 递归出口
        int mid = (start+end+1)/2;
        TreeNode *root = new TreeNode(num[mid]);
        root->left = pre_Order(num, start, mid-1);
        root->right = pre_Order(num, mid+1,end);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& num) {
        // write code here
        TreeNode *res = pre_Order(num, 0, num.size()-1);
        return res;
    }
};
```
