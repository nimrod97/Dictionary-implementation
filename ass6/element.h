/****************
*Nimrod Gabbay
*318322484
*01
*ass6
*****************/

#ifndef __ELEMENT_H
#define __ELEMENT_H

typedef struct Element Element;

Ptr createElement();
void destroy_Element(Ptr e);
void copy_Element(Ptr e1, Ptr e2);
int compare_Elements(Ptr e1, Ptr e2);
void print_Element(Ptr e);
Element* setElement(int key, int value);
int getValue(Element* e);



#endif