package pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.gory.beskidy;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.Atrakcja;

public class Cmentarz extends Atrakcja
{

    public Cmentarz(String nazwaAtrakcji, String nazwaMiejscowosci){
        setNazwaAtrakcji(nazwaAtrakcji);
        setNazwaMiejscowosci(nazwaMiejscowosci);
    }

    @Override
    public double getCzasZwiedzaniaAtrakcji(){
        return 0.33;
    }

    @Override
    public String getNazwa() {
        return getNazwaAtrakcji();
    }
}