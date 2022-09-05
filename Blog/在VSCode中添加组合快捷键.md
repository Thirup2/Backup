---
title: 在VSCode中添加组合快捷键
date: 2021-3-16
categories:
    - 编程软件
    - VSCode
tags: method
---
# 起因
用久了全键的键盘，最近换到了笔记本电脑自带的60键键盘，由于不熟悉Vim，所以安装了Vim插件也用不习惯，可是不用Vim的话，对于60键键盘，我只能说，方向键太烦人了。
我一般使用C/C++编程，经常涉及到的一种情况是：在一行代码写完之后，我的光标停留在括号或引号里面，我经常需要先使用方向键将光标移动到行末，然后再添加分号。
所以我想有没有一个快捷键方案可以让我迅速移到行末，甚至是直接在行末添加分号，在网上稍微找了一下，还真有。

# 操作
## 1. 安装'macros'扩展  
![屏幕截图 2022-02-27 204044](https://user-images.githubusercontent.com/91216205/155882737-7b01dfb6-e7b8-4052-8bf0-1e5b4efd6ea3.png)
这个扩展是用来提供快捷命令的，如将光标移动到行末。

## 2. 在settings.json里添加以下代码  
![屏幕截图 2022-02-27 204242](https://user-images.githubusercontent.com/91216205/155882815-176db15b-3855-4e7d-b1a0-062570628259.png)
```json
"macros": {
        "end_semicolon": [ // 末尾加分号
            "cursorLineEnd",
            {
                "command": "type",
                "args": {
                    "text": ";\n"
                },
            },
        ],
        "end_colon": [ // 末尾加冒号
            "cursorLineEnd",
            { "command": "type",
                "args": {
                    "text": ":\n"
                }
            },
        ],
    }
```
这一步是在设置文件里添加你想要的快捷键命令，如上图中添加了两个命令，一个是移动到行末添加分号，一个是移动到行末添加冒号，两个命令的名称分别是：`end_semicolon`和`end_colon`

## 3. 在keybindings.json里添加以下代码  
![屏幕截图 2022-02-27 204344](https://user-images.githubusercontent.com/91216205/155882879-ebe2e28b-3e27-465f-abc1-3fcf0ee50649.png)
```json
    {
        "key": "alt+;",
        "command": "macros.end_semicolon"
    },
    {
        "key": "alt+shift+;",
        "command": "macros.end_colon"
    }
```
这一步将刚才添加好的命令绑定到快捷键上。
现在，按下设置好的快捷键，是否完成了你想要的操作呢？

## 4. 实现更多功能
阅读扩展支持的命令，你还可以发现更多的命令。将这些基础命令组合，可以实现更多的功能。
比如我现在常用的快捷键和功能如下：
- keybindings.json
```json
    {
        "key": "shift+enter",
        "command": "macros.end_semicolon"
    },
    {
        "key": "alt+shift+enter",
        "command": "macros.end_colon"
    },
```
- settings.json
```json
    "macros": {
        // 转到行末添加分号
        "end_semicolon": [
            "cursorLineEnd",
            {
                "command": "type",
                "args": {
                    "text": ";"
                },
            },
        ],
        // 转到行末添加大括号并换行
        "end_colon": [
            "cursorLineEnd",
            { "command": "type",
                "args": {
                    "text": "{\n"
                }
            },
        ],
    },
```

第一个快捷键可以在行末添加分号，不过我将按键组合更改了一下，让它变得更方便了，并且能够在按下这个快捷键之后不用再转移到回车换行。
因为没有在行末添加冒号的需求，所以我将这个键改成了在行末添加大括号并换行，VSCode会将大括号自动补齐。