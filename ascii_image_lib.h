#ifndef ASCIIIMAGELIB_H_INCLUDED
#define ASCIIIMAGELIB_H_INCLUDED

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _ascii_image{
    uint32_t width;
    uint32_t height;
    char *pdata;
}ascii_image_t;

#ifdef __cplusplus
extern "C"{
#endif

ascii_image_t* ascii_image_create(char ch_def, uint32_t width, uint32_t height);
void ascii_image_destroy(ascii_image_t *pascii_image);

int ascii_image_wirte_ch(ascii_image_t *pascii_image, char ch, uint32_t xpos, uint32_t ypos);
int ascii_image_read_ch(ascii_image_t *pascii_image,char* ch, uint32_t xpos, uint32_t ypos);

int ascii_image_wirte_string(ascii_image_t *pascii_image, char *str,int len,  uint32_t xpos_begin, uint32_t ypos_begin);
int ascii_image_read_string(ascii_image_t *pascii_image,char* str_buf,int len, uint32_t xpos_begin, uint32_t ypos_begin);

int ascii_image_wirte_ch_reptimes(ascii_image_t *pascii_image, char ch, int len_times ,uint32_t xpos, uint32_t ypos);

int ascii_image_print(ascii_image_t * pascii_image);

#ifdef __cplusplus
}
#endif

#endif // ANSICIMAGELIB_H_INCLUDED
