package Kalk.Classes;
import java.util.ArrayList;
import java.util.ListIterator;

public class Spezzata extends Linea {
	private ArrayList<Punto> punti=new ArrayList<Punto>();
	
	public Spezzata(String s, Punto i, Punto f) {
		super(s, i, f);
	}
	
	public ArrayList<Punto> getLista(){
		return punti;
	}
	

	public String toString() {
		String c="";
		c=c+" ("+getInizio().x()+","+getInizio().y()+"),";
		ListIterator<Punto> i;
		i=punti.listIterator();
		while(i.hasNext()) {
			c=c+"("+i.next().x();
			i.previous();
			c=c+","+i.next().y()+"),";
		}
		c=c+"("+getFine().x()+","+getFine().y()+")";
		return getTag()+c;
	}
	
	public void aggiungi(Punto p) {
		punti.add(p);
	}
	
	public Spezzata plus(Tag t) {
		if(t instanceof Punto) {
			aggiungi(getFine());
			setFine((Punto) t);
			return this;
		}
		if(t instanceof Spezzata) {
			aggiungi(getFine());
			aggiungi(((Linea)t).getInizio());
			((Spezzata)t).punti.forEach(Punto->{aggiungi(Punto);});
			setFine(((Linea)t).getFine());
			return this;
		}
		if(t instanceof Linea) {
			aggiungi(getFine());
			aggiungi(((Linea)t).getInizio());
			setFine(((Linea)t).getFine());
			return this;
		}
		return null;
	}
	
	@Override
	public Spezzata simmetricoX(String s) {
		Spezzata ns=new Spezzata(s,getInizio().simmetricoX(""),getFine().simmetricoX(""));
		punti.forEach((Punto)->{ns.aggiungi(Punto.simmetricoX(s));});
		return ns;
	}

	@Override
	public Spezzata simmetricoY(String s) {
		Spezzata ns=new Spezzata(s,getInizio().simmetricoY(""),getFine().simmetricoY(""));
		punti.forEach((Punto)->{ns.aggiungi(Punto.simmetricoY(s));});
		return ns;
	}

	@Override
	public Spezzata simmetricoO(String s) {
		Spezzata ns=new Spezzata(s,getInizio().simmetricoO(""),getFine().simmetricoO(""));
		punti.forEach((Punto)->{ns.aggiungi(Punto.simmetricoO(s));});
		return ns;
	}

	@Override
	public void traslazione(double nX, double nY) {
		getInizio().traslazione(nX, nY);
		getFine().traslazione(nX, nY);
		punti.forEach((Punto)->{Punto.traslazione(nX, nY);});
	}
	
	public double lunghezza(){
	    double somma=0;
	    if(punti.size()==0) return getInizio().distanzaP(getFine());
	    if(punti.size()==1) return getInizio().distanzaP(punti.get(0)) + punti.get(0).distanzaP(getFine());
	    else{
	        somma=somma+getInizio().distanzaP(punti.get(0));
	        for(int j=0; j!=punti.size()-2; j++){
	            somma=somma+ punti.get(j).distanzaP(punti.get(j+1));
	        }
	        somma=somma+getFine().distanzaP(punti.get(punti.size()-1));
	        return somma;
	    }
	}
}
