package dependencyinversion;

public interface Breaker {
    boolean isOn();
    void press();
}
