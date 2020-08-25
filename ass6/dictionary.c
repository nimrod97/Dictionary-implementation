/****************
*Nimrod Gabbay
*318322484
*01
*ass6
*****************/

#include <stdio.h>
#include <stdlib.h>
#include "dictionary.h"
#include "genericBinTree.h"
#include "element.h"
#include "result.h"

//Implementing the program with binTree
struct Dictionary {
    BinTree* tree;
};

/**********************************************************************************************
*Function Name:initDictionary
*Input:none
*Output: Dictionary* (pointer)
*Function Operation: the function allocates memory for empty dictionary and returns a pointer
                     to the dictionary 
 **********************************************************************************************/
Dictionary* initDictionary()
{
    Dictionary* dicPtr = (Dictionary*) malloc(sizeof(Dictionary));
    if (dicPtr == NULL)
        return NULL;
    BinTreeFunctions int_funcs = { createElement, destroy_Element, copy_Element, compare_Elements, print_Element };
    BinTree* t1 = createBinTree(int_funcs);
    if (t1 == NULL)
    {
        free(dicPtr);
        return NULL;
    }
    dicPtr->tree=t1;
    return dicPtr;
    
}

/**********************************************************************************************
*Function Name: destroyDictionary
*Input:Dictionary* d
*Output: none
*Function Operation: the function frees all the memory that was allocated for the dictionary
 **********************************************************************************************/
void destroyDictionary(Dictionary* d)
{
    destroyBinTree(d ->tree);
    free(d);
}

/******************************************************************************************************
*Function Name: sizeOfDictionary
*Input:Dictionary* d
*Output: int
*Function Operation: the function returns the number of elements(keys/values)that are in the dictionary
 ******************************************************************************************************/
int sizeOfDictionary(Dictionary* d)
{
    return sizeOfBinTree(d->tree);
}

/**************************************************************************************************
*Function Name: putInDictionary
*Input:Dictionary* d, int key, int value
*Output: Result (SUCCESS/ FAILURE/ MEM_ERROR)
*Function Operation: the function gets a key and a value and put them in the dictionary. If the key
                     exists in the dictionary, the function will update the key with the new value
 **************************************************************************************************/
Result putInDictionary(Dictionary* d, int key, int value)
{
    Result r1;
    // creating element and updating his key and value
    Element* e = setElement(key,value);
    if (e == NULL)
        return MEM_ERROR;
    r1 = addToBinTree(d->tree, e);
    // a case that key is already exists in the the dictionary
    if(r1==FAILURE)
    {
        //finding the key in order to update his value
       BinTree* t1 = findInBinTree(d->tree, e);
       r1= removeFromBinTree(&d->tree, e);
       if (r1 == MEM_ERROR)
       {
           destroy_Element(e);
           return MEM_ERROR;
       }
       //updating the key with the new value
       r1= addToBinTree(d->tree, e);
       if (r1 == MEM_ERROR)
       {
           destroy_Element(e);
           return MEM_ERROR;
       } 
        
    }
    //freeing the memory
    destroy_Element(e);
    return r1;

}

/**************************************************************************************************
*Function Name: getFromDictionary
*Input:Dictionary* d, int key
*Output: int
*Function Operation: the function gets a key and returns the value that belongs to the key. 
                     If the key does not exist, the function will return 0
 **************************************************************************************************/
int getFromDictionary(Dictionary* d, int key)
{
    int num;
    //creating and setting the element with the key
    Element* e = setElement(key,0);
    //searching for the key in the dictionary
    BinTree* t1 = findInBinTree(d->tree, e);
    //a case that the key is not in the dictionary
    if (t1 == NULL)
    {
        destroy_Element(e);
        return 0;
    }
    //freeing the memory
    destroy_Element(e);
    //pointing to the root that has the key
    e= createCopyOfValueInRoot(t1);
    if (e == NULL)
        return 0;
    //get the value of the key
    num = getValue(e);
   //freeing the memory
    destroy_Element(e);
    return num;
   
}

/**************************************************************************************************
*Function Name: removeFromDictionary
*Input:Dictionary* d, int key
*Output: Result (SUCCESS/ FAILURE/ MEM_ERROR)
*Function Operation: the function gets a key and removes it from the dictionary (with the value).
                     If the key does not exist, the function will not do nothing
 **************************************************************************************************/
Result removeFromDictionary(Dictionary* d, int key)
{
    Result r1;
    //creating and setting the element with the key
    Element* e = setElement(key,0);
    //searching for the key in the dictionary
    BinTree* t1 = findInBinTree(d->tree, e);
    //if the key doesn't exist in the dictionary
    if (t1 == NULL)
    {
        destroy_Element(e);
        return SUCCESS;
    }
    //else (the exists in the dictionary)
    r1= removeFromBinTree(&d->tree, e);
    //freeing the memory
    destroy_Element(e);
    return r1;
  
}

/**************************************************************************************************
*Function Name: printDictionary
*Input:Dictionary* d
*Output: none
*Function Operation: the function prints the dictionary, with the keys sorted
 **************************************************************************************************/
void printDictionary(Dictionary* d)
{
    if (sizeOfDictionary(d) == 0)
        printf("{}");
    else
    {
        printf("{");
        printInOrder(d->tree);
        printf("}");

    }

}


/**************************************************************************************************
*Function Name: createDictionaryFromArrays
*Input:int keys[], int values[], int size 
*Output: Dictionary* d
*Function Operation: the function gets two arrays with the same size- one of keys and the other of
                     values, and creates a dictionary according to them (using binTree)
 **************************************************************************************************/
Dictionary* createDictionaryFromArrays(int keys[], int values[], int size)
{
    Dictionary* d = initDictionary();
    if (d == NULL)
        return NULL;
    for (int i = 0; i < size; i++)
    {
        //putting each key and value in the dictionary
        putInDictionary(d, keys[i], values[i]);
    }
    
    return d;
    
}