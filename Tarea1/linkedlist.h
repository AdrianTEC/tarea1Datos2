#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "nodo.h"

using namespace std;
template<typename T>
class LinkedList
{

private:

    Nodo<T>* head;

public:
    int lenght;
    LinkedList();
    void setHeader(T valor);
    Nodo<T>* getHeader();
    void exploreList();
    void add(T valor);
    void add(T valor,Nodo<T>*);
};


template class  LinkedList<int>;
#endif // LINKEDLIST_H
