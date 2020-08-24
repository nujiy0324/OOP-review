## My answer

* Write the output of the following code.

1. ```
   In function Max, 2
   In template function Max, 2.0
   In template function Max, 2.0
   ```

2. ```
   97	194  297
   97	48.5  33
   
   ```

3. ```
   call A(int ii=0).
   call A(int ii=0).
   call B(int ii=0).
   A::i = 2
   A::i = 0
   B::i = 2
   call A(int ii=0).
   call B(const B&).
   A::i = 2
   A::i = 0
   B::i = 2
   
```
   
4. ```
   A()
   Generating an exception object, name is ex_obj1
   catch exception
   A()
   Generating an exception object, name is ex_obj1
   catch exception
   destory an exception object, name is ex_obj1
   destory an exception object, name is ex_obj1
   ~A()
   ~A()
   ```

5. ```
   A() 1
   B() 2
   A() 1
   C()
   
   ```

6. ```
   Parent(int ii)
   Member(int ii)
   Child(int ii)
   //不知道在执行copy assignment操作符的时候会不会调用copy construct function？
   Parent: 0
   Member: 0
   Child: 2
   ```

* Correct the following programs

  1. ```c++
     pp = new char [strlen(p)+1]; strcpy(pp,p); delete [] p;  
     ```

  2. 是不是要交换catch的顺序啊？

* Fill the blanks

  ```c++
  #include <iostream>           
  #include <cmath>              
  using namespace std;
  #define PI 3.14159            
  class Shape {                 
  private:  
      int ID;
      static int counter;
  public:
      Shape():ID(counter++) {}
      int objectID() const { return ID; }
      virtual void error() const ;  
      virtual double area() = 0;
      static int getcounter() { return counter; }
  };
  ____(1)_____
  /* Default error handling function provided by base class Shape, to display default code for error.*/
  ____(2)_____
  
  class Ellipse: public Shape
  {
  private:
      int lax,sax;
      static int counter;
  public:
      Ellipse(int l,int s): ____(3)_____
      {
          if (lax!=sax) counter++;
      }
      ____(4)_____
       /* Ellipse class to handle errors */
      ____(5)_____
      static int getcounter() { return counter; }
  };
  ____(6)_____
  
  class Circle: public Ellipse 
  {
  public:
      Circle(int r): ____(7)_____
      {
          ____(8)_____
      } 
      static int getcounter() { return counter; }
      ____(9)_____ 
       /* The Circle class does not want to make any special behavior for the error */
      ____(10)_____
  private:
      static int counter;
  };
  ____(11)_____
  
  class Rectangle: public Shape
  {
  protected:
      int width,length;
      static int counter;
  public:
      Rectangle(int w,int l): ____(12)_____
      {
          ____(13)_____;
      }
      ____(14)_____
      /* Rectangle class to handle errors */
      ____(15)_____
      static int getcounter() { return counter; }
  };
  ____(16)_____
  
  class Square: public Rectangle 
  {
  public:
      Square(int r): ____(17)_____
      {
          ____(18)_____;
      }
      ____(19)_____
      /* The Square class does not want to make any special behavior for the error */
      ____(20)_____
      static int getcounter() { return counter; }
  private:
      static int counter;
  };
  ____(21)_____;
  class Triangle: public Shape 
  {
      int a,b,c;
      static int counter;
  public:
      Triangle(int a, int b, int c): ____(22)_____
      {
          counter++;
      }
      ____(23)_____
     /* Rectangle class to handle errors */
      ____(24)_____
      static int getcounter() { return counter; }
  };
  ____(25)_____;
  
  int main ()                                  
  {
      Shape *list[6] = { 
          new Ellipse(2,4), new Circle(3), 
          new Rectangle(3,5), new Square(4), 
          new Triangle(1,2,2),new Ellipse(1,3)}; 
      for (int i=0; i<6; i++) {
          cout << list[i]->area() << '\n';
          list[i]->error();
      }
      cout << Ellipse::getcounter() << endl;  //output: 2
      cout << Circle::getcounter() << endl;  //output: 1
      cout << Rectangle::getcounter() << endl;  //output: 1
      cout << Square::getcounter() << endl;   //output: 1
      cout << Triangle::getcounter() << endl;   //output: 1
  
  ```

  

* Program design