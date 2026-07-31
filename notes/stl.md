# C++ STL 常用组件

STL（Standard Template Library）提供了常用容器和算法。做题时不必背下所有接口，先掌握“存什么、如何访问、时间复杂度如何”，再按需要查示例即可。

## 顺序容器

| 组件 | 适合场景 | 常用操作 | 示例 |
| --- | --- | --- | --- |
| `array` | 长度固定的小数组 | `fill`、`front`、`back` | [array.cpp](../stl-templates/array.cpp) |
| `vector` | 默认首选的动态数组 | `push_back`、`size`、`erase` | [vector.cpp](../stl-templates/vector.cpp) |
| `deque` | 需要在两端插入或删除 | `push_front`、`push_back` | [deque.cpp](../stl-templates/deque.cpp) |
| `list` | 已知位置并频繁插入或删除 | `insert`、`erase`、`sort` | [list.cpp](../stl-templates/list.cpp) |
| `string` | 字符串处理 | `find`、`substr`、`replace` | [string.cpp](../stl-templates/string.cpp) |

多数情况下优先使用 `vector`。只有确实需要双端操作时再考虑 `deque`；`list` 不能随机访问，竞赛中使用频率相对较低。

## 容器适配器

| 组件 | 特点 | 示例 |
| --- | --- | --- |
| `stack` | 后进先出，常用于括号匹配和模拟递归 | [stack.cpp](../stl-templates/stack.cpp) |
| `queue` | 先进先出，常用于 BFS | [queue.cpp](../stl-templates/queue.cpp) |
| `priority_queue` | 每次取出当前最大值或最小值 | [priority-queue.cpp](../stl-templates/priority-queue.cpp) |

`priority_queue<int>` 默认是大根堆；小根堆可写成 `priority_queue<int, vector<int>, greater<int>>`。

## 关联容器

| 组件 | 是否有序 | 平均/典型查询复杂度 | 示例 |
| --- | --- | --- | --- |
| `set` | 有序 | `O(log n)` | [set.cpp](../stl-templates/set.cpp) |
| `map` | 有序 | `O(log n)` | [map.cpp](../stl-templates/map.cpp) |
| `unordered_set` | 无序 | 平均 `O(1)` | [unordered-set.cpp](../stl-templates/unordered-set.cpp) |
| `unordered_map` | 无序 | 平均 `O(1)` | [unordered-map.cpp](../stl-templates/unordered-map.cpp) |

需要按键排序、查找前驱或后继时使用 `set` / `map`；只关心快速查找时可以考虑 `unordered_set` / `unordered_map`。关于 `map` 的易错点见 [map 使用笔记](map.md)。

## 工具与算法

- [`pair` 与 `tuple`](../stl-templates/pair-tuple.cpp)：把多个值组合成一个对象；
- [`bitset`](../stl-templates/bitset.cpp)：固定长度的二进制位集合；
- [`algorithm`](../stl-templates/algorithm.cpp)：排序、二分、反转、查找最值；
- [`numeric`](../stl-templates/numeric.cpp)：求和、连乘、连续赋值、最大公约数。

使用算法时要留意操作区间通常写成左闭右开 `[begin, end)`。例如 `sort(values.begin(), values.end())` 会处理整个容器。

