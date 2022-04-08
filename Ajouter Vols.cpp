#include<iostream>
#include<windows.h>
#include<string>
#include<fstream>
#include"Ajouter Vols.h"
#include"Vols.1.h"

using namespace std;

int ajoutervols()
{
	string numerovol, videpart, destination ;
	int jour ;
	int mois ;
	int annee ;
	int heure ; 
	int minute ;
	double prix ;
	int choix ;

	cout<<" "<<endl;
	cout<<"		Veuillez entrer le numero de vol : ";
	cin>>numerovol;

	cout<<" "<<endl;
	cout<<"		Veuillez entrer la ville de depart : ";
	cin>>videpart;
		
	cout<<"		Veuillez entrer la ville d'arrivee : ";
	cin >> destination;
	
	do
	{
		cout<<" "<<endl;
		cout<<"		Veuillez entrer le jour du depart : ";
		cin>>jour;
	}while(jour<1 || jour>31) ;

	do
	{
		cout<<"		Veuillez entrer le mois du depart : ";
		cin>>mois;
	}while( mois<1 || mois>12) ;

	do
	{
		cout<<"		Veuillez entrer l'annee du depart : ";
		cin>>annee;
	}while(annee<2013 || annee>2100) ;

	do
	{
		cout<<" "<<endl;
		cout<<"		Veuillez entrer l'heure du depart : ";
		cin>>heure;
	}while(heure<00 || heure>24) ;
	
	do
	{
		cout<<"		Veuillez entrer les minutes : ";
		cin>>minute ;
	}while(minute<00 || minute>60) ;
	
	do
	{
		cout<<" "<<endl;
		cout<<"		Veuillez entrer le prix du vol : ";
		cin>>prix;
	}while(prix<00 || prix>30000) ;
	
	system ("cls");

	//Voyons si nous voulons enregistrer les valeurs des variables demadées ci-dessus dans un fichier.

	cout<<" "<<endl;
	cout<<"	******* Voulez vous enregistrer vos donnees ? *******"<<endl;
	cout<<"	*                                                   *"<<endl;
	cout<<"	*                   1 : Oui                         *"<<endl;
	cout<<"	*                   2 : Non                         *"<<endl;
	cout<<"	*                                                   *"<<endl;
	cout<<"	*****************************************************"<<endl;
	cout<<" "<<endl;
	cout<<"	     Votre choix : ";
	cin>>choix ;

	if(choix==1) //Oui enregistrons !
	{
		ofstream monFlux("Dossier texte/listevol.txt",ios::app);
			
		if(monFlux)
		{
			monFlux << numerovol << endl;

			monFlux << videpart << endl;
			monFlux << destination << endl;
			monFlux << jour << endl;
			monFlux << mois << endl;
			monFlux << annee << endl;
			monFlux << heure << endl;
			monFlux << minute << endl;
			monFlux << prix << endl;
			monFlux <<"---------------------------------------------------------------------"<<endl;

			system("cls");
			cout<<" "<<endl;
			cout<<"	* * * * * *  Votre vol a ete enregistre.  * * * * * *"<<endl;
			cout<<"				"<<endl;
			Sleep(3000);

			vols();//revenir menu vol
		}
		else
		{
			cout<<" "<<endl;
			cout<<"     ERREUR : Impossible d'ouvrir le fichier." << endl;
			cout<<"     ";
			Sleep(3000);
			vols();
		}
	}
	else if(choix=2) //Non, n'enregistrons pas !
	{
		vols();//revenir menu vol
	}
	return (0);
}