#include "Gioco.h"
#include <Windows.h>
#include "MMSystem.h"

int main()
{
	system("color F0");
	PlaySound(TEXT("Music.wav"), NULL, SND_LOOP | SND_ASYNC);

	
	Gioco Game;
	char replay;

	do
	{
		Game.Inizializza();
		

	  //Game.PreOrder(); //debug
		
	system("cls");
                                                           
		Game.Intestazione();
		
		Game.Play();

		Game.Salva();

	system("cls");
		
		Game.Intestazione();
		
		cout<<" Rigiocare? [s/n]\n";
		
		
		cin>>replay;
	
	}while (replay == 's');
	
system("cls");
	
	Game.Intestazione();
	
	cout<<" Arrivederci!! :)\n\n";

	system ("pause>null");
	return 0;
}
