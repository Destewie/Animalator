#ifndef GIOCO_H
#define GIOCO_H
#include <fstream>
#include "NodoA.cpp"

class Gioco
{
	private:
		
		NodoA<string> *T;
	
		void Inizializza(NodoA<string> *att, ifstream &file);
		void Play(NodoA<string> *att);	//verrà chiamato dal suo corrispettivo pubblico
		void Salva(NodoA<string> *att, ofstream &file);	//verrà chiamato dal suo corrispettivo pubblico
		
		void PreOrder(NodoA<string> *att);	//debug
		
		
		
	public:
		
		Gioco();
		~Gioco();
		
		void Inizializza();
		
		void Intestazione();
		
		void Play();		//preorder modificato ad HOC
		
		void Aggiungi(string a, string d, NodoA<string> *att);

		void Salva(); 		//preorder modificato ad HOC
	
			
		void PreOrder();	//debug
};

#endif
