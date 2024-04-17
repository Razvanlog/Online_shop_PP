
#include "file_functions.h"
#include "user_functions.h"
void create_ps_file(char *cur_file_name,struct dbl *product_list){
    FILE *f;
    *product_list=create_list();
    char *file_name=(char*)malloc(sizeof(char)*100000);
    strcpy(file_name,cur_file_name);
    file_name[strlen(file_name)-6]='\0';
    strcpy(file_name+strlen(file_name),"products.csv");
    f=fopen(file_name,"r");
    if (f==NULL){
        fclose(f);
        f=fopen(file_name,"w");
        fprintf(f,"name,quantity,price\n");
        fclose(f);
    }
    else{
        char*input=(char*)malloc(sizeof(char)*1000);
        fgets(input,101,f);
        while (fgets(input,101,f)!=NULL){
            char*it=strtok(input,",");
            struct product a;
            char *c=(char*)malloc(sizeof(char)*1001);
            strcpy(c,it);
            it=strtok(NULL,",");
            int q=0;
            for (int i=0; i<strlen(it); i++){
                q=q*10+it[i]-'0';
            }
            it=strtok(NULL,",");
            float p=0;
            int i=0;
            for (i=0;  it[i]!='.' && i<strlen(it); i++){
                p=p*10+it[i]-'0';
            }
            float power=1/10;
            i=i+1;
            for (int i; i<strlen(it); i++){
                p=p+(float)(((float)it[i]-'0'))*power;
                power=power/10;
            }
            a=create_product(c,q,p);
            free(c);
            add_product(product_list,a);
        }
        free(input);
        fclose(f);
    }
    free(file_name);
}
void save_storage(char*cur_file_name,struct dbl*l){
    char *filename=(char*)malloc(sizeof(char)*10001);
    strcpy(filename,cur_file_name);
    filename[strlen(filename)-6]='\0';
    strcpy(filename+strlen(filename),"products.csv");
    FILE *f=fopen(filename,"w");
    if (l->size){
    struct node*it=l->first;
    fprintf(f,"name,quantity,price\n");
    struct product*p=(struct product*)(it->val);
    fprintf(f,"%s,%d,%f\n",p->name,p->quantity,p->price);
    while (it!=l->last){
        it=it->next;
        struct product*p=(struct product*)(it->val);
        fprintf(f,"%s,%d,%f\n",p->name,p->quantity,p->price);
    }
    }
    else {
        fprintf(f,"name,quantity,price\n");
    }
    free(filename);
    fclose(f);
}
void create_user_file(char *cur_file_name,struct dbl *user_list){
    FILE *f;
    *user_list=create_list();
    char *file_name=(char*)malloc(sizeof(char)*100000);
    strcpy(file_name,cur_file_name);
    file_name[strlen(file_name)-6]='\0';
    strcpy(file_name+strlen(file_name),"users.csv");
    //printf("%s\n",file_name);
    f=fopen(file_name,"r");
    if (f==NULL){
        fclose(f);
        f=fopen(file_name,"w");
        fprintf(f,"name,surname,rights\n");
        fprintf(f,"root,root_surname,0\n");
        fclose(f);
        save_users(cur_file_name,user_list);
    }
    else{
        char*input=(char*)malloc(sizeof(char)*1000);
        fgets(input,101,f);
        while (fgets(input,101,f)!=NULL){
            char*it=strtok(input,",");
            char*surname=(char*)malloc(sizeof(char)*100),*user=(char*)malloc(sizeof(char)*100);
            int rights=0;
            strcpy(user,it);
            it=strtok(NULL,",");
            strcpy(surname,it);
            it=strtok(NULL,",");
            //printf("%s\n",it);
            for (int i=0; i<strlen(it)-1; i++){
                rights=rights*10+it[i]-'0';
            }
            struct user a;
            a=create_user(user,surname,rights);
            add_user(user_list,a);
            //free(user);
            //free(surname);
            /*char*it=strtok(input,",");
            struct product a;
            char *c=(char*)malloc(sizeof(char)*1001);
            strcpy(c,it);
            it=strtok(NULL,",");
            int q=0;
            for (int i=0; i<strlen(it); i++){
                q=q*10+it[i]-'0';
            }
            it=strtok(NULL,",");
            float p=0;
            int i=0;
            for (i=0;  it[i]!='.' && i<strlen(it); i++){
                p=p*10+it[i]-'0';
            }
            float power=1/10;
            i=i+1;
            for (int i; i<strlen(it); i++){
                p=p+(float)(((float)it[i]-'0'))*power;
                power=power/10;
            }
            a=create_product(c,q,p);
            add_product(product_list,a);*/
        }
        //print_users(user_list);
        free(input);
        free(file_name);
        fclose(f);
    }
}
void save_users(char*cur_file_name,struct dbl*l){
    char *filename=(char*)malloc(sizeof(char)*10001);
    strcpy(filename,cur_file_name);
    filename[strlen(filename)-6]='\0';
    strcpy(filename+strlen(filename),"users.csv");
    FILE *f=fopen(filename,"w");
    if (l->size){
    struct node*it=l->first;
    fprintf(f,"name,surname,rights\n");
    struct user*p=(struct user*)(it->val);
    fprintf(f,"%s,%s,%d\n",p->name,p->surname,p->rights);
    while (it!=l->last){
        it=it->next;
        struct user*p=(struct user*)(it->val);
        fprintf(f,"%s,%s,%d\n",p->name,p->surname,p->rights);
    }
    }
    else {
        fprintf(f,"name,surname,rights\n");
    }
    free(filename);
    fclose(f);
}
void create_orders_file(char *cur_file_name,struct dbl *user_list){
    FILE *f;
    //*user_list=create_list();
    char *file_name=(char*)malloc(sizeof(char)*100000);
    strcpy(file_name,cur_file_name);
    file_name[strlen(file_name)-6]='\0';
    strcpy(file_name+strlen(file_name),"orders.csv");
    f=fopen(file_name,"r");
    if (f==NULL){
        fclose(f);
        f=fopen(file_name,"w");
        fprintf(f,"name,surname,nr_items,items\n");
        fclose(f);
    }
    else{
        char*input=(char*)malloc(sizeof(char)*1000000);
        fgets(input,100001,f);
        while (fgets(input,100001,f)!=NULL){
            char*it=strtok(input,",");
            char*nr_items_c=(char*)malloc(sizeof(char)*100),*user=(char*)malloc(sizeof(char)*100),*surname=(char*)malloc(sizeof(char)*100);
            char *code=(char*)malloc(sizeof(char)*13);
            int nr=0;
            strcpy(user,it);
            it=strtok(NULL,",");
            strcpy(surname,it);
            it=strtok(NULL,",");
            strcpy(code,it);
            it=strtok(NULL,",");
            strcpy(nr_items_c,it);
            for (int j=0; j<strlen(nr_items_c); j++){
                nr=nr*10+nr_items_c[j]-'0';
            }
            //printf("%s %s\n",user,surname);
            struct order *cur_order=(struct order*)malloc(sizeof(struct order));
            *cur_order=create_order();
            cur_order->code=code;
           // printf("%d\n",nr);
            for (int j=0; j<nr; j++){
                //printf("%d\n",j);
                char*it=strtok(NULL,",");
                struct product a;
                char *c=(char*)malloc(sizeof(char)*1001);
                strcpy(c,it);
                it=strtok(NULL,",");
                int q=0;
                for (int i=0; it!=NULL && i<strlen(it); i++){
                    q=q*10+it[i]-'0';
                }
                it=strtok(NULL,",");
                float p=0;
                int i=0;
                for (i=0;  it!=NULL && it[i]!='.' && i<strlen(it); i++){
                    p=p*10+it[i]-'0';
                }
                float power=1/10;
                i=i+1;
                for (int i; i<strlen(it); i++){
                    p=p+(float)(((float)it[i]-'0'))*power;
                    power=power/10;
                }
                a=create_product(c,q,p);
                add_product(&(cur_order->products),a);
                cur_order->total_price+=a.price*a.quantity;
            }
            //print_products(&(cur_order->products));
            struct node*node_account_details=query_user(user_list,create_user(user,surname,0));
            struct user *account_details=((struct user*)(node_account_details->val));
            //printf("%s %s\n",account_details->name,account_details->surname);
            account_details->n_orders=0;
            if (node_account_details!=NULL){
                //printf("%s",account_details->name);
                account_details->n_orders++;
                struct node*p=(struct node*)malloc(sizeof(struct node));
                *p=create_node(cur_order);
                //print_products(&(cur_order->products));
                push_back(&(account_details->orders),p);
                //print_orders(account_details);
                //account_details->n_orders++;
            }
            //account_details->n_orders--;
            /*int rights=0;
            strcpy(user,it);
            it=strtok(NULL,",");
            //strcpy(surname,it);
            it=strtok(NULL,",");
            //printf("%s\n",it);
            for (int i=0; i<strlen(it)-1; i++){
                rights=rights*10+it[i]-'0';
            }
            struct user a;
            a=create_user(user,surname,rights);
            add_user(user_list,a);
            //free(user);
            //free(surname);
            /*char*it=strtok(input,",");
            struct product a;
            char *c=(char*)malloc(sizeof(char)*1001);
            strcpy(c,it);
            it=strtok(NULL,",");
            int q=0;
            for (int i=0; i<strlen(it); i++){
                q=q*10+it[i]-'0';
            }
            it=strtok(NULL,",");
            float p=0;
            int i=0;
            for (i=0;  it[i]!='.' && i<strlen(it); i++){
                p=p*10+it[i]-'0';
            }
            float power=1/10;
            i=i+1;
            for (int i; i<strlen(it); i++){
                p=p+(float)(((float)it[i]-'0'))*power;
                power=power/10;
            }
            a=create_product(c,q,p);
            add_product(product_list,a);*/
        }
        free(input);
        free(file_name);
        fclose(f);
    }
}
void save_orders(char*cur_file_name,struct dbl*l){
    char *filename=(char*)malloc(sizeof(char)*10001);
    strcpy(filename,cur_file_name);
    filename[strlen(filename)-6]='\0';
    strcpy(filename+strlen(filename),"orders.csv");
    FILE *f=fopen(filename,"w");
    if (l->size){
    struct node*it=l->first;
    fprintf(f,"name,surname,code,nr_items,items\n");
    while (it!=NULL){
        struct user*current_user=(struct user*)it->val;
        struct node*current_order_it=current_user->orders.first;
        //print_orders(current_user);
        //printf("\n");
        /*while (current_order_it!=NULL){

        }*/
        //printf("%d\n",current_user->n_orders);
        //printf("%s\n",current_user->name);
        while(current_order_it!=NULL){
            //printf("%s",current_user->name);
            //fprintf(stdout,"%s\n",current_user->name);
            int counter=0;
            struct order*cur_order=((struct order*)(current_order_it->val));
            struct node*it=cur_order->products.first;
            while (it!=NULL){
                it=it->next;
                counter++;
            }
            fprintf(f,"%s,%s,%s,%d,",current_user->name,current_user->surname,cur_order->code,counter);
            struct node*it2=((struct dbl*)current_order_it->val)->first;
            //print_products(((struct dbl*)current_order_it->val));
            while (it2!=NULL){
                struct product prod=*((struct product*)(it2->val));
                fprintf(f,"%s,%d,%f,",prod.name,prod.quantity,prod.price);
                it2=it2->next;
//                fprintf(f,"%s,%d,%f\n",p->name,p->quantity,p->price);
            }
            fprintf(f,"\n");
            current_order_it=current_order_it->next;
        }
        it=it->next;
    }
    free(filename);
    fclose(f);
    }
}
