/*
* author： 李俊
* time：2020/12/10
*
* 二叉树的遍历非递归版本
*/

/*
* 注意事项
* 由于需要回溯，利用栈来暂存节点
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
    void PreorderTraversal(TreeNode* root, vector<int>&ret){
        if(!root) return;
        stack<TreeNode*>s;
        TreeNode *node = root;
        while(node || !s.empty()){
            while(node) {
                ret.push_back(node->val);
                s.push(node);
                node = node->left;
            }
            if(!s.empty()){
                node = s.top();
                s.pop();
                node = node->right;
            }
        }
    }
    
    void MidorderTraversal(TreeNode* root, vector<int>&ret){
        if(!root) return;
        stack<TreeNode*>s;
        TreeNode *node = root;
        while(node || !s.empty()){
            while(node){
                s.push(node);
                node = node->left;
            }
            if(!s.empty()){
                node = s.top();
                s.pop();  // 待访问节点即使出栈，防止反复访问
                ret.push_back(node->val);  // 
                node = node->right;
            }
        }
    }
    
    void PostorderTraversal(TreeNode* root, vector<int>&ret){
        if(!root) return;
        stack<TreeNode*>s;
        TreeNode *node = root;
        TreeNode *lastVisit = root;  // 用来标记上一个访问记录，来确定根节点和子树最右节点的访问顺序
        while(node || !s.empty()){
            while(node){
                s.push(node);
                node = node->left;
            }
            node = s.top();  // 查看以后不能直接操作，需要判断右支
            if(node->right==nullptr || node->right == lastVisit){
                ret.push_back(node->val);
                s.pop();
                lastVisit = node;
                node = nullptr;  // 访问完的节点置空
            }else node = node->right;
        }
    }
    vector<vector<int> > threeOrders(TreeNode* root) {
        // write code here
        vector<int>ret1,ret2,ret3;
        vector<vector<int>>ret;
        PreorderTraversal(root, ret1);
        ret.push_back(ret1);
        MidorderTraversal(root, ret2);
        ret.push_back(ret2);
        PostorderTraversal(root, ret3);
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