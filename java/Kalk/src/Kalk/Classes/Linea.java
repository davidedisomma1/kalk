package Kalk.Classes;

public class Linea extends Tag {
	Punto inizio,fine;

	public Linea(String s, Punto i, Punto f) {
		super(s);
		inizio=i;
		fine=f;
	}

	@Override
	public Tag plus(Tag t) {
		// TODO Auto-generated method stub
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

}
