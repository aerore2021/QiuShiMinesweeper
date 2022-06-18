/*
 * File: graphics.h
 * Version: 1.0
 * Last modified on Mon Jun  6 11:03:27 1994 by eroberts
 * -----------------------------------------------------
 * This interface provides access to a simple library of
 * functions that make it possible to draw lines and arcs
 * on the screen.  This interface presents a portable
 * abstraction that can be used with a variety of window
 * systems implemented on different hardware platforms.
 */

#ifndef _graphics_h
#define _graphics_h
/*
 * Overview
 * --------
 * This library provides several functions for drawing lines                ������ṩ�˼��������������ڶ���Ϊ��ͼ�δ��ڡ�����Ļ�����л���ֱ�ߺ�Բ����
 * and circular arcs in a region of the screen that is                      һ�����Ƴ�������Щ�����ͻ��߾ͱ��������ǵ�λ�ã�
 * defined as the "graphics window."  Once drawn, these                     ����ζ�Ÿð�ֻ�����ھ�̬ͼƬ���������ڶ�����
 * lines and arcs stay in their position, which means that
 * the package can only be used for static pictures and not
 * for animation.
 *
 * Individual points within the window are specified by                     �����ڵĸ�����ͨ���������ǵ� x �� y ������ָ����
 * giving their x and y coordinates.  These coordinates are                 ��Щ��������Ӣ��Ϊ��λ��ʵ����ԭ�������½ǣ������ڴ�ͳ��ѧ��һ����
 * real numbers measured in inches, with the origin in the
 * lower left corner, as it is in traditional mathematics.
 *
 * The calls available in the package are listed below.  More               
 * complete descriptions are included with each function                    
 * description.
 *
 *   InitGraphics();
 *   MovePen(x, y);
 *   DrawLine(dx, dy);
 *   DrawArc(r, start, sweep);
 *   width = GetWindowWidth();
 *   height = GetWindowHeight();
 *   x = GetCurrentX();
 *   y = GetCurrentY();
 */

/*
 * Function: InitGraphics                                                   ������InitGraphics 
 * Usage: InitGraphics();                                                   ʹ�ã�InitGraphics();
 * ----------------------                                                   ----------------------
 * This procedure creates the graphics window on the screen.                �˹�������Ļ�ϴ���ͼ�δ��ڡ� 
 * The call to InitGraphics must precede any calls to other                 �� InitGraphics �ĵ��ñ����ڶԸð��������������κε���֮ǰ��
 * functions in this package and must also precede any printf               ���һ��������κ� printf ���֮ǰ��
 * output.  In most cases, the InitGraphics call is the first               �ڴ��������£�InitGraphics �����Ǻ��� main �еĵ�һ����䡣
 * statement in the function main.
 */

void DrawBackground();

void InitGraphics(void);

void InitConsole(void);

/*
 * Function: MovePen                                                        ������MovePen
 * Usage: MovePen(x, y);                                                    ʹ�ã�MovePen(x, y);
 * ---------------------                                                    ---------------------    
 * This procedure moves the current point to the position                   �˹��̽���ǰ���ƶ���λ�� (x, y)���������ߡ�
 * (x, y), without drawing a line.  The model is that of                    ��ģ���Ǳʴ�ͼ�δ��ڱ���̧��Ȼ���ƶ�����λ�õ�ģ�͡�
 * the pen being lifted off the graphics window surface and
 * then moved to its new position.
 */

void MovePen(double x, double y);


/*
 * Function: DrawLine                                                       ������DrawLine
 * Usage: DrawLine(dx, dy);                                                 ʹ�ã�DrawLine(dx, dy);
 * ------------------------                                                 ------------------------    
 * This procedure draws a line extending from the current                   �˹���ͨ���� x �����ƶ��� dx Ӣ����� y �����ƶ� dy Ӣ��������һ���ӵ�ǰ��������ߡ�
 * point by moving the pen dx inches in the x direction                     ����λ�ó�Ϊ�µĵ�ǰ�㡣
 * and dy inches in the y direction.  The final position
 * becomes the new current point.
 */

void MsgOut();

void DrawLine(double dx, double dy);

/*
 * Function: DrawArc                                                        ������DrawArc
 * Usage: DrawArc(r, start, sweep);                                         ʹ�ã�DrawArc(r, start, sweep);
 * --------------------------------                                         --------------------------------
 * This procedure draws a circular arc, which always begins                 �˹��̻���һ��ʼ�մӵ�ǰ�㿪ʼ��Բ����
 * at the current point.  The arc itself has radius r, and                  Բ������İ뾶Ϊ r�����Բ��� start ָ���ĽǶ������Բ�Ŀ�ʼ��
 * starts at the angle specified by the parameter start,                    ����Ƕ��Ǵ� 3 ����λ���� x ����ʱ������ĽǶȣ��봫ͳ��ѧһ����
 * relative to the center of the circle.  This angle is                     ���磬��� start Ϊ 0����Բ���� 3 ����λ�ÿ�ʼ��
 * measured in degrees counterclockwise from the 3 o'clock                  ��� start Ϊ 90����Բ���� 12 ����λ�ÿ�ʼ���ȵȣ�
 * position along the x-axis, as in traditional mathematics.                ���Ƶ�Բ���ĽǶ���sweep����ָ�����ò���Ҳ�Զ�Ϊ��λ��
 * For example, if start is 0, the arc begins at the 3 o'clock              ���sweepΪ360��DrawArc��һ��������Բ��
 * position; if start is 90, the arc begins at the 12 o'clock               ���ɨ��Ϊ 90��������ķ�֮һԲ��
 * position; and so on.  The fraction of the circle drawn is                ��� sweep ��ֵΪ������ӵ�ǰ����ʱ�����Բ����
 * specified by the parameter sweep, which is also measured in              ��� sweep Ϊ��������ӵ�ǰ��˳ʱ�����Բ����
 * degrees.  If sweep is 360, DrawArc draws a complete circle;              DrawArc ��������ʱ�ĵ�ǰ���Ǳ��ػ��ߵ�����λ�á�
 * if sweep is 90, it draws a quarter of a circle.  If the value
 * of sweep is positive, the arc is drawn counterclockwise from
 * the current point.  If sweep is negative, the arc is drawn
 * clockwise from the current point.  The current point at the
 * end of the DrawArc operation is the final position of the pen
 * along the arc.
 *
 * Examples:
 *   DrawArc(r, 0, 360)    Draws a circle to the left of the
 *                         current point.
 *   DrawArc(r, 90, 180)   Draws the left half of a semicircle
 *                         starting from the 12 o'clock position.
 *   DrawArc(r, 0, 90)     Draws a quarter circle from the 3
 *                         o'clock to the 12 o'clock position.
 *   DrawArc(r, 0, -90)    Draws a quarter circle from the 3
 *                         o'clock to the 6 o'clock position.
 *   DrawArc(r, -90, -90)  Draws a quarter circle from the 6
 *                         o'clock to the 9 o'clock position.
 */

void DrawArc(double r, double start, double sweep);

/*
 * Functions: GetWindowWidth, GetWindowHeight                               ������GetWindowWidth, GetWindowHeight
 * Usage: width = GetWindowWidth();                                         ʹ�ã�width = GetWindowWidth();
 *        height = GetWindowHeight();                                             height = GetWindowHeight();
 * ------------------------------------------                               ------------------------------------------
 * These functions return the width and height of the graphics              ��Щ��������ͼ�δ��ڵĿ�Ⱥ͸߶ȣ���Ӣ��Ϊ��λ��
 * window, in inches.
 */

double GetWindowWidth(void);
double GetWindowHeight(void);

/*
 * Functions: GetCurrentX, GetCurrentY                                      ������GetCurrentX, GetCurrentY
 * Usage: x = GetCurrentX();                                                ���ö�����
 *        y = GetCurrentY();
 * -----------------------------------
 * These functions return the current x and y positions.
 */

double GetCurrentX(void);
double GetCurrentY(void);

void Main();

/*����ļ���ö���Ǻ���Ҫ��*/

/*��갴ť*/
typedef enum
{
    NO_BUTTON = 0,
    LEFT_BUTTON,
    MIDDLE_BUTTON,
    RIGHT_BUTTON
} ACL_Mouse_Button;
/*����¼�*/
typedef enum 
{
    BUTTON_DOWN,
    BUTTON_DOUBLECLICK,
    BUTTON_UP,
    ROLL_UP,
    ROLL_DOWN,
    MOUSEMOVE	
} ACL_Mouse_Event;
/*�����¼�*/
typedef enum 
{
	KEY_DOWN,
	KEY_UP
} ACL_Keyboard_Event;

typedef void (*KeyboardEventCallback) (int key,int event);
typedef void (*CharEventCallback) (char c);
typedef void (*MouseEventCallback) (int x, int y, int button, int event);
typedef void (*TimerEventCallback) (int timerID);
/* ע��ĺ����������¼����裬�пյ�uu����������Ľ�Σ�bilibiliҲ�У����ú����*/
void registerKeyboardEvent(KeyboardEventCallback callback);
void registerCharEvent(CharEventCallback callback);
void registerMouseEvent(MouseEventCallback callback);
void registerTimerEvent(TimerEventCallback callback);

void cancelKeyboardEvent();
void cancelCharEvent();
void cancelMouseEvent();
void cancelTimerEvent();
void startTimer(int id, int timeinterval);

void DisplayClear();

#endif
