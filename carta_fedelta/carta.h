/*******************************/
/* HEADER MODULO "carta" 	   */
/*******************************/

struct tipo_inf{
	char nomeCognome[40];
	int puntiAccumulati;
};

int compare(tipo_inf,tipo_inf);
void copy(tipo_inf&,tipo_inf);
void print(tipo_inf);
