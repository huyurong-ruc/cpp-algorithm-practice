#include <iostream>
#include<iomanip>
using namespace std;

const int maxn = 15;
int n;
int b[maxn];      // 决策栈：记录当前深度（位置）填入的数字
bool vis[maxn];   // 约束集：标记数字 1~n 是否已被使用（保证互异性）

void dfs(int dep) {
    // 1. 终止条件：当决策深度超过 n，说明 1~n 个槽位已经全部填满
    if (dep > n) {
        for (int i = 1; i <= n; ++i) {
            // 洛谷 P1706 要求每个数字右对齐，保留 5 个场宽
            cout << setw(5) << b[i];
        }
        cout << "\n";
        return;
    }

    // 2. 横向枚选：当前槽位 dep，有 1~n 共 n 种可能的选择
    for (int i = 1; i <= n; ++i) {
        // 【剪枝 / 约束检查】：如果数字 i 已经在祖先节点中被选走，直接跳过
        if (vis[i]) continue;

        // --- 做出当前层的决策 ---
        vis[i] = true;  // 占据数字 i
        b[dep] = i;     // 将数字 i 放入第 dep 个槽位

        // --- 递归进入下一层（填下一个槽位）---
        dfs(dep + 1);

        // --- 撤销决策（恢复现场 / Backtracking）---
        // 核心难点：回溯时必须把占用标记洗掉，才能让上一层的其他分支继续使用数字 i
        vis[i] = false; 
        
        // 注意：b[dep] 不需要清零，因为下一轮循环或后续分支覆盖写入时会直接替换掉
    }
}

int main() {
    // 关闭 I/O 同步，提升大量的打印输出效率
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    dfs(1);
    return 0;
}