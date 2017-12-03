[练习2.1](#)

>类型int、long、long long和short的区别是什么？无符号类型和带符号类型的区别是什么？float和double的区别是什么？

int、long、long long和short都是带符号整数类型，区别在于它们的尺寸不同，可以表示的范围也不同，short->int->long->long long范围依次增大。  
float和double都是浮点类型，区别在于它们可表示的精度不同，double类型的精度比float类型的精度高。

[练习2.2](#)

>计算按揭贷款时，对于利率、本金和付款分别应选择何种数据类型？说明你的理由。

利率：float，利率的有效位数一般在float能表示的范围之内；  
本金和付款：double，因为double类型的精度更高，允许的有效数字位数更高。

[练习2.3](#)

>读程序写结果
unsigned u = 10, u2 = 42
