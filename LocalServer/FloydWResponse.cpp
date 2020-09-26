#include "Response.h"
/**
 * @brief FloydWResponse::getPredecessors
 * @return
 */
DoubleList<DoubleList<int>>* RESPONSE::getComponentes()
{
    return componentes;
}
/**
 * @brief FloydWResponse::getPrices
 * @return
 */
DoubleList<DoubleList<double>>* RESPONSE::getPrices()
{
    return costos;
}
/**
 * @brief FloydWResponse::setPrices
 * @param E_prices
 */
void RESPONSE::setPrices(DoubleList<DoubleList<double>> *E_prices)
{
    costos=E_prices;
}
/**
 * @brief FloydWResponse::setPredecessors
 * @param E_predecessors
 */
void RESPONSE::setPredecessors(DoubleList<DoubleList<int>>*E_predecessors)
{
    componentes=E_predecessors;
}

