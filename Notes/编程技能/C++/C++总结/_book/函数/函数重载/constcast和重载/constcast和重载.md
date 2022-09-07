假设有下面这个例子：
```c++
const string &shorterString(const string &s1, const string &s2)
{
    return s1.size() <= s2.size() ? s1 : s2;
}
```
该函数接受两个string对象，当两个对象都是常量string时，函数返回一个常量string的引用；但是当两个对象都是非常量string时，函数也返回一个常量string的引用。
此时可以使用`const_cast`和重载函数来改变这一点：
```c++
const string &shorterString(string &s1, string &s2)
{
    auto &r = shorterString(const_cast<const string &>(s1),
                            const_cast<const string &>(s2));
    return const_cast<string&>(r);
}
```
当传入两个非常量的string对象时，优先进入的也是形参为非常量的函数，于是进入后面的函数。
此时先给两个形参赋予底层const属性，然后将其传入这个重载函数，这次进入的是第一个函数。
第一个函数返回一个常量string的引用，将其绑定在`r`上，然后将`r`的底层const属性去掉，再进行返回。
最后，就返回了一个非常量string的引用。