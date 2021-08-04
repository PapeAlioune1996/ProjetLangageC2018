

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Etudiant
{int Num;
char Nom[100];
char Prenom[100];
char Filiere[50];
float Moy;
};

struct Etudiant Etud;
/*---------- fonction de recherche----------------*/
int rech(int Numrech)
{
    FILE *F;
  F=fopen("Etudiants.txt","r");
do{
     fscanf(F,"%d\t %s\t %s\t %f\t %s\n",&Etud.Num,&Etud.Nom,&Etud.Prenom,&Etud.Moy,&Etud.Filiere);
    fflush(stdin);
    if (Etud.Num==Numrech)
    {
        return 1;
    }
     }
    while(!feof(F));


  fclose(F);
  return -1;

}

void AjouterEtudiant()
{
    FILE *F;
    int num;

F=fopen("Etudiants.txt","a");
printf("\n entre un nouveau numero:");
scanf("%d",&num);
while(rech(num)==1)
{
    printf("ce numero existe d�ja\n");
    printf("entrer un nouveau numero");
    scanf("%d",&num);
}

      Etud.Num=num;
        fflush(stdin);
      printf("entrer le nom:");
      gets(Etud.Nom);
      fflush(stdin);
       printf("entrer le prenom:");
      gets(Etud.Prenom);
      fflush(stdin);
      printf("entrer la moyenne:");
      scanf("%f",&Etud.Moy);
      while(Etud.Moy<=0 || Etud.Moy>=20){
      printf("moyenne invalid ");
      printf("\nentrer une moyenne entre 0 et 20 :\n");
      scanf("%f",&Etud.Moy);
      fflush(stdin);
        }
      printf("entrer la filliere:");
      scanf("%s",&Etud.Filiere);
      fflush(stdin);
      fprintf(F,"%d\t %s\t %s\t %f\t %s\n",Etud.Num,Etud.Nom,Etud.Prenom,Etud.Moy,Etud.Filiere);
      fclose(F);

}

void Recherche()
{
    int NumR;
    printf("Entrer le numero d etud a recherche: ");
    scanf("%d",&NumR);
    FILE*F;
    F=fopen("Etudiants.txt","r");
    do
    {fscanf(F,"%d\t %s\t %s\t %f\t %s\n",&Etud.Num,&Etud.Nom,&Etud.Prenom,&Etud.Moy,&Etud.Filiere);
        if (NumR == Etud.Num)
        {
      printf(" num:%d\t ",Etud.Num);
      printf(" nom:%s\t ",Etud.Nom);
      printf(" prenom:%s\t ",Etud.Prenom);
      printf(" moyenne:%f\t ",Etud.Moy);
      printf(" filliere:%s\t ",Etud.Filiere);
        }
    }while(!feof(F));
          fclose(F);
}


void supprimerEtudiant()
{
  char rep;
  int NumRech;
  printf("entrer le num de l'etudiant que vous voulez supprimer:");
  scanf("%d",&NumRech);
  fflush(stdin);


          FILE *Fich,*F;
          F=fopen("Etudiants.txt","r");
          Fich=fopen("TempEtudiant.txt","a");
          do
          {
                fscanf(F,"%d\t %s\t %s\t %f\t %s\n",&Etud.Num,&Etud.Nom,&Etud.Prenom,&Etud.Moy,&Etud.Filiere);
                       if (NumRech != Etud.Num)
{


               fprintf(Fich,"%d\t %s\t %s\t %f\n %s\n",Etud.Num,Etud.Nom,Etud.Prenom,Etud.Moy,Etud.Filiere);
          }
          }
          while(!feof(F));
          fclose(Fich);
          fclose (F);
          remove("Etudiants.txt");
          rename("TempEtudiant.txt","Etudiants.txt");
          printf("supression reussite");

      }


void ModifierEtudiant()
{FILE *Fich,*F;
int num, i;

printf("entrer le num de l'etudiant que vous voulez modifier:");
  scanf("%d",&num);
  fflush(stdin);

          F=fopen("Etudiants.txt","r");
          Fich=fopen("TempEtudiant.txt","a");
          do
          {
                fscanf(F,"%d\t %s\t %s\t %f\t %s\n",&Etud.Num,&Etud.Nom,&Etud.Prenom,&Etud.Moy,&Etud.Filiere);
                       if (num == Etud.Num)
                       {
                        Etud.Num==num;
                         printf("\n entrer le nv nom:");
      gets(Etud.Nom);

       printf("\n entrer le nv prenom:");
      gets(Etud.Prenom);
      printf("\n entrer la  nv moy:");
      scanf("%f",&Etud.Moy);

       printf("\n entrer la  nv filliere:");
      scanf("%s",&Etud.Filiere);
      }
      fprintf(Fich,"%d\t %s\t %s\t %f\n %s\n",Etud.Num,Etud.Nom,Etud.Prenom,Etud.Moy,Etud.Filiere);
          }
          while(!feof(F));
          fclose(F);
          fclose (Fich);
          remove("Etudiants.txt");
          rename("TempEtudiant.txt","Etudiants.txt");
          printf("la modification est reussi");
      }

void rechercher_un_etudiant_par_nom()
{
   FILE *F;
   char nom_rech[100];
   F=fopen("Etudiants.txt","r");
   printf("\nRechercher un etudiant par son nom :\n");
   printf("--------------------------\n");
   printf("Entrer le nom d'etudiant : ");
   scanf("%s",&nom_rech);
   if (F == NULL)
    {
        printf ("ce fichier n'existe pas ");
    }
    else
    {
    printf("numero\t nom \t prenom\t moyenne\t filiere\n");
       while (!feof(F))
            {
               fscanf(F,"%d\t %s\t %s\t %f\t %s\n",&Etud.Num,&Etud.Nom,&Etud.Prenom,&Etud.Moy,&Etud.Filiere);
                   {
                       if(strcmp(Etud.Nom,nom_rech)==0)
                        {
                              printf("%d\t  %s\t  %s\t  %.2f\t\t  %s\n",Etud.Num,Etud.Nom,Etud.Prenom,Etud.Moy,Etud.Filiere);                        }
                    }
            }
}
}

void afficher_les_etudiant_d_une_filiere()
{
    char et_filiere[50];
printf("Saisir une filiere : ");
     scanf("%s",&et_filiere);
     printf("Les etudiants de la filiere %s sont : \n\n",et_filiere);
     FILE *F;
     F=fopen("Etudiants.txt","r");
        if (F == NULL)
    {
        printf ("ce fichier n'existe pas ");
    }
    else
    {
    printf("numero\t nom \t prenom\t moyenne\t filiere\n");
        while (!feof(F))
            {
                fscanf(F,"%d\t %s\t %s\t %f\t %s\n",&Etud.Num,&Etud.Nom,&Etud.Prenom,&Etud.Moy,&Etud.Filiere);                        {
                        if(strcmp(et_filiere,Etud.Filiere)==0)
                            {
                              printf("%d\t  %s\t  %s\t  %.2f\t\t  %s\n",Etud.Num,Etud.Nom,Etud.Prenom,Etud.Moy,Etud.Filiere);                             }
                        }
           }
}}

void afficher_les_etudiants_admis()
{
    FILE *F;
    F=fopen("Etudiants.txt","r");
    if (F == NULL)
    {
        printf ("ce fichier n'existe pas ");
    }
    else
    {    printf("la list des etudiants admis est:\n \n");
    printf("numero\t nom \t prenom\t moyenne\t filiere\n");
       while (!feof(F))
             {
                 if(fscanf(F,"%d\t %s\t %s\t %f\t %s\n",&Etud.Num,&Etud.Nom,&Etud.Prenom,&Etud.Moy,&Etud.Filiere)!=EOF)
                        {
                       if(Etud.Moy>10)
                            {
                          printf("%d\t  %s\t  %s\t  %.2f\t\t  %s\n",Etud.Num,Etud.Nom,Etud.Prenom,Etud.Moy,Etud.Filiere);
                            }
                        }
            }
}}

void afficher()
{
    FILE*F = NULL;
    F=fopen("Etudiants.txt","r");


    if (F == NULL)
    {
        printf ("ce fichier n'existe pas ");
    }
    else
    {
    printf("la list des etudiants est:\n \n");
    printf("numero\t nom \t prenom\t moyenne  filiere\t");

    do{
        if(fscanf(F,"%d\t %s\t %s\t %f\t %s\t ",&Etud.Num,&Etud.Nom,&Etud.Prenom,&Etud.Moy,&Etud.Filiere)!=EOF)
        fflush(stdin);
        printf ("\n \n");
        printf("%d\t",Etud.Num);
        printf(" %s\t",Etud.Nom);
        printf(" %s\t",Etud.Prenom);
        printf(" %.2f\t",Etud.Moy);
        printf("  %s\n",Etud.Filiere);
    } while(!feof(F));
          fclose(F);
}
}
void quitter(){
     system("cls");
 printf("\n\n        \t------------FIN-----------\n\n\n");
 printf("\n\n        \t------------MERCI-----------\n\n\n");
 }


int main()
{
    int choix;
    char rep;

  system("color F");
do{
printf("\n             *      Gestion des etudiants    * \n\n");



           printf("\n");

           printf("           <1.  Saisir plusiurs etudiants---------------- \n");
           printf("           <2.  Afficher la list des etudiants----------- \n");
           printf("           <3.  Supprimier un etudiant------------------- \n");
           printf("           <4.  modifier un etudiant--------------------- \n");
           printf("           <5.  Rechercher un etudiant par numero-------- \n");
           printf("           <6.  rechercher un etudiant par nom----------- \n");
           printf("           <7.  afficher les etudiant d'une filiere------ \n");
           printf("           <8.  afficher les etudiants admis------------- \n");
           printf("           <9.  Quitter---------------------------------- \n");

           printf("\n \n");

           printf("Entre votre choix : ");
           scanf("%d",&choix);
           printf("\n\n");
           switch(choix){

case 1: system("cls");AjouterEtudiant();break;
case 2: system("cls");afficher();break;
case 5: system("cls");Recherche();break;
case 6: system("cls");rechercher_un_etudiant_par_nom();break;
case 4: system("cls");ModifierEtudiant();break;
case 7: system("cls");afficher_les_etudiant_d_une_filiere();break;
case 8: system("cls");afficher_les_etudiants_admis();break;
case 3: system("cls");supprimerEtudiant();break;
case 9:system("cls");quitter();break;
default : system("cls");printf("votre choix n'est pas valide !!!\n");
        }

        }while(choix!=9);


  system("PAUSE>null");
  return 0;
  }
