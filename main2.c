#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <editline.h>

void sigint(){
//    printf("|%d|\n",signo);
//    printf("342423423\n");
}

int main(void) {
    char *p;
    signal(SIGINT, sigint);
//    rl_set_complete_func(&my_rl_complete);

    while ((p = readline("CLI> ")) != NULL) {
        free(p);
    }

    return 0;
}