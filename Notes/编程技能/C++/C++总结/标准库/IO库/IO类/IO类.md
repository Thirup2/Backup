# 一. 简介

## 1. 头文件

一般的IO类型和对象都是操纵`char`数据的。默认情况下，这些对象都是关联到用户的控制台窗口的。当然，我们不能限制实际应用程序仅从控制台窗口进行IO操作，应用程序常常需要读写命名文件。而且，使用IO操作处理`string`中的字符会很方便。此外，应用程序还可能读写需要宽字符支持的语言。

下表是IO库使用的头文件和头文件中定义的类型（含有前缀`w`的为对宽字符类型`wchar_t`的支持）：

| 头文件     | 类型                                                         |
| ---------- | ------------------------------------------------------------ |
| `iostream` | `istream`，`wistream`：从流中读取数据<br />`ostream`，`wostream`：向流中写入数据<br />`iostream`，`wiostream`：读写流 |
| `fstream`  | `ifstream`，`wifstream`：从文件读取数据<br />`ofstream`，`wofstream`：向文件写入数据<br />`fstream`，`wfstream`：读写文件 |
| `sstream`  | `istringstream`，`wistringstream`：从`string`读取数据<br />`ostringstream`，`wostringstream`：向`string`写入数据<br />`stringstream`，`wstringstream`：读写`string` |



## 2. 读写操作

通过`>>`和`<<`运算符以及`getline`函数进行读写操作，这些操作都需要指定输入输出流的对象，常用的输入输出对象有：

- `cin`：一个`istream`对象，从标准输入读取数据
- `cout`：一个`ostream`对象，向标准输出写入数据
- `cerr`：一个`ostream`对象，通常用于输出程序错误消息，写入到标准错误
- `clog`：一个`ostream`对象，通常用于输出程序运行时的一般性信息，写入到标准输出

### 1）`>>`运算符

通过`>>`运算符可以从一个`istream`对象读取输入数据并保存到右侧运算对象

运算符左侧为`istream`对象，右侧为要读取数据的变量

`>>`的结合律从左至右，返回其左侧运算对象，若读取了内容，则返回`true`，否则返回`false`

例：

```c++
int a, b;
std::cin >> a >> b;
```

### 2) `<<`运算符

通过`<<`运算符可以将右侧运算对象的值写入到左侧的`ostream`对象中

运算符左侧为`ostream`对象，右侧对象提供写入内容

`<<`的结合律从左至右，返回其左侧运算对象

例：

```c++
std::cout << "a = " << a << "; b = " << b << std::endl;
```

**注**：`endl`是一个被称为**操纵符**(manipulator)的特殊值。写入`endl`的效果是结束当前行，并将与设备关联的**缓冲区**(buffer)中的内容刷到设备中

### 3）`getline`函数

通过`getline`函数可以一次读取一行内容到`istream`对象中（如果是`cin`则只能一次读取一个单词，遇到空白就结束）

`getline`函数的参数是一个输入流，一个`string`对象；

`getline`函数的效果是从输入流读取一行内容（如果一开始就是一个换行符，则是一个空串），然后将其保存到那个`string`对象中

`getline`函数的返回值是参数中的输入流，若读取了内容，则返回`true`，若未读取内容，则返回`false`

```c++
string line;
getline(std::cin, line);
```

### 4）注意

**IO对象无拷贝或赋值**。

我们可以创建一个输入输出对象，但是不能在IO对象之间进行拷贝或赋值。

如：

```c++
ofstream out1, out2;
out1 = out2;				// 错误：不能对流对象赋值
ofstream print(ofstream);	 // 错误：不能初始化ofstream参数
out2 = print(out2);			// 错误：不能拷贝流对象
```



## 3. IO类型间的关系

我们可以通过`iostream`中的对象`cin`、`cout`等以及`>>`、`<<`和`getline`来实现标准输入输出。

而类型`ifstream`和`istringstream`都继承自`istream`；`ofstream`和`ostringstream`都继承自`ostream`。

所有我们可以用相同的方法来实现文件读取和`string`读取，只需要使用对应的类中的对象即可。



# 二. 条件状态

IO操作一个与生俱来的问题是可能发生错误。一些错误是可恢复的，而其他错误则是发生在系统深处，已经超出了应用程序可以修正的范围。

IO类定义了一些函数和标志，可以帮助我们访问和操纵流的**条件状态**(condition state)，其具体内容如下表(`strm`表示一种IO类型，`s`表示一个IO对象)：

| 函数及标志          | 条件状态                                                     |
| ------------------- | ------------------------------------------------------------ |
| `strm::iostate`     | `iostate`是一种机器相关的类型，提供了表达条件状态的完整功能  |
| `strm::badbit`      | `badbid`用来指出流已崩溃                                     |
| `strm::failbit`     | `failbit`用来指出一个IO操作失败了                            |
| `strm::eofbit`      | `eofbit`用来指出流到达了文件结束                             |
| `strm::goodbit`     | `goodbit`用来指出流未处于错误状态。此值保证为零              |
| `s.eof()`           | 若流`s`的`eofbit`置位，则返回`true`                          |
| `s.fail()`          | 若流`s`的`failbit`或`badbit`置位，则返回`true`               |
| `s.bad()`           | 若流`s`的`badbid`置位，则返回`true`                          |
| `s.good()`          | 若流`s`处于有效状态，则返回`true`                            |
| `s.clear()`         | 若流`s`中所有条件状态位复位，将流的状态设置为有效。返回`void` |
| `s.clear(flags)`    | 根据给定的`flags`标志位，将流`s`中对应条件状态位复位。`flags`的类型为`strm::iostate`。返回`void` |
| `s.setstate(flags)` | 根据给定的`flags`标志位，将流`s`中对应条件状态位置位。`flags`的类型为`strm::iostate`。返回`void` |
| `s.rdstate()`       | 返回流`s`的当前条件状态，返回值类型为`strm::iostate`         |

