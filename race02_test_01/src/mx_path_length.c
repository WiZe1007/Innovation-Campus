#include <way_home.h>

int mx_path_length(t_path *path) {
    int count = 0;
    t_path *temp = path;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

