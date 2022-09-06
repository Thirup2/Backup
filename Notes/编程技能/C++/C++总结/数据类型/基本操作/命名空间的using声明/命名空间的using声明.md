声明某个作用域的对象时有3种方法：
### 1. 在使用中声明
如：
```c++
int i;
std::cin >> i;
std::cout << i << std::endl;
```

### 2. 使用using声明逐个声明
如：
```c++
#include <iostream>
using std::cin;
using std::cout;
int main()
{
    int i;
    cin >> i;
    cout << i << std::endl;        // 未声明的对象依旧需要在使用中声明

    return 0；
}
```

### 3. 使用using声明一次性声明
如：
```c++
#include <iostream>
using namespace std;
int main()
{
    int i;
    cin >> i;
    cout << i << endl;
    return 0;
}
```

### 4. 注意
**头文件不应包含using声明**。这是因为头文件的内容会拷贝到所有引用它的文件中去，如果头文件里有某个using声明，那么每个使用了该头文件的文件就都会有这个声明。对于某些程序来说，由于不经意间包含了一些名字，反而可能产生始料未及的名字冲突