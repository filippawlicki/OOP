package pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.ludzie;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.Wedrowka;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.gory.PrzeprawaPrzezRzeke;;

public class Hydrolog extends Czlowiek{
    public Hydrolog(String imie, String nazwisko, Plec plec){
        super(imie, nazwisko, plec, 6.0, 18.0, 18.0);
    }

    @Override
    public int getUmiejetnosciNawigacyjne(){
        return 5;
    }

    @Override
    public void reagujNaWedrowke(Wedrowka a, double czas)
    {
        if(a instanceof PrzeprawaPrzezRzeke)
        {
            mow("To teren podmokły! Muszę zebrać dane na temat przewodności wody (EC) i jej pH do celów naukowych.");
            regeneruj(czas*2);
        }
        else
        {
            super.reagujNaWedrowke(a, czas);
        }
    }

}
