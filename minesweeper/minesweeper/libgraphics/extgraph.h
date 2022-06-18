/*
 * File: extgraph.h
 * Version: 3.0
 * Last modified on Tue Oct  4 11:24:41 1994 by eroberts
 * -----------------------------------------------------
 * This interface is the extended graphics interface.               �ýӿ�����չͼ�νӿڡ�
 * It includes all of the facilities in graphics.h, plus            ������ graphics.h �е����й��ܣ�
 * several additional functions that are designed to                ��һЩּ��֧�ָ����ӡ�����ʽͼ�εĸ��ӹ��ܡ�
 * support more sophisticated, interactive graphics.
 */

#ifndef _extgraph_h
#define _extgraph_h

#include "genlib.h"

/* Exported functions */                                           

/* Section 1 -- Basic functions from graphics.h */

#include "graphics.h"

/* Section 2 -- Elliptical arcs */                                  /*�ڶ����� -- ��Բ��*/

/*
 * Function: DrawEllipticalArc                                      ����������Բ��                                           
 * Usage: DrawEllipticalArc(rx, ry, start, sweep);                  
 * -----------------------------------------------
 * This procedure draws an elliptical arc.  It is exactly           �˹��̻�����Բ���� 
 * the same in its operation as DrawArc in the graphics.h           ������� graphics.h �����е� DrawArc ��ȫ��ͬ��
 * interface, except that the radius is different along the         ֻ�ǰ뾶�������᲻ͬ��
 * two axes.
 */

void DrawEllipticalArc(double rx, double ry,
                       double start, double sweep);

/* Section 3 -- Graphical regions*/                                 /*�������� -- ͼ������*/

/*
 * Functions: StartFilledRegion, EndFilledRegion
 * Usage: StartFilledRegion(density);
 *        . . . other calls . . .
 *        EndFilledRegion();
 * ------------------------------
 * These calls make it possible to draw filled shapes on the        �������������״�ĵ��á�
 * display.  After calling StartFilledRegion, any calls to          ���� StartFilledRegion ��         
 * DrawLine and DrawArc are used to create a shape definition       �� DrawLine �� DrawArc ���κε��ö����ڴ���������״�Ķ��壬
 * and do not appear on the screen until EndFilledRegion is         �����ڵ��� EndFilledRegion ֮ǰ�����������Ļ�ϡ�
 * called.  The lines and arcs must be consecutive, in the          �����ͻ��߱����������ģ���ÿ����Ԫ�ر�������һ��Ԫ�ؽ����ĵط���ʼ��
 * sense that each new element must start where the last            MovePen ����ֻ�ܷ���������Ŀ�ͷ���β�������ᷢ�����ڲ���
 * one ended.  MovePen calls may occur at the beginning             �� EndFilledRegion ������ʱ�����������������Ļ�ϣ����ڲ�����䡣
 * or the end of the region, but not in the interior. When          �ܶȲ���(density)��һ������ 0 �� 1 ֮������֣�ָʾ��ν����ܶ��������ͼ����
 * EndFilledRegion is called, the entire region appears on the      ����ܶ�Ϊ1������״�����Ϊ��ɫ�� ���Ϊ 0������佫���ɼ���
 * screen, with its interior filled in.  The density parameter      ��������֮�䣬����һЩ����ɫ����һЩ�㲻��ɫΪʵʩ��
 * is a number between 0 and 1 and indicates how the dot density
 * to be used for the fill pattern.  If density is 1, the shape
 * will be filled in a solid color; if it is 0, the fill will be
 * invisible.  In between, the implementation will use a dot
 * pattern that colors some of the screen dots but not others.
 */

void StartFilledRegion(double density);
void EndFilledRegion(void);

/* Section 4 -- String functions */                                 /*���Ĳ��� -- �ַ�������*/

/*
 * Function: DrawTextString                                         ������DrawTextString
 * Usage: DrawTextString(text);                                     ʹ�ã�DrawTextString(text);
 * ----------------------------                                     ----------------------------
 * This function displays the string text at the current point      �ú����Ե�ǰ����ʹ�С��ʾ��ǰ����ַ����ı���
 * in the current font and size.  The current point is updated      Ŀǰ��ᱻ���£��Ա���һ�� DrawTextString �������һ���ַ�λ�ü�����
 * so that the next DrawTextString command would continue from      �ַ������ð������з���
 * the next character position.  The string may not include the
 * newline character.
 */

void DrawTextString(string text);

/*
 * Function: TextStringWidth                                        ������TextStringWidth
 * Usage: w = TextStringWidth(text);                                ʹ�ã�w = TextStringWidth(text);
 * ---------------------------------                                ----------------------------
 * This function returns the width of the text string if displayed  ����Ե�ǰ����ʹ�С��ʾ���˺��������ı��ַ����Ŀ�ȡ�
 * at the current font and size.
 */

double TextStringWidth(string text);

/*
 * Function: SetFont                                                ������SetFont
 * Usage: SetFont(font);                                            ʹ�ã�SetFont(font);
 * ---------------------                                            ---------------------
 * This function sets a new font according to the font string,      �ú������������ַ������������壬�����ִ�Сд��
 * which is case-independent.  Different systems support different  ��ͬ��ϵͳ֧�ֲ�ͬ�����壬��ͨ��֧�֡�Times���͡�Courier���ȳ������塣
 * fonts, although common ones like "Times" and "Courier" are often �������������Ϊʼ��֧�ֵġ�Ĭ�ϡ������ײ�����ȡ����ϵͳ��
 * supported.  Initially, the font is set to "Default" which is     ������������޷�ʶ���򲻻�����������屣�ֲ��䡣
 * always supported, although the underlying font is system         �������Ҫ�����������������Ե��� GetFont ���鿴�����Ƿ���Ч��
 * dependent.  If the font name is unrecognized, no error is        ͨ������������²��������󣬳����ø��ӿ���ֲ��
 * generated, and the font remains unchanged.  If you need to
 * detect this condition, you can call GetFont to see if the
 * change took effect.  By not generating an error in this case,
 * programs become more portable.
 */

void SetFont(string font);

/*
 * Function: GetFont                                                ������GetFont
 * Usage: font = GetFont();                                         ʹ�ã�font = GetFont();            
 * ------------------------                                         ------------------------
 * This function returns the current font name as a string.         �����͡�
 */

string GetFont(void);

/*
 * Function: SetPointSize                                           ������SetPointSize                             
 * Usage: SetPointSize(size);                                       ʹ�ã�SetPointSize(size);            
 * --------------------------                                       ------------------------
 * This function sets a new point size.  If the point size is       ����ض����岻֧�ְ�ֵ����ѡ����ӽ������д�С��
 * not supported for a particular font, the closest existing
 * size is selected.
 */

void SetPointSize(int size);

/*
 * Function: GetPointSize                                           ������GetPointSize
 * Usage: size = GetPointSize();                                    ʹ�ã�size = GetPointSize();
 * -----------------------------
 * This function returns the current point size.
 */

int GetPointSize(void);

/*
 * Text style constants                                             �ı���ʽ����
 * --------------------                                             --------------------
 * The constants Bold and Italic are used in the SetStyle           �� SetStyle ������ʹ�ó��� Bold �� Italic ��ָ��������ı���ʽ��
 * command to specify the desired text style.  They may also        ����Ҳ����ͨ������Щ��������һ�������ʹ�ã������ + б�塣
 * be used in combination by adding these constants together,       ���� Normal ��ʾĬ����ʽ��
 * as in Bold + Italic.  The constant Normal indicates the
 * default style.
 */

#define Normal  0
#define Bold    1
#define Italic  2

/*
 * Function: SetStyle                                               ������SetStyle
 * Usage: SetStyle(style);
 * -----------------------                                          -----------------------
 * This function establishes the current style properties           �˺������ݲ��� style �����ı��ĵ�ǰ��ʽ���ԣ�
 * for text based on the parameter style, which is an integer       �ò�����һ����������ʾ�κ��ı���ʽ�������ܺ͡�
 * representing the sum of any of the text style constants.
 */

void SetStyle(int style);

/*
 * Function: GetStyle                                               ������GetStyle
 * Usage: style = GetStyle();
 * --------------------------
 * This function returns the current style.
 */

int GetStyle(void);

/*
 * Functions: GetFontAscent, GetFontDescent, GetFontHeight          ������GetFontAscent, GetFontDescent, GetFontHeight
 * Usage: ascent = GetFontAscent();
 *        descent = GetFontDescent();
 *        height = GetFontHeight();
 * -------------------------------------------------------          -------------------------------------------------------
 * These functions return properties of the current font that are   ��Щ�������ص�ǰ��������ԣ����ڼ��������ҳ���ϴ�ֱ�����ı���
 * used to calculate how to position text vertically on the page.   FontAscent�Ǵӻ��ߵ�����ַ������ľ��룻
 * The ascent of a font is the distance from the baseline to the    FontDescent���κ��ַ����쵽�������µ������롣
 * top of the largest character; the descent is the maximum         FontHeigh�������ı�֮����ܾ��룬�����м�ࣨ��Ϊ�оࣩ��
 * distance any character extends below the baseline.  The height
 * is the total distance between two lines of text, including the
 * interline space (which is called leading).
 *
 * Examples:                                                        ����
 *   To change the value of y so that it indicates the next text        Ҫ���� y ��ֵ��ʹ��ָ����һ���ı��У�
 *   line, you need to execute                                          ����Ҫִ��
 *
 *        y -= GetFontHeight();                                              y -= GetFontHeight();
 *
 *   To center text vertically around the coordinate y, you need        ������ y ��ֱ�����ı���
 *   to start the pen at                                                ����Ҫ���ʴ�
 *
 *       y - GetFontAscent() / 2                                            y - GetFontAscent() / 2
 */

double GetFontAscent(void);
double GetFontDescent(void);
double GetFontHeight(void);

/* Section 5 -- Mouse support */                                        /*���岿�� -- ���֧��*/

/*
 * Functions: GetMouseX, GetMouseY                                      ������GetMouseX, GetMouseY
 * Usage: x = GetMouseX();
 *        y = GetMouseY();                                      
 * -------------------------------                                      -------------------------------
 * These functions return the x and y coordinates of the mouse,         �����͡�
 * respectively.  The coordinate values are real numbers measured
 * in inches from the origin and therefore match the drawing
 * coordinates.
 */

double GetMouseX(void);
double GetMouseY(void);

/*
 * Functions: MouseButtonIsDown                                         ������MouseButtonIsDown
 * Usage: if (MouseButtonIsDown()) . . .                                ʹ�ã�Usage: if (MouseButtonIsDown()) . . .
 * -------------------------------------                                -------------------------------------
 * This function returns TRUE if the mouse button is currently          �����갴ť��ǰ���£��˺������� TRUE��
 * down.  For maximum compatibility among implementations, the          Ϊ���������ԣ��ٶ�������һ����ť��
 * mouse is assumed to have one button.  If the mouse has more          �������ж����ť����˺������κΰ�ť����ʱ���� TRUE��
 * than one button, this function returns TRUE if any button
 * is down.
 */

bool MouseButtonIsDown(void);

/*
 * Functions: WaitForMouseDown, WaitForMouseUp                          ������WaitForMouseDown, WaitForMouseUp 
 * Usage: WaitForMouseDown();                                           ʹ�ã�WaitForMouseDown();
 *        WaitForMouseUp();                                                   WaitForMouseUp();
 * -------------------------------------------                          -------------------------------------------
 * The WaitForMouseDown function waits until the mouse button           WaitForMouseDown �����ȴ�ֱ��������갴ťȻ�󷵻ء� 
 * is pressed and then returns.  WaitForMouseUp waits for the           WaitForMouseUp �ȴ���ť���ͷš�
 * button to be released.
 */

void WaitForMouseDown(void);
void WaitForMouseUp(void);

/* Section 6 -- Color support */                                        /*�������� -- ��ɫ֧��*/

/*
 * Function: HasColor                                                   ������HasColor
 * Usage: if (HasColor()) . . .                                         ʹ�ã�if (HasColor()) . . .
 * ----------------------------                                         ----------------------------
 * This function returns TRUE if the graphics window can display a      ���ͼ�δ��ڿ�����ʾ��ɫͼ�񣬴˺������� TRUE��
 * color image.  Note that this condition is stronger than simply       ��ע�⣬�������ȼ򵥵ؼ���ɫ��ʾ���Ƿ����Ҫǿ��
 * checking whether a color display is available.  Because color        ��Ϊ��ɫ���ڱȺڰ״�����Ҫ������ڴ棬
 * windows require more memory than black and white ones, this          �������û���㹻���ڴ����洢��ɫͼ�񣬴˺��������� FALSE ����ʾ��ɫ��Ļ��
 * function will return FALSE with a color screen if there is           ���磬�� Macintosh �ϣ�ͨ����Ҫ��������С���ӵ����� 1MB��Ȼ����ܴ�����ɫ���ڡ�
 * not enough memory to store a colored image.  On the Macintosh,
 * for example, it is usually necessary to increase the partition
 * size to at least 1MB before color windows can be created.
 */

bool HasColor(void);

/*
 * Function: SetPenColor                                                ������SetPenColor
 * Usage: SetPenColor(color);                                           ʹ�ã�SetPenColor(color);
 * --------------------------                                           --------------------------
 * This function sets the color of the pen used for any drawing,        �˺������������κλ�ͼ�ıʵ���ɫ�������������ı����������
 * including lines, text, and filled regions.  The color is a           ��ɫ��һ���ַ�����ͨ��������Ԥ������ɫ����֮һ��
 * string, which will ordinarily be one of the following
 * predefined color names:
 *
 *    Black, Dark Gray, Gray, Light Gray, White,                            ��ɫ�����ɫ����ɫ��ǳ��ɫ����ɫ��
 *    Red, Yellow, Green, Cyan, Blue, Magenta                               ��ɫ����ɫ����ɫ����ɫ����ɫ��Ʒ��ɫ
 *
 * The first line corresponds to standard gray scales and the           ��һ�ж�Ӧ��׼�Ҷȣ��ڶ��ж�Ӧ���ԭɫ�Ͷ���ɫ��
 * second to the primary and secondary colors of light.  The            �������ý�������Щ��ɫ����Ϊ���ǿ���������Ӳ���豸�϶�����ͬ�ġ�
 * built-in set is limited to these colors because they are             ���ڸ���ϸ����ɫ���ƣ���Ҳ����ʹ�� DefineColor �����������µ���ɫ���ơ�
 * likely to be the same on all hardware devices.  For finer
 * color control, you can use the DefineColor function to
 * create new color names as well.
 */

void SetPenColor(string color);

/*
 * Function: GetPenColor                                                ������GetPenColor
 * Usage: color = GetPenColor();
 * -----------------------------
 * This function returns the current pen color as a string.
 */

string GetPenColor(void);

/*
 * Function: SetPenSize                                                 ������SetPenSize
 * Usage: SetPenSize(size);
 * -----------------------------------------
 * This function sets the size(in pixels) of the pen used for any drawing.
 */

void SetPenSize(int size);

/*
 * Function: GetPenSize                                                 ������GetPenSize
 * Usage: size = GetPenSize();
 * -----------------------------------------
 * This function returns the size(in pixels) of the pen used for any drawing.
 */

int GetPenSize(void);

/*
 * Function: DefineColor                                                ������DefineColor
 * Usage: DefineColor(name, red, green, blue);                          ʹ�ã�DefineColor(name, red, green, blue);
 * -------------------------------------------                          -------------------------------------------
 * This function allows the client to define a new color name           �˹�������ͻ���ͨ��Ϊ��ɫ����ɫ����ɫ�������ǹ��ԭɫ���ṩǿ�ȼ����������µ���ɫ���ơ�
 * by supplying intensity levels for the colors red, green,             ��ɫֵ�� 0 �� 1 ֮���ʵ����ʽ�ṩ����ʾ����ɫ��ǿ�ȡ�
 * and blue, which are the primary colors of light.  The                ���磬Ԥ�������ɫ���ɫ(Magenta)����ȫǿ�ȵĺ�ɫ����ɫ��
 * color values are provided as real numbers between 0 and 1,           ��û����ɫ����˶���Ϊ��
 * indicating the intensity of that color.  For example,
 * the predefined color Magenta has full intensity red and
 * blue but no green and is therefore defined as:
 *
 *      DefineColor("Magenta", 1, 0, 1);                                    DefineColor("Magenta", 1, 0, 1);
 *
 * DefineColor allows you to create intermediate colors on              DefineColor �������������ʾ���ϴ����м���ɫ�����ܽ����Ӳ�����졣
 * many displays, although the results vary significantly               (ͬʱ���֪��������ɫ����ô������ġ�)
 * depending on the hardware.  For example, the following               ���磬����ͨ��������ɫ�ĺ������ֵ��
 * usually gives a reasonable approximation of brown:
 *
 *      DefineColor("Brown", .35, .20, .05);                                DefineColor("Brown", .35, .20, .05);
 */

void DefineColor(string name,
                 double red, double green, double blue);

/* Section 7 -- Miscellaneous functions */                              /*���߲��� -- �����*/

/*
 * Function: SetEraseMode                                               ������SetEraseMode
 * Usage: SetEraseMode(TRUE);                                           ʹ�ã�SetEraseMode(TRUE);
 *        SetEraseMode(FALSE);                                                SetEraseMode(FALSE);  
 * ---------------------------                                          ---------------------------        
 * The SetEraseMode function sets the value of the internal             SetEraseMode ���������ڲ�������־��ֵ��
 * erasing flag.  Setting this flag is similar to setting the           ���ô˱�־��Ч�������ڽ���ɫ����Ϊ����ɫ��������Ӱ�쵱ǰ��ɫ���á�
 * color to "White" in its effect but does not affect the               ������ģʽ����Ϊ FALSE ʱ��ʹ�õ�ǰ��ɫ�ָ�������ͼ��
 * current color setting.  When erase mode is set to FALSE,
 * normal drawing is restored, using the current color.
 */

void SetEraseMode(bool mode);

/*
 * Function: GetEraseMode                                               ������GetEraseMode
 * Usage: mode = GetEraseMode();
 * -----------------------------
 * This function returns the current state of the erase mode flag.
 */

bool GetEraseMode(void);

/*
 * Function: SetWindowTitle                                             ������SetWindowTitle
 * Usage: SetWindowTitle(title);                                        ʹ�ã�SetWindowTitle(title);    
 * -----------------------------                                        -----------------------------
 * This function sets the title of the graphics window, if such         ��õĺ���֮һ��
 * an operation is possible on the display.  If it is not possible      ���ö�����
 * for a particular implementation, the call is simply ignored.         Ӧ���ڵ��� InitGraphics ֮ǰ���ô˺��������ô��ڵĳ�ʼ���ơ�
 * This function may be called prior to the InitGraphics call to
 * set the initial name of the window.
 */

void SetWindowTitle(string title);

/*
 * Function: GetWindowTitle                                             ������GetWindowTitle
 * Usage: title = GetWindowTitle();
 * --------------------------------
 * This function returns the title of the graphics window.  If the
 * implementation does not support titles, this call returns the
 * empty string.
 */

string GetWindowTitle(void);

/*
 * Function: UpdateDisplay                                              ������UpdateDisplay
 * Usage: UpdateDisplay();                                              ʹ�ã�UpdateDisplay();
 * -----------------------                                              -----------------------
 * This function initiates an immediate update of the graphics          �˺�������ͼ�δ��ڵ�һ�μ�ʱ���£��Ƕ���������ġ�
 * window and is necessary for animation.  Ordinarily, the              ͨ������������ȴ��û�����ʱ�Ÿ���ͼ�δ��ڡ�
 * graphics window is updated only when the program waits for
 * user input.
 */

void UpdateDisplay(void);

/*
 * Function: Pause                                                      ������Pause
 * Usage: Pause(seconds);                                               ʹ�ã�Pause(seconds);
 * ----------------------                                               ----------------------        
 * The Pause function updates the graphics window and then              �ú������ȸ���ͼ�δ��ڣ�Ȼ����ָͣ����������
 * pauses for the indicated number of seconds.  This function           �����˶���̫��Ķ��������á�
 * is useful for animation where the motion would otherwise
 * be too fast.
 */

void Pause(double seconds);

/*
 * Function: ExitGraphics                                               ������ExitGraphics
 * Usage: ExitGraphics();                                               ʹ�ã�ExitGraphics();
 * ----------------------                                               ----------------------
 * The ExitGraphics function closes the graphics window and             ExitGraphics �����ر�ͼ�δ��ڲ��˳�Ӧ�ó���
 * exits from the application without waiting for any additional        ������ȴ��κζ�����û�������
 * user interaction.
 */

void ExitGraphics(void);

/*
 * Functions: SaveGraphicsState, RestoreGraphicsState                   ������SaveGraphicsState, RestoreGraphicsState
 * Usage: SaveGraphicsState();                                          ʹ�ã�SaveGraphicsState();        
 *        . . . graphical operations . . .                                    . . . ͼ�β��� . . .
 *        RestoreGraphicsState();                                             RestoreGraphicsState();      
 * ---------------------------------------------------                  ---------------------------------------------------
 * The SaveGraphicsState function saves the current graphics            SaveGraphicsState �������ڲ����浱ǰͼ��״̬����ǰ��λ�á����塢���С�Ͳ���ģʽ��־����
 * state (the current pen position, the font, the point size,           �Ա���һ�ε��� RestoreGraphicsState ���Իָ����ǡ�
 * and the erase mode flag) internally, so that they can be             ��������������ɶ�ʹ�ã�������Ƕ�׵�������ȡ�
 * restored by the next RestoreGraphicsState call.  These two           
 * functions must be used in pairs but may be nested to any depth.
 */

void SaveGraphicsState(void);
void RestoreGraphicsState(void);

/*
 * Functions: GetFullScreenWidth, GetFullScreenHeight                   ������GetFullScreenWidth, GetFullScreenHeight
 * Usage: width = GetFullScreenWidth();                                 ʹ�ã�width = GetFullScreenWidth();    
 *        height = GetFullScreenHeight();                                     height = GetFullScreenHeight();
 * --------------------------------------                               --------------------------------------
 * These functions return the height and width of the entire            ��Щ��������������ʾ��Ļ�ĸ߶ȺͿ�ȣ�������ͼ�δ��ڡ�
 * display screen, not the graphics window.  Their only                 ����Ψһ��Ҫ����;��������Ҫ���ݿ�����Ļ�ռ����ͼ�δ��ڴ�С��Ӧ�ó���
 * significant use is for applications that need to adjust              ��Щ���������ڵ��� InitGraphics ֮ǰ���á�
 * the size of the graphics window based on available screen
 * space.  These functions may be called before InitGraphics
 * has been called.
 */

double GetFullScreenWidth(void);
double GetFullScreenHeight(void);

/*
 * Functions: SetWindowSize                                             ������SetWindowSize
 * Usage: SetWindowSize(width, height);                                 ʹ�ã�SetWindowSize(width, height);
 * ------------------------------------                                 ------------------------------------
 * This function sets the window size to the indicated dimensions,      ������ܣ��˺��������ڴ�С����Ϊָʾ�ĳߴ硣
 * if possible.  This function should be called before the graphics     �ú���Ӧ�� InitGraphics ����ͼ�δ���֮ǰ���á�
 * window is created by InitGraphics.  Attempts to change the size      �����ִ�ж�����Ը������д��ڴ�С�ĳ��ԡ�
 * of an existing window are ignored by most implementations.  This     Ӧ����ʹ�ô˹��ܣ���Ϊ���ή��Ӧ�ó���Ŀ���ֲ�ԣ�
 * function should be used sparingly because it reduces the             �ر��ǵ��ͻ�������Ŀռ䳬����Ļ�ϵĿ��ÿռ�ʱ��
 * portability of applications, particularly if the client
 * requests more space than is available on the screen.
 */

void SetWindowSize(double width, double height);

/*
 * Functions: GetXResolution, GetYResolution                            ������GetXResolution, GetYResolution
 * Usage: xres = GetXResolution();                                      ʹ�ã�xres = GetXResolution();
 *        yres = GetYResolution();                                            yres = GetYResolution();
 * -----------------------------------------                            -----------------------------------------
 * These functions return the number of pixels per inch along           ��Щ����������ÿ�����귽��ÿӢ�����������
 * each of the coordinate directions and are useful for applications    �����ڵ��෽����ȱ�ʾ�̾������Ҫ��Ӧ�ó���ǳ����á�
 * in which it is important for short distances to be represented       ��ʹ�������ʾ���� x �� y �ֱ�����ͬ���ͻ���Ҳ��Ӧ���������ԡ�    
 * uniformly in terms of dot spacing.  Even though the x and y
 * resolutions are the same for most displays, clients should
 * not rely on this property.
 *
 * Note: Lines in the graphics library are one pixel unit wide and      ע�⣺ͼ�ο��е�����Ϊ 1 �����ص�λ���������Ǳ���Ԥ�ڵĳ� 1 �����ء�
 * have a length that is always one pixel longer than you might         ���纯������
 * expect.  For example, the function call
 *
 *     DrawLine(2 / GetXResolution(), 0);                                   DrawLine(2 / GetXResolution(), 0);    
 *
 * draws a line from the current point to the point two pixels          �ӵ�ǰ�㻭һ���ߵ��ұ��������صĵ㣬������һ���������ص��ߡ�
 * further right, which results in a line of three pixels.
 */
 
double GetXResolution(void);
double GetYResolution(void);
 
/*pixels to inches*/
double ScaleXInches(int x);
double ScaleYInches(int y);

#endif
