package Kalk.Classes;

public class Punto extends Tag {
	
	private double X;
	private double Y;
	
	public Punto(String s,double x,double y) {
		super(s);
		X=x;
		Y=y;
	}
	
	public double x() {
		return X;
	}
	
	public double y() {
		return Y;
	}
	
	@Override
	public Linea plus(Tag t) {
		return new Linea(getTag()+t.getTag(),this,(Punto)t);
	}

	@Override
	public Punto simmetricoX(String s) {
	    return new Punto(s,x(),-y());
	}

	@Override
	public Punto simmetricoY(String s) {
		return new Punto(s,-x(),y());
	}

	@Override
	public Punto simmetricoO(String s) {
		return new Punto(s,-x(),-y());
	}

	@Override
	public void traslazione(double nX, double nY) {
	    X=X+nX;
	    Y=Y+nY;
	}
	
	public String toString() {
	    String stringaOut="";
	    return stringaOut+getTag()+"("+x()+","+y()+")";
	}

}
