#include<stdio.h>
#include<string.h>

#define MaxEtudiant 100

typedef struct {
    char numero[20];
    char nom[50];
    char prenom[50];
    char date_naissance[11];
    char departement[50];
    float note_generale;
} Etudiant;

Etudiant etudiants[MaxEtudiant];
int total = 0;

void ajouteEtudiant() {
    if (total >= MaxEtudiant) {
        printf("Limite d'étudiants atteinte.\n");
        return;
    }
     printf("Entrez le numero unique: ");
    scanf("%s", etudiants[total].numero);
    printf("Entrez le nom: ");
    scanf("%s", etudiants[total].nom);
    printf("Entrez le prenom: ");
    scanf("%s", etudiants[total].prenom);
    printf("Entrez la date de naissance (jj/mm/aaaa): ");
    scanf("%s", etudiants[total].date_naissance);
    printf("Entrez le departement: ");
    scanf("%s",etudiants[total].departement);
    printf("Entrez la note generale: ");
    scanf("%f", &etudiants[total].note_generale);
       total++;
    printf("Etudiant ajoute avec succes.\n");

}

void modifier_etudiant(char numero[50]) {
    for (int i = 0; i < total; i++) {
        if (strcmp(etudiants[i].numero, numero) == 0) {
            printf("Modification des informations de l'etudiant %s:\n", numero);
            printf("Entrez le nouveau nom: ");
            scanf("%s", etudiants[i].nom);
            printf("Entrez le nouveau prenom: ");
            scanf("%s", etudiants[i].prenom);
            printf("Entrez la nouvelle date de naissance (jj/mm/aaaa): ");
            scanf("%s", etudiants[i].date_naissance);
            printf("Entrez le nouveau departement: ");
            scanf("%s", etudiants[i].departement);
            printf("Entrez la nouvelle note generale: ");
            scanf("%f", &etudiants[i].note_generale);
            printf("Etudiant modifie avec succes.\n");
            return;
        }
    }
    printf("Etudiant non trouve.\n");
}

void supprimer_etudiant(char numero[50]) {
    for (int i = 0; i < total; i++) {
        if (strcmp(etudiants[i].numero, numero) == 0) {
            for (int j = i; j < total - 1; j++) {
                etudiants[j] = etudiants[j + 1];
            }
            total--;
            printf("Etudiant supprime avec succes.\n");
            return;
        }
    }
    printf("Etudiant non trouve.\n");
}
void afficher_etudiant(char numero[50]) {
    for (int i = 0; i < total; i++) {
        if (strcmp(etudiants[i].numero, numero) == 0) {
            printf("Details de l'etudiant %s:\n", numero);
            printf("Nom: %s\n", etudiants[i].nom);
            printf("Prenom: %s\n", etudiants[i].prenom);
            printf("Date de naissance: %s\n", etudiants[i].date_naissance);
            printf("Departement: %s\n", etudiants[i].departement);
            printf("Note generale: %.2f\n", etudiants[i].note_generale);
            return;
        }
    }
    printf("Etudiant non trouve.\n");
}
 
 void moyenne_departement(char departement) {
    float somme = 0;
    int count = 0;
    for (int i = 0; i < total; i++) {
        if (strcmp(etudiants[i].departement, departement) == 0) {
            somme += etudiants[i].note_generale;
            count++;
        }
    }
    if (count > 0) {
        printf("Moyenne generale du departement %s: %.2f\n", departement, somme / count);
    } else {
        printf("Aucun etudiant trouve dans le departement %s.\n", departement);
    }
}

void moyenne_universite() {
    float somme = 0;
    for (int i = 0; i < total; i++) {
        somme += etudiants[i].note_generale;
    }
    if (total > 0) {
        printf("Moyenne generale de l'universite: %.2f\n", somme / total);
    } else {
        printf("Aucun etudiant trouve.\n");
    }
}
void nombre_etudiants() {
    printf("Nombre total d'etudiants inscrits: %d\n", total);
}
void Netudiants_par_departement() {
    int math = 0, pc = 0, info = 0, svt = 0, gec = 0;

    for (int i = 0; i < total; i++) {
        if (strcmp(etudiants[i].departement, "Math") == 0) {
            math++;
        } else if (strcmp(etudiants[i].departement, "PC") == 0) {
            pc++;
        } else if (strcmp(etudiants[i].departement, "Info") == 0) {
            info++;
        } else if (strcmp(etudiants[i].departement, "SVT") == 0) {
            svt++;
        } else if (strcmp(etudiants[i].departement, "GEC") == 0) {
            gec++;
        }
    }

    printf("Nombre d'étudiants inscrits dans chaque département:\n");
    printf("Math: %d\n", math);
    printf("PC: %d\n", pc);
    printf("Info: %d\n", info);
    printf("SVT: %d\n", svt);
    printf("GEC: %d\n", gec);
}

void afficher_etudiants_sup(float seuil) {
    printf("Etudiants avec une note generale superieure a %.2f:\n", seuil);
    for (int i = 0; i < total; i++) {
        if (etudiants[i].note_generale > seuil) {
            printf("Nom: %s, Note generale: %.2f\n", etudiants[i].nom, etudiants[i].note_generale);
        }
    }
}
void afficher_meilleurs_etudiants() {
      Etudiant temp;

              for (int i = 0; i < total - 1; i++) {
        for (int j = i + 1; j < total; j++) {
            if (etudiants[i].note_generale < etudiants[j].note_generale) {
                temp = etudiants[i];
                etudiants[i] = etudiants[j];
                etudiants[j] = temp;
            }
        }
    }
    
    printf("Les 3 étudiants ayant les meilleures notes:\n");
    for (int i = 0; i < 3 && i < total; i++) {
        printf("%d. Nom: %s, Prenom: %s, Note générale: %.2f\n", i + 1, etudiants[i].nom, etudiants[i].prenom, etudiants[i].note_generale);
    }

}