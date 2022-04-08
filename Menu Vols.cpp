#include<iostream>
#include"Vols.1.h"
#include"Menu Principal.h"
#include<Windows.h>
#include<cmath>
#include<fstream>
#include<string>
#include"Afficher Vols.h"
#include"Ajouter Vols.h"
#include"Supprimer Vols.h"
#include"Rechercher Vols.h"
#include"Modifier Vols.h"


using namespace std;

int vols()
{
	system ("cls");

	int a;
	double b;

	cout<<" "<<endl;
	cout<<"	******************       Vol       ******************"<<endl;
	cout<<"	*                                                   *"<<endl;
	cout<<"	*               1 : Afficher les vols               *"<<endl;
	cout<<"	*               2 : Modifier un vol                 *"<<endl;
	cout<<"	*               3 : Ajouter un vol                  *"<<endl;
	cout<<"	*               4 : Supprimer un vol                *"<<endl;
	cout<<"	*               5 : Rechercher un vol               *"<<endl;
	cout<<"	*                                                   *"<<endl;
	cout<<"	************ 0 : Retour au Menu Principal ***********"<<endl;
	cout<<" "<<endl;

	a=10;
	b=10;

	while ( a<0 || a>6 )
	{
		cout<<"	     Votre choix : ";
		cin>>b;
		a=floor (b);
		system ("cls");

		switch (a)
		{
		case 0 :
			main();
			break;

		case 1 :
			affichervols();//Fonction Afficher
			break;

		case 2 :
			modifiervols();//Fonction Modifier
			break;
			
		case 3 :
			ajoutervols();//Fonction Ajouter
			break;
			
		case 4 :
			supprimervols();//Fonction Supprimer
			break;
			
		case 5 :
			recherchervols();//Fonction Rechercher
			break;

		default :
			cout<<" "<<endl;
			cout<<"		Erreur, recommencer s'il vous plait"<<endl;
			cout<<"		";
			Sleep (3000);
			system ("cls");
			vols();
			break;
		}
	}
	return 0;
}