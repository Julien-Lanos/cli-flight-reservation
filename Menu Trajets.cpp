#include<iostream>
#include"Trajets.1.h"
#include"Menu Principal.h"
#include<windows.h>
#include<cmath>
#include"Afficher Trajets.h"
#include"Rechercher Trajets.h"
#include"Supprimer Trajets.h"
#include"Ajouter Trajet.h"

using namespace std;

int trajets()
{
	system ("cls");

	int a;
	double b;

	cout<<" "<<endl;
	cout<<"	*****************      Trajets      *****************"<<endl;
	cout<<"	*                                                   *"<<endl;
	cout<<"	*              1 : Afficher les trajets             *"<<endl;
	cout<<"	*              2 : Ajouter une trajet               *"<<endl;
	cout<<"	*              3 : Supprimer une trajet             *"<<endl;
	cout<<"	*              4 : Rechercher une trajet            *"<<endl;
	cout<<"	*                                                   *"<<endl;
	cout<<"	************ 0 : Retour au Menu Principal ***********"<<endl;
	cout<<" "<<endl;

	a=10;
	b=10;

	while ( a<0 || a>6 )
	{
		cout<<"		Votre choix : ";
		cin>>b;

		a=floor (b);

		system ("cls");

		switch (a)
		{
		case 0 :
			main();
			break;
	
		case 1 :
			affichertrajets();//Fonction Afficher;
			break;
	
		case 2 :
			ajoutertrajets();//Fonction Ajouter
			break;

		case 3 :
			supprimertrajets();//Fonction Supprimer
			break;

		case 4 :
			recherchertrajets();//Fonction Rechercher
			break;
	
		default ://Recommence le programme au debut
			cout<<" "<<endl;
			cout<<"		Erreur, recommencer s'il vous plait"<<endl;
			cout<<"		";
			Sleep (3000);
			system ("cls");
			trajets();

			break;
		}
	}
	return 0;
}