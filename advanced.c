#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Advanced.h"

//全局变量定义在.c文件中
int gAll=6;

/*18、const指针和数组*/
void Pointer_Array() {
    //1、const指针和指针所指的变量是const
    int x = 5;

    //指针是const，指针的值不能改变。不能对p进行赋值操作
    int *const p = &x;

    //指针指向的是常量,r和a都可以进行赋值，但是*r不能进行赋值，即：不能*r=5。等价于第三种
    int const *q = &x;

    //指针指向的是常量,r和a都可以进行赋值，但是*r不能进行赋值，即：不能*r=5。等价于第二种
    const int *r = &x;

    //2、const数组,表示不能对数组内的值进行修改
    const int a[] = {1, 2, 3, 4, 5};
}

/*19、指针运算*/
void PointerCalculate() {
    //指针初始化时，使用NULL
    int *r = NULL;

    //指针加减
    int a[] = {1, 2, 3, 4, 5, -1};
    int *p = a;
    printf("p=%p,p+1=%p\n", p, p + 1);

    //*p++运算，汇编指令对应的语句
    while (*p != -1) {
        printf("%d,", *p++);
    }
    printf("\n");
    //指针的比较

    //void *q,指向不确定的指针
    void *q;
    q = p;

    //动态内存分配,注意，使用完成后释放
    int n = 10;
    int *b = (int *) malloc(n * sizeof(int));
    printf("b:%lu", sizeof(b));
    free(b);//一定要释放
}

/*20、字符串操作*/
void StrOperation() {
    //int putchar(int para)函数
    //int getchar(void)
    int ch1=getchar();
    putchar(ch1);
    printf("\n");
    putchar('1');
    printf("\n");
    putchar(50);
    printf("\n");

    int ch2;
    while ((ch2 = getchar()) != EOF) {
        putchar(ch2);
    }
}

/*21、字符串数组*/
void StrArray() {
    char *a[] = {
            "January",
            "Febrary",
            "March",
    };

    char line[] = "Hello";
    //1、strlen 返回字符串的长度
    printf("strlen=%lu\n", strlen(line));

    //2、strcmp比较字符串
    //返回值为0，表示相等；

    //3、strcpy字符串拷贝
    //strcpy(char *restrict dst,const char *restrict src)
    //restrict关键字，表示dst和src的内存不能有重叠

    //4、字符串搜索strchr和strrchr
    //举例，找第二个
    char s[] = "hello";
    char *p = strchr(s, 'l');
    printf("找第一个l的结果：%s\n", p);
    p = strchr(p + 1, 'l');
    printf("找第二个l的结果：%s\n", p);

    //拷贝找到的部分到新的字符串中变量中
    char *q = (char *) malloc(strlen(p) + 1);
    strcpy(q, p);
    printf("拷贝结果：%s\n", q);
    free(q);

    //拷贝剩余结果
    *p = 0;
    char *r = (char *) malloc(strlen(s) - strlen(p) + 1);
    strcpy(r, s);
    printf("拷贝剩余部分的结果：%s\n", r);

    *p = 'l';
    printf("最终的s：%s", s);

    //5、字符串中查找字符串
    //strstr和strcasestr(忽略大小写)
}

/*22、结构体，其实就是自己定义的数据类型（原有数据类型的组合）*/
void TestStruct() {
    //结构体变量
    Date today = {.day=26, .month=04, .year=1992};

    //结构体指针
    Pointer_Date pd = &today;
    pd->year=1993;
    printf("%d,%d",today.year,pd->year);

    //结构体数组
    Date times[10]={{.day=01,.month=03,.year=2019}};

    //

}

/*23、联合*/
void TestUnion(){
    CHI chi;
    chi.i=1234;
    for (int i = 0; i < sizeof(int); ++i) {
        printf("%02hhx",chi.ch[i]);
    }
}

/*24、链表*/
void TestList(){
    Node *p=(Node *)malloc(sizeof(int));
    free(p);
}

/*25、函数指针*/
