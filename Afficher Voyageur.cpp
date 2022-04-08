#include<iostream>
#include<windows.h>
#include<string>
#include<fstream>
#include"Afficher Voyageur.h"
#include"Voyageur.1.h"

using namespace std;

int affichervoyageur()
{
	cout<<" "<<endl;
	cout<<"		Voici la liste des differents voyageurs saisis :"<<endl;
	cout<<" "<<endl;
	cout<<"-------------------------------------------------------------------------"<<endl;

	ifstream listevoyageur("Dossier texte/listevoyageur.txt");

	if(listevoyageur)
	{
		string ligne;
		do
		{

			string ligne,prenom,nom,age,numeroDePasseport;
 
			getline(listevoyageur,prenom); 
			if(prenom!="")
			{
				cout <<"		Le prenom du voyageur est : "<<prenom<< endl;
			}

			getline(listevoyageur, nom);
			if(nom!="")
			{
				cout<<"		Le nom du voyageur est : "<<nom<<endl;
			}
	
			getline(listevoyageur, age);
			if(age!="")
			{
				cout<<"		L'age du voyageur est : "<<age<<endl;
			}
			
			getline(listevoyageur, numeroDePasseport);
			if(numeroDePasseport!="")
			{
				cout<<"		Le numero de passeport du voyageur est : "<<numeroDePasseport<<endl;
			}

			 
			if(prenom!="")
			{
				cout<<"-------------------------------------------------------------------------"<<endl;
			}
	  }while(getline(listevoyageur, ligne));
		
		cout<<" "<<endl;
		cout<<"		";
		system("pause");

		voyageur();//Retour Menu Voyageur
     }
   else
   {
      cout<<"		ERREUR : Impossible d'ouvrir le fichier de lecture." << endl;
	  Sleep(3000);
	  voyageur();//Retour Menu Voyageur
   }
   return 0;
}