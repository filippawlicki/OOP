package pl.edu.pg.eti.ksg.po.lab1.transformacje;

import java.util.ArrayList;
public class ZlozenieTransformacji3DList implements Transformacja3D {
  public ArrayList<Transformacja3D> myList;

  public ZlozenieTransformacji3DList(int rozmiar) {this.myList = new ArrayList<Transformacja3D>(rozmiar);}

  @Override
  public Transformacja3D getTransformacjaOdwrotna3D() throws BrakTransformacjiOdwrotnejException {
    ZlozenieTransformacji3DList z = new ZlozenieTransformacji3DList(this.myList.size());
    for(int i = 0; i < this.myList.size(); i++) {
      z.myList.add(this.myList.get(i).getTransformacjaOdwrotna3D());
    }
    return z;
  }

  @Override
  public Punkt3D transformuj3D(Punkt3D p){
    for(int j = 0; j < this.myList.size(); j++){
      p =  this.myList.get(j).transformuj3D(p);
      System.out.println(p);
    }
    return p;
  }

  public void add(Transformacja3D t) {
    this.myList.add(t);
  }
}
