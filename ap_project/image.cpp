#include "image.h"



    Image::Image(QString add) {
        image_address = add;
    }
    void Image::set_image_address(QString x) {
        image_address = x;
    }
    QString Image::Image_address() {
        return image_address;
    }

