#include <sched.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>

int main(){

    int pid = fork();
    if( pid == 0){

        chdir("~");
        setsid();
        printf("starting my daemon.\n");

        close(stdout);
        close(stdin);
        close(stderr);

        openlog("myDaemon", LOG_PID,LOG_DAEMON);
        syslog(LOG_NOTICE, "deamon started 1");
        usleep(300000);
        syslog(LOG_NOTICE, "working...");
        usleep(300000);
        syslog(LOG_NOTICE, "daemon finised");

    }else{
        printf("deamon PID is : %d\n",pid);
    }
}
