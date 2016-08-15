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

//赋值
snappy.name = 68;

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
- 调用函数的时候，变量复制到形参。如果要改变变量的值，需要传指针。
- `(*)` 用在指针前，可以得到指针指向的值。 如`(*t).age`。
- 可以使用 `t->age` 代替 `(*t).age`。


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

## 联合
联合与结构的区别在于，联合的容量是由其中一个容量最大的成员决定的。而结构体的容量是成员的容量总和。

### 定义
````
typedef union {
  short count;
  float weight;
  float volume;
} quantity;
````

### 赋值方式
C89方式
````
quantity q = {4};
````
指定初始化器
````
quantity q = {.weight=1.5};
````
点表示法
````
quantity q;
q.volume = 3.7;
````

### 说明
- 联合常和结构一起用


## 枚举
有时不想保存数字和文本，而是想保存一组符号，就可以使用枚举。

### 使用
````
enum colors {RED, GREEN, PUCE};
enum colors favorite = PUCE;
````


## 二进制位
如果一个结构中很多表示是否的值，可以使用位字段。

### 使用
````
typedef struct {
  unsigned int low_pass_vcf:1;    表示该字段只用1位存储空间。
} synth;
````

## 小提示
1. C语言不支持二进制字面值，但支持16进制的字面值。
2. 结构把数据类型组合在一起。
3. 可以用点表示法读取结构中的字段。
4. 可以用typedef为数据类型创建别名。
5. 可以像初始化数组那样初始化结构。
6. 有了->表示法，就能用结构指针更新字段，十分方便。
7. 可以用指定初始化按名设置结构或联合的字段。
8. 联合可以在同一个存储器单元中保存不同的数据类型。
9. 可以用枚举创建一组符号。
10. 可以用位字段控制结构中的某些位。
