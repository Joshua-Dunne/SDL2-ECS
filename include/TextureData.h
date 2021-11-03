#ifndef TEXTURE_DAT_H
#define TEXTURE_DAT_H

struct TextureData
{
    TextureData() {x = 0, y = 0; width = 0; height = 0;}
    TextureData(int t_x, int t_y, int t_w, int t_h) {x = t_x; y = t_y; width = t_w; height = t_h;};
    int x;
    int y;
    int width;
    int height;
};

#endif