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
                    NodeG<T> nuevo;
                    nuevo.data= valor;
                    nodos->add(nuevo);
                }
            void algo()
                {

                }

            void enlazar(T inicio, T final)
                {
                    node<NodeG<T>>* curr =nodos->first;

                    NodeG<T> nodoInicial;
                    NodeG<T> nodofinal;

                    for(int i=0; i<nodos->longitud;i++)
                        {
                            if(curr->data.data==inicio)
                                {
                                    nodoInicial= curr->data;
                                }
                            if(curr->data.data==final)
                                {
                                    nodofinal= curr->data;
                                }
                        }
                }
            void Floyd_Warshall()
                {

                }
            void moverseA()
                {

                }
    };
