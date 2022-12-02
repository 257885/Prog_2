#include <iostream>
using namespace std;
#include <cstring>

#include "carta.h"

int compare(tipo_inf i, tipo_inf j){
	int cmp = strcmp(i.nomeCognome, j.nomeCognome);
	return cmp;
}

void copy(tipo_inf& i,tipo_inf j){
	i = j;
}

void print(tipo_inf i){
	cout<<i.nomeCognome<<endl;
	cout<<i.puntiAccumulati<<endl;
}
