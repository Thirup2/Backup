# 一. 标准异常类
## 1. 标准异常
C++标准库定义了一组类，用于报告标准库函数遇到的问题。这些异常类也可以在用户编写的程序中使用，它们分别定义在4个头文件中：
### 1). exception
exception头文件定义了最通用的异常类`exception`。它只报告异常的发生，不提供任何额外信息。

### 2). stdexcept
stdexcept头文件定义了几种常用的异常类，详细信息如下表：
|异常类|异常问题|
|:-:|:-:|
|`exception`|最常见的问题|
|`runtime_error`|只有在运行时才能检测出的问题|
|`range_error`|运行时错误：生成的结果超出了有意义的值域范围|
|`overflow_error`|运行时错误：计算上溢|
|`underflow_error`|运行时错误：计算下溢|
|`logic_error`|程序逻辑错误|
|`domain_error`|逻辑错误：参数对应的结果值不存在|
|`invalid_argument`|逻辑错误：无效参数|
|`length_error`|逻辑错误：试图创建一个超出该类型最大长度的对象|
|`out_of_range`|逻辑错误：使用一个超出有效范围的值|

### 3). new
new头文件定义了`bad_alloc`异常类型

### 4). type_info
type_info头文件定义了`bad_cast`异常类型

## 2. 使用
标准异常类只定义了几种运算，包括创建或拷贝异常类型的对象，以及为异常类型的对象赋值
### 1). 初始化
对于`exception`、`bad_alloc`和`bad_cast`对象，只能以默认初始化的方式初始化这些对象，不允许为这些对象提供初始值
对于其他异常类型，应该使用string对象或者C风格字符串初始化这些类型的对象，但是不允许使用默认初始化的方式。当创建此类对象时，必须提供初始值，该初始值含有错误相关的信息

### 2). 成员函数what
异常类型只定义了一个名为what的成员函数，该函数没有任何参数，返回值是一个指向C风格字符串的`const char *`。该字符串的目的是提供关于异常的一些文本信息。
what函数返回的C风格字符串的内容与异常对象的类型有关：
对于只能显式初始化的异常类型来说，what返回初始化使用的字符串；
对于只能默认初始化的异常类型来说，what返回的内容由编译器决定。

# 二. throw表达式
程序的异常检测部分使用**throw**表达式引发一个异常。
throw表达式包含关键字throw和紧随其后的一个表达式，其中表达式的类型就是抛出的异常类型。throw表达式后面通常紧跟一个分号，从而构成一条表达式语句。
如：
```c++
throw exception(str);
```
- exception即某个标准异常类
- str是用于初始化该标准异常类的string对象或C风格字符串
- 若exception是不可显式初始化的标准异常类，则不需要初始化的部分

**效果**：如果在try语句块中使用throw表达式，程序将寻找对应的catch子句进行处理。如果throw没有使用在try语句块中或者没能找到任何catch子句，程序调用名为**terminate**的标准库函数。该函数的行为与系统有关，一般情况下，执行该函数将导致程序非正常退出。

# 三. try语句块
try语句块的通用语法形式是：
```c++
try {
    program-statements
} catch (exception-declaration) {
    handler-statements
} catch (exception-declaration) {
    handler-statements
}    // ...
```
* `program-statements`部分包括一些普通的语句与一些throw表达式，用于抛出错误
* `catch`子句用于处理try语句块中抛出的错误
* `exception-declaration`是一个标准异常类的声明，用于匹配try语句块中抛出的错误以及创建一个标准异常类的对象，如果抛出错误时使用了初始化，则将该初始化值赋值给该对象。
* `handler-statements`包含一些语句，用于处理抛出的错误

**匹配catch的顺序**：
在复杂系统中，程序在遇到抛出异常的代码前，其执行路径可能已经经过了多个try语句块。例如，一个try语句块可能调用了包含另一个try语句块的函数，新的try语句块可能调用了包含有一个try语句块的新函数，以此类推。
寻找处理代码的过程与函数调用链正好相反。当异常被抛出时，首先搜索抛出该异常的函数。如果没找到匹配的catch子句，终止该函数，并在调用该函数的函数中继续寻找。如果还是没有找到匹配的catch子句，这个新的函数也被终止，继续搜索调用它的函数。以此类推，沿着程序的执行路径逐层回退，直到找到适当类型的catch子句为止。
如果最终还是没能找到任何匹配的catch子句，程序就将调用terminate函数。

# 四. 实例
```c++
#include "Sales_item.h"
#include <iostream>
#include <string>
using namespace std;
int main()
{
    Sales_item item1, item2;
    while (cin >> item1 >> item2) {
        try {
            if (item1.isbn() != item2.isbn())
                throw runtime_error("Data must refer to same ISBN");
            cout << item1 + item2 << endl;
        } catch (runtime_error err) {
            cout << err.what()
                 << "\nTry Again? Enter y or n" << endl;
            char c;
            cin >> c;
            if (!cin || c == 'n')
                break;
        }
    }

    return 0;
}
```
1. 程序首先验证两条数据是否是关于同一书籍的
2. 如果是同一书籍则跳过`if`执行加法操作然后继续循环
3. 如果不是同一书籍则抛出一个`runtime_error`异常并进行初始化
4. 寻找匹配的catch子句，该例只有一个catch子句且匹配，于是进入该catch内部执行语句块