---
title: gcc版本更新
date: 2021-3-16
categories:
    - Linux
    - CentOS
tags: method
---
# 前言
CentOS 7 的默认gcc版本是4.8.5，所以会想来更新一下gcc的版本。
第一次使用，记录一下。

# 操作
1. 安装centos-release-scl
```
yum install centos-release-scl
```
2. 安装devtoolset, 注意, 如果想安装7.* 版本的, 就改成devtoolset-7-gcc*
```
yum install devtoolset-8-gcc*
```
3. 替换旧的gcc
```
mv /usr/bin/gcc /usr/bin/gcc-4.8.5
ln -s /opt/rh/devtoolset-8/root/bin/gcc /usr/bin/gcc
```
4. 查看gcc版本
```
gcc -v
```