#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int i,j,nombre_mystere,nombre_choix,mode;
int compteur1=25,compteur2=10,compteur3=100000000;
int nombre_choix,coup,joueur1,joueur2,score=0,tour;

int deuxieme_joueur()
{
    printf("En mode 2 joueurs \n");
    joueur1=1;
    joueur2=2;
    printf("\nQuel est le nombre de tours que vous aimeriez jouer:  \n");
    scanf("%d",&tour);
    for (j=1;j<tour+1;j++)
    {
        printf("\nJoueur numero%d choisit le nombre de tours que le joueur2 peut jouer: ",joueur1);
    	scanf("%d",&coup);
    	printf("  Joueur numero%d,ENTREZ UN chiffre ENTRE 1 ET 100 :\n",joueur2);
    	scanf("%d",&nombre_choix);
    	int compteur=coup;
    	for (i=0;i<coup;i++)
        {
                compteur--;
                if (nombre_mystere < nombre_choix)
        		{
        		    printf("c'est MOINS,veuillez reessayer\n");
        		    printf("Il vous reste %d chances\n\n",compteur);
        		}
        		else if (nombre_mystere > nombre_choix)
       			{
       			    printf("c'est PLUS,veuillez reessayer\n");
        		    printf("Il vous reste %d chances\n\n",compteur);
        		}
        		score=coup-i;
    			if(compteur==0)
    		    {
        		    printf("Le joueur numero%d a obtenu %d point(s)\n",joueur2,score);
        		    int temp=joueur1;
        		    joueur1=joueur2;
        		    joueur2=temp;
        		    srand(time(NULL));
    			    nombre_mystere=rand()%100;
    			    printf("%d",nombre_mystere);
    			    exit(0);
        		    break;
        		}
    			if (nombre_mystere == nombre_choix)
    		    {
        		    printf("BINGO!vous avez trouve le chiffre mystere \n\n");
        		    printf("Le joueur numero%d, a obtenu %d point(s)\n\n",joueur2,score);
        		    int temp=joueur1;
        		    joueur1=joueur2;
            		    joueur2=temp;
            		    srand(time(NULL));
   		            nombre_mystere=rand()%100;
       				break;
        		}
        	    printf("Choisissez un autre chiffre: ");
   				 scanf("%d",&nombre_choix);
        }
    }
}


int plus_moins(int nombre_mystere_a_trouver, int nombre_choix_joueur,char mode)
{

     switch (mode)
    {
        case 1:
        {
            for (i=1;i<50;i++)
            {
                compteur3--;

                if (nombre_mystere_a_trouver < nombre_choix_joueur)
                {
                    printf("c est MOINS,veuillez reessayer\n\n");
                }
                else if (nombre_mystere_a_trouver > nombre_choix_joueur)
                {
                    printf("c'est PLUS,veuillez reessayer\\n\n");
                }
                if(nombre_mystere_a_trouver == nombre_choix_joueur)
                {
                   printf("BINGO!vous avez trouve le chiffre mystere \n\n");
                   exit(1);
                }
               printf("Entrer un autre chiffre: ");
               scanf("%d",&nombre_choix_joueur);
            }
        }
    }
     switch (mode)
    {
        case 2:
        {
            for (i=1;i<26;i++)
            {
                compteur1--;

                if (nombre_mystere_a_trouver < nombre_choix_joueur)
                {
                    printf("Il vous reste  %d chances\n",compteur1);
                    printf("c'est MOINS,veuillez reessayer\n\n");
                }
                else if (nombre_mystere_a_trouver > nombre_choix_joueur)
                {
                    printf("Il vous reste  %d chances\n",compteur1);
                    printf("c'est PLUS,veuillez reessayer\n\n");
                }
                if(nombre_mystere_a_trouver == nombre_choix_joueur)
                {
                   printf("BINGO!vous avez trouve le chiffre mystere \n\n");
                   exit(1);
                }
               printf("Entrer un autre chiffre: ");
               scanf("%d",&nombre_choix_joueur);
            }
        }
    }
       switch (mode)
    {
        case 3:
        {
            for (i=1;i<11;i++)
            {
                compteur2--;

                if (nombre_mystere_a_trouver < nombre_choix_joueur)
                    {
                        printf("Il vous reste %d chances \n",compteur2);
                        printf("c'est MOINS,veuillez reessayer\n\n");
                    }
                else if (nombre_mystere_a_trouver > nombre_choix_joueur)
                {
                    printf("Il vous reste %d chances \n",compteur2);
                   printf("c'est PLUS,veuillez reessayer\n\n");
                }
                if(nombre_mystere_a_trouver == nombre_choix_joueur)
                {
                   printf("BINGO!vous avez trouve le chiffre mystere\n\n");
                   exit(1);
                }
                printf("Entrer un autre chiffre: ");
                scanf("%d",&nombre_choix_joueur);
            }
	}	
    }
}
void chiffre()
{
    printf("Mode un joueur");
    printf("\nChoisissez un chiffre : ");
    scanf("%d",&nombre_choix); 
    plus_moins(nombre_mystere,nombre_choix,mode);
}

void mod()
{
    srand(time(NULL));
    nombre_mystere=rand()%100;
    printf("3 difficultes pour plus de fun: \n");
    printf("Tapez1:Facile     Tapez2:Moyen    Tapez3:Difficile\n\n");
    printf("Entrer le mode: ");
    scanf("%d",&mode);
    if (mode==1 || mode==2 || mode==3)
    {

        chiffre();
    }
    else 
    {
    	printf("Vous n avez pas tape sur la bonne touche,faites un choix entre les 3 chiffres ci dessous:\n\n");
    	mod();
	} 
}


int main()
{
    int joueur;
    printf("JEU PLUS OU MOINS\n");
    printf("1 joueur     2 joueurs\n\n");
    printf("Tapez sur 1 pour jouer seul ou sur 2 pour jouer contre un ami: ");
    scanf("%d",&joueur);
    if (joueur==1)
    { 
       mod(); 
    }
    if (joueur==2)
    {
    	deuxieme_joueur();
	}
    else 
    {
    	printf("Vous n avez pas tape sur la bonne touche,faites un choix entre les 2 modes de jeu\n\n");
        main();
    }
}
