#include<iostream>
#include<windows.h>
#include<string>
#include<fstream>
#include"Afficher Vols.h"
#include"Vols.1.h"

using namespace std;

int affichervols()
{
	cout<<" "<<endl;
	cout<<"		Voici la liste des differents vols saisis :"<<endl;
	cout<<" "<<endl;
	cout<<"-------------------------------------------------------------------------"<<endl;

	ifstream listevol("Dossier texte/listevol.txt");

	if(listevol)
	{
		string ligne;
		do
		{
		string numerovol, videpart, viarrivee, jour, mois, annee, heure, minute, prix;
 
		getline(listevol, numerovol); 
		if (numerovol!="")
			{
				cout <<"		Numero de vol : "<< numerovol << endl;
			}
		getline(listevol, videpart);
		if (videpart!="")
			{
				cout<<"		Ville de depart : "<<videpart<<endl;
			}
		getline(listevol, viarrivee);
		if(viarrivee!="")
			{
				cout<<"		Ville d'arrivee : "<<viarrivee<<endl;
			}
		getline(listevol, jour); 
		getline(listevol, mois);
		getline(listevol, annee);
		if(jour!="" && mois!="" &&annee!="")
			{
				cout <<"		Le "<< jour << "/"<<mois<<"/"<<annee<<endl;
			}
		

		getline(listevol, heure);
		getline(listevol, minute);
		if(heure!="" && minute!="")
			{
				cout<<"		Heure de depart : "<<heure<<"h"<<minute<<"min"<<endl;
			}
		getline(listevol, prix);
		if(prix!="")
			{
				cout<<"		Au prix de :"<<prix<<" euros"<<endl;
			}

		if(numerovol!="")
			{
				cout<<"-------------------------------------------------------------------------"<<endl;
			}
		}while(getline(listevol, ligne));
		
		cout<<" "<<endl;
		cout<<"		";
		system("pause");

		vols();//Retour Menu Vol
	}
	else
	{
		cout<<"		ERREUR : Impossible d'ouvrir le fichier de lecture."<<endl;
		Sleep(3000);
		vols();//Retour Menu Vol
	}
   return 0;
}