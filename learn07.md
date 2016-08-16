# 高阶函数
本章将学习如何把函数作为参数传递，提高代码的智商，并学会用比较器函数排序，最后还将学会使用可变参数函数让代码伸缩自如。

## 函数指针
- 函数名其实也是指针变量。
- C语言中没有函数类型。因为函数有不同的返回类型，形参列表。

### 创建函数指针
需要把返回类型和参数类型告诉编译器。
````
int go_to_warp_speed(int speed) //一个函数的定义
int (*warp_fn)(int);  //创建一个叫warp_fn的函数类型
warp_fn = go_to_warp_speed;
warp_fn(4);

char** album_names(char *artist, int year)
char** (*names_fn)(char*, int);
name_fn = album_names;
name_fn("adsf", 1988);
````
char** 是一个指针，通常用来指向字符串数组。

### 排序
#### 排序函数的定义：
````
qsort(void *array,  //这是一个数组指针
  size_t length,    //这是数组长度
  size_t item_size, //这是数组中每个元素的长度
  int (*compar)(const void *, const void *));   //比较器
````
void* 指针可以保持任何类型的指针。但使用指针前需要转换具体类型。

#### 使用
````
int compare_scores(const void* score_a, const void* score_b)
{
  int a = *(int*)score_a;
  int b = *(int*)score_b;
  return a -b;
}
int scores[] = [1, 45, 788, 44, 3];
qsort(scores, 7, sizeof(int), conpare_scores);
````

### 函数指针数组
函数指针数组让代码易于管理，让代码变得更短，更易扩展。例如处理switch之类的代码。
````
void (*replies[]) (response) = {dump, second_chance, marriage};
````
需要指定函数返回类型以及参数类型。


## 可变参数函数
````
#include <stdarg.h>
void print_ints(int args, ...)
{
  va_list ap;
  va_start(ap, args);
  int i;
  for (i = 0; i < args; i++) {
    printf("%i\n", va_arg(ap, int));
  }
  va_end(ap);
}
````
