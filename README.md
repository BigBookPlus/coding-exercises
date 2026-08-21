# coding-exercises

双线刷题仓库（C++）：Codeforces 练比赛感，洛谷按专题补知识点。

## 目录

```
cf/                 # 活跃 CF 题，命名：{Letter}_{Title}.cpp
luogu/              # 活跃洛谷题，命名：P_1160.cpp
luogu/list.md       # 洛谷综合题单（进度清单）
luogu/README.md     # 当前专题与选题规则
template.cpp        # 新题起步模板
archive/            # 历史归档（LeetCode、OJ、AcWing、旧 CF）
```

## 新题流程

### Codeforces

1. 复制 `template.cpp` 到 `cf/`，或在 CPH 中 Parse 题目。
2. CPH 默认保存目录设为仓库下的 `cf/`。
3. 文件命名与 CPH 一致，例如 `A_Minimal_Coprime.cpp`。

### 洛谷

1. 看 [luogu/README.md](luogu/README.md) 确认当前专题，从 [luogu/list.md](luogu/list.md) 选题。
2. CPH 洛谷题保存目录设为仓库下的 `luogu/`。
3. 文件命名与 CPH 一致，例如 `P_1160.cpp`。做完后在清单里勾选。

## 本地构建

```bash
cmake -S . -B build
cmake --build build
```

每个 `cf/*.cpp` 会生成同名可执行文件，例如 `build/cf/A_String`。  
每个 `luogu/*.cpp` 会生成同名可执行文件，例如 `build/luogu/P_1160`。
