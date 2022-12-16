package interfacesegregation;

public class Youtube implements Movie, Music{
    @Override
    public  void playVideo(){
        System.out.println("Porneste video");
    }
    @Override
    public void playAudio(){
        System.out.println("Porneste audio");
    }
}
