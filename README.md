# A Cheat Engine Data Protection Test Program

面向 Cheat Engine 的 CrackMe 简单的数据保护

Use many algorithm to protect the data, keeping real data in stack away from memory searching directly.

You goal is find the data in memory, change them and pass each level. You can also analyse the asm code to find the algorithm.

You **SHOULD NOT** search `printf` module call. And you **SHOULD NOT** look functions that not belongs to current step, which locates just next to each other.

使用多种算法保护数据，使真实数据仅存在栈中，免受直接内存扫描。

你的目标是找到内存中的数据，修改他们，然后通过每一关。你也可以分析反汇编指令找出算法。

你 **不应该** 直接搜索 `printf` 模块调用。你也 **不应该** 查看不属于这关的代码，就是那些相邻的代码。

## Levels

| Level | Difficulty |
| :---: | :--------: |
| 1-3   | Easy       |
| 4-6   | Normal     |
| 7-9   | Hard       |

## Compile

```bash
gcc main.c
```

## Run

You should change code page to `UTF-8` or `iconv` `main.c` to `GBK`.

```cmd
chcp 65001
a.exe
```

## MIT License

Copyright (c) 2019 Ganlv

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
