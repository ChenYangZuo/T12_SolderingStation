//
// Created by zuo-c on 2022/6/12.
//

#ifndef T12_V1_2_EMOJI_H
#define T12_V1_2_EMOJI_H

#include "u8g2.h"

static unsigned char emoji[10][208] U8X8_PROGMEM ={
        {
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x7f,0x00,0x00,0xfe,0x00,0x00,
                0x00,0xe0,0xff,0x01,0x80,0xff,0x03,0x00,0x00,0xf0,0xff,0x03,0xc0,0xff,0x0f,0x00,
                0x00,0xf8,0xff,0x07,0xe0,0xff,0x1f,0x00,0x00,0xfc,0xff,0x0f,0xf0,0xff,0x3f,0x00,
                0x00,0xfc,0xff,0x0f,0xf8,0xff,0x3f,0x00,0x00,0xfe,0xff,0x1f,0xf8,0xff,0x7f,0x00,
                0x00,0xfe,0xff,0x1f,0xf8,0xff,0x7f,0x00,0x00,0xfe,0xff,0x1f,0xfc,0xff,0x7f,0x00,
                0x00,0xff,0xff,0x1f,0xfc,0xff,0x7f,0x00,0x00,0xff,0xff,0x1f,0xfc,0xff,0x7f,0x00,
                0x00,0xff,0xff,0x1f,0xfc,0xff,0x7f,0x00,0x00,0xfe,0xff,0x1f,0xf8,0xff,0x7f,0x00,
                0x00,0xfe,0xff,0x1f,0xf8,0xff,0x7f,0x00,0x00,0xfe,0xff,0x0f,0xf8,0xff,0x3f,0x00,
                0x00,0xfc,0xff,0x0f,0xf0,0xff,0x3f,0x00,0x00,0xf8,0xff,0x07,0xf0,0xff,0x1f,0x00,
                0x00,0xf8,0xff,0x03,0xe0,0xff,0x0f,0x00,0x00,0xe0,0xff,0x01,0x80,0xff,0x07,0x00,
                0x00,0xc0,0x7f,0x00,0x00,0xff,0x01,0x00,0x00,0x00,0x0c,0x00,0x00,0x30,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
        },
        {
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x80,0x7f,0x00,0x00,0xff,0x01,0x00,0x00,0xe0,0xff,0x01,0x80,0xff,0x07,0x00,
                0x00,0xf8,0xff,0x03,0xe0,0xff,0x0f,0x00,0x00,0xfc,0xff,0x07,0xf0,0xff,0x1f,0x00,
                0x00,0xfc,0xff,0x0f,0xf0,0xff,0x3f,0x00,0x00,0xfe,0xff,0x1f,0xf8,0xff,0x3f,0x00,
                0x00,0xfe,0xff,0x1f,0xf8,0xff,0x7f,0x00,0x00,0xfe,0xff,0x1f,0xfc,0xff,0x7f,0x00,
                0x00,0xff,0xff,0x1f,0xfc,0xff,0x7f,0x00,0x00,0xff,0xff,0x1f,0xfc,0xff,0x7f,0x00,
                0x00,0xff,0xff,0x1f,0xfc,0xff,0x7f,0x00,0x00,0xfe,0xff,0x1f,0xfc,0xff,0x7f,0x00,
                0x00,0xfe,0xff,0x1f,0xf8,0xff,0x7f,0x00,0x00,0xfe,0xff,0x1f,0xf8,0xff,0x3f,0x00,
                0x00,0xfc,0xff,0x0f,0xf0,0xff,0x3f,0x00,0x00,0xfc,0xff,0x07,0xf0,0xff,0x1f,0x00,
                0x00,0xf8,0xff,0x03,0xe0,0xff,0x0f,0x00,0x00,0xe0,0xff,0x01,0xc0,0xff,0x07,0x00,
                0x00,0xc0,0x7f,0x00,0x00,0xff,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
        },
        {
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xe0,0xff,0x01,0xc0,0xff,0x07,0x00,
                0x00,0xf8,0xff,0x07,0xe0,0xff,0x1f,0x00,0x00,0xfc,0xff,0x0f,0xf0,0xff,0x3f,0x00,
                0x00,0xfe,0xff,0x0f,0xf8,0xff,0x3f,0x00,0x00,0xfe,0xff,0x1f,0xf8,0xff,0x7f,0x00,
                0x00,0xff,0xff,0x1f,0xfc,0xff,0x7f,0x00,0x00,0xff,0xff,0x3f,0xfc,0xff,0x7f,0x00,
                0x00,0xff,0xff,0x3f,0xfc,0xff,0x7f,0x00,0x00,0xff,0xff,0x3f,0xfc,0xff,0x7f,0x00,
                0x00,0xff,0xff,0x1f,0xfc,0xff,0x7f,0x00,0x00,0xfe,0xff,0x1f,0xf8,0xff,0x7f,0x00,
                0x00,0xfe,0xff,0x0f,0xf8,0xff,0x3f,0x00,0x00,0xfc,0xff,0x0f,0xf0,0xff,0x3f,0x00,
                0x00,0xf8,0xff,0x07,0xe0,0xff,0x1f,0x00,0x00,0xe0,0xff,0x01,0x80,0xff,0x07,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
        },
        {
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0xf8,0xff,0x07,0xe0,0xff,0x1f,0x00,0x00,0xfc,0xff,0x0f,0xf0,0xff,0x3f,0x00,
                0x00,0xfe,0xff,0x1f,0xf8,0xff,0x7f,0x00,0x00,0xff,0xff,0x1f,0xfc,0xff,0x7f,0x00,
                0x00,0xff,0xff,0x3f,0xfc,0xff,0xff,0x00,0x00,0xff,0xff,0x3f,0xfc,0xff,0xff,0x00,
                0x00,0xff,0xff,0x3f,0xfc,0xff,0x7f,0x00,0x00,0xff,0xff,0x1f,0xfc,0xff,0x7f,0x00,
                0x00,0xfe,0xff,0x1f,0xf8,0xff,0x7f,0x00,0x00,0xfc,0xff,0x0f,0xf0,0xff,0x3f,0x00,
                0x00,0xf8,0xff,0x07,0xe0,0xff,0x1f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
        },
        {
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xf0,0xff,0x03,0xc0,0xff,0x0f,0x00,
                0x00,0xfc,0xff,0x0f,0xf0,0xff,0x3f,0x00,0x00,0xfe,0xff,0x1f,0xf8,0xff,0x7f,0x00,
                0x00,0xff,0xff,0x3f,0xfc,0xff,0x7f,0x00,0x00,0xff,0xff,0x3f,0xfc,0xff,0xff,0x00,
                0x00,0xff,0xff,0x3f,0xfc,0xff,0xff,0x00,0x00,0xff,0xff,0x3f,0xfc,0xff,0x7f,0x00,
                0x00,0xfe,0xff,0x1f,0xf8,0xff,0x7f,0x00,0x00,0xfc,0xff,0x0f,0xf0,0xff,0x3f,0x00,
                0x00,0xf8,0xff,0x03,0xe0,0xff,0x0f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
        },
        {
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xfe,0xff,0x0f,0xf8,0xff,0x3f,0x00,
                0x00,0xff,0xff,0x1f,0xfc,0xff,0x7f,0x00,0x00,0xff,0xff,0x3f,0xfc,0xff,0xff,0x00,
                0x00,0xff,0xff,0x3f,0xfc,0xff,0xff,0x00,0x00,0xff,0xff,0x3f,0xfc,0xff,0xff,0x00,
                0x00,0xfe,0xff,0x1f,0xfc,0xff,0x7f,0x00,0x00,0xfc,0xff,0x0f,0xf8,0xff,0x3f,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
        },
        {
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xf8,0xff,0x07,0xe0,0xff,0x1f,0x00,
                0x00,0xfe,0xff,0x1f,0xf8,0xff,0x7f,0x00,0x00,0xff,0xff,0x3f,0xfc,0xff,0xff,0x00,
                0x00,0xff,0xff,0x3f,0xfc,0xff,0xff,0x00,0x00,0xff,0xff,0x3f,0xfc,0xff,0xff,0x00,
                0x00,0xff,0xff,0x1f,0xfc,0xff,0x7f,0x00,0x00,0xfe,0xff,0x0f,0xf8,0xff,0x3f,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
        },
        {
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0xfe,0xff,0x1f,0xf8,0xff,0x3f,0x00,0x00,0xff,0xff,0x3f,0xfc,0xff,0xff,0x00,
                0x00,0xff,0xff,0x3f,0xfc,0xff,0xff,0x00,0x00,0xff,0xff,0x3f,0xfc,0xff,0xff,0x00,
                0x00,0xff,0xff,0x3f,0xfc,0xff,0x7f,0x00,0x00,0xfe,0xff,0x0f,0xf8,0xff,0x3f,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
        },
        {
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xff,0x3f,0xfc,0xff,0x7f,0x00,
                0x00,0xff,0xff,0x3f,0xfc,0xff,0xff,0x00,0x00,0xff,0xff,0x3f,0xfc,0xff,0xff,0x00,
                0x00,0xff,0xff,0x3f,0xfc,0xff,0xff,0x00,0x00,0xfc,0xff,0x0f,0xf0,0xff,0x3f,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
        },
        {
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xff,0x1f,0xfc,0xff,0x7f,0x00,
                0x00,0xff,0xff,0x3f,0xfc,0xff,0xff,0x00,0x00,0xff,0xff,0x3f,0xfc,0xff,0xff,0x00,
                0x00,0xff,0xff,0x3f,0xfc,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
        }
};

#endif //T12_V1_2_EMOJI_H
