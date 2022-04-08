#include<iostream>
#include"Voyageur.1.h"
#include"Menu Principal.h"
#include<Windows.h>
#include<cmath>
#include"Ajouter Voyageur.h"
#include"Afficher Voyageur.h"
#include"Rechercher Voyageur.h"
#include"Modifier Voyageur.h"
#include"Supprimer Voyageur.h"

using namespace std;

int voyageur()
{
	system ("cls");

	int a;
	double b;

	cout<<" "<<endl;
	cout<<"	*****************     Voyageurs     *****************"<<endl;
	cout<<"	*                                                   *"<<endl;
	cout<<"	*             1 : Afficher les voyageurs            *"<<endl;
	cout<<"	*             2 : Modifier un voyageur              *"<<endl;
	cout<<"	*             3 : Ajouter un voyageur               *"<<endl;
	cout<<"	*             4 : Supprimer un voyageur             *"<<endl;
	cout<<"	*             5 : Rechercher un voyageur            *"<<endl;
	cout<<"	*                                                   *"<<endl;
	cout<<"	************ 0 : Retour au Menu Principal ***********"<<endl;
	cout<<" "<<endl;

	a=10;
	b=10;

	while ( a<0 || a>5 )
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
		affichervoyageur();//Fonction Afficher;
			break;

		case 2 :
		modifiervoyageur();//Fonction Modifier
			break;

		case 3 :
		ajoutervoyageur();//Fonction Ajouter
			break;

		case 4 :
		supprimervoyageur();//Fonction Supprimer
			break;

		case 5 :
		recherchervoyageur();//Fonction Rechercher
			break;

		default :
			cout<<" "<<endl;
			cout<<"		Erreur, recommencer s'il vous plait"<<endl;
			cout<<"		";
			Sleep (3000);
			system ("cls");
			voyageur();
			break;
		}
	}
	return 0;
}