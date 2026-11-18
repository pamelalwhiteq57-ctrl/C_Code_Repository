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
└── C_Codes\
    ├── C_Learning_codes\               ← 学习课，一课一文件夹
    │   ├── L_01_Hello_C\
    │   │   ├── L_01_hello_C.c
    │   │   ├── Notes_01_include_header_main_braces.md
    │   │   └── output\                 ← 编译产物（已 gitignore）
    │   ├── L_02_Printf_Scanf\
    │   │   ├── L_02_printf_Built_in_function.c
    │   │   ├── Notes_02_printf_and_format.md
    │   │   └── output\
    │   ├── L_03_Keywords\
    │   │   ├── L_03_keywords.c
    │   │   ├── Notes_03_keywords.md
    │   │   └── output\
    │   ├── L_04_ASCII\
    │   │   ├── L_04_ASCII.c
    │   │   ├── Notes_04_ascii.md
    │   │   └── output\
    │   ├── L_05_null_terminator\
    │   │   ├── L_05_null_terminator.c
    │   │   ├── Notes_05_null_terminator.md
    │   │   └── output\
    │   └── L_06_ESC\                    ← 之后每课都按这个形状加
    │       ├── L_06_ESC.c
    │       ├── Notes_06_escape_characters.md
    │       └── output\
    └── C_Practice_codes\               ← 练习/题（P_ 开头）
```

- **一课一文件夹**：源码、笔记、`output\` 都放在同一课的文件夹里（2026-11-16 起）
- **学习课**：`L_编号_主题.c`（和 Python 仓库的 `L_` 规则一致）
- **练习/题**：`P_编号_主题.c`，放 `C_Practice_codes\`
- **笔记**：`Notes_序号_英文主题.md`，和当天的源码放在同一个课文件夹里
- **文件名/文件夹名只用字母、数字、下划线**：不要用 `'`、空格、`(` `)`。单引号会让 PowerShell 从引号处切断路径，插件直接报 `Set-Location : A positional parameter cannot be found...` 或 `CommandNotFoundException`（2026-11-18 的 `L_05_the'0'at_the_end` 撞过一次，已改名为 `L_05_null_terminator`）
- **编译产物一律进 `output\`**，`.gitignore` 已含 `*.exe`、`*.o`

---

## 四、编译与运行（AI 用这套命令）

```powershell
# 编译（用绝对路径，因为 PATH 可能没生效；注意现在是一课一文件夹）
C:\mingw64\bin\gcc.exe "C_Codes\C_Learning_codes\L_01_Hello_C\L_01_hello_C.c" `
    -o "C_Codes\C_Learning_codes\L_01_Hello_C\output\L_01_hello_C.exe"

# 运行
& "C_Codes\C_Learning_codes\L_01_Hello_C\output\L_01_hello_C.exe"
```

**用户自己用的是插件**（点右上角 ▶ 运行），**注意**：源码没改时插件会提示
`Executable is up-to-date. Skipping compilation.` —— **这是正常行为，不是报错**。

---

## 五、当前进度

| 文件 | 内容 | 状态 |
|---|---|---|
| `L_01_Hello_C\L_01_hello_C.c` | `scanf` 读入 + `printf` 输出 | ✅ 跑通 |
| `Notes_01_include_header_main_braces.md` | 笔记 01：include / 头文件 / main / 花括号 | ✅ 定稿 |
| `L_02_printf_Built_in_function.c` | `printf` 与 `%d %f %c %s` 占位符练习 | ✅ 跑通 |
| `Notes_02_printf_and_format.md` | 笔记 02：printf 与格式化占位符（含占位符速查表） | ✅ 定稿 |
| `L_03_keywords.c` | C17 全部 44 个关键字，按字母顺序打印 | ✅ 跑通 |
| `Notes_03_keywords.md` | 笔记 03：关键字分组 + 与 Python 对照 | ✅ 定稿 |
| `L_04_ASCII.c` | 用 `%c` 打印 32~127 的 ASCII 表（`for` 循环留给后面学） | ✅ 跑通 |
| `Notes_04_ascii.md` | 笔记 04：ASCII 编码 + `char` 就是小整数 | ✅ 定稿 |
| `L_05_null_terminator\L_05_null_terminator.c` | `"abc"` 带 `\0` 与 `{'a','b','c'}` 不带 `\0` 的对比（`printf("%s")` 读到哪停） | ✅ 跑通 |
| `Notes_05_null_terminator.md` | 笔记 05：`\0` 是停止标记 / 双引号自带、大括号要自己补 | ✅ 定稿 |
| `L_06_ESC\L_06_ESC.c` | 转义字符：`\?` `\'` `\"` `\\` `\a` `\b` `\r` `\t` 各自的效果（`\f` 先不讲） | ✅ 跑通 |
| `Notes_06_escape_characters.md` | 笔记 06：讲义原文的转义字符表 + 我代码里每行的效果 | ✅ 定稿 |

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
5. C 的报错要**用中文说清它的意思**（gcc 的英文报错他还不熟）
6. **不要用"人话"这个词**，他不喜欢；解释报错就直接写「意思是……」
7. **不许超纲**（2026-11-18 他明确提的）：只用他学过的词解释。碰到没学过的概念（栈、指针、内存地址、字节编码、未定义行为……）就先写一句「这个先跳过」，最多带一嘴，绝不展开；他追问了才讲

---

## 八、交接资料

**完整对话存档**（2026-09 ~ 2026-11，含 Python 阶段）：

```
D:\Desktop\Code\备份\对话存档_2026-11-16.zip
└── 对话全文.md    ← 需要时让他读这个，能知道"上一个 AI"怎么教的、踩过什么坑
```

**他经历过的教训（别重犯）**：
- 2026-11-11：直接改 DSH 存储文件（`workspace.json`）**把工作区搞坏过一次** → **这类文件只读不写**
- `property` 那次一次性抛太多概念，把他讲崩 → 必须"一次一个"

---

## 九、已知故障（2026-11-16 排过一次）

### 工作区被 Windows 文件夹权限挡住

**症状**：新会话一打开这个工作区，任何命令都失败，报

```
SetNamedSecurityInfoW failed (Win32 5): grantWrite(D:\Desktop\Code\C_Code_Repository)
```

（意思是：DSH 要替工作区加沙箱读写授权，被这个文件夹的权限挡了）

**原因**：文件夹的**所有者虽然是当前用户**，但缺 `WRITE_OWNER`（所有者权限），
DSH 的沙箱因此没法配置授权。

**当时怎么修的**：只用 DSH 自带的诊断脚本，给**这个文件夹**补了一条
「当前登录用户 = 完全控制」的允许项；**文件内容、所有者、其他权限都没动**。
改完立刻重跑原命令 → 能列文件、gcc 正常 → 确认修好。

**备份 + 撤销命令**（都在 `C:\Users\18510\.dsh\acl-reports\`）：

```powershell
pwsh -NoProfile -File 'C:\Users\18510\.dsh\acl-reports\acl-backup-95c82bdfe2f747338f24eb7fd740c291.json.ps1' -Path 'D:\Desktop\Code\C_Code_Repository' -AllowRoot 'D:\Desktop\Code\C_Code_Repository' -Restore 'C:\Users\18510\.dsh\acl-reports\acl-backup-95c82bdfe2f747338f24eb7fd740c291.json'
```

**教训**：这种"整个工作区打不开"的故障，**先查文件夹权限**，
别急着重装 DSH、重建工作区、或去动存储文件。

> 补充：如果只是某个路径读不到/write 不进去（不是整个工作区挂掉），
> 也有专门的排查流程，别手改权限。
> 全局那份 AGENTS.md 的规矩照旧：**`~/.dsh/storages/*` 只读不写，换工作区走界面。**

---

## 十、笔记规范（2026-11-16 定，按他的反馈调整）

**一份笔记 = 一个主题。** 不搞章节目录，标题只写讲的是什么。

### 内容

- **只写当天真正讲过、他确认懂了的东西**
- **尽量精简**：长话短说，不堆概念。但**不设行数硬指标**——那天内容多就长一点，少就短一点，以「看完能复述」为准
- **重心放在 C 语言本身**：语法、类型、内存、为什么这样设计
- **尽量配 Python 类比**，他说这是笔记里最有用的部分
- **Python 对比可以再多一点，但要克制**：每块配一两处就够，整份控制在 3 到 5 处；不要每段都对比，写多了反而乱
- 开头给一两句总结，或者「先记这几句」

### 视角

- **笔记用第一人称写**，就当是他自己记的
- 不写「你的代码」「你写的这个程序」，写「我写的这个程序」
- 不用旁观者口吻（「他」「用户」也不行）：全篇只有「我」和 C 语言本身

### 报错

- **报错不是重点，不用专门列表去背。** 同一个错撞了两次以上、或者他自己问起来，再顺手记一句就行

### 格式

- 文件名 `Notes_序号_英文主题.md`，放当天源码的同一个课文件夹里
- 英文标点，不用 `**` 粗体，不用 ①②③
- **不用 Markdown 表格，不用竖线 `|` 分割**（2026-11-18 他明确说的）：要对比的东西写成「名字: 说明, 说明」，一行一条，用逗号断句。笔记要能照着抄到纸质本子上，竖线抄起来太累
- 不写「人话」这个词，解释报错直接写「意思是……」
- 不写他还没学的东西（指针、`gcc -E` 展开、`char *` 细节），学到时再说
- **例子只用他当天亲手写过的写法**。不要为了「讲全」另造带未学语法的例子（比如他还没学数组时，笔记里出现 `char c[5]`、`arr2[3]` 这种），否则等于逼他看没学过的东西（2026-11-18 笔记 05 撞过一次，已删）
- 不自己造章节体系，**以他的划分和进度为准**

### 判断标准

他能不能一口气看完，并且**当天就能照着复述**。做不到就是写复杂了。
