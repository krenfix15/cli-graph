#include <iostream>
#include <fstream>

#include "Graf.h"

using namespace std;

extern int v[20];
extern int c[20],viz[10];
extern int prim, ultim, varf;

Graf::Graf()
{
    NrNoduri = 0;
    for (int i = 1; i <= NrNoduri; i++)
        MatriceAdiacenta[i] = new int[NrNoduri];
}

Graf::Graf(int _NrNoduri)
{
    NrNoduri = _NrNoduri;
    MatriceAdiacenta = new int*[NrNoduri];
    for (int i = 1; i <= NrNoduri; i++)
        MatriceAdiacenta[i] = new int[NrNoduri];
}
Graf::GetNrNoduri()
{
    return NrNoduri;
}

Graf::SetNrNoduri(int _nrNoduri)
{
    NrNoduri = _nrNoduri;
    return NrNoduri;
}

int** Graf::GetMatriceAdiacenta()
{
    return MatriceAdiacenta;
}

void Graf::CitireMatriceAdiacenta()
{
    for(int i = 1; i <= NrNoduri; i++)
        MatriceAdiacenta[i][i] = 0;

    for(int i = 1; i < NrNoduri; i++)
    {
        for(int j = i+1; j <= NrNoduri; j++)
        {
            cout << "Scrieti 1 respectiv 0, daca muchia (" << i << ", " << j << ") exista sau nu: ";
            do
            {
                cin >> MatriceAdiacenta[i][j];
            }
            while(MatriceAdiacenta[i][j] != 0 && MatriceAdiacenta[i][j] != 1);

            MatriceAdiacenta[j][i] = MatriceAdiacenta[i][j];
        }
    }
    cout<<endl;
}

void Graf::citireMatriceFisier(ifstream &inFile)
{
  inFile >> NrNoduri;

  while(inFile)
  for(int i = 1; i <=NrNoduri; i++)
  {
    for(int j = 1; j <= NrNoduri; j++)
    {
      inFile >> MatriceAdiacenta[i][j];
    }
  }
  cout << "Citirea din fisier s a efectuat cu succes!\n\n";
  inFile.close();
}

void Graf::AfisareMatriceAdiacenta()
{
    for(int i=1; i<=NrNoduri; i++)
    {
        for(int j=1; j<= NrNoduri; j++)
            cout << MatriceAdiacenta[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

void Graf::AfisareMuchiiGraf()
{
    cout << "Muchiile sunt: ";
    for(int i = 1; i <= NrNoduri-1; i++)
    {
        for(int j = i + 1; j <= NrNoduri; j++)
        {
            if(MatriceAdiacenta[i][j] == 1)
                cout << "{" << i << " " << j<< "}" << " ";
        }
    }

    cout << "\b;";
    cout << endl;
    cout << endl;
}

Graf::returnGradNod(int nodAles)
{
    int grad_nod = 0;
    for(int i = 1; i <= NrNoduri ; i++)
    {
        if(MatriceAdiacenta[nodAles][i] == 1)
            grad_nod++;
    }
    return grad_nod;
}

void Graf::esteLant()
{
    int lant=1;
    int v[10];

    cout << "Citeste lantul: \n";
    for(int i = 1; i <= NrNoduri; i++)
    {
        cout << "Nod[" << i << "] = ";
        cin >> v[i];
    }

    for(int i = 1; i < NrNoduri; i++)
        if(MatriceAdiacenta[v[i]][v[i+1]]==0)
            lant=0;

    if(lant == 1)
    {
        cout << "{";
        for(int i = 1; i <= NrNoduri; i++)
            cout << v[i] << "-";
        cout << "\b}";
        cout << " este lant.";
    }

    else
    {
        cout << "{";
        for(int i=1; i<=NrNoduri; i++)
            cout << v[i] << "-";
        cout << "\b}";
        cout << " nu este lant.";
    }
}

void Graf::ParcurgereAdancime(int _varfStart)
{
    v[_varfStart] = 1;

    cout << _varfStart << "->";

    for(int i = 1; i <= NrNoduri; i++)
    {
        if(MatriceAdiacenta[_varfStart][i] == 1)
            if(v[i] == 0)
                ParcurgereAdancime(i);
    }
}

void Graf::ParcurgereLatime(int varfStart)
{
    int k;

    while(prim <= ultim)
    {
        varf = c[prim];
        for(k = 1; k <= NrNoduri; k++)
            if(MatriceAdiacenta[varf][k] == 1 && viz[k] == 0) ///il adaug pe k in coada daca este vecin pt. varf si nu a fost vizitat
            {
                ultim++;
                c[ultim] = k;
                viz[k] = 1;
            }
        prim++;
    }
}

Graf::~Graf()
{
    for (int i = 0; i < NrNoduri; i++)
        delete MatriceAdiacenta[i];
    delete MatriceAdiacenta;
}
