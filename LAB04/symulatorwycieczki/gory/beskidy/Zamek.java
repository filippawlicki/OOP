package pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.gory.beskidy;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.Atrakcja;

public class Zamek extends Atrakcja{
    
    public Zamek(String nazwaAtrakcji, String nazwaMiejscowosci){
        setNazwaAtrakcji(nazwaAtrakcji);
        setNazwaMiejscowosci(nazwaMiejscowosci);
    }

    @Override
    public double getCzasZwiedzaniaAtrakcji(){
        return 3;
    }

    @Override
    public String getNazwa() {
        return getNazwaAtrakcji();
    }
}
