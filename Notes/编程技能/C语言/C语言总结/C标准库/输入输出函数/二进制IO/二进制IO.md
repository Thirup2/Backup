把数据写到文件中时，效率最高的方法时用二进制形式写入。二进制输出避免了在数值转换为字符串的过程中设计的开销和精度损失。但二进制数据并非人眼所能阅读，所以只有当数据将被另一个程序按顺序读取时，这个技巧才能使用。
# 一. I/O函数
`fread`函数用于读取二进制数据，`fwrite`函数用于写入二进制数据。它们的原型如下所示：
```c
size_t fread(void *buffer, size_t size, size_t count, FILE *stream);
size_t fwrite(void *buffer, size_t size, size_t count, FILE *stream);
```
- 参数：`buffer`是一个指向用于保存数据的内存位置的指针即缓冲区。`size`是缓冲区中每个元素的字节数。`count`是读取或写入的元素数。`stream`是数据读取或写入的二进制流
- 操作
    - `fread`从二进制输入流中读取`count`个`size`大小的元素存入到`buffer`中
    - `fwrite`从`buffer`中输出`count`个`size`大小的元素到二进制输出流中
- 返回值：实际读取或写入的元素数目。如果输入过程中遇到了文件尾或者输出过程中出现了错误，这个数字可能比请求的元素数目要小。