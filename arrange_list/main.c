//
//  main.c
//  arrange_list
//
//  Created by Mert Kaya on 2017-10-01.
//  Copyright © 2017 Mert Kaya. All rights reserved.
//

#include "linked_list.h"
void cp_list(my_list *list, my_list*cplist){
    my_list *current_list = list;
    my_list *cp_list = cplist;
    while(current_list->next != NULL){
        append_list(cp_list, current_list->value);
        current_list = current_list->next;
    }
    append_list(cp_list, current_list->value);
}

bool arrange_check(my_list *list){
    my_list *current = list;
    while (current->next != NULL) {
        if(current->value > current->next->value){
            return false;
        }
        current = current->next;
    }
    return true;
}

my_list *arranged_list(my_list *list){
    my_list *arlist = create_list();
    cp_list(list, arlist);
    my_list *current = arlist;
    int cur_place = 0;
    int lengthList = length_list(arlist)+1;
    while(!arrange_check(arlist)){
        if(lengthList % 2 == 1){
            if(cur_place % 2 == 0 ){
                current  = arlist;
                cur_place = 0;
            }else{
                current  = arlist->next;
                cur_place = 1;
            }
        }else{
            if(cur_place % 2 == 0 ){
                current = arlist;
                cur_place = 0;
            }else{
                current = arlist;
                if(current->value > (go_end(arlist))->value){
                    switch_list(arlist, 0, lengthList-1);
                }
                current = current->next;
                cur_place = 1;
            }
        }
        while(current->next->next != NULL){
            if(current->value > current->next->value){
                switch_list(arlist, cur_place, cur_place+1);
            }
            current = current->next->next;
            cur_place += 2;
            if(current->next==NULL)break;
        }
        if(current->next!=NULL &&current->value > current->next->value){
            switch_list(current, 0, 1);
        }
        cur_place++;
    }
    return arlist;
}

int main(int argc, const char * argv[]) {
    int theList[] = {3,4,6,5,2,1};
    my_list *list = create_list();
    int i;
    for(i = 0; i < (int)sizeof(theList)/4; i++){
        append_list(list, theList[i]);
    }
    my_list *my_ar_list = arranged_list(list);
    print_list(my_ar_list);
    print_list(list);
    free_list(list);
    free_list(my_ar_list);
    return 0;
}

