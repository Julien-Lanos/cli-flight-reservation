#include<iostream>
#include<windows.h>
#include<string>
#include<fstream>
#include"Afficher Reservation.h"
#include"Reservation.1.h"

using namespace std;

int afficherreservation()
{
	cout<<" "<<endl;
	cout<<"		Voici la liste des differentes reservations saisis :"<<endl;
	cout<<" "<<endl;
	cout<<"-------------------------------------------------------------------------"<<endl;

	string ligne, prenom, nom, age, numeropasseport, numerovol, videpart;
	string viarrivee, jour, mois, annee, heure, minute, prix, confirmation;

	ifstream listereservation("Dossier texte/listereservation.txt");

	if(listereservation)
	{
		do
		{
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

			if(prenom!="")
			{

				cout<<"		Le prenom : "<<prenom<<endl;
				cout<<"		Le nom : "<<nom<<endl;
				cout<<"		L'age : "<<age<<endl;
				cout<<"		Le numero de passeport : "<<numeropasseport<<endl;
				cout<<"		Le numero de vol : "<<numerovol<<endl;
				cout<<"		La ville de depart : "<<videpart<<endl;
				cout<<"		La ville d arrivee : "<<viarrivee<<endl;
				cout<<"		Le"<<jour<<"/"<<mois<<"/"<<annee<<endl;
				cout<<"		A "<<heure<<"h"<<minute<<"min"<<endl;
				cout<<"		Au prix de "<<prix<<" euro"<<endl;
				cout<<"		Reserve : "<<confirmation<<endl;
				cout<<"-------------------------------------------------------------------------"<<endl;
			}

		}while(getline(listereservation, ligne));

		cout<<" "<<endl;
		cout<<"		";
		system("pause");
		reservation();
	}
	else
	{
		cout<<"		ERREUR : Impossible d'ouvrir le fichier de lecture."<<endl;
		Sleep(3000);
		reservation();
	}
	return(0);
}