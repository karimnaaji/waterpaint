#ifndef __PGM_IMAGE_H__
#define __PGM_IMAGE_H__

#include <string>

class PGMImage {
    public:
        PGMImage();
        PGMImage(int length, int width);
        PGMImage(const PGMImage& image);
        PGMImage& operator=(const PGMImage& image);
        ~PGMImage();
    
        float operator()(int i, int j) const;
        float& operator()(int i, int j);
        int getLength() const;
        int getWidth() const;

        void threshold(float threshold, float newValue);
    private:
        int length;
        int width;
        float* data;
};

#endif
