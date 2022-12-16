package dependencyinversion;

public class Conditioner implements Commutable{
    @Override
    public void turnOn(){
        System.out.println("Conditioner: conditioner is on ");
        System.out.println(" ");
    }
    @Override
    public void turnOff(){
        System.out.println("Conditioner: conditioner is off ");
    }
}
