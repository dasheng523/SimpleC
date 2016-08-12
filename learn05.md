# 结构、联合与位字段

## 用结构创建结构化数据类型
````
//定义
struct fish {
  const char *name;
  const char *species;
  int teeth;
  int age;
  struct preferences care //内嵌结构体
}

//赋值
struct fish snappy = {"Snappy", "Piranha", 69, 4, {"Meat", 7.5}};

//取值
printf("Name = %s\n", snappy.name);
printf("Name = %s\n", snappy.care.food);

//函数参数
void catalog(struct fish f)

````
### const
const 是将变量定义成静态变量，不可变的变量。

### 数组
上面的 `char *name` 其实是保存数组的指针，如果想要保存字符串，定义成数组就可以了，类似：`char name[20]`。

### 说明
- 把参数封装在结构中，代码会更稳定。因为不需要修改函数的参数了。
- 切记，为结构变量赋值相当于叫计算机复制数据。
- 在C语言中，所有的赋值都会复制数据，如果想要复制数据的引用，就应该赋指针。

### 取别名
不管定义，还是使用结构体，都不得不加struct关键字很麻烦，可以使用别名。
````
typedef struct cell_phone {
  int cell_no;
  const char *wallpaper;
  ……
} phone;
phone p = {5566,……};
````
