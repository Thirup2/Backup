# 一. 字符函数
## 1. 字符输入
```c
int fgetc(FILE *stream);
int getc(FILE *stream);
int getchar(void);
```
- 参数：`fgetc`和`getc`以读或读写模式打开的流作为参数，`getchar`始终从标准输入读取所以不需要参数
- 操作：从流中读取下一个字符
- 返回值：从流中读取的字符，如果流中不存在更多的字符，函数就返回常量值EOF
## 2. 字符输出
```c
int fputc(int character, FILE *stream);
int putc(int character, FILE *stream);
int putchar(int character);
```
- 参数：三个函数的第一个参数都是要被打印的字符。在打印之前，函数把这个整型参数裁剪为一个无符号字符型值。`fputc`和`putc`以写或读写模式打开的流作为参数，`putchar`始终写入到标准输出
- 操作：把单个字符写入到流中
- 返回值：如果由于任何原因导致函数失败，它们就返回EOF

# 二. 字符I/O宏
`fgetc`和`fputc`都是函数
`getc`、`putc`、`getchar`和`putchar`都是通过`#define`指令定义的宏

# 三. 撤销字符I/O
`ungetc`函数用于把一个先前读入的字符返回到流中，这样它可以在以后被重新读入。函数原型如下：
```c
int ungetc(int character, FILE *stream);
```
- 参数：第一个参数是将要退回到流中的字符，第二个参数则是将要退回的流
- **注意**：
    - 每个流都允许至少退回一个字符。如果一个流允许退回多个字符，那么这些字符再次被读取的顺序就以退回时的反序进行
    - 把字符退回到流中和写入到流中并不相同，“退回”字符和流的当前位置有关，所以如果用`fseek`、`fsetpos`或`rewind`函数改变了流的位置，所有退回的字符都将被丢弃
    - 与一个流相关联的外部存储并不受`ungetc`的影响