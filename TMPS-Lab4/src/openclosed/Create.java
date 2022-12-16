package openclosed;

public class Create {
    public static Transport createTransport(String type, String people, String article) {

        if ("Avion".equalsIgnoreCase(type))
            return new Avion(people, article);
        else if ("Bus".equalsIgnoreCase(type))
            return new Bus(people, article);
        return null;
    }
}
