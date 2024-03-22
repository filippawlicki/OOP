package pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.gory.beskidy;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.Atrakcja;

public class Elektrownia extends Atrakcja {

    public Elektrownia(String nazwaAtrakcji, String nazwaMiejscowosci)
    {
        setNazwaAtrakcji(nazwaAtrakcji);
        setNazwaMiejscowosci(nazwaMiejscowosci);
    }

    @Override
    public double getCzasZwiedzaniaAtrakcji()
    {
        return 0.75;
    }

    @Override
    public String getNazwa() {
        return getNazwaAtrakcji();
    }
}