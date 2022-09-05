---
title: hexo重新开始
date: 2022-08-21 15:54:33
categories:
    - 个人博客
    - Hexo
tags: method
---
# 一. 前言
通过Github Page+Hexo搭建的静态网站，我将网站内容以及Hexo源文件存放在同一个仓库中。
其中网站内容使用仓库的main分支，Hexo源文件使用仓库的Hexo分支。
其中Hexo有几个文件夹在`.gitignore`文件中设置了忽略，所以并不会上传到仓库中，这几个文件夹往往放着一些组成该静态网站的插件等内容，所以如果我在换了电脑的情况下，将这个Hexo源文件clone到本地之后，还需要进行一些配置再进行部署。
以下就是大致的内容：
# 二. 环境
## 1. git
- 访问[官网](https://git-scm.com/downloads)进行下载
- 安装完成可以看到在任意位置右键会有一个功能`Git Bash Here`，通过这个功能可以打开一个命令行界面
- 配置ssh秘钥

## 2. node.js
- 访问[官网](http://nodejs.cn/download/)下载对应的**长期支持版本**

## 3. hexo
- 在任意位置打开`Git Bash`，通过以下命令安装`hexo`
```shell
npm install hexo-cli -g
```

# 三. 恢复
## 1. 仓库
- 将所需仓库的Hexo分支克隆到本地
- 进入该仓库的文件夹

## 2. git支持
- 执行以下操作
```shell
npm install
npm install hexo-deployer-git --save
```

## 3. 我的其他插件
- 文章二维码
```shell
npm install hexo-helper-qrcode --save
```
- 本地搜索
```shell
npm install hexo-generator-search --save
```
- live2d插件
```shell
npm install --save hexo-helper-live2d
```
- live2d模型
```shell
npm install live2d-widget-model-koharu
```

# 四. 预览与部署
- 和往常一样
```shell
hexo g
hexo s
hexo clean
hexo g -d
```