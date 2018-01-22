
#include "ascii_image_lib.h"

static void debug_ascii_image(ascii_image_t *pascii_image)
{
   if(pascii_image != NULL)
    {
        printf("width:%d\n", pascii_image->width);
        printf("height:%d\n", pascii_image->height);
        printf("pdata addr:%p\n", pascii_image->pdata);
    }
}

ascii_image_t* ascii_image_create(char ch_def, uint32_t width, uint32_t height)
{

    ascii_image_t *ascii_image = (ascii_image_t *)malloc(sizeof(ascii_image_t));
    if(NULL == ascii_image){
        return NULL;
    }

    ascii_image->pdata = (char*) malloc(width*height);
    if(NULL == ascii_image->pdata){
        return NULL;
    }
    //if(ch_def < 0x20)
    if(ch_def < 0x0)
        memset(ascii_image->pdata, 0x20, width*height );
    else
        memset(ascii_image->pdata, ch_def, width*height );

    ascii_image->width = width;
    ascii_image->height = height;

    //debug_ascii_image(ascii_image);

    return ascii_image;
}

void ascii_image_destroy(ascii_image_t *pascii_image)
{
    //debug_ascii_image(pascii_image);

    if(pascii_image != NULL)
    {
        if(pascii_image->pdata != NULL)
            free(pascii_image->pdata);

        free(pascii_image);
        pascii_image = NULL;
    }
}

int ascii_image_wirte_ch(ascii_image_t *pascii_image, char ch, uint32_t xpos, uint32_t ypos)
{
    //debug_ascii_image(pascii_image);
     if(pascii_image != NULL)
    {
        if((ypos < pascii_image->height) && (xpos < pascii_image->width))
            //*(pascii_image->pdata + ypos*pascii_image->width + xpos) = ch;
            //pascii_image->pdata[ypos*pascii_image->width + xpos] = ch;
            *((char*)(pascii_image->pdata) + ypos*(pascii_image->width) + xpos) = ch;
        else
             printf("%s:wirte xpos:%d ypos:%d error\n", __func__, xpos, ypos);

        //ascii_image_print(pascii_image);
    }else{
        printf("%s,NULL ptr\n", __func__);
        return -1;
    }
    return 0;
}
int ascii_image_read_ch(ascii_image_t *pascii_image,char* ch, uint32_t xpos, uint32_t ypos)
{
    //debug_ascii_image(pascii_image);
     if(pascii_image != NULL)
    {
        if(ypos < pascii_image->height && xpos < pascii_image->width )
            *ch = *(pascii_image->pdata+ ypos*pascii_image->width + xpos);
        else
            printf("%s:read xpos:%d ypos:%d error\n", __func__, xpos, ypos);
    }else{
        printf("%s,NULL ptr\n", __func__);
        return -1;
    }
    return 0;
}

// dot not auto line feed
int ascii_image_wirte_string(ascii_image_t *pascii_image, char *str,int len,  uint32_t xpos_begin, uint32_t ypos_begin)
{
    for(int i=0 ; i < len; i++)
        ascii_image_wirte_ch(pascii_image, *(str+i), xpos_begin+i, ypos_begin);
}
int ascii_image_read_string(ascii_image_t *pascii_image,char* str_buf,int len, uint32_t xpos_begin, uint32_t ypos_begin)
{
    for(int i=0 ; i < len; i++)
        ascii_image_read_ch(pascii_image, (str_buf+i), xpos_begin+i, ypos_begin);
}

int ascii_image_wirte_ch_reptimes(ascii_image_t *pascii_image, char ch,int len_times, uint32_t xpos_begin, uint32_t ypos_begin)
{
    for(int i=0 ; i < len_times; i++)
        ascii_image_wirte_ch(pascii_image, ch, xpos_begin+i, ypos_begin);
}

int ascii_image_print(ascii_image_t * pascii_image)
{
    //debug_ascii_image(pascii_image);
     if(pascii_image != NULL)
    {
        for(int i=0; i < pascii_image->height; i++){
            for(int j=0; j < pascii_image->width; j++){
                putchar(*(pascii_image->pdata+i*pascii_image->width + j));
            }
            putchar('\r');
            putchar('\n');
        }
    }else{
        printf("%s,NULL ptr\n", __func__);
        return -1;
    }
    return 0;
}
