# [二叉树节点的公共祖先](https://www.nowcoder.com/practice/e0cc33a83afe4530bcec46eba3325116)
[题解](./main_1.cpp)

## 思路
```cpp
/*
* 值在的节点左边和右边，则返回该节点
* 都在左边，返回左节点
* 都在右边，返回又节点
*/
```

## 题解
```cpp
int lowestCommonAncestor(TreeNode* root, int o1, int o2) {
    // write code here
    if(!root) return -1;
    if(o1==root->val || o2==root->val) return root->val;
    int left = lowestCommonAncestor(root->left, o1, o2);  // 两个节点在单支，不会上升节点
    int right = lowestCommonAncestor(root->right, o1, o2);
    if(left==-1) return right;  // 都在右支
    if(right==-1) return left;  // 都在左支
    return root->val;  // 在两边
}
```
