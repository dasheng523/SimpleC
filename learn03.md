### scanf的用法
````
void scanfDemo()
{
  float lat;
  float lng;
  char info[80];
  if (scanf("%f, %f, %79[^\n]", &lat, &lng, info) == 3) {
    printf("%s\n", "读完了");
  }
}
````

### 重定向
````
< 表示将标准输入重定向。
> 表示将标准输出重定向。
````
`fprintf()`函数可以将文本发送到标准输出和标准错误中。
````
void fprintfDemo()
{
  fprintf(stderr, "%s\n", "标准错误");
  fprintf(stdout, "%s\n", "标准输出");
}
````

### 连接
符号 | 表示管道（pipe），它能连接一个进程的标准输出和另一个进程的标准输入
````
(./bermuda | ./geo2json) < spooky.csv >output.json
````

### 创建自己的数据流
如果fopen打开失败，返回0，所以用这个做一些安全检查。
r 读， w写，a追加
````
FILE *in_file = fopen("input.txt", "r");
FILE *out_file = fopen("output.txt", "w");

fprintf(out_file, "写入文件");

//读一行,返回读取数据的条数，比如这里只有一个变量就返回1.
fscanf(in_file, "&79[^\n]\n", scentence);  

fclose(out_file);
fclose(in_file);
````

### 关于main函数
main函数有两种形式，第二种如下：
````
int main(int argc, char *argv[])
argv[0] 是运行程序的名字。
argv[1] 是第一个参数，以此类推。
argc 是数组元素的个数。
````

### 设计小工具时，应遵循以下原则
1. 从标准输入读取数据；
2. 在标准输出显示数据；
3. 处理文本数据，而不是难以阅读的二进制格式；
4. 只做一件简单的事；

### 处理小工具的参数问题
可以使用 unistd.h 库，这个不是C标准库，而是posix库的一员，posix目标是创建一套所有操作系统都能用的函数。
如何处理参数呢？ 比如 `rocket_to -e 4 -a Brasillia Tokyo London`.
````
#include <unistd.h>
...
while ((ch = getopt(argc, argv, "ae:")) != EOF) {
  switch (ch) {
    case 'e' :
      engine_count = optarg;
  }
  ...
}
//需要跳过所有选项
argc -= optind;
argv += optind;
````
argv[0] 就开始是参数了。
getopt()可以合并选项，可以改变选项的顺序，选项必须出现在参数之前，避免歧义可以用--隔开参数和选项。
