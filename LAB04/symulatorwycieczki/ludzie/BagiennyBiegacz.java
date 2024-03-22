package pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.ludzie;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.Wedrowka;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.gory.Rzeka;

public class BagiennyBiegacz extends Czlowiek
{
    public BagiennyBiegacz(String imie, String nazwisko, Plec plec)
    {
        super(imie, nazwisko, plec, 6.0, 12.0, 20.0);
    }

    @Override
    public int getUmiejetnosciNawigacyjne(){
        return 5;
    }

    @Override
    public void reagujNaWedrowke(Wedrowka w, double czas)
    {
        if(w instanceof Rzeka)
        {
            mow("Fajny teren.");
            aktualizujZmeczenie(czas/2);
        }
        else
        {
            super.reagujNaWedrowke(w, czas);
        }
    }

}