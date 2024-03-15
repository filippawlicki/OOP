package pl.edu.pg.eti.ksg.po.lab1.transformacje;

public class Punkt3D extends Punkt {
  private final double z;

  public Punkt3D(double x, double y, double z) {
    super(x, y);
    this.z = z;
  }

  public double getZ() {
    return z;
  }

  @Override
  public boolean equals(Object obj) {
    if (obj instanceof Punkt3D) {
      Punkt3D other = (Punkt3D)obj;
      return (other.getX() == this.getX() && other.getY() == this.getY() && other.z == z);
    }
    return false;
  }

  @Override
  public int hashCode() {
    return 57 * Double.hashCode(z) + 11;
  }

  @Override
  public String toString() {
    return "x: " + this.getX() + ", y: " + this.getY() + ", z: " + z + ".";
  }

  /**
   * Początek układu współrzędnych.
   * W tym miejscu słowo kluczowe final oznacza, że statyczne
   * pole klasy Punkt nie może zostać zmienione.
   * Dotyczy to jednak samej referencji, a nie obiektu, na który
   * wskazuje.
   */
  public static final Punkt3D O = new Punkt3D(0, 0, 0);
  /**
   * Punkt (1,0) w układzie współrzędnych
   */
  public static final Punkt3D E_X = new Punkt3D(1, 0, 1);

  /**
   * Punkt (0,1) w układzie współrzędnych
   */
  public static final Punkt3D E_Y = new Punkt3D(0, 1, 2);
}
