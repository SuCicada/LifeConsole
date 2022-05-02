#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <editline.h>
#include <string.h>
#include "life.h"

#define HISTORY "/tmp/.life-console-history"
static char *list[] = {
        "act_date ", "time ",
        "bsd ", "cli ", "ls ", "cd ", "malloc ", "tee "
};
static const int list_num = sizeof(list) / sizeof(char *);

void sigint() {
//    printf("|%d|\n",signo);
//    printf("342423423\n");
}

static char *my_rl_complete(char *token, int *match) {
    int i;
    int index = -1;
    int matchlen = 0;
    int count = 0;

    for (i = 0; i < list_num; i++) {
        int partlen = strlen(token); /* Part of token */

        if (!strncmp(list[i], token, partlen)) {
            index = i;
            matchlen = partlen;
            count++;
        }
    }
    if (count == 1) {
        *match = 1;
        return strdup(list[index] + matchlen);
    }
    return NULL;
}

static int my_rl_list_possib(char *token, char ***av) {
    int i, total = 0;
    char **copy;

    int num = list_num;
    copy = malloc(num * sizeof(char *));
    for (i = 0; i < num; i++) {
        if (!strncmp(list[i], token, strlen(token))) {
            copy[total] = strdup(list[i]);
            total++;
        }
    }
    *av = copy;
    return total;
}

el_status_t do_suspend(void) {
    puts("Abort!");
    return CSstay;
}

char *prompt = "SU> ";

int main(void) {
    char *line;
    signal(SIGINT, sigint);
    // tab 是否补全
    rl_set_complete_func(&my_rl_complete);
    // 空行,tab 提示
    rl_set_list_possib_func(&my_rl_list_possib);
    read_history(HISTORY);
    while ((line = readline(prompt)) != NULL) {
        parse_line(line);
//        if (*line != '\0')
//            printf("\t\t\t|%s|\n", line);
        free(line);
    }
    write_history(HISTORY);
    printf("\n");
    return 0;
}