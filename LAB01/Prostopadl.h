#pragma once

#include "Bryla.h"

class Prostopadl : public Bryla{
    private:
        double a;
        double b;
        double h;
    protected:
        void Wypisz(std::ostream& out) const override;
    public:
        Prostopadl(double a);
        Prostopadl(double a, double b, double h);
        Prostopadl();

        double GetA() const;

        void SetA(double a);

        double GetB() const;

        void SetB(double b);

        double GetH() const;

        void SetH(double h);

        double PolePowierzchniBocznej() override;
        double PolePowierzchniCalkowitej() override;

        ~Prostopadl() override;
};