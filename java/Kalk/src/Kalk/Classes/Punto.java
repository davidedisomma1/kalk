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
	public Tag plus(Tag t) {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public Tag simmetricoX(String s) {
	    return new Punto(s,x(),-y());
	}

	@Override
	public Tag simmetricoY(String s) {
		return new Punto(s,-x(),y());
	}

	@Override
	public Tag simmetricoO(String s) {
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
