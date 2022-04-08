#include<iostream>
#include<windows.h>
#include<string>
#include<fstream>
#include"Reservation.1.h"
#include"Modifier Reservation.h"

using namespace std;

int modifierreservation()
{
	int compteur(0);
	string numeropasseportrecherche, numerovolrecherche, jourrecherche, moisrecherche, anneerecherche, ligne;
	
	cout<<" "<<endl;
	cout<<"		Veuillez entrer le numero de passeport : ";
	cin>>numeropasseportrecherche;
	cout<<" "<<endl;

	cout<<"		Veuillez entrer le numero de vol de la reservation a modifier : ";
	cin>>numerovolrecherche;
	cout<<" "<<endl;

	cout<<"		Veuillez entrer la date de la reservation :"<<endl;
	cout<<"		Jour : ";
	cin>>jourrecherche;
	cout<<"		Mois : ";
	cin>>moisrecherche;
	cout<<"		Annee : ";
	cin>>anneerecherche;

	ifstream listereservation("Dossier texte/listereservation.txt");

	if(listereservation)
	{
		do//cherchons la reservation a modifier
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

			if(numeropasseportrecherche==numeropasseport &&numerovolrecherche==numerovol)
			{
				compteur=1;
				int choix;
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
				cout<<"		Au prix de "<<prix<<" Euro"<<endl;
				cout<<"		Confirmation : "<<confirmation<<endl;
				cout<<"-------------------------------------------------------------------------"<<endl;
				cout<<""<<endl;
				cout<<"	****** Cette reservation est-elle a modifier ? ******"<<endl;
				cout<<"	*                                                   *"<<endl;
				cout<<"	*                   1 : Oui                         *"<<endl;
				cout<<"	*                   2 : Non                         *"<<endl;
				cout<<"	*                                                   *"<<endl;
				cout<<"	*****************************************************"<<endl;
				cout<<" "<<endl;
				cout<<" "<<endl;
				cout<<"	     Votre choix : ";
				cin>>choix;

				if(choix==1)//oui c'est bien ce vol que je souhaite modifier !
				{
					int choisir;
					system("cls");
					cout<<"	*********** Que souhaitez vous modifier ? ***********"<<endl;
					cout<<"	*                                                   *"<<endl;
					cout<<"	*                1 : Nom-Prenom                     *"<<endl;
					cout<<"	*                2 : Age                            *"<<endl;
					cout<<"	*                3 : Numero de passeport            *"<<endl;
					cout<<"	*                4 : Numero de vol                  *"<<endl;
					cout<<"	*                5 : Ville depart/destination       *"<<endl;
					cout<<"	*                6 : Date                           *"<<endl;
					cout<<"	*                7 : Heure                          *"<<endl;
					cout<<"	*                8 : Prix                           *"<<endl;
					cout<<"	*                9 : Confirmation                   *"<<endl;
					cout<<"	*                                                   *"<<endl;
					cout<<"	********** 0 : Retour au Menu Reservations **********"<<endl;
					cout<<" "<<endl;
					cout<<" "<<endl;
					cout<<"	     Votre choix : ";
					cin>>choisir;
					system("cls");

					if(choisir==1)
					{
						//Modifier Nom-Prenom
						string nouveaunom, nouveauprenom, ligne2, ligne3;
						cout<<" "<<endl;
						cout<<"	Veuillez entrer le nouveau prenom : ";
						cin>>nouveauprenom;
						cout<<" "<<endl;
						cout<<"	Veuillez entrer le nouveau nom : ";
						cin>>nouveaunom;

						//Modifier sur liste reservation
						ofstream MonFlux("Dossier texte/listevolauxiliaire.txt");
						ifstream listevolauxiliaire("Dossier texte/listevolauxiliaire.txt");
						ifstream listereservation("Dossier texte/listereservation.txt");

						do //lisons le fichier liste reservation
						{
							string sautligne11, sautligne21, sautligne31, sautligne41, numerovol1, sautligne51, sautligne61, sautligne71;
							string sautligne81, sautligne91, sautligne101, sautligne111, sautligne121, confirmation;

							getline(listereservation,sautligne11);
							getline(listereservation,sautligne21);
							getline(listereservation,sautligne31);
							getline(listereservation,sautligne41);
							getline(listereservation, numerovol1);
							getline(listereservation,sautligne51);
							getline(listereservation,sautligne61);
							getline(listereservation,sautligne71);
							getline(listereservation,sautligne81);
							getline(listereservation,sautligne91);
							getline(listereservation,sautligne101);
							getline(listereservation,sautligne111);
							getline(listereservation,sautligne121);
							getline(listereservation,confirmation);

							if(sautligne41!=numeropasseportrecherche && sautligne41!="")// tous les vols que l'on ne veut pas modifier sont copiés dans le fichier listevolauxiliaire
							{
								ofstream MonFlux("Dossier texte/listevolauxiliaire.txt",ios::app);
					
								MonFlux<<""<<endl;
								MonFlux<< sautligne11 <<endl;
								MonFlux<< sautligne21 <<endl;
								MonFlux<< sautligne31 <<endl;
								MonFlux<< sautligne41 <<endl;
								MonFlux<< numerovol1 <<endl;
								MonFlux<< sautligne51 <<endl;
								MonFlux<< sautligne61 <<endl;
								MonFlux<< sautligne71 <<endl;
								MonFlux<< sautligne81 <<endl;
								MonFlux<< sautligne91 <<endl;
								MonFlux<< sautligne101 <<endl;
								MonFlux<< sautligne111 <<endl;
								MonFlux<< sautligne121 <<endl;
								MonFlux<< confirmation <<endl;

							}
							else if(sautligne41==numeropasseportrecherche)//pour le vol que l'on souhaite modifier on copie tous les parametre inchangés dans liste vol auxiliaire en changeant celui que je souhaite mosifier
							{
								ofstream MonFlux("Dossier texte/listevolauxiliaire.txt",ios::app);
					
								MonFlux<<""<<endl;
								MonFlux<< nouveauprenom <<endl;
								MonFlux<< nouveaunom <<endl;
								MonFlux<< sautligne31 <<endl;
								MonFlux<< sautligne41 <<endl;
								MonFlux<< numerovol1 <<endl;
								MonFlux<< sautligne51 <<endl;
								MonFlux<< sautligne61 <<endl;
								MonFlux<< sautligne71 <<endl;
								MonFlux<< sautligne81 <<endl;
								MonFlux<< sautligne91 <<endl;
								MonFlux<< sautligne101 <<endl;
								MonFlux<< sautligne111 <<endl;
								MonFlux<< sautligne121 <<endl;
								MonFlux<< confirmation <<endl;

							}
					
						}while(getline(listereservation,ligne2));

						ofstream monFlux("Dossier texte/listereservation.txt");

						while(getline(listevolauxiliaire, ligne3))//enfin copions le fichier vol auxiliaire dans celui liste vol en l'évrasant cette fois ci !
						{
							ofstream monFlux("Dossier texte/listereservation.txt",ios::app);
							
							string sautligne1, sautligne2, sautligne3, sautligne4, numerovol2, sautligne5, sautligne6;
							string sautligne7, sautligne8, sautligne9, sautligne10, sautligne11, sautligne12, sautligne13;
			
							getline(listevolauxiliaire,sautligne1);
							getline(listevolauxiliaire,sautligne2);
							getline(listevolauxiliaire,sautligne3);
							getline(listevolauxiliaire,sautligne4);
							getline(listevolauxiliaire, numerovol2);
							getline(listevolauxiliaire,sautligne5);
							getline(listevolauxiliaire,sautligne6);
							getline(listevolauxiliaire,sautligne7);
							getline(listevolauxiliaire,sautligne8);
							getline(listevolauxiliaire,sautligne9);
							getline(listevolauxiliaire,sautligne10);
							getline(listevolauxiliaire,sautligne11);
							getline(listevolauxiliaire,sautligne12);
							getline(listevolauxiliaire,sautligne13);
	
							monFlux <<sautligne1<<endl;
							monFlux <<sautligne2<<endl;
							monFlux <<sautligne3<<endl;
							monFlux <<sautligne4<<endl;
							monFlux <<numerovol2<<endl;
							monFlux <<sautligne5<<endl;
							monFlux <<sautligne6<<endl;
							monFlux <<sautligne7<<endl;
							monFlux <<sautligne8<<endl;
							monFlux <<sautligne9<<endl;
							monFlux <<sautligne10<<endl;
							monFlux <<sautligne11<<endl;
							monFlux <<sautligne12<<endl;
							monFlux <<sautligne13<<endl;
							monFlux <<"-------------------------------------------------------------------------"<<endl;
									
						}
						//Modifions le voyageur dans liste voyageur !
						ofstream MonFlux99("Dossier texte/listevolauxiliaire.txt");
						ifstream listevolauxiliaire1("Dossier texte/listevolauxiliaire.txt");
						ifstream listevoyageur("Dossier texte/listevoyageur.txt");
						string ligne31;

						do
						{					
							string sautligne11,sautligne21,sautligne31,sautligne51,numeroDePasseport1;

							getline(listevoyageur,sautligne11);
							getline(listevoyageur,sautligne21);
							getline(listevoyageur,sautligne31);					
							getline(listevoyageur,numeroDePasseport1);

							if(numeropasseportrecherche!=numeroDePasseport1)
							{
								ofstream MonFlux99("Dossier texte/listevolauxiliaire.txt",ios::app);
					
								MonFlux99<<""<<endl;
								MonFlux99<< sautligne11 <<endl;					
								MonFlux99<< sautligne21 <<endl;
								MonFlux99<< sautligne31 <<endl;
								MonFlux99<< numeroDePasseport1 <<endl;
											
							}
							else
							{
								ofstream MonFlux99("Dossier texte/listevolauxiliaire.txt",ios::app);
					
								MonFlux99<<""<<endl;
								MonFlux99<< nouveauprenom <<endl;
								MonFlux99<< nouveaunom <<endl;
								MonFlux99<< sautligne31 <<endl;
								MonFlux99<< numeroDePasseport1 <<endl;
							}

						}while(getline(listevoyageur, ligne2));

						ofstream monFlux99("Dossier texte/listevoyageur.txt");

						while(getline(listevolauxiliaire1,ligne31))//enfin copions le fichier voyageur auxiliaire dans celui liste voyageur en l'évrasant cette fois ci !
						{
							ofstream monFlux99("Dossier texte/listevoyageur.txt",ios::app);
						
							string numeroDePasseport2,sautligne1,sautligne2,sautligne3,sautligne5;			
						
							getline(listevolauxiliaire1,sautligne1);
							getline(listevolauxiliaire1,sautligne2);
							getline(listevolauxiliaire1,sautligne3);
							getline(listevolauxiliaire1, numeroDePasseport2);
												
							monFlux99 <<sautligne1<<endl;
							monFlux99 <<sautligne2<<endl;
							monFlux99 <<sautligne3<<endl;
							monFlux99 <<numeroDePasseport2<<endl;
							monFlux99 <<"-------------------------------------------------------------------------"<<endl;
						}		
						system("cls");
						cout<<" "<<endl;
						cout<<"			Votre reservation a bien ete modifier."<<endl;
						cout<<"			";
						Sleep(4000);		
						reservation();//Retour Menu reservation
					}
					else if(choisir==2)
					{
						//Modifier Age
						string nouveauage, ligne2, ligne3;

						cout<<" "<<endl;
						cout<<"	Veuillez entrer l'age du voyageur : ";
						cin>>nouveauage;

						//Modifier sur liste reservation
						ofstream MonFlux("Dossier texte/listevolauxiliaire.txt");
						ifstream listevolauxiliaire("Dossier texte/listevolauxiliaire.txt");
						ifstream listereservation("Dossier texte/listereservation.txt");

						do //lisons le fichier liste reservation
						{
							string sautligne11, sautligne21, sautligne31, sautligne41, numerovol1, sautligne51, sautligne61;
							string sautligne71, sautligne81, sautligne91, sautligne101, sautligne111, sautligne121, confirmation;

							getline(listereservation,sautligne11);
							getline(listereservation,sautligne21);
							getline(listereservation,sautligne31);
							getline(listereservation,sautligne41);
							getline(listereservation, numerovol1);
							getline(listereservation,sautligne51);
							getline(listereservation,sautligne61);
							getline(listereservation,sautligne71);
							getline(listereservation,sautligne81);
							getline(listereservation,sautligne91);
							getline(listereservation,sautligne101);
							getline(listereservation,sautligne111);
							getline(listereservation,sautligne121);
							getline(listereservation,confirmation);

							if(sautligne41!=numeropasseportrecherche && sautligne41!="")// tous les vols que l'on ne veut pas modifier sont copiés dans le fichier listevolauxiliaire
							{
								ofstream MonFlux("Dossier texte/listevolauxiliaire.txt",ios::app);
					
								MonFlux<<""<<endl;
								MonFlux<< sautligne11 <<endl;
								MonFlux<< sautligne21 <<endl;
								MonFlux<< sautligne31 <<endl;
								MonFlux<< sautligne41 <<endl;
								MonFlux<< numerovol1 <<endl;
								MonFlux<< sautligne51 <<endl;
								MonFlux<< sautligne61 <<endl;
								MonFlux<< sautligne71 <<endl;
								MonFlux<< sautligne81 <<endl;
								MonFlux<< sautligne91 <<endl;
								MonFlux<< sautligne101 <<endl;
								MonFlux<< sautligne111 <<endl;
								MonFlux<< sautligne121 <<endl;
								MonFlux<< confirmation <<endl;

							}
							else if(sautligne41==numeropasseportrecherche)//pour le vol que l'on souhaite modifier on copie tous les parametre inchangés dans liste vol auxiliaire en changeant celui que je souhaite mosifier
							{
								ofstream MonFlux("Dossier texte/listevolauxiliaire.txt",ios::app);
					
								MonFlux<<""<<endl;
								MonFlux<< sautligne11 <<endl;
								MonFlux<< sautligne21 <<endl;
								MonFlux<< nouveauage <<endl;
								MonFlux<< sautligne41 <<endl;
								MonFlux<< numerovol1 <<endl;
								MonFlux<< sautligne51 <<endl;
								MonFlux<< sautligne61 <<endl;
								MonFlux<< sautligne71 <<endl;
								MonFlux<< sautligne81 <<endl;
								MonFlux<< sautligne91 <<endl;
								MonFlux<< sautligne101 <<endl;
								MonFlux<< sautligne111 <<endl;
								MonFlux<< sautligne121 <<endl;
								MonFlux<< confirmation <<endl;

							}
						}while(getline(listereservation,ligne2));

						ofstream monFlux("Dossier texte/listereservation.txt");

						while(getline(listevolauxiliaire, ligne3))//enfin copions le fichier vol auxiliaire dans celui liste vol en l'évrasant cette fois ci !
						{
							ofstream monFlux("Dossier texte/listereservation.txt",ios::app);
						
							string sautligne1, sautligne2, sautligne3, sautligne4, numerovol2, sautligne5, sautligne6;
							string sautligne7, sautligne8, sautligne9, sautligne10, sautligne11, sautligne12, sautligne13;
		
							getline(listevolauxiliaire,sautligne1);
							getline(listevolauxiliaire,sautligne2);
							getline(listevolauxiliaire,sautligne3);
							getline(listevolauxiliaire,sautligne4);
							getline(listevolauxiliaire, numerovol2);
							getline(listevolauxiliaire,sautligne5);
							getline(listevolauxiliaire,sautligne6);
							getline(listevolauxiliaire,sautligne7);
							getline(listevolauxiliaire,sautligne8);
							getline(listevolauxiliaire,sautligne9);
							getline(listevolauxiliaire,sautligne10);
							getline(listevolauxiliaire,sautligne11);
							getline(listevolauxiliaire,sautligne12);
							getline(listevolauxiliaire,sautligne13);

							monFlux <<sautligne1<<endl;
							monFlux <<sautligne2<<endl;
							monFlux <<sautligne3<<endl;
							monFlux <<sautligne4<<endl;
							monFlux <<numerovol2<<endl;
							monFlux <<sautligne5<<endl;
							monFlux <<sautligne6<<endl;
							monFlux <<sautligne7<<endl;
							monFlux <<sautligne8<<endl;
							monFlux <<sautligne9<<endl;
							monFlux <<sautligne10<<endl;
							monFlux <<sautligne11<<endl;
							monFlux <<sautligne12<<endl;
							monFlux <<sautligne13<<endl;
							monFlux <<"-------------------------------------------------------------------------"<<endl;
						
						}
							//Modifier dans liste voyageur l''age !
						ofstream MonFlux99("Dossier texte/listevolauxiliaire.txt");
						ifstream listevolauxiliaire1("Dossier texte/listevolauxiliaire.txt");
						ifstream listevoyageur("Dossier texte/listevoyageur.txt");
						string ligne31;

						do
						{					
							string sautligne11,sautligne21,sautligne31,sautligne51,numeroDePasseport1;

							getline(listevoyageur,sautligne11);
							getline(listevoyageur,sautligne21);
							getline(listevoyageur,sautligne31);					
							getline(listevoyageur,numeroDePasseport1);

							if(numeropasseportrecherche!=numeroDePasseport1)
							{
								ofstream MonFlux99("Dossier texte/listevolauxiliaire.txt",ios::app);
					
								MonFlux99<<""<<endl;
								MonFlux99<< sautligne11 <<endl;					
								MonFlux99<< sautligne21 <<endl;
								MonFlux99<< sautligne31 <<endl;
								MonFlux99<< numeroDePasseport1 <<endl;				
							}
							else
							{
								ofstream MonFlux99("Dossier texte/listevolauxiliaire.txt",ios::app);
					
								MonFlux99<<""<<endl;
								MonFlux99<< sautligne11 <<endl;
								MonFlux99<< sautligne21 <<endl;
								MonFlux99<< nouveauage <<endl;
								MonFlux99<< numeroDePasseport1 <<endl;
							}

						}while(getline(listevoyageur, ligne2));

						ofstream monFlux99("Dossier texte/listevoyageur.txt");

						while(getline(listevolauxiliaire1,ligne31))//enfin copions le fichier voyageur auxiliaire dans celui liste voyageur en l'évrasant cette fois ci !
						{
							ofstream monFlux99("Dossier texte/listevoyageur.txt",ios::app);
						
							string numeroDePasseport2,sautligne1,sautligne2,sautligne3,sautligne5;			
						
							getline(listevolauxiliaire1,sautligne1);
							getline(listevolauxiliaire1,sautligne2);
							getline(listevolauxiliaire1,sautligne3);
							getline(listevolauxiliaire1, numeroDePasseport2);
												
							monFlux99 <<sautligne1<<endl;
							monFlux99 <<sautligne2<<endl;
							monFlux99 <<sautligne3<<endl;
							monFlux99 <<numeroDePasseport2<<endl;
							monFlux99 <<"-------------------------------------------------------------------------"<<endl;
						}		
					
						system("cls");
						cout<<" "<<endl;
						cout<<"			Votre reservation a bien ete modifier."<<endl;
						cout<<"			";
						Sleep(4000);			
						reservation();//Retour Menu reservation

					}
					else if(choisir==3)//Modifier Numeropasseport
					{
						string nouveaunumeropasseport, ligne2, ligne3;

						cout<<" "<<endl;
						cout<<"	Veuillez entrer le numero de passeport du voyageur : ";
						cin>>nouveaunumeropasseport;

						//Modifier sur liste reservation
						ofstream MonFlux("Dossier texte/listevolauxiliaire.txt");
						ifstream listevolauxiliaire("Dossier texte/listevolauxiliaire.txt");
						ifstream listereservation("Dossier texte/listereservation.txt");

						do //lisons le fichier liste reservation
						{
							string sautligne11, sautligne21, sautligne31, sautligne41, numerovol1, sautligne51, sautligne61;
							string sautligne71, sautligne81, sautligne91, sautligne101, sautligne111, sautligne121, confirmation;

							getline(listereservation,sautligne11);
							getline(listereservation,sautligne21);
							getline(listereservation,sautligne31);
							getline(listereservation,sautligne41);
							getline(listereservation, numerovol1);
							getline(listereservation,sautligne51);
							getline(listereservation,sautligne61);
							getline(listereservation,sautligne71);
							getline(listereservation,sautligne81);
							getline(listereservation,sautligne91);
							getline(listereservation,sautligne101);
							getline(listereservation,sautligne111);
							getline(listereservation,sautligne121);
							getline(listereservation,confirmation);

							if(sautligne41!=numeropasseportrecherche && sautligne41!="")// tous les vols que l'on ne veut pas modifier sont copiés dans le fichier listevolauxiliaire
							{
								ofstream MonFlux("Dossier texte/listevolauxiliaire.txt",ios::app);
					
								MonFlux<<""<<endl;
								MonFlux<< sautligne11 <<endl;
								MonFlux<< sautligne21 <<endl;
								MonFlux<< sautligne31 <<endl;
								MonFlux<< sautligne41 <<endl;
								MonFlux<< numerovol1 <<endl;
								MonFlux<< sautligne51 <<endl;
								MonFlux<< sautligne61 <<endl;
								MonFlux<< sautligne71 <<endl;
								MonFlux<< sautligne81 <<endl;
								MonFlux<< sautligne91 <<endl;
								MonFlux<< sautligne101 <<endl;
								MonFlux<< sautligne111 <<endl;
								MonFlux<< sautligne121 <<endl;
								MonFlux<< confirmation <<endl;

							}
							else if(sautligne41==numeropasseportrecherche)//pour le vol que l'on souhaite modifier on copie tous les parametre inchangés dans liste vol auxiliaire en changeant celui que je souhaite mosifier
							{
								ofstream MonFlux("Dossier texte/listevolauxiliaire.txt",ios::app);
					
								MonFlux<<""<<endl;
								MonFlux<< sautligne11 <<endl;
								MonFlux<< sautligne21 <<endl;
								MonFlux<< sautligne31 <<endl;
								MonFlux<< nouveaunumeropasseport <<endl;
								MonFlux<< numerovol1 <<endl;
								MonFlux<< sautligne51 <<endl;
								MonFlux<< sautligne61 <<endl;
								MonFlux<< sautligne71 <<endl;
								MonFlux<< sautligne81 <<endl;
								MonFlux<< sautligne91 <<endl;
								MonFlux<< sautligne101 <<endl;
								MonFlux<< sautligne111 <<endl;
								MonFlux<< sautligne121 <<endl;
								MonFlux<< confirmation <<endl;

							}
					
						}while(getline(listereservation,ligne2));

						ofstream monFlux("Dossier texte/listereservation.txt");

						while(getline(listevolauxiliaire, ligne3))//enfin copions le fichier vol auxiliaire dans celui liste vol en l'évrasant cette fois ci !
						{
							ofstream monFlux("Dossier texte/listereservation.txt",ios::app);
						
							string sautligne1, sautligne2, sautligne3, sautligne4, numerovol2, sautligne5, sautligne6;
							string sautligne7, sautligne8, sautligne9, sautligne10, sautligne11, sautligne12, sautligne13;
		
							getline(listevolauxiliaire,sautligne1);
							getline(listevolauxiliaire,sautligne2);
							getline(listevolauxiliaire,sautligne3);
							getline(listevolauxiliaire,sautligne4);
							getline(listevolauxiliaire, numerovol2);
							getline(listevolauxiliaire,sautligne5);
							getline(listevolauxiliaire,sautligne6);
							getline(listevolauxiliaire,sautligne7);
							getline(listevolauxiliaire,sautligne8);
							getline(listevolauxiliaire,sautligne9);
							getline(listevolauxiliaire,sautligne10);
							getline(listevolauxiliaire,sautligne11);
							getline(listevolauxiliaire,sautligne12);
							getline(listevolauxiliaire,sautligne13);

							monFlux <<sautligne1<<endl;
							monFlux <<sautligne2<<endl;
							monFlux <<sautligne3<<endl;
							monFlux <<sautligne4<<endl;
							monFlux <<numerovol2<<endl;
							monFlux <<sautligne5<<endl;
							monFlux <<sautligne6<<endl;
							monFlux <<sautligne7<<endl;
							monFlux <<sautligne8<<endl;
							monFlux <<sautligne9<<endl;
							monFlux <<sautligne10<<endl;
							monFlux <<sautligne11<<endl;
							monFlux <<sautligne12<<endl;
							monFlux <<sautligne13<<endl;
							monFlux <<"-------------------------------------------------------------------------"<<endl;
						
						}
						//Modifions num passeport dans liste vol !
						ofstream MonFlux99("Dossier texte/listevolauxiliaire.txt");
						ifstream listevolauxiliaire1("Dossier texte/listevolauxiliaire.txt");
						ifstream listevoyageur("Dossier texte/listevoyageur.txt");
						string ligne31;

						do
						{					
							string sautligne11,sautligne21,sautligne31,sautligne51,numeroDePasseport1;

							getline(listevoyageur,sautligne11);
							getline(listevoyageur,sautligne21);
							getline(listevoyageur,sautligne31);					
							getline(listevoyageur,numeroDePasseport1);

							if(numeropasseportrecherche!=numeroDePasseport1)
							{
								ofstream MonFlux99("Dossier texte/listevolauxiliaire.txt",ios::app);
					
								MonFlux99<<""<<endl;
								MonFlux99<< sautligne11 <<endl;					
								MonFlux99<< sautligne21 <<endl;
								MonFlux99<< sautligne31 <<endl;
								MonFlux99<< numeroDePasseport1 <<endl;				
							}
							else
							{
								ofstream MonFlux99("Dossier texte/listevolauxiliaire.txt",ios::app);
					
								MonFlux99<<""<<endl;
								MonFlux99<< sautligne11 <<endl;
								MonFlux99<< sautligne21 <<endl;
								MonFlux99<< sautligne31 <<endl;
								MonFlux99<< nouveaunumeropasseport <<endl;
							}

						}while(getline(listevoyageur, ligne2));

						ofstream monFlux99("Dossier texte/listevoyageur.txt");

						while(getline(listevolauxiliaire1,ligne31))//enfin copions le fichier voyageur auxiliaire dans celui liste voyageur en l'évrasant cette fois ci !
						{
							ofstream monFlux99("Dossier texte/listevoyageur.txt",ios::app);
						
							string numeroDePasseport2,sautligne1,sautligne2,sautligne3,sautligne5;			
						
							getline(listevolauxiliaire1,sautligne1);
							getline(listevolauxiliaire1,sautligne2);
							getline(listevolauxiliaire1,sautligne3);
							getline(listevolauxiliaire1, numeroDePasseport2);
												
							monFlux99 <<sautligne1<<endl;
							monFlux99 <<sautligne2<<endl;
							monFlux99 <<sautligne3<<endl;
							monFlux99 <<numeroDePasseport2<<endl;
							monFlux99 <<"-------------------------------------------------------------------------"<<endl;
						}
						system("cls");
						cout<<" "<<endl;
						cout<<"			Votre reservation a bien ete modifier."<<endl;
						cout<<"			";
						Sleep(4000);				
						reservation();//Retour Menu reservation
					}
					else if (choisir==4)
					{
						//Modifier numero vol
						string nouveaunumerovol, ligne2, ligne3;

						cout<<" "<<endl;
						cout<<"	Veuillez entrer le nouveau numero de vol : ";
						cin>>nouveaunumerovol;

						//Modifier sur liste reservation
						ofstream MonFlux("Dossier texte/listevolauxiliaire.txt");
						ifstream listevolauxiliaire("Dossier texte/listevolauxiliaire.txt");
						ifstream listereservation("Dossier texte/listereservation.txt");

						do //lisons le fichier liste reservation
						{
							string sautligne11, sautligne21, sautligne31, sautligne41, numerovol1, sautligne51, sautligne61;
							string sautligne71, sautligne81, sautligne91, sautligne101, sautligne111, sautligne121, confirmation;

							getline(listereservation,sautligne11);
							getline(listereservation,sautligne21);
							getline(listereservation,sautligne31);
							getline(listereservation,sautligne41);
							getline(listereservation, numerovol1);
							getline(listereservation,sautligne51);
							getline(listereservation,sautligne61);
							getline(listereservation,sautligne71);
							getline(listereservation,sautligne81);
							getline(listereservation,sautligne91);
							getline(listereservation,sautligne101);
							getline(listereservation,sautligne111);
							getline(listereservation,sautligne121);
							getline(listereservation,confirmation);

							if(sautligne41!=numeropasseportrecherche && sautligne41!="")// tous les vols que l'on ne veut pas modifier sont copiés dans le fichier listevolauxiliaire
							{
								ofstream MonFlux("Dossier texte/listevolauxiliaire.txt",ios::app);
					
								MonFlux<<""<<endl;
								MonFlux<< sautligne11 <<endl;
								MonFlux<< sautligne21 <<endl;
								MonFlux<< sautligne31 <<endl;
								MonFlux<< sautligne41 <<endl;
								MonFlux<< numerovol1 <<endl;
								MonFlux<< sautligne51 <<endl;
								MonFlux<< sautligne61 <<endl;
								MonFlux<< sautligne71 <<endl;
								MonFlux<< sautligne81 <<endl;
								MonFlux<< sautligne91 <<endl;
								MonFlux<< sautligne101 <<endl;
								MonFlux<< sautligne111 <<endl;
								MonFlux<< sautligne121 <<endl;
								MonFlux<< confirmation <<endl;

							}
							else if(sautligne41==numeropasseportrecherche)//pour le vol que l'on souhaite modifier on copie tous les parametre inchangés dans liste vol auxiliaire en changeant celui que je souhaite mosifier
							{
								ofstream MonFlux("Dossier texte/listevolauxiliaire.txt",ios::app);
					
								MonFlux<<""<<endl;
								MonFlux<< sautligne11 <<endl;
								MonFlux<< sautligne21 <<endl;
								MonFlux<< sautligne31 <<endl;
								MonFlux<< sautligne41 <<endl;
								MonFlux<< nouveaunumerovol <<endl;
								MonFlux<< sautligne51 <<endl;
								MonFlux<< sautligne61 <<endl;
								MonFlux<< sautligne71 <<endl;
								MonFlux<< sautligne81 <<endl;
								MonFlux<< sautligne91 <<endl;
								MonFlux<< sautligne101 <<endl;
								MonFlux<< sautligne111 <<endl;
								MonFlux<< sautligne121 <<endl;
								MonFlux<< confirmation <<endl;

							}
						}while(getline(listereservation,ligne2));

						ofstream monFlux("Dossier texte/listereservation.txt");

						while(getline(listevolauxiliaire, ligne3))//enfin copions le fichier vol auxiliaire dans celui liste vol en l'évrasant cette fois ci !
						{
							ofstream monFlux("Dossier texte/listereservation.txt",ios::app);
						
							string sautligne1, sautligne2, sautligne3, sautligne4, numerovol2, sautligne5, sautligne6;
							string sautligne7, sautligne8, sautligne9, sautligne10, sautligne11, sautligne12, sautligne13;
		
							getline(listevolauxiliaire,sautligne1);
							getline(listevolauxiliaire,sautligne2);
							getline(listevolauxiliaire,sautligne3);
							getline(listevolauxiliaire,sautligne4);
							getline(listevolauxiliaire, numerovol2);
							getline(listevolauxiliaire,sautligne5);
							getline(listevolauxiliaire,sautligne6);
							getline(listevolauxiliaire,sautligne7);
							getline(listevolauxiliaire,sautligne8);
							getline(listevolauxiliaire,sautligne9);
							getline(listevolauxiliaire,sautligne10);
							getline(listevolauxiliaire,sautligne11);
							getline(listevolauxiliaire,sautligne12);
							getline(listevolauxiliaire,sautligne13);

							monFlux <<sautligne1<<endl;
							monFlux <<sautligne2<<endl;
							monFlux <<sautligne3<<endl;
							monFlux <<sautligne4<<endl;
							monFlux <<numerovol2<<endl;
							monFlux <<sautligne5<<endl;
							monFlux <<sautligne6<<endl;
							monFlux <<sautligne7<<endl;
							monFlux <<sautligne8<<endl;
							monFlux <<sautligne9<<endl;
							monFlux <<sautligne10<<endl;
							monFlux <<sautligne11<<endl;
							monFlux <<sautligne12<<endl;
							monFlux <<sautligne13<<endl;
							monFlux <<"-------------------------------------------------------------------------"<<endl;
						
						}
						//Modification num vol dans liste vol !
						ofstream MonFlux99("Dossier texte/listevolauxiliaire.txt");
						ifstream listevolauxiliaire1("Dossier texte/listevolauxiliaire.txt");
						ifstream listevol("Dossier texte/listevol.txt");
						string ligne31;

						do
						{
							string numerovol1, sautligne11, sautligne21, sautligne31;
							string sautligne41, sautligne51, sautligne61, sautligne71, sautligne81;

							getline(listevol, numerovol1);
							getline(listevol,sautligne11);
							getline(listevol,sautligne21);
							getline(listevol,sautligne31);
							getline(listevol,sautligne41);
							getline(listevol,sautligne51);
							getline(listevol,sautligne61);
							getline(listevol,sautligne71);
							getline(listevol,sautligne81);

							if(numerovol!=numerovol1)
							{
								ofstream MonFlux99("Dossier texte/listevolauxiliaire.txt",ios::app);
					
								MonFlux99<<""<<endl;
								MonFlux99<< numerovol1 <<endl;
								MonFlux99<< sautligne11 <<endl;
								MonFlux99<< sautligne21 <<endl;
								MonFlux99<< sautligne31 <<endl;
								MonFlux99<< sautligne41 <<endl;
								MonFlux99<< sautligne51 <<endl;
								MonFlux99<< sautligne61 <<endl;
								MonFlux99<< sautligne71 <<endl;
								MonFlux99<< sautligne81 <<endl;

							}
							else
							{
								ofstream MonFlux99("Dossier texte/listevolauxiliaire.txt",ios::app);
					
								MonFlux99<<""<<endl;
								MonFlux99<< nouveaunumerovol <<endl;
								MonFlux99<< sautligne11 <<endl;
								MonFlux99<< sautligne21 <<endl;
								MonFlux99<< sautligne31 <<endl;
								MonFlux99<< sautligne41 <<endl;
								MonFlux99<< sautligne51 <<endl;
								MonFlux99<< sautligne61 <<endl;
								MonFlux99<< sautligne71 <<endl;
								MonFlux99<< sautligne81 <<endl;
							}

						}while(getline(listevol, ligne2));

						ofstream monFlux99("Dossier texte/listevol.txt");

						while(getline(listevolauxiliaire1, ligne31))
						{
							ofstream monFlux99("Dossier texte/listevol.txt",ios::app);
						
							string numerovol20, sautligne10, sautligne20, sautligne30;
							string sautligne40, sautligne50, sautligne60, sautligne70, sautligne80;
			
							getline(listevolauxiliaire1, numerovol20);
							getline(listevolauxiliaire1,sautligne10);
							getline(listevolauxiliaire1,sautligne20);
							getline(listevolauxiliaire1,sautligne30);
							getline(listevolauxiliaire1,sautligne40);
							getline(listevolauxiliaire1,sautligne50);
							getline(listevolauxiliaire1,sautligne60);
							getline(listevolauxiliaire1,sautligne70);
							getline(listevolauxiliaire1,sautligne80);

							monFlux99 <<numerovol20<<endl;
							monFlux99 <<sautligne10<<endl;
							monFlux99 <<sautligne20<<endl;
							monFlux99 <<sautligne30<<endl;
							monFlux99 <<sautligne40<<endl;
							monFlux99 <<sautligne50<<endl;
							monFlux99 <<sautligne60<<endl;
							monFlux99 <<sautligne70<<endl;
							monFlux99 <<sautligne80<<endl;
							monFlux99 <<"-------------------------------------------------------------------------"<<endl;

						}
						system("cls");
						cout<<" "<<endl;
						cout<<"			Votre reservation a bien ete modifier."<<endl;
						cout<<"			";
						Sleep(4000);		
						reservation();//Retour menu reservation

					}
					else if(choisir==5)
					{
						//Videpart-Videstination
						string nouvellevidepart, nouvelleviarrivee, ligne2, ligne3;

						cout<<" "<<endl;
						cout<<"	Veuillez entrer la nouvelle ville de depart : ";
						cin>>nouvellevidepart;
						cout<<"	Veuillez entrer la nouvelle ville d'arrivee : ";
						cin>>nouvelleviarrivee;

						//Modifier sur liste reservation
						ofstream MonFlux("Dossier texte/listevolauxiliaire.txt");
						ifstream listevolauxiliaire("Dossier texte/listevolauxiliaire.txt");
						ifstream listereservation("Dossier texte/listereservation.txt");

						do //lisons le fichier liste reservation
						{
							string sautligne11, sautligne21, sautligne31, sautligne41, numerovol1, sautligne51, sautligne61;
							string sautligne71, sautligne81, sautligne91, sautligne101, sautligne111, sautligne121, confirmation;

							getline(listereservation,sautligne11);
							getline(listereservation,sautligne21);
							getline(listereservation,sautligne31);
							getline(listereservation,sautligne41);
							getline(listereservation, numerovol1);
							getline(listereservation,sautligne51);
							getline(listereservation,sautligne61);
							getline(listereservation,sautligne71);
							getline(listereservation,sautligne81);
							getline(listereservation,sautligne91);
							getline(listereservation,sautligne101);
							getline(listereservation,sautligne111);
							getline(listereservation,sautligne121);
							getline(listereservation,confirmation);

							if(sautligne41!=numeropasseportrecherche && sautligne41!="")// tous les vols que l'on ne veut pas modifier sont copiés dans le fichier listevolauxiliaire
							{
								ofstream MonFlux("Dossier texte/listevolauxiliaire.txt",ios::app);
					
								MonFlux<<""<<endl;
								MonFlux<< sautligne11 <<endl;
								MonFlux<< sautligne21 <<endl;
								MonFlux<< sautligne31 <<endl;
								MonFlux<< sautligne41 <<endl;
								MonFlux<< numerovol1 <<endl;
								MonFlux<< sautligne51 <<endl;
								MonFlux<< sautligne61 <<endl;
								MonFlux<< sautligne71 <<endl;
								MonFlux<< sautligne81 <<endl;
								MonFlux<< sautligne91 <<endl;
								MonFlux<< sautligne101 <<endl;
								MonFlux<< sautligne111 <<endl;
								MonFlux<< sautligne121 <<endl;
								MonFlux<< confirmation <<endl;

							}
							else if(sautligne41==numeropasseportrecherche)//pour le vol que l'on souhaite modifier on copie tous les parametre inchangés dans liste vol auxiliaire en changeant celui que je souhaite mosifier
							{
								ofstream MonFlux("Dossier texte/listevolauxiliaire.txt",ios::app);
					
								MonFlux<<""<<endl;
								MonFlux<< sautligne11 <<endl;
								MonFlux<< sautligne21 <<endl;
								MonFlux<< sautligne31 <<endl;
								MonFlux<< sautligne41 <<endl;
								MonFlux<< numerovol1 <<endl;
								MonFlux<< nouvellevidepart <<endl;
								MonFlux<< nouvelleviarrivee <<endl;
								MonFlux<< sautligne71 <<endl;
								MonFlux<< sautligne81 <<endl;
								MonFlux<< sautligne91 <<endl;
								MonFlux<< sautligne101 <<endl;
								MonFlux<< sautligne111 <<endl;
								MonFlux<< sautligne121 <<endl;
								MonFlux<< confirmation <<endl;

							}
					
						}while(getline(listereservation,ligne2));

						ofstream monFlux("Dossier texte/listereservation.txt");

						while(getline(listevolauxiliaire, ligne3))//enfin copions le fichier vol auxiliaire dans celui liste vol en l'évrasant cette fois ci !
						{
							ofstream monFlux("Dossier texte/listereservation.txt",ios::app);
						
							string sautligne1, sautligne2, sautligne3, sautligne4, numerovol2, sautligne5;
							string sautligne6, sautligne7, sautligne8, sautligne9, sautligne10, sautligne11, sautligne12, sautligne13;
		
							getline(listevolauxiliaire,sautligne1);
							getline(listevolauxiliaire,sautligne2);
							getline(listevolauxiliaire,sautligne3);
							getline(listevolauxiliaire,sautligne4);
							getline(listevolauxiliaire, numerovol2);
							getline(listevolauxiliaire,sautligne5);
							getline(listevolauxiliaire,sautligne6);
							getline(listevolauxiliaire,sautligne7);
							getline(listevolauxiliaire,sautligne8);
							getline(listevolauxiliaire,sautligne9);
							getline(listevolauxiliaire,sautligne10);
							getline(listevolauxiliaire,sautligne11);
							getline(listevolauxiliaire,sautligne12);
							getline(listevolauxiliaire,sautligne13);

							monFlux <<sautligne1<<endl;
							monFlux <<sautligne2<<endl;
							monFlux <<sautligne3<<endl;
							monFlux <<sautligne4<<endl;
							monFlux <<numerovol2<<endl;
							monFlux <<sautligne5<<endl;
							monFlux <<sautligne6<<endl;
							monFlux <<sautligne7<<endl;
							monFlux <<sautligne8<<endl;
							monFlux <<sautligne9<<endl;
							monFlux <<sautligne10<<endl;
							monFlux <<sautligne11<<endl;
							monFlux <<sautligne12<<endl;
							monFlux <<sautligne13<<endl;
							monFlux <<"-------------------------------------------------------------------------"<<endl;
						
						}
						//Modification videpart et viarrivee dans menu vol et menu trajet,
						ofstream MonFlux99("Dossier texte/listevolauxiliaire.txt");
						ifstream listevolauxiliaire1("Dossier texte/listevolauxiliaire.txt");
						ifstream listevol("Dossier texte/listevol.txt");
						string ligne31;

						do
						{
							string numerovol1, sautligne11, sautligne21, sautligne31;
							string sautligne41, sautligne51, sautligne61, sautligne71, sautligne81;

							getline(listevol, numerovol1);
							getline(listevol,sautligne11);
							getline(listevol,sautligne21);
							getline(listevol,sautligne31);
							getline(listevol,sautligne41);
							getline(listevol,sautligne51);
							getline(listevol,sautligne61);
							getline(listevol,sautligne71);
							getline(listevol,sautligne81);

							if(numerovol!=numerovol1)
							{
								ofstream MonFlux99("Dossier texte/listevolauxiliaire.txt",ios::app);
					
								MonFlux99<<""<<endl;
								MonFlux99<< numerovol1 <<endl;
								MonFlux99<< sautligne11 <<endl;
								MonFlux99<< sautligne21 <<endl;
								MonFlux99<< sautligne31 <<endl;
								MonFlux99<< sautligne41 <<endl;
								MonFlux99<< sautligne51 <<endl;
								MonFlux99<< sautligne61 <<endl;
								MonFlux99<< sautligne71 <<endl;
								MonFlux99<< sautligne81 <<endl;

							}
							else
							{
								ofstream MonFlux99("Dossier texte/listevolauxiliaire.txt",ios::app);
					
								MonFlux99<<""<<endl;
								MonFlux99<< numerovol1 <<endl;
								MonFlux99<< nouvellevidepart <<endl;
								MonFlux99<< nouvelleviarrivee <<endl;
								MonFlux99<< sautligne31 <<endl;
								MonFlux99<< sautligne41 <<endl;
								MonFlux99<< sautligne51 <<endl;
								MonFlux99<< sautligne61 <<endl;
								MonFlux99<< sautligne71 <<endl;
								MonFlux99<< sautligne81 <<endl;
							}

						}while(getline(listevol, ligne2));

						ofstream monFlux99("Dossier texte/listevol.txt");

						while(getline(listevolauxiliaire1, ligne31))
						{
							ofstream monFlux99("Dossier texte/listevol.txt",ios::app);
						
							string numerovol20, sautligne10, sautligne20, sautligne30;
							string sautligne40, sautligne50, sautligne60, sautligne70, sautligne80;
			
							getline(listevolauxiliaire1, numerovol20);
							getline(listevolauxiliaire1,sautligne10);
							getline(listevolauxiliaire1,sautligne20);
							getline(listevolauxiliaire1,sautligne30);
							getline(listevolauxiliaire1,sautligne40);
							getline(listevolauxiliaire1,sautligne50);
							getline(listevolauxiliaire1,sautligne60);
							getline(listevolauxiliaire1,sautligne70);
							getline(listevolauxiliaire1,sautligne80);

							monFlux99 <<numerovol20<<endl;
							monFlux99 <<sautligne10<<endl;
							monFlux99 <<sautligne20<<endl;
							monFlux99 <<sautligne30<<endl;
							monFlux99 <<sautligne40<<endl;
							monFlux99 <<sautligne50<<endl;
							monFlux99 <<sautligne60<<endl;
							monFlux99 <<sautligne70<<endl;
							monFlux99 <<sautligne80<<endl;
							monFlux99 <<"-------------------------------------------------------------------------"<<endl;

						}
						system("cls");
						cout<<" "<<endl;
						cout<<"			Votre reservation a bien ete modifier."<<endl;
						cout<<"			";
						Sleep(4000);		
						reservation();//Retour menu reservation
					}
					else if(choisir==6)
					{
						//date
						string nouveaujour, nouveaumois, nouvelleannee, ligne2, ligne3;

						cout<<" "<<endl;
						cout<<"	Veuillez entrer le jour de depart : ";
						cin>>nouveaujour;
						cout<<"	Veuillez entrer le mois de depart : ";
						cin>>nouveaumois;
						cout<<"	Veuillez entrer l'annee de depart : ";
						cin>>nouvelleannee;

						//Modifier sur liste reservation
						ofstream MonFlux("Dossier texte/listevolauxiliaire.txt");
						ifstream listevolauxiliaire("Dossier texte/listevolauxiliaire.txt");
						ifstream listereservation("Dossier texte/listereservation.txt");

						do //lisons le fichier liste reservation
						{
							string sautligne11, sautligne21, sautligne31, sautligne41, numerovol1, sautligne51, sautligne61;
							string sautligne71, sautligne81, sautligne91, sautligne101, sautligne111, sautligne121, confirmation;

							getline(listereservation,sautligne11);
							getline(listereservation,sautligne21);
							getline(listereservation,sautligne31);
							getline(listereservation,sautligne41);
							getline(listereservation, numerovol1);
							getline(listereservation,sautligne51);
							getline(listereservation,sautligne61);
							getline(listereservation,sautligne71);
							getline(listereservation,sautligne81);
							getline(listereservation,sautligne91);
							getline(listereservation,sautligne101);
							getline(listereservation,sautligne111);
							getline(listereservation,sautligne121);
							getline(listereservation,confirmation);

							if(sautligne41!=numeropasseportrecherche && sautligne41!="")//tous les vols que l'on ne veut pas modifier sont copiés dans le fichier listevolauxiliaire
							{
								ofstream MonFlux("Dossier texte/listevolauxiliaire.txt",ios::app);
					
								MonFlux<<""<<endl;
								MonFlux<< sautligne11 <<endl;
								MonFlux<< sautligne21 <<endl;
								MonFlux<< sautligne31 <<endl;
								MonFlux<< sautligne41 <<endl;
								MonFlux<< numerovol1 <<endl;
								MonFlux<< sautligne51 <<endl;
								MonFlux<< sautligne61 <<endl;
								MonFlux<< sautligne71 <<endl;
								MonFlux<< sautligne81 <<endl;
								MonFlux<< sautligne91 <<endl;
								MonFlux<< sautligne101 <<endl;
								MonFlux<< sautligne111 <<endl;
								MonFlux<< sautligne121 <<endl;
								MonFlux<< confirmation <<endl;

							}
							else if(sautligne41==numeropasseportrecherche)//pour le vol que l'on souhaite modifier on copie tous les parametre inchangés dans liste vol auxiliaire en changeant celui que je souhaite mosifier
							{
								ofstream MonFlux("Dossier texte/listevolauxiliaire.txt",ios::app);
					
								MonFlux<<""<<endl;
								MonFlux<< sautligne11 <<endl;
								MonFlux<< sautligne21 <<endl;
								MonFlux<< sautligne31 <<endl;
								MonFlux<< sautligne41 <<endl;
								MonFlux<< numerovol1 <<endl;
								MonFlux<< sautligne51 <<endl;
								MonFlux<< sautligne61 <<endl;
								MonFlux<< nouveaujour <<endl;
								MonFlux<< nouveaumois <<endl;
								MonFlux<< nouvelleannee <<endl;
								MonFlux<< sautligne101 <<endl;
								MonFlux<< sautligne111 <<endl;
								MonFlux<< sautligne121 <<endl;
								MonFlux<< confirmation <<endl;

							}
					
						}while(getline(listereservation,ligne2));

						ofstream monFlux("Dossier texte/listereservation.txt");

						while(getline(listevolauxiliaire, ligne3))//enfin copions le fichier vol auxiliaire dans celui liste vol en l'évrasant cette fois ci !
						{
							ofstream monFlux("Dossier texte/listereservation.txt",ios::app);
						
							string sautligne1, sautligne2, sautligne3, sautligne4, numerovol2, sautligne5, sautligne6;
							string sautligne7, sautligne8, sautligne9, sautligne10, sautligne11, sautligne12, sautligne13;
		
							getline(listevolauxiliaire,sautligne1);
							getline(listevolauxiliaire,sautligne2);
							getline(listevolauxiliaire,sautligne3);
							getline(listevolauxiliaire,sautligne4);
							getline(listevolauxiliaire, numerovol2);
							getline(listevolauxiliaire,sautligne5);
							getline(listevolauxiliaire,sautligne6);
							getline(listevolauxiliaire,sautligne7);
							getline(listevolauxiliaire,sautligne8);
							getline(listevolauxiliaire,sautligne9);
							getline(listevolauxiliaire,sautligne10);
							getline(listevolauxiliaire,sautligne11);
							getline(listevolauxiliaire,sautligne12);
							getline(listevolauxiliaire,sautligne13);

							monFlux <<sautligne1<<endl;
							monFlux <<sautligne2<<endl;
							monFlux <<sautligne3<<endl;
							monFlux <<sautligne4<<endl;
							monFlux <<numerovol2<<endl;
							monFlux <<sautligne5<<endl;
							monFlux <<sautligne6<<endl;
							monFlux <<sautligne7<<endl;
							monFlux <<sautligne8<<endl;
							monFlux <<sautligne9<<endl;
							monFlux <<sautligne10<<endl;
							monFlux <<sautligne11<<endl;
							monFlux <<sautligne12<<endl;
							monFlux <<sautligne13<<endl;
							monFlux <<"-------------------------------------------------------------------------"<<endl;
						
						}
						//Modifier dans listevol la date.
						ofstream MonFlux99("Dossier texte/listevolauxiliaire.txt");
						ifstream listevolauxiliaire1("Dossier texte/listevolauxiliaire.txt");
						ifstream listevol("Dossier texte/listevol.txt");
						string ligne31;

						do
						{
							string numerovol1, sautligne11, sautligne21, sautligne31;
							string sautligne41, sautligne51, sautligne61, sautligne71, sautligne81;

							getline(listevol, numerovol1);
							getline(listevol,sautligne11);
							getline(listevol,sautligne21);
							getline(listevol,sautligne31);
							getline(listevol,sautligne41);
							getline(listevol,sautligne51);
							getline(listevol,sautligne61);
							getline(listevol,sautligne71);
							getline(listevol,sautligne81);

							if(numerovol!=numerovol1)
							{
								ofstream MonFlux99("Dossier texte/listevolauxiliaire.txt",ios::app);
					
								MonFlux99<<""<<endl;
								MonFlux99<< numerovol1 <<endl;
								MonFlux99<< sautligne11 <<endl;
								MonFlux99<< sautligne21 <<endl;
								MonFlux99<< sautligne31 <<endl;
								MonFlux99<< sautligne41 <<endl;
								MonFlux99<< sautligne51 <<endl;
								MonFlux99<< sautligne61 <<endl;
								MonFlux99<< sautligne71 <<endl;
								MonFlux99<< sautligne81 <<endl;

							}
							else
							{
								ofstream MonFlux99("C:/Users/Asus/Documents/ESTACA/Informatique/listevolauxiliaire.txt",ios::app);
					
								MonFlux99<<""<<endl;
								MonFlux99<< numerovol1 <<endl;
								MonFlux99<< sautligne11 <<endl;
								MonFlux99<< sautligne21 <<endl;
								MonFlux99<< nouveaujour <<endl;
								MonFlux99<< nouveaumois <<endl;
								MonFlux99<< nouvelleannee <<endl;
								MonFlux99<< sautligne61 <<endl;
								MonFlux99<< sautligne71 <<endl;
								MonFlux99<< sautligne81 <<endl;
							}

						}while(getline(listevol, ligne2));

						ofstream monFlux99("Dossier texte/listevol.txt");

						while(getline(listevolauxiliaire1, ligne31))
						{
							ofstream monFlux99("Dossier texte/listevol.txt",ios::app);
						
							string numerovol20, sautligne10, sautligne20, sautligne30;
							string sautligne40, sautligne50, sautligne60, sautligne70, sautligne80;
			
							getline(listevolauxiliaire1, numerovol20);
							getline(listevolauxiliaire1,sautligne10);
							getline(listevolauxiliaire1,sautligne20);
							getline(listevolauxiliaire1,sautligne30);
							getline(listevolauxiliaire1,sautligne40);
							getline(listevolauxiliaire1,sautligne50);
							getline(listevolauxiliaire1,sautligne60);
							getline(listevolauxiliaire1,sautligne70);
							getline(listevolauxiliaire1,sautligne80);

							monFlux99 <<numerovol20<<endl;
							monFlux99 <<sautligne10<<endl;
							monFlux99 <<sautligne20<<endl;
							monFlux99 <<sautligne30<<endl;
							monFlux99 <<sautligne40<<endl;
							monFlux99 <<sautligne50<<endl;
							monFlux99 <<sautligne60<<endl;
							monFlux99 <<sautligne70<<endl;
							monFlux99 <<sautligne80<<endl;
							monFlux99 <<"-------------------------------------------------------------------------"<<endl;

						}
						system("cls");
						cout<<" "<<endl;
						cout<<"			Votre reservation a bien ete modifier."<<endl;
						cout<<"			";
						Sleep(4000);		
						reservation();//Retour menu reservation
					}
					else if(choisir==7)
					{
						//Heure
						string nouvelleheure, nouvelleminute, ligne2, ligne3;

						cout<<" "<<endl;
						cout<<"	Veuillez entrer la nouvelle heure de depart : ";
						cin>>nouvelleheure;
						cout<<"	Veuillez entrer les nouvelles minutes : ";
						cin>>nouvelleminute;

						//Modifier sur liste reservation
						ofstream MonFlux("Dossier texte/listevolauxiliaire.txt");
						ifstream listevolauxiliaire("Dossier texte/listevolauxiliaire.txt");
						ifstream listereservation("Dossier texte/listereservation.txt");

						do //lisons le fichier liste reservation
						{
							string sautligne11, sautligne21, sautligne31, sautligne41, numerovol1, sautligne51;
							string sautligne61, sautligne71, sautligne81, sautligne91, sautligne101, sautligne111, sautligne121, confirmation;

							getline(listereservation,sautligne11);
							getline(listereservation,sautligne21);
							getline(listereservation,sautligne31);
							getline(listereservation,sautligne41);
							getline(listereservation, numerovol1);
							getline(listereservation,sautligne51);
							getline(listereservation,sautligne61);
							getline(listereservation,sautligne71);
							getline(listereservation,sautligne81);
							getline(listereservation,sautligne91);
							getline(listereservation,sautligne101);
							getline(listereservation,sautligne111);
							getline(listereservation,sautligne121);
							getline(listereservation,confirmation);

							if(sautligne41!=numeropasseportrecherche && sautligne41!="")// tous les vols que l'on ne veut pas modifier sont copiés dans le fichier listevolauxiliaire
							{
								ofstream MonFlux("Dossier texte/listevolauxiliaire.txt",ios::app);
					
								MonFlux<<""<<endl;
								MonFlux<< sautligne11 <<endl;
								MonFlux<< sautligne21 <<endl;
								MonFlux<< sautligne31 <<endl;
								MonFlux<< sautligne41 <<endl;
								MonFlux<< numerovol1 <<endl;
								MonFlux<< sautligne51 <<endl;
								MonFlux<< sautligne61 <<endl;
								MonFlux<< sautligne71 <<endl;
								MonFlux<< sautligne81 <<endl;
								MonFlux<< sautligne91 <<endl;
								MonFlux<< sautligne101 <<endl;
								MonFlux<< sautligne111 <<endl;
								MonFlux<< sautligne121 <<endl;
								MonFlux<< confirmation <<endl;

							}
							else if(sautligne41==numeropasseportrecherche)//pour le vol que l'on souhaite modifier on copie tous les parametre inchangés dans liste vol auxiliaire en changeant celui que je souhaite mosifier
							{
								ofstream MonFlux("Dossier texte/listevolauxiliaire.txt",ios::app);
					
								MonFlux<<""<<endl;
								MonFlux<< sautligne11 <<endl;
								MonFlux<< sautligne21 <<endl;
								MonFlux<< sautligne31 <<endl;
								MonFlux<< sautligne41 <<endl;
								MonFlux<< numerovol1 <<endl;
								MonFlux<< sautligne51 <<endl;
								MonFlux<< sautligne61 <<endl;
								MonFlux<< sautligne71 <<endl;
								MonFlux<< sautligne81 <<endl;
								MonFlux<< sautligne91 <<endl;
								MonFlux<< nouvelleheure <<endl;
								MonFlux<< nouvelleminute <<endl;
								MonFlux<< sautligne121 <<endl;
								MonFlux<< confirmation <<endl;

							}
					
						}while(getline(listereservation,ligne2));

						ofstream monFlux("Dossier texte/listereservation.txt");

						while(getline(listevolauxiliaire, ligne3))//enfin copions le fichier vol auxiliaire dans celui liste vol en l'évrasant cette fois ci !
						{
							ofstream monFlux("Dossier texte/listereservation.txt",ios::app);
						
								
							string sautligne1, sautligne2, sautligne3, sautligne4, numerovol2, sautligne5;
							string sautligne6, sautligne7, sautligne8, sautligne9, sautligne10, sautligne11, sautligne12, sautligne13;
		
							getline(listevolauxiliaire,sautligne1);
							getline(listevolauxiliaire,sautligne2);
							getline(listevolauxiliaire,sautligne3);
							getline(listevolauxiliaire,sautligne4);
							getline(listevolauxiliaire, numerovol2);
							getline(listevolauxiliaire,sautligne5);
							getline(listevolauxiliaire,sautligne6);
							getline(listevolauxiliaire,sautligne7);
							getline(listevolauxiliaire,sautligne8);
							getline(listevolauxiliaire,sautligne9);
							getline(listevolauxiliaire,sautligne10);
							getline(listevolauxiliaire,sautligne11);
							getline(listevolauxiliaire,sautligne12);
							getline(listevolauxiliaire,sautligne13);

							monFlux <<sautligne1<<endl;
							monFlux <<sautligne2<<endl;
							monFlux <<sautligne3<<endl;
							monFlux <<sautligne4<<endl;
							monFlux <<numerovol2<<endl;
							monFlux <<sautligne5<<endl;
							monFlux <<sautligne6<<endl;
							monFlux <<sautligne7<<endl;
							monFlux <<sautligne8<<endl;
							monFlux <<sautligne9<<endl;
							monFlux <<sautligne10<<endl;
							monFlux <<sautligne11<<endl;
							monFlux <<sautligne12<<endl;
							monFlux <<sautligne13<<endl;
							monFlux <<"-------------------------------------------------------------------------"<<endl;
						
						}
						//Modifions dans menu vol la date
						ofstream MonFlux99("Dossier texte/listevolauxiliaire.txt");
						ifstream listevolauxiliaire1("Dossier texte/listevolauxiliaire.txt");
						ifstream listevol("Dossier texte/listevol.txt");
						string ligne31;

						do
						{
							string numerovol1, sautligne11, sautligne21, sautligne31;
							string sautligne41, sautligne51, sautligne61, sautligne71, sautligne81;

							getline(listevol, numerovol1);
							getline(listevol,sautligne11);
							getline(listevol,sautligne21);
							getline(listevol,sautligne31);
							getline(listevol,sautligne41);
							getline(listevol,sautligne51);
							getline(listevol,sautligne61);
							getline(listevol,sautligne71);
							getline(listevol,sautligne81);

							if(numerovol!=numerovol1)
							{
								ofstream MonFlux99("Dossier texte/listevolauxiliaire.txt",ios::app);
					
								MonFlux99<<""<<endl;
								MonFlux99<< numerovol1 <<endl;
								MonFlux99<< sautligne11 <<endl;
								MonFlux99<< sautligne21 <<endl;
								MonFlux99<< sautligne31 <<endl;
								MonFlux99<< sautligne41 <<endl;
								MonFlux99<< sautligne51 <<endl;
								MonFlux99<< sautligne61 <<endl;
								MonFlux99<< sautligne71 <<endl;
								MonFlux99<< sautligne81 <<endl;

							}
							else
							{
								ofstream MonFlux99("Dossier texte/listevolauxiliaire.txt",ios::app);
					
								MonFlux99<<""<<endl;
								MonFlux99<< numerovol1 <<endl;
								MonFlux99<< sautligne11 <<endl;
								MonFlux99<< sautligne21 <<endl;
								MonFlux99<< sautligne31 <<endl;
								MonFlux99<< sautligne41 <<endl;
								MonFlux99<< sautligne51 <<endl;
								MonFlux99<< nouvelleheure <<endl;
								MonFlux99<< nouvelleminute <<endl;
								MonFlux99<< sautligne81 <<endl;
							}

						}while(getline(listevol, ligne2));

						ofstream monFlux99("Dossier texte/listevol.txt");

						while(getline(listevolauxiliaire1, ligne31))
						{
							ofstream monFlux99("Dossier texte/listevol.txt",ios::app);
						
							string numerovol20, sautligne10, sautligne20, sautligne30;
							string sautligne40, sautligne50, sautligne60, sautligne70, sautligne80;
			
							getline(listevolauxiliaire1, numerovol20);
							getline(listevolauxiliaire1,sautligne10);
							getline(listevolauxiliaire1,sautligne20);
							getline(listevolauxiliaire1,sautligne30);
							getline(listevolauxiliaire1,sautligne40);
							getline(listevolauxiliaire1,sautligne50);
							getline(listevolauxiliaire1,sautligne60);
							getline(listevolauxiliaire1,sautligne70);
							getline(listevolauxiliaire1,sautligne80);

							monFlux99 <<numerovol20<<endl;
							monFlux99 <<sautligne10<<endl;
							monFlux99 <<sautligne20<<endl;
							monFlux99 <<sautligne30<<endl;
							monFlux99 <<sautligne40<<endl;
							monFlux99 <<sautligne50<<endl;
							monFlux99 <<sautligne60<<endl;
							monFlux99 <<sautligne70<<endl;
							monFlux99 <<sautligne80<<endl;
							monFlux99 <<"-------------------------------------------------------------------------"<<endl;

						}
						system("cls");
						cout<<" "<<endl;
						cout<<"			Votre reservation a bien ete modifier."<<endl;
						cout<<"			";
						Sleep(4000);		
						reservation();//Retour menu reservation
					}
					else if(choisir==8)
					{
						//Prix

						string nouveauprix;
						string ligne2;
						string ligne3;

						cout<<"	Veuillez entrer le nouveau prix du vol : ";
						cin>>nouveauprix;

						//Modifier sur liste reservation
						ofstream MonFlux("Dossier texte/listevolauxiliaire.txt");
						ifstream listevolauxiliaire("Dossier texte/listevolauxiliaire.txt");
						ifstream listereservation("Dossier texte/listereservation.txt");

						do //lisons le fichier liste reservation
						{
								
							string sautligne11, sautligne21, sautligne31, sautligne41, numerovol1, sautligne51, sautligne61;
							string sautligne71, sautligne81, sautligne91, sautligne101, sautligne111, sautligne121, confirmation;

							getline(listereservation,sautligne11);
							getline(listereservation,sautligne21);
							getline(listereservation,sautligne31);
							getline(listereservation,sautligne41);
							getline(listereservation, numerovol1);
							getline(listereservation,sautligne51);
							getline(listereservation,sautligne61);
							getline(listereservation,sautligne71);
							getline(listereservation,sautligne81);
							getline(listereservation,sautligne91);
							getline(listereservation,sautligne101);
							getline(listereservation,sautligne111);
							getline(listereservation,sautligne121);
							getline(listereservation,confirmation);

						if(sautligne41!=numeropasseportrecherche && sautligne41!="")// tous les vols que l'on ne veut pas modifier sont copiés dans le fichier listevolauxiliaire
						{
							ofstream MonFlux("Dossier texte/listevolauxiliaire.txt",ios::app);
					
							MonFlux<<""<<endl;
							MonFlux<< sautligne11 <<endl;
							MonFlux<< sautligne21 <<endl;
							MonFlux<< sautligne31 <<endl;
							MonFlux<< sautligne41 <<endl;
							MonFlux<< numerovol1 <<endl;
							MonFlux<< sautligne51 <<endl;
							MonFlux<< sautligne61 <<endl;
							MonFlux<< sautligne71 <<endl;
							MonFlux<< sautligne81 <<endl;
							MonFlux<< sautligne91 <<endl;
							MonFlux<< sautligne101 <<endl;
							MonFlux<< sautligne111 <<endl;
							MonFlux<< sautligne121 <<endl;
							MonFlux<< confirmation <<endl;

						}
						else if(sautligne41==numeropasseportrecherche)//pour le vol que l'on souhaite modifier on copie tous les parametre inchangés dans liste vol auxiliaire en changeant celui que je souhaite mosifier
						{
							ofstream MonFlux("Dossier texte/listevolauxiliaire.txt",ios::app);
					
							MonFlux<<""<<endl;
							MonFlux<< sautligne11 <<endl;
							MonFlux<< sautligne21 <<endl;
							MonFlux<< sautligne31 <<endl;
							MonFlux<< sautligne41 <<endl;
							MonFlux<< numerovol1 <<endl;
							MonFlux<< sautligne51 <<endl;
							MonFlux<< sautligne61 <<endl;
							MonFlux<< sautligne71 <<endl;
							MonFlux<< sautligne81 <<endl;
							MonFlux<< sautligne91 <<endl;
							MonFlux<< sautligne101 <<endl;
							MonFlux<< sautligne111 <<endl;
							MonFlux<< nouveauprix <<endl;
							MonFlux<< confirmation <<endl;

						}
					
					}while(getline(listereservation,ligne2));

					ofstream monFlux("Dossier texte/listereservation.txt");

					while(getline(listevolauxiliaire, ligne3))//enfin copions le fichier vol auxiliaire dans celui liste vol en l'évrasant cette fois ci !
					{
						ofstream monFlux("Dossier texte/listereservation.txt",ios::app);
						
						string sautligne1, sautligne2, sautligne3, sautligne4, numerovol2, sautligne5, sautligne6;
						string sautligne7, sautligne8, sautligne9, sautligne10, sautligne11, sautligne12, sautligne13;
		
						getline(listevolauxiliaire,sautligne1);
						getline(listevolauxiliaire,sautligne2);
						getline(listevolauxiliaire,sautligne3);
						getline(listevolauxiliaire,sautligne4);
						getline(listevolauxiliaire, numerovol2);
						getline(listevolauxiliaire,sautligne5);
						getline(listevolauxiliaire,sautligne6);
						getline(listevolauxiliaire,sautligne7);
						getline(listevolauxiliaire,sautligne8);
						getline(listevolauxiliaire,sautligne9);
						getline(listevolauxiliaire,sautligne10);
						getline(listevolauxiliaire,sautligne11);
						getline(listevolauxiliaire,sautligne12);
						getline(listevolauxiliaire,sautligne13);

						monFlux <<sautligne1<<endl;
						monFlux <<sautligne2<<endl;
						monFlux <<sautligne3<<endl;
						monFlux <<sautligne4<<endl;
						monFlux <<numerovol2<<endl;
						monFlux <<sautligne5<<endl;
						monFlux <<sautligne6<<endl;
						monFlux <<sautligne7<<endl;
						monFlux <<sautligne8<<endl;
						monFlux <<sautligne9<<endl;
						monFlux <<sautligne10<<endl;
						monFlux <<sautligne11<<endl;
						monFlux <<sautligne12<<endl;
						monFlux <<sautligne13<<endl;
						monFlux <<"-------------------------------------------------------------------------"<<endl;
						
					}
					//Modifier prix dans liste vol
	
					ofstream MonFlux99("Dossier texte/listevolauxiliaire.txt");
					ifstream listevolauxiliaire1("Dossier texte/listevolauxiliaire.txt");
					ifstream listevol("Dossier texte/listevol.txt");
					string ligne31;

						do
						{
							string numerovol1, sautligne11, sautligne21, sautligne31;
							string sautligne41, sautligne51, sautligne61, sautligne71, sautligne81;

							getline(listevol, numerovol1);
							getline(listevol,sautligne11);
							getline(listevol,sautligne21);
							getline(listevol,sautligne31);
							getline(listevol,sautligne41);
							getline(listevol,sautligne51);
							getline(listevol,sautligne61);
							getline(listevol,sautligne71);
							getline(listevol,sautligne81);

							if(numerovol!=numerovol1)
							{
								ofstream MonFlux99("Dossier texte/listevolauxiliaire.txt",ios::app);
					
								MonFlux99<<""<<endl;
								MonFlux99<< numerovol1 <<endl;
								MonFlux99<< sautligne11 <<endl;
								MonFlux99<< sautligne21 <<endl;
								MonFlux99<< sautligne31 <<endl;
								MonFlux99<< sautligne41 <<endl;
								MonFlux99<< sautligne51 <<endl;
								MonFlux99<< sautligne61 <<endl;
								MonFlux99<< sautligne71 <<endl;
								MonFlux99<< sautligne81 <<endl;

							}
							else
							{
								ofstream MonFlux99("Dossier texte/listevolauxiliaire.txt",ios::app);
					
								MonFlux99<<""<<endl;
								MonFlux99<< numerovol1 <<endl;
								MonFlux99<< sautligne11 <<endl;
								MonFlux99<< sautligne21 <<endl;
								MonFlux99<< sautligne31 <<endl;
								MonFlux99<< sautligne41 <<endl;
								MonFlux99<< sautligne51 <<endl;
								MonFlux99<< sautligne61 <<endl;
								MonFlux99<< sautligne71 <<endl;
								MonFlux99<< nouveauprix <<endl;
							}

						}while(getline(listevol, ligne2));

						ofstream monFlux99("Dossier texte/listevol.txt");

						while(getline(listevolauxiliaire1, ligne31))
						{
							ofstream monFlux99("Dossier texte/listevol.txt",ios::app);
						
							string numerovol20, sautligne10, sautligne20, sautligne30;
							string sautligne40, sautligne50, sautligne60, sautligne70, sautligne80;
			
							getline(listevolauxiliaire1, numerovol20);
							getline(listevolauxiliaire1,sautligne10);
							getline(listevolauxiliaire1,sautligne20);
							getline(listevolauxiliaire1,sautligne30);
							getline(listevolauxiliaire1,sautligne40);
							getline(listevolauxiliaire1,sautligne50);
							getline(listevolauxiliaire1,sautligne60);
							getline(listevolauxiliaire1,sautligne70);
							getline(listevolauxiliaire1,sautligne80);

							monFlux99 <<numerovol20<<endl;
							monFlux99 <<sautligne10<<endl;
							monFlux99 <<sautligne20<<endl;
							monFlux99 <<sautligne30<<endl;
							monFlux99 <<sautligne40<<endl;
							monFlux99 <<sautligne50<<endl;
							monFlux99 <<sautligne60<<endl;
							monFlux99 <<sautligne70<<endl;
							monFlux99 <<sautligne80<<endl;
							monFlux99 <<"-------------------------------------------------------------------------"<<endl;

						}
						system("cls");
						cout<<" "<<endl;
						cout<<"			Votre reservation a bien ete modifier."<<endl;
						cout<<"			";
						Sleep(4000);		
						reservation();//Retour menu reservation
					}
					else if(choisir==9)
					{
						//Confirmation
						system("cls");
				
						string nouvelleconfirmation, ligne2, ligne3;
						//lecture du fichier liste volauxiliaire jusqu'au bout et reservation jusqu'au bout
				
						cout<<"	Veuillez entrer l'état de la confirmation (oui/non) : ";
						cin>>nouvelleconfirmation;

						ofstream MonFlux("Dossier texte/listevolauxiliaire.txt");
						ifstream listevolauxiliaire("Dossier texte/listevolauxiliaire.txt");
						ifstream listereservation("Dossier texte/listereservation.txt");

						do //lisons le fichier liste reservation
						{
							string sautligne11, sautligne21, sautligne31, sautligne41, numerovol1, sautligne51, sautligne61;
							string sautligne71, sautligne81, sautligne91, sautligne101, sautligne111, sautligne121, confirmation;

							getline(listereservation,sautligne11);
							getline(listereservation,sautligne21);
							getline(listereservation,sautligne31);
							getline(listereservation,sautligne41);
							getline(listereservation, numerovol1);
							getline(listereservation,sautligne51);
							getline(listereservation,sautligne61);
							getline(listereservation,sautligne71);
							getline(listereservation,sautligne81);
							getline(listereservation,sautligne91);
							getline(listereservation,sautligne101);
							getline(listereservation,sautligne111);
							getline(listereservation,sautligne121);
							getline(listereservation,confirmation);

							if(sautligne41!=numeropasseportrecherche && sautligne41!="")// tous les vols que l'on ne veut pas modifier sont copiés dans le fichier listevolauxiliaire
							{
								ofstream MonFlux("Dossier texte/listevolauxiliaire.txt",ios::app);
					
								MonFlux<<""<<endl;
								MonFlux<< sautligne11 <<endl;
								MonFlux<< sautligne21 <<endl;
								MonFlux<< sautligne31 <<endl;
								MonFlux<< sautligne41 <<endl;
								MonFlux<< numerovol1 <<endl;
								MonFlux<< sautligne51 <<endl;
								MonFlux<< sautligne61 <<endl;
								MonFlux<< sautligne71 <<endl;
								MonFlux<< sautligne81 <<endl;
								MonFlux<< sautligne91 <<endl;
								MonFlux<< sautligne101 <<endl;
								MonFlux<< sautligne111 <<endl;
								MonFlux<< sautligne121 <<endl;
								MonFlux<< confirmation <<endl;

							}
							else if(sautligne41==numeropasseportrecherche)//pour le vol que l'on souhaite modifier on copie tous les parametre inchangés dans liste vol auxiliaire en changeant celui que je souhaite mosifier
							{
								ofstream MonFlux("Dossier texte/listevolauxiliaire.txt",ios::app);
					
								MonFlux<<""<<endl;
								MonFlux<< sautligne11 <<endl;
								MonFlux<< sautligne21 <<endl;
								MonFlux<< sautligne31 <<endl;
								MonFlux<< sautligne41 <<endl;
								MonFlux<< numerovol1 <<endl;
								MonFlux<< sautligne51 <<endl;
								MonFlux<< sautligne61 <<endl;
								MonFlux<< sautligne71 <<endl;
								MonFlux<< sautligne81 <<endl;
								MonFlux<< sautligne91 <<endl;
								MonFlux<< sautligne101 <<endl;
								MonFlux<< sautligne111 <<endl;
								MonFlux<< sautligne121 <<endl;
								MonFlux<< nouvelleconfirmation <<endl;

							}
						
						}while(getline(listereservation,ligne2));

						ofstream monFlux("Dossier texte/listereservation.txt");

						while(getline(listevolauxiliaire, ligne3))//enfin copions le fichier vol auxiliaire dans celui liste vol en l'évrasant cette fois ci !
						{
							ofstream monFlux("Dossier texte/listereservation.txt",ios::app);
						
							string sautligne1, sautligne2, sautligne3, sautligne4, numerovol2, sautligne5;
							string sautligne6, sautligne7, sautligne8, sautligne9, sautligne10, sautligne11, sautligne12, sautligne13;
		
							getline(listevolauxiliaire,sautligne1);
							getline(listevolauxiliaire,sautligne2);
							getline(listevolauxiliaire,sautligne3);
							getline(listevolauxiliaire,sautligne4);
							getline(listevolauxiliaire, numerovol2);
							getline(listevolauxiliaire,sautligne5);
							getline(listevolauxiliaire,sautligne6);
							getline(listevolauxiliaire,sautligne7);
							getline(listevolauxiliaire,sautligne8);
							getline(listevolauxiliaire,sautligne9);
							getline(listevolauxiliaire,sautligne10);
							getline(listevolauxiliaire,sautligne11);
							getline(listevolauxiliaire,sautligne12);
							getline(listevolauxiliaire,sautligne13);

							monFlux <<sautligne1<<endl;
							monFlux <<sautligne2<<endl;
							monFlux <<sautligne3<<endl;
							monFlux <<sautligne4<<endl;
							monFlux <<numerovol2<<endl;
							monFlux <<sautligne5<<endl;
							monFlux <<sautligne6<<endl;
							monFlux <<sautligne7<<endl;
							monFlux <<sautligne8<<endl;
							monFlux <<sautligne9<<endl;
							monFlux <<sautligne10<<endl;
							monFlux <<sautligne11<<endl;
							monFlux <<sautligne12<<endl;
							monFlux <<sautligne13<<endl;
							monFlux <<"-------------------------------------------------------------------------"<<endl;
						
						}
						system("cls");
						cout<<" "<<endl;
						cout<<"			Votre reservation a bien ete modifier."<<endl;
						cout<<"			";
						Sleep(4000);
						reservation();//Retour menu reservation
					}
					else if(choisir==0)
					{
						reservation();//Retour Menu reservation
					}
				}
				else if(choix==2)
				{
					reservation();//retour menu reservation
				}
			}
		}while(getline(listereservation, ligne));

		if(compteur==0)
		{
			cout<<"	Aucune reservation ne correspond a cette recherche"<<endl;
			Sleep(5000);
			reservation();//retour menu reservation
		}
	}
	else
	{
		cout<<" "<<endl;
		cout<<"		ERREUR : Impossible d'ouvrir le fichier de lecture." << endl;
		system("pause");
		reservation();//Retour menu reservation
	}
return(0);
}