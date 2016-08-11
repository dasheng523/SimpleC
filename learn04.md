# 使用多个源文件

## 数据类型

### 简明数据类型指南
- char 字符编码是一个数字。
- int 有16位，保存几万以内的数字。
- short 8位，保存几百，几千的数字。
- long 可以保存几十亿的数字，32位。
- float 浮点数
- double 精确浮点数，精确到小数点很多位。
- unsigned 只能是非负数。
- 可以在数据类型前加long，使它变长。

### 数据类型大小
- `limits.h` 含有表示整型大小的值
- `float.h` 含有表示float和double大小的值
- `INT_MAX` 表示int最大值
- `FLT_MAX` float
- `CHAR_MAX` char
- `DBL_MAX` double
- `SHRT_MAX` short
- `LNG_MAX` long
- `sizeof`返回类型的大小

### 声明与定义分离
- 如果编译器调用一个没见过的函数，会假设这函数返回int。
- .h文件用来声明一系列函数，不需要写实现。
- 引入头文件，使用`#include` 尖括号会去标准库所在的目录找，引号会去同文件目录找。
- 尖括号以绝对路径找头文件，引号以相对路径找头文件。

### 共享代码
- 可以把共享代码放在单独的C文件中；
- 需要把函数声明放到一个单独的.h头文件中；
- 所有需要使用的共享代码的C文件都包含这个头文件；
- 编译的命令列出所有的C文件；
eg: `gcc message_hider.c encrypt.c -o message_hider`
- `gcc -c *.c` 将所有源文件编译成目标文件；
- `gcc *.o -o launch` 将目标链接起来形成最终的程序;

### make
- make工具可以自动化代码的构建过程；
- make只编译那些修改过的文件；
- 需要makefile告诉make如果构建代码；
- 缩进要用tab，而不是空格！
- makefile:
````
launch.o: launch.c launch.h thruster.h
    gcc -c launch.c
thruster.o： thruster.h thruster.c
    gcc -c thruster.c
launch: launch.o thruster.o
    gcc launch.o thruster.o -o launch
````
- execute:
````
make launch
````



### 小提示：
遍历数组，可以使用下面的办法
````
while (*list) {
  int val = *list ;
  list++;
}
````
