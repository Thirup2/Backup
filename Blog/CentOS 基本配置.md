---
title: CentOS 基本配置
date: 2021-3-16
categories:
    - Linux
    - CentOS
tags: method
---
# 前言
第一次学习Linux，找个地方记录以下基本的环境搭建。

# 一. Vim安装
## 1. 检查是否已安装

查看一下本机已经存在的包, 确认一下Vim是否已经安装, 输入:
```shell
rpm -qa|grep vim
```
如果已安装,会显示:
```shell
vim-minimal-7.4.629.e17.x86_64
vim-filesystem-7.4.629.e17.x86_64
vim-enhanced-7.4.629.e17.x86_64
vim-common-7.4.629.e17.x86_64
vim-X11-7.4.629.e17.x86_64
```
## 2. 安装

如果缺少了其中某个, 比如说: vim-enhanced这个包少了, 则执行:
```shell
yum -y install vim-enhanced
```
它会自动下载安装. 如果上面三个包一个都没有显示, 则直接输入命令:
```shell
yum -y install vim*
```
执行命令后会自动安装, 完毕后就可以使用vim编辑器了.
## 3. 配置

安装完成后开始配置vim
```shell
vim /etc/vimrc
```
打开文件后, 按 i 进入编辑模式, 然后找一个位置添加如下代码:
```shell
set nu                         " 设置显示行号
set showmode           " 设置在命令行界面最下面显示当前模式等
set ruler                     " 在右下角显示光标所在的行数等信息
set autoindent           " 设置每次单击Enter键后, 光标移动到下一行时与上一行的起始字符对齐
syntax on                   " 即设置语法检测, 当编辑C或者Shell脚本时, 关键字会用特殊颜色显示
```
添加好了之后, 按Esc, 然后输入
`:wq`
退出并保存即可.
# 二. gcc编译器安装
## 1. 查看gcc是否已安装

输入
```shell
gcc -v
```
如果显示版本号, 则已安装, 若显示找不到文件, 则未安装
## 2. 安装gcc

输入
```shell
yum -y install gcc
```
等待安装完成
## 3. 查看gcc版本

```shell
gcc -v
```
# 三. 安装gdb
## 1. 查看gdb是否安装

输入
```shell
gdb -v
```
如果显示版本号则已安装, 若显示未找到文件则未安装
## 2. 安装gdb

输入:
```shell
yum -y install gdb
```
## 3. 查看gdb版本

```shell
gdb -v
```