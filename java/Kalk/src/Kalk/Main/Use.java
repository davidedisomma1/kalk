package Kalk.Main;

import Kalk.Classes.Punto;
import Kalk.Classes.Linea;
import Kalk.Classes.Spezzata;
import Kalk.Classes.Rettangolo;

public class Use {

	public static void main(String[] args) {
		Punto p1=new Punto("p1",1,1);
		Punto p2=new Punto("p2",2,2);
		Punto p0=new Punto("p0",0,0);
		Punto p4=new Punto("p4",4,4);
		Linea l1=new Linea("l1",p1,p2);
		Spezzata s1=new Spezzata("s1",p1,p2);

		Punto pX=p1.simmetricoX("PsimmX");
		Punto pY=p1.simmetricoY("PsimmY");
		Punto pO=p1.simmetricoO("PsimmO");
		System.out.println("Punto esempio: "+p1.toString());
		System.out.println("Simmetrico rispetto asse x: "+pX.toString());
		System.out.println("Simmetrico rispetto asse y: "+pY.toString());
		System.out.println("Simmetrico rispetto all'origine: "+pO.toString());
		p1.traslazione(1, 2);
		System.out.println("Punto prova traslato di (1,2): "+p1.toString());
		System.out.println("Distanza dall'origine: "+p1.distanzaO());
		System.out.println("Distanza da PsimmX: "+p1.distanzaP(pX));
		System.out.println("p0+p4 "+p0.plus(p4));
		
		Linea lX=l1.simmetricoX("LsimmX");
		Linea lY=l1.simmetricoY("LsimmY");
		Linea lO=l1.simmetricoO("LsimmO");
		System.out.println("Linea esempio: "+l1.toString());
		System.out.println("Simmetrica rispetto asse x: "+lX.toString());
		System.out.println("Simmetrica rispetto asse y: "+lY.toString());
		System.out.println("Simmetrica rispetto all'origine: "+lO.toString());
		l1.traslazione(1, 2);
		System.out.println("Lunghezza di linea prova: "+l1.lunghezza());
		System.out.println("Linea prova traslata di (1,2): "+l1.toString());
		System.out.println("Punto medio linea prova: "+l1.puntoMedio("pM").toString());
		System.out.println("lx+p4 "+lX.plus(p4));
		System.out.println("lx+ly "+lX.plus(lY));
//		System.out.println("Somma vettoriale tra l1 e LsimmX: "+l1.sommaVettoriale(lX));


		s1=s1.plus(p0);
		Spezzata sX=s1.simmetricoX("SsimmX");
		Spezzata sY=s1.simmetricoY("SsimmY");
		Spezzata sO=s1.simmetricoO("SsimmO");
		System.out.println("Spezzata esempio: "+s1.toString());
		System.out.println("Simmetrica rispetto asse x: "+sX.toString());
		System.out.println("Simmetrica rispetto asse y: "+sY.toString());
		System.out.println("Simmetrica rispetto all'origine: "+sO.toString());
		s1.traslazione(1, 2);
		System.out.println("Spezzata prova traslata di (1,2): "+s1.toString());
		System.out.println("Lunghezza spezzata: "+s1.lunghezza());
		System.out.println("s1+p4 "+s1.plus(p4));
		System.out.println("s1+lX "+s1.plus(lX));
		System.out.println("s1+sX "+s1.plus(sX));
		
		Rettangolo r1=new Rettangolo("r1",new Punto("pr1",0,0),new Punto("pr2",4,0),new Punto("pr3",4,3),new Punto("pr4",0,3));
		Rettangolo rX=r1.simmetricoX("RsimmX");
		Rettangolo rY=r1.simmetricoY("RsimmY");
		Rettangolo rO=r1.simmetricoO("RsimmO");
		System.out.println("Rettangolo esempio: "+r1.toString());
		System.out.println("Simmetrico rispetto asse x: "+rX.toString());
		System.out.println("Simmetrico rispetto asse y: "+rY.toString());
		System.out.println("Simmetrico rispetto all'origine: "+rO.toString());
		r1.traslazione(1, 2);
		System.out.println("Rettangolo prova traslato di (1,2): "+r1.toString());
		System.out.println("Lunghezza rettangolo: "+r1.lunghezza());
		System.out.println("Area rettangolo: "+r1.area());
	}

}
