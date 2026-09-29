#include <stdio.h>
#include <stdlib.h>
#include "array.h"

// prints all array values 
void outputarray(Array *array)
{
    for (int i = 0; i < array->size; i++)
    {
        printf("%f ", array->data[i]);
    }
    printf("\n");
}

// moves all the values left and first value to end, and makes a new array
void shiftarray(Array *array)
{
    double temp = array->data[0];

    for (int i = 0; i < array->size - 1; i++)
    {
        array->data[i] = array->data[i + 1];
    }
    array->data[array->size - 1] = temp;
}

Array *averageadjacent(Array *array)
{
    Array *newarray = malloc(sizeof(Array));
    newarray->size = array->size / 2;
    newarray->data = malloc(newarray->size * sizeof(double));

    for (int i = 0; i < newarray->size; i++)
    {
        newarray->data[i] = (array->data[2 * i] + array->data[2 * i + 1]) / 2.0;
    }
    return newarray;
}

int main(int arcount, char *arvector[])
{
    if (arcount != 2)
    {
        printf("Enter a size.\n");
        return 1;
    }

// converts string inputs to int, with a check
    int convertinput;
    sscanf(arvector[1], "%d", &convertinput);

    if (convertinput <= 0)
    {
        printf("size must be more than 0\n");
        return 1;
    }

// allocate array mem, and fills array with input
    Array *array = malloc(sizeof(Array));

    array->size = convertinput;
    array->data = malloc(convertinput * sizeof(double));

    for (int i = 0; i < convertinput; i++)
    {
        array->data[i] = i + 1;
    }

    outputarray(array);
    shiftarray(array);
    outputarray(array);

    Array *averagedarray = averageadjacent(array);
    outputarray(averagedarray);

// free all dedicated mem
    free(array->data);
    free(array);

    free(averagedarray->data);
    free(averagedarray);

    return 0;
}
