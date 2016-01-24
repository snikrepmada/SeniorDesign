#ifndef __OV2640_H__
#define __OV2640_H__

enum sensor_pixformat {
  PIXFORMAT_RGB565,    /* 2BPP/RGB565*/
  PIXFORMAT_YUV422,    /* 2BPP/YUV422*/
  PIXFORMAT_GRAYSCALE, /* 1BPP/GRAYSCALE*/
  PIXFORMAT_JPEG,      /* JPEG/COMPRESSED */
};

enum sensor_framesize {
  FRAMESIZE_QQCIF,    /* 88x72     */
  FRAMESIZE_QQVGA,    /* 160x120   */
  FRAMESIZE_QQVGA2,   /* 128x160   */
  FRAMESIZE_QCIF,     /* 176x144   */
  FRAMESIZE_QVGA,     /* 320x240   */
  FRAMESIZE_CIF,      /* 352x288   */
  FRAMESIZE_VGA,      /* 640x480   */
  FRAMESIZE_SVGA,     /* 800x600   */
  FRAMESIZE_SXGA,     /* 1280x1024 */
  FRAMESIZE_UXGA,     /* 1600x1200 */
};

enum sensor_framerate {
  FRAMERATE_2FPS  = 0x9F,
  FRAMERATE_8FPS  = 0x87,
  FRAMERATE_15FPS = 0x83,
  FRAMERATE_30FPS = 0x81,
  FRAMERATE_60FPS = 0x80,
};

enum sensor_gainceiling {
  GAINCEILING_2X,
  GAINCEILING_4X,
  GAINCEILING_8X,
  GAINCEILING_16X,
  GAINCEILING_32X,
  GAINCEILING_64X,
  GAINCEILING_128X,
};

enum sensor_attr {
  ATTR_CONTRAST    = 0,
  ATTR_BRIGHTNESS,
  ATTR_SATURATION,
  ATTR_GAINCEILING,
};

enum reset_polarity {
  ACTIVE_LOW,
  ACTIVE_HIGH
};

extern const int res_width[];
extern const int res_height[];

extern int OV2640_Init(void);

#endif