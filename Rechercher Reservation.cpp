#include<iostream>
#include<windows.h>
#include<string>
#include<fstream>
#include"Reservation.1.h"
#include"Rechercher Reservation.h"

using namespace std;

int rechercherreservation()
{
	system("cls");
	ifstream listereservation("Dossier texte/listereservation.txt");

	int a;

	cout<<"	**  Voulez vous rechercher votre reservation par : **"<<endl;
	cout<<"	*                                                   *"<<endl;
	cout<<"	*             1 : Nom-Prenom                        *"<<endl;
	cout<<"	*             2 : Numero de passeport               *"<<endl;
	cout<<"	*             3 : Numero de vol                     *"<<endl;
	cout<<"	*             4 : Ville de depart et d'arrivée      *"<<endl;
	cout<<"	*             5 : Date du depart                    *"<<endl;
	cout<<"	*                                                   *"<<endl;
	cout<<"	********** 0 : Retour au Menu Reservations **********"<<endl;
	cout<<" "<<endl;
	cout<<"		Votre choix : ";

	cin>>a;
	system("cls");

	if(a==1)//Nom-Prenom
	{
		if(listereservation)
		{
			string prenomrecherche;
			string nomrecherche;
			string ligne;
			int compteur(0);

			cout<<" "<<endl;
			cout<<"	Veuillez entrer le prenom du voyageur : ";
			cin>>prenomrecherche;
			cout<<"	Veuillez entrer le nom du voyageur : ";
			cin>>nomrecherche;

			do
			{
				string prenom, nom, age, numeropasseport, numerovol, videpart, viarrivee;
				string jour, mois, annee, heure, minute, prix, confirmation;

				getline(listereservation, prenom);
				getline(listereservation, nom);
				getline(listereservation, age);
				getline(listereservation, numeropasseport);
				getline(listereservation, numerovol);
				getline(listereservation, videpart);
				getline(listereservation, viarrivee);
				getline(listereservation, jour);
				getline(listereservation, mois);
				getline(listereservation, annee);
				getline(listereservation, heure);
				getline(listereservation, minute);
				getline(listereservation, prix);
				getline(listereservation, confirmation);

				if(prenomrecherche==prenom && nomrecherche==nom)
				{
					compteur=1;
					system("cls");
					cout<<" "<<endl;
					cout<<"	Voici les information concernant votre reservation : "<<endl;
					cout<<" "<<endl;
					cout<<"		Le prenom : "<<prenom<<endl;
					cout<<"		Le nom : "<<nom<<endl;
					cout<<"		L'age : "<<age<<" ans"<<endl;
					cout<<"		Le numero de passeport : "<<numeropasseport<<endl;
					cout<<"		Le numero de vol : "<<numerovol<<endl;
					cout<<"		La ville de depart : "<<videpart<<endl;
					cout<<"		La ville d arrivee : "<<viarrivee<<endl;
					cout<<"		Le"<<jour<<"/"<<mois<<"/"<<annee<<endl;
					cout<<"		A "<<heure<<"h"<<minute<<"min"<<endl;
					cout<<"		Au prix de "<<prix<<" euro"<<endl;
					cout<<"		Confirmation : "<<confirmation<<endl;
					cout<<" "<<endl;
					cout<<"		";
					system("pause");
					reservation();
				}
			}while(getline(listereservation, ligne));

			if(compteur==0)
			{
				cout<<" "<<endl;
				cout<<"	Remarque : si aucune reservation ne vient de s'afficher ci dessus : "<<endl;
				cout<<"		Aucune reservation ne correspond a votre recherche."<<endl;
				cout<<" "<<endl;
				cout<<"		";
				system("pause");
				reservation();//retour menu reservation
			}
		}
		else
		{
			cout<<" "<<endl;
			cout<<"     ERREUR : Impossible d'ouvrir le fichier de lecture." << endl;
			cout<<"     ";
			Sleep(3000);
			reservation();//retour menu reservation
		}
	}
	else if(a==2)//Numero de passeport
	{
		if(listereservation)
		{
			string numeropasseportrecherche;
			string ligne;
			int compteur(0);

			cout<<" "<<endl;
			cout<<"	Veuillez entrer le numero de passeport du voyageur : ";
			cin>>numeropasseportrecherche;

			ifstream listereservation("Dossier texte/listereservation.txt");

			do
			{
				string prenom, nom, age, numeropasseport, numerovol, videpart;
				string viarrivee, jour, mois, annee, heure, minute, prix, confirmation;

				getline(listereservation, prenom);
				getline(listereservation, nom);
				getline(listereservation, age);
				getline(listereservation, numeropasseport);
				getline(listereservation, numerovol);
				getline(listereservation, videpart);
				getline(listereservation, viarrivee);
				getline(listereservation, jour);
				getline(listereservation, mois);
				getline(listereservation, annee);
				getline(listereservation, heure);
				getline(listereservation, minute);
				getline(listereservation, prix);
				getline(listereservation, confirmation);

				if(numeropasseportrecherche==numeropasseport)
				{
					compteur=1;
					cout<<" "<<endl;
					cout<<"	Voici les information concernant votre reservation : "<<endl;
					cout<<" "<<endl;
					cout<<"		Le prenom : "<<prenom<<endl;
					cout<<"		Le nom : "<<nom<<endl;
					cout<<"		L'age : "<<age<<" ans"<<endl;
					cout<<"		Le numero de passeport : "<<numeropasseport<<endl;
					cout<<"		Le numero de vol : "<<numerovol<<endl;
					cout<<"		La ville de depart : "<<videpart<<endl;
					cout<<"		La ville d arrivee : "<<viarrivee<<endl;
					cout<<"		Le"<<jour<<"/"<<mois<<"/"<<annee<<endl;
					cout<<"		A "<<heure<<"h"<<minute<<"min"<<endl;
					cout<<"		Au prix de "<<prix<<" euros"<<endl;
					cout<<"		Confirmation : "<<confirmation<<endl;
					cout<<" "<<endl;
					cout<<"		";
					system("pause");
					reservation();
				}
			}while(getline(listereservation, ligne));
			if(compteur==0)
			{
				cout<<" "<<endl;
				cout<<"	Remarque : si aucune reservation ne vient de s'afficher ci dessus : "<<endl;
				cout<<"		Aucune reservation ne correspond a votre recherche."<<endl;
				cout<<" "<<endl;
				cout<<"		";
				system("pause");
				reservation();//retour menu reservation
			}
		}
		else
		{
			cout<<" "<<endl;
			cout<<"     ERREUR : Impossible d'ouvrir le fichier de lecture." << endl;
			cout<<"     ";
			Sleep(3000);
			reservation();//retour menu reservation
		}
	}
	else if(a==3)//Numero de vol
	{
		if(listereservation)
		{
			string numerovolrecherche;
			string ligne;
			int compteur(0);
	
			cout<<" "<<endl;
			cout<<"	Veuillez entrer le numero de vol : ";
			cin>>numerovolrecherche;
	
			ifstream listereservation("Dossier texte/listereservation.txt");
	
			do
			{
				string prenom, nom, age, numeropasseport, numerovol, videpart;
				string viarrivee, jour, mois, annee, heure, minute, prix, confirmation;
	
				getline(listereservation, prenom);
				getline(listereservation, nom);
				getline(listereservation, age);
				getline(listereservation, numeropasseport);
				getline(listereservation, numerovol);
				getline(listereservation, videpart);
				getline(listereservation, viarrivee);
				getline(listereservation, jour);
				getline(listereservation, mois);
				getline(listereservation, annee);
				getline(listereservation, heure);
				getline(listereservation, minute);
				getline(listereservation, prix);
				getline(listereservation, confirmation);
	
				if(numerovolrecherche==numeropasseport)
				{
					compteur=1;
					cout<<" "<<endl;
					cout<<"	Voici les information concernant votre reservation : "<<endl;
					cout<<" "<<endl;
					cout<<"		Le prenom : "<<prenom<<endl;
					cout<<"		Le nom : "<<nom<<endl;
					cout<<"		L'age : "<<age<<" ans"<<endl;
					cout<<"		Le numero de passeport : "<<numeropasseport<<endl;
					cout<<"		Le numero de vol : "<<numerovol<<endl;
					cout<<"		La ville de depart : "<<videpart<<endl;
					cout<<"		La ville d arrivee : "<<viarrivee<<endl;
					cout<<"		Le"<<jour<<"/"<<mois<<"/"<<annee<<endl;
					cout<<"		A "<<heure<<"h"<<minute<<"min"<<endl;
					cout<<"		Au prix de "<<prix<<" euros"<<endl;
					cout<<"		Confirmation : "<<confirmation<<endl;
					cout<<" "<<endl;
					cout<<"		";
					system("pause");
					reservation();
				}
	
			}while(getline(listereservation, ligne));
	
			if(compteur==0)
			{
				cout<<" "<<endl;
				cout<<"	Remarque : si aucune reservation ne vient de s'afficher ci dessus : "<<endl;
				cout<<"		Aucune reservation ne correspond a votre recherche."<<endl;
				cout<<" "<<endl;
				cout<<"		";
				system("pause");
				reservation();//retour menu reservation
			}
			else
			{
				cout<<" "<<endl;
				cout<<"     ERREUR : Impossible d'ouvrir le fichier de lecture." << endl;
				cout<<"     ";
				Sleep(3000);
				reservation();//retour menu reservation
			}
		}
	}
	else if(a==4)//Ville depart et destination
	{
		if(listereservation)
		{
			string videpartrecherche, viarriveerecherche, ligne;
			int compteur(0);
				
			cout<<" "<<endl;
			cout<<"	Veuillez entrer la ville de depart : ";
			cin>>videpartrecherche;
			cout<<"	Veuillez entrer la ville d'arrivee : ";
			cin>>viarriveerecherche;
	
			ifstream listereservation("V/listereservation.txt");
	
			do
			{
				string prenom, nom, age, numeropasseport, numerovol, videpart;
				string viarrivee, jour, mois, annee, heure, minute, prix, confirmation;
					
				getline(listereservation, prenom);
				getline(listereservation, nom);
				getline(listereservation, age);
				getline(listereservation, numeropasseport);
				getline(listereservation, numerovol);
				getline(listereservation, videpart);
				getline(listereservation, viarrivee);
				getline(listereservation, jour);
				getline(listereservation, mois);
				getline(listereservation, annee);
				getline(listereservation, heure);
				getline(listereservation, minute);
				getline(listereservation, prix);
				getline(listereservation, confirmation);
					
				if(videpartrecherche==videpart && viarriveerecherche==viarrivee)
				{
					compteur=1;
					cout<<" "<<endl;
					cout<<"	Voici les information concernant votre reservation : "<<endl;
					cout<<" "<<endl;
					cout<<"		Le prenom : "<<prenom<<endl;
					cout<<"		Le nom : "<<nom<<endl;
					cout<<"		L'age : "<<age<<" ans"<<endl;
					cout<<"		Le numero de passeport : "<<numeropasseport<<endl;
					cout<<"		Le numero de vol : "<<numerovol<<endl;
					cout<<"		La ville de depart : "<<videpart<<endl;
					cout<<"		La ville d arrivee : "<<viarrivee<<endl;
					cout<<"		Le"<<jour<<"/"<<mois<<"/"<<annee<<endl;
					cout<<"		A "<<heure<<"h"<<minute<<"min"<<endl;
					cout<<"		Au prix de "<<prix<<" euros"<<endl;
					cout<<"		Confirmation : "<<confirmation<<endl;
					cout<<" "<<endl;
					cout<<"		";
					system("pause");
					reservation();
				}
			}while(getline(listereservation, ligne));

			if(compteur==0)
			{
				cout<<" "<<endl;
				cout<<"	Remarque : si aucune reservation ne vient de s'afficher ci dessus : "<<endl;
				cout<<"		Aucune reservation ne correspond a votre recherche."<<endl;
				cout<<" "<<endl;
				cout<<"		";
				system("pause");
				reservation();//retour menu reservation
			}
			else
			{
				cout<<" "<<endl;
				cout<<"     ERREUR : Impossible d'ouvrir le fichier de lecture." << endl;
				cout<<"     ";
				Sleep(3000);
				reservation();//retour menu reservation
			}
		}
	}
	else if(a==5)//date de depart
	{
		if(listereservation)
		{
			string jourrecherche, moisrecherche, anneerecherche, ligne;
			int compteur(0);
	
			cout<<" "<<endl;
			cout<<"	Veuillez entrer la date de depart du vol : "<<endl;
			cout<<"		Jour";
			cin>>jourrecherche;
			cout<<"		Mois : ";
			cin>>moisrecherche;
			cout<<"		Annee : ";
			cin>>anneerecherche;
	
			ifstream listereservation("Dossier texte/listereservation.txt");
	
			do
			{
				string prenom, nom, age, numeropasseport, numerovol;
				string videpart, viarrivee, jour, mois, annee, heure, minute, prix, confirmation;

				getline(listereservation, prenom);
				getline(listereservation, nom);
				getline(listereservation, age);
				getline(listereservation, numeropasseport);
				getline(listereservation, numerovol);
				getline(listereservation, videpart);
				getline(listereservation, viarrivee);
				getline(listereservation, jour);
				getline(listereservation, mois);
				getline(listereservation, annee);
				getline(listereservation, heure);
				getline(listereservation, minute);
				getline(listereservation, prix);
				getline(listereservation, confirmation);

				if(jourrecherche==jour && moisrecherche==mois && annee==anneerecherche)
				{
					compteur=1;
					system("cls");
					cout<<" "<<endl;
					cout<<"	Voici les information concernant votre reservation : "<<endl;
					cout<<" "<<endl;
					cout<<"		Le prenom : "<<prenom<<endl;
					cout<<"		Le nom : "<<nom<<endl;
					cout<<"		L'age : "<<age<<" ans"<<endl;
					cout<<"		Le numero de passeport : "<<numeropasseport<<endl;
					cout<<"		Le numero de vol : "<<numerovol<<endl;
					cout<<"		La ville de depart : "<<videpart<<endl;
					cout<<"		La ville d arrivee : "<<viarrivee<<endl;
					cout<<"		Le"<<jour<<"/"<<mois<<"/"<<annee<<endl;
					cout<<"		A "<<heure<<"h"<<minute<<"min"<<endl;
					cout<<"		Au prix de "<<prix<<" euros"<<endl;
					cout<<"		Confirmation : "<<confirmation<<endl;
					cout<<" "<<endl;
					cout<<"		";
					system("pause");
					reservation();
				}
			}while(getline(listereservation, ligne));

			if(compteur==0)
			{
				cout<<" "<<endl;
				cout<<"	Remarque : si aucune reservation ne vient de s'afficher ci dessus : "<<endl;
				cout<<"		Aucune reservation ne correspond a votre recherche."<<endl;
				cout<<" "<<endl;
				cout<<"		";
				system("pause");
				reservation();//retour menu reservation
			}
			else
			{
				cout<<" "<<endl;
				cout<<"     ERREUR : Impossible d'ouvrir le fichier de lecture." << endl;
				cout<<"     ";
				Sleep(3000);
				reservation();//retour menu reservation
			}
		}
	}
	else if(a==0)
	{
		reservation();
	}
	else 
	{
		cout<<"		Votre choix n'est pas valide."<<endl;
		Sleep(3000);
		reservation();//retour menu reservation
	}
return(0);
}