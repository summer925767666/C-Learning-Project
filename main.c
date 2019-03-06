#include <stdio.h>
#include "Base.h"
#include "Advanced.h"
#include "MyArray.h"

#define PI 3.141592653 //宏定义
#define PI2 PI*2 //宏定义的嵌套
#define FORMAT "%f\n"
#define PRT printf(FORMAT,PI); \
            printf(FORMAT,PI2)  //'\'表示换行
#define _DEBUG //没有值的宏，用于条件编译
//编译器预定义好的宏
//__LINE__ __FILE__ __DATE__ __TIME__

//类函数宏,带参数的宏
//函数和参数都需要有括号
//末尾不能加分号
#define cube(x) (x*x*x)



int main() {
    PRT;
    printf("%s:%d\n",__FILE__,__LINE__);
    printf("%s,%s\n",__DATE__,__TIME__);
    printf("%d\n",cube(5));
    printf("%d\n",gAll);

    return 0;
}
