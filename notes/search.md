# 搜索：标记、DFS 与 BFS

搜索题的核心通常是先回答三个问题：

1. 状态是什么？
2. 一个状态可以转移到哪些新状态？
3. 如何避免重复访问，并判断搜索何时结束？

## 标记数组与“桶”

数据范围不大时，可以用数组下标表示某个值或状态：

- `visited[x]`：状态 `x` 是否访问过；
- `count[x]`：数值 `x` 出现了多少次；
- 多个标记数组：分别记录列、主对角线、副对角线是否被占用。

这种写法查询快、逻辑直观，但要先确认下标范围，避免数组越界。N 皇后练习中就分别记录了列和两条对角线的占用情况：[1219.cpp](../practice/search/1219.cpp)。

## DFS：沿一条路走到底

适合枚举方案、连通块、回溯等问题。基本过程是：

1. 判断当前状态是否已经得到答案或无法继续；
2. 枚举下一步；
3. 标记新状态并递归；
4. 如果状态会被后续分支复用，递归结束后恢复现场。

```cpp
void dfs(int state) {
    if (到达终止状态) {
        记录答案;
        return;
    }

    for (每个可行的 next_state) {
        标记 next_state;
        dfs(next_state);
        恢复标记;  // 只有回溯类问题需要
    }
}
```

连通块问题通常不需要恢复标记，因为一个位置只应访问一次。例题：[P1596](../practice/stage-1/dfs-bfs/P1596/1.cpp)。

## BFS：按距离逐层扩展

使用 `queue` 保存待处理状态。若每一步代价相同，第一次到达目标时得到的就是最少步数。

```cpp
struct Node {
    int position;
    int distance;
};

void bfs(int start) {
    queue<Node> waiting;
    waiting.push({start, 0});
    visited[start] = true;

    while (!waiting.empty()) {
        Node current = waiting.front();
        waiting.pop();

        if (current.position == target) {
            return;
        }

        for (int next : next_states(current.position)) {
            if (!visited[next]) {
                visited[next] = true;
                waiting.push({next, current.distance + 1});
            }
        }
    }
}
```

状态应在入队时标记，而不是出队时标记，否则同一个状态可能重复入队。例题：[P1135](../practice/stage-1/dfs-bfs/P1135/1.cpp)。

## 如何选择

| 场景 | 更适合的方式 |
| --- | --- |
| 枚举所有方案、回溯 | DFS |
| 判断连通性、统计连通块 | DFS 或 BFS |
| 无权图最短路、最少操作次数 | BFS |
| 搜索树很深，但只需保存当前路径 | DFS |

写完后可以用三个问题检查：终止条件是否完整、每次转移是否真的可行、标记是否在正确的时机设置或恢复。

