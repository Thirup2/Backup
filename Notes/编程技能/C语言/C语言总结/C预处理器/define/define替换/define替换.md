在工序中扩展`#define`定义符号和宏时，需要涉及几个步骤：
1. 在调用宏时，首先对参数进行检查，看看是否包含了任何由`#define`定义的符号。如果是，它们首先被替换
2. 替换文本随后被插入到程序中原来文本的位置。对于宏，参数名被他们的值所替代
3. 最后，再次对结果文本进行扫描，看看它是否包含了任何由`#define`定义的符号。如果是，就重复上述处理过程。

这样，宏参数和`#define`定义可以包含其他`#define`定义的符号。但是，宏不可以出现递归

# 一. 将宏参数插入到字符串常量中
## 1. 可以把一个字符串分成几段，每段实际上都是一个宏参数
```c
#define PRINT(FORMAT,VALUE)    \
        printf( "The value is " FORMAT "\n", VALUE );
...
PRINT( "%d", x+3 );
```
这个技巧只有当字符串常量作为宏参数给出时才能使用
## 2. 使用预处理器把一个宏参数转换为一个字符串。
在宏定义中使用`#argument`这种结构将被预处理器翻译为`"argument"`
```c
#define PRINT(FORMAT,VALUE)               \
        printf( "The value of " #VALUE    \
        " is " FORMAT "\n", VALUE )
...
PRINT("%d", x + 3);
```
它将产生下面的输出：
```c
The value of x + 3 is 25
```
- `#VALUE`由于VALUE参数是`x + 3`，所以被转换为`"x + 3"`进行输出
# 二. 将两个符号连接为一个符号
在宏定义中使用`##`符号可以将其左右两边的符号连接成一个符号：
```c
#define ADD_TO_SUM(sum_number, value)    \
        sum ## sum_number += value
...
ADD_TO_SUM( 5, 25 );
```
`sum_number`为5，`##`将`sum`和`5`连接在一起，所以该语句被转换为`sum5 += 25;`
- 注意：这种连接必须产生一个合法的标识符，否则，其结果就是未定义的