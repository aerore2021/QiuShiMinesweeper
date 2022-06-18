/*
 * File: random.h
 * Version: 1.0
 * Last modified on Fri Jul 22 16:44:36 1994 by eroberts
 * -----------------------------------------------------
 * This interface provides several functions for generating					�ýӿ��ṩ�˼�����������α������ĺ�����
 * pseudo-random numbers.
 */

#ifndef _random_h
#define _random_h

#include "genlib.h"
#include <stdlib.h>

/*
 * Constant: RAND_MAX														������RAND_MAX
 * ------------------														------------------
 * Unfortunately, several libraries that supposedly conform to				���ҵ��ǣ�һЩ�ݳƷ��� ANSI ��׼�Ŀ�û���� <stdlib.h> �ж��� RAND_MAX��
 * the ANSI standard do not define RAND_MAX in <stdlib.h>.  To				Ϊ�˼��ٿ���ֲ�����⣬�˽ӿڽ� RAND_MAX ����Ϊδ����������������
 * reduce portability problems, this interface defines RAND_MAX
 * to be the largest positive integer if it is undefined.
 */

#ifndef RAND_MAX
#  define RAND_MAX ((int) ((unsigned) ~0 >> 1))
#endif

/*
 * Function: Randomize														������Randomize
 * Usage: Randomize();														ʹ�ã�Randomize();
 * -------------------														-------------------
 * This function sets the random seed so that the random sequence			�ú�������������ӣ�ʹ������в���Ԥ�⡣
 * is unpredictable.  During the debugging phase, it is best not			�ڵ��Խ׶Σ���ò�Ҫ������������������������Ϊ���ǿ��ظ��ġ�
 * to call this function, so that program behavior is repeatable.
 */

void Randomize(void);

/*
 * Function: RandomInteger													������RandomInteger
 * Usage: n = RandomInteger(low, high);										ʹ�ã�n = RandomInteger(low, high);
 * ------------------------------------										------------------------------------
 * This function returns a random integer in the range low to high,			�˺������شӵ͵��ߣ�������Χ�ڵ����������
 * inclusive.
 */

int RandomInteger(int low, int high);

/*
 * Function: RandomReal														������RandomReal
 * Usage: d = RandomReal(low, high);										ʹ�ã�d = RandomReal(low, high);
 * ---------------------------------										---------------------------------
 * This function returns a random real number in the half-open				�ú����ڰ뿪���� [low , high) �з���һ�����ʵ����
 * interval [low .. high), meaning that the result is always				����ζ�Ž��ʼ�մ��ڻ���� low ���ϸ�С�� high��
 * greater than or equal to low but strictly less than high.
 */

double RandomReal(double low, double high);

/*
 * Function: RandomChance													������RandomChance
 * Usage: if (RandomChance(p)) . . .										ʹ�ã�if (RandomChance(p)) . . .
 * ---------------------------------										---------------------------------
 * The RandomChance function returns TRUE with the probability				RandomChance ������ p ��ʾ�ĸ��ʷ��� TRUE��
 * indicated by p, which should be a floating-point number between			p Ӧ���ǽ��� 0����ʾ�Ӳ����� 1����ʾʼ�գ�֮��ĸ�������
 * 0 (meaning never) and 1 (meaning always).  For example, calling			���磬���� RandomChance(.30) �� 30% ��ʱ�䷵�� TRUE��
 * RandomChance(.30) returns TRUE 30 percent of the time.
 */

bool RandomChance(double p);

#endif
