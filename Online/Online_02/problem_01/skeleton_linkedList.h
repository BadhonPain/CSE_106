#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int element;
    struct node *next;
    struct node *prev;
} node;

typedef struct
{
    node *head;
    node *tail;
    int cur;
    int size;
} linkedList;

void init(linkedList *list)
{
    list->head = NULL;
    list->tail = NULL;
    list->cur = 0;
    list->size = 0;
}

node *createNode(int item)
{
    node *newNode = (node *)malloc(sizeof(node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->element = item;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

node *traversal_ptr(linkedList *list, int index)
{
    node *temp = list->head;
    for (int i = 0; i < index && temp; i++)
        temp = temp->next;
    return temp;
}
void free_list(linkedList *list)
{
    node *current = list->head;
    node *temp;
    while (current != NULL)
    {
        temp = current->next;
        free(current);
        current = temp;
    }
    init(list);
}

void print(linkedList *list)
{
    if (list->size == 0)
    {
        printf("[ . ]\n");
        return;
    }

    printf("[");
    node *temp = list->head;
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

void insert(int item, linkedList *list)
{
    node *newNode = createNode(item);
    if (list->size == 0)
    {
        list->head = list->tail = newNode;
    }
    else if (list->cur == 0)
    {
        newNode->next = list->head;
        list->head->prev = newNode;
        list->head = newNode;
    }
    else if (list->cur == list->size)
    {
        newNode->prev = list->tail;
        list->tail->next = newNode;
        list->tail = newNode;
    }
    else
    {
        node *right = traversal_ptr(list, list->cur);
        node *left = right->prev;

        left->next = newNode;
        newNode->prev = left;
        newNode->next = right;
        right->prev = newNode;
    }

    list->size++;
    list->cur++;
}

int delete_cur(linkedList *list)
{
    if (list->size == 0 || list->cur == 0)
        return -1;

    int idx = list->cur - 1;
    node *target = traversal_ptr(list, idx);
    int deleted = target->element;

    node *left = target->prev;
    node *right = target->next;

    if (left)
        left->next = right;
    else
        list->head = right;

    if (right)
        right->prev = left;
    else
        list->tail = left;

    free(target);
    list->size--;

    if (idx == list->size)
        list->cur--;

    return deleted;
}

void append(int item, linkedList *list)
{
    node *newNode = createNode(item);

    if (list->size == 0)
    {
        list->head = list->tail = newNode;
        list->cur = 1;
    }
    else
    {
        list->tail->next = newNode;
        list->tail = newNode;
    }

    list->size++;
}

int size(linkedList *list)
{
    return list->size;
}

void prev(int n, linkedList *list)
{
    list->cur -= n;
    if (list->cur < 1)
        list->cur = 1;
}

void next(int n, linkedList *list)
{
    list->cur += n;
    if (list->cur > list->size)
        list->cur = list->size;
}

int is_present(int n, linkedList *list)
{
    node *temp = list->head;
    while (temp)
    {
        if (temp->element == n)
            return 1;
        temp = temp->next;
    }
    return 0;
}

void clear(linkedList *list)
{
    free_list(list);
}

int search(int item, linkedList *list)
{
    node *temp = list->head;
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

int delete_item(int item, linkedList *list)
{
    int idx = search(item, list);

    if (idx == -1)
        return 0;

    int temp = list->cur;
    list->cur = idx + 1;
    delete_cur(list);

    if (temp != list->size + 1)
    {
        if (temp > idx + 1)
            list->cur = temp - 1;
        else
            list->cur = (temp > list->size) ? list->size : temp;
    }

    if (list->cur < 0)
        list->cur = 0;

    return 1;
}
void swap_ind(int ind1, int ind2, linkedList *list)
{
    if (ind1 < 0 || ind2 < 0 || ind1 >= list->size || ind2 >= list->size)
        return;

    if (ind1 == ind2)
        return;

    node *n1 = traversal_ptr(list, ind1);
    node *n2 = traversal_ptr(list, ind2);

    int tmp = n1->element;
    n1->element = n2->element;
    n2->element = tmp;
}

int find(int ind, linkedList *list)
{
    if (ind < 0 || ind >= list->size)
        return -1;

    node *n = traversal_ptr(list, ind);
    list->cur = ind + 1;
    return n->element;
}

int update(int ind, int value, linkedList *list)
{
    if (ind < 0 || ind >= list->size)
        return -1;

    node *n = traversal_ptr(list, ind);
    int temp = n->element;
    n->element = value;

    list->cur = ind + 1;
    return temp;
}

int trim(linkedList *list)
{
    if (list->size == 0)
        return -1;

    int val = list->tail->element;
    node *temp = list->tail;

    list->tail = temp->prev;
    if (list->tail)
        list->tail->next = NULL;
    else
        list->head = NULL;

    free(temp);
    list->size--;

    if (list->cur > list->size)
        list->cur = list->size;

    return val;
}

void reverse(linkedList *list)
{
    node *cur = list->head;
    node *temp = NULL;

    while (cur)
    {
        temp = cur->prev;
        cur->prev = cur->next;
        cur->next = temp;
        cur = cur->prev;
    }

    temp = list->head;
    list->head = list->tail;
    list->tail = temp;
}

node *reverseKGroups(node *head, int k)
{
    node *current = head;
    for (int i = 0; i < k; i++)
    {
        if (current == NULL)
            return head;
        current = current->next;
    }
    node *newHead = reverseKGroups(current, k);

    current = head;
    node *prev = NULL;
    node *nxt = NULL;

    for (int i = 0; i < k; i++)
    {
        nxt = current->next;
        current->next = prev;
        current->prev = nxt;
        prev = current;
        current = nxt;
    }

    head->next = newHead;
    if (newHead != NULL)
        newHead->prev = head;
    return prev;
}

void reverse_range(linkedList *list, int k)
{
    if (k <= 1 || list->size <= 1)
        return;

    list->head = reverseKGroups(list->head, k);

    node *currrent = list->head;
    while (currrent != NULL || currrent->next != NULL)
    {
        currrent = currrent->next;
    }

    list->tail = currrent;
}
