#include <stdio.h>
#include "skeleton_arrayList.h"

int main()
{
    FILE *file = fopen("in.txt", "r");
    if (file == NULL)
        return 1;

    arrayList list;
    init(&list);

    int func, param, param2;
    while (fscanf(file, "%d", &func) == 1 && func != 0)
    {
        if (func == 1 && fscanf(file, "%d", &param) == 1)
        {
            printf("Insert %d\n", param);
            insert(param, &list);
            print(&list);
        }
        else if (func == 2)
        {
            printf("Delete current item\n");
            int ret = delete_cur(&list);
            if (ret >= 0)
            {
                print(&list);
                printf("%d is deleted\n\n", ret);
            }
            else
                printf("List is empty\n");
        }
        else if (func == 3 && fscanf(file, "%d", &param) == 1)
        {
            printf("Append %d\n", param);
            append(param, &list);
            print(&list);
        }
        else if (func == 4)
        {
            printf("Size of the list is %d\n\n", size(&list));
        }
        else if (func == 5 && fscanf(file, "%d", &param) == 1)
        {
            printf("Prev %d\n", param);
            prev(param, &list);
            print(&list);
        }
        else if (func == 6 && fscanf(file, "%d", &param) == 1)
        {
            printf("Next %d\n", param);
            next(param, &list);
            print(&list);
        }
        else if (func == 7 && fscanf(file, "%d", &param) == 1)
        {
            if (is_present(param, &list))
                printf("%d is present\n\n", param);
            else
                printf("%d is not present\n\n", param);
        }
        else if (func == 8)
        {
            printf("Clear list\n");
            clear(&list);
            print(&list);
        }
        else if (func == 9 && fscanf(file, "%d", &param) == 1)
        {
            printf("Delete %d\n", param);
            if (delete_item(param, &list))
                print(&list);
            else
                printf("%d not found\n", param);
        }
        else if (func == 10 && fscanf(file, "%d %d", &param, &param2) == 2)
        {
            printf("Swap index %d and %d\n", param, param2);
            swap_ind(param, param2, &list);
            print(&list);
        }
        else if (func == 11 && fscanf(file, "%d", &param) == 1)
        {
            printf("Search %d\n", param);
            int ret = search(param, &list);
            if (ret != -1)
                printf("%d is found at %d\n\n", param, ret);
            else
                printf("%d is not found\n\n", param);
        }
        else if (func == 12 && fscanf(file, "%d", &param) == 1)
        {
            printf("Find %d\n", param);
            int ret = find(param, &list);
            if (ret != -1)
            {
                print(&list);
                printf("%d is found at %d\n\n", ret, param);
            }
            else
                printf("%d is not a valid index\n\n", param);
        }
        else if (func == 13 && fscanf(file, "%d %d", &param, &param2) == 2)
        {
            printf("Update element at %d\n", param);
            int ret = update(param, param2, &list);
            if (ret != -1)
            {
                print(&list);
                printf("%d is updated by %d\n", ret, param2);
            }
            else
                printf("%d is not a valid index\n\n", param);
        }
        else if (func == 14)
        {
            printf("Trim\n");
            int ret = trim(&list);
            if (ret != -1)
            {
                print(&list);
                printf("%d removed\n\n", ret);
            }
        }
        else if (func == 15)
        {
            printf("Reverse\n");
            reverse(&list);
            print(&list);
        }
        else if (func == 16)
        {
            printf("Reverse in range: \n");
            reverse_range(&list, 3);
            print(&list);
        }
    }
    free_list(&list);
    fclose(file);
    return 0;
}