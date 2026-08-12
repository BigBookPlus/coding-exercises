# coding-exercises

Codeforces 刷题仓库（C++）。

## 目录

```
cf/                 # 活跃 CF 题，命名：{Letter}_{Title}.cpp
template.cpp        # 新题起步模板
archive/            # 历史归档（LeetCode、OJ、AcWing、旧 CF）
```

## 新题流程

1. 复制 `template.cpp` 到 `cf/`，或在 CPH 中 Parse 题目。
2. CPH 默认保存目录设为仓库下的 `cf/`。
3. 文件命名与 CPH 一致，例如 `A_Minimal_Coprime.cpp`。

## 本地构建

```bash
cmake -S . -B build
cmake --build build
```

每个 `cf/*.cpp` 会生成同名可执行文件，例如 `build/cf/A_String`。
