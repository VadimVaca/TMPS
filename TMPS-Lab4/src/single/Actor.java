package single;

public class Actor {
    private String name;
    private String prenume;
    private String rol;

    public Actor(String name, String prenume, String rol) {
        this.name = name;
        this.prenume = prenume;
        this.rol = rol;
    }

    public String getName() {
        return name;
    }

    public String getPrenume() {
        return prenume;
    }


}
