#ifndef _Graphics_h_
#define _Graphics_h_
/* Graphics.h
 *
 * Copyright (C) 1992-2005 Paul Boersma
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or (at
 * your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

/*
 * pb 2005/09/18
 */

#ifndef _Thing_h_
	#include "Thing.h"
#endif
typedef struct structGraphics *Graphics;
Graphics Graphics_create (int resolution);
Graphics Graphics_create_postscriptjob (MelderFile file, int resolution, int spots,
	int paperSize, int rotation, double magnification);
Graphics Graphics_create_epsfile (MelderFile file, int resolution, int spots,
	double xmin, double xmax, double ymin, double ymax, int includeFonts, int useSilipaPS);
Graphics Graphics_create_postscriptprinter (void);
Graphics Graphics_create_screenPrinter (void *display, unsigned long window);
#define GraphicsPostscript_FINE  0
#define GraphicsPostscript_PHOTOCOPYABLE  1
#define Graphics_A4  0
#define Graphics_A3  1
#define Graphics_US_LETTER  2
#define Graphics_PORTRAIT  0
#define Graphics_LANDSCAPE  1
#define GraphicsPostscript_AUTOMATIC  0
#define GraphicsPostscript_LINOTYPE  1
#define GraphicsPostscript_MONOTYPE  2
#define GraphicsPostscript_PS_MONOTYPE  3
Graphics Graphics_create_screen (void *display, unsigned long window, int resolution);
#ifdef macintosh
	Graphics Graphics_create_port (void *display, unsigned long port, int resolution);
#endif
Graphics Graphics_create_xmdrawingarea (/* Widget */ void *drawingArea);

void Graphics_setWsViewport (I, short x1DC, short x2DC, short y1DC, short y2DC);
void Graphics_setWsWindow (I, double x1NDC, double x2NDC, double y1NDC, double y2NDC);
void Graphics_inqWsViewport (I, short *x1DC, short *x2DC, short *y1DC, short *y2DC);
void Graphics_inqWsWindow (I, double *x1NDC, double *x2NDC, double *y1NDC, double *y2NDC);
void Graphics_clearWs (I);
void Graphics_flushWs (I);
void Graphics_updateWs (I);
void Graphics_DCtoWC (I, short xDC, short yDC, double *xWC, double *yWC);
void Graphics_WCtoDC (I, double xWC, double yWC, short *xDC, short *yDC);

typedef struct { double x1NDC, x2NDC, y1NDC, y2NDC; } Graphics_Viewport;
void Graphics_setViewport (I, double x1NDC, double x2NDC, double y1NDC, double y2NDC);
Graphics_Viewport Graphics_insetViewport (I, double x1rel, double x2rel, double y1rel, double y2rel);
void Graphics_resetViewport (I, Graphics_Viewport viewport);
void Graphics_setWindow (I, double x1, double x2, double y1, double y2);

void Graphics_polyline (I, long numberOfPoints, float *x, float *y);
void Graphics_text (I, double x, double y, const char * text);
void Graphics_textRect (I, double x1, double x2, double y1, double y2, const char *txt);
double Graphics_textWidth (I, const char *txt);
double Graphics_textWidth_ps (I, const char *txt, int useSilipaPS);
double Graphics_textWidth_ps_mm (I, const char *txt, int useSilipaPS);
void Graphics_fillArea (I, long numberOfPoints, float *x, float *y);
void Graphics_cellArray (I, float **z, long ix1, long ix2, double x1, double x2,
	long iy1, long iy2, double y1, double y2, double minimum, double maximum);
void Graphics_cellArray8 (I, unsigned char **z, long ix1, long ix2, double x1, double x2,
	long iy1, long iy2, double y1, double y2, unsigned char minimum, unsigned char maximum);
void Graphics_image (I, float **z, long ix1, long ix2, double x1, double x2,
	long iy1, long iy2, double y1, double y2, double minimum, double maximum);
void Graphics_image8 (I, unsigned char **z, long ix1, long ix2, double x1, double x2,
	long iy1, long iy2, double y1, double y2, unsigned char minimum, unsigned char maximum);
void Graphics_line (I, double x1, double y1, double x2, double y2);
void Graphics_rectangle (I, double x1, double x2, double y1, double y2);
void Graphics_fillRectangle (I, double x1, double x2, double y1, double y2);
void Graphics_roundedRectangle (I, double x1, double x2, double y1, double y2, double r_mm);
void Graphics_fillRoundedRectangle (I, double x1, double x2, double y1, double y2, double r_mm);
void Graphics_function (I, float y [], long ix1, long ix2, double x1, double x2);   /* y [ix1..ix2] */
void Graphics_function16 (I, short y [], int stagger, long ix1, long ix2, double x1, double x2);
	/* y [ix1..ix2] or y [ix1*2..ix2*2] */
void Graphics_circle (I, double x, double y, double r);
void Graphics_fillCircle (I, double x, double y, double r);
void Graphics_circle_mm (I, double x, double y, double d);
void Graphics_fillCircle_mm (I, double x, double y, double d);
void Graphics_rectangle_mm (I, double x, double y, double horizontalSide_mm, double verticalSide_mm);
void Graphics_fillRectangle_mm (I, double x, double y, double horizontalSide_mm, double verticalSide_mm);
void Graphics_arc (I, double x, double y, double r, double fromAngle, double toAngle);
void Graphics_fillArc (I, double x, double y, double r, double fromAngle, double toAngle);
void Graphics_ellipse (I, double x1, double x2, double y1, double y2);
void Graphics_fillEllipse (I, double x1, double x2, double y1, double y2);
void Graphics_arrow (I, double x1, double y1, double x2, double y2);
void Graphics_arcArrow (I, double x, double y, double r, double fromAngle, double toAngle, int arrowAtStart, int arrowAtEnd);
void Graphics_mark (I, double x, double y, double size_mm, const char *markString);
void Graphics_button (I, double x1, double x2, double y1, double y2);
void Graphics_innerRectangle (I, double x1, double x2, double y1, double y2);

void Graphics_xorOn (I, int colour);
void Graphics_xorOff (I);
void Graphics_highlight (I, double x1, double x2, double y1, double y2);
void Graphics_unhighlight (I, double x1, double x2, double y1, double y2);
void Graphics_highlight2 (I, double x1, double x2, double y1, double y2,
	double innerX1, double innerX2, double innerY1, double innerY2);
void Graphics_unhighlight2 (I, double x1, double x2, double y1, double y2,
	double innerX1, double innerX2, double innerY1, double innerY2);

#define Graphics_NOCHANGE  -1
#define Graphics_LEFT  0
#define Graphics_CENTRE  1
#define Graphics_CENTER  1
#define Graphics_RIGHT  2
#define Graphics_JUSTIFIED  3
#define Graphics_BOTTOM  0
#define Graphics_HALF  1
#define Graphics_TOP  2
#define Graphics_BASELINE  3
void Graphics_setTextAlignment (I, int horizontal, int vertical);
void Graphics_setFont (I, int font);
#define Graphics_HELVETICA  0
#define Graphics_TIMES  1
#define Graphics_COURIER  2
#define Graphics_NEWCENTURYSCHOOLBOOK  3
#define Graphics_PALATINO  4
void Graphics_setFontSize (I, int height);
void Graphics_setFontStyle (I, int style);
void Graphics_setItalic (I, int onoff);
void Graphics_setBold (I, int onoff);
void Graphics_setCode (I, int onoff);
#define Graphics_NORMAL  0
#define Graphics_BOLD  1
#define Graphics_ITALIC  2
#define Graphics_BOLD_ITALIC  3
#define Graphics_CODE  4
void Graphics_setTextRotation (I, double angle);
void Graphics_setTextRotation_vector (I, double dx, double dy);
void Graphics_setWrapWidth (I, double wrapWidth);
void Graphics_setSecondIndent (I, double indent);
float Graphics_inqTextX (I);
float Graphics_inqTextY (I);
typedef struct { float x1, x2, y1, y2; char *name; } Graphics_Link;
int Graphics_getLinks (Graphics_Link **plinks);
void Graphics_setNumberSignIsBold (I, int isBold);
void Graphics_setPercentSignIsItalic (I, int isItalic);
void Graphics_setCircumflexIsSuperscript (I, int isSuperscript);
void Graphics_setUnderscoreIsSubscript (I, int isSubscript);
void Graphics_setDollarSignIsCode (I, int isCode);
void Graphics_setAtSignIsLink (I, int isLink);

void Graphics_setLineType (I, int lineType);
#define Graphics_DRAWN  0
#define Graphics_DOTTED  1
#define Graphics_DASHED  2
void Graphics_setLineWidth (I, double lineWidth);

void Graphics_setColour (I, int colour);
#define Graphics_setColor  Graphics_setColour
#define Graphics_BLACK  0
#define Graphics_WHITE  1
#define Graphics_RED  2
#define Graphics_GREEN  3
#define Graphics_BLUE  4
#define Graphics_CYAN  5
#define Graphics_MAGENTA  6
#define Graphics_YELLOW  7
#define Graphics_MAROON  8
#define Graphics_LIME  9
#define Graphics_NAVY  10
#define Graphics_TEAL  11
#define Graphics_PURPLE  12
#define Graphics_OLIVE  13
#define Graphics_SILVER  14
#define Graphics_GREY  15
void Graphics_setGrey (I, double grey);
#define Graphics_setGray  Graphics_setGrey

void Graphics_inqViewport (I, double *x1NDC, double *x2NDC, double *y1NDC, double *y2NDC);
void Graphics_inqWindow (I, double *x1WC, double *x2WC, double *y1WC, double *y2WC);
int Graphics_inqFont (I);
int Graphics_inqFontSize (I);
int Graphics_inqFontStyle (I);
int Graphics_inqLineType (I);
float Graphics_inqLineWidth (I);
int Graphics_inqColour (I);

void Graphics_printf (I, double xWC, double yWC, const char *format, ...);
void Graphics_contour (I, float **z,
	long ix1, long ix2, double x1WC, double x2WC, long iy1, long iy2, double y1WC, double y2WC, double height);
void Graphics_altitude (I, float **z,
	long ix1, long ix2, double x1, double x2, long iy1, long iy2, double y1, double y2, int numberOfBorders, float borders []);
void Graphics_grey (I, float **z,
	long ix1, long ix2, double x1, double x2, long iy1, long iy2, double y1, double y2, int numberOfBorders, float borders []);
#define Graphics_gray Graphics_grey
void Graphics_surface (I, float **z, long ix1, long ix2, double x1, double x2,
	long iy1, long iy2, double y1, double y2, double minimum, double maximum, double elevation, double azimuth);

void Graphics_setInner (I);
void Graphics_unsetInner (I);
void Graphics_drawInnerBox (I);
void Graphics_textLeft (I, int far, const char *text);
void Graphics_textRight (I, int far, const char *text);
void Graphics_textBottom (I, int far, const char *text);
void Graphics_textTop (I, int far, const char *text);
void Graphics_marksLeft (I, int numberOfMarks, int haveNumbers, int haveTicks, int haveDottedLines);
void Graphics_marksRight (I, int numberOfMarks, int haveNumbers, int haveTicks, int haveDottedLines);
void Graphics_marksBottom (I, int numberOfMarks, int haveNumbers, int haveTicks, int haveDottedLines);
void Graphics_marksTop (I, int numberOfMarks, int haveNumbers, int haveTicks, int haveDottedLines);
void Graphics_marksLeftLogarithmic (I, int numberOfMarksPerDecade, int haveNumbers, int haveTicks, int haveDottedLines);
void Graphics_marksRightLogarithmic (I, int numberOfMarksPerDecade, int haveNumbers, int haveTicks, int haveDottedLines);
void Graphics_marksBottomLogarithmic (I, int numberOfMarksPerDecade, int haveNumbers, int haveTicks, int haveDottedLines);
void Graphics_marksTopLogarithmic (I, int numberOfMarksPerDecade, int haveNumbers, int haveTicks, int haveDottedLines);
void Graphics_markLeft (I, double yWC, int hasNumber, int hasTick, int hasDottedLine, const char *text);
void Graphics_markRight (I, double yWC, int hasNumber, int hasTick, int hasDottedLine, const char *text);
void Graphics_markBottom (I, double xWC, int hasNumber, int hasTick, int hasDottedLine, const char *text);
void Graphics_markTop (I, double xWC, int hasNumber, int hasTick, int hasDottedLine, const char *text);
void Graphics_markLeftLogarithmic (I, double y /* > 0 */, int hasNumber, int hasTick, int hasDottedLine, const char *text);
void Graphics_markRightLogarithmic (I, double y, int hasNumber, int hasTick, int hasDottedLine, const char *text);
void Graphics_markBottomLogarithmic (I, double x, int hasNumber, int hasTick, int hasDottedLine, const char *text);
void Graphics_markTopLogarithmic (I, double x, int hasNumber, int hasTick, int hasDottedLine, const char *text);
void Graphics_marksLeftEvery (I, double units, double distance, int haveNumbers, int haveTicks, int haveDottedLines);
void Graphics_marksRightEvery (I, double units, double distance, int haveNumbers, int haveTicks, int haveDottedLines);
void Graphics_marksBottomEvery (I, double units, double distance, int haveNumbers, int haveTicks, int haveDottedLines);
void Graphics_marksTopEvery (I, double units, double distance, int haveNumbers, int haveTicks, int haveDottedLines);

void *Graphics_x_getGC (I);

int Graphics_startRecording (I);
int Graphics_stopRecording (I);
void Graphics_play (Graphics from, Graphics to);
int Graphics_writeRecordings (I, FILE *f);
int Graphics_readRecordings (I, FILE *f);
#ifdef _WIN32
int Graphics_readRecordings_oldWindows (I, FILE *f);
#endif
void Graphics_markGroup (I);
void Graphics_undoGroup (I);

double Graphics_dxMMtoWC (I, double dx_mm);
double Graphics_dyMMtoWC (I, double dy_mm);
double Graphics_distanceWCtoMM (I, double x1WC, double y1WC, double x2WC, double y2WC);
double Graphics_dxWCtoMM (I, double dxWC);
double Graphics_dyWCtoMM (I, double dyWC);

int Graphics_mouseStillDown (I);
void Graphics_waitMouseUp (I);
void Graphics_getMouseLocation (I, double *xWC, double *yWC);

void Graphics_nextSheetOfPaper (I);

/* End of file Graphics.h */
#endif
