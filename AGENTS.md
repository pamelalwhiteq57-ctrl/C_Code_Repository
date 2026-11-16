# AGENTS.md —— C 语言学习仓库

> 全局说明在 `C:\Users\18510\.dsh\AGENTS.md`（**任何会话都会自动加载**）。
> **这份只写 C 项目相关的东西。**

---

## 一、这个仓库是什么

- **用户的 C 语言自学仓库**（学校大一下**不教 C**，他自己提前学；学校课是《人工智能导论》）
- **起步时间**：2026-11-16
- **远程**：https://github.com/pamelalwhiteq57-ctrl/C_Code_Repository
- **一语言一仓库**：Python 在另一个仓库（`D:\Desktop\Code\My Python code Repository`）

---

## 二、环境（不用重新排查）

| 项目 | 值 |
|---|---|
| 编译器 | **MinGW-W64 GCC 16.2.0**，`C:\mingw64\bin\gcc.exe` |
| C 标准 | **`c17`**（与 GCC 默认 `gnu17` 一致；**C23 先不用**，教材/题库不认） |
| 编辑器 | VSCode + `ms-vscode.cpptools` + `danielpinto8zz6.c-cpp-compile-run` |
| 运行方式 | 插件自动编译 → 产物放 `output\` → 再运行 exe |
| ⚠️ 注意 | gcc 已加进系统 PATH，但 **AI 的 shell 是启动时的快照**，可能读不到 → **用绝对路径调用**：`C:\mingw64\bin\gcc.exe` |

---

## 三、目录与命名

```
C_Code_Repository\
├── AGENTS.md
├── .gitignore
└── C_Practice_Codes\
    └── C_Learning_codes\
        ├── L_01_Hello_C.c
        └── output\                     ← 编译产物（已 gitignore）
            └── L_01_Hello_C.exe
```

- **学习课**：`L_编号_主题.c`（和 Python 仓库的 `L_` 规则一致）
- **练习/题**：`P_编号_主题.c`
- **编译产物一律进 `output\`**，`.gitignore` 已含 `*.exe`、`*.o`

---

## 四、编译与运行（AI 用这套命令）

```powershell
# 编译（用绝对路径，因为 PATH 可能没生效）
C:\mingw64\bin\gcc.exe "C_Practice_Codes\C_Learning_codes\L_01_Hello_C.c" `
    -o "C_Practice_Codes\C_Learning_codes\output\L_01_Hello_C.exe"

# 运行
& "C_Practice_Codes\C_Learning_codes\output\L_01_Hello_C.exe"
```

**用户自己用的是插件**（点右上角 ▶ 运行），**注意**：源码没改时插件会提示
`Executable is up-to-date. Skipping compilation.` —— **这是正常行为，不是报错**。

---

## 五、当前进度

| 文件 | 内容 | 状态 |
|---|---|---|
| `L_01_Hello_C.c` | `scanf` 读入 + `printf` 输出 | ✅ 跑通 |

**下一步**：变量/运算符 → 分支循环 → 数组 → 函数 → 指针（重点）→ 结构体

---

## 六、C 新手高频坑（重点盯这些）

| 坑 | 说明 |
|---|---|
| **忘写分号** | 报错常常指在**下一行**，看错误别只看行号 |
| **`scanf` 忘 `&`** | `scanf("%d", a)` 会崩 → 必须 `&a` |
| **格式符不匹配** | `int`→`%d`、`double`→`%lf`（`printf` 里 `%f` 也行）、`char`→`%c`、字符串→`%s` |
| **数组越界** | C **不检查边界**，越界不报错但行为未定义（最凶的坑） |
| **`printf` 忘 `\n`** | 输出会粘成一行 |
| **`if (a = 1)`** | 赋值不是比较，恒为真 → 要 `==` |
| **变量未初始化** | 局部变量是**随机值**，不像 Python 会报错 |
| **字符串是字符数组** | 没有 `str` 类型，要用 `char s[20]` + `strlen`（需 `#include <string.h>`） |

---

## 七、怎么教他（和全局一致，C 这边强调这几条）

1. **先讲"为什么"，再讲"怎么写"**
2. **一次只加一个概念**，给 **10 行以内**的最小例子
3. **每次给多个测试用例 + 期望值**（他最需要的是"多测几个"的习惯）
4. **不要直接给答案，给提示 / 台阶**
5. C 的报错要**翻译成人话**（gcc 的英文报错他还不熟）

---

## 八、交接资料

**完整对话存档**（2026-09 ~ 2026-11，含 Python 阶段）：

```
D:\Desktop\备份\对话存档_2026-11-16.zip
└── 对话全文.md    ← 需要时让他读这个，能知道"上一个 AI"怎么教的、踩过什么坑
```

**他经历过的教训（别重犯）**：
- 2026-11-11：直接改 DSH 存储文件（`workspace.json`）**把工作区搞坏过一次** → **这类文件只读不写**
- `property` 那次一次性抛太多概念，把他讲崩 → 必须"一次一个"
