
#include <cstring>
#include "structs.h"
#include <iostream>
void number_judge(char buffer[], int, int);

void alphabet_judge(char buffer[], int column, int row);

bool compare(char buffer[100]);

bool relation_operator_judge(char buffer[100], int &i, int &column, int row);

bool arithmetical_operator_judge(char string[100], int *pInt, int& column, int row);

bool division_operator_judge(char string[100], int i, int column, int row);

using namespace std;

int main() {
    cout<<"单词 二元序列 类型 位置(行，列)"<<endl;
    char string1[100];
    char buffer[100] = {'\0'};
    int i = 0, j = 0;
    FILE *fp = fopen("/Users/anniezfy/CLionProjects/compilers principles/documentary.txt", "r");
    int row = 1;
    int k = 0;
    while (fgets(string1, 100, fp) != nullptr) {
        int len = strlen(string1);
        int column = 0;
        int flag = 1;
        int first, flaga = 1;
        i = 0;
        while (i < len) {
            first = i;
            if (( string1[first] >= '0' && string1[first] <= '9' )) { //常数
                while (( string1[i] != ' ' ) && ( string1[i] != '\n' )) {
                    buffer[k++] = string1[i++];
                }
                column++;
                number_judge(buffer, column, row);
                memset(buffer, 0, sizeof(buffer));
                k = 0;
            } else if (( string1[first] >= 'a' && string1[first] <= 'z' ) ||
                       ( string1[first] >= 'A' && string1[first] <= 'Z' )) { //标识符或者关键字
                while ((( string1[i] != ' ' ) && ( string1[i] != '\n' ) && ( string1[i] >= 'a' && string1[i] <= 'z' ) ||
                        ( string1[i] >= 'A' && string1[i] <= 'Z' ) || ( string1[i] >= '0' && string1[i] <= '9' ))) {
                    buffer[k++] = string1[i++];
                }
                column++;
                alphabet_judge(buffer, column, row);
                memset(buffer, 0, sizeof(buffer));
                k = 0;
            } else if (relation_operator_judge(string1 + first, i, column, row)) { //关系运算符
                k = 0;
                i++;
            } else if(arithmetical_operator_judge(string1+first,&i,column,row)){
                i++;
            }else if(division_operator_judge(string1+first,i,column,row)){
                i++;
            }else if (string1[i] == ' '||string1[i] == '\n') {
                i++;
            }else{
                struct error er(string1[i], row, column);
                i++;
            } 
        }
        row++;
    }
}

bool division_operator_judge(char *string, int i, int column, int row) {
    char str[6] = {',',';','(',')','[',']'};
    for(int i =0;i<6;i++){
        if(string[0]==str[i]){
            column++;
            struct division_operator do1(string[0],row,column);
            return true;
        }
    }
    return false;
}

bool arithmetical_operator_judge(char string[100], int *pInt, int &column, int row) {
    char str[4] = {'+','-','*','/'};
    for(int i = 0;i<4;i++){
        if((string[0]==str[i])&&string[1]>='0'&&string[1]<='9'){
            column++;
            struct arithmetical_operator ap(string,row,column);
            return true;
        }else if(string[0]==str[i]){
            (*pInt)++;
            column++;
            char new_str[3] = {string[0],string[1],'\0'};
            struct error er(new_str,row,column);
            return true;
        }
    }
    return false;
}


void alphabet_judge(char buffer[100], int column, int row) {
    if (compare(buffer)) {
        struct critical_words cw(buffer, row, column);
    } else {
        struct identifier id(buffer, row, column);
    }
}

bool compare(char buffer[100]) {  //用string的FIND函数试一下 ?
    char str[8][10] = {"do", "end", "for", "if", "printf", "scanf", "then", "while"};
    for (int i = 0; i < 8; i++) {
        if (!( strcmp(str[i], buffer))) { //字符串比较函数 相同为0；
            return 1;
        }
    }
    return 0;
}

void number_judge(char buffer[100], int column, int row) {
    int len = strlen(buffer);
    for (int i = 0; i < len; i++) {
        if (!( buffer[i] <= '9' && buffer[i] >= '0' )) {
            struct error er(buffer, row, column);
            return;
        }
    }
    struct const_variable cv(buffer, row, column);
}

bool relation_operator_judge(char buffer[100], int &i, int &column, int row) { //难点判断不等长的关系运算符 < 和 <=
    char str[3][3] = {"<=", ">=", "<>"};
    char char1[3] = {'<', '>', '='};
    char new_str[3] = {buffer[0], buffer[1], '\0'};
    for (int j = 0; j < 3; j++) {
        if (!( strcmp(str[j], new_str))) {
            i++;
            column++;
            struct relation_operator rp(new_str, row, column);
            return true;
        }
    }

    for (int j = 0; j < 3; j++) {
        if (char1[j] == buffer[0]) {
            column++;
            struct relation_operator rp(buffer[0], row, column);
            return true;
        }
    }
    return false;
}
