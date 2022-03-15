#ifndef IMAGE_H
#define IMAGE_H




        #include <iostream>
        #include<QString>
//        using namespace std;
        class Image
        {
        protected:
            QString image_address;
        public:
            Image();
            Image(QString add);
            void set_image_address(QString x);
            QString Image_address();
        };


#endif // IMAGE_H
