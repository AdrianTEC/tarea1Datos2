#include "DoubleList.hpp"
template<typename T>
class Grafo{
public:
    Grafo();
    ~Grafo();
    T* getNode(int pos);
    DoubleList<double>* getRelations(int pos);
    DoubleList<DoubleList<double>>* getRelations();
    void AddNode(T &data);
    void DeleteNode(int pos);
    void fixRelationShip(int from,int to, double price);
    constexpr static const double maxValue=9999999.9;

private:
    DoubleList<T>* Nodes;
    DoubleList<DoubleList<double>>* RelationMatrix;

    void getPointerMaxValue(double *&ptr);
    void getVector(DoubleList<double>* List,int len,double value);
};
template<typename T>
Grafo<T>::Grafo()
{
    Nodes=new DoubleList<T>;
    RelationMatrix=new DoubleList<DoubleList<double>>;
}
template<typename T>
void Grafo<T>::getPointerMaxValue(double *&ptr)
{
    ptr=(double*)malloc(sizeof(double));
    *ptr=maxValue;
}
template<typename T>
void Grafo<T>::getVector(DoubleList<double>* List,int len,double value)
{
    double *temp;
    for(int i=0;i<len;i++){
        temp=(double*)malloc(sizeof(double));
        *temp=value;
        List->add(*temp);
    }
}
template<typename T>
T* Grafo<T>::getNode(int pos) {
    return Nodes->get(pos);
}
template<typename T>
DoubleList<double>* Grafo<T>::getRelations(int pos) {
    return RelationMatrix->get(pos);
}
template<typename T>
void Grafo<T>::AddNode(T &data) {
    double *temp;
    Nodes->add(data);
    int len=Nodes->getLen();
    for(int i=0;i<len-1;i++){
        Grafo<T>::getPointerMaxValue(temp);
        RelationMatrix->get(i)->add(*temp);
    }
    DoubleList<double>* vector=new DoubleList<double>;
    getVector(vector,len,maxValue);
    RelationMatrix->add(*vector);
}
template<typename T>
void Grafo<T>::DeleteNode(int pos) {
    Nodes->erase(pos);
    RelationMatrix->erase(pos);
    for(int i=0;i<RelationMatrix->getLen();i++){
        RelationMatrix->get(i)->erase(pos);
    }
}
template<typename T>
void Grafo<T>::fixRelationShip(int from, int to, double price) {
    *RelationMatrix->get(from)->get(to)=price;
}
template<typename T>

DoubleList<DoubleList<double>>* Grafo<T>::getRelations(){
    return RelationMatrix;
}
template<typename T>
Grafo<T>::~Grafo(){
    free(RelationMatrix);
    free(Nodes);
}

