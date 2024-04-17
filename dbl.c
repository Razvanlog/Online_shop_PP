#include "dbl.h"
struct node create_node(void* v){
    struct node*p=(struct node*)malloc(sizeof(struct node));
    p->val=v;
    p->next=NULL;
    p->previous=NULL;
    return *p;
}
struct dbl create_list(){
    struct dbl p;
    p.size=0;
    p.first=NULL;
    p.last=NULL;
    return p;
}
void push_back(struct dbl*l,struct node*c){
    if (l->size){
    c->previous=l->last;
    l->last->next=c;
    l->last=c;
    }
    else{
        l->last=c;
        l->first=c;
        c->next=NULL;
        c->previous=NULL;
    }
    l->size++;
}
short pop_back(struct dbl*l){
    if (l->size>1){
        struct node*to_be_deleted=l->last;
        l->last=l->last->previous;
        l->last->next=NULL;
        l->size--;
        free(to_be_deleted);
        return 1;
    }
    else if (l->size==1){
        struct node*to_be_deleted=l->last;
        free(to_be_deleted);
        l->size=0;
        return 1;
    }
    else return 0;
}
void push_front(struct dbl*l,struct node*c){
    if (l->size){
    c->next=l->first;
    c->previous=l->last;
    l->first=c;
    }
    else{
        l->last=l->first=c;
        c->next=NULL;
        c->previous=NULL;
    }
    l->size++;
}
short pop_front(struct dbl*l){
    if (l->size>1){
        struct node*to_be_deleted=l->first;
        l->first=l->first->next;
        l->first->previous=NULL;
        l->size--;
        free(to_be_deleted);
        return 1;
    }
    else if (l->size==1){
        struct node*to_be_deleted=l->last;
        free(to_be_deleted);
        l->size=0;
        return 1;
    }
    else return 0;
}
short insert(struct dbl*l,struct node*c,int poz){
    if (poz>l->size && l->size){
        return 0;
    }
    if (poz>=0){
        if (poz==0){
            push_front(l,c);
        }
        else if (poz==l->size){
            push_back(l,c);
        }
        else{
        struct node*it=l->first;
        int counter=0;
        while (counter!=poz){
            counter++;
            it=it->next;
        }
        c->previous=it->previous;
        c->next=it;
        it->previous->next=c;
        it->previous=c;
        l->size++;
        }
        return 1;
    }
    else{
        return 0;
    }
}
short pop(struct dbl*l,int poz){
    if (poz>l->size && l->size){
        return 0;
    }
    if (poz>=0){
        if (poz==0){
            pop_front(l);
        }
        else if (poz==l->size-1){
            pop_back(l);
        }
        else{
        struct node*it=l->first;
        int counter=0;
        while (counter!=poz){
            counter++;
            it=it->next;
        }
        it->previous->next=it->next;
        it->next->previous=it->previous;
        free(it);
        l->size--;
        }
        return 1;
    }
    else{
        return 0;
    }
}
