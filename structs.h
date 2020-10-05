
#ifndef COMPILERS_PRINCIPLES_STRUCTS_H
#define COMPILERS_PRINCIPLES_STRUCTS_H
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
using namespace  std;
struct critical_words{
    const int index = 1;
    critical_words(char string1[100],int row,int column){
        printf("%s (%d,%s) 关键字 (%d,%d)\n",string1,index,string1,row,column);
    }

};
struct identifier {
    const int  index = 6;
    identifier(char string1[100],int row,int column){
        printf("%s (%d,%s) 标识符 (%d,%d)\n",string1,index,string1,row,column);
    }
};

struct const_variable{
    const int  index = 5;
    const_variable(char string1[100],int row,int column){
       printf("%s (%d,%s) 常数 (%d,%d)\n",string1,index,string1,row,column);
    }
};

struct  division_operator{
    const int index = 2;
    division_operator(char string1,int row,int column){
        printf("%c (%d,%c) 分界符 (%d,%d)\n",string1,index,string1,row,column);
    }
};

struct arithmetical_operator{
    const int index = 3;
    string str[10] = {"+","-","*","/"};
    arithmetical_operator(char string1[100],int row,int column){
        printf("%s (%d,%s) 算数运算符 (%d,%d)\n",string1,index,string1,row,column);
    }
};

struct relation_operator{
    const int index = 4;
    relation_operator(char string[100],int row,int column){
        printf("%s (%d,%s) 关系运算符 (%d,%d)\n",string,index,string,row,column);
    }
    relation_operator(char string,int row,int column){
        printf("%c (%d,%c) 关系运算符 (%d,%d)\n",string,index,string,row,column);
    }
};

struct error{
    error(char string[100],int row,int column){
        printf("%s Error Error (%d,%d)\n",string,row,column);
    }
    error(char string,int row,int column){
        printf("%c Error Error (%d,%d)\n",string,row,column);
    }
};
#endif //COMPILERS_PRINCIPLES_STRUCTS_H
