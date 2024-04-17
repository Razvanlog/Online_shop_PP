#include "product.h"
struct product create_product(char*c,int q,float p){
    struct product a;
    a.name=malloc(sizeof(c));
    strcpy(a.name,c);
    a.quantity=q;
    a.price=p;
    return a;
}
void add_product(struct dbl*l,struct product a){
    struct node*p=(struct node*)malloc(sizeof(struct node));
    struct product *copy=(struct product*)calloc(1,sizeof(struct product));
    *copy=a;
    //printf("%s\n",a.name);
    //printf("ok");
    //struct node*p=(struct node*)calloc(1,sizeof(struct node));
    *p=create_node((void*)(copy));
    //printf("%s\n",a.name);
    struct node*prod_node=query_product(l,a);
    if (prod_node==NULL)
        push_back(l,p);
    else{
        struct product*prod=(struct product*)(prod_node->val);
        prod->quantity+=a.quantity;
    }
    //printf("ok\n");
}
short remove_product(struct dbl*l,struct product a,int quantity){
    struct node*it=l->first;
    int poz=0;
    while (it!=NULL && strcmp(a.name,((struct product*)(it->val))->name)){
        it=it->next;
        poz++;
    }
    //printf("%d\n",poz);
    if (it!=NULL){
        struct product*product=(struct product*)(it->val);
        if (product->quantity>quantity){
            product->quantity-=quantity;
        }
        else if (product->quantity==quantity)
            pop(l,poz);
        else return 1;
        return 0;
    }
    else {
        return 1;
    }
}
struct node*query_product(struct dbl*l,struct product a){
    struct node*it=l->first;
    int poz=0;
    while (it!=NULL && strcmp(a.name,((struct product*)(it->val))->name)){
        it=it->next;
        poz++;
    }
    if (it!=NULL){
        return it;
    }
    else {
        return NULL;
    }
}
struct dbl query_name(struct dbl*l,char*str){
    struct dbl a=create_list();
    struct node*it=l->first;
    //char **a;
    int counter=0;
    //a=malloc(sizeof(char*)*100);
    while (it!=NULL){
        if (strstr(((struct product*)(it->val))->name,str)!=NULL){
            struct node*ins=malloc(sizeof(struct node));
            ins->val=(it->val);
            push_back(&a,ins);
            //*(a+counter)=malloc(sizeof(char)*100);
            //strcpy(*(a+counter),((struct product*)(it->val))->name);
            //counter++;
        }
        it=it->next;
    }
    return a;
}
struct dbl query_pr(struct dbl*l,float minv,float maxv){
    struct dbl a=create_list();
    struct node*it=l->first;
    //char **a;
    int counter=0;
    //a=malloc(sizeof(char*)*100);
    while (it!=NULL){
        if (((struct product*)(it->val))->price>=minv && ((struct product*)(it->val))->price<=maxv){
            struct node*ins=malloc(sizeof(struct node));
            ins->val=(it->val);
            push_back(&a,ins);
            //*(a+counter)=malloc(sizeof(char)*100);
            //strcpy(*(a+counter),((struct product*)(it->val))->name);
            //counter++;
        }
        it=it->next;
    }
    return a;
}
struct dbl query_npr(struct dbl*l,char*str,float minv,float maxv){
    struct dbl a=create_list();
    struct node*it=l->first;
    //char **a;
    int counter=0;
    //a=malloc(sizeof(char*)*100);
    while (it!=NULL){
        if (strstr(((struct product*)(it->val))->name,str)!=NULL && ((struct product*)(it->val))->price>=minv && ((struct product*)(it->val))->price<=maxv){
            struct node*ins=malloc(sizeof(struct node));
            ins->val=(it->val);
            push_back(&a,ins);
            //*(a+counter)=malloc(sizeof(char)*100);
            //strcpy(*(a+counter),((struct product*)(it->val))->name);
            //counter++;
        }
        it=it->next;
    }
    return a;
}
void print_products(struct dbl*l){
    if (l->size){
    struct node*it=l->first;
    printf("name,quantity,price\n");
    struct product*p=(struct product*)(it->val);
    //*(p->name+strlen(p->name)-1)='\0';
    printf("%s,%d,%f\n",p->name,p->quantity,p->price);
    while (it!=l->last){
        it=it->next;
        struct product*p=(struct product*)(it->val);
        fprintf(stdout,"%s,%d,%f\n",p->name,p->quantity,p->price);
    }
    }
    else printf("empty product list\n");
}
