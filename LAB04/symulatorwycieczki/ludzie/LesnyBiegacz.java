package pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.ludzie;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.Atrakcja;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.gory.beskidy.CmentarzZIWojny;

public class LesnyBiegacz extends Czlowiek
{
    public LesnyBiegacz(String imie, String nazwisko, Plec plec)
    {
        super(imie, nazwisko, plec, 6.0, 12.0, 20.0);
    }

    @Override
    public int getUmiejetnosciNawigacyjne()
    {
        return 5;
    }

    @Override
    public void reagujNaAtrakcje(Atrakcja a, double czas)
    {
        if(a instanceof CmentarzZIWojny)
        {
            mow("Wow, bardzo lubie cmentarze!");
            regeneruj(czas*2);
        }
        else{
            super.reagujNaAtrakcje(a, czas);
        }
    }

}
