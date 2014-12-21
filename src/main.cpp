#include <iostream>
#include <cstdlib>
#include <ctime>  
#include <cmath>

#include "ppmimage.h"
#include "netpbmloader.h"

typedef Vector3D Color;

inline float rand_0_1() {
    return (float) rand() / RAND_MAX;
}

inline float clamp(float min, float max, float val) {
    return val < min ? min : (val > max ? max : val);
}

inline Color rand_color() {
    return Color(rand_0_1()*35+150, rand_0_1()*35+130, rand_0_1()*45+160);
}

int main(int argc, char** argv) {
    srand(time(NULL));

    NetPBMLoader loader;

    int size = 1024;
    int k = 20;
    int a = 200;
    Color background = Color(248, 250, 245);

    PPMImage image(size, size);

    for(int i = 0; i < image.getLength(); i++) {
        for(int j = 0; j < image.getWidth(); j++) {
            image(i, j) = background;
        }
    }

    for(int j = 0; j < k; j++) {
        int y = rand_0_1() * size;
        float s = (rand_0_1() / 15.0) + 0.01;

        Color c = rand_color();
        
        for(int x = 0; x < size; x++) {
            float step = 100;
            float w = s / step;

            s += rand_0_1() * 0.05 - 0.025;

            if(s > -0.009 && s < 0.009) {
                c = rand_color();                       
            }

            for(int i = 0; i < step; i++) {
                int y1 = y + a * sin(i*w);
                int y2 = y - a * sin(i*w);
                
                y1 = clamp(0, size, y1);
                y2 = clamp(0, size, y2);

                float reduce = 0.1 - i / (step*10);

                image(x, y1) = image(x, y1) + (c - image(x, y1)) * reduce;
                image(x, y2) = image(x, y2) + (c - image(x, y2)) * reduce;
            }
        }
    }

    loader.savePPM(image, "image");

    return EXIT_SUCCESS;
}
