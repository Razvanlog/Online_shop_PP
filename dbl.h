#ifndef DBL_H_INCLUDED
#define DBL_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
/*struct tester{
    int a;
    float b;
    char c;
};*/
struct node{
    void*val;
    struct node*next,*previous;
};
struct dbl{
    struct node*first,*last;
    int size;
};
struct node create_node(void*);
struct dbl create_list();
void push_back(struct dbl*,struct node*);
short pop_back(struct dbl*);
void push_front(struct dbl*,struct node*);
short pop_front(struct dbl*);
short insert(struct dbl*,struct node*,int);
short pop(struct dbl*,int);
/*void print_list(struct dbl*l){
    if (l->size){
    struct node*it=l->first;
    printf("%d\n",*((int*)it->val));
    while (it!=l->last){
        it=it->next;
        printf("%d\n",*((int*)it->val));
    }
    }
    else printf("empty list!\n");
}
void print_reversed_list(struct dbl*l){
    if (l->size){
    struct node*it=l->last;
    printf("%d %f %c\n",((struct tester*)it->val)->a,((struct tester*)it->val)->b,((struct tester*)it->val)->c);
    while(it!=l->first){
        it=it->previous;
        printf("%d %f %c\n",(((struct tester*)(it->val))->a),((struct tester*)it->val)->b,((struct tester*)it->val)->c);
    }
    }
    else printf("empty list!\n");
}*/


#endif // DBL_H_INCLUDED
