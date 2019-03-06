#ifndef C_LEARNING_MYARRAY_H
#define C_LEARNING_MYARRAY_H

typedef struct array {
    int *array;
    int size;
} Array;

//Array a;

Array array_creat(int init_size);

void array_free(Array *a);

int array_size(const Array *a);

int *array_at(Array *a, int index);

void array_inflate(Array *a, int more_size);

#endif //C_LEARNING_MYARRAY_H
