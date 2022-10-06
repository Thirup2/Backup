# 一. 准备

在HTML文档中定义脚本有以下几种方法：

1. 定义内嵌脚本：即在HTML文档内部通过`script`元素插入脚本，遵循JavaScript语法。位置在`head`元素内部或`body`元素末尾。
2. 定义外部脚本：脚本包含在另一个文件中，通过一个URL引用。



# 二. 使用语句

JavaScript的基本元素是语句。一条语句代表着一条命令，通常以分号结尾，实际上分号也可以不加。

```html
<!DOCTYPE HTML>
<html>
    <head>
        <titile>Example</titile>
    </head>
    <body>
        <script type="text/javascript">
            document.writeln("This is a statement");
            document.writeln("This is also a statement");
        </script>
    </body>
</html>
```

上例中执行的操作是输出两条信息，结果如下：

```
This is a statement
This is also a statement
```



# 三. 使用函数

## 1. 前言

如果在`script`元素中直接使用语句，那么浏览器一遇到这些语句就会执行它们。

也可以把几条语句包装在一个函数中，浏览器只有在遇到一条调用该函数的语句时才会执行它。



## 2. 基本定义方法

**格式**：`function 函数名(参数列表) {语句};`

**调用**：`函数名(实参);`

```html
<!DOCTYPE HTML>
<html>
    <head>
        <title>Example</title>
    </head>
    <body>
        <script type="text/javascript">
            function myFunc() {
                document.writeln("This is a statement");
            };
            
            myFunc();
        </script>
    </body>
</html>
```

函数中的语句只有在浏览器遇到一条函数调用时，才会执行函数的操作。



## 3. 带参数的函数

JavaScript是门弱类型的语言，在定义函数时不需要声明参数的数据类型。

```html
<!DOCTYPE HTML>
<html>
    <head>
        <titile>Example</titile>
    </head>
    <body>
        <script type="text/javascript">
            function myFunc(name, weather) {
            	document.writeln("Hello " + name + ".");
            	document.writeln("It is " + weather + " today");
            };
            myFunc("Adam", "Sunny");
        </script>
    </body>
</html>
```

上例的运行效果是：

```
Hello Adam. It is Sunny today
```

调用参数时提供的参数数目不必与函数定义中的参数数目相同。如果提供的参数值更少，那么所有未提供值的参数的值均为`undefined`。如果提供的参数值更多，那么多出的值会被忽略。在JavaScript中，如果定义了两个同名但参数数目不同的函数，其不会根据提供的参数数目判断调用者调用的是哪一个函数，只调用后定义的函数。



## 4. 带返回值的函数

JavaScript中如果函数有返回值，并不需要在函数定义头上做修正，只需要在函数定义体中末尾添加一条`return`语句即可。

```html
<!DOCTYPE HTML>
<html>
    <head>
        <title>Example</title>
    </head>
    <body>
        <script type="text/javascript">
            function myFunc(name) {
                return ("hello " + name + ".");
            };
            document.writeln(myFunc("Adam"));
        </script>
    </body>
</html>
```

上例的输出效果如下：

```
hello Adam.
```



# 四. 使用变量和类型

## 1. 定义变量

定义变量要使用`var`关键字，在定义的同时可以进行初始化。

定义在函数中的变量称为局部变量，只能在该函数范围内使用。直接在`script`元素中定义的变量称为全局变量，可以在任何地方使用，包括在其他脚本中。

```html
<!DOCTYPE HTML>
<html>
    <head>
        <title>Example</title>
    </head>
    <body>
        <script type="text/javascript">
            var myGlobalVar = "apples";
            function myFunc(name) {
                var myLocalVar = "sunny";
                return ("Hello " + name + ". Today is " + myLocalVar + ".");
            };
            document.writeln(myFunc("Adam"));
        </script>
        <script type="text/javascript">
            document.writeln("I like " + myGlobalVar);
        </script>
    </body>
</html>
```

上例的输出效果如下：

```
Hello Adam. Today is sunny. I like apples
```

JavaScript根据赋给变量的值确定其类型，还可以根据使用场景在类型间自由转换。



## 2. 使用基本类型

- **字符串类型**

`string`类型的值可以用一对单引号(`''`)或一对双引号(`""`)来表示，需要注意的是，前后的引号要匹配，即不能在字符串的一端使用单引号，另一端使用双引号。

- **布尔类型**

布尔类型有两个值：`true`和`false`。

- **数值类型**

整数和浮点数都用数值类型来表示，在定义时不必写出具体是哪种数值，只需要写出需要的值即可，JavaScript会酌情处理。



## 3. 创建对象

JavaScript支持对象的概念。

有多种方法可以用来创建对象:

- **调用new Object()**

```html
<!DOCTYPE HTML>
<html>
    <head>
        <title>Example</title>
    </head>
    <body>
        <script type="text/javascript">
            var myData = new Object();
            myData.name = "Adam";
            myData.weather = "sunny";
            
            document.writeln("Hello " + myData.name + ". ");
            document.writeln("Today is " + myData.weather + ".");
        </script>
    </body>
</html>
```

使用`new Object()`创建的对象本身并没有属性，当执行`myData.name`和`myData.weather`这两条语句之后就有了这两个属性。

- **使用对象字面量**

```html
<!DOCTYPE HTML>
<html>
    <head>
        <title>Example</title>
    </head>
    <body>
        <script type="text/javascript">
            var myData = {
                name: "Adam",
                weather: "sunny"
            };
            
            document.writeln("Hello " + myData.name + ". ");
            document.writeln("Today is " + myData.weather + ".");
        </script>
    </body>
</html>
```

用对象字面量的方式可以一口气定义一个对象及其属性。其中属性的名称和值之间用冒号(`:`)分隔，而各个属性之间又以逗号(`,`)分隔。

- **将函数用做方法**

可以往对象中添加属性，也可以添加函数，添加在对象中的函数叫做**方法**。

使用这个方法时，不需要函数名，但需要一个方法名，其用法是`方法名: function(形参列表) {语句}`，调用时按照以下方法调用：`对象名.方法名(实参列表);`。

在方法内部使用对象属性时要用到`this`关键字，用来代表当前这个对象。

```html
<!DOCTYPE HTML>
<html>
    <head>
        <title>Example</title>
    </head>
    <body>
        <script type="text/javascript">
            var myData = {
                name: "Adam",
                weather: "sunny",
                printMessages: function() {
                    document.writeln("Hello " + this.name + ". ");
                    document.writeln("Today is " + this.weather + ".");
                }
            };
            
            myData.printMessages();
        </script>
    </body>
</html>
```

上例的输出结果如下所示：

```
Hello Adam. Today is sunny.
```



## 4. 使用对象

- **读取和修改属性值**

读取和修改属性值则涉及到访问属性，JavaScript中访问一个对象的属性有两种方法：

1. 点操作符：`对象.属性`，如`myData.name`
2. 中括号：`对象["属性"]`，如`myData["weather"]`

- **枚举对象属性**

通过`for...in`语句可以枚举对象的属性。

1. 基本语法：

   ```javascript
   for(var 循环控制变量名 in 对象名) {
       循环控制体；
   }
   ```

   每次循环，`循环控制变量`的就被赋值为对象中的一个属性名（字符串格式），包括方法。

2. 例：

   ```javascript
   var myData = {
       name: "Adam",
       weather: "sunny",
       printMessage: function() {
           document.writeln("Hello " + this.name + ". ");
           document.writeln("Today is " + this.weather + ".");
       }
   };
   
   for(var prop in myData) {
       document.writeln("Name: " + prop + " Value: " + myData[prop] + "<br />");
   }
   ```

   该程序的输出结果如下：

   ```
   Name: name Value: Adam
   Name: weather Value: sunny
   Name: printMessages Value: function() { document.writeln("Hello " + this.name + ". "); document.writeln("Today is " + this.weather + "."); }
   ```

- **增删属性和方法**

就算使用对象字面量生成的对象，也可以为其定义新属性或方法或者删除已有的属性或方法。

1. 添加新属性

   ```javascript
   var myData = {
       name: "Adam",
       weather: "sunny",
   };
   
   myData.dataOfWeek = "Monday"; // 添加dataOfWeek属性
   ```

2. 添加新方法
   ```javascript
   var myData = {
       name: "Adam",
       weather: "sunny",
   };
   
   myData.sayHello = function() {	// 添加sayHello方法
       document.writeln("Hello");
   };
   ```

3. 删除属性或方法

   通过`delete`关键字可以删除对象中的属性或方法

   ```javascript
   var myData = {
       name: "Adam",
       weather: "sunny",
       sayHello: function() {
           document.writeln("Hello");
       }
   };
   
   delete myData.name;
   delete myData["weather"];
   delete myData.sayHello;
   ```

4. 判断对象是否具有某个属性
   可以用`in`表达式判断对象是否具有某个属性，表达式返回的值为一个布尔值，若为`true`，则表示表达式成立，否则不成立。

   ```javascript
   var myData = {
       name: "Adam",
       weather: "sunny",
   };
   
   var hasName = "name" in myData;		// 判断name是否是对象myData的一个属性，并将返回结果赋值给hasName
   var hasDate = "date" in myData;
   
   document.writeln("HasName: " + hasName);
   document.writeln("HasDate: " + hasDate);
   ```



# 五. 运算符

## 1. 前言

JavaScript定义了大量的标准运算符，以下是这些运算符的表格：

| 运算符                  | 说明                           |
| ----------------------- | ------------------------------ |
| `++`、`--`              | 前置或后置自增和自减           |
| `+`、`-`、`*`、`/`、`=` | 加、减、乘、除、求余           |
| `<`、`<=`、`>`、`>=`    | 小于、小于等于、大于、大于等于 |
| `==`、`!=`              | 相等和不相等                   |
| `===`、`!==`            | 等同和不等同                   |
| `&&`、&#124;&#124;      | 逻辑与、逻辑或                 |
| `=`                     | 赋值                           |
| `+`                     | 字符串连接                     |
| `?:`                    | 三元条件语句                   |

其中大部分与其他编程语言的运算符效果是相同的，就不再多赘述了。



## 2. 相等和等同运算符

- 相等运算符会将两个操作数转换为同一类型进行比较，如数字5和字符"5"，如果使用相等运算符，其结果将为`true`。
- 等同运算符则不会对操作数类型进行转换，上一个例子的结果将为`false`

**注意**：JavaScript中基本类型的比较是值的比较，而对象的比较则是引用的比较。如果一个对象是按照另一个对象的样式手动进行建立，那么二者不论是相等性测试还是等同性测试其结果都为`false`；如果一个对象是另一个对象的copy，那么二者的相等性测试和等同性测试则都为`true`。

```javascript
var myData1 = {
    name: "Adam",
    weather: "sunny",
};

var myData2 = {
    name: "Adam",
    weather: "sunny",
};

var myData3 = myData2;

var test1 = myData1 == myData2;
var test2 = myData2 == myData3;
var test3 = myData1 === myData2;
var test4 = myData2 === myData3;

document.writeln("Test 1: " + test1 + " Test 2: " + test2);
document.writeln("Test 3: " + test3 + " Test 4: " + test4);
```

这段脚本的输出效果如下所示：

```
Test 1: false Test 2: true
Test 3: false Test 4: true
```



## 3. 显式类型转换

假设有以下的表达式：`5+"5"`。

如果本意是想计算两个数字的和，但实际上得到的值是55，即JavaScript自动将前面的数字转换成了字符，而不是将后面的字符视为数字。

如果想要让JavaScript将字符视为数字，就需要用到显式类型转换，当然，还有其他的一些需要转换的形式：

- **将数值转换为字符串**

将数值转换为字符串有两种方法：

1. 使用`toString`方法：`num类型.toString()`，其返回值即为数字类型的字符串格式，需要注意的是，此方法为`num`类型的方法，如果想将字面值转换为字符串，则需要在字面值外面添加一层括号先将字面值转换为`num`类型值，如：`(5).toString()`。
2. 调用`String`函数：`String(num)`，其操作是将参数转换为String类型并返回，此时的参数可以是字面值，也可以是num类型值。
3. 其他方法

| 方法             | 说明                                                         | 返回   |
| ---------------- | ------------------------------------------------------------ | ------ |
| toString()       | 以十进制形式表示数值                                         | 字符串 |
| toString(2)      | 以二进制形式表示数值                                         | 字符串 |
| toString(8)      | 以八进制形式表示数值                                         | 字符串 |
| toString(16)     | 以十六进制形式表示数值                                       | 字符串 |
| toFixed(n)       | 以小数点后有n位数字的形式表示实数                            | 字符串 |
| toExponential(n) | 以指数表示法表示数值。尾数的小数点前后分别有1位数字和n位数字 | 字符串 |
| toPrecision(n)   | 用n位有效数字表示数值，在必要的情况下使用指数表示法          | 字符串 |

- **将字符串转换为数值**

1. 使用`Number`函数：`Number(str)`，将参数的字符串转换为数值，但要求参数的字符串不能包含其他字符
2. 使用`parseInt`函数：`parseInt(str)`，将参数的字符串转换为整数值，参数字符串可以包含其他字符，函数对其进行忽略。
3. 使用`parseFloat`函数：`parseFloat(str)`，将参数的字符串转换为一个整数或实数值，参数字符串可以包含其他字符。



# 六. 使用数组

## 1. 创建数组

通过调用`new Array()`可以创建一个新的数组，创建结果是一个空数组。

```javascript
var myArray = new Array();
myArray[0] = 100;
myArray[1] = "Adam";
myArray[2] = true;
```

**注意**：

- 创建数组的时候不需要声明数组中元素的个数。使用声明即可向数组内添加数据。
- 不必声明数组所含元素的类型，JavaScript数组可以混合包含各种类型的数据。



## 2. 使用数组字面量

使用数组字面量，可以在一条语句中创建和填充数组：

```javascript
var myArray = [100, "Adam", true];
```

此例通过在一对方括号之间指定所需数组元素的方式创建了一个新数组，并将其赋给变量`myArray`。



## 3. 读取和修改数组内容

- 读取：通过下标读取，下标从0开始
- 修改：直接向用下标访问的元素赋值即可修改数组元素的值



## 4. 枚举数组内容

通过`for`循环可以枚举数组内容

- 基本语法：

  ```javascript
  for(var 循环控制变量 = 初始值; i < 数组名.length; i++) {
      循环体;
  }
  ```

  其语法与其他语言的`for`循环语法基本相同，不多做解释。其中数组的长度可以用一个数组对象的`length`方法得到

- 例：

  ```javascript
  var myArray = [100, "Adam", true];
  for(var i = 0; i< myArray.length; i++) {
      document.writeln("Index " + i + ": " + myArray[i]);
  }
  ```



## 5. 使用内置的数组方法

JavaScript中的Array对象定义了许多方法，以下是一些常用的方法：

| 方法                    | 说明                                                         | 返回   |
| ----------------------- | ------------------------------------------------------------ | ------ |
| `concat(<otherArray>)`  | 将数组和参数所指数组的内容合并为一个新数组。可指定多个数组   | 数组   |
| `join(<separator>)`     | 将所有数组元素连接为一个字符串。各元素内容用参数指定的字符分隔 | 字符串 |
| `pop()`                 | 把数组当做栈使用，删除并返回数组的最后一个元素               | 对象   |
| `push(<item>)`          | 把数组当做栈使用，将指定的数据添加到数组中                   | void   |
| `reverse()`             | 就地反转数组元素的次序                                       | 数组   |
| `shift()`               | 类似`pop`，但操作的是数组的第一个元素                        | 对象   |
| `slice(<start>, <end>)` | 返回一个子数组                                               | 数组   |
| `sort()`                | 就地对数组元素排序                                           | 数组   |
| `unshift(<item>)`       | 类似`push`，但新元素被插到数组的开头位置                     | void   |



# 七. 处理错误

## 1. try语句

JavaScript使用`try...catch`语句处理错误，其基本语法如下：

```javascript
try {
    语句;
} catch(任意名字) {
    语句;
} finally {
    语句
}
```

- 程序将可能会引发错误的代码包含在`try`语句块中
- 如果没有引发错误，那么程序将跳过后面的`catch`和`finally`子句；如果`try`语句块中的代码引发的错误，那么程序将会用一些内置的错误信息对`catch`子句后的括号内的变量名称进行初始化，该变量被定义为一个`Error`对象。在`catch`子句中，可以使用`Error`对象的一些属性来显示错误。
- `finally`字句为可选，其效果是如果发生了错误，那么在执行完前两个子句之后，将执行`finally`子句，一般用来从错误中恢复或在错误发生后进行一些清理工作的机会。



## 2. Error对象的属性

| 属性    | 说明                           | 返回   |
| ------- | ------------------------------ | ------ |
| message | 对错误条件的说明               | 字符串 |
| name    | 错误的名称，默认为Error        | 字符串 |
| number  | 该错误的错误代号（如果有的话） | 数值   |



# 八. undefined和null值

## 1. 前言

JavaScript中有两个特殊值：undefined和null。

- `undefined`：当程序读取未赋值的变量或试图读取对象没有的属性时得到的就是`undefined`值
- `null`：是一个值，如果用`null`给变量或对象的属性赋值之后，那么该变量或该对象的属性将不再是`undefined`值，但是也没有任何有意义的值，其值即为`null`



## 2. 检查是否为undefined或null

如果只想检查一个变量或属性是否包含于以上两种，并不对二者进行区分，可以使用`if`语句和逻辑非运算符`!`进行判定：

```javascript
if(!变量名) {
    语句;
}
if(!对象名.属性名) {
    语句;
}
```

若某变量或某对象的某属性为`undefined`或`null`，那么将进入对应的`if`语句并执行，若不为以上两种中的任何一种，那么将不会进入对应的`if`语句。



## 3. 区分null和undefined

可以使用等同运算符(`===`)判断。能做的只有通过待判断变量或属性与值为`null`的变量进行等同性比较，若二者相等，则可以确定待判断变量的值为`null`而不是`undefined`。

要判断某变量是否为`undefined`，只有通过先判断是否属于二者中的一种，然后再通过区分`null`的方法来排除为`null`的可能。
