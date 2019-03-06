#include <stdlib.h>
#include "MyArray.h"

/*创建一个结构体返回
 * 结构体内包含一个int指针用来指向数组，size表示数组的大小*/
Array array_creat(int init_size) {
    Array a;
    a.size=init_size;
    a.array=(int*)malloc(sizeof(int)*init_size);
    return a;
}

/*释放结构体的array指向的内存
 * 对应creat内的malloc函数*/

void array_free(Array *a) {
    free(a->array);
    a->size=0;
    a->array=NULL;
}

/*把a的大小封装起来*/
int array_size(const Array *a) {
    return a->size;
}

//返回index位置数组的指针
int *array_at(Array *a, int index) {
    int *res;

    if (index>=array_size(a)){
        res=NULL;
    }
    else{
        res=&(a->array[index]);
    }

    return res;
}

/*数组的自增*/
void array_inflate(Array *a, int more_size) {
    int count=(array_size(a)+more_size);//计算新的大小

    //赋值原数组的值到新的数组
    int *p=(int *)malloc(count* sizeof(int));
    for (int i = 0; i < array_size(a); ++i) {
        p[i]==a->array[i];
    }

    free(a->array);//释放原本内存空间

    //更新结构体成员
    a->array=p;
    a->size=array_size(a)+more_size;
}
