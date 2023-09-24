#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct _List {
    int32_t* data;
    int32_t length;
};
typedef struct _List List;

List* resizeArray(List* array) {
    int32_t* dPtr = array->data;
    int32_t* newPtr = realloc(dPtr, 15 * sizeof(int32_t));

    if(!newPtr){
        printf("erro na alocacao de memoria!\n");
        free(dPtr);
        exit(EXIT_FAILURE);
    }
    else {
        array->data = newPtr;
    }

    return array;
}

int main() {
    List* array = calloc(1, sizeof(List));
    array->data = calloc(10, sizeof(int32_t));
    array = realloc(array, sizeof(*array));

    free(array->data);
    free(array);
    return 0;
}
