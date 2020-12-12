# [平衡二叉树](https://www.nowcoder.com/practice/8b3b95850edb4115918ecebdf1b4d222)
[题解](./main_1.cpp)

## 后续遍历来计算树高
```cpp
class Solution {
public:
    int tree_hight(TreeNode* root){  // 后序遍历
        if(!root) return 0;
        // 左子树操作
        int lval = tree_hight(root->left);
        if(lval == -1) return -1;
        // 右子树操作
        int rval = tree_hight(root->right);
        if(rval == -1) return -1;
        // 根节点操作
        if(abs(lval-rval) > 1) return -1;
        return max(lval, rval) + 1;
    }
    bool IsBalanced_Solution(TreeNode* pRoot) {
        return (tree_hight(pRoot) != -1);
    }
};
```