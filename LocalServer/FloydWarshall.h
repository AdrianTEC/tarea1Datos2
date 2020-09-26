#include "Response.h"

//headers


RESPONSE* Floyd(DoubleList<DoubleList<double>> &prices);
//headers
void FloydInit(DoubleList<DoubleList<double>>*& prices, DoubleList<DoubleList<int>>*& predecessors);
//headers
void FloydProcess(DoubleList<DoubleList<double>>*& prices, DoubleList<DoubleList<int>>* & predecessors);
//headers
void calculo(int i,int j, int k,DoubleList<DoubleList<double>>*& prices, DoubleList<DoubleList<int>>*& predecessors);
//headers
DoubleList<int>* getPath(RESPONSE* response,int start,int end);
//headers
double getPrice(RESPONSE* response,int start,int end);
