package Kalk.Classes;

import java.util.ListIterator;

public class Rettangolo extends Spezzata {

	public Rettangolo(String s, Punto a, Punto b, Punto c, Punto d) {
		super(s, a, a);
		aggiungi(b);
		aggiungi(c);
		aggiungi(d);
	}
	
	public String toString() {
		String c="";
		c=c+" ("+getInizio().x()+","+getInizio().y()+"),";
		ListIterator<Punto> i;
		i=getLista().listIterator();
		while(i.hasNext()) {
			c=c+"("+i.next().x();
			i.previous();
			c=c+","+i.next().y()+"),";
		}
		return getTag()+c;
	}
	
	public double lunghezza() {
		return (getInizio().distanzaP(getLista().get(0)) + getInizio().distanzaP(getLista().get(2)))*2;
	}
	
	public double area() {
		return getInizio().distanzaP(getLista().get(0)) * getInizio().distanzaP(getLista().get(2));
	}
	
	public Rettangolo simmetricoX(String s) {
		Spezzata sp=super.simmetricoX(s);
		return new Rettangolo(getTag(),sp.getInizio(),sp.getLista().get(0),sp.getLista().get(1),sp.getLista().get(2));
	}
	
	public Rettangolo simmetricoY(String s) {
		Spezzata sp=super.simmetricoY(s);
		return new Rettangolo(getTag(),sp.getInizio(),sp.getLista().get(0),sp.getLista().get(1),sp.getLista().get(2));
	}
	
	public Rettangolo simmetricoO(String s) {
		Spezzata sp=super.simmetricoO(s);
		return new Rettangolo(getTag(),sp.getInizio(),sp.getLista().get(0),sp.getLista().get(1),sp.getLista().get(2));
	}
	
	public void traslazione(double nX, double nY) {
		getInizio().traslazione(nX, nY);
		getLista().forEach((Punto)->{Punto.traslazione(nX, nY);});
	}
}
