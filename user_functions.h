#pragma once
#include <stdlib.h>
#include <stdio.h>
#include "user.h"
#include "dbl.h"

void create_account(struct dbl*l);
void add_product_cart(struct dbl*l,struct user*user);
void remove_product_cart(struct dbl*l,struct user*user);
void user_query_keyword(struct dbl*l);
void user_query_price_range(struct dbl*l);
void user_query_npr(struct dbl*l);
void place_order(struct user*user);
void print_order(struct order it);
void print_orders(struct user*user);
void sell_prod(struct dbl*storage);
void user_help();
int user_command_recog(char*command);
void print_all(struct dbl*);
