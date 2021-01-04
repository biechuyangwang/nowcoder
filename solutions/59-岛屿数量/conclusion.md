# [岛屿数量](https://www.nowcoder.com/practice/0c9664d1554e466aa107d899418e814e)
[题解](./main_1.cpp)

## 思路
```cpp
/*
* dfs
* 并查集
*/
```

## dfs
```cpp
class Solution {
public:
    /**
     * 判断岛屿数量
     * @param grid char字符型vector<vector<>> 
     * @return int整型
     */
    void dfs(vector<vector<char> >& grid, int i, int j){
        grid[i][j]='0';  // 标志访问，然后依次访问四个方向
        if(i-1>=0 && grid[i-1][j]=='1') dfs(grid,i-1,j);
        if(i+1<grid.size() && grid[i+1][j] == '1') dfs(grid,i+1,j);
        if(j-1>=0 && grid[i][j-1]=='1') dfs(grid,i,j-1);
        if(j+1<grid[0].size() && grid[i][j+1] == '1') dfs(grid,i,j+1);
    }
    int solve(vector<vector<char> >& grid) {
        // write code here
        int res=0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j] == '1'){
                    res++;
                    dfs(grid,i,j);
                }
            }
        }
        return res;
    }
};
```

## 并查集
```cpp
class Solution {
public:
    int n, m, f[40005], vis[40005];
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};

    int getid(int x,int y) { // 为方格中每个点编号
        return x * m + y;
    }
    int find(int x) {
        return x == f[x] ? x : f[x] = find(f[x]);  // 递归查根节点
    }
    void merge(int a,int b,int x,int y) {
        int k1 = find(getid(a, b)), k2 = find(getid(x, y));
        if (k1 != k2) f[k1] = k2;  // 并入并查集
    }
    bool Judge(int x,int y) { // 判断一个点是否出界
        return x >= 0 && x < n && y >= 0 && y < m;
    }
    int solve(vector<vector<char> >& grid) {
        n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n * m; ++i) vis[i] = 0, f[i] = i;
        for (int i = 0; i < n; ++i) 
            for (int j = 0; j < m; ++j) 
                for (int k = 0; k < 4; ++k) {
                    int x = i + dx[k], y = j + dy[k];
                    if (Judge(x, y) && grid[x][y] == '1' && grid[i][j] == '1') merge(x, y, i, j);
                }
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (grid[i][j] == '1') vis[find(getid(i, j))] = 1;  // 并查集的根节点置1
        int ans = 0;
        for (int i = 0; i < n * m; ++i) 
            ans += vis[i];
        return ans;

    }
};
```