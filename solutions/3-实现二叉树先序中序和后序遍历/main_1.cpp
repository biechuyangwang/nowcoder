/*
* author： 李俊
* time：2020/12/10
*
* 二叉树的遍历递归版本
*/

/*
* 注意事项
*/

/*
* 输入：
* {1,2,3}
* 输出：
* [[1,2,3],[2,1,3],[2,3,1]]
*/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

class Solution {
public:
    /**
     * 
     * @param root TreeNode类 the root of binary tree
     * @return int整型vector<vector<>>
     */
    void recursionPreorderTraversal(TreeNode* root, vector<int>&ret){
        if(!root) return;
        ret.push_back(root->val);
        if(root->left) recursionPreorderTraversal(root->left, ret);
        if(root->right) recursionPreorderTraversal(root->right, ret);
    }
    
    void recursionMidorderTraversal(TreeNode* root, vector<int>&ret){
        if(!root) return;
        if(root->left) recursionMidorderTraversal(root->left, ret);
        ret.push_back(root->val);
        if(root->right) recursionMidorderTraversal(root->right, ret);
    }
    
    void recursionPostorderTraversal(TreeNode* root, vector<int>&ret){
        if(!root) return;
        if(root->left) recursionPostorderTraversal(root->left, ret);
        if(root->right) recursionPostorderTraversal(root->right, ret);
        ret.push_back(root->val);
    }
    vector<vector<int> > threeOrders(TreeNode* root) {
        // write code here
        vector<int>ret1,ret2,ret3;
        vector<vector<int>>ret;
        recursionPreorderTraversal(root, ret1);
        ret.push_back(ret1);
        recursionMidorderTraversal(root, ret2);
        ret.push_back(ret2);
        recursionPostorderTraversal(root, ret3);
        ret.push_back(ret3);
        return ret;
    }
};

int main(){
    // {1,2,3,#,#,4,#,#,5}
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(3);
    TreeNode *node4 = new TreeNode(4);
    TreeNode *node5 = new TreeNode(5);
    node1->left = node2;
    node1->right = node3;
    node3->left = node4;
    node4->right = node5;

    Solution s;
    vector<vector<int>>ret;
    ret = s.threeOrders(node1);
    for(auto list : ret){
        for(auto val : list){
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}