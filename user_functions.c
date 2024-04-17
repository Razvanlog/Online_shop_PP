#include "user_functions.h"
#include"admin_functions.h"
void create_account(struct dbl*l){
    char *user=(char*)malloc(sizeof(char)*100),*surname=(char*)malloc(sizeof(char)*100);
    printf("user:");
    fgets(user,1000,stdin);
    printf("surname:");
    fgets(surname,1000,stdin);
    user[strlen(user)-1]='\0';
    surname[strlen(surname)-1]='\0';
    struct user a=create_user(user,surname,1);
    if (!add_user(l,a))
        printf("succesfully created account!\n");
    return;
}

void add_product_cart(struct dbl*l,struct user*user){
    char*name=(char*)malloc(sizeof(char)*100);
    int quantity=0;
    printf("name:");
    fgets(name,100,stdin);
    //while ((getchar())!='\n');
    printf("quantity:");
    fscanf(stdin,"%d",&quantity);
    while ((getchar())!='\n');
    name[strlen(name)-1]='\0';
    //struct node*p=query_product(l,a);
    struct product a=create_product(name,quantity,0);
    struct node*p=query_product(l,a);
    if (p!=NULL){
    a.price=((struct product*)p->val)->price;
    if (!remove_product(l,a,quantity)){
    add_product(&(user->cart.products),a);
    user->cart.total_price+=a.price*quantity;
    printf("succesfully added product to shopping cart!\n");
    return;
    }
    else{
        printf("failed adding product to shopping cart, try again\n");
    }
    }
    else printf("failed adding product to shopping cart, try again\n");
}

void remove_product_cart(struct dbl*l,struct user*user){
    char*name=(char*)malloc(sizeof(char)*100);
    int quantity=0;
    printf("name:");
    fgets(name,100,stdin);
    printf("quantity:");
    fscanf(stdin,"%d",&quantity);
    while ((getchar())!='\n');
    name[strlen(name)-1]='\0';
    //struct node*p=query_product(l,a);
    struct product a=create_product(name,quantity,0);
    struct node*p=query_product(l,a);
    a.price=((struct product*)p->val)->price;
    if (!remove_product(&(user->cart.products),a,quantity)){
    add_product(l,a);
    user->cart.total_price-=a.price*quantity;
    printf("succesfully removed product from shopping cart!\n");
    return;
    }
    else{
        printf("failed removing product from shopping cart,try again\n");
    }
}

void user_query_keyword(struct dbl*l){
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
void user_query_price_range(struct dbl*l){
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
void user_query_npr(struct dbl*l){
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
void place_order(struct user*user){
    if (user->cart.products.first!=NULL){
    struct node*p=(struct node*)malloc(sizeof(struct node));
    struct order*copy=(struct order*)malloc(sizeof(struct order));
    *copy=user->cart;
    *p=create_node((void*)copy);
    struct dbl*order_list=&(user->orders);
    push_back(order_list,p);
    (user->n_orders)++;
    user->cart=create_order();
    printf("the order has been placed succesfully!\n");
    }
    else printf("the cart is empty!\n");
    return;
}
void print_order(struct order it){
    struct dbl*l=&(it.products);
    print_products(l);
    /*while (cur!=NULL){
        struct product*product=(struct product*)(cur->val);
        sum+=product->price;
        cur=cur->next;
    }*/
    printf("total price of order: %f\n",it.total_price);
}
void print_orders(struct user*user){
    struct node*it=(user->orders).first;
    int counter=0;
    if (it==NULL)
    printf("no orders placed\n");
    while (it!=NULL){
        struct order*cur_order=(struct order*)(it->val);
        printf("%d. order %s:\n",++counter,cur_order->code);
        print_order(*cur_order);
        printf("\n");
        it=it->next;
    }
}
void sell_prod(struct dbl*storage){
    admin_add_product(storage);
    return;
}
void user_help(){
    printf("add product - add a product to your shopping cart\nremove product - remove a product from your shopping cart\nplace order - place the order with the items from your shopping cart\nprint all - print all the products available\nprint cart - print the items in your shopping cart\nprint orders - print all placed orders\nexit - quit the program\nlog out - log out of the accout\nquery n - display all products which contain the a word\nquery pr - display all products which are in a price range\nquery npr - display all products which contain a word and are in a price range\nsell product - sell a product on Remag\n\n");
}
void print_all(struct dbl*l){
    print_products(l);
}
int user_command_recog(char*command){
    if (!strcmp(command,"place order\n"))
        return 11;
    if (!strcmp(command,"add product\n"))
        return 1;
    if (!strcmp(command,"exit\n")) // exit - quit the program
        return 10;
    if (!strcmp(command,"logout\n")) // log out - log out of the accout
        return 2;
    if (!strcmp(command,"print cart\n"))
        return 3;
    if (!strcmp(command,"remove product\n"))
        return 4;
    if (!strcmp(command,"query n\n")) //query n - display all products which contain the a word
        return 5;
    if (!strcmp(command,"query pr\n")) //query pr - display all products which are in a price range
        return 6;
    if (!strcmp(command,"query npr\n")) // query npr - display all products which contain a word and are in a price range
        return 7;
    if (!strcmp(command,"sell product\n")) // sell product - sell a product on Remag
        return 8;
    if (!strcmp(command,"help\n"))
        return 9;
    if (!strcmp(command,"print orders\n")) //print orders - print all placed orders
        return 12;
    if (!strcmp(command,"print all\n"))
        return 13;
    return 0;
}
