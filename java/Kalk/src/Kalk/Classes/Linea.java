package Kalk.Classes;

public class Linea extends Tag {
	private Punto inizio,fine;

	public Linea(String s, Punto i, Punto f) {
		super(s);
		inizio=i;
		fine=f;
	}
	
	public void setInizio(Punto p) {
		inizio=p;
	}
	
	public void setFine(Punto p) {
		fine=p;
	}

	@Override
	public Spezzata plus(Tag t) {
		if(t instanceof Punto) {
			Spezzata s=new Spezzata(getTag(),inizio,(Punto)t);
			s.aggiungi(fine);
			return s;
		}
		if(t instanceof Linea) {
		    Spezzata s=new Spezzata(getTag(),getInizio(), ((Linea) t).getFine());
		    s.aggiungi(getFine());
		    s.aggiungi(((Linea)t).getInizio());
		    return s;
		}
		return null;
	}

	@Override
	public Linea simmetricoX(String s) {
		return new Linea(s,inizio.simmetricoX(""),fine.simmetricoX(""));
	}

	@Override
	public Linea simmetricoY(String s) {
		return new Linea(s,inizio.simmetricoY(""),fine.simmetricoY(""));
	}

	@Override
	public Linea simmetricoO(String s) {
		return new Linea(s,inizio.simmetricoO(""),fine.simmetricoO(""));
	}

	@Override
	public void traslazione(double nX, double nY) {
		inizio.traslazione(nX, nY);
		fine.traslazione(nX, nY);
	}
	
	public Punto getInizio() {
		return inizio;
	}
	
	public Punto getFine() {
		return fine;
	}
	
	public String toString() {
	    return getTag() + "(" + inizio.x() +
	    			"," + inizio.y() + "),(" + fine.x() + "," + fine.y() + ")";
	}
	
	public double lunghezza(){
	    return inizio.distanzaP(fine);
	}
	
	public Punto puntoMedio(String s){
	    return new Punto(s,((inizio.x()+fine.x())/2),((inizio.y()+fine.y())/2));
	}
	
	public Linea sommaVettoriale(Linea l){
	    Linea vettoreUno=new Linea(getTag(),inizio,fine);
	    vettoreUno.traslazione(l.getFine().x()-vettoreUno.getInizio().x(),l.getFine().y()-vettoreUno.getInizio().y());
	    return new Linea("",l.getInizio(),vettoreUno.getFine());
	}

}
