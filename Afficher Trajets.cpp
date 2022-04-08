#include<iostream>
#include<windows.h>
#include<string>
#include<fstream>
#include"Trajets.1.h"
#include"Afficher Trajets.h"

using namespace std;

int affichertrajets()
{
	cout<<" "<<endl;
	cout<<"		Voici la liste des differents trajets saisis :"<<endl;
	cout<<" "<<endl;
	cout<<"-------------------------------------------------------------------------"<<endl;

	ifstream listetrajet ("Dossier texte/listetrajet.txt");

	if(listetrajet)
	{
		string ligne;
		do
		{ 
			string villeDepart; 
			string villeArrivee;

			getline(listetrajet, villeDepart);
			if(villeDepart!="")
			{
				cout <<"		La ville de depart est : "<<villeDepart<< endl;
			}
			getline(listetrajet, villeArrivee);
			if(villeArrivee!="")
			{
				cout<<"		La ville d'arrivee est : "<<villeArrivee<<endl;
			}
			if(villeArrivee!="")
			{
				cout<<"-------------------------------------------------------------------------"<<endl;
			}

		}while(getline(listetrajet, ligne));

		cout<<"		";
		system("pause");
		trajets();
	}
	else
	{
		cout<<"		ERREUR : Impossible d'ouvrir le fichier de lecture." << endl;
		Sleep(3000);
		trajets();//Retour Menu Trajets
	}
	return 0;
}