#include "../inc/libmx.h"

t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *)) {
    if (lst == NULL || cmp == NULL) {
        return NULL;
    }

    t_list *sorted = NULL;
    t_list *next = NULL;
    t_list *current = lst;
    t_list *current_sorted;

    while (current != NULL) {
        next = current->next;
        if (sorted == NULL || !cmp(current->data, sorted->data)) {
            current->next = sorted;
            sorted = current;
        } else {
            current_sorted = sorted;
            while (current_sorted->next != NULL && cmp(current->data, current_sorted->next->data)) {
                current_sorted = current_sorted->next;
            }
            current->next = current_sorted->next;
            current_sorted->next = current;
        }
        current = next;
    }
    return sorted;
}







