#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <libgen.h>
#include "dbl.h"
#include "product.h"
#include "admin_functions.h"
#include "file_functions.h"
#include "user_functions.h"
#include "order.h"
struct dbl product_list;
struct dbl user_list;
struct user current_user;
int main(int argc,char **argv){
    product_list=create_list();
    user_list=create_list();
    int connected=0,run=1;
    //printf("ok");
    create_ps_file(__FILE__,&product_list);
    //printf("ok\n");
    create_user_file(__FILE__,&user_list);
   // printf("ok\n");
    create_orders_file(__FILE__,&user_list);
   // printf("ok\n");
    int state=1;
    char*user,*surname,*create_user;
    user=(char*)malloc(sizeof(char)*26);
    surname=(char*)malloc(sizeof(char)*26);
    create_user=(char*)malloc(sizeof(char)*26);
    //if (user==NULL || surname==NULL || create_user==NULL)
    //printf("null");
    if (argc==1){
       // printf("one argument");
    }
    else{
        if (!strcmp(argv[1],"login")){
            if (argc==4){
                strcpy(user,argv[2]);
                strcpy(surname,argv[3]);
                //printf("%s\n%s\n",user,surname);
                connected=check_credentials(&user_list,user,surname,&current_user);
            //printf("%s",__FILE__);
            //print_users(&user_list);
            }
            else printf("try again\n");
        }
    }
    while (run){
        if (!connected){
            printf("Welcome to Remag!\ncommands:\ncreate account - create a Remag account\nlogin - log into a Remag account\nexit - exit the program\n\n");
        }
        while (!connected && run){
            printf("Remag:");
            fgets(create_user,25,stdin);
            create_user[strlen(create_user)-1]='\0';
            if (!strcmp(create_user,"create account")){
                create_account(&user_list);
                save_users(__FILE__,&user_list);
            }
            else if (!strcmp(create_user,"login")){
                break;
            }
            else if (!strcmp(create_user,"exit")){
                run=0;
                state=0;
                connected=0;
                break;
            }
            else printf("command unrecognized!\n");
        }
        //system("clear");
        if (run){
        while (!connected){
            printf("user:");
            fgets(user,25,stdin);
            printf("surname:");
            fgets(surname,25,stdin);
            user[strlen(user)-1]='\0';
            surname[strlen(surname)-1]='\0';
            connected=check_credentials(&user_list,user,surname,&current_user);
            if (!connected){
                printf("try again\n");
            }
            //break;
        }
        //printf("ok");
        system("cls");
        //printf("ok");
        if (connected)
            state=1;
        if (current_user.rights==0){
            printf("Hello admin!\ntype help to learn more about the available commands\n\n");
        }
        else printf("Hello %s!\ntype help to learn more about the available commands\n\n",current_user.name);
        while (state && run){
            if (state==1){
            char *command;
            command=(char*)malloc(sizeof(char)*26);
            printf("%s:",current_user.name);
            fgets(command,25,stdin);
            if (current_user.rights==0){
            int type=admin_command_recog(command);
            switch(type){
                case 1:
                    admin_add_product(&product_list);
                    break;
                case 2:
                    admin_pop_product(&product_list);
                    break;
                case 3:
                    print_products(&product_list);
                    break;
                case 4:
                    state=0;
                    run=0;
                    break;
                case 5:
                    admin_add_user(&user_list);
                    break;
                case 6:
                    admin_pop_user(&user_list);
                    break;
                case 7:
                    admin_query_keyword(&product_list);
                    break;
                case 8:
                    admin_help();
                    break;
                case 9:
                    admin_query_price_range(&product_list);
                    break;
                case 10:
                    state=0;
                    connected=0;
                    break;
                case 11:
                    admin_query_npr(&product_list);
                    break;
                default:
                    printf("command not recognized\n");
                    break;
                }
            }
            else{
                int type=user_command_recog(command);
                switch(type){
                    case 1:
                    add_product_cart(&product_list,&current_user);
                    break;
                    case 2:
                    state=0;
                    connected=0;
                    break;
                    case 3:
                    print_order(current_user.cart);
                    break;
                    case 4:
                    remove_product_cart(&product_list,&current_user);
                    break;
                    case 5:
                    user_query_keyword(&product_list);
                    break;
                    case 6:
                    user_query_price_range(&product_list);
                    break;
                    case 7:
                    user_query_npr(&product_list);
                    break;
                    case 8:
                    sell_prod(&product_list);
                    break;
                    case 9:
                    user_help();
                    break;
                    case 10:
                    state=0;
                    run=0;
                    connected=0;
                    break;
                    case 11:
                    place_order(&current_user);
                    struct node*it=query_user(&user_list,current_user);
                    *((struct user*)it->val)=current_user;
                    save_orders(__FILE__,&user_list);
                    break;
                    case 12:
                    print_orders(&current_user);
                    break;
                    case 13:
                    print_all(&product_list);
                    break;
                    default:
                    printf("command not recognized\n");
                    break;
                }
            }
            free(command);
        }
    }
    }
    system("cls");
    //stdin.clear();
    }
    save_storage(__FILE__,&product_list);
    save_users(__FILE__,&user_list);
    save_orders(__FILE__,&user_list);
    return 0;
}
