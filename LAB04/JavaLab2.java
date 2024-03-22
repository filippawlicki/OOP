package pl.edu.pg.eti.ksg.po.lab2;

import java.util.HashSet;
import java.util.Set;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.Grupa;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.SymulatorWycieczki;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.SluchaczPostepow;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.Uczestnik;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.Wycieczka;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.gory.Droga;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.gory.Las;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.gory.Laka;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.gory.PrzeprawaPrzezRzeke;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.gory.ZalanaLaka;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.gory.Pole;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.gory.beskidy.Cmentarz;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.gory.beskidy.Elektrownia;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.gory.beskidy.Zamek;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.ludzie.Czlowiek;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.ludzie.LesnyBiegacz;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.ludzie.BagiennyBiegacz;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.ludzie.CzlowiekZKontuzja;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.ludzie.PrzewodnikBeskidzki;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.ludzie.Hydrolog;

public class JavaLab2 {
    public static void main(String[] args) {
        Wycieczka w = doDydiowki();
        Set<SluchaczPostepow> listaSluchaczy = new HashSet<>();
        
        PrzewodnikBeskidzki przewodnik = new PrzewodnikBeskidzki("Vin", "Diesel", Czlowiek.Plec.KOBIETA);
        Set<Uczestnik> uczestnicy = new HashSet<>();
        uczestnicy.add(new Hydrolog("Gragas", "Hydrolog", Czlowiek.Plec.MEZCZYZNA));
        uczestnicy.add(new LesnyBiegacz("Kon", "Rafal", Czlowiek.Plec.MEZCZYZNA));
        uczestnicy.add(new BagiennyBiegacz("Bartek", "Z Blaviken", Czlowiek.Plec.MEZCZYZNA));
        uczestnicy.add(new CzlowiekZKontuzja("Jednonogi", "Bandyta", Czlowiek.Plec.MEZCZYZNA));
        
        Grupa g = new Grupa(przewodnik, uczestnicy);
        
        SymulatorWycieczki symulator = new SymulatorWycieczki(g, w);
        
        listaSluchaczy.add((elementWycieczki, lp, liczbaElementow)-> {
            if(lp == liczbaElementow)
            {
                System.out.println("To koncówka naszej wycieczki. Miło było was poznać i oprowadzać.");
            }
            else
            {
                System.out.println("Jesteśmy na etapie wycieczki numer "+lp+" / "+liczbaElementow+". Jesteśmy coraz bliżej końca.");
            }
        });

        symulator.setListaSluchaczy((listaSluchaczy));
        symulator.symuluj();
    }
    
    public static Wycieczka doDydiowki()
    {
        Wycieczka ret = new Wycieczka("Do Zamku w Stalowej Woli");
        ret.dodajElementWycieczki(new Droga(5.0));
        ret.dodajElementWycieczki(new Elektrownia("Elektrownia", "Babice"));
        ret.dodajElementWycieczki(new Las(1.0));
        ret.dodajElementWycieczki(new PrzeprawaPrzezRzeke(3.0));
        ret.dodajElementWycieczki(new ZalanaLaka(4.0));
        ret.dodajElementWycieczki(new Cmentarz("Cmentarz", "Ustron"));
        ret.dodajElementWycieczki(new Droga(2.0));
        ret.dodajElementWycieczki(new Pole(3.5));
        ret.dodajElementWycieczki(new Droga(5.0));
        ret.dodajElementWycieczki(new Laka(2.0));
        ret.dodajElementWycieczki(new Zamek("Zamek", "Stalowa Wola"));
        return ret;
    }
   
}
