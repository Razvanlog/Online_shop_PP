#ifndef PRODUCT_H_INCLUDED
#define PRODUCT_H_INCLUDED

#include "dbl.h"
#include <string.h>
struct product{
    int quantity;
    char*name;
    float price;
};
struct product create_product(char*,int,float);
void add_product(struct dbl*,struct product);
short remove_product(struct dbl*,struct product ,int);
struct node*query_product(struct dbl*,struct product);
struct dbl query_name(struct dbl*,char*);
struct dbl query_pr(struct dbl*,float,float);
struct dbl query_npr(struct dbl*,char*,float,float);
void print_products(struct dbl*);
#endif // PRODUCT_H_INCLUDED
