# 静态库与动态库

## <>
如果在#include语句中使用尖括号，编译器会在标准头文件目录中查找头文件，而不是当前目录。
为了用本地头文件编译程序，需要把尖括号换成双引号。

标准头文件一般在以下目录找：
linux:
````
/usr/local/include
/usr/include
````
windows MinGW
````
c:\MinGW\include
````

## 共享.h头文件
在多个C项目中共享头文件的方法有很多：
1. 把头文件保存在标准目录中；
2. 在include语句中使用完整路径名； `#inlcude "/myfiles/encrypt.h"`
3. 直接告诉编译器去哪里找头文件，使用-I选项； `gcc -I/myfiles test_code.c ... -o test_code`

## 用完整路径名共享.o目标文件
````
gcc -I/myfiles test_code.c /myfiles/encrypt.o -o test_code
````

## 存档
用存档可以将多个`.o`文件打包起来。
用nm命令可以查看存档里面的文件，如：
````
nm libl.a
````
用`ar`命令创建存档
````
ar -rcs libhfsecurity.a encrypt.o checksum.o
````
- r 表示如果.a文件存在就更新它。
- c 表示创建存档时不显示反馈信息。
- s 告诉ar要在.a文件开头建立索引。
- 静态库要以lib开头。

编译程序
````
如果将.a文件放在标准库中
gcc test_code.c -llibhfsecurity -o test_code
如果将.a文件放在自定义库中
gcc test_code.c -L/mylib -llibhfsecurity -o test_code
````

使用nm命令查看模块时，可以看到很多名字，如果以T开头的，说明它是一个函数。
