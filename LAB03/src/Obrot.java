package pl.edu.pg.eti.ksg.po.lab1.transformacje;
import java.lang.Math;

public class Obrot implements Transformacja {
  private final double a;

  public Obrot(double a) {
    this.a = Math.toRadians(a);
  }
  @Override
  public Punkt transformuj(Punkt p) {
    double x = p.getX() * Math.cos(a) - p.getY() * Math.sin(a);
    double y = p.getX() * Math.sin(a) + p.getY() * Math.cos(a);
    return new Punkt(x, y);
  }

  @Override
  public Transformacja getTransformacjaOdwrotna() throws BrakTransformacjiOdwrotnejException {
    if (a == 0)
      throw new BrakTransformacjiOdwrotnejException("Brak transformacji odwrotnej. " +
              "Alpha wynosi 0.");

    return new Obrot(1 / a);
  }

  public double getA(){
    return a;
  }

  @Override
  public String toString() {
    return "Obrot, gdzie a = " + a;
  }
}