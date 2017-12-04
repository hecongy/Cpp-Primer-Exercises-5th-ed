[练习2.1](#)

>类型int、long、long long和short的区别是什么？无符号类型和带符号类型的区别是什么？float和double的区别是什么？

int、long、long long和short都是带符号整数类型，区别在于它们的尺寸不同，可以表示的范围也不同，short->int->long->long long范围依次增大。  
float和double都是浮点类型，区别在于它们可表示的精度不同，double类型的精度比float类型的精度高。

[练习2.2](#)

>计算按揭贷款时，对于利率、本金和付款分别应选择何种数据类型？说明你的理由。

利率：float，利率的有效位数一般在float能表示的范围之内；  
本金和付款：double，因为double类型的精度更高，允许的有效数字位数更高，而本金和付款可能具有多位有效数字。

[练习2.3](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch02/ex2_3.cpp)

>读程序写结果  
unsigned u = 10, u2 = 42;  
std::cout << u2 - u << std::endl;  
std::cout << u - u2 << std::endl;  
int i = 10, i2 = 42;  
std::cout << i2 - i << std::endl;  
std::cout << i - i2 << std::endl;  
std::cout << i - u << std::endl;  
std::cout << u - i << std::endl;

结果分别是30、4294967264、32、-32、0、0。  
无符号整数超出表示范围，值为取模后的余数（P33），所以第二个运算的结果是4294967264；  
当一个算术表达式中既有无符号数又有int值时，int会被转换成无符号数，所以最后两个运算的结果都是unsigned类型。

[练习2.4](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch02/ex2_3.cpp)

>编写程序检查你的估计是否正确，如果不正确，请仔细研读本节直到弄明白问题所在。

略

[练习2.3](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch02/ex2_3.cpp)
