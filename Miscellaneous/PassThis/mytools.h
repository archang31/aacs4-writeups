#ifndef __MYTOOLS
#define __MYTOOLS

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

#define NAMESIZE 20
#define MSIZE 200

static int placehoder(char* a){return 0;}

struct use{
    int (*func)(char*);
    char message[MSIZE];
};

struct fastener{
    char name[NAMESIZE];
    uint16_t tightness;
};

struct tool{
    char name[NAMESIZE];
    uint8_t durability;
    struct fastener* target;
    struct use* use_struct;
};

struct toolbox{
    char name[NAMESIZE];
    char message[MSIZE];
    struct tool** toolbelt; 
};


//Make a new tool with the specified name and durability
struct tool* fabricateTool(char* tname, uint32_t tdur);

//Given a set of tools, generate a toolbox with a name and a message
struct toolbox* assembleToolbox(char* name, char* message, struct tool** tools, ssize_t count);

//Count the number of tools in the toolbox, and also read their descriptions and durabilities
int checkToolbox(struct toolbox* box);

//Make a set of tools from a list of names and durabilities, and then turn that into a toolbox
struct toolbox* fillNewToolbox(char* name, char* message, char** names, uint32_t* durs, ssize_t count);

//Add a message to a toolbox
void addMessage(struct toolbox* tb, char* message);

//Assign a fastener to a tool, and specify what it does when it's used
void assignTool(struct tool* t, struct fastener* f, char* message);

//Use the tool, using the use_struct field in the tool to know what to do, return -1 if something goes wrong
struct tool* useTool(struct tool* t);

#endif