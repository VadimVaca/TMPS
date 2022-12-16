package openclosed;

public abstract  class Transport {
    public abstract String getPeople();

    public abstract String getArticle();

    @Override
    public String toString(){
        return "Transport oameni = " + this.getPeople() + ", Transport marfa = " + this.getArticle();
    }
}
