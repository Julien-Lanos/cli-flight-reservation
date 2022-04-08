#include<iostream>
#include"Reservation.1.h"
#include"Trajets.1.h"
#include"Vols.1.h"
#include"Voyageur.1.h"
#include"Menu Principal.h"
#include<windows.h>

using namespace std;

int main()
{
	system ("cls");

	cout<<"	            Bienvenue chez DFMPL Airlines"<<endl;
	cout<<" "<<endl;

	int a;
	double b;

	cout<<"	                *********************"<<endl;
	cout<<"	*****************   Menu Principal  *****************"<<endl;
	cout<<"	*               *********************               *"<<endl;
	cout<<"	*                                                   *"<<endl;
	cout<<"	*                 1 : Reservations                  *"<<endl;
	cout<<"	*                 2 : Voyageurs                     *"<<endl;
	cout<<"	*                 3 : Vols                          *"<<endl;
	cout<<"	*                 4 : Trajets                       *"<<endl;
	cout<<"	*                                                   *"<<endl;
	cout<<"	*                                                   *"<<endl;
	cout<<"	*                 *****************                 *"<<endl;
	cout<<"	*******************  0 : Quitter  *******************"<<endl;
	cout<<"	                  *****************"<<endl;
	cout<<" "<<endl;

	a=6;
	b=6;

	while ( a<0 || a>4 )
	{
		cout<<"	     Votre choix : ";
		cin>>b;
		a=floor (b);
		system ("cls");
		switch (a)
		{
		case 0 :
			cout<<" "<<endl;
			cout<<" "<<endl;
			cout<<"	         Merci d'utiliser notre compagnie."<<endl;
			cout<<"	              Au revoir et a bientot."<<endl;
			cout<<"	                        ";
			Sleep (5000);
			exit(1);
			break;

		case 1 :
			reservation();
			break;

		case 2 :
			voyageur();
			break;

		case 3 :
			vols();
			break;

		case 4 :
			trajets();
			break;

		default :
			cout<<" "<<endl;
			cout<<"		Erreur, recommencer s'il vous plait"<<endl;
			cout<<"		";
			Sleep (3000);
			system ("cls");
			main();
			break;
		}
	}
	return 0;
}