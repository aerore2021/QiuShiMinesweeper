/*
 * File: simpio.h
 * Version: 1.0
 * Last modified on Wed Apr 27 07:29:13 1994 by eroberts
 * -----------------------------------------------------
 * This interface provides access to a simple package of						�ýӿ��ṩ�Լ��������ݶ�ȡ�ļ򵥺������ķ��ʡ�
 * functions that simplify the reading of input data.			
 */

#ifndef _simpio_h
#define _simpio_h

#include "genlib.h"

/*
 * Function: GetInteger															������GetInteger
 * Usage: i = GetInteger();														ʹ�ã�i = GetInteger();
 * ------------------------														------------------------
 * GetInteger reads a line of text from standard input and scans				GetInteger �ӱ�׼�����ж�ȡһ���ı�������ɨ��Ϊ������
 * it as an integer.  The integer value is returned.  If an						��������ֵ��
 * integer cannot be scanned or if more characters follow the					����޷�ɨ������ �� ���ֺ����и����ַ������û��л������ԡ�
 * number, the user is given a chance to retry.
 */

int GetInteger(void);

/*
 * Function: GetLong															������GetLong
 * Usage: l = GetLong();														���ö�����
 * ---------------------
 * GetLong reads a line of text from standard input and scans
 * it as a long integer.  The value is returned as a long.
 * If an integer cannot be scanned or if more characters follow
 * the number, the user is given a chance to retry.
 */

long GetLong(void);

/*
 * Function: GetReal															������GetReal
 * Usage: x = GetReal();														ʹ�ã�x = GetReal();
 * ---------------------														---------------------
 * GetReal reads a line of text from standard input and scans					GetReal �ӱ�׼�����ȡһ���ı�������ɨ��Ϊ˫�������֡�
 * it as a double.  If the number cannot be scanned or if extra
 * characters follow after the number ends, the user is given
 * a chance to reenter the value.
 */

double GetReal(void);

/*
 * Function: GetLine															������GetLine
 * Usage: s = GetLine();														ʹ�ã�s = GetLine();
 * ---------------------														---------------------
 * GetLine reads a line of text from standard input and returns					GetLine �ӱ�׼�����ж�ȡһ���ı�����������Ϊ�ַ������ء�
 * the line as a string.  The newline character that terminates					��ֹ����Ļ��з����洢Ϊ�ַ�����һ���֡�
 * the input is not stored as part of the string.
 */

string GetLine(void);

/*
 * Function: ReadLine															������ReadLine
 * Usage: s = ReadLine(infile);													ʹ�ã�s = ReadLine(infile);
 * ----------------------------													----------------------------
 * ReadLine reads a line of text from the input file and						ReadLine �������ļ��ж�ȡһ���ı�����������Ϊ�ַ������ء�
 * returns the line as a string.  The newline character							��ֹ����Ļ��з����洢Ϊ�ַ�����һ���֡�
 * that terminates the input is not stored as part of the						��� infile λ���ļ�ĩβλ�ã�ReadLine ���������� NULL��
 * string.  The ReadLine function returns NULL if infile	
 * is at the end-of-file position.
 */

string ReadLine(FILE *infile);

#endif
