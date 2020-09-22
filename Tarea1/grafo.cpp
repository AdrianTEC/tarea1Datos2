#include "linkedlist.cpp"
template<class T>
struct NodeG
    {
        LinkedList<node<T>> salidas;
        T data;
    };

template<class T>
class Grafo
    {
        LinkedList<NodeG<T>>* nodos;
        LinkedList<LinkedList<NodeG<T>>>* matrizDeDirecciones;
        public:
            Grafo()
                {
                    nodos= new LinkedList<NodeG<T>>();
                    matrizDeDirecciones= new  LinkedList<LinkedList<NodeG<T>>>();
                }
            void add(T valor)
                {
                    NodeG nuevo = new NodeG();
                    nuevo.data= valor;
                    nodos->add(nuevo);
                }
            void algo()
                {

                }
            void enlazar(T valor, T valor)
                {

                }
            void Floyd_Warshall()
                {

                }
            void moverseA()
                {

                }
    };
