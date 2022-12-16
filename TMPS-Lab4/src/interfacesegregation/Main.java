package interfacesegregation;

public class Main {
    public static void main(String[] args) {
        Youtube youtube1= new Youtube();
        System.out.println("Actiunile pentru Youtube sunt: ");
        youtube1.playAudio();
        youtube1.playVideo();
        System.out.println(" ");

        Spotify spotify1= new Spotify();
        System.out.println("Actiunile pentru Spotify sunt: ");
        spotify1.playAudio();
        System.out.println(" ");

        Netflix netflix1= new Netflix();
        System.out.println("Actiunile pentru Netflix sunt: ");
        netflix1.playVideo();
    }
}
