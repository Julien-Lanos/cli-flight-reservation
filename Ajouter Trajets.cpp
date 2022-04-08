#include<iostream>
#include<windows.h>
#include<string>
#include<fstream>
#include"Ajouter Trajet.h"
#include"Trajets.1.h"

using namespace std;

int ajoutertrajets() // ajouttrajet()
{
	string depart,arrivee,ligne ;
	int choix, compteur(0);

	ifstream listevol("Dossier texte/listevol.txt");
	ofstream monflux99("Dossier texte/listetrajet.txt");
		
	cout<<""<<endl;
	cout<<"		Veuillez entrer la ville de depart : ";
	cin>>depart;
	cout<<""<<endl;
	cout<<"		Veuillez entrer la ville d'arrivee : ";
	cin >>arrivee;

	while(getline(listevol, ligne))
	{ 
		string numerovol,videpart,viarrivee,jour,mois,annee,heure,minute,prix;
		getline(listevol, numerovol); 
		getline(listevol, videpart);
		getline(listevol, viarrivee);
		getline(listevol, jour); 
		getline(listevol, mois);
		getline(listevol, annee);
		getline(listevol, heure);
		getline(listevol, minute);
		getline(listevol, prix);		

		if(depart==numerovol && arrivee==videpart)
		{
			compteur=1;
			cout<<" "<<endl;
			cout<<"		Ce trajet existe deja !"<<endl;
			cout<<"		";
			system("pause");
		} 	
		ofstream monflux99("Dossier texte/listetrajet.txt", ios::app);
		monflux99<<numerovol<<endl;
		monflux99<<videpart<<endl;
		monflux99<<"---------------------------------------------------------------------"<<endl;
	}	
	string ligne2;
		
	if(compteur!=1)//Voyons si nous voulons enregistrer les valeurs des variables demadées ci-dessus dans un fichier.
	{
		cout<<" "<<endl;
		cout<<"	******* Voulez vous enregistrer vos donnees ? *******"<<endl;
		cout<<"	*                                                   *"<<endl;
		cout<<"	*                   1 : Oui                         *"<<endl;
		cout<<"	*                   2 : Non                         *"<<endl;
		cout<<"	*                                                   *"<<endl;
		cout<<"	*****************************************************"<<endl;
		cout<<" "<<endl;
		cout<<" "<<endl;
		cout<<"	     Votre choix : ";
					
		cin>>choix ;

		if(choix==1) //Oui enregistrons !
		{
			ofstream monFluxB("Dossier texte/listetrajetauxiliaire.txt",ios::app);
    
			monFluxB<<depart<<endl;
			monFluxB<<arrivee<<endl;
			monFluxB<<"---------------------------------------------------------------------"<<endl;

					
			ofstream monFluxD("Dossier texte/listetrajet.txt",ios::app);
			ifstream listetrajet3 ("Dossier texte/listetrajetauxiliaire.txt");
					
			if(monFluxD)
			{
				string ligne3;
				do
				{ 
					string depart,arrivee;
					getline(listetrajet3, depart); 
					getline(listetrajet3, arrivee);			
					
					monFluxD << depart << endl;
					monFluxD <<arrivee << endl;
					monFluxD <<"---------------------------------------------------------------------"<<endl;
				}while(getline(listetrajet3, ligne3));

				system("cls");
				cout<<" "<<endl;
				cout<<"	* * * * *  Votre trajet a ete enregistre. * * * * * *"<<endl;
				cout<<"				"<<endl;
				Sleep(3000);
				trajets();//retour menu trajet
			}
			else
			{
				cout<<" "<<endl;
				cout<<"     ERREUR : Impossible d'ouvrir le fichier." << endl;
				cout<<"     ";
				Sleep(3000);
				trajets();
			}
		}		
		else if(choix==2)//Non, n'enregistrons pas !
		{					
			trajets();//revenir menu trajet
		}
	}
	if(compteur==1)
	{
		ofstream monFluxD("Dossier texte/listetrajet.txt",ios::app);
		ifstream listetrajet3 ("Dossier texte/listetrajetauxiliaire.txt");

		if(monFluxD)
		{
			string ligne3;
			do
			{ 
				string depart,arrivee;
				getline(listetrajet3, depart); 
				getline(listetrajet3, arrivee);			
					
				monFluxD << depart << endl;
				monFluxD <<arrivee << endl;
				monFluxD <<"---------------------------------------------------------------------"<<endl;
			}while(getline(listetrajet3, ligne3));

			trajets();//retour menu trajet
		}
		else
		{
			cout<<" "<<endl;
			cout<<"     ERREUR : Impossible d'ouvrir le fichier." << endl;
			cout<<"     ";
			Sleep(3000);
			trajets();
		}	
	}
	return (0);
}