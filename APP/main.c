#include "main.h"
#include "dev_systick.h"
#include "dev_rgblcd.h"

//static uint32_t lcdbuf_gui[HOR_RES_MAX * VER_RES_MAX / 2] __attribute__((section(".SDRAM")));
static uint32_t lcdbuf_show[HOR_RES_MAX * VER_RES_MAX / 2] __attribute__((section(".SDRAM")));

static inline void drawpoint(int32_t x, int32_t y, uint32_t c)
{
    uint32_t temp;
    uint32_t index;

    //    index = (y*HOR_RES_MAX+x) / 2;
    //    uint32_t pos = ((x%2) == 0 ? 0 : 16);
    //    temp = lcdbuf_show[index];
    //    temp &= ~(0xFFFF << pos);
    //    temp |=  (c      << pos);
    //    lcdbuf_show[index] = temp;

    index = ((VER_RES_MAX - x) * HOR_RES_MAX + y) / 2;
    uint32_t pos = ((y % 2) == 0 ? 0 : 16);
    temp = lcdbuf_show[index];
    temp &= ~(0xFFFF << pos);
    temp |= (c << pos);
    lcdbuf_show[index] = temp;
}

//Transfer GuiLite 32 bits color to your LCD color
#define GL_RGB_32_to_16(rgb) (((((unsigned int)(rgb)) & 0xFF) >> 3) | ((((unsigned int)(rgb)) & 0xFC00) >> 5) | ((((unsigned int)(rgb)) & 0xF80000) >> 8))
//Encapsulate your LCD driver:
void gfx_draw_pixel(int x, int y, unsigned int rgb)
{
    drawpoint(x, y, GL_RGB_32_to_16(rgb));
}

//UI entry
struct EXTERNAL_GFX_OP
{
    void (*draw_pixel)(int x, int y, unsigned int rgb);
    void (*fill_rect)(int x0, int y0, int x1, int y1, unsigned int rgb);
} my_gfx_op;

int main(void)
{
    SystemInit();

    systick_init();
    //serial_init();
    lcd_memory_init();
    lcd_rgb_init();
    LCD->SRCADDR = (uint32_t)lcdbuf_show;
    LCD_Start(LCD);

    //Link your LCD driver & start UI:
    my_gfx_op.draw_pixel = gfx_draw_pixel;
    my_gfx_op.fill_rect = NULL; //gfx_fill_rect;

//    extern void startHello3D(void *phy_fb, int width, int height, int color_bytes, struct EXTERNAL_GFX_OP *gfx_op);
//    startHello3D(NULL, VER_RES_MAX, HOR_RES_MAX, 2, &my_gfx_op);

//    //大量double运算，运行缓慢
//    extern void startHello3Ddonut(void* phy_fb, int width, int height, int color_bytes, struct EXTERNAL_GFX_OP* gfx_op);
//    startHello3Ddonut(NULL, VER_RES_MAX, HOR_RES_MAX, 2, &my_gfx_op);

//    extern void startHello3Dwave(void* phy_fb, int width, int height, int color_bytes, struct EXTERNAL_GFX_OP* gfx_op);
//    startHello3Dwave(NULL, VER_RES_MAX, HOR_RES_MAX, 2, &my_gfx_op);

//    extern void startHelloCircle(void* phy_fb, int width, int height, int color_bytes, struct EXTERNAL_GFX_OP* gfx_op);
//    startHelloCircle(NULL, VER_RES_MAX, HOR_RES_MAX, 2, &my_gfx_op);

//    extern void startHelloLayers(void* phy_fb, int width, int height, int color_bytes, struct EXTERNAL_GFX_OP* gfx_op);
//    startHelloLayers(NULL, VER_RES_MAX, HOR_RES_MAX, 2, &my_gfx_op);

//    //动态内存不够，不能运行
//    extern void startHelloMario(void* phy_fb, int width, int height, int color_bytes, struct EXTERNAL_GFX_OP* gfx_op);
//    startHelloMario(NULL, VER_RES_MAX, HOR_RES_MAX, 2, &my_gfx_op);

//    extern void startHelloMolecule(void* phy_fb, int width, int height, int color_bytes, struct EXTERNAL_GFX_OP* gfx_op);
//    startHelloMolecule(NULL, VER_RES_MAX, HOR_RES_MAX, 2, &my_gfx_op);

//    extern void startHelloNets(void* phy_fb, int width, int height, int color_bytes, struct EXTERNAL_GFX_OP* gfx_op);
//    startHelloNets(NULL, VER_RES_MAX, HOR_RES_MAX, 2, &my_gfx_op);

//    extern void startHelloNoTouch(void* phy_fb, int width, int height, int color_bytes, struct EXTERNAL_GFX_OP* gfx_op);
//    extern void sendKey2HelloNoTouch(unsigned int key);
//    startHelloNoTouch(NULL, VER_RES_MAX, HOR_RES_MAX, 2, &my_gfx_op);
//    while(1)
//    {
//        //sendKey2HelloNoTouch(1);//Backward focus
//        sendKey2HelloNoTouch(0);//Forward focus
//        swm_delay(1000);
//        sendKey2HelloNoTouch(2);//Click
//        swm_delay(1000);
//    }

//    extern void startHelloParticle(void* phy_fb, int width, int height, int color_bytes, struct EXTERNAL_GFX_OP* gfx_op);
//    startHelloParticle(NULL, VER_RES_MAX, HOR_RES_MAX, 2, &my_gfx_op);

//    extern void startHelloPendulum(void* phy_fb, int width, int height, int color_bytes, struct EXTERNAL_GFX_OP* gfx_op);
//    startHelloPendulum(NULL, VER_RES_MAX, HOR_RES_MAX, 2, &my_gfx_op);

//    extern void startHelloStar(void* phy_fb, int width, int height, int color_bytes, struct EXTERNAL_GFX_OP* gfx_op);
//    startHelloStar(NULL, VER_RES_MAX, HOR_RES_MAX, 2, &my_gfx_op);

//    extern void startHelloTimer(void* phy_fb, int width, int height, int color_bytes, struct EXTERNAL_GFX_OP* gfx_op);
//    startHelloTimer(NULL, VER_RES_MAX, HOR_RES_MAX, 2, &my_gfx_op);

    extern void startHelloWave(void *phy_fb, int width, int height, int color_bytes, struct EXTERNAL_GFX_OP *gfx_op);
    startHelloWave(NULL, VER_RES_MAX, HOR_RES_MAX, 2, &my_gfx_op);
    while (1 == 1)
    {
    }
}

void SysTick_Handler_cb(void)
{
}

void SysTick_Handler(void)
{
    swm_inctick();
    SysTick_Handler_cb();
}
