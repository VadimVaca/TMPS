package single;

public class Main {
    public static void main(String[] args) {
        Actor actor1= new Actor(" Tom ", "Cruise ", " principal");
        PrintActor printActor1= new PrintActor();
        printActor1.printActorToConsole(actor1);

        Actor actor2= new Actor(" Jenifer ", "Eniston ", " sedundar");
        printActor1.printActorToConsole(actor2);
    }
}
