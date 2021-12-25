#include <iostream>
#include <fstream>

#include "Graf.h"
#include "GrafOrientat.h"

int v[20];  ///coada pentru parcurgere adancime
int c[20], viz[10];
int prim, ultim, varf;

using namespace std;

int main()
{
    Graf graf(100);
    GrafOrientat grafOrientat(100);

    char filename[] = "matriceAdGrafNeorientat.txt";
    char filename1[] = "matriceAdGrafOrientat.txt";

    ifstream finNeorientat, finOrientat;

    finNeorientat.open(filename);
    finOrientat.open(filename1);

    char alegereTipGraf;

    cout << "[SELECTARE TIP GRAF]\n\n"
        "--------------------------\n"
        "|                        |\n"
        "| N. Graf Neorientat     |\n"
        "| O. Graf Orientat       |\n"
        "|                        |\n"
        "--------------------------\n\n";
    do
    {
        cout << "Introduceti optiunea [N/O]: ";
        cin >> alegereTipGraf;
    }
    while(alegereTipGraf != 'O' && alegereTipGraf !='N' && alegereTipGraf !='o' && alegereTipGraf!='n');

    if(toupper(alegereTipGraf) == 'N')
    {
        do
        {
            system("cls");

            cout<<"[MENIU OPTIUNI GRAF NEORIENTAT]\n\n"
                "------------------------------------------------------------------------------\n"
                "| C. Citire matrice adiacenta.                                               |\n"
                "| F. Citire matrice din fisier.                                              |\n"
                "| A. Afisare matrice adiacenta.                                              |\n"
                "| D. Determinarea muchiilor grafului pornind de la matricea de adiacenta.    |\n"
                "| G. Determinare gradului unui varf X folosind matricea de adiacenta.        |\n"
                "| P. Parcurgere in adancime.                                                 |\n"
                "| L. Parcurgere in latime.                                                   |\n"
                "| V. Verifica daca o succesiune de noduri este lant.                         |\n"
                "|              ---------------------------------------------------------------"
                "\n| X. INCHIDERE.|\n----------------\n\n";

            char optiune;
            cout << "Introduceti optiunea: ";
            cin >> optiune;
            cout << endl;

            switch(toupper(optiune))
            {
            case 'C':
            {
                int n;
                cout << "Introduceti nr. de noduri [1,100]: ";
                cin >> n;
                graf.SetNrNoduri(n);
                graf.CitireMatriceAdiacenta();
            }

            case 'F':
                graf.citireMatriceFisier(finNeorientat);
                break;

            case 'A':
            {
                graf.AfisareMatriceAdiacenta();
            }
            break;

            case 'D':
            {
                graf.AfisareMuchiiGraf();
            }
            break;

            case 'G':
            {
                int nodAles;
                do
                {
                    cout << "Introduceti numarul nodului [1,"<<graf.GetNrNoduri()<<"]: ";
                    cin >> nodAles;
                }
                while(nodAles>graf.GetNrNoduri() && nodAles<=0);

                cout << "Gradul nodului "<<nodAles<<" este "<<graf.returnGradNod(nodAles)<<"."<<endl;
                cout << endl;
            }
            break;

            case 'V':
            {
                graf.esteLant();
            }
            break;

            case 'P':
            {
                int varfStart;
                cout << "Dati varful de start [1,"<<graf.GetNrNoduri() << "]: ";
                cin >> varfStart;
                cout << endl;

                cout << "Parcurgere in adancime: [";
                graf.ParcurgereAdancime(varfStart);
                cout << "\b\b]\n"<<endl;
            }
            break;

            case 'L':
            {
                int varfStart;
                cout << "Dati varful de start [1," << graf.GetNrNoduri() << "]: ";
                cin>>varfStart;

                ultim = prim = 1;
                viz[varfStart] = 1;
                c[prim] = varfStart;
                cout << "Parcurgere in latime: [";
                graf.ParcurgereLatime(varfStart);

                for(int i = 1; i <= ultim; i++) //afisarea cozii
                    cout << c[i] << "->";
                cout << "\b\b]\n" << endl;
            }
            break;

            case 'X':
                exit(0);
            default :
                cout << "Optiune nevalida!\n\n";
                break;
            }

            system("pause");
        }
        while(1);
    }

    if(toupper(alegereTipGraf) == 'O')
    {
        do
        {
            system("cls");

            cout<<"[MENIU OPTIUNI GRAF ORIENTAT]\n\n"
                "------------------------------------------------------------------------------\n"
                "| C. Citire matrice adiacenta.                                               |\n"
                "| F. Citire matrice din fisier.                                              |\n"
                "| A. Afisare matrice adiacenta.                                              |\n"
                "| D. Determinarea muchiilor grafului pornind de la matricea de adiacenta.    |\n"
                "| G. Determinare gradului unui varf X folosind matricea de adiacenta.        |\n"
                "| P. Parcurgere in adancime.                                                 |\n"
                "| L. Parcurgere in latime.                                                   |\n"
                "|              ---------------------------------------------------------------"
                "\n| X. INCHIDERE.|\n----------------\n\n";

            char optiune;
            cout << "Introduceti optiunea: ";
            cin >> optiune;
            cout << endl;

            switch(toupper(optiune))
            {
            case 'C':
            {
                int nrNoduri;
                do
                {
                    cout << "Introduceti nr. de noduri [1,100]: ";
                    cin >> nrNoduri;
                    cout << endl;
                }
                while(nrNoduri>100 || nrNoduri<=0);

                grafOrientat.SetNrNoduri(nrNoduri);
                grafOrientat.CitireMatriceAdiacenta();
            }

            case 'A':
            {
                grafOrientat.AfisareMatriceAdiacenta();
            }
            break;

            case 'F':
                grafOrientat.citireMatriceFisier(finOrientat);
                break;

            case 'D':
            {
                grafOrientat.AfisareMuchiiGraf();
            }
            break;

            case 'G':
            {
                int nodAles;
                do
                {
                    cout << "Introduceti numarul nodului [1," << grafOrientat.GetNrNoduri() << "]: ";
                    cin >> nodAles;
                }
                while(nodAles > grafOrientat.GetNrNoduri() && nodAles <= 0);

                grafOrientat.returnGradNodOrientat(nodAles);
                cout << endl;
            }
            break;

            case 'P':
            {
                int varfStart;
                do
                {
                    cout << "Dati varful de start [1," << grafOrientat.GetNrNoduri() << "]: ";
                    cin >> varfStart;
                    cout << endl;
                }
                while(varfStart > grafOrientat.GetNrNoduri() && varfStart <= 0);

                cout << "Parcurgere in adancime: [";
                grafOrientat.ParcurgereAdancime(varfStart);
                cout << "\b\b]\n" << endl;
            }
            break;

            case 'L':
            {
                int varfStart;
                do
                {
                    cout << "Dati varful de start [1," << grafOrientat.GetNrNoduri() << "]: ";
                    cin >> varfStart;
                    cout << endl;
                }
                while(varfStart > grafOrientat.GetNrNoduri() && varfStart <= 0);

                ultim = prim = 1;
                viz[varfStart] = 1;
                c[prim] = varfStart;
                cout << "Parcurgere in latime: [";
                grafOrientat.ParcurgereLatime(varfStart);

                for(int i = 1; i <= ultim; i++) //afisarea cozii
                    cout << c[i] << "->";
                cout << "\b\b]\n" << endl;
            }
            break;

            case 'X':
                exit(0);
            default :
                cout << "Optiune nevalida!\n\n";
                break;
            }

            system("pause");
        }
        while(1);
    }
    return 0;
}
