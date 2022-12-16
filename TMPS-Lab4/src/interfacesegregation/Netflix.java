package interfacesegregation;

public class Netflix implements Movie{
    @Override
    public void playVideo(){
        System.out.println("Porneste video");
    }
}
