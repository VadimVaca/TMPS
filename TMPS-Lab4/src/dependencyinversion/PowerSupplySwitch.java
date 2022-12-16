package dependencyinversion;

public class PowerSupplySwitch implements Breaker {
    public Commutable client;
    public boolean on;

    public PowerSupplySwitch(Commutable client) {
        this.client = client;
        this.on = false;
    }
    public boolean isOn() {
        return this.on;
    }
    public void press(){
        boolean checkOn = isOn();
        if (checkOn) {
            client.turnOff();
            this.on = false;
        } else {
            client.turnOn();
            this.on = true;
        }
}
}
