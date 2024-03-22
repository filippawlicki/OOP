package pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.gory;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.Wedrowka;

public class Rzeka extends Wedrowka{

    public Rzeka(double odleglosc){
        super(odleglosc);
    }

    @Override
    public double modyfikujPredkoscGrupy(double predkosc){
        return (predkosc * 0.1);
    }

    @Override
    public int getTrudnoscNawigacyjna(){
        return 2;
    }

    @Override
    public String getNazwa(){
        return "Rzeka";
    }
}
