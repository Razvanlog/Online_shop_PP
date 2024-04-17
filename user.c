#include "user.h"
#include "product.h"
#include "order.h"
struct user create_user(char*name,char*surname,int rights){
    struct user a;
    a.name=(char*)malloc(sizeof(name));
    strcpy(a.name,name);
    a.surname=(char*)malloc(sizeof(surname));
    strcpy(a.surname,surname);
    a.rights=rights;
    a.cart=create_order();
    a.orders=create_list();
    a.n_orders=0;
    return a;
}
short add_user(struct dbl*l,struct user a){
    struct node*p=(struct node*)malloc(sizeof(struct node));
    struct user *copy=(struct user*)malloc(sizeof(struct user));
    *copy=a;
    *p=create_node((void*)(copy));
    if (query_user(l,a)==NULL)
    {
        push_back(l,p);
        return 0;
    }
    else printf("this account is already created\n");
    return 1;
}
short remove_user(struct dbl*l,struct user a){
    struct node*it=l->first;
    int poz=0;
    while (it!=NULL && strcmp(a.name,((struct user*)(it->val))->name)){
        it=it->next;
        poz++;
    }
    if (it!=NULL){
        pop(l,poz);
        return 1;
    }
    else {
        return 0;
    }
}
struct node*query_user(struct dbl*l,struct user a){
    struct node*it=l->first;
    int poz=0;
    struct user*p;
    if (it!=NULL)
    p=(struct user*)(it->val);
    else return NULL;
    //printf("%s",p->surname);
    //print_users(l);
    while (it!=NULL && strcmp(a.name,((struct user*)(it->val))->name)&& strcmp(a.surname,((struct user*)(it->val))->surname)){
       // printf("%d %s %s\n",strcmp(a.name,((struct user*)(it->val))->name),a.name,((struct user*)(it->val))->name);
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
void print_users(struct dbl*l){
    if (l->size){
    struct node*it=l->first;
    printf("user,surname,rights\n");
    struct user*p=(struct user*)(it->val);
    //*(p->name+strlen(p->name)-1)='\0';
    printf("%s,%s,%d\n",p->name,p->surname,p->rights);
    while (it!=l->last){
        it=it->next;
        struct user*p=(struct user*)(it->val);
        fprintf(stdout,"%s,%s,%d\n",p->name,p->surname,p->rights);
    }
    }
    else printf("empty product list\n");
}
short check_credentials(struct dbl*user_list,char*user,char*surname,struct user *current_user){
    struct node*try;
    struct user a=create_user(user,surname,0);
    try=query_user(user_list,a);
    //printf("%x\n",try);
    if (try!=NULL && strcmp(((struct user*)(try->val))->surname,surname)==0){
        //connected=1;
        *current_user=*((struct user*)(try->val));
        return 1;
    }
    return 0;
}
