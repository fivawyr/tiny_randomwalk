import processing.core.PApplet;

public class Walker {
    PApplet p; 
    float x, y;

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
        //third approche, using probabilitys for defining the steps chance. This is highly useful when we dont want acutally randomness which we need for aaalot of concepts in simulations. For a classic walk, the randon approche would be enough though -> its called random walk for a reason
        float r = p.random(1);
        
        if (r < 0.1) {
            this.x = p.mouseX;
            this.y = p.mouseY;
        }
        else if (r < 0.4) this.x++;
        else if (r < 0.6) this.x--;
        else if (r < 0.8) this.y++;
        else this.y--;


        /*
        float xstep = p.random(-1, 1); //instead of using random(3) -- 1, we can just use three steps on both asixes to get the entire moveset 
        float ystep = p.random(-1, 1);
        this.x += xstep;
        this.y += ystep;
        int choice = p.floor(p.random(4));
        if (choice == 0) this.x++;
        else if (choice == 1) this.x--;
        else if (choice == 2) this.y++;
        else this.y--;
        */
    }

    
}


