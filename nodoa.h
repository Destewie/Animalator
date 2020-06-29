#ifndef NODOA_H
#define NODOA_H
#include <iostream>
using namespace std;

template <class tipo>
class NodoA
{
	private:
		tipo info;
		NodoA<tipo> *Rlink;
		NodoA<tipo> *Llink;
		
	public:
		NodoA();
		NodoA(tipo x);
		~NodoA();
		
		tipo GetInfo();
		void SetInfo(tipo i);
		
		NodoA<tipo>* GetRlink();
		void SetRlink(NodoA<tipo> *n);
		
		NodoA<tipo>* GetLlink();
		void SetLlink(NodoA<tipo> *n);
		
		
		
};

#endif
