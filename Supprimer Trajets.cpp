#include<iostream>
#include<windows.h>
#include<string>
#include<fstream>
#include"Trajets.1.h"
#include"Supprimer Trajets.h"

using namespace std;

int supprimertrajets()
{
	cout<<"	Seul les trajets saisis par ce menu peuvent être supprimer."<<endl;
	cout<<" Pour supprimer le trajet d'un vol,"<<endl;
	cout<<"	il faut supprimer le vol en question."<<endl;
	string videpartrecherche,viarriveerecherche;
	string ligne;
	string ligne2,ligne3;
	
	cout<<" "<<endl;
	cout<<"	Veuillez entrer la ville de depart : ";
	cin>>videpartrecherche;
	cout<<" "<<endl;
	cout<<"	Veuillez entrer la ville d'arrivee : ";
	cin>>viarriveerecherche;
	
	ifstream listetrajetauxiliaire("Dossier texte/listetrajetauxiliaire.txt");
	ofstream MonFlux("Dossier texte/listetrajetauxiliaire2.txt");	
	
	do
	{
			
		string videpart;
		string viarrivee;

		getline(listetrajetauxiliaire,videpart);
		getline(listetrajetauxiliaire,viarrivee);

		if(videpartrecherche!=videpart&&viarriveerecherche!=viarrivee)
		{
			ofstream MonFlux1("Dossier texte/listetrajetauxiliaire2.txt",ios::app);
			MonFlux<< videpart <<endl;
			MonFlux<< viarrivee <<endl;
			MonFlux<<""<<endl;
		}

	}while(getline(listetrajetauxiliaire, ligne));

	ofstream MonFlux2("Dossier texte/listetrajetauxiliaire.txt");
	ifstream listetrajetAuxiliaire("Dossier texte/listetrajetauxiliaire2.txt");
	ofstream MonFlux21("Dossier texte/listetrajetauxiliaire.txt",ios::app);

	do
	{				
		string videpart1,viarrivee1;
				
		getline(listetrajetAuxiliaire,videpart1);
		getline(listetrajetAuxiliaire,viarrivee1);

		MonFlux2<< videpart1 <<endl;
		MonFlux2<< viarrivee1 <<endl;
		MonFlux2<<"-------------------------------------------------------------------------"<<endl;
	}while(getline(listetrajetAuxiliaire, ligne2));

	string videpartFin,viarriveeFin,sautligne;

	ofstream monFlux31("Dossier texte/listetrajet.txt");
	ifstream listetrajetAuxiliaire2("Dossier texte/listetrajetauxiliaire.txt");
	ofstream monFlux3("Dossier texte/listetrajet.txt",ios::app);

	do
	{
		getline(listetrajetAuxiliaire2,videpartFin);
		getline(listetrajetAuxiliaire2,viarriveeFin);
				
		monFlux3<<videpartFin<<endl;
		monFlux3<<viarriveeFin<<endl;
		monFlux3<<"-------------------------------------------------------------------------"<<endl;
	}while(getline(listetrajetAuxiliaire2,ligne3));

	ifstream listevol("Dossier texte/listevol.txt");
	ofstream trajet("Dossier texte/listetrajet.txt",ios::app);
	string ligne4;
		
	do
	{ 
		string villeDepart2,villeArrivee2, numerovol,videpart2,viarrivee2,jour,mois,annee,heure,minute,prix;
		getline(listevol, numerovol); 
		getline(listevol, videpart2);
		getline(listevol, viarrivee2);
		getline(listevol, jour); 
		getline(listevol, mois);
		getline(listevol, annee);
		getline(listevol, heure);
		getline(listevol, minute);
		getline(listevol, prix);

		trajet<<videpart2<<endl;
		trajet<<viarrivee2<<endl;
		trajet<<"-------------------------------------------------------------------------"<<endl;
	}while(getline(listevol, ligne4));
	system("cls");
	cout<<" "<<endl;
	cout<<"			Votre vol a bien ete supprimer."<<endl;
	cout<<"			";
	Sleep(4000);
	trajets();
	return(0);
}