
var Walker = function() {
    this.x = width/2;
    this.y = height/2;
};

Walker.prototype.display = function() {
    stroke(0, 0, 0);
    fill(64, 0, 255);
    noStroke();
    ellipse(this.x, this.y, width, height);
};

Walker.prototype.walk = function() {
    

     *var generator = new Random(1);
    var standardDeviation = 2;
    var mean = 0;
    ;
        var xStepSize = standardDeviation * generator.nextGaussian() + mean;
        var yStepSize = standardDeviation * generator.nextGaussian() + mean;
      
        var step_size = 6; 
    var choice = floor(random(4));
    if (choice === 0) {
        this.x += step_size;
    } else if (choice === 1) {
        this.x -= step_size;
    } else if (choice === 2) {
        this.y += step_size ;
    } else {
        this.y -= step_size;
    } 
};

var w = new Walker();

draw = function() {
    // I would personaly give either walk a paramter with a fixed/dynamic input
    // or I would put w.walk() in a for loop and iterate over f.e. 
    // for (var i = 0; i < 10; ++i) 
    w.walk();
    w.display();
};
