#include <iostream>

#include "png.h"

int main(int argc, char* argv[])
{

    if(argc < 2)
    {
        std::cout << "File name expected:" << std::endl 
            << "Usage: " << argv[0] << " filename.png" << std::endl;
        return 0;
    }

    std::string filename(argv[1]);

    png_image image;
    memset(&image, 0, (sizeof image));
    image.version = PNG_IMAGE_VERSION;

    if (png_image_begin_read_from_file(&image, filename.c_str()) != 0)
    {
        std::cout << "Width: " << image.width
            << " Height: " << image.height << std::endl
            << "Message: " << image.message << std::endl
            << "Version: " << image.version << std::endl;
    }
    else
    {
        std::cout << "Can't read image: " << image.warning_or_error << std::endl;
    }
}