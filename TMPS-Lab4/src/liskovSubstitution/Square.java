package liskovSubstitution;

public class Square extends Rectancle {

    public Square(int length, int width) {
        super(length, width);
    }

    @Override
    public void setWidth(int width) {
        super.setWidth(width);
        super.setLength(width);
    }

    @Override
    public void setLength(int length) {
        super.setLength(length);
        super.setWidth(length);
    }
}
