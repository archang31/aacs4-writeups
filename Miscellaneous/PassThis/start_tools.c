#include "mytools.h"
#include <string.h>

struct tool* fabricateTool(char* tname, uint32_t tdur){
    struct tool* t = (struct tool*) malloc(sizeof(struct tool));
    sprintf(t->name, "%s", tname);
    t->durability = 0;
    return t;
}


struct toolbox* assembleToolbox(char* name, char* message, struct tool** tools, ssize_t count){
    struct toolbox* tb = (struct toolbox* ) malloc(sizeof(struct toolbox));
    //memset(tb, 0x00, sizeof(struct toolbox));
    memset(tb->name, 0x00, NAMESIZE);
    memset(tb->message,0x00, MSIZE);
    strcpy(tb->name, name);
    strcpy(tb->message, message);
    if (count == 0){
        tb->toolbelt = NULL;
        return tb;
    }
    struct tool** belt = malloc(sizeof(struct tool*) * count+1);
    for (int i=0; i<count; i++){
        belt[i] = (tools[i]);
    }
    belt[count] = NULL; 
    tb->toolbelt = belt;
    return tb;
}

int checkToolbox(struct toolbox* box){
    if (box->toolbelt == NULL) return 0;
    struct tool* curTool = box->toolbelt[0];
    int count = 0;
    char* namebuf = malloc(100);
    char* messbuf = malloc(MSIZE);
    strcpy(messbuf, box->message);
    strcpy(namebuf, box->name);
    printf("Box %s says: %s\n", namebuf, messbuf);
    while (curTool != NULL){
        count++;
        snprintf(namebuf, 100, "\tTool %d: %s\n", count, curTool->name);
        printf("%s", namebuf);
        curTool = box->toolbelt[count];
    }
    return count;
}

void addMessage(struct toolbox* tb, char* message){
    memset(tb->message, 0x00, MSIZE);
    strcpy(tb->message, message);
    tb->message[200] = 0x00;
}

struct toolbox* fillNewToolbox(char* name, char* message, char** names, uint32_t* durs, ssize_t count){
    if(count <= 0){
        return NULL;
    }

    struct tool** tools = malloc(sizeof(struct tool*) * count);
    for (int i=0; i<count; i++){
        struct tool* t = malloc(sizeof(struct tool));
        strncpy(t->name, names[i], NAMESIZE);
        t->durability = durs[i];
        tools[i] = t;
    }

    return assembleToolbox(name, message, tools, count);
}

int helperfunc(char* message){
    printf("%s\n", message);
}

void assignTool(struct tool* t, struct fastener* f, char* message){
    int (*funcptr)(char*) = NULL;
    funcptr = &helperfunc;
    struct use* us = malloc(sizeof(struct use));
    strcpy(us->message, message);
    t->use_struct = us;
    t->target = f;
};


struct tool* useTool(struct tool* t){

    if (t->durability > t->target->tightness && t->target->tightness != 0){
        printf("running: ");
        t->target->tightness = 0;
        t->use_struct->func(t->use_struct->message);
        t->target = NULL;
        return t;
    }

    if (t->durability < t->target->tightness){
        t->target->tightness -= t->durability;
        printf("%s isn't strong enough to tighten %s %d:%d\n", t->name, t->target->name, t->durability, t->target->tightness);
        t->durability = 0;
        return t;
    }

}