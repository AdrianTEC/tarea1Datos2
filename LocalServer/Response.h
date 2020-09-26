#include "Grafo.hpp"

class RESPONSE{

private:

    DoubleList<DoubleList<double>>* costos;
    DoubleList<DoubleList<int>> * componentes;

public:

    DoubleList<DoubleList<double>>* getPrices();
    DoubleList<DoubleList<int>>* getComponentes();
    void setPrices(DoubleList<DoubleList<double>>* E_prices);
    void setPredecessors(DoubleList<DoubleList<int>>* E_predecessors);
};
