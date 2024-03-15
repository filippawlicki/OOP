package pl.edu.pg.eti.ksg.po.lab1.transformacje;

public class Obrot3D extends ObrotOS implements Transformacja3D {

  private final double alpha;
  private final double beta;
  private final double gamma;
  public Obrot3D(double alpha, double beta, double gamma) {
    super('x' , 1);
    this.alpha = alpha;
    this.beta = beta;
    this.gamma = gamma;
  }

  public Punkt3D transformuj3D(Punkt3D p) {
    Transformacja3D x = new ObrotOS('x', alpha);
    Transformacja3D y = new ObrotOS('y', beta);
    Transformacja3D z = new ObrotOS('z', gamma);
    p = x.transformuj3D(p);
    p = y.transformuj3D(p);
    p = z.transformuj3D(p);
    return p;
  }

  @Override
  public Transformacja3D getTransformacjaOdwrotna3D() throws BrakTransformacjiOdwrotnejException {
    if (alpha == 0 || beta == 0 || gamma == 0)
      throw new BrakTransformacjiOdwrotnejException("Brak transformacji odwrotnej. " +
              "kat wynosi 0.");

    return new Obrot3D(1/alpha, 1/beta, 1/gamma);
  }

  @Override
  public String toString() {
    return "Obrot3D, x = " + alpha + ", y = " + beta + ", z =  " + gamma;
  }
}
