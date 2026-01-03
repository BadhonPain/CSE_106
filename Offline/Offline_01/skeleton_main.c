#include <stdio.h>
#include "skeleton_arraylist.h"

int main() {
    FILE* file = fopen("in.txt", "r");
    if(file == NULL) return 1;

    arrayList list;
    init(&list);

    int func, p1, p2;
    while(fscanf(file, "%d", &func) == 1 && func != 0) {
        if(func == 1 && fscanf(file, "%d", &p1) == 1){
            printf("Insert %d\n", p1);
            insert(p1, &list); print(&list);
        }
        else if(func == 2){
            printf("Delete current item\n");
            int ret = delete_cur(&list);
            if(ret >= 0) { print(&list); printf("%d is deleted\n", ret); }
            else printf("List is empty\n");
        }
        else if(func == 3 && fscanf(file, "%d", &p1) == 1){
            printf("Append %d\n", p1);
            append(p1, &list); print(&list);
        }
        else if(func == 4){
            printf("Size of the list is %d\n", size(&list));
        }
        else if(func == 5 && fscanf(file, "%d", &p1) == 1){
            printf("Prev %d\n", p1);
            prev(p1, &list); print(&list);
        }
        else if(func == 6 && fscanf(file, "%d", &p1) == 1){
            printf("Next %d\n", p1);
            next(p1, &list); print(&list);
        }
        else if(func == 7 && fscanf(file, "%d", &p1) == 1){
            if(is_present(p1, &list)) printf("%d is present\n", p1);
            else printf("%d is not present\n", p1);
        }
        else if(func == 8){
            printf("Clear list\n");
            clear(&list); print(&list);
        }
        else if(func == 9 && fscanf(file, "%d", &p1) == 1){
            printf("Delete %d\n", p1);
            if(delete_item(p1, &list) != -1) print(&list);
            else printf("%d not found\n", p1);
        }
        else if(func == 10 && fscanf(file, "%d %d", &p1, &p2) == 2){
            printf("Swap index %d and %d\n", p1, p2);
            swap_ind(p1, p2, &list); print(&list);
        }
        else if(func == 11 && fscanf(file, "%d", &p1) == 1){
            printf("Search %d\n", p1);
            int res = search(p1, &list);
            if(res != -1) printf("%d is found at %d\n", p1, res);
            else printf("%d is not found\n", p1);
        }
        else if(func == 12 && fscanf(file, "%d", &p1) == 1){
            printf("Find %d\n", p1);
            int res = find(p1, &list);
            if(res != -1) printf("%d is found at index %d\n", res, p1);
            else printf("%d is not a valid index\n", p1);
        }
        else if(func == 13 && fscanf(file, "%d %d", &p1, &p2) == 2){
            printf("Update element at %d\n", p1);
            int res = update(p1, p2, &list);
            if(res != -1) { print(&list); printf("%d is updated by %d\n", res, p2); }
            else printf("%d is not a valid index\n", p1);
        }
        else if(func == 14){
            printf("Trim\n");
            int res = trim(&list);
            if(res != -1) { print(&list); printf("%d removed\n", res); }
        }
        else if(func == 15){
            printf("Reverse\n");
            reverse(&list); print(&list);
        }
    }
    free_list(&list);
    fclose(file);
    return 0;
}