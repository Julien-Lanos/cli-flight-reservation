#include<iostream>
#include<windows.h>
#include<string>
#include<fstream>
#include"Ajouter Voyageur.h"
#include"Voyageur.1.h"

using namespace std;

int ajoutervoyageur()
{
	system ("cls");
	string prenom,nom,age,numeroDePasseport,ligne;
	int choix ;

	cout<<" "<<endl;
	cout<<"	Veuillez entre le prenom du voyageur : "; cin>>prenom;
	cout<<"	Veuillez entre le nom du voyageur : "; cin>>nom;
	cout<<"	Veuillez entre le age du voyageur : "; cin>>age;
	cout<<"	Veuillez entre le numero de passeport du voyageur : "; cin>>numeroDePasseport;
	cout <<""<<endl;
	
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
	cout<<" "<<endl;
	cout<<"			Votre choix : ";
	cin>>choix ;

	if(choix==1) //Oui enregistrons !
	{
		ofstream monFlux("Dossier texte/listevoyageur.txt",ios::app);
			
		if(monFlux)
		{		
			monFlux << prenom << endl;
			monFlux << nom << endl;
			monFlux << age << endl;
			monFlux << numeroDePasseport << endl;					
			monFlux <<"---------------------------------------------------------------------"<<endl;

			system("cls");
			cout<<" "<<endl;
			cout<<"	* * * * * Votre voyageur a ete enregistre.  * * * * *"<<endl;
			cout<<"			  "<<endl;
			Sleep(3000);

			voyageur();//revenir menu voyageur
		}
		else
		{
			cout<<" "<<endl;
			cout<<"     ERREUR : Impossible d'ouvrir le fichier." << endl;
			cout<<"     ";
			Sleep(3000);
			voyageur();//revenir menu voyageur
		}
	}
	else if(choix=2) //Non, n'enregistrons pas !
	{
		voyageur();//revenir menu voyageur
	}
	return (0);
}