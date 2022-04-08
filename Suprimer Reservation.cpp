#include<iostream>
#include<windows.h>
#include<string>
#include<fstream>
#include"Reservation.1.h"
#include"Supprimer Reservation.h"

using namespace std;

int supprimerreservation()
{	
	string numerorecherche;
	string numeropasseportrecherche;
	string ligne;
	string ligne2;
	string ligne3;
	string ligne4;
	
	cout<<" "<<endl;
	cout<<"	Veuillez entrer le numero du vol : ";
	cin>>numerorecherche;

	cout<<" "<<endl;
	cout<<"	Veuillez entrer le numero du passeport : ";
	cin>>numeropasseportrecherche;

	ifstream listevol("Dossier texte/listereservation.txt");
	ofstream MonFlux("Dossier texte/listevolauxiliaire.txt");

	do
	{
		string prenom;
		string nom;
		string age;
		string numeropasseport;
		string numerovol;
		string sautligne1;
		string sautligne2;
		string sautligne3;
		string sautligne4;
		string sautligne5;
		string sautligne6;
		string sautligne7;
		string sautligne8;
		string confirmation;
			
		getline(listevol,prenom);
		getline(listevol,nom);
		getline(listevol,age);
		getline(listevol,numeropasseport);
		getline(listevol,numerovol);
		getline(listevol,sautligne1);
		getline(listevol,sautligne2);
		getline(listevol,sautligne3);
		getline(listevol,sautligne4);
		getline(listevol,sautligne5);
		getline(listevol,sautligne6);
		getline(listevol,sautligne7);
		getline(listevol,sautligne8);
		getline(listevol, confirmation);
			
		if(numerorecherche!=numerovol && numeropasseport!=numeropasseportrecherche)
		{
			ofstream MonFlux("Dossier texte/listevolauxiliaire.txt",ios::app);
					
			if(MonFlux)
			{
				MonFlux<<" "<<endl;
				MonFlux<< prenom <<endl;
				MonFlux<< nom <<endl;
				MonFlux<< age <<endl;
				MonFlux<< numeropasseport<<endl;
				MonFlux<< numerovol <<endl;
				MonFlux<< sautligne1 <<endl;
				MonFlux<< sautligne2 <<endl;
				MonFlux<< sautligne3 <<endl;
				MonFlux<< sautligne4 <<endl;
				MonFlux<< sautligne5 <<endl;
				MonFlux<< sautligne6 <<endl;
				MonFlux<< sautligne7 <<endl;
				MonFlux<< sautligne8 <<endl;
				MonFlux<< confirmation <<endl;
			}
			else
			{
				cout<<" "<<endl;
				cout<<"     ERREUR: Impossible d'ouvrir le fichier de lecture." << endl;
				cout<<"     "<<endl;
				Sleep(3000);
				reservation();
			}
		}
	}while(getline(listevol, ligne));

	ifstream listevolauxiliaire("Dossier texte/listevolauxiliaire.txt");
	ofstream MonFlux2("Dossier texte/listereservation.txt");

	while(getline(listevolauxiliaire, ligne2))
	{
		ofstream MonFlux2("Dossier texte/listereservation.txt",ios::app);

		if(MonFlux2)
		{

			string prenom1;
			string nom1;
			string age1;
			string numeropasseport1;
			string numerovol1;
			string sautligne11;
			string sautligne21;
			string sautligne31;
			string sautligne41;
			string sautligne51;
			string sautligne61;
			string sautligne71;
			string sautligne81;
			string confirmation1;

			getline(listevolauxiliaire,prenom1);
			getline(listevolauxiliaire,nom1);
			getline(listevolauxiliaire,age1);
			getline(listevolauxiliaire,numeropasseport1);
			getline(listevolauxiliaire,numerovol1);
			getline(listevolauxiliaire,sautligne11);
			getline(listevolauxiliaire,sautligne21);
			getline(listevolauxiliaire,sautligne31);
			getline(listevolauxiliaire,sautligne41);
			getline(listevolauxiliaire,sautligne51);
			getline(listevolauxiliaire,sautligne61);
			getline(listevolauxiliaire,sautligne71);
			getline(listevolauxiliaire,sautligne81);
			getline(listevolauxiliaire, confirmation1);
				
			MonFlux2<< prenom1 <<endl;
			MonFlux2<< nom1 <<endl;
			MonFlux2<< age1 <<endl;
			MonFlux2<< numeropasseport1 <<endl;
			MonFlux2<< numerovol1 <<endl;
			MonFlux2<< sautligne11 <<endl;
			MonFlux2<< sautligne21 <<endl;
			MonFlux2<< sautligne31 <<endl;
			MonFlux2<< sautligne41 <<endl;
			MonFlux2<< sautligne51 <<endl;
			MonFlux2<< sautligne61 <<endl;
			MonFlux2<< sautligne71 <<endl;
			MonFlux2<< sautligne81 <<endl;
			MonFlux2<< confirmation1 <<endl;
			MonFlux2<<"---------------------------------------------------------------------"<<endl;

		}
		else
		{
			cout<<" "<<endl;
			cout<<"     ERREUR: Impossible d'ouvrir le fichier de lecture." << endl;
			cout<<"     "<<endl;
			Sleep(3000);
			reservation();
		}
	}
	int a(0);
	do
	{
		string prenom;
		string nom;
		string age;
		string numeropasseport;
		string numerovol;
		string sautligne1;
		string sautligne2;
		string sautligne3;
		string sautligne4;
		string sautligne5;
		string sautligne6;
		string sautligne7;
		string sautligne8;
		string confirmation;
			
		getline(listevol,prenom);
		getline(listevol,nom);
		getline(listevol,age);
		getline(listevol,numeropasseport);
		getline(listevol,numerovol);
		getline(listevol,sautligne1);
		getline(listevol,sautligne2);
		getline(listevol,sautligne3);
		getline(listevol,sautligne4);
		getline(listevol,sautligne5);
		getline(listevol,sautligne6);
		getline(listevol,sautligne7);
		getline(listevol,sautligne8);
		getline(listevol, confirmation);

		if(numeropasseport==numeropasseportrecherche && numerorecherche==numerovol)
		{
			a=1;
		}
	}while(getline(listevol, ligne4));

	if(a=0)
	{
		cout<<"	Aucune reservation ne correspond a la reservation"<<endl;
		cout<<"	que vous voulez supprimer."<<endl;
		Sleep(3000);
		reservation();
	}
	system("cls");
	cout<<" "<<endl;
	cout<<"		Votre reservation a bien ete supprimer."<<endl;
	cout<<"			";
	Sleep(3000);
	reservation();

	return(0);
}		