/*
 * File: strlib.h
 * Version: 1.0
 * Last modified on Fri Jul 15 14:10:40 1994 by eroberts
 * -----------------------------------------------------
 * The strlib.h file defines the interface for a simple					strlib.h �ļ�������һ�����ַ�����Ľӿڡ�													
 * string library.  In the context of this package, strings				�ڴ˰��У��ַ�������Ϊ��һ�ֳ����������ͣ�
 * are considered to be an abstract data type, which means				����ζ�ſͻ��˽�������Ϊ�����Ͷ���Ĳ��������������ڵײ��ʾ��
 * that the client relies only on the operations defined for
 * the type and not on the underlying representation.
 */

/*
 * Cautionary note:														ע�����
 * ----------------														----------------
 * Although this interface provides an extremely convenient				���ܴ˽ӿ�Ϊ�����ַ����ṩ�˼��䷽��ĳ��󣬵�����������������Ӧ�ó���
 * abstraction for working with strings, it is not appropriate			�ڴ˽ӿ��У������ַ���ֵ�ĺ��������� Concat �� SubString��ͨ���������ڴ���ʵ�֡�
 * for all applications.  In this interface, the functions that			����ʱ������ƣ�ʹ�ô˰��ĳ�������Խ��Խ����ڴ沢���պľ����õ��ڴ档
 * return string values (such as Concat and SubString) do so			��������ڱ�дһ������ʱ��̲ܶ�ֹͣ�ĳ�����ô����������ڴ����ʵ�������⡣
 * by allocating new memory.  Over time, a program that uses			���ǣ���������ڱ�дһ�����볤ʱ�����е�Ӧ�ó���
 * this package will consume increasing amounts of memory				��ʹ�ô˰���Ҫ��Ϊ�ͷ��κ��ѷ���Ĵ洢�ռ���һЩ׼����
 * and eventually exhaust the available supply.  If you are
 * writing a program that runs for a short time and stops,
 * the fact that the package consumes memory is not a problem.
 * If, however, you are writing an application that must run
 * for an extended period of time, using this package requires
 * that you make some provision for freeing any allocated
 * storage.
 */

#ifndef _strlib_h
#define _strlib_h

#include "genlib.h"

/* Section 1 -- Basic string operations */								/*��һ���� -- �����ַ�������*/

/*
 * Function: Concat														������Concat
 * Usage: s = Concat(s1, s2);											ʹ�ã�s = Concat(s1, s2);
 * --------------------------											--------------------------
 * This function concatenates two strings by joining them end			�˺���ͨ���������ַ�����β�������������ǡ�
 * to end.  For example, Concat("ABC", "DE") returns the string			���磬Concat("ABC", "DE") �����ַ�����ABCDE����
 * "ABCDE".
 */

string Concat(string s1, string s2);

/*
 * Function: IthChar													������IthChar
 * Usage: ch = IthChar(s, i);											ʹ�ã�ch = IthChar(s, i);
 * --------------------------											--------------------------
 * This function returns the character at position i in the				�˺��������ַ��� s ��λ�� i �����ַ���
 * string s.  It is included in the library to make the type			�������ڿ�����ʹ�����ַ�����Ϊ�����ĳ������ͣ���Ϊ����ʹ�ú����������б�Ҫ�Ĳ�����
 * string a true abstract type in the sense that all of the				���� IthChar(s, i) ����ѡ�� s[i] һ����
 * necessary operations can be invoked using functions. Calling			ֻ�� IthChar ��� i �Ƿ��ںϷ�����λ�õķ�Χ�ڣ��� 0 ���쵽 StringLength(s)��
 * IthChar(s, i) is like selecting s[i], except that IthChar			IthChar(s, StringLength(s)) �����ַ���ĩβ�Ŀ��ַ���	
 * checks to see if i is within the range of legal index
 * positions, which extend from 0 to StringLength(s).
 * IthChar(s, StringLength(s)) returns the null character
 * at the end of the string.
 */

char IthChar(string s, int i);

/*
 * Function: SubString													������SubString
 * Usage: t = SubString(s, p1, p2);										ʹ�ã�t = SubString(s, p1, p2);
 * --------------------------------										--------------------------------
 * SubString returns a copy of the substring of s consisting			SubString ���� s �����ַ����ĸ�����
 * of the characters between index positions p1 and p2,					�ø���������λ�� p1 �� p2 ֮����ַ���ɣ���������λ�á�
 * inclusive.  The following special cases apply:						�������������ʱ��
 *
 * 1. If p1 is less than 0, it is assumed to be 0.						1. ���p1С��0����ٶ�Ϊ0��
 * 2. If p2 is greater than the index of the last string				2. ��� p2 �������һ���ַ���λ�õ��������� StringLength(s) - 1��
 *    position, which is StringLength(s) - 1, then p2 is				   ������ p2 ���� StringLength(s) - 1��
 *    set equal to StringLength(s) - 1.
 * 3. If p2 < p1, SubString returns the empty string.				    3. ��� p2 < p1��SubString ���ؿ��ַ�����
 */

string SubString(string s, int p1, int p2);

/*
 * Function: CharToString												������CharToString
 * Usage: s = CharToString(ch);											ʹ�ã�s = CharToString(ch);
 * ----------------------------											----------------------------
 * This function takes a single character and returns a					�˺�������ĳ���ַ��������ɸ��ַ���ɵĵ��ַ��ַ�����
 * one-character string consisting of that character.  The				CharToString ���������ã����磬�������Ҫ�����ַ������ַ���
 * CharToString function is useful, for example, if you					���� Concat ��Ҫ�����ַ�������˱����Ƚ��ַ�ת��Ϊ�ַ�����
 * need to concatenate a string and a character.  Since
 * Concat requires two strings, you must first convert
 * the character into a string.
 */

string CharToString(char ch);

/*
 * Function: StringLength												������StringLength
 * Usage: len = StringLength(s);										���ö����˰ɡ�
 * -----------------------------
 * This function returns the length of s.
 */

int StringLength(string s);

/*
 * Function: CopyString													������CopyString
 * Usage: newstr = CopyString(s);										ʹ�ã�newstr = CopyString(s);
 * ------------------------------										------------------------------
 * CopyString copies the string s into dynamically allocated			CopyString ���ַ��� s ���Ƶ���̬����Ĵ洢�в��������ַ�����
 * storage and returns the new string.  This function is not			�������ʹ�ô˰���ͨ������Ҫ�˹��ܣ�����ʹ�ö���ַ�����ʱͨ����Ҫ�˹��ܡ�
 * ordinarily required if this package is used on its own,
 * but is often necessary when you are working with more than
 * one string package.
 */

string CopyString(string s);

/* Section 2 -- String comparison functions */							/*�ڶ����� -- �ַ����ȽϺ���*/

/*
 * Function: StringEqual												������StringEqual
 * Usage: if (StringEqual(s1, s2)) ...									ʹ�ã�if (StringEqual(s1, s2)) ...
 * -----------------------------------									-----------------------------------
 * This function returns TRUE if the strings s1 and s2 are				����ַ��� s1 �� s2 ��ȣ���˺������� TRUE��
 * equal.  For the strings to be considered equal, every				���ڱ���Ϊ��ȵ��ַ�����һ���ַ����е�ÿ���ַ����뾫ȷƥ����һ���ַ����е���Ӧ�ַ���
 * character in one string must precisely match the						���ִ�Сд��
 * corresponding character in the other.  Uppercase and
 * lowercase characters are considered to be different.
 */

bool StringEqual(string s1, string s2);

/*
 * Function: StringCompare												������StringCompare
 * Usage: if (StringCompare(s1, s2) < 0) ...							ʹ�ã�if (StringCompare(s1, s2) < 0) ...
 * -----------------------------------------							-----------------------------------------
 * This function returns a number less than 0 if string s1				����ַ��� s1 ����ĸ˳���� s2 ֮ǰ����˺�������С�� 0 �����֣�
 * comes before s2 in alphabetical order, 0 if they are equal,			�����������򷵻� 0����� s1 �� s2 ֮���򷵻ش��� 0 �����֡�
 * and a number greater than 0 if s1 comes after s2.  The				�����������ַ����ڲ���ʾȷ����ͨ���� ASCII��
 * ordering is determined by the internal representation used
 * for characters, which is usually ASCII.
 */

int StringCompare(string s1, string s2);

/* Section 3 -- Search functions */										/*�������� -- ��������*/

/*
 * Function: FindChar													������FindChar	
 * Usage: p	= FindChar(ch, text, start);								ʹ�ã�p = FindChar(ch, text, start);
 * -------------------------------------								-------------------------------------
 * Beginning at position start in the string text, this					���ַ����ı��е� start λ�ÿ�ʼ���˺��������ַ� ch �����������ֵĵ�һ��������
 * function searches for the character ch and returns the				���û���ҵ�ƥ����򷵻� -1��
 * first index at which it appears or -1 if no match is
 * found.
 */

int FindChar(char ch, string text, int start);

/*
 * Function: FindString													������FindString
 * Usage: p = FindString(str, text, start);								ʹ�ã�p = FindString(str, text, start);
 * ----------------------------------------								----------------------------------------
 * Beginning at position start in the string text, this					���ַ����ı��� start λ�ÿ�ʼ���˺��������ַ��� str �����������ֵĵ�һ��������	
 * function searches for the string str and returns the					���û���ҵ�ƥ����򷵻� -1��
 * first index at which it appears or -1 if no match is
 * found.
 */

int FindString(string str, string text, int start);

/* Section 4 -- Case-conversion functions */							/*���Ĳ��� -- ��Сдת������*/

/*
 * Function: ConvertToLowerCase											������ConvertToLowerCase
 * Usage: s = ConvertToLowerCase(s);									ʹ�ã�s = ConvertToLowerCase(s);
 * ---------------------------------									---------------------------------	
 * This function returns a new string with all							����һ��ȫСд�汾��s
 * alphabetic characters converted to lower case.
 */

string ConvertToLowerCase(string s);

/*
 * Function: ConvertToUpperCase											������ConvertToUpperCase
 * Usage: s = ConvertToUpperCase(s);									���ö����˰ɡ�
 * ---------------------------------
 * This function returns a new string with all
 * alphabetic characters converted to upper case.
 */

string ConvertToUpperCase(string s);

/* Section 5 -- Functions for converting numbers to strings */			/*���岿�� -- ���֡��ַ���ת���ĺ���*/

/*
 * Function: IntegerToString											������IntegerToString
 * Usage: s	= IntegerToString(n);										ʹ�ã�s = IntegerToString(n);
 * ------------------------------										------------------------------
 * This function converts an integer into the corresponding				�˺���������ת��Ϊ��Ӧ�������ַ�����
 * string of digits.  For example, IntegerToString(123)					���磬IntegerToString(123) ����123����Ϊ�ַ������ء�
 * returns "123" as a string.	
 */

string IntegerToString(int n);

/*
 * Function: StringToInteger											������StringToInteger
 * Usage: n = StringToInteger(s);										ʹ�ã�n = StringToInteger(s);
 * ------------------------------										------------------------------
 * This function converts a string of digits into an integer.			�˺�����һ������ת��Ϊ������
 * If the string is not a legal integer or contains extraneous			����ַ������ǺϷ�����������޹��ַ����� StringToInteger �ᷢ�������źš�
 * characters, StringToInteger signals an error condition.
 */

int StringToInteger(string s);

/*
 * Function: RealToString												������RealToString
 * Usage: s = RealToString(d);											ʹ�ã�s = RealToString(d);
 * ---------------------------											---------------------------		
 * This function converts a floating-point number into the				�˺�����������ת��Ϊ��Ӧ���ַ�����ʽ��
 * corresponding string form.  For example, calling						���磬���� RealToString(23.45) ���ء�23.45����
 * RealToString(23.45) returns "23.45".  The conversion is				ת���� printf �����ڡ�%G����ʽ��ת����ͬ��
 * the same as that used for "%G" format in printf.
 */

string RealToString(double d);

/*
 * Function: StringToReal												������StringToReal
 * Usage: d = StringToReal(s);											ʹ�ã�d = StringToReal(s);
 * ---------------------------											---------------------------
 * This function converts a string representing a real number			�˺�������ʾʵ�����ַ���ת��Ϊ���Ӧ��ֵ��
 * into its corresponding value.  If the string is not a				����ַ������ǺϷ��ĸ�����������޹��ַ����� StringToReal �ᷢ�������źš�
 * legal floating-point number or if it contains extraneous
 * characters, StringToReal signals an error condition.
 */

double StringToReal(string s);

#endif
