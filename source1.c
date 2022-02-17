#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include "projet.h"
#define n_taille 20
#define tab 20

/*definition de deux structures
la premiere groupe permet de saisir
nom prenom ville de groupe
deuxieme pour saisir information personnels
nom,prenom,sexe,age,taille,poids
*/
typedef struct
{
	char nom[tab],prenom[tab],ville[tab];
}
Groupe;
Groupe fichegrp1[5],fichegrp,fichegrp2[5];
typedef struct
{
	char nom[tab],prenom[tab],sexe;
	int age;
	float taille,poids;
}Candidat;
// declaration des variables globales de type Candidat
Candidat fiche1,fiche2,fiche3,fiche4,fiche5,fiche6,tempfiche1,nvlfiche1,nvlfiche2[100];
/*
permet de  saisir les elements
et leurs informations
*/
void create_Candidat_file(FILE*f,char*name)
{
	//ouverture de fichier name en mode d'ecriture
	f=fopen(name,"w");
	/*fflush(stdin)permet de libérer un tampon dans
	 la mémoire pour entrer autre valeur. 
	 */
	fflush(stdin);
	// début de saisie les informations
	printf("\nentrez le nom du candidat: ");
	gets(fiche1.nom);
	//utilisation des points pour accéder au contenu des structures
	fflush(stdin);
	printf("\nentrez le prenom du candidat: ");
	gets(fiche1.prenom);
	printf("\nson age:");
	scanf("%d",&fiche1.age);
	printf("\nla taille:");
	scanf("%f",&fiche1.taille);
	printf("\nle poids :");
	scanf("%f",&fiche1.poids);
	printf("\nle sexe(f/m):");
	scanf(" %c",&fiche1.sexe);
	printf("operation succeed.");
	//ecrire ces information dans le fichier
	fwrite(&fiche1,sizeof(Candidat),1,f);
	fprintf(f,"\n");
	// fermeture de fichier
	fclose(f);
}
// creation du groupe
void create_Groupe_file(FILE*f,char*name)
{
	int i;
	// pour l'utilise en la boucle for
	printf("Creation d\'un fiche\n");
	//ouverture de fichier name en mode d'ecriture
	f=fopen(name,"w");
	printf("la saisie des candidats du groupe:\n");
	for(i=0;i<5;i++){
		fflush(stdin);
		printf("\nle nom du candidat numero %d:",i+1);
		gets(fichegrp1[i].nom);
		fflush(stdin);
		printf("\nle prenom du candidat numero %d:",i+1);
		gets(fichegrp1[i].prenom);
		fflush(stdin);
		printf("\nla ville du candidat numero %d:",i+1);
		gets(fichegrp1[i].ville);
		// ecriture de tous les information de fichegrp1 en fichier 'f'
		fwrite(&fichegrp1[i],sizeof(Groupe),1,f);
	}
	printf("\nle saisie est bien fait.");
	fclose(f);
}
/* fonction 'add' permet d'ajouter
 des candidats
 */
void add_Candidat(FILE*f,char*name)
{
	//ouverture de fichier en mode d'ajout à la fin
	//lire les informations
	f=fopen(name,"a");
	fflush(stdin);
	printf("\nentrez le nom du candidat: ");
	gets(fiche2.nom);
	fflush(stdin);
	printf("\nentrez le prenom du candidat: ");
	gets(fiche2.prenom);
	printf("\nson age:");
	scanf("%d",&fiche2.age);
	printf("\nla taille:");
	scanf("%f",&fiche2.taille);
	printf("\nle poids :");
	scanf("%f",&fiche2.poids);
	printf("\nle sexe(f/m):");
	scanf(" %c",&fiche2.sexe);
	printf("\noperation succeed.");
	// ecriture de tous les information de fiche2 en  'f'
	fwrite(&fiche2,sizeof(Candidat),1,f);
	//fermeture de fichier
	fclose(f);
	}
	/*fonction add _groupe
	permet d'ajouter groupe de
	candidats avec leurs informations
	*/
void add_Groupe(FILE*f,char*name){
	int i;// pour l'utilise dans for
	f=fopen(name,"a");
	for(i=0;i<5;i++){
		fflush(stdin);
		printf("\nle nom du candidat numero %d:",i+1);
		gets(fichegrp2[i].nom);
		fflush(stdin);
		printf("\nle prenom du candidat numero %d:",i+1);
		gets(fichegrp2[i].prenom);
		fflush(stdin);
		printf("\nla ville du candidat numero %d:",i+1);
		gets(fichegrp2[i].ville);
		// ecriture de tous les information de fichegrp2 en fichier 'f'
		fwrite(&fichegrp2[i],sizeof(Groupe),1,f);
	}
	fclose(f);
	printf("operation succeed.");
}
/*fonction seek pour rechercher
candidat par son nom er prenom
*/
int seek_Candidat(FILE*f,char*name,char*seek1name,char*seek2name)
{
	// t:taille et p:poids
	float t,p;
	//ouverture de fichier en mode lecture
	f=fopen(name,"r");
	//teste si fichier n'existe pas
	if (f==NULL)
	printf("\nERREUR, CE FICHIER N'EXISTE PAS\n");
	else{	
		// puissque le curseur n'est pas a la fin de fichier  faire	
		while(fread(&fiche3,sizeof(Candidat),1,f)!=0){
			//teste si le nom et prenom sont identiques
			/*
			strcmp permet de compare deux chaines de caracteres.
			Elle renvoie une valeur negative si la première chaine
		    est plus petite que la deuxième,
			zero si elles sont égaux et 
			une valeur positive si la premiere est plus grande.
			*/
			if((strcmp(fiche3.nom,seek1name)==0)&&(strcmp(fiche3.prenom,seek2name)==0))
			{
			printf("le candidat existe:\n");
			t=fiche3.taille;
			p=fiche3.poids;
			printf("nom:%s prenom:%s age:%d taille:%f poids:%f sexe:%c",fiche3.nom,fiche3.prenom,fiche3.age,t,p,fiche3.sexe);	
			// operation succeed
			return 1;
			//fermeture de fichier
			fclose(f);
			}
		}
		printf("le candidat n existe pas");
		return 0;
		//fermeture de fichier
		fclose(f);
}
}
/* fonction delete permet de supprimer
 des candidats prend comme input son nom
 */
void deleting_Candidat(FILE*f,char*name)
{
	char prenom1[tab],nom1[tab];
	//declaration noveau fichier pour copie les elements que nous ne voulont pas supprimer de ancien fichier 
	FILE*fichiertemp;
	fflush(stdin);
	printf("entrez le nom du Candidat a supprimer: ");
	gets(nom1);
	fflush(stdin);
	printf("entrez son prenom: ");
	gets(prenom1);
	// ouverture de fichier source en mode lecture
	f=fopen(name,"r");
	//ouverture de fichier temporaire en mode ecriture
	fichiertemp=fopen("temmp.txt","w");
	while(fread(&fiche4,sizeof(Candidat),1,f)!=0)
	{
		//teste si nom et prenom sont identiques
		if((strcmp(nom1,fiche4.nom)!=0)&&(strcmp(prenom1,fiche4.prenom)!=0))
		{
			//ecrire les element que nous voulont pas supprimer en temp
			fwrite(&fiche4,sizeof(Candidat),1,fichiertemp);
		}
	}
	//fermeture de fichier f
	fclose(f);
	//fermeture de fichier 'temp'
	fclose(fichiertemp);
	//suppression de l'ancien fichier
	remove(name);
	// renommer temp fichier par l'ancien nom 
	rename("temmp.txt",name);
	printf("suppresion avec succes");
}
/*fonction de recherche d'un groupe
 par son 'ville'
 */
void seek_Groupe(FILE*f,char*name)
{
	int n=0,m=0;//nombre des repetitions de la ville du groupe
	char nom1[tab],prenom1[tab],ville1[tab],ville2[tab];
	//ouverture en mode lecture
	f=fopen(name,"r");
	//libérer un tampon dans la mémoire pour entrer autre valeur
	fflush(stdin);
	printf("entrez la ville du groupe a chercher: ");
	gets(ville2);
	//puisque on a pas arriver à la fin du fichier
	while(!feof(f)){
	//lecture des information de 'f'
	fread(nom1,tab,1,f);
	fread(prenom1,tab,1,f);
	fread(ville1,tab,1,f);
	//si la ville existe et identique avec une autre ville de fichier
	if((strcmp(ville2,ville1)==0))
	{
	// pour l'afficher l'existence une seule fois (il y a une incrementation)
	if(m==0)
	printf("le groupe existe: \n");
	printf("Candidat %d: \n",n+1);
	printf("le nom: %s\t\tle prenom: %s\t\tla ville: %s\n",nom1,prenom1,ville1);
	n++;
	m++;
	}
	if(n==5){
	n=0;m=0;
	//puisque chaque groupe contient 5 candidats
	//et pour que la fonction ne trompe pas
	// operation succeed--> close file 'f'
	goto r;
	}
	}
	//au cas ou il n'existe pas
	printf("le groupe n existe pas");
	//fermeture de fichier
	r:fclose(f);
}
/* fonction d'affichage
 des groupe
 */
void view_file_Groupe2(FILE*f,char*name){
	int compteur=0;
	float t,p;
	printf("Affichage des Candidats\n");
	//ouverture du fichier en mode lecture
	f=fopen(name,"r");
	//teste si fichier existe(car c'est lecture)
	if (f==NULL) printf("\nERREUR, CE FICHIER N'EXISTE PAS\n");
	else{	
		//lecture les information de fichegrp 
		while(fread(&fichegrp,sizeof(Groupe),1,f)!=0){
			printf("\nCandidat numero %d:\n",compteur+1);
			printf("nom:%s prenom:%s ville:%s",fichegrp.nom,fichegrp.prenom,fichegrp.ville);
			compteur++;
		}
		//fermeture de fichier
		fclose(f);
	}
}
/*fonction permet de modifier
 les information des candidats
*/
void modify_Candidat(FILE*f,char*name){
	//declaration de tous les variable qu'on peut l'utilise pour la modification
	char ancsexe,nom1[tab],prenom1[tab],ancprenom[tab],ancnom[tab],nvlnom[tab],nvlprenom[tab],nvlsexe,choix;
	float ancpoids,anctaille,nvlpoids,nvltaille;
	int ancage,nvlage;
	//ouvrir fichier temporaire
	FILE*fichiertemp;
	//libérer un tampon dans la mémoire pour entrer autre valeur
	fflush(stdin);
	printf("\nentrez le nom Candidat a modifier: ");
	gets(nom1);
	fflush(stdin);
	printf("\nentrez son prenom: ");
	gets(prenom1);
	//ouverture en mode lecture
	f=fopen(name,"r");
	//ouverture en mode ecriture
	fichiertemp=fopen("temmp.txt","w");
	while(fread(&fiche5,sizeof(Candidat),1,f)!=0)
	{
		//teste si le nom et le prenom sont identiques
		if((strcmp(nom1,fiche5.nom)==0)&&(strcmp(prenom1,fiche5.prenom)==0)){
			//copie des informations
			/*
			 copie une chaine 
			 dans une autre chaine et
			 renvoie l'addresse de 
			 la 1ere chaine
			 */
			strcpy(ancprenom,fiche5.prenom);
			strcpy(ancnom,fiche5.nom);
			anctaille=fiche5.taille;
			ancpoids=fiche5.poids;
			ancage=fiche5.age;
			ancsexe=fiche5.sexe;}
			// s'ils ne sont pas identiques (ne sont pas les candidats qu'on veut modifier)
		if((strcmp(nom1,fiche5.nom)!=0)||(strcmp(prenom1,fiche5.prenom)!=0))
			{
				//ecrire les informations de fiche5 en fichiertemp
			fwrite(&fiche5,sizeof(Candidat),1,fichiertemp);
			}
		}
	do{
		//les choix de ce que vous voulez modifier
		printf("\nQue souhaitez vous modifier?");
		printf("(nom(n),prenom(p),age(a),taille(t),poids(d),sexe(s)): ");
		printf("\nsi vous voulez modifier rien tappez (e): ");
		scanf(" %c",&choix);
		switch(choix){
		//cas de prenom
		case 'p':
		fflush(stdin);
		printf("\nentrez le nouveau prenom: ");
		gets(nvlprenom);
		//changer prenom par le nouveau
		strcpy(ancprenom,nvlprenom);
		break;
		//cas de nom
		case 'n':
		fflush(stdin);
		printf("\nentrez le nouveau nom: ");
		gets(nvlnom);
		//changer nom par le nouveau
		strcpy(ancnom,nvlnom);
		break;
		//cas de l'age
		case 'a':
		printf("\nentrez le nouveau age: ");
		scanf("%d",&nvlage);
		//changer age par le nouveau
		ancage=nvlage;
		break;
		// cas de taille
		case 't':
		printf("\nentrez la nouvelle taille: ");
		scanf("%f",&nvltaille);
		//changer taille par la nouvelle taille
		anctaille=nvltaille;
		break;
		//cas de poids
		case 'd':
		printf("\nentrez le nouveau poids: ");
		scanf("%f",&nvlpoids);
		//le changer par noveau
		ancpoids=nvlpoids;
		break;
		}
		//cas ou vous ne voulez modifier rien
	}while((choix!='e')&&choix!='E');
			strcpy(nvlfiche1.prenom,ancprenom);
			strcpy(nvlfiche1.nom,ancnom);
			nvlfiche1.taille=anctaille;
			nvlfiche1.poids=ancpoids;
			nvlfiche1.age=ancage;
			nvlfiche1.sexe=ancsexe;
	//le role de ses ancvars est dans le cas où l'utilisateur
	//veut changer un ou plisieurs choses mais pas tout les donnees du candidat 
	//fermeture du fichier		
	fclose(fichiertemp);
	//ouverture de fichier temp en mode d'ajout à la fin'
	fichiertemp=fopen("temmp.txt","a");
	//ecrire dans fichiertemp from nvlfiche1
	fwrite(&nvlfiche1,sizeof(Candidat),1,fichiertemp);
	//fermeture de fichier f
	fclose(f);
	//fermeture de fichier temp
	fclose(fichiertemp);
	//suppression 
	remove(name);
	//renomer
	rename("temmp.txt",name);
}
/*
 affichage de tous les candidats
 en ordre alphabetique
 */
void alphab_display(FILE*f,char*name){
	int i=0,j,nbrcandidat=0,m=0;
	float t[100],p[100];
	//100 candidats à traiter(le nombre à regler)
	char str[100][tab],temp[tab];
	//tableau de deux dimentions pour recuperer les noms des 100 candidats 
	//ouverture en mode lecture
	f=fopen(name,"r");
	//lire les informations de fichier f et l'affecter a fiche6
	while(fread(&fiche6,sizeof(Candidat),1,f)!=0){
		nvlfiche2[i]=fiche6;
		//copie nom de fiche6 à str
		strcpy(str[i],fiche6.nom);
		i++;
	}
	nbrcandidat=i;
	i=0;
	//affecter les information de fiche2 à un temporaire
	for(i=0;i<=nbrcandidat;i++)
		for(j=i+1;j<=nbrcandidat;j++){
			if(strcmp(str[i],str[j])>0){
				/*dans cette partie si str[i] est plus grande que str[j]
				c-à-d les chars(alphabets) de str[j] se trouves apres str[i]
				puis une fonction d'echange simple en deux champs
				champs pour les noms et champs pour les fiches
				*/
				strcpy(temp,str[i]);
				tempfiche1=nvlfiche2[i];
				strcpy(str[i],str[j]);
				nvlfiche2[i]=nvlfiche2[j];
				strcpy(str[j],temp);
				nvlfiche2[j]=tempfiche1;
			}
		}
	for(i=0;i<=nbrcandidat;i++){
		if(nvlfiche2[i].age==0)
		continue;
		else {
		t[i]=nvlfiche2[i].taille;
		p[i]=nvlfiche2[i].poids;
		printf("\nCandidat %d: nom:%s prenom:%s age:%d taille:%.2f poids:%.2f sexe:%c",m+1,nvlfiche2[i].nom,nvlfiche2[i].prenom,nvlfiche2[i].age,t[i],p[i],nvlfiche2[i].sexe);
		m++;}
	}
	fclose(f);
	printf("\nfin du fonction.");
}


