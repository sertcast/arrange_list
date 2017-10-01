//
//  linked_list.h
//  arrange_list
//
//  Created by Mert Kaya on 2017-10-01.
//  Copyright © 2017 Mert Kaya. All rights reserved.
//

#ifndef linked_list_h
#define linked_list_h

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

struct my_list {
    int value;
    struct my_list *next, *prev;
    bool added_value;
};
typedef struct my_list my_list;

my_list *create_list(void);
my_list *go_end(my_list *the_list);
void print_list(my_list *list);
void change_value(my_list *the_node, int value);
void append_list(my_list *the_list,int value);
my_list *go_value(my_list *list, int place);
void free_list(my_list *the_list);
int length_list(my_list* list);
void switch_list(my_list *list, int first_place, int second_place);
void cp_list(my_list *list, my_list*cplist);
#endif /* linked_list_h */

