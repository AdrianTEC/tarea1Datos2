#include "doublelist.hpp"
template<typename T>


class Grafo
    {
        public:

            void fixRelationShip(int from,int to, double price);
            DoubleList<DoubleList<double>>* getRelations();
            constexpr static const double Maximo=1000000;
            DoubleList<double>* getRelations(int pos);
            void DeleteNode(int pos);
            void Add(T &data);
            T* get(int pos);
            Grafo();
            ~Grafo();



        private:
            void getVector(DoubleList<double>* List,int len,double value);
            DoubleList<DoubleList<double>>* matriz;
            void getPointerMaxValue(double *&ptr);
            DoubleList<T>* Nodes;
    };






template<typename T>
Grafo<T>::Grafo()
    {
        Nodes=new DoubleList<T>;
        matriz=new DoubleList<DoubleList<double>>;
    }
template<typename T>
void Grafo<T>::getPointerMaxValue(double *&ptr)
    {
        ptr=(double*)malloc(sizeof(double));
        *ptr=Maximo;
    }
template<typename T>
void Grafo<T>::getVector(DoubleList<double>* List,int len,double value)
    {
        double *temp;
        for(int i=0;i<len;i++)
            {
                temp=(double*)malloc(sizeof(double));
                *temp=value;
                List->add(*temp);
            }
    }
template<typename T>
T* Grafo<T>::get(int pos){return Nodes->get(pos);}
template<typename T>
DoubleList<double>* Grafo<T>::getRelations(int pos){return matriz->get(pos);}

template<typename T>
void Grafo<T>::Add(T &data)
    {
        double *temp;
        Nodes->add(data);
        int len=Nodes->getLen();
        for(int i=0;i<len-1;i++)
            {
                Grafo<T>::getPointerMaxValue(temp);
                matriz->get(i)->add(*temp);
            }
        DoubleList<double>* vector=new DoubleList<double>;
        getVector(vector,len,Maximo);
        matriz->add(*vector);
    }
template<typename T>
void Grafo<T>::DeleteNode(int pos)
    {
        Nodes->erase(pos);
        matriz->erase(pos);
        for(int i=0;i<matriz->getLen();i++)
            {
                matriz->get(i)->erase(pos);
            }
    }

template<typename T>
void Grafo<T>::fixRelationShip(int from, int to, double price)
    {
        *matriz->get(from)->get(to)=price;
    }

template<typename T>
DoubleList<DoubleList<double>>* Grafo<T>::getRelations()
    {
        return matriz;
    }

template<typename T>
Grafo<T>::~Grafo()
    {
        free(matriz);
        free(Nodes);
    }
