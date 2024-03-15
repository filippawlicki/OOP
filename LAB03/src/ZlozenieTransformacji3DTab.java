package pl.edu.pg.eti.ksg.po.lab1.transformacje;

public class ZlozenieTransformacji3DTab implements Transformacja3D {
  public Transformacja3D[] tab;

  public ZlozenieTransformacji3DTab(int rozmiar) {
    this.tab = new Transformacja3D[rozmiar];
  }

  @Override
  public Transformacja3D getTransformacjaOdwrotna3D() throws BrakTransformacjiOdwrotnejException {
    ZlozenieTransformacji3DTab z = new ZlozenieTransformacji3DTab(this.tab.length);
    for(int i = 0; i < this.tab.length; i++) {
      z.tab[i] = this.tab[i].getTransformacjaOdwrotna3D();
    }
    return z;
  }

  @Override
  public Punkt3D transformuj3D(Punkt3D p) {
    for(int i = 0; i < this.tab.length; i++) {
      p = tab[i].transformuj3D(p);
      System.out.println(p);
    }
    return p;
  }
}
