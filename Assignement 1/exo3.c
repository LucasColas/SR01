#include <stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include<math.h>
#define max 255
#define MAXCHAR 500

typedef struct Restaurant{
    char nom_restaurant[max];
    char adresse_restaurant[max];
    char position_restaurant[max];
    char specialite[max];
}Restaurant;


void viderBuffer() {

    int c = 0;
    while (c != '\n' && c != EOF){
        c = getchar();
    }

}

int lire(char* chaine, int longueur) {
    char* positionEntree = NULL;
    if (fgets(chaine, longueur, stdin) != NULL)

    {
        positionEntree = strchr(chaine, '\n');
        if (positionEntree != NULL)
        {
            *positionEntree = '\0';
        }
        else
        {
            viderBuffer();
        }
        return 1;
    }
    else
    {
        viderBuffer();
        return 0;
    }
}
int lire_restaurant (char* chemin, Restaurant restaurants[]){
    FILE *frest = fopen(chemin, "r");
    char row[MAXCHAR];
    char *token;
    char c;
    char newcar[4][max]; // récupérer les caractéristiques d'un restaurant

    if(frest == NULL)
    {printf("Fichier impossible à ouvrir");}
    int j = 0;
    Restaurant new;
    fgets(row, MAXCHAR, frest); //lecture de l'entete
    if (frest != NULL) {
        while(fgets(row, max, frest) != NULL) {
            c = row[0];
            if (c != '\n') {
                token = strtok(row, ";");
                strcpy(restaurants[j].nom_restaurant, token);
                
                token = strtok(NULL, ";");
                strcpy(restaurants[j].adresse_restaurant, token);
                
                token = strtok(NULL, ";");
                strcpy(restaurants[j].position_restaurant, token);
                
                token = strtok(NULL, ";");
                strcpy(restaurants[j].specialite, token);
                
                //printf("%s\n", restaurants[j].nom_restaurant);
                //printf("%s\n", restaurants[j].adresse_restaurant);
                //printf("%s\n", restaurants[j].position_restaurant);
                //printf("%s\n", restaurants[j].specialite);

                j++;

            }
        }
    }
    /*
    while (feof(frest) != true)
    {
        fgets(row, MAXCHAR, frest);
        if (strcmp(row,"\n") != 0){
        //printf("Row : %s", row);
        Restaurant new;
        int i = 0;
        token = strtok(row, ";");
        while(token != NULL)
        {
            //printf("Token: %s\n", token);
            strcpy(newcar[i], token);
            i++;
            token = strtok(NULL, ";");
        }
            strcpy(new.nom_restaurant, newcar[0]);
            strcpy(new.adresse_restaurant, newcar[1]);
            strcpy(new.position_restaurant, newcar[2]);
            strcpy(new.specialite, newcar[3]);

            //printf("%s", new.nom_restaurant);
            memset(newcar, 0, sizeof(newcar));//clear le tableau newcar
            restaurants[j] = new;
            printf("%s\n", restaurants[j].nom_restaurant);
            printf("%s\n", restaurants[j].adresse_restaurant);
            printf("%s\n", restaurants[j].position_restaurant);
            printf("%s\n", restaurants[j].specialite);
            j++;
            

        }
    }
    */
            fclose(frest);
    return j-1;
}

void inserer_restaurant (Restaurant restaurant){
    FILE *frest = fopen("restau.txt", "a");
    if(frest == NULL)
    {printf("Fichier impossible à ouvrir");}
    fprintf(frest, "\n%s; %s; %s; %s;", restaurant.nom_restaurant, restaurant.adresse_restaurant, restaurant.position_restaurant, restaurant.specialite); // On supposera que les position et specialite sont dans le même format que le fichier restau.txt
    fclose(frest);
}

void cherche_restaurant(double x, double y, double rayon_recherche, Restaurant results[]){
    Restaurant liste_restau[max];
    int nb_rest;
    nb_rest = lire_restaurant("restau.txt", liste_restau);
    int ires = 0; // indice de results
    for(int i=0; i<nb_rest; i++){
        double xrest, yrest;
        sscanf(liste_restau[i].position_restaurant, " (x=%lf, y=%lf)", &xrest, &yrest);
        //printf("%lf, %lf", xrest, yrest);
        if(pow(xrest - x, 2)+pow(yrest-y,2) < pow(rayon_recherche, 2)){
            results[ires]=liste_restau[i];
            ires++;
}
}
    printf("\n-----Affichage des résultats----- \n");
    for(int i =0; i<ires;i++){
            printf("Restau : %d, %s \n", i, results[i].nom_restaurant);
                }
}

void cherche_par_specialite(double x, double y, char* specialite[], Restaurant results[]){
    Restaurant liste_restau[max];
    int nb_rest;
    int ires = 0;
    bool added;
    nb_rest = lire_restaurant("restau.txt", liste_restau);
    for(int i=0; i<nb_rest; i++){
        added = false;
        int j = 0;
        while(specialite[j]!=NULL){
            if (!strcmp(liste_restau[i].specialite, specialite[j])&&(added == false)) // on vérifie pour chaque spécialité et on ne rajoute pas 2 fois le restau!
            {
                added = true;
                results[ires] = liste_restau[i];
                ires++;
            }
            j++;
        }
    }

    //for(int i=0; i<ires; i++)
    //{printf("ligne %d, nom : %s", i, results[i].nom_restaurant);}

    Restaurant temp;
    printf("%d", ires); //tri à bulles
    for(int i = 0; i<ires-1; i++){ // pour parcourir tous les éléments de results
        for(int j = 0; j <ires-i-1; j++){
            double xrest, yrest, xrest1, yrest1;
            sscanf(results[j].position_restaurant, " (x=%lf, y=%lf)", &xrest, &yrest); // on récupère les coord du resto
            sscanf(results[j+1].position_restaurant, " (x=%lf, y=%lf)", &xrest1, &yrest1); // on récupère les coord du resto

            //printf("Restaurant : %s et %s \n", results[j].nom_restaurant, results[j+1].nom_restaurant);
            //printf("xrest : %lf, yrest : %lf, xrest1 : %lf, yrest1 : %lf \n", xrest, yrest, xrest1, yrest1);
            //printf("Op1 : %lf \n", sqrt(pow(xrest-x,2)+pow(yrest-y,2)));
            //printf("Op2 : %lf \n", sqrt(pow(xrest1-x,2)+pow(yrest1-y,2)));

            if ( sqrt(pow(xrest-x,2)+pow(yrest-y,2)) > sqrt(pow(xrest1-x,2)+pow(yrest1-y,2)) ){
                temp = results[j];
                results[j] = results[j+1];
                results[j+1] = temp;
            }

    }
    }
    printf("\n-----Affichage des résultats----- \n");
    for(int i =0; i<ires;i++){
                    printf("Restau : %d, %s \n", i, results[i].nom_restaurant);
                }

}

int main()
{

    int choix = 0;
    Restaurant nouveau;
    Restaurant liste[max];
    //lire_restaurant("restau.txt", liste);
    char nom[max];
    char adresse[max];
    char position[max];
    char specialite[max];
    
    while (choix!=4)
    {
        printf("-----------------------MENU-----------------------\n\n");
        printf("1-Insérer un restaurant\n");
        printf("2-Chercher un restaurant (par rayon)\n");
        printf("3-Chercher un restaurant (par spécialité)\n");
        printf("4-Sortir\n");
        scanf("%d", &choix);
        Restaurant results[max];
        switch(choix)
        {
            case 1:
                
                printf(">Entrez le nom du restaurant : ");
                getchar();
                fgets(nom, max, stdin);
                nom[strcspn(nom, "\n")] = 0;
                //printf("%s", nom);
                printf(">Entrez l'adresse du restaurant : ");
                fgets(adresse, max, stdin);
                adresse[strcspn(adresse, "\n")] = 0;
                //printf("%s", adresse);
                printf(">Entrez la position du restaurant (format : (x=valeur, y=valeur) ) : ");
                fgets(position, max, stdin);
                position[strcspn(position, "\n")] = 0;
                printf(">Entrez la spécialité du restaurant (format : {specialite} ) : ");
                fgets(specialite, max, stdin);
                specialite[strcspn(specialite, "\n")] = 0;
                strcpy(nouveau.nom_restaurant, nom);
                strcpy(nouveau.adresse_restaurant, adresse);
                strcpy(nouveau.position_restaurant, position);
                strcpy(nouveau.specialite, specialite);
                inserer_restaurant(nouveau);
                printf("\n Restaurant ajouté ! \n");
                break;
            case 2:
                memset(results, 0, sizeof(results));
                double x, y, rayon;
                printf(">Entrez la coordonnée x de votre position : ");
                scanf("%lf", &x);
                printf(">Entrez la coordonnée y de votre position : ");
                scanf("%lf", &y);
                printf("Entrez le rayon de recherche : ");
                scanf("%lf", &rayon);
                cherche_restaurant(x, y, rayon, results);
                break;
            case 3:
                memset(results, 0, sizeof(results));
                char* specialites_ent[max];
                memset(specialites_ent, 0, sizeof(specialites_ent));
                char spec[max];
                char spec_formatted[max];
                double x2, y2;
                int nb_sp;
                printf(">Entrez la coordonnée x de votre position : ");
                scanf("%lf", &x2);
                printf(">Entrez la coordonnée y de votre position : ");
                scanf("%lf", &y2);
                printf("Entrez le nombre de spécialités à ajouter \n");
                scanf("%d", &nb_sp);
                //getchar();
                viderBuffer();
                for(int i=0; i<nb_sp; i++){
                    printf(">Entrez une spécialité : ");
                    //fgets(spec, max, stdin);
                    //spec[strcspn(spec, "\n")] = 0;
                    lire(spec, 255);
                    sprintf(spec_formatted, " {%s}", spec);
                    specialites_ent[i] = strdup(spec_formatted);
                }
                //for(int i=0; i<nb_sp; i++){printf("%s, %d", specialites_ent[i], i);}
                cherche_par_specialite(x, y, specialites_ent, results);
                for(int i =0; i<nb_sp;i++){
                    free(specialites_ent[i]);
                }

                break;


        }
        //printf("\n >> Pressez une touche pour continuer \n\n");
        //getc(stdin);
    }
    
    /*
    Restaurant liste_restau[max];
    int nb_rest = 0;
    nb_rest = lire_restaurant("restau.txt", liste_restau);
    printf("%d", nb_rest);
    for(int i=0; i<nb_rest; i++){
        printf("Restau : %d, %s \n", i, liste_restau[i].specialite);
    }
    */
    //Restaurant results[max];
    /*
    // pr tester l'ajout
    Restaurant test;
    strcpy(test.nom_restaurant, "honestly nevermind");
    strcpy(test.adresse_restaurant, "Toronto, CA");
    strcpy(test.position_restaurant, "(x=2, y=3)");
    strcpy(test.specialite, "{Drake}");
    inserer_restaurant(test);
    */

    /*
    //pr tester chercher
    cherche_restaurant(48, 2, 1, results);
    for(int i =0; i<nb_rest;i++){
        printf("Restau : %d, %s \n", i, results[i].nom_restaurant);
    }
    */
    /*
    char* specialite[max];
    specialite[0] = " {Cuisine gastronomique}"; //espace avant nécéssaire, à voir pour implémentation menu
    specialite[1] = " {Cuisine marocaine}";
    specialite[2] = " {Bistrot}";
    //printf("%s", specialite[0]);
    cherche_par_specialite(0, 0, specialite, results);
    for(int i=0; i<20;i++){
        printf("Restau : %d, %s \n", i, results[i].nom_restaurant);
    }
    */
    return 0;

}
