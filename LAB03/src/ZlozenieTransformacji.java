package pl.edu.pg.eti.ksg.po.lab1.transformacje;

public class ZlozenieTransformacji implements Transformacja {
  public Transformacja[] tab;

  public ZlozenieTransformacji(int rozmiar) {
    this.tab = new Transformacja[rozmiar];
  }

  @Override
  public Transformacja getTransformacjaOdwrotna() throws BrakTransformacjiOdwrotnejException {
    ZlozenieTransformacji z = new ZlozenieTransformacji(this.tab.length);
    for (int i = 0; i < this.tab.length; i++) {
      z.tab[i] = this.tab[i].getTransformacjaOdwrotna();
    }
    return z;
  }

  @Override
  public Punkt transformuj(Punkt p) {
    for (int i = 0; i < tab.length; i++) {
      p = tab[i].transformuj(p);
    }
    return p;
  }

}
