#include<iostream>
#include<windows.h>
#include<string>
#include<fstream>
#include"Modifier Vols.h"
#include"Vols.1.h"

using namespace std;

int modifiervols()
{
	string choix;
	cout<<" "<<endl;
	cout<<"		Veuillez selectionner le numero de vol  : ";
	cin>>choix;
	cout<<" "<<endl;
	
	ifstream listevol("Dossier texte/listevol.txt");

	if(listevol)
	{
		string ligne;
		do//do de la boucle recherche du vol que l'on souhaite modifier
		{
		string numerovol, videpart, viarrivee, jour, mois, annee, heure, minute, prix;

		getline(listevol, numerovol);
		getline(listevol, videpart);
		getline(listevol, viarrivee);
		getline(listevol, jour); 
		getline(listevol, mois);
		getline(listevol, annee);
		getline(listevol, heure);
		getline(listevol, minute);
		getline(listevol, prix);
			//lecture du fichier listevol
		if(choix==numerovol)//Si on trouve le vol que l'on souhaite modifier
			{
		int a;
		cout<<" "<<endl;
		cout<<"		Numero de vol : "<< numerovol << endl;
		cout<<"		Ville de depart : "<<videpart<<endl;
		cout<<"		Ville d'arrivee : "<<viarrivee<<endl;
		cout<<"		Le "<< jour << "/"<<mois<<"/"<<annee<<endl;
		cout<<"		Heure de depart : "<<heure<<"h"<<minute<<"min"<<endl;
		cout<<"		Au prix de "<<prix<<"E"<<endl;
		cout<<"-------------------------------------------------------------------------"<<endl;
		cout<<" "<<endl;
		cout<<"	************ Ce vol est-il a modifier ? *************"<<endl;
		cout<<"	*                                                   *"<<endl;
		cout<<"	*                   1 : Oui                         *"<<endl;
		cout<<"	*                   2 : Non                         *"<<endl;
		cout<<"	*                                                   *"<<endl;
		cout<<"	*****************************************************"<<endl;
		cout<<" "<<endl;
		cout<<" "<<endl;
		cout<<"	     Votre choix : ";
		cin>>a;

			if(a==1)//Oui c'est ce vol que je souhaite modifier !
			{
				int b;

				system("cls");
				cout<<"	*********** Que souhaitez vous modifier ? ***********"<<endl;
				cout<<"	*                                                   *"<<endl;
				cout<<"	*            1 : Numero de vol                      *"<<endl;
				cout<<"	*            2 : Ville de depart                    *"<<endl;
				cout<<"	*            3 : Ville d'arrivee                    *"<<endl;
				cout<<"	*            4 : La date de depart                  *"<<endl;
				cout<<"	*            5 : L'heure de depart                  *"<<endl;
				cout<<"	*            6 : Le prix du vol                     *"<<endl;
				cout<<"	*                                                   *"<<endl;
				cout<<"	************** 0 : Retour au Menu Vols **************"<<endl;
				cout<<" "<<endl;
				cout<<" "<<endl;
				cout<<"	     Votre choix : ";
				cin>>b;

				if(b==1)//modifions le numero de vol
				{
				
				system("cls");
				
				string nouveaunumerovol, ligne2, ligne3;//lecture du fichier liste volauxiliaire jusqu'au bout
				
				cout<<" "<<endl;
				cout<<"	Veuillez entrer le nouveau numero de vol : ";
				cin>>nouveaunumerovol;

				ofstream MonFlux("Dossier texte/listevolauxiliaire.txt");
				ifstream listevolauxiliaire("Dossier texte/listevolauxiliaire.txt");
				ifstream listevol("Dossier texte/listevol.txt");

					do //lisons le fichier liste vol
					{
					string numerovol1, sautligne11, sautligne21, sautligne31, sautligne41, sautligne51, sautligne61, sautligne71, sautligne81;

					getline(listevol, numerovol1);
					getline(listevol,sautligne11);
					getline(listevol,sautligne21);
					getline(listevol,sautligne31);
					getline(listevol,sautligne41);
					getline(listevol,sautligne51);
					getline(listevol,sautligne61);
					getline(listevol,sautligne71);
					getline(listevol,sautligne81);
					
					if(numerovol!=numerovol1)// tous les vol que l'on ne veut pas modifier sont copiés dans le fichier listevolauxiliaire
					{
					ofstream MonFlux("Dossier texte/listevolauxiliaire.txt",ios::app);
					
					MonFlux<<""<<endl;
					MonFlux<< numerovol1 <<endl;
					MonFlux<< sautligne11 <<endl;
					MonFlux<< sautligne21 <<endl;
					MonFlux<< sautligne31 <<endl;
					MonFlux<< sautligne41 <<endl;
					MonFlux<< sautligne51 <<endl;
					MonFlux<< sautligne61 <<endl;
					MonFlux<< sautligne71 <<endl;
					MonFlux<< sautligne81 <<endl;

					}
					else//pour le vol que l'on souhaite modifier on copie tous les parametres inchangés dans liste vol auxiliaire en changeant celui que je souhaite modifier
					{
					ofstream MonFlux("Dossier texte/listevolauxiliaire.txt",ios::app);
					
					MonFlux<<""<<endl;
					MonFlux<< nouveaunumerovol <<endl;
					MonFlux<< sautligne11 <<endl;
					MonFlux<< sautligne21 <<endl;
					MonFlux<< sautligne31 <<endl;
					MonFlux<< sautligne41 <<endl;
					MonFlux<< sautligne51 <<endl;
					MonFlux<< sautligne61 <<endl;
					MonFlux<< sautligne71 <<endl;
					MonFlux<< sautligne81 <<endl;
					}
					
					}while(getline(listevol,ligne2));

					ofstream monFlux("Dossier texte/listevol.txt");

					while(getline(listevolauxiliaire, ligne3))//enfin copions le fichier vol auxiliaire dans celui liste vol en l'évrasant cette fois ci !
					{
						ofstream monFlux("Dossier texte/listevol.txt",ios::app);
						
						string numerovol2, sautligne1, sautligne2, sautligne3, sautligne4, sautligne5, sautligne6, sautligne7, sautligne8;
			
						getline(listevolauxiliaire, numerovol2);
						getline(listevolauxiliaire,sautligne1);
						getline(listevolauxiliaire,sautligne2);
						getline(listevolauxiliaire,sautligne3);
						getline(listevolauxiliaire,sautligne4);
						getline(listevolauxiliaire,sautligne5);
						getline(listevolauxiliaire,sautligne6);
						getline(listevolauxiliaire,sautligne7);
						getline(listevolauxiliaire,sautligne8);

						monFlux <<numerovol2<<endl;
						monFlux <<sautligne1<<endl;
						monFlux <<sautligne2<<endl;
						monFlux <<sautligne3<<endl;
						monFlux <<sautligne4<<endl;
						monFlux <<sautligne5<<endl;
						monFlux <<sautligne6<<endl;
						monFlux <<sautligne7<<endl;
						monFlux <<sautligne8<<endl;
						monFlux <<"-------------------------------------------------------------------------"<<endl;
						
					}
				}
				else if(b==2)//changeons la ville de depart
				{
					
				system("cls");//meme principe que ci dessus
				
				string nouvellevidepart;
				string ligne2;
				string ligne3;
				
				cout<<" "<<endl;
				cout<<"	Veuillez entrer la nouvelle ville de depart : ";
				cin>>nouvellevidepart;

				ofstream MonFlux("Dossier texte/listevolauxiliaire.txt");
				ifstream listevolauxiliaire("Dossier texte/listevolauxiliaire.txt");
				ifstream listevol("Dossier texte/listevol.txt");

					do
					{
					string numerovol1, sautligne11, sautligne21, sautligne31, sautligne41, sautligne51, sautligne61, sautligne71, sautligne81;

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
					ofstream MonFlux("Dossier texte/listevolauxiliaire.txt",ios::app);
					
					MonFlux<<""<<endl;
					MonFlux<< numerovol1 <<endl;
					MonFlux<< sautligne11 <<endl;
					MonFlux<< sautligne21 <<endl;
					MonFlux<< sautligne31 <<endl;
					MonFlux<< sautligne41 <<endl;
					MonFlux<< sautligne51 <<endl;
					MonFlux<< sautligne61 <<endl;
					MonFlux<< sautligne71 <<endl;
					MonFlux<< sautligne81 <<endl;

					}
					else
					{
					ofstream MonFlux("Dossier texte/listevolauxiliaire.txt",ios::app);
					
					MonFlux<<""<<endl;
					MonFlux<< numerovol1 <<endl;
					MonFlux<< nouvellevidepart <<endl;
					MonFlux<< sautligne21 <<endl;
					MonFlux<< sautligne31 <<endl;
					MonFlux<< sautligne41 <<endl;
					MonFlux<< sautligne51 <<endl;
					MonFlux<< sautligne61 <<endl;
					MonFlux<< sautligne71 <<endl;
					MonFlux<< sautligne81 <<endl;
					}

					}while(getline(listevol, ligne2));

					ofstream monFlux("Dossier texte/listevol.txt");

					while(getline(listevolauxiliaire, ligne3))
					{
						ofstream monFlux("Dossier texte/listevol.txt",ios::app);
						
						string numerovol2, sautligne1, sautligne2, sautligne3, sautligne4, sautligne5, sautligne6, sautligne7, sautligne8;
			
						getline(listevolauxiliaire, numerovol2);
						getline(listevolauxiliaire,sautligne1);
						getline(listevolauxiliaire,sautligne2);
						getline(listevolauxiliaire,sautligne3);
						getline(listevolauxiliaire,sautligne4);
						getline(listevolauxiliaire,sautligne5);
						getline(listevolauxiliaire,sautligne6);
						getline(listevolauxiliaire,sautligne7);
						getline(listevolauxiliaire,sautligne8);

						monFlux <<numerovol2<<endl;
						monFlux <<sautligne1<<endl;
						monFlux <<sautligne2<<endl;
						monFlux <<sautligne3<<endl;
						monFlux <<sautligne4<<endl;
						monFlux <<sautligne5<<endl;
						monFlux <<sautligne6<<endl;
						monFlux <<sautligne7<<endl;
						monFlux <<sautligne8<<endl;
						monFlux <<"-------------------------------------------------------------------------"<<endl;
						
					}
				}
				else if(b==3)//changeons ville d'arrivée
				{
					system("cls");//meme principe ci dessus
				
				string nouvelleviarrivee, ligne2, ligne3;
				
				cout<<" "<<endl;
				cout<<"	Veuillez entrer la nouvelle ville d'arrivee"<<endl;
				cin>>nouvelleviarrivee;

				ofstream MonFlux("Dossier texte/listevolauxiliaire.txt");
				ifstream listevolauxiliaire("Dossier texte/listevolauxiliaire.txt");
				ifstream listevol("Dossier texte/listevol.txt");

					do
					{
					string numerovol1, sautligne11, sautligne21, sautligne31, sautligne41,sautligne51, sautligne61, sautligne71, sautligne81;

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
					ofstream MonFlux("Dossier texte/listevolauxiliaire.txt",ios::app);
					
					MonFlux<<""<<endl;
					MonFlux<< numerovol1 <<endl;
					MonFlux<< sautligne11 <<endl;
					MonFlux<< sautligne21 <<endl;
					MonFlux<< sautligne31 <<endl;
					MonFlux<< sautligne41 <<endl;
					MonFlux<< sautligne51 <<endl;
					MonFlux<< sautligne61 <<endl;
					MonFlux<< sautligne71 <<endl;
					MonFlux<< sautligne81 <<endl;

					}
					else
					{
					ofstream MonFlux("Dossier texte/listevolauxiliaire.txt",ios::app);
					
					MonFlux<<""<<endl;
					MonFlux<< numerovol1 <<endl;
					MonFlux<< sautligne11 <<endl;
					MonFlux<< nouvelleviarrivee <<endl;
					MonFlux<< sautligne31 <<endl;
					MonFlux<< sautligne41 <<endl;
					MonFlux<< sautligne51 <<endl;
					MonFlux<< sautligne61 <<endl;
					MonFlux<< sautligne71 <<endl;
					MonFlux<< sautligne81 <<endl;
					}

					}while(getline(listevol, ligne2));

					ofstream monFlux("Dossier texte/listevol.txt");

					while(getline(listevolauxiliaire, ligne3))
					{
						ofstream monFlux("Dossier texte/listevol.txt",ios::app);
						
						string numerovol2, sautligne1, sautligne2, sautligne3, sautligne4, sautligne5, sautligne6, sautligne7, sautligne8;
			
						getline(listevolauxiliaire, numerovol2);
						getline(listevolauxiliaire,sautligne1);
						getline(listevolauxiliaire,sautligne2);
						getline(listevolauxiliaire,sautligne3);
						getline(listevolauxiliaire,sautligne4);
						getline(listevolauxiliaire,sautligne5);
						getline(listevolauxiliaire,sautligne6);
						getline(listevolauxiliaire,sautligne7);
						getline(listevolauxiliaire,sautligne8);

						monFlux <<numerovol2<<endl;
						monFlux <<sautligne1<<endl;
						monFlux <<sautligne2<<endl;
						monFlux <<sautligne3<<endl;
						monFlux <<sautligne4<<endl;
						monFlux <<sautligne5<<endl;
						monFlux <<sautligne6<<endl;
						monFlux <<sautligne7<<endl;
						monFlux <<sautligne8<<endl;
						monFlux <<"-------------------------------------------------------------------------"<<endl;
						
					}
				}
				else if(b==4)//changeons la date 
				{	
					int choix3;
					
					do//boucle : si on se trompe d'index
					{
						system("cls");
						//3 possibilités ; changer le jour ; changer le mois ; changer l'année
						cout<<"	********** Que souhaiteriez vous modifier ? *********"<<endl;
						cout<<"	*                                                   *"<<endl;
						cout<<"	*                  1 : Le jour                      *"<<endl;
						cout<<"	*                  2 : Le mois                      *"<<endl;
						cout<<"	*                  3 : L'année                      *"<<endl;
						cout<<"	*                                                   *"<<endl;
						cout<<"	************ 0 : Retour au Menu Vol *****************"<<endl;
						cout<<" "<<endl;
						cout<<" "<<endl;
						cout<<"	     Votre choix : ";
						cin>>choix3;

						if(choix3==1)//changeons le jour
						{
								system("cls");
								//meme principe ci dessus
								string nouveaujour, ligne2, ligne3;
								
								cout<<" "<<endl;
								cout<<"	Veuillez entrer le nouveau jour de depart : ";
								cin>>nouveaujour;

								ofstream MonFlux("Dossier texte/listevolauxiliaire.txt");
								ifstream listevolauxiliaire("Dossier texte/listevolauxiliaire.txt");
								ifstream listevol("Dossier texte/listevol.txt");

									do
									{
									string numerovol1, sautligne11, sautligne21, sautligne31, sautligne41, sautligne51, sautligne61, sautligne71, sautligne81;

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
									ofstream MonFlux("Dossier texte/listevolauxiliaire.txt",ios::app);
					
									MonFlux<<""<<endl;
									MonFlux<< numerovol1 <<endl;
									MonFlux<< sautligne11 <<endl;
									MonFlux<< sautligne21 <<endl;
									MonFlux<< sautligne31 <<endl;
									MonFlux<< sautligne41 <<endl;
									MonFlux<< sautligne51 <<endl;
									MonFlux<< sautligne61 <<endl;
									MonFlux<< sautligne71 <<endl;
									MonFlux<< sautligne81 <<endl;

									}
									else
									{
									ofstream MonFlux("Dossier texte/listevolauxiliaire.txt",ios::app);
					
									MonFlux<<""<<endl;
									MonFlux<< numerovol1 <<endl;
									MonFlux<< sautligne11 <<endl;
									MonFlux<< sautligne21 <<endl;
									MonFlux<< nouveaujour <<endl;
									MonFlux<< sautligne41 <<endl;
									MonFlux<< sautligne51 <<endl;
									MonFlux<< sautligne61 <<endl;
									MonFlux<< sautligne71 <<endl;
									MonFlux<< sautligne81 <<endl;
									}

									}while(getline(listevol, ligne2));

									ofstream monFlux("Dossier texte/listevol.txt");

									while(getline(listevolauxiliaire, ligne3))
									{
										ofstream monFlux("Dossier texte/listevol.txt",ios::app);
						
										string numerovol2, sautligne1, sautligne2, sautligne3, sautligne4, sautligne5, sautligne6, sautligne7, sautligne8;
			
										getline(listevolauxiliaire, numerovol2);
										getline(listevolauxiliaire,sautligne1);
										getline(listevolauxiliaire,sautligne2);
										getline(listevolauxiliaire,sautligne3);
										getline(listevolauxiliaire,sautligne4);
										getline(listevolauxiliaire,sautligne5);
										getline(listevolauxiliaire,sautligne6);
										getline(listevolauxiliaire,sautligne7);
										getline(listevolauxiliaire,sautligne8);

										monFlux <<numerovol2<<endl;
										monFlux <<sautligne1<<endl;
										monFlux <<sautligne2<<endl;
										monFlux <<sautligne3<<endl;
										monFlux <<sautligne4<<endl;
										monFlux <<sautligne5<<endl;
										monFlux <<sautligne6<<endl;
										monFlux <<sautligne7<<endl;
										monFlux <<sautligne8<<endl;
										monFlux <<"-------------------------------------------------------------------------"<<endl;
						
										}
									}
						else if(choix3==2)//changeons le mois
						{
								system("cls");
								//meme principe ci dessus
								string nouveaumois, ligne2, ligne3;
								
								cout<<" "<<endl;
								cout<<"	Veuillez entrer le nouveau mois de depart : ";
								cin>>nouveaumois;

								ofstream MonFlux("Dossier texte/listevolauxiliaire.txt");
								ifstream listevolauxiliaire("Dossier texte/listevolauxiliaire.txt");
								ifstream listevol("Dossier texte/listevol.txt");

									do
									{
									string numerovol1, sautligne11, sautligne21, sautligne31, sautligne41, sautligne51, sautligne61, sautligne71, sautligne81;

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
									ofstream MonFlux("Dossier texte/listevolauxiliaire.txt",ios::app);
					
									MonFlux<<""<<endl;
									MonFlux<< numerovol1 <<endl;
									MonFlux<< sautligne11 <<endl;
									MonFlux<< sautligne21 <<endl;
									MonFlux<< sautligne31 <<endl;
									MonFlux<< sautligne41 <<endl;
									MonFlux<< sautligne51 <<endl;
									MonFlux<< sautligne61 <<endl;
									MonFlux<< sautligne71 <<endl;
									MonFlux<< sautligne81 <<endl;

									}
									else
									{
									ofstream MonFlux("Dossier texte/listevolauxiliaire.txt",ios::app);
					
									MonFlux<<""<<endl;
									MonFlux<< numerovol1 <<endl;
									MonFlux<< sautligne11 <<endl;
									MonFlux<< sautligne21 <<endl;
									MonFlux<< sautligne31 <<endl;
									MonFlux<< nouveaumois <<endl;
									MonFlux<< sautligne51 <<endl;
									MonFlux<< sautligne61 <<endl;
									MonFlux<< sautligne71 <<endl;
									MonFlux<< sautligne81 <<endl;
									}

									}while(getline(listevol, ligne2));

									ofstream monFlux("Dossier texte/listevol.txt");

									while(getline(listevolauxiliaire, ligne3))
									{
										ofstream monFlux("Dossier texte/listevol.txt",ios::app);
						
										string numerovol2, sautligne1, sautligne2, sautligne3, sautligne4, sautligne5, sautligne6, sautligne7, sautligne8;
			
										getline(listevolauxiliaire, numerovol2);
										getline(listevolauxiliaire,sautligne1);
										getline(listevolauxiliaire,sautligne2);
										getline(listevolauxiliaire,sautligne3);
										getline(listevolauxiliaire,sautligne4);
										getline(listevolauxiliaire,sautligne5);
										getline(listevolauxiliaire,sautligne6);
										getline(listevolauxiliaire,sautligne7);
										getline(listevolauxiliaire,sautligne8);

										monFlux <<numerovol2<<endl;
										monFlux <<sautligne1<<endl;
										monFlux <<sautligne2<<endl;
										monFlux <<sautligne3<<endl;
										monFlux <<sautligne4<<endl;
										monFlux <<sautligne5<<endl;
										monFlux <<sautligne6<<endl;
										monFlux <<sautligne7<<endl;
										monFlux <<sautligne8<<endl;
										monFlux <<"-------------------------------------------------------------------------"<<endl;

											}
									}
						else if(choix3==3)//changer l'année
						{
								system("cls");
								//meme principe ci dessus
								string nouvelleannee;
								string ligne2, ligne3;
								
								cout<<" "<<endl;
								cout<<"	Veuillez entrer la nouvelle annee de depart : ";
								cin>>nouvelleannee;

								ofstream MonFlux("Dossier texte/listevolauxiliaire.txt");
								ifstream listevolauxiliaire("Dossier texte/listevolauxiliaire.txt");
								ifstream listevol("Dossier texte/listevol.txt");

									do
									{
									string numerovol1, sautligne11, sautligne21, sautligne31, sautligne41, sautligne51, sautligne61, sautligne71, sautligne81;

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
									ofstream MonFlux("Dossier texte/listevolauxiliaire.txt",ios::app);
					
									MonFlux<<""<<endl;
									MonFlux<< numerovol1 <<endl;
									MonFlux<< sautligne11 <<endl;
									MonFlux<< sautligne21 <<endl;
									MonFlux<< sautligne31 <<endl;
									MonFlux<< sautligne41 <<endl;
									MonFlux<< sautligne51 <<endl;
									MonFlux<< sautligne61 <<endl;
									MonFlux<< sautligne71 <<endl;
									MonFlux<< sautligne81 <<endl;

									}
									else
									{
									ofstream MonFlux("Dossier texte/listevolauxiliaire.txt",ios::app);
					
									MonFlux<<""<<endl;
									MonFlux<< numerovol1 <<endl;
									MonFlux<< sautligne11 <<endl;
									MonFlux<< sautligne21 <<endl;
									MonFlux<< sautligne31 <<endl;
									MonFlux<< sautligne41 <<endl;
									MonFlux<< nouvelleannee <<endl;
									MonFlux<< sautligne61 <<endl;
									MonFlux<< sautligne71 <<endl;
									MonFlux<< sautligne81 <<endl;
									}

									}while(getline(listevol, ligne2));

									ofstream monFlux("Dossier texte/listevol.txt");

									while(getline(listevolauxiliaire, ligne3))
									{
										ofstream monFlux("Dossier texte/listevol.txt",ios::app);
						
										string numerovol2, sautligne1, sautligne2, sautligne3, sautligne4, sautligne5, sautligne6, sautligne7, sautligne8;
			
										getline(listevolauxiliaire, numerovol2);
										getline(listevolauxiliaire,sautligne1);
										getline(listevolauxiliaire,sautligne2);
										getline(listevolauxiliaire,sautligne3);
										getline(listevolauxiliaire,sautligne4);
										getline(listevolauxiliaire,sautligne5);
										getline(listevolauxiliaire,sautligne6);
										getline(listevolauxiliaire,sautligne7);
										getline(listevolauxiliaire,sautligne8);

										monFlux <<numerovol2<<endl;
										monFlux <<sautligne1<<endl;
										monFlux <<sautligne2<<endl;
										monFlux <<sautligne3<<endl;
										monFlux <<sautligne4<<endl;
										monFlux <<sautligne5<<endl;
										monFlux <<sautligne6<<endl;
										monFlux <<sautligne7<<endl;
										monFlux <<sautligne8<<endl;
										monFlux <<"-------------------------------------------------------------------------"<<endl;

											}
									}
						else if(choix3==0)
						{
							vols();//retour menu vol
						}
					
					}while(choix3!=1 && choix3!=2 && choix3!=3 && choix3!=4);//boucle  erreur index
				
				}
				else if(b==5)//changeons l'horaire
				{
					int choix4;

					do//boucle erreur d'index
					{

					system("cls");
					//2 cas : on souhaite modif heure ou modif minute
					cout<<"	********** Que souhaiteriez vous modifier ? *********"<<endl;
					cout<<"	*                                                   *"<<endl;
					cout<<"	*                  1 : L'heure                      *"<<endl;
					cout<<"	*                  2 : Les minutes                  *"<<endl;
					cout<<"	*                                                   *"<<endl;
					cout<<"	************ 0 : Retour au Menu Vol *****************"<<endl;
					cout<<" "<<endl;
					cout<<" "<<endl;
					cout<<"	     Votre choix : ";
					cin>>choix4;

						if(choix4==1)//modifions l'heure
						{
							system("cls");
								//meme principe ci dessus
								string nouvelleheure, ligne2, ligne3;
				
								cout<<" "<<endl;
								cout<<"	Veuillez entrer la nouvelle heure de depart : ";
								cin>>nouvelleheure;

								ofstream MonFlux("Dossier texte/listevolauxiliaire.txt");
								ifstream listevolauxiliaire("Dossier texte/listevolauxiliaire.txt");
								ifstream listevol("Dossier texte/listevol.txt");

									do
									{
									string numerovol1, sautligne11, sautligne21, sautligne31, sautligne41, sautligne51, sautligne61, sautligne71, sautligne81;

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
									ofstream MonFlux("Dossier texte/listevolauxiliaire.txt",ios::app);
					
									MonFlux<<""<<endl;
									MonFlux<< numerovol1 <<endl;
									MonFlux<< sautligne11 <<endl;
									MonFlux<< sautligne21 <<endl;
									MonFlux<< sautligne31 <<endl;
									MonFlux<< sautligne41 <<endl;
									MonFlux<< sautligne51 <<endl;
									MonFlux<< sautligne61 <<endl;
									MonFlux<< sautligne71 <<endl;
									MonFlux<< sautligne81 <<endl;

									}
									else
									{
									ofstream MonFlux("Dossier texte/listevolauxiliaire.txt",ios::app);
					
									MonFlux<<""<<endl;
									MonFlux<< numerovol1 <<endl;
									MonFlux<< sautligne11 <<endl;
									MonFlux<< sautligne21 <<endl;
									MonFlux<< sautligne31 <<endl;
									MonFlux<< sautligne41 <<endl;
									MonFlux<< sautligne51 <<endl;
									MonFlux<< nouvelleheure <<endl;
									MonFlux<< sautligne71 <<endl;
									MonFlux<< sautligne81 <<endl;
									}

									}while(getline(listevol, ligne2));

									ofstream monFlux("Dossier texte/listevol.txt");

									while(getline(listevolauxiliaire, ligne3))
									{
										ofstream monFlux("Dossier texte/listevol.txt",ios::app);
						
										string numerovol2, sautligne1, sautligne2, sautligne3, sautligne4, sautligne5, sautligne6, sautligne7, sautligne8;
			
										getline(listevolauxiliaire, numerovol2);
										getline(listevolauxiliaire,sautligne1);
										getline(listevolauxiliaire,sautligne2);
										getline(listevolauxiliaire,sautligne3);
										getline(listevolauxiliaire,sautligne4);
										getline(listevolauxiliaire,sautligne5);
										getline(listevolauxiliaire,sautligne6);
										getline(listevolauxiliaire,sautligne7);
										getline(listevolauxiliaire,sautligne8);

										monFlux <<numerovol2<<endl;
										monFlux <<sautligne1<<endl;
										monFlux <<sautligne2<<endl;
										monFlux <<sautligne3<<endl;
										monFlux <<sautligne4<<endl;
										monFlux <<sautligne5<<endl;
										monFlux <<sautligne6<<endl;
										monFlux <<sautligne7<<endl;
										monFlux <<sautligne8<<endl;
										monFlux <<"-------------------------------------------------------------------------"<<endl;

											}
									}
						else if(choix4==2)//modifions minutes
						{
								system("cls");
								//meme principe ci dessus
								string nouvelleminute, ligne2, ligne3;
				
								cout<<" "<<endl;
								cout<<"	Veuillez entrer la nouvelle minute de depart : "<<endl;
								cin>>nouvelleminute;

								ofstream MonFlux("Dossier texte/listevolauxiliaire.txt");
								ifstream listevolauxiliaire("Dossier texte/listevolauxiliaire.txt");
								ifstream listevol("Dossier texte/listevol.txt");

									do
									{
									string numerovol1, sautligne11, sautligne21, sautligne31, sautligne41, sautligne51, sautligne61, sautligne71, sautligne81;

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
									ofstream MonFlux("Dossier texte/listevolauxiliaire.txt",ios::app);
					
									MonFlux<<""<<endl;
									MonFlux<< numerovol1 <<endl;
									MonFlux<< sautligne11 <<endl;
									MonFlux<< sautligne21 <<endl;
									MonFlux<< sautligne31 <<endl;
									MonFlux<< sautligne41 <<endl;
									MonFlux<< sautligne51 <<endl;
									MonFlux<< sautligne61 <<endl;
									MonFlux<< sautligne71 <<endl;
									MonFlux<< sautligne81 <<endl;

									}
									else
									{
									ofstream MonFlux("Dossier texte/listevolauxiliaire.txt",ios::app);
					
									MonFlux<<""<<endl;
									MonFlux<< numerovol1 <<endl;
									MonFlux<< sautligne11 <<endl;
									MonFlux<< sautligne21 <<endl;
									MonFlux<< sautligne31 <<endl;
									MonFlux<< sautligne41 <<endl;
									MonFlux<< sautligne51 <<endl;
									MonFlux<< sautligne61 <<endl;
									MonFlux<< nouvelleminute <<endl;
									MonFlux<< sautligne81 <<endl;
									}

									}while(getline(listevol, ligne2));

									ofstream monFlux("Dossier texte/listevol.txt");

									while(getline(listevolauxiliaire, ligne3))
									{
										ofstream monFlux("Dossier texte/listevol.txt",ios::app);
						
										string numerovol2, sautligne1, sautligne2, sautligne3, sautligne4, sautligne5, sautligne6, sautligne7, sautligne8;
			
										getline(listevolauxiliaire, numerovol2);
										getline(listevolauxiliaire,sautligne1);
										getline(listevolauxiliaire,sautligne2);
										getline(listevolauxiliaire,sautligne3);
										getline(listevolauxiliaire,sautligne4);
										getline(listevolauxiliaire,sautligne5);
										getline(listevolauxiliaire,sautligne6);
										getline(listevolauxiliaire,sautligne7);
										getline(listevolauxiliaire,sautligne8);

										monFlux <<numerovol2<<endl;
										monFlux <<sautligne1<<endl;
										monFlux <<sautligne2<<endl;
										monFlux <<sautligne3<<endl;
										monFlux <<sautligne4<<endl;
										monFlux <<sautligne5<<endl;
										monFlux <<sautligne6<<endl;
										monFlux <<sautligne7<<endl;
										monFlux <<sautligne8<<endl;
										monFlux <<"-------------------------------------------------------------------------"<<endl;

											}
									}
						else if(choix4==0)
						{
						vols();//retour menu vol
						}
					}while(choix4!=1 &&choix4!=2 && choix4!=0);
				}
				else if(b==6)//modifions le prix
				{
								system("cls");
				
								string nouveauprix, ligne2, ligne3;
				
								cout<<" "<<endl;
								cout<<"	Veuillez entrer le nouveau prix du vol : ";
								cin>>nouveauprix;

								ofstream MonFlux("Dossier texte/listevolauxiliaire.txt");
								ifstream listevolauxiliaire("Dossier texte/listevolauxiliaire.txt");
								ifstream listevol("Dossier texte/listevol.txt");

									do
									{
									string numerovol1, sautligne11, sautligne21, sautligne31, sautligne41, sautligne51, sautligne61, sautligne71, sautligne81;

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
									ofstream MonFlux("Dossier texte/listevolauxiliaire.txt",ios::app);
					
									MonFlux<<""<<endl;
									MonFlux<< numerovol1 <<endl;
									MonFlux<< sautligne11 <<endl;
									MonFlux<< sautligne21 <<endl;
									MonFlux<< sautligne31 <<endl;
									MonFlux<< sautligne41 <<endl;
									MonFlux<< sautligne51 <<endl;
									MonFlux<< sautligne61 <<endl;
									MonFlux<< sautligne71 <<endl;
									MonFlux<< sautligne81 <<endl;

									}
									else
									{
									ofstream MonFlux("Dossier texte/listevolauxiliaire.txt",ios::app);
					
									MonFlux<<""<<endl;
									MonFlux<< numerovol1 <<endl;
									MonFlux<< sautligne11 <<endl;
									MonFlux<< sautligne21 <<endl;
									MonFlux<< sautligne31 <<endl;
									MonFlux<< sautligne41 <<endl;
									MonFlux<< sautligne51 <<endl;
									MonFlux<< sautligne61 <<endl;
									MonFlux<< sautligne71 <<endl;
									MonFlux<< nouveauprix <<endl;
									}

									}while(getline(listevol, ligne2));

									ofstream monFlux("Dossier texte/listevol.txt");

									while(getline(listevolauxiliaire, ligne3))
									{
										ofstream monFlux("Dossier texte/listevol.txt",ios::app);
						
										string numerovol2, sautligne1, sautligne2, sautligne3, sautligne4, sautligne5, sautligne6, sautligne7, sautligne8;
			
										getline(listevolauxiliaire, numerovol2);
										getline(listevolauxiliaire,sautligne1);
										getline(listevolauxiliaire,sautligne2);
										getline(listevolauxiliaire,sautligne3);
										getline(listevolauxiliaire,sautligne4);
										getline(listevolauxiliaire,sautligne5);
										getline(listevolauxiliaire,sautligne6);
										getline(listevolauxiliaire,sautligne7);
										getline(listevolauxiliaire,sautligne8);

										monFlux <<numerovol2<<endl;
										monFlux <<sautligne1<<endl;
										monFlux <<sautligne2<<endl;
										monFlux <<sautligne3<<endl;
										monFlux <<sautligne4<<endl;
										monFlux <<sautligne5<<endl;
										monFlux <<sautligne6<<endl;
										monFlux <<sautligne7<<endl;
										monFlux <<sautligne8<<endl;
										monFlux <<"-------------------------------------------------------------------------"<<endl;

											}
									}
				else if(b==0)//retour menu vol
				{
					vols();
				}
			}
			else 
			{
				vols();//retour menu vol
			}
			}
	}while(getline(listevol, ligne));
		system("cls");
		cout<<" "<<endl;
		cout<<"			Votre vol a bien ete modifier."<<endl;
		cout<<"			";
		Sleep(4000);
		vols();//Retour Menu Vol
	}
	else
	{
		cout<<" "<<endl;
		cout<<"		ERREUR : Impossible d'ouvrir le fichier de lecture." << endl;
		Sleep(3000);
		vols();//Retour Menu Vol
	}
	return 0;
}