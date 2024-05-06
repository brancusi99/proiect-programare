#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void meniu_principal(){
    printf("Meniu:\n");
    printf("1. Vizualizeaza produsele\n");
    printf("2. Rezerva produs\n");
    printf("3. Adauga produs\n");
    printf("4. Sterge produs\n");
    printf("5. Cauta produs\n");
    printf("6. Arata produse rezervate\n");
    printf("7. Exit\n");
}

void rezervare(char path[], char path2[]){
    FILE *fp_output;
    fp_output = fopen(path, "r+");
    FILE *fp2_output;
    fp2_output = fopen(path2, "a+");
    FILE *temp_output;
    temp_output = fopen("temp.txt", "w");

    char linie[50], temp[512];
    if(fp_output == NULL || fp2_output == NULL || temp_output == NULL){
        printf("Eroare!");
        printf("1. Back\n");
        printf("2. Exit\n");
        }
    else{
        while(fgets(temp, 512, fp_output))
            if(temp[0] != '\n'){
                temp[strcspn(temp, "\n")] = '\0';
                printf("- %s\n", temp);
            }
        printf("\n");
        printf("Apasati 1 pentru a anula.\n\n");
        printf("Ce produs doriti sa imprumutati?\n");
        scanf("%s", &linie);

            if(linie[0] == '1'){
                fclose(fp_output);
                fclose(fp2_output);
                fclose(temp_output);
                int n = 0;
                meniu(n, path, path2);
            }

        rewind(fp_output);

        fprintf(fp2_output, "%s", linie);

        while(fgets(temp, 512, fp_output)){
            if(strstr(temp, linie) == NULL)
                fprintf(temp_output, "%s", temp);
        }

        fclose(fp_output);
        fclose(fp2_output);
        fclose(temp_output);

        remove(path);
        rename("temp.txt", path);

    }
}


void sterge(char path[], char path2[]){
    FILE *fp_output;
    fp_output = fopen(path, "r+");
    FILE *temp_output;
    temp_output = fopen("temp.txt", "w");

    char linie[50], temp[512];
    if(fp_output == NULL || temp_output == NULL){
        printf("Eroare!\n");
        printf("1. Back\n");
        printf("2. Exit\n");
}
    else{
            while(fgets(temp, 512, fp_output))
                if(temp[0] != '\n'){
                    temp[strcspn(temp, "\n")] = '\0';
                    printf("- %s\n", temp);
                }
        printf("Apasati 1 pentru a anula\n");
        printf("\n");
        printf("Ce produs doriti sa stergeti?\n");
        scanf("%s", &linie);

        if(linie[0] == '1'){
                fclose(fp_output);
                fclose(temp_output);
                int n = 0;
                meniu(n, path, path2);
            }

        rewind(fp_output);
        while(fgets(temp, 512, fp_output) != NULL){
                //printf("%s", temp);
                //printf("%s", linie);
            if(strstr(temp, linie) == NULL){
                //4printf("ceva");
               fprintf(temp_output, "%s", temp);
            }
        }
    fclose(fp_output);
    fclose(temp_output);
    remove(path);
    rename("temp.txt", path);
    }
}

void cauta_produs(char path[], char path2[]){
    FILE *fp_output;
    fp_output = fopen(path, "r");

    int aux = 1;
    char linie[50], temp[512];
    if(fp_output == NULL){
        printf("Eroare!\n");
        printf("1. Back\n");
        printf("2. Exit\n");
    }
    else{
            while(fgets(linie, 50, fp_output))
                if(linie[0] != '\n'){
                    linie[strcspn(linie, "\n")] = '\0';
                    printf("- %s\n", linie);
                }
        printf("Apasati 1 pentru a anula\n\n");
        printf("Ce produs cautati?\n");
        scanf("%s", &linie);

        if(linie[0] == '1'){
                fclose(fp_output);
                int n = 0;
                meniu(n, path, path2);
            }

        while(fgets(temp, 512, fp_output)){

            if(strstr(temp, linie) != NULL){
                printf("Produsul a fost gasit pe linia %d\n", aux);
                printf("- %s", temp);
                break;
            }
            aux++;
        }
    }
    fclose(fp_output);
    printf("\n");
}

void adaugare(char path[], char path2[]){
    FILE *fp_output;
    fp_output = fopen(path, "a+");

    int aux = 0;
    char linie[50], temp[512];
    if(fp_output == NULL){
        printf("Eroare!\n");
        printf("1. Back\n");
        printf("2. Exit\n");
    }
    else{
            while(fgets(temp, 512, fp_output))
            if(temp[0] != '\n'){
                temp[strcspn(temp, "\n")] = '\0';
                printf("- %s\n", temp);
            }
        printf("Apasati 1 pentru a anula\n");
        printf("\n");
        printf("Ce produs doriti sa adaugati?\n");
        scanf("%s", &linie);

        if(linie[0] == '1'){
                fclose(fp_output);
                int n = 0;
                meniu(n, path, path2);
            }

        while(fgets(temp, 512, fp_output)){

            if(strstr(temp, linie) != NULL){
                printf("Produsul deja exista\n");
                aux++;
                break;
            }
    }
     if(aux == 0)
            fprintf(fp_output, "%s", linie);
    fclose(fp_output);
     printf("\n");
}
}

void afisare_rezervate(int y, char path2[]){
    int optiune = 0;
    FILE *fp2_output;
    fp2_output = fopen(path2, "r");

    char linie[50];
     while(optiune != 1){
                if(y == 6){
        if(fp2_output == NULL){
            printf("Fisierul nu poate fi accesat\n");
            printf("1. Back\n");
            printf("2. Exit\n");
                }
        else{
            while(fgets(linie, 50, fp2_output)){
                if(linie[0] != '\n'){
                    linie[strcspn(linie, "\n")] = '\0';
                    printf("- %s\n", linie);
                }
            }
            printf("1. Back\n");
            printf("2. Exit\n");
            }
            fclose(fp2_output);
            scanf("%d", &optiune);
        if(optiune == 1)
            printf("\n");
        else if(optiune == 2)
            exit(0);
        else
            printf("Nu exista optiunea\n");
        }
                }

}

void afisare(int y, char path[]){
    int optiune = 0;
    FILE *fp_output;
    fp_output = fopen(path, "r");

    char linie[50];

        while(optiune != 1){
                if(y == 1){
        if(fp_output == NULL){
            printf("Fisierul nu poate fi accesat\n");
            printf("1. Back\n");
            printf("2. Exit\n");
        }
        else{
            while(fgets(linie, 50, fp_output)){
                if(linie[0] != '\n'){
                    linie[strcspn(linie, "\n")] = '\0';
                    printf("- %s\n", linie);
                }
            }
            printf("1. Back\n");
            printf("2. Exit\n");
            }
            fclose(fp_output);
            scanf("%d", &optiune);
        if(optiune == 1)
            printf("\n");
        else if(optiune == 2)
            exit(0);
        else
            printf("Nu exista optiunea\n");
        }
                }

        }


void meniu(int n, char path[], char path2[]){
    while(n != 7){
    meniu_principal();

    scanf("%d", &n);
    switch(n){
    case 1:;
        afisare(1, path);
        break;
    case 2:;
        rezervare(path, path2);
        break;
    case 3:;
        adaugare(path, path2);
        break;
    case 4:;
        sterge(path, path2);
        break;
    case 5:;
        cauta_produs(path, path2);
        break;
    case 6:;
        afisare_rezervate(6, path2);
        break;
    case 7:
        exit(0);
    default:
        printf("Nu exista optiunea\n");
    }
    }
}

int main()
{
    char path[] = "produse.txt";
    char path2[] = "rezervate.txt";
    int n = 0;

    meniu(n, path, path2);

    return 0;
}
