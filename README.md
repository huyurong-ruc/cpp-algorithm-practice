# 暑期 C++ 与算法练习

这是我的暑期 C++ 与算法练习仓库，用来记录基础语法、STL、搜索与模拟等内容。仓库保留了做题过程中的个人实现和部分参考代码，也整理了可复用的代码示例与学习笔记，方便之后复习和继续补充。

## 目前包含

- C++ 基础分支结构练习；
- DFS、BFS 与搜索类题目；
- 模拟题与 LeetCode 练习；
- 常用 STL 组件的独立可运行示例；
- 对应的学习笔记。

## 仓库结构

```text
.
├── notes/                  # 学习笔记
├── practice/               # 按专题整理的题目代码
│   ├── basics/             # C++ 基础练习
│   ├── leetcode/           # LeetCode 题目
│   ├── search/             # 搜索专题练习
│   └── stage-1/            # 第一阶段专题训练
├── resources/              # 学习资料
├── stl-templates/          # 常用 STL 独立示例
└── templates/              # 做题用的通用代码模板
```

题目代码大多继续使用题号作为文件名，便于和题目来源对应；目录则按照知识点分类，方便查找。

## 快速浏览

- [学习笔记索引](notes/README.md)
- [搜索：标记、DFS 与 BFS](notes/search.md)
- [C++ STL 常用组件](notes/stl.md)
- [STL 示例代码](stl-templates/)
- [阶段练习](practice/stage-1/)

## 编译与运行

示例代码以 C++17 为基础，可以在仓库根目录执行：

```bash
mkdir -p /tmp/cpp-algorithm-practice
clang++ -std=c++17 stl-templates/vector.cpp -o /tmp/cpp-algorithm-practice/vector
/tmp/cpp-algorithm-practice/vector
```

VS Code 的构建、调试和 Code Runner 配置都会把可执行文件放到 `/tmp/cpp-algorithm-practice/`，不会在源码目录生成二进制文件。该临时目录可能由 macOS 自动清理，需要时重新编译即可。

## 后续计划

- 持续补充不同算法专题的练习；
- 在笔记中记录典型思路、易错点和复杂度分析；
- 对已经完成的题目进行复盘，逐步改进代码规范。

这个仓库会随着学习进度持续更新。
