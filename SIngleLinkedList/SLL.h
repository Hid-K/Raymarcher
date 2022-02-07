#ifndef RAYMARCHING_SLL_H
#define RAYMARCHING_SLL_H

#include <stdio.h>

#include <string.h>
#include <stdlib.h>

#include <setjmp.h>

jmp_buf env;

#define TRY \
{ \
  if (setjmp (env) == 0) { \
    signal(SIGABRT, &on_sig); \
    signal(SIGSEGV, &on_sig);

#define CATCH \
    signal (SIGABRT, SIG_DFL); \
    signal(SIGSEGV, SIG_DFL); \
  } \
  else \
  {

#define CATCHEND \
  } \
} 

typedef struct SLLNode SLLNode;

typedef struct SLLNode
{
    SLLNode * next;
    void * data;
} SLLNode;

typedef struct SLL
{
    SLLNode * first;
    SLLNode * last;
} SLL;

void * getNodeDataBySerialNumber(SLL * list, size_t nodeNumber);
SLLNode * getNodeBySerialNumber(SLL * list, size_t nodeNumber);

SLL getSLL();

void addNode(SLL * list, void * data);

void deleteNodeBySerialNumber(SLL * list, size_t nodeNumber);

void * sllToRaw(SLL * list);


#endif