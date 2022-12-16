package interfacesegregation;

public class Spotify implements Music{
    @Override
    public void playAudio(){
        System.out.println("Porneste audio");
    }
}
