#pragma once

#ifndef ESCAPE_CODES_H
#include "escape_codes.h"
#endif

#ifndef ESCAPE_GRAPHICS_LIB
#define ESCAPE_GRAPHICS_LIB

// CUSTOMIZATION VARIABLES

u8
// RECT
rect_color[] = { 0, 0, 0 },
rect_bg_color[] = { 0, 0, 0 },
// RECT
// LINES
line_color[] = { 0, 0, 0 },
line_bg_color[] = { 0, 0, 0 },
// LINES
// FILL
fill_color[] = { 0,0,0 },
fill_bg_color[] = { 0,0,0 },
// FILL
// LABEL
label_color[] = { 0,0,0 },
label_bg_color[] = { 0,0,0 },
// LABEL
// PROGRESS BAR
progress_bar_full_color[] = { 0,0,0 },
progress_bar_full_bg_color[] = { 0,0,0 },
progress_bar_empty_color[] = { 0,0,0 },
progress_bar_empty_bg_color[] = { 0,0,0 },
progress_bar_text_color[] = { 0,0,0 },
// PROGRESS BAR
// WINDOW
window_border_color[] = { 0,0,0 },
window_border_bg_color[] = { 0,0,0 },
window_bg_color[] = { 0,0,0 },
// WINDOW
// CIRCLE
circle_color[] = { 0,0,0 },
circle_bg_color[] = { 0,0,0 };
// CIRCLE



// CUSTOMIZATION VARIABLES

// ENUMS AND STRUCTS
enum graph_type {
	BAR,
	COLUMN,
	LINE,
	LINE_AUTOSCALE,
	PIE,
	DOUGHNUT,
	AREA
};

enum alignment {
	LEFT,
	CENTER,
	RIGHT,
	PROGRESS_OVER,
	PROGRESS_UNDER,
	PROGRESS_MIDDLE,
	START,
	END
};

typedef struct vec2 {
	i16 x, y;
} pos;

// EXPERIMENTAL BUFFER FUNCTIONS
/*
typedef struct screen_buffer {
	char buffer[80000];
	u16 height, width;
} scr_buf;

// ENUMS AND STRUCTS

void print_buffer(scr_buf buf);

void fill_buffer(scr_buf buf, char fill_char);
*/
// EXPERIMENTAL BUFFER FUNCTIONS

float sqrt(u16 x);

u16 distance(u16 x1, u16 y1, u16 x2, u16 y2);

u16 lerp(u16 v0, u16 v1, float t);

void rect(u16 x1, u16 y1, u16 x2, u16 y2, char h_char, char v_char, char tl_char, char tr_char, char bl_char, char br_char);

void rect_relative(u16 x, u16 y, u16 width, u16 height, char h_char, char v_char, char tl_char, char tr_char, char bl_char, char br_char);

void rect_filled(u16 x1, u16 y1, u16 x2, u16 y2, char h_char, char v_char, char tl_char, char tr_char, char bl_char, char br_char, char fill_char);

void rect_filled_relative(u16 x, u16 y, u16 width, u16 height, char h_char, char v_char, char tl_char, char tr_char, char bl_char, char br_char, char fill_char);

void h_line(u16 x, u16 y, u16 length, char fill_char);

void v_line(u16 x, u16 y, u16 length, char fill_char);

void line(u16 x1, u16 y1, u16 x2, u16 y2, char fill_char);

void circle(u16 x, u16 y, u16 radius, char line_char);

void fill(u16 x1, u16 y1, u16 x2, u16 y2, char fill_char);

void fill_relative(u16 x, u16 y, u16 width, u16 height, char fill_char);

// UI ELEMENTS

void ui_color(u8* object_color, u8 r, u8 g, u8 b);

void window(u16 x1, u16 y1, u16 x2, u16 y2, u8 title_alignment);

void label(u16 x, u16 y, const char* text);

void progress_bar(u16 x, u16 y, u16 length, u64 max_value, u64 value, char full_char, char empty_char, const char* prefix, const char* suffix, u8 text_align);

//void graph(pos start_position, pos end_position, u8 type, i32* data_array);

//void graph_relative(pos position, pos size, u8 type, i32* data_array);

// UI ELEMENTS

#endif // !ESCAPE_GRAPHICS_LIB