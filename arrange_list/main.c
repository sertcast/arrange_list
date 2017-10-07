//
//  main.c
//  arrange_list
//
//  Created by Mert Kaya on 2017-10-01.
//  Copyright © 2017 Mert Kaya. All rights reserved.
//

#include "linked_list.h"

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
    int len_list = 0, i;
    char *line = (char*)malloc(sizeof(char));
    FILE *num_file = fopen(filename, "r");
    int a;
    for(i = 0; i < 200; i++){
        fgets(line, 20, num_file);
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
    double *ar_list = list;
    int i;
    int odd = 0;
    while(!arrange_check(list, psize)){
        if((*psize)%2 == 0){
            if(odd == 0){
                for(i = 0; i < (*psize)-1; i++){
                    
                }
                odd++;
            }else{
                odd--;
            }
        }else{
            
        }
    }
}

int main(int argc, const char * argv[]) {
    int *size = (int*)malloc(sizeof(int));
    double *list = parse_file("/Users/mert/Desktop/data1.txt",size);
    arrange_list(list,size);
    free(list);
    return 0;
}

