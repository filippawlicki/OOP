package pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.gory;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.Wedrowka;


public class WietrznaGran extends Wedrowka{

    public WietrznaGran(double odleglosc){
        super(odleglosc);
    }

    @Override
    public double modyfikujPredkoscGrupy(double predkosc){
        return (predkosc * (4/3));
    }

    @Override
    public int getTrudnoscNawigacyjna(){
        return 1;
    }

    @Override
    public String getNazwa(){
        return "Wietrzna Gran";
    }
}
