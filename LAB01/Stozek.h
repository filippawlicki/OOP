#include "Bryla.h"

class Stozek : public Bryla {
  private:
    double r;
    double h;
  protected:
    void Wypisz(std::ostream& out) const override;
  public:
    Stozek(double r, double h);

    double GetR() const;

    double GetH() const;

    void SetR(double r);

    void SetH(double h);

    double Tworzaca();
    double PolePowierzchniBocznej();
    double PolePowierzchniCalkowitej();

    ~Stozek() override;
};