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
 
typedef        char *         Pchar; // pointer to char
typedef const Pchar          CPchar; // const pointer to char
typedef const  char *        PCchar; // pointer to const char
typedef       Pchar *        PPchar; // pointer to pointer to char
typedef const  char * const CPCchar; // const pointer to const char
typedef      PCchar *       PPCchar; // pointer to pointer to const char
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

### 头文件

头文件中只能存在变量或者函数声明。（不能放定义，对于一个函数即便是相同的定义，出现两次也是illegal。）(且变量应该 extern，而不能直接声明)

以下为特例：

* const或者static对象的定义，因为只在当前文件有效。
* inline的定义（内联函数不会链接，直接展开）
* class的定义

**综上所述，头文件中能包含：**

- 类成员数据的声明，但不能赋值
- 类静态数据成员的定义和赋值，但不建议，只是个声明就好。
- 类的成员函数的声明
- 非类成员函数的声明
- 常数的定义。（如：const int a=5;）
- 静态函数的定义
- 类的内联函数的定义

不能包含：

- 所有非静态变量（不是类的数据成员）的声明
- 默认命名空间声明不要放在头文件，using namespace std;等应放在.cpp中，在 .h 文件中使用 std::string

### 成员变量

### 访问属性

* 在类的内部（类的声明和类的定义）可以访问public、protected、private所有成员
* 在类的外部（对象和其他函数）不能访问private和protected成员

三种不同的派生方式：

1. public：
   public ->public;
   protected->protected;
   private->不可访问;
2. protected:
   public->protected;
   protected->protected;
   private->不可访问;
3. private:
   public->private;
   protected->private;
   private->不可访问;

***friend 友元***：在对象中声明，可以访问private和protected成员  ***友元关系不能被继承***

```c++
/*Instance*/
#include <iostream>
using namespace std;

class Address;  //提前声明Address类

//声明Student类
class Student{
public:
    Student(char *name, int age, float score);
public:
    void show(Address *addr);
private:
    char *m_name;
    int m_age;
    float m_score;
};

//声明Address类
class Address{
private:
    char *m_province;  //省份
    char *m_city;  //城市
    char *m_district;  //区（市区）
public:
    Address(char *province, char *city, char *district);
    //将Student类中的成员函数show()声明为友元函数
    friend void Student::show(Address *addr);
};

//实现Student类
Student::Student(char *name, int age, float score): m_name(name), m_age(age), m_score(score){ }
void Student::show(Address *addr){
    cout<<m_name<<"的年龄是 "<<m_age<<"，成绩是 "<<m_score<<endl;
    cout<<"家庭住址："<<addr->m_province<<"省"<<addr->m_city<<"市"<<addr->m_district<<"区"<<endl;
}

//实现Address类
Address::Address(char *province, char *city, char *district){
    m_province = province;
    m_city = city;
    m_district = district;
}

int main(){
    Student stu("小明", 16, 95.5f);
    Address addr("陕西", "西安", "雁塔");
    stu.show(&addr);
   
    Student *pstu = new Student("李磊", 16, 80.5);
    Address *paddr = new Address("河北", "衡水", "桃城");
    pstu -> show(paddr);

    return 0;
}
```

### 静态成员

​	按照以前的理解，静态成员就是不需要实例化就能够访问的成员，非静态成员即为需要实例化才能访问的。

​	静态成员也遵循public等访问规则。

1. 静态成员变量
   1. 优势在于数据隐藏，比如private
   2. 不和全局变量的名称冲突
2. 静态成员函数
   1. 没有this指针，所以无法访问类对象中的非静态数据成员

## namespace

```c++
:: //作用域
/*如果想在类的外部引用静态成员函数，或在类的外部定义成员函数都要用到。使用命名空间里的类型或函数也要用到*/
```

## 函数

![image-20200822163527306](..\OOP-review\pic\image-20200822163527306.png)

### 默认参数

```c++
/*Instance*/
void Func(int i = 1, float f = 2.0f, double d = 3.0){}
```

***如果某个参数是默认参数，那么它后面的参数必须都是默认参数***

***默认参数可以放在函数声明或者定义中，但只能放在二者之一***，一般情况放在声明中，头文件中

### 内联函数

* inline关键字必须与定义放在一起，只放在声明前面是不起到任何作用的
* 内联函数必须简单，不能包含复杂结构控制语句（while，switch），且不能是递归函数

## 继承

![image-20200822165929356](..\OOP-review\pic\image-20200822165929356.png)

## 多态

![image-20200823162103456](..\OOP-review\pic\image-20200823162103456.png)

## 拷贝构造

```c++
classname (const classname &obj);
```

### 拷贝时机

1. 对象以值传递的方式传入函数参数
2. 对象以值传递的方式从函数返回
3. 用另一个对象进行初始化

### 拷贝构造的写法

似乎就是开辟空间，然后拷贝就完了？

## 运算符重载

![image-20200823171435095](..\OOP-review\pic\image-20200823171435095.png)

### 基本原则

1. 只能使用成员函数重载的运算符有：=、()、[]、->、new、delete
2. 单目运算符最好重载为成员函数
3. 对于复合的赋值运算符如+=、-=、*=、/=、&=、!=、~=、%=、>>=、<<=建议重载为成员函数
4. 对于其它运算符，建议重载为友元函数

### 重载的方式

无非是一种作为成员函数重载，还有一种是作为全局函数重载，不过作为全局函数重载需要friend（用友元进行引入）

### 类型转换

```c++
class Integer
{
public:
    Integer(int v);
    Integer& opetaror =(const int &v); //重载赋值操作符，可以做到 Integer i = 10;//把i当基本数据类型使用
    operator int(); //重载类型转换操作符，可以做到int i; Integer it;  i = it; //it直接转为int类型，然后赋值给i
 
private:
    int data;
};
Integer::Integer(int v)
{
    data = v;
}
 
/*!
 *@brief 重载赋值操作符，可以做到 Integer i = 10;//把i当基本数据类型使用
 */
Integer& Integer::opetaror =(const int &v)
{
    data = v;
    return *this;
}
 
/*!
 *@brief 重载类型转换操作符，可以做到int i; Integer it;  i = it; //it直接转为int类型，然后赋值给i
 */
Integer::operator int()
{
    return data;
}
 
#include <iostream>
using namespace std;
 
int main()
{
    Integer integer1(10); //调用构造函数进行初始化
    Integer integer2;
    int i1 = 10;
    integer2 = i1; //调用=赋值操作符进行赋值
 
    //下面测试类型转换操作符的应用
    int i2;
    i2 = integer1; //integer1是Integer类型，这里直接把Integer类型转换为int，然后赋值给i2
                          //如果没有重载了int()，需要类型转换的话，这里必须写成 i2 = (int)integer1;
    return 0;
}
```

## 模板

![image-20200823174429592](..\OOP-review\pic\image-20200823174429592.png)

*模板是泛型编程的基础，泛型编程即以一种独立于任何特定类型的方式编写代码。*

### 模板的声明

#### 函数模板

```c++
/*scheme*/
template <typename type> ret-type func-name(parameter list);
/*instance*/
template <typename T>
inline T const& Max (T const& a, T const& b) 
{ 
    return a < b ? b:a; 
} 
int main ()
{
    int i = 39;
    int j = 20;
    cout << "Max(i, j): " << Max(i, j) << endl; 
    double f1 = 13.5; 
    double f2 = 20.7; 
    cout << "Max(f1, f2): " << Max(f1, f2) << endl; 
    string s1 = "Hello"; 
    string s2 = "World"; 
    cout << "Max(s1, s2): " << Max(s1, s2) << endl; 
   return 0;
}
```

#### 类模板

```c++
/*scheme*/
template <class type> class class-name{}
/*instance*/
template <class T>
class Stack { 
  private: 
    vector<T> elems;     // 元素 
  public: 
    void push(T const&);  // 入栈
    void pop();               // 出栈
    T top() const;            // 返回栈顶元素
    bool empty() const{       // 如果为空则返回真。
        return elems.empty(); 
    } 
}; 
 
template <class T>
void Stack<T>::push (T const& elem) 
{ 
    // 追加传入元素的副本
    elems.push_back(elem);    
} 
 
template <class T>
void Stack<T>::pop () 
{ 
    if (elems.empty()) { 
        throw out_of_range("Stack<>::pop(): empty stack"); 
    }
    // 删除最后一个元素
    elems.pop_back();         
} 
 
template <class T>
T Stack<T>::top () const 
{ 
    if (elems.empty()) { 
        throw out_of_range("Stack<>::top(): empty stack"); 
    }
    // 返回最后一个元素的副本 
    return elems.back();      
} 
 
int main() 
{ 
    try { 
        Stack<int> intStack;  // int 类型的栈 
        Stack<string> stringStack;    // string 类型的栈 
 
        // 操作 int 类型的栈 
        intStack.push(7); 
        cout << intStack.top() <<endl; 
 
        // 操作 string 类型的栈 
        stringStack.push("hello"); 
        cout << stringStack.top() << std::endl; 
        stringStack.pop(); 
        stringStack.pop(); 
    } 
    catch (exception const& ex) { 
        cerr << "Exception: " << ex.what() <<endl; 
        return -1;
    } 
}
```

### 模板实例化

* 显式实例化
* 隐式实例化

## 异常

![image-20200823180507344](..\OOP-review\pic\image-20200823180507344.png)

*异常是程序在执行期间产生的问题。C++ 异常是指在程序运行时发生的特殊情况，比如尝试除以零的操作。*

### 异常的抛出

* throw关键字

### 异常的捕捉

```c++
try
{
    //保护代码
}catch(ExceptionName e1)
{
 	//catch块   
}catch(ExceptionName e2)
{
    //catch块
}catch(...)
{
    //这个表示该catch块可以处理任何类型的异常
}
```

```c++
/*instance*/
double division(int a, int b)
{
   if( b == 0 )
      throw "Division by zero condition!";
   return (a/b);
}
//以下为在主函数中
try {
     z = division(x, y);
     cout << z << endl;
   }catch (const char* msg) {
     cerr << msg << endl;
   }
```

![C++ 异常的层次结构](..\OOP-review\pic\exceptions_in_cpp.png)、

![image-20200823182948284](..\OOP-review\pic\image-20200823182948284.png)

## 绑定







