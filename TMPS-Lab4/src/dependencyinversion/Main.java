package dependencyinversion;

import org.testng.annotations.Test;

public class Main {
    @Test
    public void testPress() throws Exception {
        Commutable switchableSnoot=new Snoot();
        Breaker PowerBreaker=new PowerSupplySwitch(switchableSnoot);
        PowerBreaker.press();
        PowerBreaker.press();
        Commutable commutableConditioner=new Conditioner();
        Breaker fanPowerSwitch=new PowerSupplySwitch(commutableConditioner);
        fanPowerSwitch.press();
        fanPowerSwitch.press();
    }
}

