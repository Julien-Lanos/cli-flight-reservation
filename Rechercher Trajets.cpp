#include<iostream>
#include<windows.h>
#include<string>
#include<fstream>
#include"Trajets.1.h"
#include"Rechercher Reservation.h"

using namespace std;

int recherchertrajets() //rechercheTrajet()
{
	system("cls");
	ifstream listetrajet("Dossier texte/listetrajet.txt");
	
	int choix;

	cout<<"	******* Voulez vous rechercher un trajet par : ******"<<endl;
	cout<<"	*                                                   *"<<endl;
	cout<<"	*              1 : Sa ville de depart               *"<<endl;
	cout<<"	*              2 : Sa ville d'arrivee               *"<<endl;
	cout<<"	*                                                   *"<<endl;
	cout<<"	************* 0 : Retour au Menu Trajet *************"<<endl;
	cout<<""<<endl;
	cout<<"		Votre choix : "; 
	cin>>choix;	

 if(choix==1)
	{
		if(listetrajet)
		{
			system("cls");
			string ligne;
			string recherche;
			cout<<" "<<endl;
			cout<<"	Veuillez entrer la ville de depart a rechercher : ";
			cin>>recherche;

			do
			{
			string ligne,villeDepart,villeArrivee,sautligne2,sautligne3;

			getline(listetrajet, villeDepart);
			getline(listetrajet,sautligne2);

				if(villeDepart==recherche)
				{
					cout<<" "<<endl;
					cout<<"	Voici les information concernant votre trajet : "<<endl;
					cout<<" "<<endl;
					cout<<"		Ville de depart : "<<villeDepart<<endl;
					cout<<"		Ville d'arrivee : "<<sautligne2<<endl;
					cout<<" "<<endl;
					cout<<"		";
					system("pause");
				}
			}while(getline(listetrajet, ligne));
			
			cout<<" "<<endl;
			cout<<"	Remarque : si aucun trajets ne vient de s'afficher ci dessus : "<<endl;
			cout<<"		Aucun trajets ne correspond a votre recherche."<<endl;
			cout<<" "<<endl;
			cout<<"		";
			system("pause");
			trajets();//main();
		}
		else
		{
			cout<<" "<<endl;
			cout<<"     ERREUR : Impossible d'ouvrir le fichier de lecture." << endl;
			cout<<"     ";
			Sleep(3000);
			trajets();//main();
		}
	}
	else if(choix==2)
	{
		if(listetrajet)
		{
			system("cls");
			string ligne;
			string recherche;
			cout<<" "<<endl;
			cout<<"	Veuillez entrer la ville d'arrivee a rechercher : ";
			cin>>recherche;
			do
			{
			string villeArrivee,sautligne1,sautligne3;
		
			getline(listetrajet,sautligne1);
			getline(listetrajet, villeArrivee);

				if(villeArrivee==recherche)
				{
					cout<<" "<<endl;
					cout<<"	Voici les information concernant votre vol : "<<endl;
					cout<<" "<<endl;
					cout<<"		Ville de depart : "<<sautligne1<<endl;
					cout<<"		Ville d'arrivee : "<<villeArrivee<<endl;
					cout<<" "<<endl;
					cout<<"		";
					system("pause");
				}
			}while(getline(listetrajet, ligne));
			
			cout<<" "<<endl;
			cout<<"	Remarque : si aucun trajets ne vient de s'afficher ci dessus : "<<endl;
			cout<<"		Aucun trajets ne correspond a votre recherche."<<endl;
			cout<<" "<<endl;
			cout<<"		";
			system("pause");
			trajets();//main();
		}
		else
		{
			cout<<" "<<endl;
			cout<<"     ERREUR : Impossible d'ouvrir le fichier de lecture." << endl;
			cout<<"     ";
			Sleep(3000);
			trajets();//main();
		}
	}
	else if (choix==0)
	{
		trajets();//Retour menu vol
	}
	else
	{
		cout<<"		Votre choix n'est pas valide."<<endl;
		Sleep(3000);
		recherchertrajets();
	}
	return(0);
}