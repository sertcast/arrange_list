//
//  linked_list.c
//  arrange_list
//
//  Created by Mert Kaya on 2017-10-01.
//  Copyright © 2017 Mert Kaya. All rights reserved.
//

#include "linked_list.h"
//creates a node
my_list *create_node(){
    my_list *newNode = (my_list*)malloc(sizeof(my_list));
    newNode->next = NULL;
    newNode->prev = NULL;
    newNode->added_value = false;
    newNode->value = 0.0;
    return newNode;
}
//creates a list
my_list *create_list(){
    return create_node();
}
//returns the node that is at the end of the list
my_list *go_end(my_list *the_list){
    my_list *current = the_list;
    while(current->next != NULL){
        current = current->next;
    }
    return current;
}
//removes the node from memory
void free_node(my_list *the_node){
    the_node->next = NULL;
    the_node->prev = NULL;
    the_node->value = 0;
    the_node->added_value = false;
    free(the_node);
}
//removes the list from memory
void free_list(my_list *the_list){
    if(go_end(the_list)->prev != NULL){
        my_list *current = (go_end(the_list))->prev;
        while(current->prev != NULL){
            free_node(current->next);
            current = current->prev;
        }
        free_node(current);
    }else{
        free_node(the_list);
    }
}
//changes the value that is in the node given
void change_value(my_list *the_node, double value){
    the_node->value = value;
    the_node->added_value = true;
}
//adds a value to the end
void append_list(my_list *the_list,double value){
    my_list *current = go_end(the_list);
    if(current->added_value){
        my_list *newNode = create_node();
        current->next = newNode;
        newNode->prev = current;
        change_value(newNode,value);
    }
    else{
        change_value(current,value);
    }
}

