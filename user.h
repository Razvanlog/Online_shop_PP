#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dbl.h"
#include "order.h"
struct user{
    char*name,*surname;
    int rights,n_orders;
    struct dbl orders;
    struct order cart;
};
struct user create_user(char*,char*,int);
void add_user(struct dbl*,struct user);
short remove_user(struct dbl*,struct user);
struct node*query_user(struct dbl*,struct user);
void print_users(struct dbl*);
short check_credentials(struct dbl*,char*,char*,struct user*);
//#endif
#endif // USER_H_INCLUDED
