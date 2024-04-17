#ifndef ADMIN_FUNCTIONS_H_INCLUDED
#define ADMIN_FUNCTIONS_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include "product.h"
#include "user.h"
int admin_command_recog(char*);
void admin_help();
void admin_add_product(struct dbl*);
void admin_add_user(struct dbl*);
void admin_pop_product(struct dbl*);
void admin_pop_user(struct dbl*);
void admin_query_keyword(struct dbl*);
void admin_query_price_range(struct dbl*);
void admin_query_npr(struct dbl*);

#endif // ADMIN_FUNCTIONS_H_INCLUDED
