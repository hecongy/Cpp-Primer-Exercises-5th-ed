[练习5.1](#)

>什么是空语句？什么时候会用到空语句？

    空语句是指含有一个单独的分号的语句，当语法上需要一条语句但逻辑上不需要时使用

[练习5.2](#)

>什么时块？什么时候会用到块？

    块是指用花括号括起来的（可能为空的）语句和声明的序列，当语法上需要一条语句但逻辑上需要多条语句时使用

[练习5.3](#)

>使用逗号运算符（参见4.10节，第140页）重写1.4.1节（第10页）的while循环，使它不再需要块，观察改写之后的代码的可读性提高了还是降低了。

    可读性降低

```cpp
//原程序
while (val <= 10) {
    sum += val;
    ++val;
}

//改写
while (val <= 10)
    sum += val, ++val;
```

[练习5.4](#)

>说明下列例子的含义，如果存在问题，试着修改它。  
(a) while (string::iterator iter != s.end()) { /* ... \*/ }  
(b) while (bool status = find(word)) { /* ... \*/ }  
        if (!status) { /* ... \*/}
        
    (a) iter未初始化，修改：
        string::iterator iter = s.begin();
        while (iter != s.end()) { /* ... \*/ }  
    (b) status的作用域在while中，所以if中不能使用status，修改：
        bool status;
        while (status = find(word)) { /* ... */ }  
            if (!status) { /* ... */}
