numberOfBays = 2;
bayW = 50;
bayH = 30;
bayD = 50;
eps = 0.01; 
wall_width = 5;
width = numberOfBays * bayW + (numberOfBays) * wall_width + wall_width;
height = bayH + wall_width;
depth = bayD + wall_width*2;

module bay() {
    cube([bayW,bayD,bayH]);
}

module bays() {
    difference(){
        cube([width, depth, height]);
        for (i = [0:numberOfBays-1]) {
        translate([i * (bayW + wall_width)+wall_width, wall_width+eps, wall_width+eps]) {
            bay();
        }
    }
    }
    
}

module cutout(){
    color("red")
    translate([wall_width/2, wall_width/2, height - wall_width + eps])
    cube([width - wall_width, depth - wall_width, wall_width]);
}

difference(){
    bays();
    cutout();

}

//cutout();