#include<iostream>
#include"Reservation.1.h"
#include"Menu Principal.h"
#include<Windows.h>
#include<cmath>
#include"Ajouter Reservation.h"
#include"Afficher Reservation.h"
#include"Supprimer Reservation.h"
#include"Rechercher Reservation.h"
#include"Modifier Reservation.h"

using namespace std;

int reservation()
{
	system ("cls");

	int a;
	double b;

	cout<<" "<<endl;
	cout<<"	******************   Reservation   ******************"<<endl;
	cout<<"	*                                                   *"<<endl;
	cout<<"	*            1 : Afficher les reservations          *"<<endl;
	cout<<"	*            2 : Modifier une reservation           *"<<endl;
	cout<<"	*            3 : Ajouter une reservation            *"<<endl;
	cout<<"	*            4 : Supprimer une reservation          *"<<endl;
	cout<<"	*            5 : Rechercher une reservation         *"<<endl;
	cout<<"	*                                                   *"<<endl;
	cout<<"	************ 0 : Retour au Menu Principal ***********"<<endl;
	cout<<" "<<endl;
	
	a=10;

	b=10;

	while ( a<0 || a>6 )
	{
		cout<<"     Votre choix : ";
		cin>>b;

		a=floor (b);

		system ("cls");

		switch (a)
		{
		case 0 :
			main();
			break;

		case 1 :
			afficherreservation();//Fonction Afficher;
			break;
	
		case 2 :
			modifierreservation();//Fonction Modifier
			break;
	
		case 3 :
			ajouterreservation();//Fonction Ajouter
			break;
	
		case 4 :
			supprimerreservation();//Fonction Supprimer
			break;
	
		case 5 :
			rechercherreservation();//Fonction Rechercher
			break;

		default : //Recommence le programme au debut
			cout<<" "<<endl;
			cout<<"		Erreur, recommencer s'il vous plait"<<endl;
			cout<<"		";
			Sleep (3000);
			system ("cls");
			reservation();
			break;
		}
	}
	return 0;
}