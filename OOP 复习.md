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

```





