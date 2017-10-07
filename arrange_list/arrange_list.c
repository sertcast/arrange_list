//
//  arrange_list.c
//  arrange_list
//
//  Created by Mert Kaya on 2017-10-07.
//  Copyright © 2017 Mert Kaya. All rights reserved.
//

#include "arrange_list.h"


bool arrange_check(double *list, int *psize){
    double *current = list;
    current++;
    double *next = current;
    current--;
    int i;
    for(i = 0; i < (*psize)-1; i++){
        if(*current > *next){
            return false;
        }
        current++;
        next++;
    }
    return true;
}
double *parse_file(char*filename, int *psize){
    my_list *the_list = create_list();
    int len_list = 0;
    char line[200];
    FILE *num_file = fopen(filename, "r");
    int a;
    while(!feof(num_file)){
        fgets(line, 200, num_file);
        if(atof(line)!= 0.0){
            append_list(the_list, atof(line));
            len_list++;
        }
    }
    fclose(num_file);
    
    double *list = (double*)malloc(len_list*sizeof(double));
    my_list *current = the_list;
    for(a = 0; a < len_list; a++){
        list[a] = current->value;
        current = current->next;
    }
    free_list(the_list);
    *psize = len_list;
    return list;
}
void arrange_list(double *list, int *psize){
    double *ar_list = list, *next = &(list[1]), keep;
    int i;
    int ilk = 0;
    while(!arrange_check(list, psize)){
        if((*psize)%2 == 0){
            ar_list = list;
            next = &(list[1]);
            if(ilk == 0){
                for(i = 0; i < ((*psize)/2) - 1; i++){
                    if(*ar_list > *next){
                        keep = *ar_list;
                        *ar_list = *next;
                        *next = keep;
                    }
                    ar_list+=2;
                    next+=2;
                }
                if(*ar_list > *next){
                    keep = *ar_list;
                    *ar_list = *next;
                    *next = keep;
                }
                ilk++;
            }else{
                if(ar_list[0] > ar_list[(*psize)-1]){
                    keep = *ar_list;
                    *ar_list = *next;
                    *next = keep;
                }
                ar_list++;
                next++;
                for(i = 0; i < ((*psize)/2) - 1; i++){
                    if(*ar_list > *next){
                        keep = *ar_list;
                        *ar_list = *next;
                        *next = keep;
                    }
                    ar_list+=2;
                    next+=2;
                }
                ilk--;
            }
        }else{
            ar_list = list;
            next = &(list[1]);
            if(ilk == 0){
                for(i = 0; i < ((*psize)/2) - 1; i++){
                    if(*ar_list > *next){
                        keep = *ar_list;
                        *ar_list = *next;
                        *next = keep;
                    }
                    ar_list+=2;
                    next+=2;
                }
                if(*ar_list > *next){
                    keep = *ar_list;
                    *ar_list = *next;
                    *next = keep;
                }
                ilk++;
            }else{
                ar_list++;
                next++;
                for(i = 0; i < ((*psize)/2) - 1; i++){
                    if(*ar_list > *next){
                        keep = *ar_list;
                        *ar_list = *next;
                        *next = keep;
                    }
                    ar_list+=2;
                    next+=2;
                }
                ilk--;
            }
        }
    }
}

