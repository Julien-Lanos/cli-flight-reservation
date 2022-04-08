#include<iostream>
#include<windows.h>
#include<string>
#include<fstream>
#include"Voyageur.1.h"
#include"Modifier Voyageur.h"

using namespace std;

int modifiervoyageur()
{
	string choix;
	cout<<" "<<endl;
	cout<<"	Veuillez selectionner le numero de passeport du voyageur"<<endl;
	cout<<"	que vous souhaiter modifier : ";
	cin>>choix;
	
	ifstream listevoyageur("Dossier texte/listevoyageur.txt");

	if(listevoyageur)
	{
		string ligne;
		do//do de la boucle recherche du vol que l'on souhaite modifier
		{

			string prenom, nom, age, numeroDePasseport;

			getline(listevoyageur, prenom);
			getline(listevoyageur, nom);
			getline(listevoyageur, age);
			getline(listevoyageur, numeroDePasseport); 
		
			//lecture du fichier listevol
			if(choix==numeroDePasseport)//Si on trouve le vol que l'on souhaite modifier
			{
				int a;
				cout<<" "<<endl;
				cout<<"		Prenom du voyageur : "<< prenom << endl;
				cout<<"		Nom du voyageur : "<<nom<<endl;
				cout<<"		Age du voyageur : "<<age<<endl;
				cout<<"		Numero de passeport : "<< numeroDePasseport<<endl;
				cout<<"-------------------------------------------------------------------------"<<endl;
				cout<<" "<<endl;
				cout<<"	********** Ce voyageur est-il a modifier ? **********"<<endl;
				cout<<"	*                                                   *"<<endl;
				cout<<"	*                    1 : Oui                        *"<<endl;
				cout<<"	*                    2 : Non                        *"<<endl;
				cout<<"	*                                                   *"<<endl;
				cout<<"	*****************************************************"<<endl;
				cout<<" "<<endl;
				cout<<" "<<endl;
				cout<<"	     Votre choix : ";
				cin>>a;

				if(a==1)//Oui c'est ce voyayeur que je souhaite modifier !
				{
					int b;
				
					system("cls");
					cout<<" "<<endl;
					cout<<"	*********** Que souhaitez vous modifier ? ***********"<<endl;
					cout<<"	*                                                   *"<<endl;
					cout<<"	*             1 : Le prenom                         *"<<endl;
					cout<<"	*             2 : Le nom                            *"<<endl;
					cout<<"	*             3 : L'age                             *"<<endl;
					cout<<"	*             4 : Le numero de passeport            *"<<endl;
					cout<<"	*                                                   *"<<endl;
					cout<<"	************ 0 : Retour au Menu Voyageur ************"<<endl;
					cout<<" "<<endl;
					cout<<"	     Votre choix : ";
					cin>>b;

					if(b==1)//modifions le prenom du voyageur
					{
				
						system("cls");
				
						string nouveauprenom;
						string ligne2;//lecture du fichier liste voyageur jusqu'au bout
						string ligne3;//lecture du fichier liste voyageur auxiliaire jusqu'au bout
					
						cout<<" "<<endl;
						cout<<"	Veuillez entrer le nouveau prenom du voyageur : ";
						cin>>nouveauprenom;

						ofstream MonFlux("Dossier texte/listevoyageurauxiliaire.txt");
						ifstream listevoyageurauxiliaire("Dossier texte/listevoyageurauxiliaire.txt");
						ifstream listevoyageur("Dossier texte/listevoyageur.txt");
	
						do //lisons le fichier liste vol
						{
							string numeroDePasseport1,sautligne11,sautligne21,sautligne31,sautligne51;

							getline(listevoyageur,sautligne11);
							getline(listevoyageur,sautligne21);
							getline(listevoyageur,sautligne31);
							getline(listevoyageur,numeroDePasseport1);
						
							if(numeroDePasseport!=numeroDePasseport1)// tous les voyageurs que l'on ne veut pas modifier sont copiés dans le fichier liste voyageur auxiliaire
							{
								ofstream MonFlux("Dossier texte/listevoyageurauxiliaire.txt",ios::app);
					
								MonFlux<<""<<endl;
								MonFlux<< sautligne11 <<endl;
								MonFlux<< sautligne21 <<endl;
								MonFlux<< sautligne31 <<endl;
								MonFlux<<numeroDePasseport1 <<endl;
							}
							else//pour le voyageur que l'on souhaite modifier on copie tous les parametres inchangés dans liste voyageur auxiliaire en changeant celui que je souhaite modifier
							{
								ofstream MonFlux("Dossier texte/listevoyageurauxiliaire.txt",ios::app);
								MonFlux<<""<<endl;
								MonFlux<< nouveauprenom <<endl;
								MonFlux<< sautligne21 <<endl;
								MonFlux<< sautligne31 <<endl;
								MonFlux<< numeroDePasseport1 <<endl;
							}
					
						}while(getline(listevoyageur,ligne2));

						ofstream monFlux("Dossier texte/listevoyageur.txt");

						while(getline(listevoyageurauxiliaire,ligne3))//enfin copions le fichier voyageur auxiliaire dans celui liste voyageur en l'évrasant cette fois ci !
						{
							ofstream monFlux("Dossier texte/listevoyageur.txt",ios::app);
						
							string numeroDePasseport2,sautligne1,sautligne2,sautligne3,sautligne5;			
						
							getline(listevoyageurauxiliaire,sautligne1);
							getline(listevoyageurauxiliaire,sautligne2);
							getline(listevoyageurauxiliaire,sautligne3);
							getline(listevoyageurauxiliaire, numeroDePasseport2);
						
												
							monFlux <<sautligne1<<endl;
							monFlux <<sautligne2<<endl;
							monFlux <<sautligne3<<endl;
							monFlux <<numeroDePasseport2<<endl;
							monFlux <<"-------------------------------------------------------------------------"<<endl;
						}
						voyageur();
					}
					else if(b==2)//changeons le nom
					{
						system("cls");//meme principe que ci dessus
				
						string nouveaunom,ligne2,ligne3;
				
						cout<<" "<<endl;
						cout<<"	Veuillez entrer le nouveau nom du voyageur : ";
						cin>>nouveaunom;

						ofstream MonFlux("Dossier texte/listevoyageurauxiliaire.txt");
						ifstream listevoyageurauxiliaire("Dossier texte/listevoyageurauxiliaire.txt");
						ifstream listevoyageur("Dossier texte/listevoyageur.txt");

						do
						{					
							string sautligne11,sautligne21,sautligne31,sautligne51,numeroDePasseport1;
							
							getline(listevoyageur,sautligne11);
							getline(listevoyageur,sautligne21);
							getline(listevoyageur,sautligne31);					
							getline(listevoyageur,numeroDePasseport1);
							if(numeroDePasseport!=numeroDePasseport1)
							{
								ofstream MonFlux("Dossier texte/listevoyageurauxiliaire.txt",ios::app);
					
								MonFlux<<""<<endl;
								MonFlux<< sautligne11 <<endl;					
								MonFlux<< sautligne21 <<endl;
								MonFlux<< sautligne31 <<endl;
								MonFlux<< numeroDePasseport1 <<endl;
						
							}
							else
							{
								ofstream MonFlux("Dossier texte/listevoyageurauxiliaire.txt",ios::app);
					
								MonFlux<<""<<endl;
								MonFlux<< sautligne11 <<endl;
								MonFlux<< nouveaunom <<endl;
								MonFlux<< sautligne31 <<endl;
								MonFlux<< numeroDePasseport1 <<endl;
							}

						}while(getline(listevoyageur, ligne2));

						ofstream monFlux("Dossier texte/listevoyageur.txt");

						while(getline(listevoyageurauxiliaire,ligne3))//enfin copions le fichier voyageur auxiliaire dans celui liste voyageur en l'évrasant cette fois ci !
						{
							ofstream monFlux("Dossier texte/listevoyageur.txt",ios::app);
						
							string numeroDePasseport2,sautligne1,sautligne2,sautligne3,sautligne5;			
						
							getline(listevoyageurauxiliaire,sautligne1);
							getline(listevoyageurauxiliaire,sautligne2);
							getline(listevoyageurauxiliaire,sautligne3);
							getline(listevoyageurauxiliaire, numeroDePasseport2);
												
							monFlux <<sautligne1<<endl;
							monFlux <<sautligne2<<endl;
							monFlux <<sautligne3<<endl;
							monFlux <<numeroDePasseport2<<endl;
							monFlux <<"-------------------------------------------------------------------------"<<endl;
						}
						voyageur();
					}
					else if(b==3)//changeons l'age du voyageur
					{
						system("cls");//meme principe ci dessus
				
						string newage,ligne2,ligne3;
					
						cout<<" "<<endl;
						cout<<"	Veuillez entrer l'age nouveau du voyageur : ";
						cin>>newage;

						ofstream MonFlux("Dossier texte/listevoyageurauxiliaire.txt");
						ifstream listevoyageurauxiliaire("Dossier texte/listevoyageurauxiliaire.txt");
						ifstream listevoyageur("Dossier texte/listevoyageur.txt");

						do
						{
							string numeroDePasseport1,sautligne11,sautligne21,sautligne31,sautligne51;
										
							getline(listevoyageur,sautligne11);
							getline(listevoyageur,sautligne21);
							getline(listevoyageur,sautligne31);
							getline(listevoyageur, numeroDePasseport1);

							if(numeroDePasseport!=numeroDePasseport1)
							{
								ofstream MonFlux("Dossier texte/listevoyageurauxiliaire.txt",ios::app);
					
								MonFlux<<""<<endl;
								MonFlux<< sautligne11 <<endl;
								MonFlux<< sautligne21 <<endl;
								MonFlux<< sautligne31 <<endl;
								MonFlux<< numeroDePasseport1 <<endl;				
							}
							else
							{
								ofstream MonFlux("Dossier texte/listevoyageurauxiliaire.txt",ios::app);
					
								MonFlux<<""<<endl;
								MonFlux<< sautligne11 <<endl;
								MonFlux<< sautligne21 <<endl;
								MonFlux<< newage <<endl;
								MonFlux<< numeroDePasseport1 <<endl;
							}

						}while(getline(listevoyageur, ligne2));

						ofstream monFlux("Dossier texte/listevoyageur.txt");

						while(getline(listevoyageurauxiliaire, ligne3))
						{
							ofstream monFlux("Dossier texte/listevoyageur.txt",ios::app);
						
							string numeroDePasseport2,sautligne1,sautligne2,sautligne3,sautligne5;				
						
							getline(listevoyageurauxiliaire,sautligne1);
							getline(listevoyageurauxiliaire,sautligne2);
							getline(listevoyageurauxiliaire,sautligne3);
							getline(listevoyageurauxiliaire, numeroDePasseport2);
						
							monFlux <<sautligne1<<endl;
							monFlux <<sautligne2<<endl;
							monFlux <<sautligne3<<endl;
							monFlux <<numeroDePasseport2<<endl;
							monFlux <<"----------------"<<endl;
						}
						voyageur();
					}
					else if(b==4)//changeons le numero de passeport 
					{	
						system("cls");//meme principe que ci dessus
				
						string nouveaundp,ligne2,ligne3;
				
						cout<<" "<<endl;
						cout<<"	Veuillez entrer le nouveau numero de passeport du voyageur : ";
						cin>>nouveaundp;

						ofstream MonFlux("Dossier texte/listevoyageurauxiliaire.txt");
						ifstream listevoyageurauxiliaire("Dossier texte/listevoyageurauxiliaire.txt");
						ifstream listevoyageur("Dossier texte/listevoyageur.txt");

						do
						{					
							string sautligne11,sautligne21,sautligne31,sautligne51,numeroDePasseport1;

							getline(listevoyageur,sautligne11);
							getline(listevoyageur,sautligne21);
							getline(listevoyageur,sautligne31);					
							getline(listevoyageur,numeroDePasseport1);
							if(numeroDePasseport!=numeroDePasseport1)
							{
								ofstream MonFlux("Dossier texte/listevoyageurauxiliaire.txt",ios::app);
					
								MonFlux<<""<<endl;
								MonFlux<< sautligne11 <<endl;					
								MonFlux<< sautligne21 <<endl;
								MonFlux<< sautligne31 <<endl;
								MonFlux<< numeroDePasseport1 <<endl;			
							}
							else
							{
								ofstream MonFlux("Dossier texte/listevoyageurauxiliaire.txt",ios::app);
					
								MonFlux<<""<<endl;
								MonFlux<< sautligne11 <<endl;
								MonFlux<< sautligne21 <<endl;
								MonFlux<< sautligne31 <<endl;
								MonFlux<< nouveaundp <<endl;
							}

						}while(getline(listevoyageur, ligne2));

						ofstream monFlux("Dossier texte/listevoyageur.txt");

						while(getline(listevoyageurauxiliaire,ligne3))//enfin copions le fichier voyageur auxiliaire dans celui liste voyageur en l'évrasant cette fois ci !
						{
							ofstream monFlux("Dossier texte/listevoyageur.txt",ios::app);
						
							string numeroDePasseport2,sautligne1,sautligne2,sautligne3,sautligne5;			
						
							getline(listevoyageurauxiliaire,sautligne1);
							getline(listevoyageurauxiliaire,sautligne2);
							getline(listevoyageurauxiliaire,sautligne3);
							getline(listevoyageurauxiliaire, numeroDePasseport2);
												
							monFlux <<sautligne1<<endl;
							monFlux <<sautligne2<<endl;
							monFlux <<sautligne3<<endl;
							monFlux <<numeroDePasseport2<<endl;
							monFlux <<"----------------"<<endl;
						}			
						voyageur();
					}
					else if(b==0)
					{
						voyageur();//retour menu voyageur
					}				
				}
			}
		}while(getline(listevoyageur, ligne));
	}
	else
	{
		cout<<" "<<endl;
		cout<<"		ERREUR : Impossible d'ouvrir le fichier de lecture." << endl;
		Sleep(3000);
		voyageur();//Retour Menu Voyageur
	}
	return 0;
}