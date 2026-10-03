import processing.core.PApplet;

public class Main extends PApplet {
    Walker localWalker; 

    public void setup() {
        background(255);
        localWalker = new Walker(this);
    }

    public void settings() {
        size(700, 600);
    }

    public void draw() {
        localWalker.step();
        localWalker.show();
    }

    public static void main(String[] args) {
        PApplet.main("Main");
    }
}
