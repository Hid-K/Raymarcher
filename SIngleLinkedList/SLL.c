#include "SLL.h"

void on_sigabrt (int signum)
{
  signal (signum, SIG_DFL);
  longjmp (env, 1);
}

void * getNodeDataBySerialNumber(SLL * list, size_t nodeNumber)
{
    SLLNode * currNode = list->first;
    for(size_t i = 0; i < nodeNumber; ++i)
    {
        if(currNode == NULL) return NULL;
        else currNode = currNode->next;
    };

    if(currNode == NULL) return NULL;
    else return currNode->data;
};

SLLNode * getNodeBySerialNumber(SLL * list, size_t nodeNumber)
{
    SLLNode * currNode = list->first;
    for(size_t i = 0; i < nodeNumber; ++i)
    {
        if(currNode == NULL) return NULL;
        else currNode = currNode->next;
    };

    return currNode;
};

SLL getSLL()
{
    SLL res =
    {
        NULL,
        NULL
    };

    return res;
};

void addNode(SLL * list, void * data)
{
    if(list->last != NULL)
    {
        list->last->next = (SLLNode *)malloc( sizeof( SLLNode ) );

        list->last = list->last->next;

        list->last->data = data;
        list->last->next = NULL;
    } else 
    {
        list->first = (SLLNode *)malloc( sizeof( SLLNode ) );
        list->last = list->first;

        list->last->next = NULL;
        list->last->data = data;
    }
};

void deleteNodeBySerialNumber(SLL * list, size_t nodeNumber)
{
    if(nodeNumber > 0)
    {
        SLLNode * prev = getNodeBySerialNumber(list, nodeNumber - 1);
        SLLNode * deletable = getNodeBySerialNumber(list, nodeNumber);
        SLLNode * next = getNodeBySerialNumber(list, nodeNumber + 1);

        if(next != NULL)
        {
            prev->next = next;
        } else
        {
            prev->next = NULL;
        }

        TRY
        {
            free(deletable->data);
        } CATCH
        {

        }
        CATCHEND;

        free(deletable);
    } else
    {
        SLLNode * deletable = list->first;
        SLLNode * next = deletable->next;

        list->first = next;
        free(deletable->data);
        free(deletable);
    }
};