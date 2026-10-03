import processing.core.PApplet;

public class Walker {
    PApplet p; 
    int x, y;

    Walker(PApplet p) {
        this.p = p;
        x = p.width / 2; // in java we dont need to write this.x unless I would get x as an parameter (compare p!)
        y = p.height / 2; 
    }

    void show() {
        p.stroke(0);
        p.point(x, y);
    }

    void step() {
        int choice = p.floor(p.random(4));
        if (choice == 0) this.x++;
        else if (choice == 1) this.x--;
        else if (choice == 2) this.y++;
        else this.y--;
    }

    
}


