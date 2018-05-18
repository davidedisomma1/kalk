package Kalk.Classes;

public abstract class Tag {
	private String tag;
    public abstract Tag plus(Tag t);
    //bool operator==(const Tag&)const;

    public abstract Tag simmetricoX(String s);
    public abstract Tag simmetricoY(String s);
    public abstract Tag simmetricoO(String s);
    public abstract void traslazione(double nX,double nY);
    
    public Tag(String s) {
    	tag=s;
    }
    public void setTag(String s) {
    	tag=s;
    }
    public String getTag() {
    	return tag;
    }
}
