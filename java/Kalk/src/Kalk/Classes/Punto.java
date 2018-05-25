package Kalk.Classes;
import java.lang.Math;

public class Punto extends Tag {
	
	private double X;
	private double Y;
	
	public Punto(String s,double x,double y) {
		super(s);
		X=x;
		Y=y;
	}
	

	
	public void setX(double x) {
		X=x;
	}
	
	public void setY(double y) {
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
		if(t instanceof Punto)
		return new Linea(getTag()+t.getTag(),this,(Punto)t);
		return null;
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
	    return getTag()+"("+x()+","+y()+")";
	}
	
	public double distanzaO(){
	    return (Math.sqrt(Math.pow(x(),2)+Math.pow(y(),2)));
	}
	
	public double distanzaP(Punto p){
	    return (Math.sqrt(Math.pow(x()-p.x(),2)+Math.pow(y()-p.y(),2)));
	}
}
