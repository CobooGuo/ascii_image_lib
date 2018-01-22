#include <iostream>

#include "ascii_image_lib.h"

using namespace std;

void ascii_image_test2(void);
void ascii_image_test3(void);
void ascii_image_test4(void);
int main()
{
     ascii_image_t* pascii_image =  ascii_image_create('-', 20, 20);

    if(NULL != pascii_image){
        //ascii_image_print(pascii_image);

        ascii_image_wirte_ch(pascii_image, 'A', 0, 0);
        ascii_image_wirte_ch(pascii_image, 'S', 10, 10);
        ascii_image_wirte_ch(pascii_image, 'E', 19, 19);

         ascii_image_wirte_ch(pascii_image, 'E', 119, 19);
        //ascii_image_read_ch(pascii_image,char* ch, uint32_t xpos, uint32_t ypos);

        ascii_image_print(pascii_image);

        ascii_image_destroy(pascii_image);
    }
    //cout << "Hello world!" << endl;
    //ascii_image_test2();

    //cout << "Hello world!" << endl;
    //ascii_image_test3();

    cout << "Hello world!" << endl;
    ascii_image_test4();
    return 0;
}

void ascii_image_test2(void)
{
     ascii_image_t* pascii_image =  ascii_image_create(0, 20, 20);

    if(NULL != pascii_image){
        //ascii_image_print(pascii_image);

        ascii_image_wirte_ch(pascii_image, 'A', 0, 0);
        ascii_image_wirte_ch(pascii_image, 'S', 10, 10);
        ascii_image_wirte_ch(pascii_image, 'E', 19, 19);

         ascii_image_wirte_ch(pascii_image, 'E', 119, 19);
        //ascii_image_read_ch(pascii_image,char* ch, uint32_t xpos, uint32_t ypos);

        ascii_image_print(pascii_image);

        ascii_image_destroy(pascii_image);
    }
}

void ascii_image_test3(void)
{
    char * pchdemo = "Hello, World.";
    char pdemo_buf[50]= {0};

     ascii_image_t* pascii_image =  ascii_image_create(0, 20, 20);

    if(NULL != pascii_image){
        //ascii_image_print(pascii_image);

        ascii_image_wirte_string(pascii_image, pchdemo, strlen(pchdemo), 9, 1);

        ascii_image_read_string(pascii_image,pdemo_buf,20, 12, 1);
        printf(pdemo_buf);

        ascii_image_print(pascii_image);

        ascii_image_destroy(pascii_image);
    }
}
void ascii_image_test4(void)
{
    char * pchdemo = "Hello, World.";

     ascii_image_t* pascii_image =  ascii_image_create(0, 20, 20);

    if(NULL != pascii_image){
        //ascii_image_print(pascii_image);

        ascii_image_wirte_string(pascii_image, pchdemo, strlen(pchdemo), 9, 1);
        ascii_image_wirte_ch_reptimes(pascii_image, '~', strlen(pchdemo), 9, 1+1);

        ascii_image_print(pascii_image);

        ascii_image_destroy(pascii_image);
    }
}
