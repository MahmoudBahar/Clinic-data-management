#ifndef TERMINAL_H
#define	TERMINAL_H

//Colors numbers
#define	BLACK			0
#define	RED				1
#define	GREEN			2
#define	YELLOW			3
#define	BLUE			4
#define	MAGENTA			5
#define	CYAN			6
#define	WHITE			7
#define	GRAY			8
#define	BRIGHT_RED		9
#define	BRIGHT_GREEN	10
#define	BRIGHT_YELLOW	11
#define	BRIGHT_BLUE		12
#define	BRIGHT_MAGENTA	13
#define	BRIGHT_CYAN		14
#define	BRIGHT_WHITE	15

//GRAPHICAL OPTIONS
#define RESET							0
#define BOLD							1
#define FAINT							2
#define ITALIC							3
#define UNDERLINE						4
#define SLOW_BLINK						5
#define RAPID_BLINK						6
#define INVERT							7
#define HIDE							8
#define STRIKE							9
#define PRIMARY_FONT					10
#define ALTERNATIVE_FONT_0				11
#define ALTERNATIVE_FONT_1				12
#define ALTERNATIVE_FONT_2				13
#define ALTERNATIVE_FONT_3				14
#define ALTERNATIVE_FONT_4				15
#define ALTERNATIVE_FONT_5				16
#define ALTERNATIVE_FONT_6				17
#define ALTERNATIVE_FONT_7				18
#define ALTERNATIVE_FONT_8				19
#define FRAKTUR							20
#define DOUBLE_UNDERLINE				21
#define NORMAL_INTENSITY				22
#define NOT_ITALIC_BLACKLETTER			23
#define NOT_UNDERLINED					24
#define NOT_BLINKING					25
#define PROPORTIONAL_SPACING			26
#define NOT_REVERSED					27
#define REVEAL							28
#define NOT_CROSSED_OUT					29
#define DEFAULT_FOREGROUND_COLOR		39
#define DEFAULT_BACKGROUND_COLOR		49
#define DISABLE_PROPORTIONAL_SPACING	50
#define FRAMED							51
#define ENCIRCLED						52
#define OVERLINED						53
#define NOT_FRAMED_ENCIRCLED			54
#define NOT_OVERLINED					55
#define DEFAULT_UNDERLINE_COLOR			59
#define IDEOGRAM_UNDERLINE				60
#define IDEOGRAM_DOUBLE_UNDERLINE		61
#define IDEOGRAM_OVERLINE				62
#define IDEOGRAM_DOUBLE_OVERLINE		63
#define IDEOGRAM_STRESS_MARKING			64
#define NO_IDEOGRAM						65
#define SUPERSCRIPT						73
#define SUBSCRIPT						74
#define NOT_SUPERSCRIPT_SUBSCRIPT		75


void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}


#define	Change_Color_FG(color_number)		printf("%c[38;5;%dm", 27, color_number)

#define	Change_Color_BG(color_number)		printf("%c[48;5;%dm", 27, color_number)

#define	Change_Color_UL(color_number)		printf("%c[58;5;%dm", 27, color_number)

#define Select_Graphic_Rendition(Option)	printf("%c[%dm", 27, Option)

#define	Move_Cursor(right, up)				printf("%c[%d;%df", 27, up, right)

#define	Double_Height_Top()					printf("%c#%d", 27, 3)

#define	Double_Height_Bottom()				printf("%c#%d", 27, 4)

#define	Single_Width()						printf("%c#%d", 27, 5)

#define	Double_Width()						printf("%c#%d", 27, 6)

#define	Save_Cursor()						printf("%c[s",27)

#define	Erase_After_Cursor()				printf("%c[%dK",27,0)

#define	Erase_Before_Cursor()				printf("%c[%dK",27,1)

#define	Erase_Line()						printf("%c[%dK",27,2)

#define	Restore_Cursor()					printf("%c[u",27)

#endif