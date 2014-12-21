#ifndef __NET_PBM_LOADER_H__
#define __NET_PBM_LOADER_H__

#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <ctime>

#include "pgmimage.h"
#include "ppmimage.h"

#define COLOR_LEVELS 255
#define PPM_EXT ".ppm"
#define PGM_EXT ".pgm"

struct s_NetPBMFileDesc {
	unsigned int length;
	unsigned int width;
	unsigned int colors;
	unsigned char* memblock;
};

class NetPBMLoader {
    public:
        NetPBMLoader() {};
        ~NetPBMLoader() {};
        PGMImage loadPGM(std::string filename);
        PPMImage loadPPM(std::string filename);
        void savePGM(PGMImage& pgmimage, std::string filename);
        void savePPM(PPMImage& ppmimage, std::string filename);

    private:
        void read(std::string filename, std::string ext, s_NetPBMFileDesc* fileDesc);
};

#endif
