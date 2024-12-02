#include "objPosArrayList.h"
#include <iostream>
using namespace std;
// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{
    //create new array list with max size of 200
    aList = new objPos[ARRAY_MAX_CAP];
    listSize = 0;
    arrayCapacity = ARRAY_MAX_CAP;
}


//destructor
objPosArrayList::~objPosArrayList()
{
    delete [] aList;
}

int objPosArrayList::getSize() const
{
    return listSize;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    if (listSize == arrayCapacity){
        cout<<"Max capacity"<<endl;
        return;
    }
    for(int i = listSize;i>0;i--){
        aList[i] = aList[i-1];
    }
    listSize++;
    aList[0] = thisPos;
}

void objPosArrayList::insertTail(objPos thisPos)
{
    if (listSize == arrayCapacity){
        cout<<"Max capacity"<<endl;
        return;
    }
    aList[listSize] = thisPos;
    listSize++;
}

void objPosArrayList::removeHead()
{
    if(listSize ==0){
        cout<<"List is empty"<<endl;
        return;
    }
    for(int i=0;i<listSize-1;i++){
        aList[i]=aList[i+1];
    }
    listSize--;
}

void objPosArrayList::removeTail()
{
    if(listSize ==0){
        cout<<"List is empty"<<endl;
        return;
    }
    listSize--;
}

objPos objPosArrayList::getHeadElement() const
{
    return aList[0];
}

objPos objPosArrayList::getTailElement() const
{
    return aList[listSize-1];
}

objPos objPosArrayList::getElement(int index) const
{
    return aList[index];
}
