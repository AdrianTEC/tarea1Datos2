#include "nodo.h"
template<typename T>
Nodo<T>::Nodo()
{

}
template<typename T>
Nodo<T>::Nodo(T valor)
{
    this->data=valor;
    this->next=nullptr;
}
template<typename T>
void Nodo<T>::setData(T valor)
    {

        this->data=valor;
    }
template<typename T>
void Nodo<T>::setNext(Nodo<T>* valor)
{
    this->next=valor;
}
