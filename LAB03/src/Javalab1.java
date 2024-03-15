package pl.edu.pg.eti.ksg.po.lab1.transformacje;

import com.sun.jdi.ObjectReference;
import pl.edu.pg.eti.ksg.po.lab1.transformacje.Obrot;
import pl.edu.pg.eti.ksg.po.lab1.transformacje.Translacja;
import pl.edu.pg.eti.ksg.po.lab1.transformacje.Skalowanie;
import pl.edu.pg.eti.ksg.po.lab1.transformacje.BrakTransformacjiOdwrotnejException;
import pl.edu.pg.eti.ksg.po.lab1.transformacje.Punkt;
import pl.edu.pg.eti.ksg.po.lab1.transformacje.Transformacja;

public class Javalab1 {
  public static void main(String[] args) {
    /*
     * Konstrukcja językowa try {} catch (...){} służy do
     * obsługi wyjątków. Kod w bloku try jest monitorowany
     * pod kątem wystąpienia wyjątku bądź wyjątków
     * wspomnianych na początku bloku/bloków catch.
     * Jeżeli gdzieś w bloku try wystąpi wyjątek, to sterowanie
     * zostanie natychmiast przeniesione do bloku catch.
     * Tam powinien znajdować się kod obsługujący wyjątek.
     * Może to być np. wypisanie stosu wywołań na wyjście błędów
     * lub zapisanie wyjątku w logach, lub wyrzucenie (zgłoszenie)
     * innego wyjątku lepiej opisującego sytuacje (można załączyć
     * wyjątek który zainicjował to zdarzenie patrz. Konstruktor
     * klasy java.lang.Exception)
     */
//    try {
//      Punkt p1 = Punkt.E_X;
//      System.out.println(p1);
//      Transformacja tr = new Translacja(5, 6);
//      System.out.println(tr);
//      Punkt p2 = tr.transformuj(p1);
//      System.out.println(p2);
//      Transformacja trr = tr.getTransformacjaOdwrotna();
//      System.out.println(trr);
//      Punkt p3 = trr.transformuj(p2);
//      System.out.println(p3);
//
//    } catch (BrakTransformacjiOdwrotnejException ex) {
//      ex.printStackTrace();
//    }
//    System.out.println();
//
//    try {
//      Punkt p1 = new Punkt(2, 2);
//      System.out.println(p1);
//      Transformacja tr2 = new Skalowanie(5, 4);
//      System.out.println(tr2);
//      Punkt p2 = tr2.transformuj(p1);
//      System.out.println(p2);
//      Transformacja trr2 = tr2.getTransformacjaOdwrotna();
//      System.out.println(trr2);
//      Punkt p3 = trr2.transformuj(p2);
//      System.out.println(p3);
//    } catch (BrakTransformacjiOdwrotnejException ex) {
//      ex.printStackTrace();
//    }
//    System.out.println();
//
//    try {
//      Punkt p1 = new Punkt(2, 2);
//      Transformacja tr2 = new Skalowanie(5, 0);
//      System.out.println(tr2);
//      System.out.println(p1);
//      Punkt p2 = tr2.transformuj(p1);
//      System.out.println(p2);
//      Transformacja trr2 = tr2.getTransformacjaOdwrotna();
//      System.out.println(trr2);
//      Punkt p3 = trr2.transformuj(p2);
//      System.out.println(p3);
//    } catch (BrakTransformacjiOdwrotnejException ex) {
//      ex.printStackTrace();
//    }
//    System.out.println();

//    try {
//      Punkt p1 = new Punkt(2, 2);
//      Transformacja tr2 = new Obrot(5);
//      System.out.println(tr2);
//      System.out.println(p1);
//      Punkt p2 = tr2.transformuj(p1);
//      System.out.println(p2);
//      Transformacja trr2 = tr2.getTransformacjaOdwrotna();
//      System.out.println(trr2);
//      Punkt p3 = trr2.transformuj(p2);
//      System.out.println(p3);
//    } catch (BrakTransformacjiOdwrotnejException ex) {
//      ex.printStackTrace();
//    }
//    System.out.println();

//    try {
//      Punkt p1 = new Punkt(2, 2);
//      System.out.println(p1);
//      ZlozenieTransformacji z = new ZlozenieTransformacji(2);
//      z.tab[0] = new Obrot(3.141592653);
//      z.tab[1] = new Skalowanie(5, 2);
//      Punkt p2 = z.transformuj(p1);
//      System.out.println(p2);
//      Transformacja zt2 = z.getTransformacjaOdwrotna();
//    } catch (BrakTransformacjiOdwrotnejException ex) {
//      ex.printStackTrace();
//    }
//    System.out.println();

    try {
      Punkt3D p1 = new Punkt3D(2, 2, 2);
      System.out.println("Przed Zlozeniem: " + p1);
      ZlozenieTransformacji3DTab z = new ZlozenieTransformacji3DTab(2);
      z.tab[0] = new Obrot3D(30, 60, 90);
      z.tab[1] = new Translacja3D(1, 2, 3);
      System.out.println(z.tab[0]);
      System.out.println(z.tab[1]);
      Punkt3D p2 = z.transformuj3D(p1);
      System.out.println("Po 1 Zlozeniu Transformacji: " + p2);
      ZlozenieTransformacji3DList z2 = new ZlozenieTransformacji3DList(2);
      z2.add(new Obrot3D(50, 80, 70));
      z2.add(new Translacja3D(9,8,7));
      System.out.println(z2.myList.get(0));
      System.out.println(z2.myList.get(1));
      Punkt3D p3 = z2.transformuj3D(p2);
      System.out.println("Po 2 zlozeniu trasfromacji: " + p3);
      Transformacja3D z3 = z.getTransformacjaOdwrotna3D();
      Transformacja3D z4 = z2.getTransformacjaOdwrotna3D();
      Punkt3D p4 = z4.transformuj3D(p3);
      Punkt3D p5 = z3.transformuj3D(p4);
      System.out.println("Po odwroconych transformacjach: " + p5);

//      Punkt3D p6 = new Punkt3D(1, 1, 1);
//      System.out.println(p6);
//      Transformacja3D tr = new Translacja3D(1, 2 , 3);
//      Punkt3D p7 = tr.transformuj3D(p6);
//      System.out.println(p7);
//      Transformacja3D tr1 = new Obrot3D(30, 30 , 30);
//      Punkt3D p8 = tr1.transformuj3D(p7);
//      System.out.println(p8);
//      Punkt3D p9 = tr1.getTransformacjaOdwrotna3D().transformuj3D(p8);
//      Punkt3D p10 = tr.getTransformacjaOdwrotna3D().transformuj3D(p9);
//      System.out.println(p10);

    } catch (BrakTransformacjiOdwrotnejException ex) {
      ex.printStackTrace();
    }
  }
}