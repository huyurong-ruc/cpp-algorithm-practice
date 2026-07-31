# map 使用笔记

`map<Key, Value>` 保存“键—值”对应关系，并按照键自动排序。底层通常由平衡树实现，插入、删除和查询的时间复杂度都是 `O(log n)`。

完整可运行示例：[map.cpp](../stl-templates/map.cpp)。

## 创建与写入

```cpp
map<string, int> scores;
scores["Alice"] = 90;
scores.insert({"Bob", 85});
```

同一个键只会保留一个值，再次赋值会更新原值。

## 查询

只判断键是否存在时，可以使用 `count`：

```cpp
if (scores.count("Alice") > 0) {
    // Alice 存在
}
```

需要同时读取键和值时，使用 `find`：

```cpp
auto iter = scores.find("Alice");
if (iter != scores.end()) {
    cout << iter->first << ' ' << iter->second;
}
```

`find` 返回迭代器，不是数组下标或普通指针。查找失败时，它等于 `scores.end()`，因此解引用之前一定要检查。

## `operator[]` 的易错点

```cpp
cout << scores["Carol"];
```

如果 `"Carol"` 原本不存在，`operator[]` 会先创建它，并把对应的 `int` 初始化为 `0`。因此，只想查询而不想修改容器时，应使用 `find`、`count` 或 `at`：

```cpp
cout << scores.at("Alice");
```

`at` 在键不存在时会抛出异常，使用前仍要确认键存在。

## 遍历

```cpp
for (const auto& [name, score] : scores) {
    cout << name << ' ' << score << '\n';
}
```

这里使用引用可以避免复制，`const` 表示遍历过程中不修改元素。因为 `map` 按键排序，遍历结果也是有序的。

如果不需要有序结果，只关心平均 `O(1)` 的查询，可以参考 [unordered_map 示例](../stl-templates/unordered-map.cpp)。

