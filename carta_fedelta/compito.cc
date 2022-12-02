#include <iostream>
using namespace std;
#include <cstring>
#include "carta.h"
#include "bst.h"

/*
 * Funzione totalePunti che dati in ingresso un bst e due numeri di carta, inf e sup,
 * restituisce la somma dei punti accumulati dalle carte maggiori o uguali a inf e
 * minori o uguali a sup. Richiamare la funzione dal main dopo aver richiesto all’utente i due estremi.
 */
int totalePunti(bst b, int inf, int sup){
	int sum = 0;

	if(b == NULL)
		return 0;

	if(b->key >= inf && b->key <= sup)
		sum = sum + b->inf.puntiAccumulati;
	if(b->key >= inf)
		sum = sum + totalePunti(b->left, inf, sup);
	if(b->key <= sup)
		sum = sum + totalePunti(b->right, inf, sup);
		
	return sum;
}

/*
 * Funzione aggiorna che dati un bst e i dati relativi ad un acquisto,
 * aggiorna la carta nel bst aggiungendo i punti accumulati con l’acquisto, se esiste,
 * mentre segnala errore se non esiste. Richiamare aggiorna dal main per un numero a piacere di acquisti
 * e stampare il bst risultante.
 */
void aggiorna(bst& b, int carta, int punti){
	bnode* search = bst_search(b,carta);
	if(search == NULL)
		cout<<"Carta non esistente! "<<endl;

	else{
		search->inf.puntiAccumulati += punti;
	}
}

int main(){

	/* PUNTO 1
	 * Il file compito.cc deve contenere il codice per l’acquisizione di una sequenza di n carte,
	 * con n inserito da tastiera e dove i dati di ogni singola carta vengono inseriti riga per riga.
	 */
	int numeroCarta;
	tipo_inf carta;
	bst btree = NULL;

	int n;
	cout<<"Quante carte inserire? ";
	cin>>n;

	for(int i = 0; i < n; i++){

		cout<<"Numero carta: ";
		cin>>numeroCarta;

		cout<<"Nome e Cognome: ";
		cin.ignore();
		cin.getline(carta.nomeCognome, 40);

		cout<<"Punti accumulati: ";
		cin>>carta.puntiAccumulati;


		bnode* n = bst_newNode(numeroCarta, carta);
		bst_insert(btree, n);

		cout<<endl;
	}

	/* PUNTO 2 */
	print_bst(btree);

	/* PUNTO 3 */
	int inf, sup;

	cout<<"Limite inferiore? ";
	cin>>inf;

	cout<<"Limite superirore? ";
	cin>>sup;

	cout<<"Il totale dei punti è: "<<totalePunti(btree, inf, sup)<<endl;

	/* PUNTO 3 */
	int numCarta, punti;
	char flag;

	do{
	cout<<"Numero carta: ";
	cin>>numCarta;
	cout<<"Punti nuovo acquisto: ";
	cin>>punti;

	aggiorna(btree, numCarta, punti);

	cout<<"Per terminare premere *, altrimenti altro tasto ";
	cin>>flag;
	}while(flag != '*');

	print_bst(btree);

	cout<<"Success!"<<endl;
	return 0;
}

