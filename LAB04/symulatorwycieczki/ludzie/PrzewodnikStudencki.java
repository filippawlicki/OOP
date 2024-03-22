package pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.ludzie;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.Atrakcja;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.Wycieczka;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.gory.beskidy.Zamek;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.gory.beskidy.ElektrowniaWodna;

public class PrzewodnikStudencki extends Student {

    public PrzewodnikStudencki(String imie, String nazwisko, Plec plec) {
        super(imie, nazwisko, plec, 5.0);
    }

    protected PrzewodnikStudencki(String imie, String nazwisko, Plec plec, double maksymalnaPredkosc, double czasPelnejRegeneracji, double czasPelnegoZmeczenia) {
        super(imie, nazwisko, plec, maksymalnaPredkosc, czasPelnejRegeneracji, czasPelnegoZmeczenia);
    }

    @Override
    public void opiszWycieczke(Wycieczka wycieczka) {
        mow("Szanowna grupo, proszę o uwagę. Teraz opowiem Wam o wycieczce.");
        super.opiszWycieczke(wycieczka);
    }

    @Override
    public int getUmiejetnosciNawigacyjne() {
        return 4;
    }

    @Override
    public void reagujNaAtrakcje(Atrakcja a, double czas) {
        if(a instanceof ElektrowniaWodna) {
            ElektrowniaWodna elek = (ElektrowniaWodna) a;
            mow("To jest elektrownia w miejscowosci: " + elek.getNazwaMiejscowosci() + ". Uczylem się o niej w gimnazjum, więc mogę coś opowiedzieć.");
            regeneruj(czas);
        }
        else if(a instanceof Zamek) {
            Zamek zamek = (Zamek) a;
            mow("Tutaj widzimy Zamek miejcowości "+zamek.getNazwaMiejscowosci()+". Takie zamki występowały m.in. w serii bajek 'Shrek'.");
            regeneruj(czas);
        }
        else {
            super.reagujNaAtrakcje(a, czas);
        }
    }
    
}
