# 洛谷（知识点线）

与 `cf/` 并行：这里跟 [list.md](list.md) 补知识点，CF 练比赛感。

清单改编自 [SFOI-Team/luogu-problem-list](https://github.com/SFOI-Team/luogu-problem-list)（[CC BY-SA 4.0](https://creativecommons.org/licenses/by-sa/4.0/deed.zh) + [SATA](https://github.com/zTrix/sata-license)）。请给上游仓库 Star。

## 怎么用

- 一次只做一个专题；每节做 **模板（若有）+ 前 2–4 道**，节末综合题以后再做。
- 优先 CSP-S 子集：Part 3.1–3.4、4.1–4.4、6.1–6.5、7.1–7.8、8.1–8.7。不要从 Part 1 或 Part 8.9+ 当日常任务。
- CPH Parse 后保存到本目录，文件名保持 `P_1160.cpp`。
- 做完后在 [list.md](list.md) 把对应条目改成 `- [x]`。
- 题单停更于约 2020 年，遇死链或改号就换同专题的题，不必卡在原题号上。
- CF 卡在某知识点时，再回清单对应 Part（例如最短路 8.2，二分 2.3）。

## 当前专题

- 进行中：Part 7.1 链表（[P1160](https://www.luogu.com.cn/problem/P1160)）、单调队列补充（[P1440](https://www.luogu.com.cn/problem/P1440)）
- 下一节：Part 7.2 栈（[P1449](https://www.luogu.com.cn/problem/P1449) → [P1739](https://www.luogu.com.cn/problem/P1739) → [P1981](https://www.luogu.com.cn/problem/P1981) → [P1175](https://www.luogu.com.cn/problem/P1175)）
- 之后：Part 7.4 并查集（7.3 只有 P1540，已做过）

做完当前专题后，改上面这几行即可。

## 题单外补充

Part 7.3 只有 P1540，覆盖不了单调队列。这两道不在上游原文里，进度记在这里：

- [P1440 求m区间内的最小值](https://www.luogu.com.cn/problem/P1440) — `P_1440.cpp`（进行中）
- [P1886 滑动窗口](https://www.luogu.com.cn/problem/P1886) — `archive/oj-2023/luogu-p1886.cpp`

## 本地构建

```bash
cmake -S . -B build
cmake --build build
```

每个 `luogu/*.cpp` 会生成同名可执行文件，例如 `build/luogu/P_1160`。
