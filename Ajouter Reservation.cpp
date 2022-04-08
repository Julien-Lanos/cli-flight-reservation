#include<iostream>
#include<windows.h>
#include<string>
#include<fstream>
#include"Reservation.1.h"
#include"Ajouter Reservation.h"

using namespace std;

int ajouterreservation()
{
	int b(0);

	string numeropasseportvoyageur;
	string ligne;

	ifstream listevoyageur("Dossier texte/listevoyageur.txt");
	ifstream listevol("Dossier texte/listevol.txt");

	cout<<" "<<endl;
	cout<<"		Une reservation regroupe un voyageur et un vol.";

	cout<<" "<<endl;
	cout<<"		Veuillez rentrer numero de passeport du voyageur : ";
	cin>>numeropasseportvoyageur;

	do
	{
		
		int a(0);
		string prenom;
		string nom;
		string age;
		string numeropasseport;

		getline(listevoyageur,prenom);
		getline(listevoyageur, nom);
		getline(listevoyageur,age);
		getline(listevoyageur, numeropasseport);

		if(numeropasseport==numeropasseportvoyageur)
		{
			b=b+1;
			string numerovol;
			string jour;
			string mois;
			string annee;
			string ligne1;

			system("cls");

			cout<<"		Ce voyageur est deja entre dans la liste des voyageurs."<<endl;
			Sleep(2000);
			
			system("cls");

			cout<<"		Veuillez entrer le numero de vol : ";
			cin>>numerovol;

			cout<<"		Veuillez maintenant entrer la date de depart."<<endl;
			cout<<"		Entrez le jour : ";
			cin>>jour;
			cout<<"		Entrez le mois : ";
			cin>>mois;
			cout<<"		Entrez l'annee : ";
			cin>>annee;

			do
			{
				string numerovol1, videpart1, viarrivee1;
				string jour1, mois1, annee1, heure1, minute1, prix1;

				getline(listevol, numerovol1);
				getline(listevol, videpart1);
				getline(listevol, viarrivee1);
				getline(listevol, jour1); 
				getline(listevol, mois1);
				getline(listevol, annee1);
				getline(listevol, heure1);
				getline(listevol, minute1);
				getline(listevol, prix1);

				if(numerovol==numerovol1 && jour==jour1 && mois==mois1 && annee==annee1)
				{
					a=a+1;
					int choix;
					string confirmation ;
					cout<<" "<<endl;
					cout<<"		Le vol existe deja (vous en avez de la chance !!)."<<endl;
					cout<<" "<<endl;
					Sleep(3000);
					
					cout<<"		La reservation est elle confirmee (oui/non) ?"<<endl;
					cout<<"		";
					cin>>confirmation;
					
					system("cls");

					do
					{
						cout<<" "<<endl;
						cout<<"	******* Voulez vous enregistrer vos donnees ? *******"<<endl;
						cout<<"	*                                                   *"<<endl;
						cout<<"	*                   1 : Oui                         *"<<endl;
						cout<<"	*                   2 : Non                         *"<<endl;
						cout<<"	*                                                   *"<<endl;
						cout<<"	*****************************************************"<<endl;
						cout<<" "<<endl;
						cout<<" "<<endl;
						cout<<"	     Votre choix : ";
						cin>>choix;

						if(choix==1)
						{
						
							ofstream MonFlux("Dossier texte/listereservation.txt",ios::app);
							if(MonFlux)
							{
								MonFlux<<prenom<<endl;
								MonFlux<<nom<<endl;
								MonFlux<<age<<endl;
								MonFlux<<numeropasseport<<endl;
								MonFlux<<numerovol<<endl;
								MonFlux<<videpart1<<endl;
								MonFlux<<viarrivee1<<endl;
								MonFlux<<jour1<<endl;
								MonFlux<<mois1<<endl;
								MonFlux<<annee1<<endl;
								MonFlux<<heure1<<endl;
								MonFlux<<minute1<<endl;
								MonFlux<<prix1<<endl;
								MonFlux<<confirmation<<endl;
								MonFlux<<"---------------------------------------------------------------------"<<endl;
							
								system("cls");
								cout<<" "<<endl;
								cout<<"	* * * * * *  Votre vol a ete enregistre.  * * * * * *"<<endl;
								cout<<"				"<<endl;
								Sleep(3000);

								reservation();//retour menu reservation
							}
							else
							{
								cout<<" "<<endl;
								cout<<"		ERREUR : Impossible d'ouvrir le fichier." << endl;
								cout<<"     ";
								Sleep(3000);
								reservation();//Retour menu reservation
							}
						}
						else if(choix==2)
						{
							reservation();//Retour Menu reservation
						}

					}while(choix!=1 &&choix!=2);
				}
			}while(getline(listevol, ligne1));

			if(a==0)
			{

				cout<<"	Aucun vol ne correspond a votre choix, enregistrons le :"<<endl;
				
				Sleep(4000);

				string numerovol, videpart, destination ;
				int jour, mois, annee, heure, minute ;
				double prix ;
				int choix ;

				cout<<" "<<endl;
				cout<<"		Veuillez entrer le numero du vol : ";
				cin>>numerovol;

				cout<<" "<<endl;
				cout<<"		Veuillez entrer la ville de depart : ";
				cin>>videpart;

				cout<<" "<<endl;
				cout<<"		Veuillez entrer la ville d'arrivee : ";
				cin >> destination;
	
				do
				{
					cout<<" "<<endl;
					cout<<"		Veuillez entrer du jour du depart : ";
					cin>>jour;
				}while(jour<1 || jour>31) ;

				do
				{
					cout<<" "<<endl;
					cout<<"		Veuillez entrer le mois du depart : ";
					cin>>mois;
				}while( mois<1 || mois>12) ;

				do
				{
					cout<<"		Veuillez entrer l'annee du depart : ";
					cin>>annee;
				}while(annee<2013 || annee>2100) ;

				do
				{
					cout<<" "<<endl;
					cout<<"		Veuillez entrer l'heure du depart : ";
					cin>>heure;
				}while(heure<00 || heure>24) ;system ("cls");

				do
				{
					cout<<" "<<endl;
					cout<<"		Veuillez entrer les minutes : ";
					cin>>minute ;
				}while(minute<00 || heure>60) ;system ("cls");

				do
				{
					cout<<" "<<endl;
					cout<<"		Veuillez entrer le prix du vol : ";
					cin>>prix;
				}while(prix<00 || heure>30000) ;
	
				system ("cls");

				//Voyons si nous voulons enregistrer les valeurs des variables demadées ci-dessus dans un fichier.

				cout<<" "<<endl;
				cout<<"	******* Voulez vous enregistrer vos donnees ? *******"<<endl;
				cout<<"	*                                                   *"<<endl;
				cout<<"	*                   1 : Oui                         *"<<endl;
				cout<<"	*                   2 : Non                         *"<<endl;
				cout<<"	*                                                   *"<<endl;
				cout<<"	*****************************************************"<<endl;
				cout<<" "<<endl;
				cout<<" "<<endl;
				cout<<"	     Votre choix : ";

				cin>>choix ;

				if(choix==1) //Oui enregistrons !
				{
					ofstream monFlux("Dossier texte/listevol.txt",ios::app);
			
					if(monFlux)
					{
						monFlux << numerovol << endl;

						monFlux << videpart << endl;
						monFlux << destination << endl;
						monFlux << jour << endl;
						monFlux << mois << endl;
						monFlux << annee << endl;
						monFlux << heure << endl;
						monFlux << minute << endl;
						monFlux << prix << endl;
						monFlux <<"---------------------------------------------------------------------"<<endl;

					}
					else
					{
						cout<<" "<<endl;
						cout<<"     ERREUR : Impossible d'ouvrir le fichier." << endl;
						cout<<"     ";
						Sleep(3000);
						reservation();//retour menu reservation
					}

						string confirmation;
						cout<<"		La reservation est elle confirmee (oui/non) ?"<<endl;
						cout<<"		";
						cin>>confirmation;

						ofstream MonFlux("Dossier texte/listereservation.txt",ios::app);
						MonFlux<<prenom<<endl;
						MonFlux<<nom<<endl;
						MonFlux<<age<<endl;
						MonFlux<<numeropasseport<<endl;
						MonFlux<<numerovol<<endl;
						MonFlux<<videpart<<endl;
						MonFlux<<destination<<endl;
						MonFlux<<jour<<endl;
						MonFlux<<mois<<endl;
						MonFlux<<annee<<endl;
						MonFlux<<heure<<endl;
						MonFlux<<minute<<endl;
						MonFlux<<prix<<endl;
						MonFlux<<confirmation<<endl;
						MonFlux<<"---------------------------------------------------------------------"<<endl;

						cout<<"	* * * *  Votre reservation a ete enregistre.  * * * *"<<endl;
						cout<<"				"<<endl;
						Sleep(3000);

						reservation();//Retour menu reservation
				}
				else //Non, n'enregistrons pas !
				{
						reservation();//revenir menu reservation
				}
			}
		}
	}while(getline(listevoyageur,ligne));

	if(b==0)
	{
		int choix;

		system("cls");

		cout<<" "<<endl;
		cout<<"		Ce passager n'est pas enregistre."<<endl;
		cout<<" "<<endl;
		cout<<"	*** Voulez vous enregistrer un nouveau voyageur ? ***"<<endl;
		cout<<"	*                                                   *"<<endl;
		cout<<"	*                   1 : Oui                         *"<<endl;
		cout<<"	*                   2 : Non                         *"<<endl;
		cout<<"	*                                                   *"<<endl;
		cout<<"	*****************************************************"<<endl;
		cout<<" "<<endl;
		cout<<" "<<endl;
		cout<<"	     Votre choix : ";

		cin>>choix;

		if(choix==1)
		{
			string prenom, nom, age, numeropasseport;

			cout<<" "<<endl;
			cout<<"	Veuillez entrer le prenom du voyageur : ";
			cin>>prenom;

			cout<<" "<<endl;
			cout<<"	Veuillez entrer le nom du voyageur : ";
			cin>>nom;

			cout<<" "<<endl;
			cout<<"	Veuillez entrer l'age du voyageur : ";
			cin>>age;

			cout<<" "<<endl;
			cout<<"	Veuillez entrer le numero de passeport du voyageur : ";
			cin>>numeropasseport;

			ofstream MonFlux("Dossier texte/listevoyageur.txt",ios::app);
				
			if(MonFlux)
			{
				MonFlux<<prenom<<endl;
				MonFlux<<nom<<endl;
				MonFlux<<age<<endl;
				MonFlux<<numeropasseport<<endl;
				MonFlux<<"---------------------------------------------------------------------"<<endl;

				system("cls");
				cout<<" "<<endl;
				cout<<"	* * * * *  Votre voyageur a ete enregistre. * * * * *"<<endl;
				cout<<"				"<<endl;
				Sleep(3000);
			}
			else
			{
				cout<<" "<<endl;
				cout<<"     ERREUR : Impossible d'ouvrir le fichier." << endl;
				cout<<"     ";
				Sleep(3000);
				reservation();//retour menu reservation
			}
			system("cls");
				
			int a(0);
			string numerovol, jour, mois, annee, ligne;
			cout<<" "<<endl;	
			cout<<"	Veuillez entrer le numero de vol que ce voyageur prendra : ";
			cin>>numerovol;
			cout<<" "<<endl;
			cout<<"		Veuillez entrer la date de depart du vol : "<<endl;
			cout<<"		Jour : ";
			cin>>jour;
			cout<<"		Mois : ";
			cin>>mois;
			cout<<"		Annee : ";
			cin>>annee;
					
			do
			{
				string numerovol1, sautligne11;
				string sautligne21, sautligne31, sautligne41, sautligne51, sautligne61, sautligne71, sautligne81;

				getline(listevol, numerovol1);
				getline(listevol,sautligne11);
				getline(listevol,sautligne21);
				getline(listevol,sautligne31);
				getline(listevol,sautligne41);
				getline(listevol,sautligne51);
				getline(listevol,sautligne61);
				getline(listevol,sautligne71);
				getline(listevol,sautligne81);

				if(numerovol==numerovol1 && jour==sautligne31 && mois==sautligne41 && annee==sautligne51)
				{
					string confirmation;
					//Si le vol existe
					a=a+1;

					system("cls");
					cout<<" "<<endl;
					cout<<"Le vol recherche a ete trouve"<<endl;

					cout<<"La reservation est elle confirmee (oui ou non) ?"<<endl;
					cin>>confirmation;

					ofstream monflux("Dossier texte/listereservation.txt",ios::app);
								
					if(monflux)
					{
						monflux<<prenom<<endl;
						monflux<<nom<<endl;
						monflux<<age<<endl;
						monflux<<numeropasseport<<endl;
						monflux<<numerovol1<<endl;
						monflux<<sautligne11<<endl;
						monflux<<sautligne21<<endl;
						monflux<<sautligne31<<endl;
						monflux<<sautligne41<<endl;
						monflux<<sautligne51<<endl;
						monflux<<sautligne61<<endl;
						monflux<<sautligne71<<endl;
						monflux<<sautligne81<<endl;
						monflux<<confirmation<<endl;
						monflux<<"---------------------------------------------------------------------"<<endl;

						cout<<"	* * * *  Votre reservation a ete enregistre.  * * * *"<<endl;
						Sleep(3500);
						reservation();//retour menu reservation
					}
					else
					{
						cout<<" "<<endl;
						cout<<"     ERREUR : Impossible d'ouvrir le fichier." << endl;
						cout<<"     ";
						Sleep(3000);
						reservation();//retour menu reservation
					}	
				}
			}while(getline(listevol, ligne));

			if(a==0)
			{
				int choisir;
				//Si le vol n'existe pas
				system("cls");
				cout<<" "<<endl;
				cout<<"		Aucun vol ne correspond a votre recherche"<<endl;
				cout<<" "<<endl;
				cout<<"	*****  Voulez vous enregistrer un nouveau vol ? *****"<<endl;
				cout<<"	*                                                   *"<<endl;
				cout<<"	*                   1 : Oui                         *"<<endl;
				cout<<"	*                   2 : Non                         *"<<endl;
				cout<<"	*                                                   *"<<endl;
				cout<<"	*****************************************************"<<endl;
				cout<<" "<<endl;
				cout<<" "<<endl;
				cout<<"	     Votre choix : ";

				cin>>choisir;
				system("cls");

				if(choisir==1)
				{
					string sautligne11, sautligne21, sautligne61, sautligne71, sautligne81;

					cout<<" "<<endl;
					cout<<"		Veuillez entrer la ville de depart : ";
					cin>>sautligne11;
					cout<<"		Veuillez entrer la ville d'arrivee : ";
					cin>>sautligne21;
					cout<<" "<<endl;
					cout<<"		Veuillez entrer l'heure de depart : ";
					cin>>sautligne61;
					cout<<"		Veuillez entrer les minutes : ";
					cin>>sautligne71;
					cout<<" "<<endl;
					cout<<"		Veuillez entrer le prix du vol : ";
					cin>>sautligne81;

					ofstream monflux1("Dossier texte/listevol.txt",ios::app);
							
					if(monflux1)
					{
						string confirmation;

						monflux1<<numerovol<<endl;
						monflux1<<sautligne11<<endl;
						monflux1<<sautligne21<<endl;
						monflux1<<jour<<endl;
						monflux1<<mois<<endl;
						monflux1<<annee<<endl;
						monflux1<<sautligne61<<endl;
						monflux1<<sautligne71<<endl;
						monflux1<<sautligne81<<endl;
						monflux1<<"---------------------------------------------------------------------"<<endl;

						system("cls");
						cout<<" "<<endl;
						cout<<"	* * * * * *  Votre vol a ete enregistre.  * * * * * *"<<endl;
						cout<<"				"<<endl;
						Sleep(3000);
						cout<<" "<<endl;
						cout<<"		La reservation est elle confirmee (oui/non) ?"<<endl;
						cout<<"		";
						cin>>confirmation;

						ofstream monflux2("Dossier texte/listereservation.txt",ios::app);
									
						if(monflux2)
						{
							monflux2<<prenom<<endl;
							monflux2<<nom<<endl;
							monflux2<<age<<endl;
							monflux2<<numeropasseport<<endl;
							monflux2<<numerovol<<endl;
							monflux2<<sautligne11<<endl;
							monflux2<<sautligne21<<endl;
							monflux2<<jour<<endl;
							monflux2<<mois<<endl;
							monflux2<<annee<<endl;
							monflux2<<sautligne61<<endl;
							monflux2<<sautligne71<<endl;
							monflux2<<sautligne81<<endl;
							monflux2<<confirmation<<endl;
							monflux2<<"---------------------------------------------------------------------"<<endl;

							cout<<"	* * * *  Votre reservation a ete enregistre.  * * * *"<<endl;
							cout<<"	         ";
							system("pause");
							reservation();//retour menu reservation
						}
						else
						{
							cout<<" "<<endl;
							cout<<"     ERREUR : Impossible d'ouvrir le fichier." << endl;
							cout<<"     ";
							Sleep(3000);
							reservation();//retour menu reservation
						}
					}
					else
					{
						cout<<" "<<endl;
						cout<<"     ERREUR : Impossible d'ouvrir le fichier." << endl;
						cout<<"     ";
						Sleep(3000);
						reservation();//retour menu reservation
					}
				}
				else
				{
					reservation();//retour menu reservation
				}
			}
		}
		else
		{
			reservation();//Retour Menu Reservation
		}
	}
return(0);
}