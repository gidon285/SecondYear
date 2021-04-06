#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void print(const char *text){

    for (int i = 0; i < 20; i++){
        printf("hello from %s \n", text);
        usleep(1000000);
    }
}
int main(){

    int pid1 = fork();
    if( pid1 == 0){

        int pid2 = fork();
        if( pid2 == 0){
            print("chid 2");
        }
        else{
            print("child 1");
        }

    }else{
        print("main");
    }   

return 0;
}
