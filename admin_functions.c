#include "admin_functions.h"
int admin_command_recog(char*s){
    if (!strcmp(s,"add product\n")){
        return 1;
    }
    if (!strcmp(s,"remove product\n")){
        return 2;
    }
    if (!strcmp(s,"print products\n")){
        return 3;
    }
    if (!strcmp(s,"exit\n"))
    return 4;
    if (!strcmp(s,"add user\n"))
    return 5;
    if (!strcmp(s,"remove user\n"))
    return 6;
    if (!strcmp(s,"query keyword\n"))
    return 7;
    if (!strcmp(s,"help\n"))
    return 8;
    if (!strcmp(s,"query price range\n"))
    return 9;
    if (!strcmp(s,"logout\n"))
    return 10;
    if (!strcmp(s,"query npr\n"))
    return 11;
    return 0;
}
void admin_help(){
    printf("add product\nremove product\nprint products\nadd user\nremove user\nquery keyword\nhelp");
    return;
}
void admin_add_product(struct dbl*l){
    struct product a;
    a.name=(char*)malloc(sizeof(char)*101);
    printf("name:");
    fgets(a.name,101,stdin);
    a.name[strlen(a.name)-1]='\0';
    printf("quantity:");
    scanf("%d",&a.quantity);
    while ((getchar())!='\n');
    printf("price:");
    scanf("%f",&a.price);
    while ((getchar())!='\n');
    add_product(l,a);
}
void admin_add_user(struct dbl*l){
    struct user a;
    int rights;
    a.name=(char*)malloc(sizeof(char)*101);
    a.surname=(char*)malloc(sizeof(char)*101);
    printf("user:");
    fgets(a.name,101,stdin);
    a.name[strlen(a.name)-1]='\0';
    printf("surname:");
    fgets(a.surname,101,stdin);
    printf("rights:");
    fscanf(stdin,"%d",&rights);
    while ((getchar())!='\n');
    a.rights=rights;
    a.surname[strlen(a.surname)-1]='\0';
    add_user(l,a);
}
void admin_pop_product(struct dbl*l){
    char*product=malloc(sizeof(char)*100);
    int q=0;
    printf("name:");
    fgets(product,10000,stdin);
    printf("quantity:");
    fscanf(stdin,"%d",&q);
    while ((getchar())!='\n');
    struct node*it=l->first;
    int execute=1;
    product[strlen(product)-1]='\0';
    while (execute){
        if (it==NULL){
            execute=0;
        }
        else if (!strcmp(product,((struct product*)(it->val))->name)){
            execute=0;
            struct product v=create_product((void*)(product),0,0.0);
            remove_product(l,v,q);
        }
        if (it!=NULL)
        it=it->next;
    }
    free(product);
}
void admin_pop_user(struct dbl*l){
    char*name=malloc(sizeof(char)*100);
    printf("name:");
    fgets(name,10000,stdin);
    struct node*it=l->first;
    int execute=1;
    name[strlen(name)-1]='\0';
    while (execute){
        if (it==NULL){
            execute=0;
        }
        else if (!strcmp(name,((struct user*)(it->val))->name)){
            execute=0;
            struct user v=create_user((void*)(name),0,0.0);
            remove_user(l,v);
        }
        if (it!=NULL)
        it=it->next;
    }
}
void admin_query_keyword(struct dbl*l){
    char*name=malloc(sizeof(char)*100);
    printf("keyword:");
    fgets(name,100,stdin);
    name[strlen(name)-1]='\0';
    struct dbl a=query_name(l,name);
    print_products(&a);
    //printf("\n");
    free(name);
    return;
}
void admin_query_price_range(struct dbl*l){
    float minv=0,maxv=0;
    printf("min value:");
    fscanf(stdin,"%f",&minv);
    printf("max_value:");
    fscanf(stdin,"%f",&maxv);
    while ((getchar())!='\n');
    //printf("%f %f\n",minv,maxv);
    struct dbl a=query_pr(l,minv,maxv);
    print_products(&a);
    return;
}
void admin_query_npr(struct dbl*l){
    char*name=malloc(sizeof(char)*100);
    printf("keyword:");
    fgets(name,100,stdin);
    name[strlen(name)-1]='\0';
    float minv=0,maxv=0;
    printf("min value:");
    fscanf(stdin,"%f",&minv);
    printf("max_value:");
    fscanf(stdin,"%f",&maxv);
    while ((getchar())!='\n');
    struct dbl a=query_npr(l,name,minv,maxv);
    print_products(&a);
    //printf("\n");
    free(name);
    return;
}
