# 一. 定义和应用样式

## 1. 前言

CSS样式有一条或多条以分号隔开的样式**声明**组成。

每条声明包含着一个CSS**属性**和该属性的**值**，二者以冒号分隔。

```css
background-color:grey;
color:white;
```



## 2. 元素内嵌样式

通过元素的全局属性`style`可以设置元素内嵌样式

```html
<!DOCTYPE HTML>
<html>
    <head>
        <title>Example</title>
    </head>
    <body>
        <a href="http://apress.com" style="background-color:grey; color:white">Visit the Apress website</a>
        <p>
            I like <span>apples</span> and oranges.
        </p>
        <a href="http://w3c.org">Visit the W3C website</a>
    </body>
</html>
```

其中`style`属性只将样式应用到第一个`a`元素。



## 3. 文档内嵌样式

可以使用`style`元素而不是`style`属性来定义文档内嵌样式，需要使用到CSS选择器。

内嵌CSS样式的语法如下：

```html
...
<style type="text/css">
    selector {
        一些声明;
    }
</style>
```

其中选择器就是一些元素的名称，如`a`，`p`等等。

例：

```html
<!DOCTYPE HTML>
<html>
    <head>
        <title>Example</title>
        <style type="text/css">
            a {
                background-color:grey;
                color:white;
            }
        </style>
    </head>
    <body>
        <a href="http://apress.com">Visit the Apress website</a>
        <p>
            I like <span>apples</span> and oranges.
        </p>
        <a href="http://w3c.org">Visit the W3C website</a>
    </body>
</html>
```

上例将选择器`a`的样式应用到文档内的每一个`a`元素。

一个`style`元素中可以定义多条样式：

```html
<!DOCTYPE HTML>
<html>
    <head>
        <title>Example</title>
        <style type="text/css">
            a {
                background-color:grey;
                color:white;
            }
            span {
                border: thin black solid;
                padding: 10px;
            }
        </style>
    </head>
    <body>
        <a href="http://apress.com">Visit the Apress website</a>
        <p>
            I like <span>apples</span> and oranges.
        </p>
        <a href="http://w3c.com">Visit the W3C website</a>
    </body>
</html>
```



## 4. 外部样式表

通过外部样式表文件（`.css`文件）为HTML文档元素应用样式。

如有下面的`style.css`文件：

```css
a {
    background-color:grey;
    color:white;
}
span {
    border: thin black solid;
    padding: 10px;
}
```

**导入外部样式表**：

```html
<!DOCTYPE HTML>
<html>
    <head>
        <title>Example</title>
        <link rel="stylesheet" type="text/css" href="style.css"> <!-- 导入外部样式表 -->
    </head>
    <body>
        <a href="http://apress.com">Visit the Aprss website</a>
        <p>
            I like <span>apples</span> and oranges.
        </p>
        <a href="http://w3c.org">Visit the W3C website</a>
    </body>
</html>
```

可以为文档导入多个样式表，为每一个样式表使用一个`link`元素即可。

如果不同的样式表使用了相同的选择器，那么这些样式表的导入顺序很重要，在此情况下得以应用的是后导入的样式。

**为样式表导入其他样式**：

可以在样式表文件中导入其他样式表文件，如果在导入之后定义了相同选择器的不同样式，那么后定义的样式将会覆盖先定义的样式：

假设有以下一个`combined.css`样式表文件：

```css
@import "style.css";
span {
    border: medium black dashed;
    padding: 10px;
}
```

在`combined.css`里的`span`样式将会覆盖`style.css`中`span`的样式。

**声明样式表的字符编码**：

通过`@charset`语句可以设置样式表的字符编码：

```css
@charset "UTF-8";
@import "style.css";
span {
    border: medium black dashed;
    padding: 10px;
}
```

能出现在`@import`语句之前的只有`@charset`语句。

