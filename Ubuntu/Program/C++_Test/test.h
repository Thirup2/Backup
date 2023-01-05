// 数组相关头文件
#include <cstddef>      // 包含size_t、ptrdiff_t类型
#include <cstring>      // C风格字符串处理函数，字符为char类型
#include <cwchar>       // C风格宽与多字节字符串处理函数，字符为wchar_t、char16_t、char32_t类型
#include <cuchar>       // C风格Unicode字符转换函数，字符为char、char16_t、char32_t类型
#include <iterator>     // 包含begin、end函数
using std::begin;       // begin函数
using std::end;         // end函数

// 可变形参
#include <initializer_list>     // 包含initializer_list类型
using std::initializer_list;    // initializer_list类型

// IO
#include <iostream>     // 标准IO库
using std::cin;         // istream对象，用于标准输入
using std::cout;        // ostream对象，用于标准输出
using std::cerr;        // ostream对象，用于错误的标准输出
using std::clog;        // ostream对象，用于日志的标准输出
using std::wcin;        // wistream对象，用于wchar_t的标准输入
using std::wcout;       // wostream对象，用于wchar_t的标准输出
using std::wcerr;       // wostream对象，用于wchar_t类型的错误输出
using std::wclog;       // wostream对象，用于wchar_t类型的日志输出
#include <fstream>      // 文件IO库
using std::ifstream;    // ifstream类型
using std::ofstream;    // ofstream类型
using std::fstream;     // fstream类型
using std::wifstream;   // wifstream类型
using std::wofstream;   // wofstream类型
using std::wfstream;    // wfstream类型
#include <sstream>      // stringIO库
using std::istringstream;   // istringstream类型
using std::ostringstream;   // ostringstream类型
using std::stringstream;    // stringstream类型
using std::wistringstream;  // wistringstream类型
using std::wostringstream;  // wostringstream类型
using std::wstringstream;   // wstringstream类型

using std::endl;            // 输出该符号前的内容和一个换行，然后刷新缓冲区
using std::ends;            // 输出该符号前的内容和一个空字符，然后刷新缓冲区
using std::flush;           // 输出该符号前的内容，然后刷新缓冲区
using std::unitbuf;         // 将刷新模式设置为unitbuf，即每一次输出操作后立即执行flush操作
using std::nounitbuf;       // 将刷新模式恢复为默认设置