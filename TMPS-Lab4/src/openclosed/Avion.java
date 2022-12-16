package openclosed;

public class Avion extends Transport {
    private String people;
    private String article;

    public Avion(String people, String article) {
        this.people = people;
        this.article = article;
    }

    @Override
    public String getPeople() {
        return this.people;
    }

    @Override
    public String getArticle() {
        return this.article;
    }
}