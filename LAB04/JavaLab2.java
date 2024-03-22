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
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.gory.WietrznaGran;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.gory.Rzeka;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.gory.ZalanaLakaTurzyc;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.gory.PoleBarszczuSosnowskiego;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.gory.beskidy.CmentarzZIWojny;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.gory.beskidy.ElektrowniaWodna;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.gory.beskidy.Zamek;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.ludzie.Czlowiek;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.ludzie.LesnyBiegacz;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.ludzie.BagiennyBiegacz;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.ludzie.CzlowiekZKontuzja;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.ludzie.PrzewodnikBeskidzki;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.ludzie.Hydrolog;

public class JavaLab2 {
    public static void main(String[] args) {
        Wycieczka w = doBabic();
        Set<SluchaczPostepow> listaSluchaczy = new HashSet<>();
        
        PrzewodnikBeskidzki przewodnik = new PrzewodnikBeskidzki("Vin", "Diesel", Czlowiek.Plec.KOBIETA);
        Set<Uczestnik> uczestnicy = new HashSet<>();
        uczestnicy.add(new Hydrolog("Gragas", "Hydrolog", Czlowiek.Plec.MEZCZYZNA));
        uczestnicy.add(new LesnyBiegacz("Kon", "Rafal", Czlowiek.Plec.MEZCZYZNA));
        uczestnicy.add(new CzlowiekZKontuzja("Jednonogi", "Bandyta", Czlowiek.Plec.MEZCZYZNA));
        uczestnicy.add(new BagiennyBiegacz("Bartek", "Z Blaviken", Czlowiek.Plec.MEZCZYZNA));
        
        Grupa g = new Grupa(przewodnik, uczestnicy);
        
        SymulatorWycieczki symulator = new SymulatorWycieczki(g, w);
        
        listaSluchaczy.add((elementWycieczki, lp, liczbaElementow)-> {
            if(lp == liczbaElementow)
            {
                System.out.println("To juz koniec, dziekuje za wycieczke.");
            }
            else
            {
                System.out.println("Jesteśmy na w momencie "+lp+" / "+liczbaElementow+". Coraz blizej.");
            }
        });

        symulator.setListaSluchaczy((listaSluchaczy));
        symulator.symuluj();
    }
    
    public static Wycieczka doBabic()
    {
        Wycieczka ret = new Wycieczka("Do Elektrowni w Babicach");
        ret.dodajElementWycieczki(new Droga(4));
        ret.dodajElementWycieczki(new CmentarzZIWojny("Cmentarz", "Ustron"));
        ret.dodajElementWycieczki(new Rzeka(2));
        ret.dodajElementWycieczki(new ZalanaLakaTurzyc(5));
        ret.dodajElementWycieczki(new Zamek("Zamek", "Stalowa Wola"));
        ret.dodajElementWycieczki(new Las(1.0));
        ret.dodajElementWycieczki(new PoleBarszczuSosnowskiego(4.5));
        ret.dodajElementWycieczki(new Droga(3));
        ret.dodajElementWycieczki(new WietrznaGran(1.5));
        ret.dodajElementWycieczki(new ElektrowniaWodna("Elektrownia", "Babice"));
        return ret;
    }
   
}
