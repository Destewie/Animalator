#include "gioco.h"

Gioco::Gioco()
{
}


Gioco::~Gioco()
{
}

//--------------------------------------------------------------------------------------- 
//--------------------------------------------------------------------------------------- INIZIALIZZA DA FILE 

void Gioco :: Inizializza()
{
	string contenutoIniz;
	
	ifstream mioFile;
	mioFile.open("Animali.txt");
	
	string contenuto;
	getline(mioFile, contenuto);
	
	T = new NodoA<string>(contenuto);
	
	Inizializza(T, mioFile);
	
	mioFile.close();
}

//--------------------------------------------------------------------------------------- 

void Gioco :: Inizializza(NodoA<string> *att, ifstream &fileAnimali)
{
	string contenuto;
	getline(fileAnimali, contenuto);
	
	if(att->GetInfo()[0] == '?')
	{
		NodoA<string> *nuovoS = new NodoA<string>(contenuto);
		att-> SetLlink(nuovoS);
		if(contenuto[0] == '?')
		{
			Inizializza (nuovoS, fileAnimali);
		}
		
		
		getline(fileAnimali, contenuto);
		
		NodoA<string> *nuovoD = new NodoA<string>(contenuto);
		att-> SetRlink(nuovoD);
		if(contenuto[0] == '?')
		{
			Inizializza (nuovoD, fileAnimali);
		}
	}		
}

//--------------------------------------------------------------------------------------- 
//---------------------------------------------------------------------------------------	AGGIUNTA DI UN NUOVO ANIMALE

void Gioco :: Aggiungi(string a, string d, NodoA<string> *att)
{
	NodoA<string>* nuovoR = new NodoA<string>(att->GetInfo());
	NodoA<string>* nuovoL = new NodoA<string>(a);
	
	att->SetInfo(d);
	
	att->SetRlink(nuovoR);
	att->SetLlink(nuovoL);
}

//---------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------	PLAY

void Gioco :: Play()
{	
	Play(T);
}

//---------------------------------------------------------------------------------------

void Gioco :: Play(NodoA<string> *att)
{	
	string scelta;	

	if(att != NULL)
	{
		if(att->GetLlink()==NULL && att->GetRlink()==NULL)		//vede se sei su un animale (nodo foglia)
		{
			cout<<"E' per caso un/a "<<att-> GetInfo()<<"? [s/n]\n";
			cin>>scelta;
			if(scelta == "s")
			{
				cout<<"\nANIMALATOR HA VINTO!!\n";
				system("pause>null");
			}
			if(scelta == "n")
			{
				cout<<"\nOh, peccato, non conosco il tuo animale...\n";
				cout<<"Per curiosita', a che animale stai pensando?\n";
				string animal;
				fflush(stdin);
				getline(cin, animal);
				
				cout<<"\nCosa differenzia un/a "<<animal<< " da un/a "<<att-> GetInfo()<<"?\n";
				string diff;
				fflush(stdin);
				getline(cin, diff);
			//	diff = "?" + diff + "?";
				Aggiungi(animal, diff, att);
			}
		}
		
		else
		{
			string temp = att-> GetInfo();
			temp[0] = ' ';
			cout<<temp<<" [s/n]\n";
			cin>>scelta;
			cout<<endl;
			if(scelta == "s")
			{
				Play(att-> GetLlink());
			}
			if(scelta == "n")
			{
				Play(att-> GetRlink());
			}
		}

	}
}

//---------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------		SAVE

void Gioco :: Salva()
{	
	ofstream mioFile;
	mioFile.open("Animali.txt");
	Salva(T, mioFile);
	mioFile.close();
}

//---------------------------------------------------------------------------------------

void Gioco :: Salva(NodoA<string> *att, ofstream &fileAnimali)
{	
	if(att != NULL)
	{
		if(att->GetLlink()!= NULL && att->GetRlink()!= NULL)	//se è una domanda
		{
			if(att->GetInfo()[0] == '?')				//condizione per aggiungere o meno i punti di domanda alla fine
				fileAnimali<<att-> GetInfo()<<endl;
			else
				fileAnimali<<"?"<<att-> GetInfo()<<"?"<<endl;
		}
		else
		{
			fileAnimali<<att-> GetInfo()<<endl;
		}
		
		Salva(att-> GetLlink(), fileAnimali);
		Salva(att-> GetRlink(), fileAnimali);
	}
}





//---------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------	PRE ORDER //debug

void Gioco :: PreOrder()
{	
	PreOrder(T);
}

//---------------------------------------------------------------------------------------

void Gioco :: PreOrder(NodoA<string> *att)
{	
	if(att != NULL)
	{
		cout<<att-> GetInfo()<<endl;
		PreOrder(att-> GetLlink());
		PreOrder(att-> GetRlink());
	}
}

//---------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------

void Gioco :: Intestazione()
{	
		cout<<endl<<endl;
		cout<<" 	   _|_|    _|      _|  _|_|_|  _|      _|    _|_|    _|          _|_|    _|_|_|_|_|    _|_|    _|_|_|    "<<endl;     
	   	cout<<" 	 _|    _|  _|_|    _|    _|    _|_|  _|_|  _|    _|  _|        _|    _|      _|      _|    _|  _|    _|  "<<endl;
		cout<<" 	 _|_|_|_|  _|  _|  _|    _|    _|  _|  _|  _|_|_|_|  _|        _|_|_|_|      _|      _|    _|  _|_|_|    "<<endl;
		cout<<" 	 _|    _|  _|    _|_|    _|    _|      _|  _|    _|  _|        _|    _|      _|      _|    _|  _|    _|  "<<endl;
		cout<<" 	 _|    _|  _|      _|  _|_|_|  _|      _|  _|    _|  _|_|_|_|  _|    _|      _|        _|_|    _|    _|  "<<endl<<endl;
                                                                                       
		cout<<"			          Pensa ad un animale e io provero' ad indovinarlo\n\n"<<endl<<endl;
}







