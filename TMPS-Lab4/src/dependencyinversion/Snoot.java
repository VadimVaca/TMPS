package dependencyinversion;

public class Snoot implements Commutable{
    @Override
    public void turnOn() {
        System.out.println("Light snoot: Snoot turned on...");
    }
    @Override
    public void turnOff() {
        System.out.println("Light snoot: Snoot turned off...");
    }
}
