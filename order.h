#ifndef ORDER_H_INCLUDED
#define ORDER_H_INCLUDED

#include "product.h"
#include "dbl.h"
#include <stdlib.h>
#include <time.h>
struct order{
    struct dbl products;
    float total_price;
    char* code;
};
struct order create_order();


#endif // ORDER_H_INCLUDED
