#include<iostream>
#include<windows.h>
#include<string>
#include<fstream>
#include"Voyageur.1.h"
#include"Supprimer Voyageur.h"

using namespace std;

int supprimervoyageur()
{
	string numerorecherche, ligne, ligne2;
	
	cout<<" "<<endl;
	cout<<"	Veuillez entrer le numero de passeport : ";
	cin>>numerorecherche;
	
	ifstream listevoyageur("Dossier texte/listevoyageur.txt");
	ofstream MonFlux("Dossier texte/listevoyageurauxiliaire.txt");

	do
	{
		string sautligne1, sautligne2, sautligne3, numeroDePasseport;

		getline(listevoyageur,sautligne1);
		getline(listevoyageur,sautligne2);
		getline(listevoyageur,sautligne3);
		getline(listevoyageur,numeroDePasseport);

		if(numerorecherche!=numeroDePasseport)
		{
			ofstream MonFlux("Dossier texte/listevoyageurauxiliaire.txt",ios::app);
			MonFlux<<" "<<endl;
					
			MonFlux<< sautligne1 <<endl;
			MonFlux<< sautligne2 <<endl;
			MonFlux<< sautligne3 <<endl;
			MonFlux<< numeroDePasseport <<endl;
		}

	}while(getline(listevoyageur, ligne));

	ifstream listevoyageurauxiliaire("Dossier texte/listevoyageurauxiliaire.txt");
	ofstream MonFlux2("Dossier texte/listevoyageur.txt");

	while(getline(listevoyageurauxiliaire, ligne2))
	{
		ofstream MonFlux2("Dossier texte/listevoyageur.txt",ios::app);

		string sautligne11, sautligne21, sautligne31, numeroDePasseport1;
				
		getline(listevoyageurauxiliaire,sautligne11);
		getline(listevoyageurauxiliaire,sautligne21);
		getline(listevoyageurauxiliaire,sautligne31);
		getline(listevoyageurauxiliaire, numeroDePasseport1);
							
		MonFlux2<< sautligne11 <<endl;
		MonFlux2<< sautligne21 <<endl;
		MonFlux2<< sautligne31 <<endl;				
		MonFlux2<< numeroDePasseport1 <<endl;
		MonFlux2<<"-------------------------------------------------------------------------"<<endl;
	}
	system("cls");
	cout<<" "<<endl;
	cout<<"			Votre voyageur a bien ete supprimer."<<endl;
	cout<<"			";
	Sleep(4000);
	voyageur();
	return(0);
}