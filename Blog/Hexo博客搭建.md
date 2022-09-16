---
title: Hexo博客搭建
date: 2022-08-25 08:39:26
categories:
    - 个人博客
    - Hexo
tags: method
---
# 前言
从我自己利用Hexo搭建博客也已经过了好几天了，本文将从如何准备到最终发布到公网上来进行说明，由于我也只是个新手，文章中难免涉及到错误，如果看到还请务必联系我。
文章参考了博主<b>[ITBOB·鲍勃](https://itrhx.blog.csdn.net/)</b>的博文：[使用 Github Pages 和 Hexo 搭建自己的独立博客【超级详细的小白教程】](https://blog.csdn.net/qq_36759224/article/details/82121420?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522166138842216782391823439%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fblog.%2522%257D&request_id=166138842216782391823439&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~blog~first_rank_ecpm_v1~rank_v31_ecpm-1-82121420-null-null.nonecase&utm_term=hexo%E6%90%AD%E5%BB%BA&spm=1018.2226.3001.4450)，是一篇十分优秀的搭建hexo博客的教程，我也是根据这篇教程才建好了自己的博客，如果有兴趣，务必要去看看。
当人掌握了某种知识之后，大部分人都会把它当成理所应当的东西，所以反而不清楚问题人的疑惑在哪。于是我在刚作为小白将博客搭建好之后，就想到一定要快点将它记录下来。
因为我是在Windows环境下搭建的，本文也将以Windows环境为前提进行搭建，如果想找Linux的博客搭建教程，请移步另外的地址。

# 一. Hexo简介
在这里就不搬百度百科里面的内容了，说一下我自己的理解吧。
首先Hexo就是一个工具，一个搭建博客系统的工具，最终的博客的表现形式是一个静态网站。
Hexo是基于Node框架的，所以首先需要安装Node。
如果要备份博客文件夹或者是使用Github Page将Hexo博客发布到公网上，那么还需要一个Git插件。
另外，Hexo的使用是用命令行工具进行的，其中可以使用的命令行有Windows的**cmd**和后面安装Git插件后可以使用的**Git Bash**。而Windows的**powershell**似乎不能使用hexo命令，可能是我技术不到位不会调试。
最后，博客系统最重要的就是博文了，Hexo使用**Markdown**格式的文档。它首先将md文档解析为静态网页，然后发布到网站中。关于Markdown的语法，可以去网上搜搜，内容并不多，花个半个小时就能学会。
好吧，就让我们开始吧。

# 二. 环境准备
## 1. Node
- 进入[Node官网](https://nodejs.org/en/download/)即可下载该工具，如图所示，选择长期维护版Windows版本，点击下载即可。
![官网页面](https://user-images.githubusercontent.com/91216205/186554345-b0e15c54-02c1-435c-8a05-fa5be3d97249.png)

- 下载好后，打开安装文件。该next的next，该接受协议的接受协议，该选择安装路径的选择安装路径。下图列出了需要注意的页面：
![安装页面](https://user-images.githubusercontent.com/91216205/186561104-25a1ae79-3f90-4606-b2cc-2a99056128c5.png)

- Ok，这样Node就安装好了。

# 错误整理
## 1. 