/*
* author： 李俊
* time：2020/12/30
*
* 数据流的中位数 
*/

/*
* 注意事项
*/

/*
* dp[i][j] = dp[i-1][j-1]+1
* dp[i][j] = max(dp[i-1][j],dp[i][j-1]) others
* 注意空串返回"-1"
* dp开辟空间(m+1,n+1)，方便处理i-1的问题
*/

#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
}; 

class Solution {
public:
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
};


int main(){
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node1 = new TreeNode(1);
    node3->left = node5;
    node3->right = node1;
    TreeNode* input = node3;
	int o1=5,o2=1;
	Solution ss;
    auto res = ss.lowestCommonAncestor(intpu,o1,o2);
    cout << res;
	return 0;
}

/*
* output 1:
* 3
*/