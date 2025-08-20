#include "utils.h"

int linearSearch(vector<Book>& library, int id) {
    for (int i = 0; i < library.size(); i++) {
        if (library[i].id == id)
            return i;
    }
    return -1;
}
