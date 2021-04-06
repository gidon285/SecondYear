#define _GNU_SOURCE
#include <sched.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 10000
#define CYCLES 1000
char child_stack[STACK_SIZE+1];
void print(const char *text){

    for (int i = 0; i < CYCLES; i++){

        printf("Hello from: %s\n", text);
        usleep(1000000);
        
    }
}

int child(void *params){
    
    print("child_thread");
    return 0;
}

int main(){


    int pid1 =  clone(child, child_stack+ + STACK_SIZE, 0,0);
    if( pid1 == 0){

        int pid2 =  clone(child, child_stack+ + STACK_SIZE, 0,0);
        if( pid2 == 0){
            print("chid 2");
        }
        else{
            print("child 1");
        }

    }else{
        print("main");
    }   
    
}