#include "GrafOrientat.h"
#include "Graf.h"
#include <iostream>
using namespace std;

GrafOrientat::GrafOrientat()
{
    NrNoduri = 0;
    for (int i = 1; i <= NrNoduri; i++)
        MatriceAdiacenta[i] = new int[NrNoduri];
}

GrafOrientat::GrafOrientat(int _NrNoduri)
{
    NrNoduri = _NrNoduri;
    MatriceAdiacenta=new int*[NrNoduri];
    for (int i = 1; i <= NrNoduri; i++)
        MatriceAdiacenta[i] = new int[NrNoduri];
}

void GrafOrientat::CitireMatriceAdiacenta()
{
    for(int i = 1; i <= NrNoduri; i++)
        MatriceAdiacenta[i][i] = 0;

    for(int i = 1; i <= NrNoduri-1; i++)
    {
        for(int j = 1; j <= NrNoduri; j++)
        {
            if(i == j)
                continue;
            cout << "Scrieti 1 respectiv 0, daca drumul dinspre nodul " << i << " spre nodul " << j << " exista sau nu: ";
            do
            {
                cin >> MatriceAdiacenta[i][j];
            }
            while(MatriceAdiacenta[i][j] != 0 && MatriceAdiacenta[i][j] != 1);
        }
    }
    cout << endl;
}

void GrafOrientat::AfisareMuchiiGraf()
{
    cout << "Muchiile sunt: ";
    for(int i = 1; i <= NrNoduri; i++)
    {
        for(int j = 1; j <= NrNoduri; j++)
        {
            if(MatriceAdiacenta[i][j] == 1)
                cout << "{" << i << " " << j<<"}" << " ";
        }
    }

    cout << "\b;";
    cout << endl;
    cout << endl;
}

void GrafOrientat::returnGradNodOrientat(int nodAles)
{
    int grad_Pozitiv = 0;
    int grad_Negativ = 0;

    for(int i = 1; i <= NrNoduri; i++)
    {
        if(MatriceAdiacenta[nodAles][i] == 1)
            grad_Pozitiv++;
        if(MatriceAdiacenta[i][nodAles] == 1)
            grad_Negativ++;
    }
    cout << "\nGradul pozitiv al nodului " << nodAles << " este " << grad_Pozitiv << ".\n";
    cout << "Gradul negativ al nodului " << nodAles << " este " << grad_Negativ << ".\n\n";
}

GrafOrientat::~GrafOrientat()
{
    for (int i = 0; i < NrNoduri; i++)
        delete MatriceAdiacenta[i];
    delete MatriceAdiacenta;
}
