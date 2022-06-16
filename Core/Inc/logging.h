//
// Created by zuo-c on 2022/5/22.
//

#ifndef T12_TEST_LOGGING_H
#define T12_TEST_LOGGING_H

#include "stdio.h"

#define __DEBUG    //日志模块总开关，注释掉将关闭日志输出

#ifdef __DEBUG
#define M_DEBUG(format, ...) printf(format, ##__VA_ARGS__)
#else
#define M_DEBUG(format, ...)
#endif

//定义日志级别
enum LOGGING_LEVEL {
    LOGGING_LEVEL_OFF = 0,
    LOGGING_LEVEL_FATAL,
    LOGGING_LEVEL_ERR,
    LOGGING_LEVEL_WARN,
    LOGGING_LEVEL_INFO,
    LOGGING_LEVEL_ALL
};

#define LOGGING_F(level, format, ...) \
    do { \
         if(level>=LOGGING_LEVEL_FATAL)\
            M_DEBUG("[LOGGING,FATAL] "format"\r\n",##__VA_ARGS__ );\
    } while (0)

#define LOGGING_E(level, format, ...) \
    do { \
         if(level>=LOGGING_LEVEL_ERR)\
           M_DEBUG("[LOGGING,ERROR] "format"\r\n",##__VA_ARGS__ );\
    } while (0)

#define LOGGING_W(level, format, ...) \
    do { \
         if(level>=LOGGING_LEVEL_WARN)\
           M_DEBUG("[LOGGING,WARNING] "format"\r\n",##__VA_ARGS__ );\
    } while (0)

#define LOGGING_I(level, format, ...) \
    do { \
         if(level>=LOGGING_LEVEL_INFO)\
           M_DEBUG("[LOGGING,INFO] "format"\r\n",##__VA_ARGS__ );\
    } while (0)

#define LOGGING_D(level, format, ...) \
    do { \
         if(level>=LOGGING_LEVEL_ALL)\
           M_DEBUG("[LOGGING,DEBUG] "format"\r\n",##__VA_ARGS__ );\
    } while (0)

#endif //T12_TEST_LOGGING_H
