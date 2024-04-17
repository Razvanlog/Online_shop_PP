#include "order.h"

struct order create_order(){
    struct order a;
    //a.code=NULL;
    a.code=malloc(sizeof(char)*13);
    time_t t1;
    srand((unsigned)time(&t1));
    for (int i=0; i<12; i++){
        char t=rand()%127;
        while (!((t>='A' && t<='Z') || (t>='a' && t<='Z') || (t>='0' && t<='9'))){
        t=rand()%127;
        }
        a.code[i]=t;
    }
    a.code[12]='\0';
    a.total_price=0;
    a.products=create_list();
    return a;
}
