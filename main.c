#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

//结构体类型定义
typedef struct {
    int amount;
    char *name;
} Dollar;

//函数声明
void Bool(void);

void Comma(void);

void RandGame(void);

void SplitInt(void);

void TestArray(void);

void TestType(int x);

void TestPointer(void);

void Swap(int *x, int *y);

void Array_2Dim(void);

void IniArr(void);

void TestStr(void);

void GetPoint(void);

void TestPoint(void);

void ChangeValue(int *p);

void PointerAndArray(void);

void TestPointerAndArray(int *a, int **b);

int main() {
//    Bool();
//    Comma();
//    RandGame();
//    SplitInt();
//    TestArray();
//    TestType(2.0);
//    TestPointer();
//    Array_2Dim();
//    IniArr();
//    TestStr();
//    GetPoint();
//    TestPoint();
//    PointerAndArray();
    return 0;
}

/*13、指针与数组
 * 数组变量是（特殊的，广义的，不完全相等）常量类型的指针变量,两点不同：
 *  1、sizeof()时返回的是整个数组的大小（而不是指针的大小）
 *  2、&取地址返回的是数组的第一个元素的位置（而不是a的存储位置，是否开辟内存保留意见）todo
 * 相互等价关系：数组可以使用*间接运算，指针也可以使用[]运算*/
void PointerAndArray() {
    //数组等指针相互的演示
    int a[10] = {2, 4, 6, 8};//等价于 const *a;
    int *b = a;//可以直接赋值给指针变量，反之不行，因为a是const类型
    printf("*a=%d,b[1]=%d\n", *a, b[1]);//相互运算使用

    //数组的大小就是数组占据的内存；64b编译环境下，指针类型的大小是8B
    printf("sizeof(a)=%lu,sizeof(b)=%lu\n", sizeof(a),sizeof(b));

    //无论是a还是&a，返回都是数组第一个元素的地址
    printf("a=%p,&a=%p\n",a,&a);
    //而b返回的是b指向的地址，&b返回的是存储b变量的内存地址
    printf("b=%p,&b=%p\n",b,&b);

    TestPointerAndArray(a, &b);
}
/*注意：在参数表里的数组，等价于指针变量
 * 非常量类型，sizeof（）和&操作都与普通指针相同*/
void TestPointerAndArray(int *a, int **b) {//参数表里的数组，完全用指针代替了
    printf("a=%p,&a=%p",a,&a);
}

/*12、指针类型
 * “*”号和变量结合,表示*p是int类型的，而不是p是int*类型的 */
void TestPoint() {
    int x = 10;
    printf("former:%d\n", x);
    ChangeValue(&x);
    printf("later:%d\n", x);
}
void ChangeValue(int *p) {
    *p += 10;
}

/*11、取地址&运算符
 * 只能对变量取地址*/
void GetPoint() {
    //变量地址，相邻变量地址相邻，注意堆栈的分配
    int i = 0, j = 0;
    printf("%p,%p\n", &i, &j);

    //数组地址
    int a[10] = {0};
    printf("%p\n", &a);
    printf("%p\n", a);
    printf("%p\n", &a[0]);
    printf("%p\n", &a[1]);
}

/*10、字符指针表示字符串&&结构体*/
void TestStr() {
    //字符指针的使用
    char *s = "panny";

    //使用结构体定义数组
    Dollar coins[] = {
            {1,  "panny"},
            {5,  "nickel"},
            {10, "dime"},
            {25, "quarter"},
            {50, "half-dollar"}
    };
    Dollar d = {1, "panny"};
    printf("%d,%s", d.amount, d.name);
}

/*9、数组初始化
 * 数组不能直接赋值，arr1=arr2，数组是常量；只能使用循环赋值（唯一）*/
void IniArr() {
    int arr1[10] = {0};
    int arr2[10] = {[0]=5, [3]=5};
    for (int i = 0; i < sizeof(arr1) / sizeof(arr1[0]); ++i) {
        printf("%d,", arr1[i]);
    }
    for (int i = 0; i < sizeof(arr2) / sizeof(arr2[0]); ++i) {
        printf("%d,", arr2[i]);
    }

    printf("数组大小：%ld，int类型大小%ld,元素大小%ld", sizeof(arr1), sizeof(int), sizeof(arr1[0]));
}

/*8、二维数组
 * 不要写成arr[i,j]，有逗号表达式的歧义
 * 列数不能省略，行数可以省略*/
void Array_2Dim() {
    int arr[2][3];
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            arr[i][j] = i + j;
        }
    }
    for (int k = 0; k < 2; ++k) {
        for (int i = 0; i < 3; ++i) {
            printf("%d行%d列:%d,", k, i, arr[k][i]);
        }
        printf("\n");
    }
}

/*7、值传递
 * 逗号只是表示标点符号，不是逗号表达式*/
void TestPointer() {
    int a = 5, b = 6;
    printf("former:a=%d,b=%d\n", a, b);
    Swap(&a, &b);
    printf("later:a=%d,b=%d", a, b);
}

void Swap(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}

/*6、类型测试*/
void TestType(int x) {
    printf("%d", x);
}

/*5、测试数组*/
void TestArray() {
    int number[100];
//    number[200] = 20;
//    printf("%d", number[200]);
}

/*4、整数拆分*/
void SplitInt() {
    int x;
    int b = 1;
    int t;

    //获取整数
//    scanf("%d",&x);
    x = 1900;
    t = x;

    //获取整数最高位数的基数
    while (t >= 10) {
        t /= 10;
        b *= 10;
    }

    //正序按位输出整数
    while (b >= 1) {
        printf("%d", x / b);
        if (b >= 10) { printf("-"); }//不是最后一位的时候用空格分割
        x %= b;
        b /= 10;
    }
}

/*3、随机数-猜数游戏*/
void RandGame() {
    //产生一个随机数
    srand(time(0));//初始化随机数种子，产生真正的随机
    int temp = rand() % 100;//取两位随机数
    printf("想好了一个数\n");

    //读取用户输入，判断是否相等
    int x = 0;
    do {
        scanf("%d", &x);
        if (x > temp) {
            printf("大了\n");
        } else if (x < temp) {
            printf("小了\n");
        }
    } while (x != temp);

    //猜中
    printf("猜中了");
}

/*2、逗号表达式-连接两个表达式，值取后者的值*/
void Comma() {
    printf("%d", (1 + 2, 3 + 4));
}

/*1、bool测试-引入头文件stdbool.h*/
void Bool() {
    if (true) {
        printf("可以使用bool变量");
    }
}
