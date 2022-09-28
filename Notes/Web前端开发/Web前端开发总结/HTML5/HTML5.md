# 一. 使用元素

## 1. 前言

**基本格式**：

```html
I like <code> apples</code> and oranges.
```

其中，`<code></code>`成为**标签**，标签之间的是元素的内容。两个标签连同其中的内容构成`code`**元素**。元素是一种用来向浏览器说明文档内容的工具。其效果体现在内容之上。不同的元素有不同的确切含义。例如，前述`code`元素代表的是计算机代码片段。

**注意**：

元素名不区分大小写。`<CODE>`、`<code>`甚至`<CoDe>`都会被浏览器视为`code`元素的开始标签。



## 2. 使用空元素

元素的开始和结束标签之间并非一定要有内容。没有内容的元素称为空元素。

有些元素为空时没有意义，但是却是有效的HTML代码。

空元素有以下两种表示方法：

1. 常规方法：标签内无内容

   ```html
   I like <code></code> apples and oranges.
   ```

2. 使用自闭合标签

   ```html
   I like <code/> apples and oranges.
   ```

   可以用这种形式表示空元素，即将开始标签和结束标签合二为一。



## 3. 使用虚元素

有些内容只能用一个标签表示，在其中放置任何内容都不符合HTML规范，这类元素称为**虚元素**。

虚元素有以下两种表示方法：

1. 只使用开始标签

   ```html
   I like apples and oranges.
   <hr>
   Today was warm and sunny.
   ```

2. 用空元素结构表示虚元素

   ```html
   I like apples and oranges.
   <hr />
   Today was warm and sunny.
   ```



## 4. 格式规范

本规范并非官方规定的，仅仅只是用于规范我自己的代码格式。

1. 普通标签：采用`<code>some words</code>`的格式，结束标签中的斜杠与标签之间不含空格。
2. 空元素：采用`<code/>`的格式，标签和斜杠之间不含空格。
3. 虚元素：采用`<hr />`的格式，标签和斜杠之间含空格。



# 二. 使用元素属性

## 1. 前言

元素可以用**属性**进行配置。如`<a>`标签需要使用`href`属性来配置超链接地址。

**基本格式**：

```html
I like <a href="/apples.html">apples</a> and oranges.
```

属性具有名称和值两部分，在上例中：名称为"href"，值为"/apples.html"。

其中名称和值用等号`=`进行连接；属性值用双引号`""`或单引号`''`进行界定。

**注意**：

如果属性值本身含有引号，那么两种引号都要用到，哪一个在内，哪一个在外则不影响，如`"''"`或`'""'`都行。



## 2. 布尔属性

有些属性不需要设定一个值，只需要将属性名添加到元素中即可，这类属性称为布尔属性，如：

```html
Enter your name: <input disabled>
```

`input`元素为用户在HTML表单中输入数据提供了一种手段。添加`disabled`属性可以阻止用户输入数据。

布尔属性还有另外两种表示方法：

```html
1. Enter your name: <input disabled=""> <!--将属性值设置为空字符串-->
2. Enter your name: <input disabled="disabled"> <!--将属性值设置为属性名称字符串-->
3. Enter your name: <input disabled="true"> <!--将属性值设置为布尔值-->
```



## 3. 自定义属性

用户可自定义属性，这种属性必须以`data-`开头，如：

```html
Enter your name: <input disabled="true" data-creator="adam" data-purpose="collection">
```

在这类属性名称之前添加前缀`data-`是为了避免与HTML的未来版本中可能增加的属性名冲突。

单独的自定义属性将被浏览器忽略，自定义属性与CSS和JavaScript结合起来很有用。



## 4. 应用多个属性

一个元素可以应用多个属性，这些属性间以一个或几个空格分隔即可。

```html
I like <a class="link" href="/apples.html" id="firstlink">apples</a> and oranges.
```

这些属性的顺序未作要求，全局属性和元素专有属性可随意交错。



## 5. 格式规范

1. 引号：外层使用双引号`""`，内层使用单引号`''`
2. 布尔属性：使用默认的格式，即无属性值的格式



# 三. 创建HTML文档

## 1. 前言

用于处理HTML文档的各种软件有一个共同的名称叫做用户代理。浏览器是最流行的用户代理，但不是唯一的一种。

HTML文档具有特定的结构，最起码要有一些关键性的元素。



## 2. 外层结构

HTML文档的外层结构由两个元素确定：`DOCTYPE`和`html`，如：

```html
<!DOCTYPE HTML>
<html>
    <!-- elements go here -->
</html>
```

上例中的`DOCTYPE`元素让浏览器明白其处理的是HTML文档。该元素中的`HTML`属性是一个布尔属性，它告诉浏览器自此直到`html`结束标签，所有内容都应作为HTML处理。



## 3. 元数据

HTML文档的元数据部分可以用来向浏览器提供文档的一些信息。

元数据包含在`head`元素内部，如：

```html
<!DOCTYPE HTML>
<html>
    <head>
        <!-- metadata goes here -->
        <title>Example</title>
    </head>
</html>
```

上例中包含一个主要的元数据元素`title`，大多数浏览器把`title`元素的内容显示在其窗口的标题栏上或用来显示文档的标签页的标签位置上。

除了可包含用于说明HTML文档的元素，`head`元素还能用来规定文档与外部资源的关系（如CSS样式表），定义内嵌CSS样式，放置和载入脚本程序。



## 4. 内容

HTML文档的主体内容部分放在`body`元素中，如：

```html
<!DOCTYPE HTML>
<html>
    <head>
        <!-- metadata goes here -->
        <title>Example</title>
    </head>
    <body>
        <!-- content and elements go here -->
        I like <code>apples</code> and oranges.
    </body>
</html>
```

`body`元素告诉浏览器该向用户显示文档的哪个部分。



## 5. 注释

放在标签`<!--`和`-->`之中的内容为注释，如：

```html
<!-- metadata goes here -->
```



## 6. 父元素、子元素、后代元素和兄弟元素

HTML文档中元素之间有明确的关系。

- **父元素**：包含另一个元素的元素是被包含元素的**父元素**，任何一个元素只能有一个父元素。
- **子元素**：被包含的元素是直接包含该元素的元素的**子元素**，一个元素可以有多个子元素。
- **后代元素**：所有被包含的元素（包括间接包含）都是包含这些元素的元素的**后代元素**，子元素也是其父元素的后代元素。
- **兄弟元素**：具有同一个父元素的几个元素互为**兄弟元素**。

**注意**：在HTML文档中，一个元素能以什么样的元素为父元素或子元素是有限制的，这些限制通过**元素类型**表现出来。



## 7. 元素类型

HTML5规范将元素分为三大类：元数据元素、流元素、短语元素

- 元数据元素：用来构建HTML文档的基本结构，以及就如何处理文档向浏览器提供信息和指示。
- 流元素和短语元素：用于确定一个元素合法的父元素和子元素范围。短语元素是HTML的基本成分，而流元素是短语元素的超集。
- 其他元素：这些元素要么没有什么特别的含义，要么只能用在一些非常有限的情况下。



# 四. 使用HTML实体

## 1. 前言

HTML文档中有些字符具有特殊含义，如最明显的`<`和`>`字符。

有时需要在文档内容中用到这些字符，但不想让他们被当做HTML处理，为此应该使用HTML实体，实体是浏览器用来替代特殊字符的一种代码。

每个特殊字符都有一个实体编号，可以用来在文档内容中代表该字符。特别常用的特殊字符还有对应的实体名称。



## 2. 常用HTML实体

| 字符    | 实体名称  | 实体编号  |
| ------- | --------- | --------- |
| &lt;    | `&lt;`    | `&#60;`   |
| &gt;    | `&gt;`    | `&#62;`   |
| &amp;   | `&amp;`   | `&#30;`   |
| &euro;  | `&euro;`  | `&#8364;` |
| &pound; | `&pound;` | `&#163;`  |
| &sect;  | `&sect;`  | `&#167;`  |
| &copy;  | `&copy;`  | `&#169;`  |
| &reg;   | `&reg;`   | `&#174;`  |
| &trade; | `&trade;` | `&#8482;` |



# 五. HTML5全局属性

## 1. 前言

每种元素都有独属于自己的属性，这种属性称为**局部属性**。而属性还有另外一种属性，叫做**全局属性**，它们用来配置所有元素共有的行为。

全局属性可以用在任何一个元素身上，不过这不一定会带来有意义或有用的行为改变。



## 2. `accesskey`属性

使用`accesskey`属性可以设定一个或几个用来选择页面上的元素的快捷键。

```html
<!DOCTYPE HTML>
<html>
    <head>
        <title>Example</title>
    </head>
    <body>
        <form>
            Name: <input type="text" name="name" accesskey="n" />
            <p/>
            Password: <input type="password" name="password" accesskey="p" />
            <p/>
            <input type="submit" value="Log In" accesskey="s" />
        </form>
    </body>
</html>
```

此例为三个`input`元素添加了`accesskey`属性。其目的是让网页或网站的熟客可以使用快捷键访问经常用到的元素。用来触发`accesskey`机制的按键组合因平台而异，在Windows系统上是同时按下`Alt`键和`accesskey`属性值对应的键。

在上例中，如果是Windows系统，那么按下`Alt+n`键可以使光标移动到`Name`输入框，按下`Alt+s`相当于按下`Log In`按钮



## 3. `class`属性

`class`属性用来将元素归类。这样做通常是为了能够找出文档中的某一类元素或为某一类元素应用CSS样式。

```html
<!DOCTYPE HTML>
<html>
    <head>
        <title>Example</title>
    </head>
    <body>
        <form>
            <a class="class1 class2" href="http://apress.com">Apress web site</a>
            <p/>
            <a class="class2 otherclass" href="http://w3c.org">W3C web site</a>
        </form>
    </body>
</html>
```

一个元素可以被归入多个类别，为此在`class`属性值中提供多个用空格分隔的类名即可。

类名可以随便取，不过最好取点具有实际含义的，文档中拥有许多元素类别时尤其如此。<br />

`class`属性本身没有任何作为，其一种利用方式是设计CSS样式时以所定义的一个或多个类作为应用目标，如：

```html
<!DOCTYPE HTML>
<html>
    <head>
        <title>Example</title>
        <style type="text/css">
            .class2 {
                background-color:grey;
                color:white;
                padding:5px;
                margin:2px;
            }
            .class1 {
                font-size:x-large;
            }
        </style>
    </head>
    <body>
        <a class="class1 class2" href="http://apress.com">Apress web site</a>
        <p/>
        <a class="class2 otherclass" href="http://w3c.org">W3C web site</a>
    </body>
</html>
```

此例用`style`元素定义了两条样式，第一条用于属于`class2`类的元素，第二条用于属于`class1`类的元素。<br />

脚本程序也可以利用`class`属性，如：

```html
<!DOCTYPE HTML>
<html>
    <head>
        <title>Example</title>
    </head>
    <body>
        <a class="class1 class2" href="http://apress.com">Apress web site</a>
        <p />
        <a class="class2 otherclass" href="http://w3c.org">W3C web site</a>
        <script type="text/javascript">
            var elems = document.getElementsByClassName("otherclass");
            for (i = 0; i < elem.length; i++) {
                var x = elems[i];
                x.style.border = "thin solid black";
                x.style.backgroundColor = "white";
                x.style.color = "black";
            }
        </script>
    </body>
</html>
```

此例中的脚本程序找出所有属于`otherclass`类的元素并对其设置了一些样式。



## 4. `contenteditable`属性
