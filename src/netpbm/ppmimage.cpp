#include "ppmimage.h"

PPMImage::PPMImage() :  
    length(0),
    width(0) { 
    data = NULL;
}

PPMImage::PPMImage(int length_, int width_) : 
    length(length_), 
    width(width_) {
    data = new Vector3D[length*width];

    for(int i = 0; i < length; ++i) {
        for(int j = 0; j < width; ++j) {
            (*this)(i,j) = Vector3D::zero();
        }
    }
}

PPMImage::PPMImage(const PPMImage& image) {
    length = image.length;
    width = image.width;
    data = new Vector3D[length*width];

    for(int i = 0; i < length; ++i) {
        for(int j = 0; j < width; ++j) {
            (*this)(i,j) = image(i,j);
        }
    }
}

PPMImage& PPMImage::operator=(const PPMImage& image) {
    if(this != &image) {
        if(data != NULL) {
            delete[] data;
        }
        length = image.length;
        width = image.width;

        data = new Vector3D[length*width];
        for(int i = 0; i < length; ++i) {
            for(int j = 0; j < width; ++j) {
                (*this)(i,j) = image(i,j);
            }
        }
    }
    return *this;
}

PPMImage::~PPMImage() {
    if(data != NULL) {
        delete[] data;
    }
}

Vector3D PPMImage::operator()(int i, int j) const {
    return data[i*width+j];
}

Vector3D& PPMImage::operator()(int i, int j) {
    return data[i*width+j];
}

int PPMImage::getLength() const {
    return length;
}

int PPMImage::getWidth() const {
    return width;
}

int PPMImage::getSize() const {
    return width*length;
}
