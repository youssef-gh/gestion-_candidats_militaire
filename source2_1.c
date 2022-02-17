#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include "source1.c"
#include "projet.h"
#define tab 20
void main()
{
	FILE *fichier;
char name1[10],name2[10],nom[tab],prenom[tab];/* noms des fichiers */
int choix;
fflush(stdin);
printf("entrez le nom de fichier des groupes:");
gets(name1);
fflush(stdin);
printf("entrez le nom du fichier des candidats:");
gets(name2);
do
{
printf("\n\t\t\tGESTION DE FICHIER\n");
printf("\t\t\t------------------\n\n\n");
printf("CREATION DU FICHIER CANDIDATS ---> 1\n");
printf("LECTURE DU FICHIER CANDIDATS ---> 2\n");
printf("AJOUTER UNE FICHE CANDIDAT ---> 3\n");
printf("RECHERCHER UNE FICHE CANDIDAT ---> 4\n");
printf("CREATION DU FICHIER DES GROUPES ---> 5\n");
printf("LECTURE DU FICHIER DES GROUPES ---> 6\n");
printf("AJOUTER UNE FICHE GROUPE ---> 7\n");
printf("SUPPRESSION D\'UN CANDIDAT ---> 8\n");
printf("RECHERCHER UN GROUPE ---> 9\n");
printf("modifier un candidat ---> 10\n");
printf("SORTIE ---> 99\n\n");
printf("VOTRE CHOIX: ");
scanf("%d",&choix);
switch(choix)
{
case 1:create_Candidat_file(fichier,name2);break;
case 2:alphab_display(fichier,name2);break;
case 3:add_Candidat(fichier,name2);break;
case 4:
	fflush(stdin);
	printf("entrez le nom du candidat a chercher: ");
	gets(nom);
	fflush(stdin);
	printf("entrez son prenom: ");
	gets(prenom);
	seek_Candidat(fichier,name2,nom,prenom);break;
case 5:create_Groupe_file(fichier,name1);break;
case 6:view_file_Groupe2(fichier,name1);break;
case 7:add_Groupe(fichier,name1);break;
case 8:deleting_Candidat(fichier,name2);break;
case 9:seek_Groupe(fichier,name1);break;
case 10:modify_Candidat(fichier,name2);break;
}
}
while ((choix!=0));
}

