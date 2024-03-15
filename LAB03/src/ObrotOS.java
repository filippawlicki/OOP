package pl.edu.pg.eti.ksg.po.lab1.transformacje;
import java.lang.Math;

public class ObrotOS implements Transformacja3D {
  private final double angle;
  private final char os;

  public ObrotOS(char os, double angle) {
    this.os = os;
    this.angle = Math.toRadians(angle);
  }
  @Override
  public Punkt3D transformuj3D(Punkt3D p) {
    if(os == 'x')
      return new Punkt3D(p.getX(), -p.getY()*angle, -p.getZ()*angle);
    else if(os == 'y')
      return new Punkt3D(-p.getX()*angle, p.getY(), -p.getZ()*angle);
    else if(os == 'z')
      return new Punkt3D(-p.getX()*angle, -p.getY()*angle, p.getZ());
    else return p;
  }

  @Override
  public Transformacja3D getTransformacjaOdwrotna3D() throws BrakTransformacjiOdwrotnejException {
    if (angle == 0)
      throw new BrakTransformacjiOdwrotnejException("Brak transformacji odwrotnej. " +
              "Alpha wynosi 0.");

    return new ObrotOS(os,1 / angle);
  }

  public double getAngle(){
    return angle;
  }

  public char getOs(){
    return os;
  }


  @Override
  public String toString() {
    return "ObrotOS, po osi: " + os + " ,gdzie kat = " + angle;
  }
}