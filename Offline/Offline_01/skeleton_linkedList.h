#include <stdio.h>
#include <stdlib.h>

/* ---------- Node ---------- */
typedef struct node
{
    int element;
    struct node* next;
    struct node* prev;
} node;

/* ---------- Linked List ---------- */
typedef struct
{
    node* head;
    node* tail;
    int cur;    // cursor position (bar)
    int length;
} linkedList;

/* ---------- Helper ---------- */
node* getNodeAt(linkedList* list, int index)
{
    node* temp = list->head;
    for (int i = 0; i < index && temp; i++)
        temp = temp->next;
    return temp;
}

/* ---------- Core ---------- */
void init(linkedList* list)
{
    list->head = NULL;
    list->tail = NULL;
    list->cur = 0;
    list->length = 0;
}

void free_list(linkedList* list)
{
    node* temp = list->head;
    while (temp)
    {
        node* next = temp->next;
        free(temp);
        temp = next;
    }
    init(list);
}

/* ---------- Print ---------- */
void print(linkedList* list)
{
    if (list->length == 0)
    {
        printf("[ . ]\n");
        return;
    }

    printf("[");
    node* temp = list->head;
    int idx = 0;

    while (temp)
    {
        printf(" %d", temp->element);
        idx++;
        if (idx == list->cur)
            printf("|");
        temp = temp->next;
    }

    if (list->cur == 0)
        printf("|");

    printf(" ]\n");
}

/* ---------- Insert ---------- */
void insert(int item, linkedList* list)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->element = item;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (list->length == 0)
    {
        list->head = list->tail = newNode;
    }
    else if (list->cur == 0)
    {
        newNode->next = list->head;
        list->head->prev = newNode;
        list->head = newNode;
    }
    else if (list->cur == list->length)
    {
        newNode->prev = list->tail;
        list->tail->next = newNode;
        list->tail = newNode;
    }
    else
    {
        node* right = getNodeAt(list, list->cur);
        node* left = right->prev;

        left->next = newNode;
        newNode->prev = left;
        newNode->next = right;
        right->prev = newNode;
    }

    list->length++;
    list->cur++;   // cursor moves right
}

/* ---------- Delete Current ---------- */
int delete_cur(linkedList* list)
{
    if (list->length == 0 || list->cur == 0)
        return -1;

    int idx = list->cur - 1;
    node* target = getNodeAt(list, idx);
    int deleted = target->element;

    node* left = target->prev;
    node* right = target->next;

    if (left) left->next = right;
    else list->head = right;

    if (right) right->prev = left;
    else list->tail = left;

    free(target);
    list->length--;

    /* prefer right neighbor */
    if (idx == list->length)
        list->cur--;

    return deleted;
}

/* ---------- Append ---------- */
void append(int item, linkedList* list)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->element = item;
    newNode->next = NULL;
    newNode->prev = list->tail;

    if (list->length == 0)
    {
        list->head = list->tail = newNode;
        list->cur = 1;
    }
    else
    {
        list->tail->next = newNode;
        list->tail = newNode;
    }

    list->length++;
}

/* ---------- Size ---------- */
int size(linkedList* list)
{
    return list->length;
}

/* ---------- Cursor Movement ---------- */
void prev(int n, linkedList* list)
{
    list->cur -= n;
    if (list->cur < 1)
        list->cur = 1;
}

void next(int n, linkedList* list)
{
    list->cur += n;
    if (list->cur > list->length)
        list->cur = list->length;
}

/* ---------- Presence ---------- */
int is_present(int n, linkedList* list)
{
    node* temp = list->head;
    while (temp)
    {
        if (temp->element == n)
            return 1;
        temp = temp->next;
    }
    return 0;
}

/* ---------- Clear ---------- */
void clear(linkedList* list)
{
    free_list(list);
}

/* ---------- Delete Item ---------- */
int delete_item(int item, linkedList* list)
{
    node* temp = list->head;
    int idx = 0;

    while (temp)
    {
        if (temp->element == item)
            break;
        temp = temp->next;
        idx++;
    }

    if (!temp)
    {
        printf("%d not found\n", item);
        return 0;
    }

    int barValueIdx = list->cur - 1;

    node* left = temp->prev;
    node* right = temp->next;

    if (left) left->next = right;
    else list->head = right;

    if (right) right->prev = left;
    else list->tail = left;

    free(temp);
    list->length--;

    if (idx <= barValueIdx)
        list->cur--;

    if (list->cur < 0) list->cur = 0;
    if (list->cur > list->length) list->cur = list->length;

    return 1;
}

/* ---------- Swap ---------- */
void swap_ind(int ind1, int ind2, linkedList* list)
{
    if (ind1 < 0 || ind2 < 0 || ind1 >= list->length || ind2 >= list->length)
        return;

    if (ind1 == ind2) return;

    node* n1 = getNodeAt(list, ind1);
    node* n2 = getNodeAt(list, ind2);

    int tmp = n1->element;
    n1->element = n2->element;
    n2->element = tmp;
}

/* ---------- Search ---------- */
int search(int item, linkedList* list)
{
    node* temp = list->head;
    int idx = 0;
    while (temp)
    {
        if (temp->element == item)
            return idx;
        temp = temp->next;
        idx++;
    }
    return -1;
}

/* ---------- Find ---------- */
int find(int ind, linkedList* list)
{
    if (ind < 0 || ind >= list->length)
    {
        printf("%d is not a valid index\n", ind);
        return -1;
    }

    node* n = getNodeAt(list, ind);
    list->cur = ind + 1;
    print(list);
    return n->element;
}

/* ---------- Update ---------- */
int update(int ind, int value, linkedList* list)
{
    if (ind < 0 || ind >= list->length)
    {
        printf("%d is not a valid index\n", ind);
        return -1;
    }

    node* n = getNodeAt(list, ind);
    int old = n->element;
    n->element = value;

    list->cur = ind + 1;
    print(list);
    return old;
}

/* ---------- Trim ---------- */
int trim(linkedList* list)
{
    if (list->length == 0)
        return -1;

    int val = list->tail->element;
    node* temp = list->tail;

    list->tail = temp->prev;
    if (list->tail)
        list->tail->next = NULL;
    else
        list->head = NULL;

    free(temp);
    list->length--;

    if (list->cur > list->length)
        list->cur = list->length;

    return val;
}

/* ---------- Reverse ---------- */
void reverse(linkedList* list)
{
    node* curr = list->head;
    node* temp = NULL;

    while (curr)
    {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }

    temp = list->head;
    list->head = list->tail;
    list->tail = temp;

    /* DO NOT MODIFY list->cur */
}
