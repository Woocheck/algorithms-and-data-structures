#include <stdio.h>
#include <stdlib.h>
 
typedef struct node
{
    int data;
    struct node* next;
} node;

typedef struct Lists
{
    node* head;
    node* tail;
} List;

void push(List** list, int new_data) 
{ 
    struct node* new_node = (struct node*)malloc(sizeof(struct node)); 
    new_node->data = new_data; 
    new_node->next=NULL;

    new_node->next = (*list)->head;  
    (*list)->head = new_node; 
    
    while(new_node->next!=NULL){
        new_node=new_node->next;
    }
    (*list)->tail=new_node;
            
}

int pop(List** list)
{
    if((*list) == NULL){
        printf("No solution available, exiting program.\n");
        exit(-1);
    }
    else if((*list)->head==(*list)->tail)
    {
        int pop_element=(*list)->tail->data;
        free((*list)->head);
        (*list)->head=(*list)->tail=NULL;
        return pop_element;
    }
    else
    {
        struct node* new_tail=NULL;
        int pop_element=(*list)->tail->data;
        for (new_tail = (*list)->head; new_tail->next != (*list)->tail; new_tail = new_tail->next);
        new_tail->next = NULL;
        free((*list)->tail);
        (*list)->tail = new_tail;
        return pop_element;
    }
}
     
void print_list(List** list)
{
    node* list_element = (*list)->head; 
    while(list_element != NULL) {
        printf("%d ", list_element ->data);
        list_element = list_element->next;
    }
    printf("\n");
}

int main()
{
    List* list;
    list->head=NULL;
    list->tail=NULL;
    
    for(int i=0; i<10; ++i)
                push( &list, i);
    
    print_list(&list);

    for(int i=0; i<4; ++i)
                printf ("%d, ",pop(&list));
    
    printf("\n");
    print_list(&list);
    

    return 0;
}
