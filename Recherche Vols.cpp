#include<iostream>
#include<windows.h>
#include<string>
#include<fstream>
#include"Rechercher Vols.h"
#include"Vols.1.h"

using namespace std;

int recherchervols()
{
	system("cls");
	ifstream listevol("Dossier texte/listevol.txt");
	
	int choix;

	cout<<" "<<endl;
	cout<<"	****** Voulez vous rechercher votre vol par : *******"<<endl;
	cout<<"	*                                                   *"<<endl;
	cout<<"	*             1 : Son numero de vol                 *"<<endl;
	cout<<"	*             2 : Sa ville de depart                *"<<endl;
	cout<<"	*             3 : Sa ville d'arrivee                *"<<endl;
	cout<<"	*             4 : Sa date                           *"<<endl;
	cout<<"	*             5 : Son heure de depart               *"<<endl;
	cout<<"	*             6 : Son prix                          *"<<endl;
	cout<<"	*                                                   *"<<endl;
	cout<<"	*************** 0 : Retour au Menu Vols *************"<<endl;
	cout<<" "<<endl;
	cout<<"		Votre choix : ";

	cin>>choix;

	if(choix==1)
	{
		if(listevol)
		{	
			system("cls");
			string ligne, recherche;

			cout<<" "<<endl;
			cout<<"	Veuillez entrer son numero de vol : ";
			cin>>recherche;

			do
			{
			string numerovol, sautligne1, sautligne2, sautligne3;
			string sautligne4, sautligne5, sautligne6, sautligne7, sautligne8;

			getline(listevol,numerovol);
			getline(listevol,sautligne1);
			getline(listevol,sautligne2);
			getline(listevol,sautligne3);
			getline(listevol,sautligne4);
			getline(listevol,sautligne5);
			getline(listevol,sautligne6);
			getline(listevol,sautligne7);
			getline(listevol,sautligne8);

				if(numerovol==recherche)
				{
					cout<<" "<<endl;
					cout<<"	Voici les information concernant votre vol : "<<endl;
					cout<<" "<<endl;
					cout<<"		Ville de depart : "<<sautligne1<<endl;
					cout<<"		Ville d'arrivee : "<<sautligne2<<endl;
					cout<<"		Le "<<sautligne3<<"/"<<sautligne4<<"/"<<sautligne5<<endl;
					cout<<"		Heure de depart : "<<sautligne6<<"h"<<sautligne7<<"min"<<endl;
					cout<<"		Au prix de "<<sautligne8<<" euros"<<endl;
					cout<<" "<<endl;
					cout<<"		";
					system("pause");
				}
			}while(getline(listevol, ligne));
			cout<<" "<<endl;
			cout<<"	Remarque : si aucun vol ne vient de s'afficher ci dessus : "<<endl;
			cout<<"		Aucun vol ne correspond a votre recherche."<<endl;
			cout<<" "<<endl;
			cout<<"		";
			system("pause");
			recherchervols();
		}
		else
		{
		cout<<" "<<endl;
		cout<<"     ERREUR : Impossible d'ouvrir le fichier de lecture." << endl;
		cout<<"     ";
		Sleep(3000);
		recherchervols();
		}
	}
	else if(choix==2)
	{
		if(listevol)
		{
			system("cls");
			string ligne;
			string recherche;
			cout<<"	Veuillez entrer sa ville de depart : ";
			cin>>recherche;

			do
			{
				string videpart, sautligne1, sautligne2, sautligne3, sautligne4;
				string sautligne5, sautligne6, sautligne7, sautligne8;
					
				getline(listevol,sautligne1);
				getline(listevol,videpart);
				getline(listevol,sautligne2);
				getline(listevol,sautligne3);
				getline(listevol,sautligne4);
				getline(listevol,sautligne5);
				getline(listevol,sautligne6);
				getline(listevol,sautligne7);
				getline(listevol,sautligne8);

				if(videpart==recherche)
				{
					cout<<" "<<endl;
					cout<<"	Voici les information concernant votre vol : "<<endl;
					cout<<" "<<endl;
					cout<<"		Numero de vol : "<<sautligne1<<endl;
					cout<<"		Ville de depart : "<<videpart<<endl;
					cout<<"		Ville d'arrivee : "<<sautligne2<<endl;
					cout<<"		Le "<<sautligne3<<"/"<<sautligne4<<"/"<<sautligne5<<endl;
					cout<<"		Heure de depart : "<<sautligne6<<"h"<<sautligne7<<endl;
					cout<<"		Au prix de : "<<sautligne8<<" euros"<<endl;
					cout<<" "<<endl;
					cout<<"		";
					system("pause");

				}
			}while(getline(listevol, ligne));
			cout<<" "<<endl;
			cout<<"	Remarque : si aucun vol ne vient de s'afficher ci dessus : "<<endl;
			cout<<"		Aucun vol ne correspond a votre recherche."<<endl;
			cout<<" "<<endl;
			cout<<"		";
			system("pause");
			recherchervols();
		}
		else
		{
		cout<<" "<<endl;
		cout<<"     ERREUR : Impossible d'ouvrir le fichier de lecture." << endl;
		cout<<"     ";
		Sleep(3000);
		recherchervols();
		}
	}
	else if(choix==3)
	{
		if(listevol)
		{
			system("cls");

			string ligne, recherche;

			cout<<"	Veuillez entrer sa ville d'arrivee : ";
			cin>>recherche;

			do
			{
			string viarrivee, sautligne1, sautligne2, sautligne3, sautligne4;
			string sautligne5, sautligne6, sautligne7, sautligne8;

			getline(listevol,sautligne1);
			getline(listevol,sautligne2);
			getline(listevol, viarrivee);
			getline(listevol,sautligne3);
			getline(listevol,sautligne4);
			getline(listevol,sautligne5);
			getline(listevol,sautligne6);
			getline(listevol,sautligne7);
			getline(listevol,sautligne8);

				if(viarrivee==recherche)
				{
				cout<<" "<<endl;
				cout<<"	Voici les information concernant votre vol : "<<endl;
				cout<<" "<<endl;
				cout<<"		Numero de vol : "<<sautligne1<<endl;
				cout<<"		Ville de depart : "<<sautligne2<<endl;
				cout<<"		Ville d'arrivee : "<<viarrivee<<endl;
				cout<<"		Ve "<<sautligne3<<"/"<<sautligne4<<"/"<<sautligne5<<endl;
				cout<<"		Heure de depart : "<<sautligne6<<"h"<<sautligne7<<endl;
				cout<<"		Au prix de : "<<sautligne8<<" euros"<<endl;
				cout<<" "<<endl;
				cout<<"		";

				system("pause");

				}
			}while(getline(listevol, ligne));
			cout<<" "<<endl;
			cout<<"	Remarque : si aucun vol ne vient de s'afficher ci dessus : "<<endl;
			cout<<"		Aucun vol ne correspond a votre recherche."<<endl;
			cout<<" "<<endl;
			cout<<"		";
			system("pause");
			recherchervols();
		}
		else
		{
		cout<<" "<<endl;
		cout<<"     ERREUR : Impossible d'ouvrir le fichier de lecture." << endl;
		cout<<"     ";
		Sleep(3000);
		recherchervols();
		}
	}
	else if (choix==4)
	{
		if(listevol)
		{
			system("cls");

			string ligne, jourrecherche, moisrecherche, anneerecherche;

			cout<<"	Veuillez entrer la date du vol (jour/mois/annee) : ";
			cin>>jourrecherche;
			cout<<"		";
			cin>>moisrecherche;
			cout<<"		";
			cin>>anneerecherche;

			do
			{
			string jour, mois, annee, sautligne1, sautligne2;
			string sautligne3, sautligne6, sautligne7, sautligne8;

			getline(listevol,sautligne1);
			getline(listevol,sautligne2);
			getline(listevol,sautligne3);
			getline(listevol,jour);
			getline(listevol,mois);
			getline(listevol,annee);
			getline(listevol,sautligne6);
			getline(listevol,sautligne7);
			getline(listevol,sautligne8);

				if(jour==jourrecherche && mois==moisrecherche && annee==anneerecherche)
				{
				cout<<" "<<endl;
				cout<<"	Voici les information concernant votre vol : "<<endl;
				cout<<" "<<endl;
				cout<<"		Numero de vol est : "<<sautligne1<<endl;
				cout<<"		Ville de depart : "<<sautligne2<<endl;
				cout<<"		Ville d'arrivee : "<<sautligne3<<endl;
				cout<<"		Le "<<jour<<"/"<<mois<<"/"<<annee<<endl;
				cout<<"		Heure de depart : "<<sautligne6<<"h"<<sautligne7<<endl;
				cout<<"		Au prix de : "<<sautligne8<<" euros"<<endl;
				cout<<" "<<endl;
				cout<<"		";

				system("pause");

				}
			}while(getline(listevol, ligne));
			cout<<" "<<endl;
			cout<<"	Remarque : si aucun vol ne vient de s'afficher ci dessus : "<<endl;
			cout<<"		Aucun vol ne correspond a votre recherche."<<endl;
			cout<<" "<<endl;
			cout<<"		";
			system("pause");
			recherchervols();
		}
		else
		{
		cout<<" "<<endl;
		cout<<"     ERREUR : Impossible d'ouvrir le fichier de lecture." << endl;
		cout<<"     ";
		Sleep(3000);
		recherchervols();
		}
	}
	else if (choix==5)
	{
		if(listevol)
		{
			system("cls");

			string ligne, heurerecherche, minuterecherche;
			cout<<" "<<endl;
			cout<<"	Veuillez entrer l'heure de depart : ";
			cin>>heurerecherche;
			cout<<" "<<endl;
			cout<<"	Veuillez entre les minutes : ";
			cin>>minuterecherche;

			do
			{
			string sautligne1, sautligne2, sautligne3, sautligne4;
			string sautligne5, sautligne6, heure, minute, sautligne8;

			getline(listevol,sautligne1);
			getline(listevol,sautligne2);
			getline(listevol,sautligne3);
			getline(listevol,sautligne4);
			getline(listevol,sautligne5);
			getline(listevol,sautligne6);
			getline(listevol,heure);
			getline(listevol,minute);
			getline(listevol,sautligne8);

				if(heure==heurerecherche && minute==minuterecherche)
				{
				cout<<" "<<endl;
				cout<<"	Voici les information concernant votre vol : "<<endl;
				cout<<" "<<endl;
				cout<<"		Le numero de vol est : "<<sautligne1<<endl;
				cout<<"		Ville de depart : "<<sautligne2<<endl;
				cout<<"		Ville d'arrivee : "<<sautligne3<<endl;
				cout<<"		Le "<<sautligne4<<"/"<<sautligne5<<"/"<<sautligne6<<endl;
				cout<<"		Heure de depart : "<<heure<<"h"<<minute<<endl;
				cout<<"		Au prix de : "<<sautligne8<<" euros"<<endl;
				cout<<" "<<endl;
				cout<<"		";

				system("pause");
				}
			}while(getline(listevol, ligne));
			cout<<" "<<endl;
			cout<<"	Remarque : si aucun vol ne vient de s'afficher ci dessus : "<<endl;
			cout<<"		Aucun vol ne correspond a votre recherche."<<endl;
			cout<<" "<<endl;
			cout<<"		";
			system("pause");
			recherchervols();
		}
		else
		{
		cout<<" "<<endl;
		cout<<"     ERREUR : Impossible d'ouvrir le fichier de lecture." << endl;
		cout<<"     ";
		Sleep(3000);
		recherchervols();
		}
	}
	else if (choix==6)
	{
		if(listevol)
		{
			system("cls");

			string ligne, prixrecherche;

			cout<<"	Veuillez entrer le prix du vol que vous recherchez : "<<endl;
			cin>>prixrecherche;

			do
			{
			string prix, sautligne1, sautligne2, sautligne3, sautligne4;
			string sautligne5, sautligne6, sautligne7, sautligne8;

			getline(listevol,sautligne1);
			getline(listevol,sautligne2);
			getline(listevol,sautligne3);
			getline(listevol,sautligne4);
			getline(listevol,sautligne5);
			getline(listevol,sautligne6);
			getline(listevol,sautligne7);
			getline(listevol,sautligne8);
			getline(listevol, prix);

				if(prix==prixrecherche)
				{
				cout<<" "<<endl;
				cout<<"	Voici les information concernant votre vol : "<<endl;
				cout<<" "<<endl;
				cout<<"		Numero de vol est : "<<sautligne1<<endl;
				cout<<"		Ville de depart : "<<sautligne2<<endl;
				cout<<"		Ville d'arrivee : "<<sautligne3<<endl;
				cout<<"		Le "<<sautligne4<<"/"<<sautligne5<<"/"<<sautligne6<<endl;
				cout<<"		Heure de depart : "<<sautligne7<<"h"<<sautligne8<<endl;
				cout<<"		Au prix de : "<<prix<<" euros"<<endl;
				cout<<" "<<endl;
				cout<<"		";

				system("pause");
				}
			}while(getline(listevol, ligne));
			cout<<" "<<endl;
			cout<<"	Remarque : si aucun vol ne vient de s'afficher ci dessus : "<<endl;
			cout<<"		Aucun vol ne correspond a votre recherche."<<endl;
			cout<<" "<<endl;
			cout<<"		";
			system("pause");
			recherchervols();
		}
		else
		{
		cout<<" "<<endl;
		cout<<"     ERREUR : Impossible d'ouvrir le fichier de lecture." << endl;
		cout<<"     ";
		Sleep(3000);
		recherchervols();
		}
	}
	else if (choix==0)
	{
		vols();
	}
	else
	{
		cout<<"		Votre choix n'est pas valide."<<endl;
		Sleep(3000);
		recherchervols();
	}
	return(0);
}