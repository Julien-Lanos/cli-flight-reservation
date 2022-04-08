#include<iostream>
#include<windows.h>
#include<string>
#include<fstream>
#include"Supprimer Vols.h"
#include"Vols.1.h"

using namespace std;

int supprimervols()
{
	string numerorecherche, ligne, ligne2, ligne3;
	
	cout<<" "<<endl;
	cout<<"	Veuillez entrer le numero du vol a supprimer : ";
	cin>>numerorecherche;

	ifstream listevol("Dossier texte/listevol.txt");
	ofstream MonFlux("Dossier texte/listevolauxiliaire.txt");

			do
			{
			string numerovol;
			string sautligne1;
			string sautligne2;
			string sautligne3;
			string sautligne4;
			string sautligne5;
			string sautligne6;
			string sautligne7;
			string sautligne8;
			
			getline(listevol, numerovol);
			getline(listevol,sautligne1);
			getline(listevol,sautligne2);
			getline(listevol,sautligne3);
			getline(listevol,sautligne4);
			getline(listevol,sautligne5);
			getline(listevol,sautligne6);
			getline(listevol,sautligne7);
			getline(listevol,sautligne8);
			
				if(numerorecherche!=numerovol)
				{
					ofstream MonFlux("Dossier texte/listevolauxiliaire.txt",ios::app);
					MonFlux<<" "<<endl;
					MonFlux<< numerovol <<endl;
					MonFlux<< sautligne1 <<endl;
					MonFlux<< sautligne2 <<endl;
					MonFlux<< sautligne3 <<endl;
					MonFlux<< sautligne4 <<endl;
					MonFlux<< sautligne5 <<endl;
					MonFlux<< sautligne6 <<endl;
					MonFlux<< sautligne7 <<endl;
					MonFlux<< sautligne8 <<endl;

				}

			}while(getline(listevol, ligne));

			ifstream listevolauxiliaire("Dossier texte/listevolauxiliaire.txt");
			ofstream MonFlux2("Dossier texte/listevol.txt");

			while(getline(listevolauxiliaire, ligne2))
			{
				ofstream MonFlux2("Dossier texte/listevol.txt",ios::app);

				string numerovol1;
				string sautligne11;
				string sautligne21;
				string sautligne31;
				string sautligne41;
				string sautligne51;
				string sautligne61;
				string sautligne71;
				string sautligne81;

				getline(listevolauxiliaire, numerovol1);
				getline(listevolauxiliaire,sautligne11);
				getline(listevolauxiliaire,sautligne21);
				getline(listevolauxiliaire,sautligne31);
				getline(listevolauxiliaire,sautligne41);
				getline(listevolauxiliaire,sautligne51);
				getline(listevolauxiliaire,sautligne61);
				getline(listevolauxiliaire,sautligne71);
				getline(listevolauxiliaire,sautligne81);
				
				MonFlux2<< numerovol1 <<endl;
				MonFlux2<< sautligne11 <<endl;
				MonFlux2<< sautligne21 <<endl;
				MonFlux2<< sautligne31 <<endl;
				MonFlux2<< sautligne41 <<endl;
				MonFlux2<< sautligne51 <<endl;
				MonFlux2<< sautligne61 <<endl;
				MonFlux2<< sautligne71 <<endl;
				MonFlux2<< sautligne81 <<endl;
				MonFlux2<<"-------------------------------------------------------------------------"<<endl;
	}
	system("cls");
	cout<<" "<<endl;
	cout<<"			Votre vol a bien ete supprimer."<<endl;
	cout<<"			";
	Sleep(4000);
	vols();
	return(0);
}		