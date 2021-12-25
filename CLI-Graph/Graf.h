#ifndef GRAF_H
#define GRAF_H

#include <fstream>

using namespace std;

class Graf
{
    private:

    public:
        int **MatriceAdiacenta;
        int NrNoduri;

        Graf();
        Graf(int);

        int** GetMatriceAdiacenta();
        int returnGradNod(int);

        virtual int GetNrNoduri();
        virtual int SetNrNoduri(int);

        virtual void citireMatriceFisier(ifstream&);
        virtual void CitireMatriceAdiacenta();
        virtual void AfisareMatriceAdiacenta();
        virtual void AfisareMuchiiGraf();

        virtual void ParcurgereAdancime(int);
        virtual void ParcurgereLatime(int);

        void esteLant();

    virtual ~Graf();
};

#endif // GRAF_H
