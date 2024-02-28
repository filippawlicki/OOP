#pragma once

#include <iostream>

class Bryla {
  protected:
    virtual void Wypisz(std::ostream& out) const = 0;
    friend std::ostream& operator<<(std::ostream& os, const Bryla&bryla);
  public:
    //virtual double Pole() = 0;
    //virtual double Obwod() = 0;
    
    virtual ~Bryla();
};