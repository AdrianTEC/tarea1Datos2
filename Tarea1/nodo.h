#ifndef NODO_H
#define NODO_H

template<class T>
class Nodo
{
    public:
        Nodo<T>* next;
        T data;
        Nodo();
        Nodo(T valor);
        void setData(T valor);
        void setNext(Nodo<T>* valor);
};

#endif // NODO_H
