#ifndef C_LEARNING_ADVANCED_H
#define C_LEARNING_ADVANCED_H

//在.h中声明
extern int gAll;

//枚举类型
enum colors {
    Red, Yellow, Green, NumColors,
};

//结构体类型定义
typedef struct date {
    int month;
    int day;
    int year;
} Date, *Pointer_Date;

//联合定义
typedef union chi {
    int i;
    char ch[sizeof(int)];
} CHI;

//链表结点
typedef struct node {
    int value;
    struct node *next;
} Node, *LinkList;

void TestUnion();

void Pointer_Array(void);

void PointerCalculate(void);

void StrOperation(void);

void StrArray(void);

void TestStruct(void);

void TestList(void);

#endif //C_LEARNING_ADVANCED_H
