#ifndef FILE_FUNCTIONS_H_INCLUDED
#define FILE_FUNCTIONS_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "product.h"
#include "dbl.h"
#include "admin_functions.h"
#include "user.h"
void create_ps_file(char*,struct dbl*);
void save_storage(char*,struct dbl*);
void create_user_file(char*,struct dbl*);
void save_users(char*,struct dbl*);
void create_orders_file(char*,struct dbl*);
void save_orders(char*,struct dbl*);

#endif // FILE_FUNCTIONS_H_INCLUDED
