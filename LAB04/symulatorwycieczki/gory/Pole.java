package pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.gory;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.Wedrowka;


public class Pole extends Wedrowka{

    public Pole(double odleglosc){
        super(odleglosc);
    }

    @Override
    public double modyfikujPredkoscGrupy(double predkosc){
        return (predkosc * (0.75));
    }

    @Override
    public int getTrudnoscNawigacyjna(){
        return 3;
    }

    @Override
    public String getNazwa(){
        return "PoleBarszczuSosnowskiego";
    }
}
