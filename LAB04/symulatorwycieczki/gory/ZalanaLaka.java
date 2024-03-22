package pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.gory;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.Wedrowka;


public class ZalanaLaka extends Wedrowka{

    public ZalanaLaka(double odleglosc){
        super(odleglosc);
    }

    @Override
    public double modyfikujPredkoscGrupy(double predkosc){
        return (predkosc * (0.25));
    }

    @Override
    public int getTrudnoscNawigacyjna(){
        return 2;
    }

    @Override
    public String getNazwa(){
        return "ZalanaLakaTurzyc";
    }
}
