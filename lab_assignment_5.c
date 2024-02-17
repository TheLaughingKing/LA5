// COP3502C Spring 2024 Lab Assignment 4
// Copyright 2024 Gradys_Alex

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char letter;
    struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
    int nodeCount;
    node * nodeTotal;
    for (nodeCount = 0, nodeTotal = head; nodeTotal != NULL; nodeTotal = (*nodeTotal).next)
    {
        nodeCount = nodeCount + 1;
    }
    return nodeCount;
}

// parses the string in the linkedList
// if the linked list is head -> |a|->|b|->|c|
// then toCString function wil return "abc"
char* toCString(node* head)
{
    int nodeCount = 0; 
    char * str = (char*)malloc((nodeCount + 1) * sizeof(char));

    node * nodeTotal;
    int i;

    for (nodeTotal = head, i = 0; nodeTotal != NULL; nodeTotal = (*nodeTotal).next, i = i + 1) 
    {
        str[i] = (*nodeTotal).letter;
    }
    str[i] = '\0';
    return str;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
    node * nodeUpdated = malloc(sizeof(node));
    if (!nodeUpdated) 
    {
        return;
    } 
    else 
    {
        (*nodeUpdated).letter = c;
        (*nodeUpdated).next = NULL;
    }

    if (*pHead == NULL) 
    {
        *pHead = nodeUpdated;
    } 
    else 
    {
        node * nodeTotal;
        for (nodeTotal = *pHead; (*nodeTotal).next != NULL; nodeTotal = (*nodeTotal).next) 
        {
        }
        (*nodeTotal).next = nodeUpdated;
    }    
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
    node * nodeTotal;
    for (nodeTotal = *pHead; nodeTotal != NULL; ) 
    {
        node * next = (*nodeTotal).next;
        free(nodeTotal);
        nodeTotal = next;
    }
    *pHead = NULL;
}

int main(void)
{
    int i, strLen, numInputs;
    node* head = NULL;
    char* str;
    char c;
    FILE* inFile = fopen("input.txt","r");

    fscanf(inFile, " %d\n", &numInputs);

    while (numInputs-- > 0)
    {
        fscanf(inFile, " %d\n", &strLen);
        for (i = 0; i < strLen; i++)
        {
            fscanf(inFile," %c", &c);
            insertChar(&head, c);
        }

        str = toCString(head);
        printf("String is : %s\n", str);

        free(str);
        deleteList(&head);

        if (head != NULL)
        {
            printf("deleteList is not correct!");
            break;
        }
    }
    fclose(inFile);
}