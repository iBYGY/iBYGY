#include <stdio.h>
#include <stdlib.h>
#define o_UMLAUT 148
#define u_UMLAUT 129
#define s_UMLAUT 225
#define a_UMLAUT 132
#define ZEILEN 11
#define SPALTEN 11
#define SHIP_FIELD_COUNT 20 // 'x'-Felder Anzahl
/* ------------------------------------------------------------------------------------*/
/* Globale variablen feldsp1/2 für placements & spielfeldsp1/2 für das spiel; */
char feldsp1[ZEILEN][SPALTEN] , feldsp2[ZEILEN][SPALTEN] , spielfeldsp1[ZEILEN][SPALTEN] , spielfeldsp2[ZEILEN][SPALTEN] ;
/* ------------------------------------------------------------------------------------*/
/* Funktionsprototyp zum Anzeigen der Spielregeln; */
void welcomescreen();
/* ------------------------------------------------------------------------------------*/
/* Funktionsprototypen zum Anzeigen der Positionierungsfelder / Für Spieler 1 und Spieler 2; */
void brettsp1();
void brettsp2();
/* ------------------------------------------------------------------------------------*/
/* Funktionsprototypen zum Anzeigen der Spielfelder / Für Spieler 1 und Spieler 2; */
void spielbrettsp1();
void spielbrettsp2();
/* ------------------------------------------------------------------------------------*/
/* Funktionsprototypen zum Platzieren der Schiffe; */
void platzsp1();
void platzsp2();
/* ------------------------------------------------------------------------------------*/

/* ------------------------------------------------------------------------------------*/
/* Hauptspielfunktion;*/
int main()
{
/* ------------------------------------------------------------------------------------*/
    int getroffensp1 = 0 , getroffensp2 = 0 ;
    int verfehltsp1 = 0 , verfehltsp2 = 0 ;
/* ----- Initialisierung der Spielfelder ----- */
    feldsp1[0][0] = ' ' ; feldsp1[0][1] = '0' ; feldsp1[0][2] = '1' ; feldsp1[0][3] = '2' ; feldsp1[0][4] = '3' ; feldsp1[0][5] = '4' ; feldsp1[0][6] = '5' ; feldsp1[0][7] = '6' ; feldsp1[0][8] = '7' ; feldsp1[0][9] = '8' ; feldsp1[0][10] = '9' ;
    feldsp1[1][0] = 'A' ; feldsp1[2][0] = 'B' ; feldsp1[3][0] = 'C' ; feldsp1[4][0] = 'D' ; feldsp1[5][0] = 'E' ; feldsp1[6][0] = 'F' ; feldsp1[7][0] = 'G' ; feldsp1[8][0] = 'H' ; feldsp1[9][0] = 'I' ; feldsp1[10][0] = 'J' ;
    spielfeldsp1[0][0] = ' ' ; spielfeldsp1[0][1] = '0' ; spielfeldsp1[0][2] = '1' ; spielfeldsp1[0][3] = '2' ; spielfeldsp1[0][4] = '3' ; spielfeldsp1[0][5] = '4' ; spielfeldsp1[0][6] = '5' ; spielfeldsp1[0][7] = '6' ; spielfeldsp1[0][8] = '7' ; spielfeldsp1[0][9] = '8' ; spielfeldsp1[0][10] = '9' ;
    spielfeldsp1[1][0] = 'A' ; spielfeldsp1[2][0] = 'B' ; spielfeldsp1[3][0] = 'C' ; spielfeldsp1[4][0] = 'D' ; spielfeldsp1[5][0] = 'E' ; spielfeldsp1[6][0] = 'F' ; spielfeldsp1[7][0] = 'G' ; spielfeldsp1[8][0] = 'H' ; spielfeldsp1[9][0] = 'I' ; spielfeldsp1[10][0] = 'J' ;

    feldsp2[0][0] = ' ' ; feldsp2[0][1] = '0' ; feldsp2[0][2] = '1' ; feldsp2[0][3] = '2' ; feldsp2[0][4] = '3' ; feldsp2[0][5] = '4' ; feldsp2[0][6] = '5' ; feldsp2[0][7] = '6' ; feldsp2[0][8] = '7' ; feldsp2[0][9] = '8' ; feldsp2[0][10] = '9' ;
    feldsp2[1][0] = 'A' ; feldsp2[2][0] = 'B' ; feldsp2[3][0] = 'C' ; feldsp2[4][0] = 'D' ; feldsp2[5][0] = 'E' ; feldsp2[6][0] = 'F' ; feldsp2[7][0] = 'G' ; feldsp2[8][0] = 'H' ; feldsp2[9][0] = 'I' ; feldsp2[10][0] = 'J' ;
    spielfeldsp2[0][0] = ' ' ; spielfeldsp2[0][1] = '0' ; spielfeldsp2[0][2] = '1' ; spielfeldsp2[0][3] = '2' ; spielfeldsp2[0][4] = '3' ; spielfeldsp2[0][5] = '4' ; spielfeldsp2[0][6] = '5' ; spielfeldsp2[0][7] = '6' ; spielfeldsp2[0][8] = '7' ; spielfeldsp2[0][9] = '8' ; spielfeldsp2[0][10] = '9' ;
    spielfeldsp2[1][0] = 'A' ; spielfeldsp2[2][0] = 'B' ; spielfeldsp2[3][0] = 'C' ; spielfeldsp2[4][0] = 'D' ; spielfeldsp2[5][0] = 'E' ; spielfeldsp2[6][0] = 'F' ; spielfeldsp2[7][0] = 'G' ; spielfeldsp2[8][0] = 'H' ; spielfeldsp2[9][0] = 'I' ; spielfeldsp2[10][0] = 'J' ;
/* ------------------------------------------------------------------------------------*/
welcomescreen() ;
/* ------------------------------------------------------------------------------------*/
platzsp1(); // Funktion für Spieler1 um die Schiffe zu platzieren.
system("CLS");
platzsp2(); //Funktion für Spieler2 um die Schiffe zu platzieren.
system("cls");
/* ------------------------------------------------------------------------------------*/
/* Initialisierung der Spielfelder für Spieler 1 und 2; */
    for(int i=1 ; i < ZEILEN ; i++){
        for(int j=1 ; j < SPALTEN ; j++){
            spielfeldsp1[i][j] = 63 ;
        }
    }

    for(int i=1 ; i < ZEILEN ; i++){
        for(int j=1 ; j < SPALTEN ; j++){
            spielfeldsp2[i][j] = 63 ;
        }
    }
/* ------------------------------------------------------------------------------------*/
    char yRicht ,yRicht2 , xRicht , xRicht2 ;
    do{
        do{
            spielbrettsp1();
            printf("\nW%chlen Sie die Startreihe der Abfrage (a-j) : ",a_UMLAUT);
            scanf("%c",&yRicht);
            fflush(stdin);
            printf("\nW%chlen Sie die Startzelle der Abfrage (0-9) : ",a_UMLAUT);
            scanf("%c",&xRicht);
            fflush(stdin);
            if(feldsp2[yRicht-96][xRicht-47] == 120)
            {
                printf("\nTreffer");
                spielfeldsp1[yRicht-96][xRicht-47] =  103 ;
                getroffensp1 += 1 ;
            }
            else
            {
                printf("\nWasser");
                spielfeldsp1[yRicht-96][xRicht-47] = 126 ;
                verfehltsp1 += 1;
            }
        }while(feldsp2[yRicht-96][xRicht-47] != 95);

        do{
            spielbrettsp2();
            printf("\nW%chlen Sie die Startreihe der Abfrage (a-j) : ",a_UMLAUT);
            scanf("%c",&yRicht2);
            fflush(stdin);
            printf("\nW%chlen Sie die Startzelle der Abfrage (0-9) : ",a_UMLAUT);
            scanf("%c",&xRicht2);
            fflush(stdin);
            if(feldsp1[yRicht2-96][xRicht2-47] == 120)
            {
                printf("\nTreffer");
                spielfeldsp2[yRicht2-96][xRicht2-47] =  103 ;
                getroffensp2 += 1 ;
            }
            else
            {
                printf("\nWasser");
                spielfeldsp2[yRicht2-96][xRicht2-47] = 126 ;
                verfehltsp2 += 1;
            }
        }while(feldsp1[yRicht2-96][xRicht-47] != 95);

    }while((getroffensp1 != SHIP_FIELD_COUNT) || (getroffensp2 != SHIP_FIELD_COUNT));

    if(getroffensp1 == SHIP_FIELD_COUNT){
        printf("\nGratulation zum Sieg Spieler 1 !!");
    }
    else if(getroffensp2 == SHIP_FIELD_COUNT){
        printf("\nGratulation zum Sieg Spieler 2 !!");
    }

}
/* ------------------------------------------------------------------------------------*/

/* ------------------------------------------------------------------------------------*/
/* Funktion zum Anzeigen der Spielregeln */
void welcomescreen()
{
    char enter ;
    printf("\nRICHTIG DURCHLESEN UM DAS SPIEL KORREKT ZU SPIELEN BITTE \n\n"
           "\nWillkommen zum Spiel Schiffe Versenken !\n"
           "\nJeder Spieler hat sein eigenes Rasterfeld der Gr%c%ce 10x10"
           "\nJeder Spieler positioniert 10 Schiffe\n"
           "\n 1 Schiff  der L%cnge 4"
           "\n 2 Schiffe der L%cnge 3"
           "\n 3 Schiffe der L%cnge 2"
           "\n 4 Schiffe der L%cnge 1\n"
           "\nWichtig dabei ist die Schiffe richtig zu positionieren"
           "\nDie Schiffe m%cssen waagerecht oder senkrecht positioniert sein"
           "\nD%crfen einander nicht waagerecht oder senkrecht ber%chren (wohl aber diagonal)"
           "\nEigentliches Spiel beginnt wenn jeder Spieler seine Schiffe positioniert hat"
           "\nJeder Spieler darf im Wechsel auf ein Feld des Gegners 'schie%cen', z.B. 'a8' "
           "\nTrifft er, erh%clt er Antwort 'Treffer' "
           "\nIst durch Treffer letzte unbesch%cdigte Feld des Schiffes getroffen,Antwort 'Versenkt' "
           "\nVerfehlter Schuss, Antwort 'Wasser' "
           "\nSpieler solange dran, bis er sein Ziel verfehlt"
           "\nnun ist der Gegner an der Reihe"
           "\nSieger: Wer zuerst alle Schiffe des Gegners versenkt\n"
            ,o_UMLAUT,s_UMLAUT,a_UMLAUT,a_UMLAUT,a_UMLAUT,a_UMLAUT,u_UMLAUT,u_UMLAUT,u_UMLAUT,s_UMLAUT,a_UMLAUT);

    printf("\n\nDr%ccken Sie Enter um fortzufahren : ",u_UMLAUT);
    scanf("%c",&enter);
}
/* ------------------------------------------------------------------------------------*/
/* Funktionen zum Anzeigen der Positionierungsfelder / Für Spieler 1 und Spieler 2 */
void brettsp1()
{
    int i , j ;
    printf("\n\tSpieler 1");
    for(i = 0 ; i < ZEILEN ; i++ ){
        printf("\n");
        for(j = 0 ; j < SPALTEN ; j++){
            printf("%c ",feldsp1[i][j]);
        }
    }
    printf("\n");
}

void brettsp2()
{
    int i , j ;
    printf("\n\tSpieler 2");
    for(i = 0 ; i < ZEILEN ; i++ ){
        printf("\n");
        for(j = 0 ; j < SPALTEN ; j++){
            printf("%c ",feldsp2[i][j]);
        }
    }
    printf("\n");
}
/* ------------------------------------------------------------------------------------*/
/* Funktionen zum Anzeigen der Spielfelder / Für Spieler 1 und Spieler 2 */
void spielbrettsp1(){
    int i , j ;
    printf("\n\tSpieler 1");
    for(i = 0 ; i < ZEILEN ; i++ ){
        printf("\n");
        for(j = 0 ; j < SPALTEN ; j++){
            printf("%c ",spielfeldsp1[i][j]);
        }
    }
    printf("\n");
}

void spielbrettsp2(){
    int i , j ;
    printf("\n\tSpieler 2");
    for(i = 0 ; i < ZEILEN ; i++ ){
        printf("\n");
        for(j = 0 ; j < SPALTEN ; j++){
            printf("%c ",spielfeldsp2[i][j]);
        }
    }
    printf("\n");
}
/* ------------------------------------------------------------------------------------*/
/* Funktionen zum Platzieren der Schiffe / Für Spieler 1 und Spieler 2 */
void platzsp1()
{
    int i , j ;
    char lage ;
    char yRicht ;
    char xRicht ;
    for(i=1 ; i < 11 ; i++){
        for(j=1 ; j < 11 ; j++){
            feldsp1[i][j] = 95 ;
        }
    }

    brettsp1() ;

    printf("\nPositionierungsphase des 4er Schiffs");
    printf("\nW%chlen Sie ob (h)orizontal oder (v)ertikal : ",a_UMLAUT);
    scanf("%c",&lage);
    fflush(stdin);
    printf("\nW%chlen Sie die Startreihe (a-j) : ",a_UMLAUT);
    scanf("%c",&yRicht);
    fflush(stdin);
    printf("\nW%chlen Sie die Startzelle (0-9) : ",a_UMLAUT);
    scanf("%c",&xRicht);
    fflush(stdin);

    if(lage == 104)
    {
        feldsp1[yRicht-96][xRicht-47] = 120 ;
        feldsp1[yRicht-96][xRicht-46] = 120 ;
        feldsp1[yRicht-96][xRicht-45] = 120 ;
        feldsp1[yRicht-96][xRicht-44] = 120 ;
    }
    else if(lage == 118)
    {
        feldsp1[yRicht-96][xRicht-47] = 120 ;
        feldsp1[yRicht-95][xRicht-47] = 120 ;
        feldsp1[yRicht-94][xRicht-47] = 120 ;
        feldsp1[yRicht-93][xRicht-47] = 120 ;
    }
    brettsp1();
/* ------------------------------------------------------------------------------------*/
    printf("\nPositionierungsphase des 3er Schiffs - 2 Mal !");
    printf("\nW%chlen Sie ob (h)orizontal oder (v)ertikal : ",a_UMLAUT);
    scanf("%c",&lage);
    fflush(stdin);
    printf("\nW%chlen Sie die Startreihe (a-j) : ",a_UMLAUT);
    scanf("%c",&yRicht);
    fflush(stdin);
    printf("\nW%chlen Sie die Startzelle (0-9) : ",a_UMLAUT);
    scanf("%c",&xRicht);
    fflush(stdin);

    if(lage == 104)
    {
        feldsp1[yRicht-96][xRicht-47] = 120 ;
        feldsp1[yRicht-96][xRicht-46] = 120 ;
        feldsp1[yRicht-96][xRicht-45] = 120 ;
    }
    else if(lage == 118)
    {
        feldsp1[yRicht-96][xRicht-47] = 120 ;
        feldsp1[yRicht-95][xRicht-47] = 120 ;
        feldsp1[yRicht-94][xRicht-47] = 120 ;
    }
    brettsp1();

    printf("\nW%chlen Sie ob (h)orizontal oder (v)ertikal : ",a_UMLAUT);
    scanf("%c",&lage);
    fflush(stdin);
    printf("\nW%chlen Sie die Startreihe (a-j) : ",a_UMLAUT);
    scanf("%c",&yRicht);
    fflush(stdin);
    printf("\nW%chlen Sie die Startzelle (0-9) : ",a_UMLAUT);
    scanf("%c",&xRicht);
    fflush(stdin);

    if(lage == 104)
    {
        feldsp1[yRicht-96][xRicht-47] = 120 ;
        feldsp1[yRicht-96][xRicht-46] = 120 ;
        feldsp1[yRicht-96][xRicht-45] = 120 ;
    }
    else if(lage == 118)
    {
        feldsp1[yRicht-96][xRicht-47] = 120 ;
        feldsp1[yRicht-95][xRicht-47] = 120 ;
        feldsp1[yRicht-94][xRicht-47] = 120 ;
    }
    brettsp1();
/* ------------------------------------------------------------------------------------*/
    printf("\nPositionierungsphase des 2er Schiffs - 3 Mal !");
    printf("\nW%chlen Sie ob (h)orizontal oder (v)ertikal : ",a_UMLAUT);
    scanf("%c",&lage);
    fflush(stdin);
    printf("\nW%chlen Sie die Startreihe (a-j) : ",a_UMLAUT);
    scanf("%c",&yRicht);
    fflush(stdin);
    printf("\nW%chlen Sie die Startzelle (0-9) : ",a_UMLAUT);
    scanf("%c",&xRicht);
    fflush(stdin);

    if(lage == 104)
    {
        feldsp1[yRicht-96][xRicht-47] = 120 ;
        feldsp1[yRicht-96][xRicht-46] = 120 ;
    }
    else if(lage == 118)
    {
        feldsp1[yRicht-96][xRicht-47] = 120 ;
        feldsp1[yRicht-95][xRicht-47] = 120 ;
    }
    brettsp1();

    printf("\nW%chlen Sie ob (h)orizontal oder (v)ertikal : ",a_UMLAUT);
    scanf("%c",&lage);
    fflush(stdin);
    printf("\nW%chlen Sie die Startreihe (a-j) : ",a_UMLAUT);
    scanf("%c",&yRicht);
    fflush(stdin);
    printf("\nW%chlen Sie die Startzelle (0-9) : ",a_UMLAUT);
    scanf("%c",&xRicht);
    fflush(stdin);

    if(lage == 104)
    {
        feldsp1[yRicht-96][xRicht-47] = 120 ;
        feldsp1[yRicht-96][xRicht-46] = 120 ;
    }
    else if(lage == 118)
    {
        feldsp1[yRicht-96][xRicht-47] = 120 ;
        feldsp1[yRicht-95][xRicht-47] = 120 ;
    }
    brettsp1();

    printf("\nW%chlen Sie ob (h)orizontal oder (v)ertikal : ",a_UMLAUT);
    scanf("%c",&lage);
    fflush(stdin);
    printf("\nW%chlen Sie die Startreihe (a-j) : ",a_UMLAUT);
    scanf("%c",&yRicht);
    fflush(stdin);
    printf("\nW%chlen Sie die Startzelle (0-9) : ",a_UMLAUT);
    scanf("%c",&xRicht);
    fflush(stdin);

    if(lage == 104)
    {
        feldsp1[yRicht-96][xRicht-47] = 120 ;
        feldsp1[yRicht-96][xRicht-46] = 120 ;
    }
    else if(lage == 118)
    {
        feldsp1[yRicht-96][xRicht-47] = 120 ;
        feldsp1[yRicht-95][xRicht-47] = 120 ;
    }
    brettsp1();
/* ------------------------------------------------------------------------------------*/
    printf("\nPositionierungsphase des 1er Schiffs - 4 Mal !");

    printf("\nW%chlen Sie die Startreihe (a-j) : ",a_UMLAUT);
    scanf("%c",&yRicht);
    fflush(stdin);
    printf("\nW%chlen Sie die Startzelle (0-9) : ",a_UMLAUT);
    scanf("%c",&xRicht);
    fflush(stdin);
    feldsp1[yRicht-96][xRicht-47] = 120 ;
    brettsp1();

    printf("\nW%chlen Sie die Startreihe (a-j) : ",a_UMLAUT);
    scanf("%c",&yRicht);
    fflush(stdin);
    printf("\nW%chlen Sie die Startzelle (0-9) : ",a_UMLAUT);
    scanf("%c",&xRicht);
    fflush(stdin);
    feldsp1[yRicht-96][xRicht-47] = 120 ;
    brettsp1();

    printf("\nW%chlen Sie die Startreihe (a-j) : ",a_UMLAUT);
    scanf("%c",&yRicht);
    fflush(stdin);
    printf("\nW%chlen Sie die Startzelle (0-9) : ",a_UMLAUT);
    scanf("%c",&xRicht);
    fflush(stdin);
    feldsp1[yRicht-96][xRicht-47] = 120 ;
    brettsp1();

    printf("\nW%chlen Sie die Startreihe (a-j) : ",a_UMLAUT);
    scanf("%c",&yRicht);
    fflush(stdin);
    printf("\nW%chlen Sie die Startzelle (0-9) : ",a_UMLAUT);
    scanf("%c",&xRicht);
    fflush(stdin);
    feldsp1[yRicht-96][xRicht-47] = 120 ;
    brettsp1();


/* ------------------------------------------------------------------------------------*/
}

void platzsp2()
{
    int k ,o ;
    char lage ;
    char yRicht ;
    char xRicht ;

    for(k=1 ; k < ZEILEN ; k++){
        for(o=1 ; o < SPALTEN ; o++){
            feldsp2[k][o] = 95 ;
        }
    }

    brettsp2() ;
/* ------------------------------------------------------------------------------------*/
    printf("\nPositionierungsphase des 4er Schiffs");
    printf("\nW%chlen Sie ob (h)orizontal oder (v)ertikal : ",a_UMLAUT);
    scanf("%c",&lage);
    fflush(stdin);
    printf("\nW%chlen Sie die Startreihe (a-j) : ",a_UMLAUT);
    scanf("%c",&yRicht);
    fflush(stdin);
    printf("\nW%chlen Sie die Startzelle (0-9) : ",a_UMLAUT);
    scanf("%c",&xRicht);
    fflush(stdin);

    if(lage == 104)
    {
        feldsp2[yRicht-96][xRicht-47] = 120 ;
        feldsp2[yRicht-96][xRicht-46] = 120 ;
        feldsp2[yRicht-96][xRicht-45] = 120 ;
        feldsp2[yRicht-96][xRicht-44] = 120 ;
    }
    else if(lage == 118)
    {
        feldsp2[yRicht-96][xRicht-47] = 120 ;
        feldsp2[yRicht-95][xRicht-47] = 120 ;
        feldsp2[yRicht-94][xRicht-47] = 120 ;
        feldsp2[yRicht-93][xRicht-47] = 120 ;
    }
    brettsp2();
/* ------------------------------------------------------------------------------------*/
    printf("\nPositionierungsphase des 3er Schiffs - 2 Mal !");
    printf("\nW%chlen Sie ob (h)orizontal oder (v)ertikal : ",a_UMLAUT);
    scanf("%c",&lage);
    fflush(stdin);
    printf("\nW%chlen Sie die Startreihe (a-j) : ",a_UMLAUT);
    scanf("%c",&yRicht);
    fflush(stdin);
    printf("\nW%chlen Sie die Startzelle (0-9) : ",a_UMLAUT);
    scanf("%c",&xRicht);
    fflush(stdin);

    if(lage == 104)
    {
        feldsp2[yRicht-96][xRicht-47] = 120 ;
        feldsp2[yRicht-96][xRicht-46] = 120 ;
        feldsp2[yRicht-96][xRicht-45] = 120 ;

    }
    else if(lage == 118)
    {
        feldsp2[yRicht-96][xRicht-47] = 120 ;
        feldsp2[yRicht-95][xRicht-47] = 120 ;
        feldsp2[yRicht-94][xRicht-47] = 120 ;

    }
    brettsp2();
/* ------------------------------------------------------------------------------------*/
    printf("\nW%chlen Sie ob (h)orizontal oder (v)ertikal : ",a_UMLAUT);
    scanf("%c",&lage);
    fflush(stdin);
    printf("\nW%chlen Sie die Startreihe (a-j) : ",a_UMLAUT);
    scanf("%c",&yRicht);
    fflush(stdin);
    printf("\nW%chlen Sie die Startzelle (0-9) : ",a_UMLAUT);
    scanf("%c",&xRicht);
    fflush(stdin);

    if(lage == 104)
    {
        feldsp2[yRicht-96][xRicht-47] = 120 ;
        feldsp2[yRicht-96][xRicht-46] = 120 ;
        feldsp2[yRicht-96][xRicht-45] = 120 ;

    }
    else if(lage == 118)
    {
        feldsp2[yRicht-96][xRicht-47] = 120 ;
        feldsp2[yRicht-95][xRicht-47] = 120 ;
        feldsp2[yRicht-94][xRicht-47] = 120 ;

    }
    brettsp2();
/* ------------------------------------------------------------------------------------*/
    printf("\nPositionierungsphase des 2er Schiffs - 3 Mal !");
    printf("\nW%chlen Sie ob (h)orizontal oder (v)ertikal : ",a_UMLAUT);
    scanf("%c",&lage);
    fflush(stdin);
    printf("\nW%chlen Sie die Startreihe (a-j) : ",a_UMLAUT);
    scanf("%c",&yRicht);
    fflush(stdin);
    printf("\nW%chlen Sie die Startzelle (0-9) : ",a_UMLAUT);
    scanf("%c",&xRicht);
    fflush(stdin);

    if(lage == 104)
    {
        feldsp2[yRicht-96][xRicht-47] = 120 ;
        feldsp2[yRicht-96][xRicht-46] = 120 ;
    }
    else if(lage == 118)
    {
        feldsp2[yRicht-96][xRicht-47] = 120 ;
        feldsp2[yRicht-95][xRicht-47] = 120 ;
    }
    brettsp2();
/* ------------------------------------------------------------------------------------*/
    printf("\nW%chlen Sie ob (h)orizontal oder (v)ertikal : ",a_UMLAUT);
    scanf("%c",&lage);
    fflush(stdin);
    printf("\nW%chlen Sie die Startreihe (a-j) : ",a_UMLAUT);
    scanf("%c",&yRicht);
    fflush(stdin);
    printf("\nW%chlen Sie die Startzelle (0-9) : ",a_UMLAUT);
    scanf("%c",&xRicht);
    fflush(stdin);

    if(lage == 104)
    {
        feldsp2[yRicht-96][xRicht-47] = 120 ;
        feldsp2[yRicht-96][xRicht-46] = 120 ;
    }
    else if(lage == 118)
    {
        feldsp2[yRicht-96][xRicht-47] = 120 ;
        feldsp2[yRicht-95][xRicht-47] = 120 ;
    }
    brettsp2();
/* ------------------------------------------------------------------------------------*/
    printf("\nW%chlen Sie ob (h)orizontal oder (v)ertikal : ",a_UMLAUT);
    scanf("%c",&lage);
    fflush(stdin);
    printf("\nW%chlen Sie die Startreihe (a-j) : ",a_UMLAUT);
    scanf("%c",&yRicht);
    fflush(stdin);
    printf("\nW%chlen Sie die Startzelle (0-9) : ",a_UMLAUT);
    scanf("%c",&xRicht);
    fflush(stdin);

    if(lage == 104)
    {
        feldsp2[yRicht-96][xRicht-47] = 120 ;
        feldsp2[yRicht-96][xRicht-46] = 120 ;
    }
    else if(lage == 118)
    {
        feldsp2[yRicht-96][xRicht-47] = 120 ;
        feldsp2[yRicht-95][xRicht-47] = 120 ;
    }
    brettsp2();
/* ------------------------------------------------------------------------------------*/
    printf("\nPositionierungsphase des 1er Schiffs - 4 Mal !");

    printf("\nW%chlen Sie die Startreihe (a-j) : ",a_UMLAUT);
    scanf("%c",&yRicht);
    fflush(stdin);
    printf("\nW%chlen Sie die Startzelle (0-9) : ",a_UMLAUT);
    scanf("%c",&xRicht);
    fflush(stdin);
    feldsp2[yRicht-96][xRicht-47] = 120 ;
    brettsp2();
/* ------------------------------------------------------------------------------------*/
    printf("\nW%chlen Sie die Startreihe (a-j) : ",a_UMLAUT);
    scanf("%c",&yRicht);
    fflush(stdin);
    printf("\nW%chlen Sie die Startzelle (0-9) : ",a_UMLAUT);
    scanf("%c",&xRicht);
    fflush(stdin);
    feldsp2[yRicht-96][xRicht-47] = 120 ;
    brettsp2();
/* ------------------------------------------------------------------------------------*/
    printf("\nW%chlen Sie die Startreihe (a-j) : ",a_UMLAUT);
    scanf("%c",&yRicht);
    fflush(stdin);
    printf("\nW%chlen Sie die Startzelle (0-9) : ",a_UMLAUT);
    scanf("%c",&xRicht);
    fflush(stdin);
    feldsp2[yRicht-96][xRicht-47] = 120 ;
    brettsp2();
/* ------------------------------------------------------------------------------------*/
    printf("\nW%chlen Sie die Startreihe (a-j) : ",a_UMLAUT);
    scanf("%c",&yRicht);
    fflush(stdin);
    printf("\nW%chlen Sie die Startzelle (0-9) : ",a_UMLAUT);
    scanf("%c",&xRicht);
    fflush(stdin);
    feldsp2[yRicht-96][xRicht-47] = 120 ;
    brettsp2();
}
/* ------------------------------------------------------------------------------------*/

