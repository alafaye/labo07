/* Fichier : finance.c
 * Auteur  : Alexandre Lafaye
 * Date    : 28.10.2015
 *
 * But     :  Labo07: Calcul d'interets et de taux de conversions
 *
 *
 * Remarque(s) : 
 *
 *
 * Compilateur : g++
 * Debuggueur : gdb
 */
//Pour Windows
//#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define TAUX_CHANGE 1.236

//fonction destinee a calculer et afficher les interets
//en fonction  d'un taux et d'une somme.
void interets_annuels(void){
    double taux_interet, capital, resultat;
    do{
	printf("Taux d'interet (%) :");
	scanf("%lf", &taux_interet);
	fflush(stdin);
	printf("Montant du capital :");
	scanf("%lf", &capital);
	fflush(stdin);
	if(taux_interet < 0 || capital < 0) 
	    printf("L'entree doit etre positive.\n");
    }
    while(taux_interet < 0 || capital < 0);
    resultat = capital + capital * taux_interet/100;
    printf("+=========== INTERETS =========+\n");
    printf("| taux     | %.2f\n", taux_interet);
    printf("| capital  | %.2f\n", capital);
    printf("| resultat | %.2f\n", resultat);
    printf("/n");
}

//fonction destinee a changer une valeur de euro a chf.
void conversion_euro_chf(void){
    double euro, chf;
    do{
    printf("Argent (euro) :");
    scanf("%lf", &euro);
    fflush(stdin);
    	if(euro < 0) 
	    printf("L'entree doit etre positive.\n");
    }
    while(euro < 0);
    chf = euro * TAUX_CHANGE;
    printf("Argent : %lg  chf.\n", chf);
}

//fonction destinee a changer une valeur de chf a euro.
void conversion_chf_euro(void){
    double chf, euro;
    do{
    printf("Argent (chf) :");
    scanf("%lf", &chf);
    fflush(stdin);
    if(chf < 0)
	    printf("L'entree doit etre positive.\n");
    }
    while(chf < 0);
    euro = chf * 1/TAUX_CHANGE;
    printf("Argent : %lg  euro.\n", euro);
}

int main(void) {
    int choix;
    //Boucle principale se repetant tant que l'utilisateur ne
    //sort pas explicitement du programme.
    printf("Programme permettant de calculer un taux d'interet ");
    printf("ou de change a partir d'une somme.\n");
    do
    {
	//Le tableau des choix de fonctionalites.
	printf("============ MENU ============\n");
	printf("1 - Interets annuels.\n");
	printf("2 - Conversion EURO --> CHF.\n");
	printf("3 - Conversion CHF --> EURO.\n");
	printf("0 - Quitter                 \n");
	printf("Choix:");
	scanf("%d", &choix);
	if (choix == 1)
	    interets_annuels();
	else if (choix == 2)
	    conversion_euro_chf();
	else if (choix == 3)
	    conversion_chf_euro();
	else if (choix == 0)
	    printf("Fin du programme");
	else
	    printf("Choix incorrect");
    	fflush(stdin);
	system("PAUSE");
    }
    while(choix!=0);

    return EXIT_SUCCESS;
}
