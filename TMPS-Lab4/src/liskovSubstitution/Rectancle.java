package liskovSubstitution;

public class Rectancle {

    public int length;
    public int width;

    public Rectancle(int length, int width) {
        this.length = length;
        this.width = width;
    }

    public void setLength(int length) {
        this.length = length;
    }

    public void setWidth(int width) {
        this.width = width;
    }

    public int getArea() {
        return this.length * this.width;
    }
}

