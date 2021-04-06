#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>
#include <dlfcn.h>

void (*hello_Ariel)(const char *);

bool init(){

    void *hdl = dlopen("./libHello.so", RTLD_LAZY );
    if( hdl == NULL){
        printf("erorrrrrrrrrrr  hdl\n");
        return false;
    }
    hello_Ariel = (void(*)(const char *))dlsym(hdl,"hello_Ariel");
    if(hello_Ariel == NULL){
        printf("erorrrrrrrrrrr dlsym \n");
        return false;
    }
    return true;
}
int main(){

    if( init()){
        hello_Ariel("Ariel");
    }
    else{
        printf("erorrrrrrrrrrr\n");
    }

    return 0;
}