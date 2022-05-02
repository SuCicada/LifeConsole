//
// Created by SuCicada on 5/2/2022.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "life.h"
#include "stringlib.h"
#include <time.h>

typedef void (*syntax_func)();

typedef struct {
    char *line;
    syntax_func action;
} Syntax;

void act_time() {
    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    char *res = malloc(1024);
    sprintf(res, "%02d:%02d:%02d",
            timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
    puts(res);
    puts("");
    free(res);
//    printf("Current local time and act_date: %s", asctime(timeinfo));
}

void act_date() {

}

Syntax Dictionary[] = {
        {"time",     act_time},
        {"act_date", act_date},
};

syntax_func find_func(char *str) {
    // todo 使用更高效的查找方式
    int dict_len = sizeof(Dictionary) / sizeof(Syntax);
    for (int i = 0; i < dict_len; i++) {

        if (!strncmp(Dictionary[i].line, str, strlen(str))) {
            return Dictionary[i].action;
        }
    }
    return NULL;
}

void parse_line(char *str) {
    s_trim(str);
    syntax_func action = find_func(str);
    if (action) {
        action();
    }
}


