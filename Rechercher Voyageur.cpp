#include<iostream>
#include<windows.h>
#include<string>
#include<fstream>
#include"Rechercher Voyageur.h"
#include"Voyageur.1.h"

using namespace std;

int recherchervoyageur()
{
	system("cls");
	ifstream listevoyageur("C:/Users/Valentin/Desktop/Projet info/listevoyageur.txt");
	
	int choix;

	cout<<" "<<endl;
	cout<<"	****** Voulez vous rechercher un voyageur par : *****"<<endl;
	cout<<"	*                                                   *"<<endl;
	cout<<"	*                   1 : Son prenom                  *"<<endl;
	cout<<"	*                   2 : Son nom                     *"<<endl;
	cout<<"	*                   3 : Son numero de passeport     *"<<endl;
	cout<<"	*                                                   *"<<endl;
	cout<<"	*********** 0 : Revenir au Menu Voyageurs ***********"<<endl;
	cout<<" "<<endl;
	cout<<"		Votre choix : ";

	cin>>choix;

	if(choix==1)
	{
		if(listevoyageur)
		{	
			system("cls");
			string ligne;
			string recherche;
			cout<<" "<<endl;
			cout<<"	Veuillez entrer le prenom du voyageur : ";
			cin>>recherche;

			do
			{
				string prenom;
				string sautligne1;
				string sautligne2;
				string sautligne3;
				string sautligne4;
				string sautligne5;
				getline(listevoyageur, prenom);
				getline(listevoyageur,sautligne2);
				getline(listevoyageur,sautligne3);
				getline(listevoyageur,sautligne4);
				getline(listevoyageur,sautligne5);

				if(prenom==recherche)
				{
					cout<<" "<<endl;
					cout<<"	Voici les information concernant votre voyageur : "<<endl;
					cout<<" "<<endl;
					cout<<"		Prenom : "<<prenom<<endl;
					cout<<"		Nom : "<<sautligne2<<endl;
					cout<<"		Age "<<sautligne3<<endl;
					cout<<"		Numero de passeport : "<<sautligne4<<endl;
					cout<<" "<<endl;
					cout<<"		";
					system("pause");

				}
			}while(getline(listevoyageur, ligne));
			
			cout<<" "<<endl;
			cout<<"	Remarque : si aucun voyageur ne vient de s'afficher ci dessus : "<<endl;
			cout<<"		Aucun voyageur ne correspond a votre recherche."<<endl;
			cout<<" "<<endl;
			cout<<"		";
			system("pause");
			voyageur();
		
		}
		else
		{
			cout<<" "<<endl;
			cout<<"     ERREUR : Impossible d'ouvrir le fichier de lecture." << endl;
			cout<<"     ";
			Sleep(3000);
			voyageur();
		}
	}
	else if(choix==2)
	{
		if(listevoyageur)
		{
			system("cls");
			string ligne;
			string recherche;
			cout<<" "<<endl;
			cout<<"	Veuillez entrer le nom du voyageur : ";
			cin>>recherche;

			do
			{
				string nom;
				string sautligne1;
				string sautligne2;
				string sautligne3;
				string sautligne4;
				string sautligne5;				
				getline(listevoyageur,sautligne1);
				getline(listevoyageur, nom);
				getline(listevoyageur,sautligne3);
				getline(listevoyageur,sautligne4);
				getline(listevoyageur,sautligne5);
			
				if(nom==recherche)
				{
					cout<<" "<<endl;
					cout<<"	Voici les information concernant votre voyageur : "<<endl;
					cout<<" "<<endl;
					cout<<"		Prenom : "<<sautligne1<<endl;
					cout<<		"Nom : "<<nom<<endl;
					cout<<"		Age : "<<sautligne3<<endl;
					cout<<"		Numero de passeport : "<<sautligne4<<endl;
					cout<<" "<<endl;
					cout<<"		";
					system("pause");
				}
			}while(getline(listevoyageur, ligne));
			
			cout<<" "<<endl;
			cout<<"	Remarque : si aucun voyageur ne vient de s'afficher ci dessus : "<<endl;
			cout<<"		Aucun voyageur ne correspond a votre recherche."<<endl;
			cout<<" "<<endl;
			cout<<"		";
			system("pause");
			voyageur();
		}
		else
		{
			cout<<" "<<endl;
			cout<<"     ERREUR : Impossible d'ouvrir le fichier de lecture." << endl;
			cout<<"     ";
			Sleep(3000);
			voyageur();
		}
	}
	else if(choix==3)
	{
		if(listevoyageur)
		{
			system("cls");
			string ligne;
			string recherche;
			cout<<" "<<endl;
			cout<<"	Veuillez entrer le numero de passeport du voyageur : ";
			cin>>recherche;

			do
			{
				string numeroDePasseport;
				string sautligne1;
				string sautligne2;
				string sautligne3;
				string sautligne4;
				string sautligne5;
				getline(listevoyageur,sautligne1);
				getline(listevoyageur,sautligne2);
				getline(listevoyageur,sautligne3);
				getline(listevoyageur, numeroDePasseport);
				getline(listevoyageur,sautligne5);

				if(numeroDePasseport==recherche)
				{
					cout<<" "<<endl;
					cout<<"	Voici les information concernant votre voyageur : "<<endl;
					cout<<" "<<endl;
					cout<<"		Prenom : "<<sautligne1<<endl;
					cout<<"		Nom : "<<sautligne2<<endl;
					cout<<"		Age : "<<sautligne3<<endl;
					cout<<"		Numero de passeport : "<<numeroDePasseport<<endl;
					cout<<" "<<endl;
					cout<<"		";
					system("pause");
				}
			}while(getline(listevoyageur, ligne));
			
			cout<<" "<<endl;
			cout<<"	Remarque : si aucun voyageur ne vient de s'afficher ci dessus : "<<endl;
			cout<<"		Aucun voyageur ne correspond a votre recherche."<<endl;
			cout<<" "<<endl;
			cout<<"		";
			system("pause");
			voyageur();
		}
		else
		{
			cout<<" "<<endl;
			cout<<"     ERREUR : Impossible d'ouvrir le fichier de lecture." << endl;
			cout<<"     ";
			Sleep(3000);
			voyageur();
		}
	}
	
	else if (choix==0)
	{
		voyageur();//Retour menu voyageur
	}
	else
	{
		cout<<"		Votre choix n'est pas valide."<<endl;
		Sleep(3000);
		recherchervoyageur();
	}
	return(0);
}