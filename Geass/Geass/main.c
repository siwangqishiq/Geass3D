//
//  main.c
//  Geass
//
//  Created by  潘易  on 15/8/19.
//  Copyright (c) 2015年 xinlan. All rights reserved.
//
#include  "Geass.h"
#include <stdio.h>

int init()
{
    //test();
    //test2();
    
    glClearColor(1,1,1,1);
    //资源载入
    
    return 0;
}

struct Point2D_TYPE
{
    float x;
    float y;
};
typedef struct Point2D_TYPE Point2D;

//绘制一个三角形
void drawTrigle()
{
    Point2D p1 = {350,300};
    Point2D p2 = {150,200};
    Point2D p3 = {50,200};
    
    Color color = {0,0,0};
    drawLine(p1.x, p1.y, p2.x, p2.y, color);
    drawLine(p1.x, p1.y, p3.x, p3.y, color);
    drawLine(p2.x, p2.y, p3.x, p3 .y, color);
    
    float dxy_left = (p2.x - p1.x)/(p1.y - p2.y);
    float dxy_right = (p3.x - p1.x)/(p1.y - p3.y);
    float x_start = p1.x;
    float x_end = p1.x;
    
    for(float y =p1.y;y > p2.y;y--)
    {
        printf("%f %f %f %f\n",x_start,y,x_end,y);
        drawLine(x_start,y,x_end,y,color);
        x_start += dxy_left;
        x_end += dxy_right;
        //x_start++;
        //x_end+=10;
    }//end for y
    
    
}

//画面渲染
void render()
{
    //清空颜色缓冲区，填充的颜色由 glClearColor( 0, 0.0, 0.0, 1 ); 指定为黑色
    glClear(GL_COLOR_BUFFER_BIT);
    //glPointSize(2);//指定点的大小
    Color color = {0,0,255};
    
    drawLine(0, 0, 100, 100,color);
    
    drawTrigle();
    
    glutSwapBuffers();
    
    
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(SCR_WDITH, SCR_HEIGHT);
    glutInitWindowPosition(200, 100);
    glutCreateWindow("Hello World");
    glutDisplayFunc(render);
    init();
    glutMainLoop();
    return 1;
}