#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *array;
    int capacity;
    int size;
    int cur_pos;
} arrayList;

void increase_capacity(arrayList *list)
{
    int temp = list->capacity;
    list->capacity *= 2;
    list->array = (int *)realloc(list->array, list->capacity * sizeof(int));
    printf("Capacity increased from %d to %d\n", temp, list->capacity);
}

void decrease_capacity(arrayList *list)
{
    if (list->capacity <= 2)
        return;

    int temp = list->capacity;
    list->capacity /= 2;
    if (list->capacity < 2)
        list->capacity = 2;

    list->array = (int *)realloc(list->array, list->capacity * sizeof(int));
    printf("Capacity decreased from %d to %d\n", temp, list->capacity);
}

void init(arrayList *list)
{
    list->capacity = 2;
    list->size = 0;
    list->cur_pos = 0;
    list->array = (int *)malloc(2 * sizeof(int));
}

void free_list(arrayList *list)
{
    free(list->array);
}

void print(arrayList *list)
{
    if (list->size == 0)
    {
        printf("[ . ]\n");
        return;
    }
    printf("[");
    for (int i = 0; i < list->size; i++)
    {
        if (i+1 == list->cur_pos)
            printf(" %d|", list->array[i]);
        else
            printf(" %d", list->array[i]);
    }
    printf(" ]\n");
}

void insert(int item, arrayList *list)
{
    if (list->size + 1 > list->capacity / 2)
        increase_capacity(list);

    for (int i = list->size; i > list->cur_pos; i--)
        list->array[i] = list->array[i - 1];

    list->array[list->cur_pos] = item;
    list->size++;
    list->cur_pos++; 
}

int delete_cur(arrayList *list)
{
    if (list->size == 0 || list->cur_pos == 0)
        return -1;

    int idx = list->cur_pos - 1;
    int deleting_elem = list->array[idx];

    for (int i = idx; i < list->size - 1; i++)
        list->array[i] = list->array[i + 1];

    list->size--;

   
    if (idx == list->size)
    {
      
        list->cur_pos--;
    }
    
    if (list->cur_pos < 0)
        list->cur_pos = 0;
    if (list->cur_pos > list->size)
        list->cur_pos = list->size;

    if (list->size < list->capacity / 4)
        decrease_capacity(list);

    return deleting_elem;
}

void append(int item, arrayList *list)
{
    if (list->size + 1 > list->capacity / 2)
        increase_capacity(list);

    list->array[list->size++] = item;
    if (list->size == 1)
        list->cur_pos = 1; 
}

int size(arrayList *list)
{
    return list->size;
}

void prev(int n, arrayList *list)
{
    list->cur_pos -= n;
    if (list->cur_pos < 0)
        list->cur_pos = 0;
}

void next(int n, arrayList *list)
{
    list->cur_pos += n;
    if (list->cur_pos > list->size)
        list->cur_pos = list->size;
}

int is_present(int n, arrayList *list)
{
    for (int i = 0; i < list->size; i++)
        if (list->array[i] == n)
            return 1;
    return 0;
}

void clear(arrayList *list)
{
    free(list->array);
    init(list);
}

int delete_item(int item, arrayList* list)
{
    int idx = -1;

    for (int i = 0; i < list->size; i++)
    {
        if (list->array[i] == item)
        {
            idx = i;
            break;
        }
    }

    if (idx == -1)
    {
        printf("%d not found\n", item);
        return 0;
    }

    int barValueIdx = list->cur_pos - 1;

    for (int i = idx; i < list->size - 1; i++)
        list->array[i] = list->array[i + 1];

    list->size--;

    if (idx <= barValueIdx)
        list->cur_pos--;

    if (list->cur_pos < 0) list->cur_pos = 0;
    if (list->cur_pos > list->size) list->cur_pos = list->size;

    if (list->size < list->capacity / 4)
        decrease_capacity(list);

    return 1;
}

void swap_ind(int ind1, int ind2, arrayList *list)
{
    if (ind1 < 0 || ind2 < 0 || ind1 >= list->size || ind2 >= list->size)
        return;

    int temp = list->array[ind1];
    list->array[ind1] = list->array[ind2];
    list->array[ind2] = temp;
}

int search(int item, arrayList *list)
{
    for (int i = 0; i < list->size; i++)
        if (list->array[i] == item)
            return i;
    return -1;
}

int find(int ind, arrayList *list)
{
    if (ind < 0 || ind >= list->size)
        return -1;

    list->cur_pos = ind;
    return list->array[ind];
}

int update(int ind, int value, arrayList *list)
{
    if (ind < 0 || ind >= list->size)
        return -1;

    int temp = list->array[ind];
    list->array[ind] = value;
    list->cur_pos = ind+1;
    return temp;
}

int trim(arrayList *list)
{
    if (list->size == 0)
        return -1;

    int val = list->array[list->size - 1];
    list->size--;

    if (list->cur_pos > list->size)
        list->cur_pos = list->size;

    if (list->size < list->capacity / 4)
        decrease_capacity(list);

    return val;
}

void reverse(arrayList *list)
{
    int start = 0, end = list->size - 1;
    while (start < end)
    {
        int temp = list->array[start];
        list->array[start] = list->array[end];
        list->array[end] = temp;
        start++;
        end--;
    }
}
