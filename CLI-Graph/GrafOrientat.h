#ifndef GRAFORIENTAT_H
#define GRAFORIENTAT_H
#include <iostream>
#include "Graf.h"

class GrafOrientat: public Graf
{
    public:
        GrafOrientat();
        GrafOrientat(int);

        void returnGradNodOrientat(int);
        void AfisareMuchiiGraf();
        void CitireMatriceAdiacenta();
        virtual ~GrafOrientat();

    protected:

    private:
};

#endif // GRAFORIENTAT_H
