package liskovSubstitution;

public class Main {
    public static void main(String[] args) {

        Rectancle rectancle1 = new Rectancle(8, 7);
        System.out.println("Aria dreptunghiului este " + rectancle1.getArea());

        Square square1 = new Square(10, 9);
        System.out.println("Aria patratului este " + square1.getArea());
    }

}

