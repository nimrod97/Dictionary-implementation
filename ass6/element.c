/****************
*Nimrod Gabbay
*318322484
*01
*ass6
*****************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "genericBinTree.h"
#include "element.h"


struct Element{
    int key;
    int value;
};

/************************************************************************************************
*Function Name:createElement
*Input:none
*Output: Ptr (void*)
*Function Operation: the function allocates memory for empty element and returns a pointer to the 
                     element
 ************************************************************************************************/
Ptr createElement()
{
    Element* e = (Element*)malloc(sizeof(Element));
    if (e == NULL)
        return NULL;
    return e;
}

/************************************************************************************************
*Function Name: destroy_Element
*Input: Ptr e (void*)
*Output: none
*Function Operation: the function fress the memory that was allocated for the element
 ************************************************************************************************/
void destroy_Element(Ptr e) {
    free(e);
}

/************************************************************************************************
*Function Name: copy_Element
*Input: Ptr e1, Ptr e2 (both void*)
*Output: none
*Function Operation: the function gets two pointers of elements and copies the details of the 
                     first element to the second element
 ************************************************************************************************/
void copy_Element(Ptr e1, Ptr e2) {

    Element* p1 =(Element*) e1;
    Element* p2 =(Element*) e2;
    p1->key = p2->key;
    p1->value = p2->value;
}


/**************************************************************************************************
*Function Name: compare_Elements
*Input: Ptr e1, Ptr e2 (both void*)
*Output: int
*Function Operation: the function gets two pointers of elements and returns the difference bewtween
                     the keys of them in order to determine which of them is bigger
 **************************************************************************************************/
int compare_Elements(Ptr e1, Ptr e2) {
    Element* p1  = (Element*)e1;
    Element* p2 =  (Element*)e2;
    return p1->key - p2->key;
}


/**************************************************************************************************
*Function Name: print_Element
*Input: Ptr e (void*)
*Output: none
*Function Operation: the function gets an element and prints the key and the value of it
 **************************************************************************************************/
void print_Element(Ptr e) {
    Element* p = (Element*)e;
    printf("[%d:%d]",p->key,p->value);
}


/************************************************************************************************
*Function Name: setElement
*Input: int key, int value
*Output: Element* (Pointer)
*Function Operation: the function creates an element and setting his key and value.
                     After that, the function returns the element (the pointer)
 ************************************************************************************************/
Element* setElement(int key, int value)
{
    Element* e = createElement();
    if (e == NULL)
        return NULL;
    e->key = key;
    e->value = value;
    return e;
}


/************************************************************************************************
*Function Name: getValue
*Input: Element* e (pointer)
*Output: int
*Function Operation: the function gets an element and returns his value
 ************************************************************************************************/
int getValue(Element* e)
{
    return e->value;
}



