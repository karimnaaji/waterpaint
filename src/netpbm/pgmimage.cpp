#include "pgmimage.h"

PGMImage::PGMImage() : 
    length(0),
    width(0) { 
    data = NULL;
}

PGMImage::PGMImage(int length_, int width_) : 
    length(length_), 
    width(width_) {
    data = new float[length*width];

    for(int i = 0; i < length; ++i) {
        for(int j = 0; j < width; ++j) {
            (*this)(i,j) = 0.0;
        }
    }
}

PGMImage::PGMImage(const PGMImage& image) {
    length = image.length;
    width = image.width;
    data = new float[length*width];

    for(int i = 0; i < length; ++i) {
        for(int j = 0; j < width; ++j) {
            (*this)(i,j) = image(i,j);
        }
    }
}

PGMImage& PGMImage::operator=(const PGMImage& image) {
    if(this != &image) {
        if(data != NULL) {
            delete[] data;
        }
        length = image.length;
        width = image.width;

        data = new float[length*width];
        for(int i = 0; i < length; ++i) {
            for(int j = 0; j < width; ++j) {
                (*this)(i,j) = image(i,j);
            }
        }
    }
    return *this;
}

PGMImage::~PGMImage() {
    if(data != NULL) {
        delete[] data;
    }
}

float PGMImage::operator()(int i, int j) const {
    return data[i*width+j];
}

float& PGMImage::operator()(int i, int j) {
    return data[i*width+j];
}

int PGMImage::getLength() const {
    return length;
}

int PGMImage::getWidth() const {
    return width;
}

void PGMImage::threshold(float threshold, float newValue) {
    for(int i = 0; i < length; ++i) {
        for(int j = 0; j < width; ++j) {
            if((*this)(i,j) > threshold) {
                (*this)(i,j) = newValue;
            }
        }
    }
}
