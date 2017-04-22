#include <stdio.h>
#include <string.h>
#include <math.h>

// Konstanten
#define N 35 // Dimension des Merkmalraums
#define MAX_TRAININGSDATEN 2000
#define MAX_TESTDATEN 500
#define MAX_ZEILENLAENGE_MERKMAL_DATEI 10000


// Typdefinitionen
typedef double MerkmalsVektorT[N];

/** @brief lade Merkmalsdatensaetze
*
*   Die Funktion laedt die Merkmalvektoren aus einer Datei. Die Merkmalvektoren muessen in der Datei
*   zeienweise abgelegt werden. Die einzelnen Elemente eines Merkmalvektors muessen durch Komma getrennt
*   sein. Die Dimension des Merkmalraums muss mit der Groesse des Feld-Typs MerkmalsVektorT uebereinstimmen.
*
*   @param [in] dateiname Dateiname (inkl. Pfad) der Datei mit den Merkmalsvektoren
*   @param [out] mv Merkmalsvektoren. In der Funktion wird fuer mv nicht dynamisch Speicher angelegt.
*                   D.h. das uebergebene Feld muss hinreichend gross sein dimensioniert sein.

*   @return Anzahl gelesener Datensaetze
*/
int ladeMerkmalVektoren(char* dateiname, MerkmalsVektorT mv[]);


/** @brief lade Klassenlabel
*
*   Die Funktion laedt Klassenlabel aus einer Datei. In der Datei wird die Klassenzugeh�rigkeit
*   durch die Position der 1 in einem ansonsten mit 0en gef�llten Feld von ganzen Zahlen codiert.
*   Im Labelvektor lv wird die Klasse durch einen ganzzahligen Wert codiert, welcher der Position
*   der 1 in dem gelesenen Datensatz entspricht.
*
*   @param [in] dateiname Dateiname (inkl. Pfad) der Datei mit den Merkmalsvektoren
*   @param [out] lv Labelvektor. In der Funktion wird fuer lv nicht dynamisch Speicher angelegt.
*                   D.h. das uebergebene Feld muss hinreichend gross dimensioniert sein.
*
*   @return Anzahl gelesener Datensaetze
*/
int ladeLabelVektor(char* dateiname, int lv[]);

/** @brief euklidischer Abstand
*
*   Die Funktion berechnet den euklidischen Abstand zwischen zwei Merkmalsvektoren
*
*   @param [in] m1 Merkmalsvektor 1
*   @param [in] m2 Merkmalsvektor 2
*
*   @return euklidischer Abstand zwischen m1 und m2
*/
double euklidischerAbstand(MerkmalsVektorT m1, MerkmalsVektorT m2)
{
    int n = sizeof(MerkmalsVektorT)/sizeof(double); // Dimension des Merkmalraums
    double summe=0;
    int i;
    for(i=0;i<n;i++)
        summe = summe + pow((m1[i]-m2[i]),2);

    return sqrt(summe);
}

/** @brief sortiere Trainingsdaten
*
*   Sortiert ein Feld von Merkmalsvektoren mv und den dazugehoerigen Labeln lv nach dem Abstand der
*   Merkmalsvektoren zu einem Referenzmerkmalsvektore ref. Als Sortieralgorithmus wird Bubble-Sort genutzt.
*
*   @param [in] mv m-dimensionales Feld von Merkmalsvektoren;
*                 Ein Merkmalsvektor ist ein Feld von double-Werten. Die Dimension des Feldes, d.h.
*                 die Dimension des Merkmalraums laesst sich ermitteln durch N = sizeof(MerkmalsVektorT)/sizeof(double).
*   @param [in] lv m-dimensionales Feld, dessen i-tes Element das Klassenlabel fuer den i-ten
*                 Merkmalsvektor enthaelt. Die Klassenlabel muessen aus dem Intervall [0...c[ sein (c=Anzahl der Klassen).
*   @param [in] m Anzahl der Elemente der Trainingsdaten
*   @param [in] ref Referenzvektor
*   @param [out] mv sortiertes Feld von Merkmalsvektoren
*   @param [out] lv sortiertes Feld von Klassenlabeln
*/
void sortiereNachAbstandZuReferenz(MerkmalsVektorT mv[], int lv[], int m, MerkmalsVektorT ref)
{   // gewaehlter Sortieralgorithmus: Bubble-Sort
    int i,j;
    MerkmalsVektorT t;
    int tl;

    for(i=m-1;i>0;i--)
    {
        for(j=0;j<i;j++)
        {
            if(euklidischerAbstand(mv[j],ref) > euklidischerAbstand(mv[j+1],ref))
            {   // vertausche mv[j] mit mv[j+1] und lv[j] mit lv[j+1]
                memcpy(&t,&mv[j],sizeof(MerkmalsVektorT));
                memcpy(&mv[j],&mv[j+1],sizeof(MerkmalsVektorT));
                memcpy(&mv[j+1],&t,sizeof(MerkmalsVektorT));
                tl = lv[j];
                lv[j] = lv[j+1];
                lv[j+1] = tl;
            }
        }
    }

}

/** @brief k-N�chste-Nachbarn-Klassifikator
*
*   Unter Verwendung des k-N�chste-Nachbarn Algorithmus wird ein unbekanntes Muster (Merkmalsvektor)
*   klassifiziert.
*
*   @param [in] x m-dimensionales Feld von Merkmalsvektoren (Trainingsdatensatz);
*                 Ein Merkmalsvektor ist ein Feld von double-Werten. Die Dimension des Feldes, d.h.
*                 die Dimension des Merkmalraums laesst sich ermitteln durch N = sizeof(MerkmalsVektorT)/sizeof(double).
*   @param [in] y m-dimensionales Feld, dessen i-tes Element das Klassenlabel fuer den i-ten
*                 Merkmalsvektor enthaelt. Die Klassenlabel muessen aus dem Intervall [0...c[ sein.
*                 c darf maximal 100 sein, d.h. die Anzahl der verschiedenen Klassen ist auf 100 beschraenkt.
*   @param [in] m Anzahl der Elemente der Trainingsdaten
*   @param [in] k Anzahl der zu beruecksichtigen naechsten Nachbarn (maximal 101)
*   @param [in] u zu klassifizierender Merkmalsvektor
*
*   @return Klassenlabel des Merkmalsvektor u
*/
int kNN_KlassifikatorB(MerkmalsVektorT x[], int y[], int m, int k, MerkmalsVektorT u)
{

    return 0;
}

int kNN_KlassifikatorA(MerkmalsVektorT x[], int y[], int m, int k, MerkmalsVektorT u)
{
// ---- Start TODO ----

    return 0;
// ---- Ende TODO -----
}

int main(int argc, char* argv[])
{
    MerkmalsVektorT training[1000],test[100];
    int m,i,j,m1;
    int v[1000],vt[100]; // Labelvektor der Traings- und Testdaten

    m = ladeMerkmalVektoren("training_merkmal860.dat",training);
    printf("Anzahl Datensaetze: %i\n",m);


    m = ladeLabelVektor("training_target860.dat",v);
    printf("Anzahl Datensaetze: %i\n",m);

    m1 = ladeMerkmalVektoren("test_merkmal100.dat",test);
    m1 = ladeLabelVektor("test_target100.dat",vt);
    printf("Anzahl Datensaetze: %i\n",m1);
    int anzFehler=0;
    int klasse;

    for(i=0;i<m1;i++)
    {
        klasse = kNN_KlassifikatorA(training,v,m,13,test[i]);
        if(klasse!=vt[i])
            anzFehler++;
        printf("%i. Merkmalsvektor wird Klasse %i (%i) zugeordnet.\n",i,klasse,vt[i]);
    }
    printf("Fehler: %i   Fehlerrate: %.1f%%\n",anzFehler,(float)anzFehler/m1*100);
    return 0;
}



int ladeMerkmalVektoren(char* dateiname, MerkmalsVektorT mv[])
{
    FILE* datei;
    int anz=0,i;
    char text[MAX_ZEILENLAENGE_MERKMAL_DATEI];
    char* tp;
    int n = sizeof(MerkmalsVektorT)/sizeof(double); // Dimension des Merkmalraums

    datei=fopen(dateiname,"r");
    if(!datei)
    {
        printf("Datei <%s> konnte nicht geoeffnet werden.\n",dateiname);
        return 0;
    }
    while(fgets(text,MAX_ZEILENLAENGE_MERKMAL_DATEI,datei))
    {

        tp = text;
        for(i=0;i<n && tp!=NULL;i++)
        {
            sscanf(tp,"%lf",&mv[anz][i]);
            tp = strchr(tp,',');
            tp++;
        }
        anz++;
    }


    fclose(datei);
    return anz;
}

int ladeLabelVektor(char* dateiname, int lv[])
{
    FILE* datei;
    int anz=0;
    char text[MAX_ZEILENLAENGE_MERKMAL_DATEI];
    char* tp;

    datei=fopen(dateiname,"r");
    if(!datei)
    {
        printf("Datei <%s> konnte nicht geoeffnet werden.\n",dateiname);
        return 0;
    }
    while(fgets(text,MAX_ZEILENLAENGE_MERKMAL_DATEI,datei))
    {
        tp = strchr(text,'1');
        if(tp!=NULL)
        {
            lv[anz]= (tp-text)/2;
        }else
        {
            lv[anz] = -1;
        }
        anz++;
    }
    fclose(datei);
    return anz;
}