#include <stdio.h>
# define N 5
/*
Les 'o' pour le nuage des points peuvent être remplacés par des '*' 
pour éviter des bugs d'affichage dans la console.
*/

void saisir_notes(float POINTS[]) {
    int note;
    for (int i = 0; i < N; i++) {
        printf("Entrez la %d eme note : ", i+1);
        scanf("%f", &POINTS[i]);
    }
}

int note_max(float POINTS[]) {
    float max = POINTS[0];
    for (int i = 0; i < N; i++) {
        if (max < POINTS[i]) {
            max = POINTS[i];
        }
    }
    printf("Note Maximale : %.2f\n", max);
    return max;
}

int note_min(float POINTS[]) {
    float min = POINTS[0];
    for (int i = 0; i < N; i++) {
        if (min > POINTS[i]) {
            min = POINTS[i];
        }
    }
    printf("Note Minimum : %.2f\n", min);
    return min;
}


int obtenir_moyenne(float POINTS[]) {
    float moyenne = 0;
    for (int i = 0; i < N; i++) {
        moyenne += POINTS[i];
    }
    moyenne = moyenne / N;
    printf("Moyenne : %.2f\n", moyenne);
    return moyenne;
}

void afficher_notes(float POINTS[]) {
    for (int i = 0; i < N; i++) {
        printf("%.2f\n", POINTS[i]);
    }
}

void repartition_notes(float POINTS[], int NOTES[]) {
    for (int i = 0; i < N; i++) {
        if (POINTS[i] >= 60) {
            //printf("egale a 60 %f\n", POINTS[i]);
            NOTES[6] += 1;
        }

        else if (POINTS[i] >= 50 && POINTS[i] < 60) {
            //printf("%f\n", POINTS[i]);
            NOTES[5] += 1;
        }

        else if (POINTS[i] >= 40 && POINTS[i] < 50) {
            //printf("%f\n", POINTS[i]);
            NOTES[4] += 1;
        }

        else if (POINTS[i] >= 30 && POINTS[i] <= 39) {
            //printf("%f\n", POINTS[i]);
            NOTES[3] += 1;
        }

        else if (POINTS[i] >= 20 && POINTS[i] <= 29){
            //printf("%f\n", POINTS[i]);
            NOTES[2] += 1;
        }

        else if (POINTS[i] >= 10 && POINTS[i] <= 19) {
            //printf("%f\n", POINTS[i]);
            NOTES[1] += 1;
        }

        else {
            //printf("%f\n", POINTS[i]);
            NOTES[0] += 1;
            
        }


    }
}

int max_note(int NOTES[]) {
    int max = 0;
    for (int i = 0; i < 7; i++) {
        //printf("%d", NOTES[i]);
        if (NOTES[i] > max) {
            max = NOTES[i];
        }
    }
    
    return max;
}

void nuage_points(int NOTES[]) {
    /*
        +--------+
    */
    int max = max_note(NOTES);
    int deja_point = 0;
    for (int i = 2*max+1; i >= 0; i--) {
        if (i%2==0 && i != 0) {
            printf("%d >", (int) i/2);
            printf("  ");
            for (int j = 0; j <= 6; j++) {
                if (NOTES[j] == (int) i/2) {
                    if (j == 0) {
                        for (int k = 0; k < 8; k++) {
                            if (k == 4) {
                                printf("°");
                            }
                            else {
                                printf(" ");
                            }
                        }
                    }
                    else {
                        
                        for (int k = 0; k < 10; k++) {
                            if (k == 5) {
                                printf("°");
                            }
                            else {
                                printf(" ");
                            }

                        }
                    }
                }
                else {
                    if (j == 0) {
                        for (int k = 0; k < 8; k++) {
                            printf(" ");
                        }
                    }

                    else {
                        for (int k = 0; k < 10; k++) {
                            printf(" ");

                        }
                    }  
                }
                
                
            }
            printf("\n");
        }
        else {
            printf("\n");
        }
        
    }

    printf("     ");
    for (int i = 0; i < 7; i++) {
        if (i == 0) {
            for (int j = 0; j < 8; j++) {
            if (j == 0) {
                printf("+");
            }
            else {
                if (NOTES[i] == 0 && j == 4) {
                    printf("°");
                }
                else {
                    printf("-");

                }
                
            }
            }
        }
        
        
        else {
            for (int j = 0; j < 10; j++) {
                if (j == 0) {
                    printf("+");
                }
                else {
                    if (NOTES[i] == 0 && j == 5) {
                        printf("°");
                    }
                    else {
                        printf("-");

                    }
                    
                }
            }
        }

        
        
        
    }
    printf("+\n");


    printf("     ");
    int nb1 = 0;
    int nb2 = 9;
    for (int i = 0; i < 7; i++) {
        if (i == 6) {
            printf("|    60   |");
        }
        else {
            printf("| %d - %d ", nb1, nb2);
            if (i == 0) {
                
                nb1 = nb2+1;
                nb2 = 2*nb1-1;
            }
            else {
                nb1 += 10;
                nb2 += 10;
            }
            
            
        }
    }
}

void graphique_batons(int NOTES[]) {
    int max_ = max_note(NOTES);
    printf("\n");
    int deja_point = 0;
    int rien = 0;
    for (int i = 2*max_+1; i >= 0; i--) {
        if (i%2==0 && i != 0) {
            printf("%d >", (int) i/2);
            printf("  ");
            for (int j = 0; j <= 6; j++) {
                if (NOTES[j] >= (int) i/2) {
                    if (j == 0) {
                        for (int k = 0; k < 8; k++) {
                            if (k >= 2 && k <= 5) {
                                printf("#");
                            }
                            else {
                                printf(" ");
                            }
                        }
                    }
                    else {
                        
                        for (int k = 0; k < 10; k++) {
                            if (k >= 2 && k <= 6) {
                                printf("#");
                            }
                            else {
                                printf(" ");
                            }

                        }
                    }
                }
                else {
                    if (j == 0) {
                        for (int k = 0; k < 8; k++) {
                            printf(" ");
                        }
                    }

                    else {
                        for (int k = 0; k < 10; k++) {
                            printf(" ");

                        }
                    }  
                }
                
                
            }
            deja_point = 0;
            rien = 0;
            printf("\n");
        }
        else {
            printf("\n");
        }
        
    }

    printf("     ");
    for (int i = 0; i < 7; i++) {
        if (i == 0) {
            for (int j = 0; j < 8; j++) {
            if (j == 0) {
                printf("+");
            }
            else {
                
                printf("-");

            
                
            }
            }
        }
        
        
        else {
            for (int j = 0; j < 10; j++) {
                if (j == 0) {
                    printf("+");
                }
                else {
                    printf("-");
                    
                }
            }
        }

        
        
        
    }
    printf("+\n");


    printf("     ");
    int nb1 = 0;
    int nb2 = 9;
    for (int i = 0; i < 7; i++) {
        if (i == 6) {
            printf("|    60   |");
        }
        else {
            printf("| %d - %d ", nb1, nb2);
            if (i == 0) {
                
                nb1 = nb2+1;
                nb2 = 2*nb1-1;
            }
            else {
                nb1 += 10;
                nb2 += 10;
            }
            
            
        }
    }

}

void afficher_repartition_notes(int NOTES[]) {
    printf("répartition notes : \n");
    for (int i = 0; i < 7; i++) {
        printf("%d\n", NOTES[i]);
    }
}

int main() {
    //printf("Test\n");
    float POINTS[N] = {0};
    int NOTES[7] = {0};
    saisir_notes(POINTS);
    //afficher_notes(POINTS);
    float max = note_max(POINTS);
    float min = note_min(POINTS);
    float moyenne = obtenir_moyenne(POINTS);
    repartition_notes(POINTS, NOTES);
    //afficher_repartition_notes(NOTES);
    
    nuage_points(NOTES);
    graphique_batons(NOTES);
     

    return 0;
}
