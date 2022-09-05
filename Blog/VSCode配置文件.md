---
title: VSCode配置文件
date: 2021-3-16
categories:
    - 编程软件
    - VSCode
tags: method
---
# 前言
VSCode的设定文件比较繁杂，所以在这里做一个备份，以免之后文件出问题之后不知道怎么改回去

# 相关文件
1. 快捷键文件<keybindings.json>
```json
[
    {
        "key": "shift+enter",
        "command": "macros.end_semicolon"
    },
    {
        "key": "alt+shift+enter",
        "command": "macros.end_colon"
    },
    {
        "key": "ctrl+h v",
        "command": "extension.liveServerPreview.open"
    }
]
```
2. 配置文件<settings.json>
```json
{
    /* 快捷键命令设置, 需要扩展"macros" */
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

    /* 文本编辑器 */
    // 基础设置
    "editor.linkedEditing": true,       // 控制编辑器是否已启用链接编辑。相关符号(如 HTML 标记)在编辑时进行更新，具体由语言而定
    "editor.smoothScrolling": true,     // 控制编辑器是否使用动画滚动
    "editor.matchBrackets":"never",    // 不显示括号小方框
    "editor.guides.indentation": true, // 不显示代码缩进线
    "editor.guides.highlightActiveIndentation": true,  // 不显示活动代码缩进线
    "editor.renderLineHighlight":"line",   // 当前行不进行高亮显示
    // 光标
    "editor.cursorBlinking": "expand",  // 控制光标的动画样式
    "editor.cursorSmoothCaretAnimation": true,  // 控制是否启用平滑插入动画
    // 格式化
    "editor.formatOnPaste": true,       // 控制编辑器是否自动格式化粘贴的内容。格式化程序必须可用，并且能针对文档中的某一范围进行格式化
    "editor.formatOnType": true,        // 换行时自动格式化
    // 建议
    "editor.acceptSuggestionOnEnter": "off",    // 关闭enter键接受建议的功能
    "editor.suggest.showSnippets": false,       // 关闭"片段"建议
    // 文件
    "files.autoSave": "afterDelay", // 自动保存
    "files.enableTrash": false, // 直接删除文件
    "files.autoGuessEncoding": true,

    /* 工作台 */
    // 外观
    "workbench.tree.renderIndentGuides": "none",    // 不显示文件夹缩进线
    // 基础设置
    "workbench.startupEditor": "none", // 启动时不自动打开编辑器
    // 导航路径
    "breadcrumbs.enabled": false, // 禁用导航路径

    /* 功能 */
    // 资源管理器
    "explorer.compactFolders": false, // 控制资源管理器文件夹呈现形式
    "explorer.confirmDragAndDrop": false, 
    "terminal.integrated.enableBell": true, // 控制是否启用终端铃声，这在终端名称旁边显示为视觉上的铃铛
    "terminal.integrated.enableMultiLinePasteWarning": false, // 将多行粘贴到终端时显示警告对话框
    "terminal.integrated.enablePersistentSessions": false, // 跨窗口是否重新加载保持工作区的终端会话
    "terminal.integrated.defaultProfile.windows": "PowerShell",
    // "terminal.integrated.profiles.windows": {
    //     "PowerShell": {
    //         "source": "PowerShell",
    //         "overrideName": true,
    //         "args": ["-NoExit", "/c", "chcp 65001"],
    //         "icon": "terminal-powershell",
    //         "env": {
    //             "TEST_VAR": "value"
    //         }
    //     },
    // },

    /* 安全性 */
    // 工作区
    "security.workspace.trust.untrustedFiles": "open", // 始终允许不受信任的文件引入受信任的工作区，而不显示提示

    /* 扩展 */
    /* C/C++ , 需要扩展"C/C++" */
    // 格式化
    "C_Cpp.formatting": "vcFormat",     // 配置格式设置引擎
    "C_Cpp.autocompleteAddParentheses": true,       // 调用函数时自动添加括号
    "C_Cpp.vcFormat.wrap.preserveBlocks": "never",  // 块的换行选项
    "C_Cpp.vcFormat.indent.caseLabels": true,
    "C_Cpp.vcFormat.indent.gotoLabels": "leftmostColumn",
    "C_Cpp.vcFormat.indent.withinParentheses": "alignToParenthesis",
    "C_Cpp.vcFormat.newLine.beforeOpenBrace.block": "sameLine",
    "C_Cpp.vcFormat.newLine.beforeOpenBrace.function": "newLine",
    "C_Cpp.vcFormat.newLine.beforeElse": false,
    "C_Cpp.vcFormat.newLine.beforeCatch": false,
    "C_Cpp.vcFormat.newLine.beforeOpenBrace.lambda": "sameLine",
    "C_Cpp.vcFormat.newLine.beforeOpenBrace.namespace": "newLine",
    "C_Cpp.vcFormat.newLine.beforeOpenBrace.type": "newLine",
    "C_Cpp.vcFormat.newLine.closeBraceSameLine.emptyFunction": true,
    "C_Cpp.vcFormat.newLine.closeBraceSameLine.emptyType": true,
    "C_Cpp.vcFormat.newLine.scopeBracesOnSeparateLines": true,
    "C_Cpp.vcFormat.space.pointerReferenceAlignment": "right",
    "C_Cpp.vcFormat.space.insertAfterSemicolon": true,
    "C_Cpp.vcFormat.space.afterCastCloseParenthesis": true,
    "C_Cpp.vcFormat.space.beforeLambdaOpenParenthesis": true,
    "C_Cpp.vcFormat.space.withinInitializerListBraces": false,

    /* Git */
    "git.ignoreLegacyWarning": true,        // 忽略旧版"Git"警告

    /* LiveServer , 需要扩展"Live Server" */
    "liveServer.settings.AdvanceCustomBrowserCmdLine": "chrome",
    "liveServer.settings.donotShowInfoMsg": true,
}
```