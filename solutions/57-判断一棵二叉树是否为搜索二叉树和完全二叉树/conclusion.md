# [判断一棵二叉树是否为搜索二叉树和完全二叉树](https://www.nowcoder.com/practice/f31fc6d3caf24e7f8b4deb5cd9b5fa97)
[题解](./main_1.cpp)

## 思路
```cpp
/*
* 判断搜索树
*   中序遍历，需要一个节点保存上一个节点，用来比较大小。
*   去掉不是二叉树的条件，剩下的就是搜索二叉树
* 判断完全二叉树
*   可以使用层次遍历
*   使用判断左右是否是完全二叉树来判断，但是允许一次不平衡（用一个全局变量来标志）
*/
```

## 题解
```cpp
class Solution {
public:
    /**
     * 
     * @param root TreeNode类 the root
     * @return bool布尔型vector
     */
    int last = INT_MIN;
    bool flag = false;
    bool isBST(TreeNode* root){
        if(!root) return true;
        if(!isBST(root->left)) return false;  // 保存了左支最右节点
        if(last > root->val) return false;
        last = root->val;  // 为了和右支最左节点比较
        return isBST(root->right);
    }
    bool isComp(TreeNode* root){
        if(!root) return true;
        if(!root->left && !root->right) return true;
        if(root->left && !root->right){
            if(flag) return false;  // 已经不平衡了，只能接受一次不平衡
            flag = true;
        }
        if(!root->left && root->right) return false;
        return isComp(root->left) && isComp(root->right);
    }
    vector<bool> judgeIt(TreeNode* root) {
        // write code here
        bool flag1 = isBST(root);
        bool flag2 = isComp(root);
        vector<bool>res;
        res.push_back(flag1);
        res.push_back(flag2);
        return res;
    }
};
```
