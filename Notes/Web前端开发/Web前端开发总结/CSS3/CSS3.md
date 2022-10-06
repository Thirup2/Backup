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



# 二. 样式的层叠和继承

## 1. 前言

样式除了上述的元素内嵌样式、文档内嵌样式和外部样式表这三种之外，还有另外两个来源：

1. 浏览器样式：即元素还未设置时浏览器应用在元素身上的默认样式。根据浏览器的不同而不同。
2. 用户样式：即用户在浏览器上定义的自己的样式表



## 2. 样式的层叠

- **样式如何层叠**

浏览器要显示元素时按照以下次序检索CSS的属性值：

1. 元素内嵌样式
2. 文档内嵌样式
3. 外部样式
4. 用户样式
5. 浏览器样式

浏览器按照顺序对某个元素的样式进行查找，当找到了某个属性的值时，就不再继续往下找。

- **调整层叠次序**

将样式属性值标记为重要，可以改变正常的层叠次序，如：

```html
<!DOCTYPE HTML>
<html>
    <head>
        <title>Example</title>
        <style type="text/css">
            a {
                color: black !important; /*将这条文档内嵌样式标记为重要*/
            }
        </style>
    </head>
    <body>
        <a style="color:red" href="http://apress.com">Visit the Apress website</a>
        <!-- 此时的style将不是第一个被检索的 -->
        <p>
            I like <span>apples</span> and oranges.
        </p>
        <a href="http://w3c.org">Visit the W3C website</a>
    </body>
</html>
```

- **解决同级样式冲突**

如果有两条定义于同一层次的样式都能应用于同一个元素，而且它们都包含着浏览器要查看的CSS属性值，这时需要评估两条样式的具体程度，样式的具体程度通过统计三类特征得出：

1. 样式的选择器中的`id`值的数目
2. 选择器中其他属性和伪类的数目
3. 选择器中元素名和伪元素的数目

在评定具体程度时将上述三类特征按照`a-b-c`的形式生成两个数字（分别是两个样式对应的三个特性的数目），其比较方法是，先比较第一项`a`，若某个样式的`a`值更大，则该样式具体程度高；若两样式`a`值相等，则比较第二项`b`，与上述相同，当两样式`a`、`b`都相等时，比较`c`项。

若两样式的`a-b-c`值都相同，则浏览器根据其位置的先后选择所用的值，规则是选用定义的位置在后的值。



## 3. 样式的继承

当浏览器在上述中直接相关的样式中找不到某个属性的值，就会求助继承机制，使用父元素的这个样式属性值。

**注意**：并非所有CSS属性均可继承。一条经验是：与元素外观（文字颜色、字体等）相关的样式会被继承；与元素在页面页面上的布局相关的样式不会被继承。

在样式中使用`inherit`这个特殊的值可以强行实施继承，明确指示浏览器在该属性上使用父元素样式的值，如：

```html
<!DOCTYPE HTML>
<html>
    <head>
        <title>Example</title>
        <style type="text/css">
            p {
                color:white;
                background:grey;
                border: medium solid black;
            }
            span {
                border: inherit;
            }
        </style>
    </head>
    <body>
        <a href="http://apress.com">Visit the Aprss website</a>
        <p>
            I like <span>apples</span> and oranges.
        </p>
        <a class="myclass1 myclass2" href="http://w3c.org">Visit the W3C website</a>
    </body>
</html>
```

该例中定义了`span`的样式，其含义为`span`的`border`属性继承自父元素，而在html代码中，`span`的父元素是`p`，所以`span`的`border`属性与`p`的`border`属性值相同，即`medium solid black`。



# 三. CSS中的颜色

## 1. 前言

在CSS中，设置颜色的值可以使用多种方法：一是直接使用规定的颜色名称；二是使用十六进制或十进制数字；三是使用一些颜色函数。

可以在下面的网站中找到一份完整的颜色列表：www.w3.org/TR/css3-color



## 2. 名称与数字方法

将颜色值设为名称直接使用对应的名称即可。若将颜色值设置为十进制，则按照以下形式：`255,255,255`，表示的是红绿蓝三种颜色的亮度，0是不亮，255是最亮。将颜色值设置为十六进制则按照以下格式：`#ffffff`，其原理和十进制相同，每两个十六进制数表示一种颜色的亮度。

以下是常用的颜色名称及其数字表示法的对应表：

| 颜色名称 | 十六进制表示 | 十进制表示    |
| -------- | ------------ | ------------- |
| black    | #000000      | 0, 0, 0       |
| silver   | #C0C0C0      | 192, 192, 192 |
| gray     | #808080      | 128, 128, 128 |
| white    | #FFFFFF      | 255, 255, 255 |
| maroon   | #800000      | 128, 0, 0     |
| red      | #FF0000      | 255, 0, 0     |
| purple   | #800080      | 128, 0, 128   |
| fushia   | #FF00FF      | 255, 00, 255  |
| green    | #008000      | 0, 128, 0     |
| lime     | #00FF00      | 0, 255, 0     |
| olive    | #808000      | 128, 128, 0   |
| yellow   | #FFFF00      | 255, 255, 0   |
| navy     | #000080      | 0, 0, 128     |
| blue     | #0000FF      | 0, 0, 255     |
| teal     | #008080      | 0, 128, 128   |
| aqua     | #00FFFF      | 0, 255, 255   |

以及一组灰色派生色：

| 颜色名称       | 十六进制表示 | 十进制表示    |
| -------------- | ------------ | ------------- |
| darkgray       | #a9a9a9      | 169, 169, 169 |
| darkslategray  | #2f4f4f      | 47, 79, 79    |
| dimgray        | #696969      | 105, 105, 105 |
| gray           | #808080      | 128, 128, 128 |
| lightgray      | #d3d3d3      | 211, 211, 211 |
| lightslategray | #778899      | 119, 136, 153 |
| slategray      | #708090      | 112, 128, 144 |



## 3. 函数方法

CSS中还可以使用一些函数选择颜色。

以下是这四种颜色函数：

| 函数             | 说明                                                         | 示例                             |
| ---------------- | ------------------------------------------------------------ | -------------------------------- |
| rgb(r, g, b)     | 用RGB模型表示颜色                                            | color: rgb(112, 128, 144)        |
| rgba(r, g, b, a) | 用RGB模型表示颜色，外加一个用于表示透明度的α值（0-1）        | color: rgba(112, 128, 144, 0.4)  |
| hsl(h, s, l)     | 用HSL模型（色相[hue]、饱和度[saturation]、明度[lightness])表示颜色 | color: hsl(120, 100%, 22%)       |
| hsla(h, s, l, a) | 与HSL模型类似，只不过增加了一个表示透明度的α值               | color: hsla(120, 100%, 22%, 0.4) |



# 四. CSS中的长度

## 1. 前言

许多CSS属性要求为其设置长度值，如`width`属性和`font-size`属性，前者用于设置元素的宽度，后者用于设置元素内容的字号。

长度值是数字和单位的组合，二者之间不能有空格或其他字符。

CSS中的长度有许多单位，包括绝对长度和相对长度这两种。



## 2. 绝对长度

绝对长度的单位是现实世界的度量单位，CSS支持以下五种单位：

| 单位标识符 | 说明               |
| ---------- | ------------------ |
| in         | 英寸               |
| cm         | 厘米               |
| mm         | 毫米               |
| pt         | 磅（1磅=1/72英寸） |
| pc         | pica（1pica=12磅） |

一条样式中可以混合使用多种单位，包括混合使用绝对单位和相对单位。如果能预先知道内容的呈现方式，那么绝对单位很有用处。



## 3. 相对长度

相对长度的规定和实现都比绝对长度更复杂，需要以严密、精确的语言明确定义。相对单位的测量需要依托其他类型的单位。

以下是主流浏览器支持的一些CSS相对单位。

| 单位标识符 | 说明                                   |
| ---------- | -------------------------------------- |
| em         | 与元素字号挂钩                         |
| ex         | 与元素字体的"x高度"挂钩                |
| rem        | 与根元素的字号挂钩                     |
| px         | CSS像素（假定显示设备的分辨率为96dpi） |
| %          | 另一属性的值的百分比                   |

- **em**

以字号为基准，1em即为该元素字号宽度。

- **ex**

以当前字体的x高度为基准，也即字体基线到中线之间的距离，一般与字母`x`的高度相当。通常1ex大致等于0.5em。

- **rem**

以html元素（文档的根元素）的字号而定，若将html元素的字号设置为0.2英寸，那么2rem等于0.4英寸

- **px**

以像素为基准，但官方的定义是：参考像素是距读者一臂之遥的像素密度为96dpi的设备上一个像素的视角。

由于该标准理解起来比较困难，所以一般主流浏览器都没有理会CSS定义的像素和显示设备的像素之间的差别，它们将1像素视为1英寸的1/96（以96dpi的像素密度为准，有些平台的显示设备具有不同的像素密度，它们的浏览器通常会做些转换工作，让1像素仍然大约等于1英寸的1/96）。

所以尽管标准想定义的是一个相对长度，但是却最终被处理成了一个绝对长度。

- **%**

通过`%`可以将一个度量单位表示为其他属性值的百分比。

但是使用百分比会遇到两个麻烦，一是并非所有属性都能用这个单位。二是对于能用百分比单位的属性，那个百分比挂钩的其他属性各不相同。例如，对于`font-size`属性，挂钩的是元素继承到的`font-size`值；而对于`width`属性，挂钩的则是元素的包含块的宽度。



## 4. 其他长度

除了前面的那些相对单位，CSS还定义了其他一些单位，但是它们还未获得广泛支持。大概有以下这些：

| 单位标识符 | 说明                                                         |
| ---------- | ------------------------------------------------------------ |
| gd         | 与网格（grid）挂钩。它依赖于CSS规范中一些定义不太明确的属性，所以未获得广泛支持 |
| vw         | 与视口（viewport）宽度挂钩。1vw等于文档显示区域（如浏览器窗口）宽度的1% |
| vh         | 与视口高度挂钩。1vh等于文档显示区域高度的1%                  |
| vmin       | 1vmin等于vh和vw中较小的那个                                  |
| vmax       | 1vmax等于vh和vw中较大的那个                                  |
| ch         | 与用当前字体显示的字符的平均宽度挂钩。                       |



## 5. 用算式作值

CSS3还允许将CSS属性值设置为算式，如可以如下进行设置：`width: calc(80%-20px);`

算式包含在关键字`calc`之后的括号之中。在其中可以混合使用各种单位进行基本的算术运算。



# 五. 其他CSS单位

## 1. CSS角度单位

| 单位标识符 | 说明                              |
| ---------- | --------------------------------- |
| deg        | 度（取值范围：0deg~360deg）       |
| grad       | 百分度（取值范围：0grad~400grad） |
| rad        | 弧度（取值范围：0rad~6.28rad）    |
| turn       | 圆周（1turn等于360deg）           |



## 2. CSS时间单位

| 单位标识符 | 说明 |
| ---------- | ---- |
| s          | 秒   |
| ms         | 毫秒 |
