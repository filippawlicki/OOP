package pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.ludzie;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.Atrakcja;
//import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.Wycieczka;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.gory.beskidy.ElektrowniaWodna;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.gory.beskidy.Zamek;

public class PrzewodnikBeskidzki extends Czlowiek {

    public PrzewodnikBeskidzki(String imie, String nazwisko, Plec plec) {
        super(imie, nazwisko, plec, 5.0, 16.0, 18.0);
    }

    @Override
    public int getUmiejetnosciNawigacyjne(){
        return 5;
    }

    @Override
    public void reagujNaAtrakcje(Atrakcja a, double czas) {
        if(a instanceof ElektrowniaWodna) {
            ElektrowniaWodna elek = (ElektrowniaWodna) a;
            mow("To jest elektrownia w " + elek.getNazwaMiejscowosci() + ". Bardzo stara.");
            regeneruj(czas);
        }

        else if(a instanceof Zamek) {
            Zamek zamek = (Zamek) a;
            mow(""+zamek.getNazwaMiejscowosci()+". " +zamek.getNazwa()+ ". Od pokolen zamieszkują go koty.");
            regeneruj(czas);
        }
        else {
            super.reagujNaAtrakcje(a, czas);
        }
    }

}
