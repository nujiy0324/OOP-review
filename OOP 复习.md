# OOP 复习

## 引言

### cin & cout

用endl时会刷新缓冲区，使得栈中的东西刷新一次，但用“\n”不会刷新，它只会换行，栈内数据没有变化。cout << endl;除了往输出流中插入一个'\n'，还有刷新输出流的作用。

```c++
cout <<endl; /*等价于*/cout<< '\n' << flush;
```

## 使用对象

![image-20200821110500909](.\pic\image-20200821110500909.png)

## string class

 * 构造函数

   ```c++
   string s1();  // si = ""
   string s2("Hello");  // s2 = "Hello"
   string s3(4, 'K');  // s3 = "KKKK"
   string s4("12345", 1, 3);  //s4 = "234"，即 "12345" 的从下标 1 开始，长度为 3 的子串
   ```

 * 常用函数

   ```c++
   string str;
   str.assign(); //赋值函数
   str.length(); str.size(); //
   str.append();//在后面添加内容，而且会“真”添加，并非运算
   	str.insert(int,/*string OR int,char*/)
   str.compare();//小于 0 表示当前的字符串小,等于0说明一样，大于零反之
   str.substr();
   str.swap(/*using class string*/);
   ```

### 储存模式

* 堆，由**new动态分配**的内存块，他们的释放由程序员控制，所以一个new对应一个delete。如果程序员没有自己释放内存块，那么程序结束后，操作系统会自动回收。
*  栈，在**函数内部局部变量**都可以在栈尚创建，函数执行结束后，局部变量自动释放。栈内存分配运算内置于处理器的指令集中，效率高，但分配的内存容量有限。
* 自由存储区，由**malloc等**分配的内存块，和堆相似，不过有free释放。
* 全局/静态存储区，**全局变量和静态变量**被分配到同一块内存中。在以前的C语言中，全局变量又分为初始化和未初始化变量，在C++中不在对其进行区分，他们共同占用一块内存区。

### 通过指针调用函数

```c++
int (*p) (int, int);  //normal form
int fun(int x,int y); //如此的声明语句，fun本身就是函数指针。
/*举例*/
int main()
{
	int sum(int x,int y);
	int (*p) (int, int);
	p = sum;
	int a = 2, b = 3;
	cout<<p(a,b);
}
int sum(int x, int y)
{return x+y;}
```

### 动态内存申请

* 申请的内存在堆中

```c++
new Data-Type;
/*example 1*/
double* p = NULL;
p = new double;//如果内存空间被分配完，则new会返回空指针
delete p;
/*example 2*/
char* p_str = NULL:
p_str = new char[20];
delete [] p_str;
/*example 3*/
int **array;//第一维长度为m，第二维长度为n
array = new int *[m];
for( int i=0; i<m; i++ )
{array[i] = new int [n];}
//release
for( int i=0; i<m; i++ )
{delete [] array[i];}
delete [] array;
```

### 引用

*绑定暂时先放下，应该分为动态绑定和静态绑定两种。*

```c++
//instance
int ival = 1; 
int & refval = ival;
int func (int &a, int &b); //引用传递，参数a，b都是引用，即实参的别名，对a，b的修改即为对实参的修改

```

###  常量

```c++
int b = 500;
const int* a = &b; 			//[1]
int const *a = &b;			//[2]
int* const a = &b;			//[3]
const int* const a = &b;     //[4]
 
typedef        char *         Pchar; // pointer to char
typedef const Pchar          CPchar; // const pointer to char
typedef const  char *        PCchar; // pointer to const char
typedef       Pchar *        PPchar; // pointer to pointer to char
typedef const  char * const CPCchar; // const pointer to const char
typedef      PCchar *       PPCchar; // pointer to pointer to const char
```

1. 如果const位于星号的左侧，则const就是用来修饰指针所指向的变量，即指针指向为常量。
2. 如果const位于星号的右侧，const就是修饰指针本身，即指针本身是常量。因此，[1]和[2]的情况相同，都是指针所指向的内容为常量（const放在变量声明符的位置无关），这种情况下不允许对内容进行更改操作，如不能*a = 3 。
3. [3]为指针本身是常量，而指针所指向的内容不是常量，这种情况下不能对指针本身进行更改操作，如a++是错误的。
4. [4]为指针本身和指向的内容均为常量。

***左常量右指针***

## **定义类**

![image-20200821135428310](..\OOP-review\pic\image-20200821135428310.png)

### 封装

- 对于虚函数，子类可以（也可以不）重新定义基类的虚函数，该行为称之为复写Override。（virtual 关键字实现）
- 对于纯虚函数，子类必须提供纯虚函数的个性化实现。（虚函数后加“=0”）

### 类和对象的关系

Object is the abstraction of objective things, and class is the abstraction of objects. Class is an abstract data type.

Object is an instance of class, and class is a scheme of object. 

Definition & Declaration 定义是完全描述，声明是声明存在。





