/*
* author： 李俊
* time：2020/12/12
*
* 后续遍历 
*/

/*
* 注意事项
*/

/*
* 
*/

#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e9+7;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

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


int main(){
	vector<int>input = {0,1,2,3,4,-1,-1,5}; 
	TreeNode *node0 = new TreeNode(0);
	TreeNode *node1 = new TreeNode(1);
	TreeNode *node2 = new TreeNode(2);
	TreeNode *node3 = new TreeNode(3);
	TreeNode *node4 = new TreeNode(4);
	TreeNode *node5 = new TreeNode(5);
	node0->left = node1;
	node0->right = node2;
	node1->left = node3;
	node1->right = node4;
	node3->right = node5;
	TreeNode *root = node0;
	
	Solution s;
    auto res = s.IsBalanced_Solution(root);

	cout << res;
	cout << endl;
	return 0;
}

/*
* output 1:
* false
*/