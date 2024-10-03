#include "escape_graphics.h"

// EXPERIMENTAL BUFFER FUNCTIONS
/*
void print_buffer(scr_buf buf) {
	for (u32 character = buf.height * buf.width; character > 0; character--) {
		if (character == NULL) return;
		printf("%c", buf.buffer[character]);
	}
}

void fill_buffer(scr_buf buf, char fill_char) {
	for (u32 i = 79990; i > 0; i--) {
		buf.buffer[i] = fill_char;
	}
}
*/
// EXPERIMENTAL BUFFER FUNCTIONS

float sqrt(u16 x) {
	if (x <= 1) return 0; // Safety Operator to prevent crashes because of dividing by 0
	float s;
	s = ((x / 2) + x / (x / 2)) / 2;
	for (u16 i = 1; i <= 4; i++) {
		s = (s + x / s) / 2;
	}
	return s;
}

u16 distance(u16 x1, u16 y1, u16 x2, u16 y2) {
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

u16 lerp(u16 v0, u16 v1, float t) {
	return (u16)(v0 + t * (v1 - v0));
}

void rect(u16 x1, u16 y1, u16 x2, u16 y2, char h_char, char v_char, char tl_char, char tr_char, char bl_char, char br_char) {
	h_line(x1 + 1, y1, x2 - x1, h_char);
	h_line(x1 + 1, y2, x2 - x1, h_char);
	v_line(x1, y1 + 1, y2 - y1, v_char);
	v_line(x2, y1 + 1, y2 - y1, v_char);
	move(x1, y1);
	printf("%c", tl_char);
	move(x2, y1);
	printf("%c", tr_char);
	move(x1, y2);
	printf("%c", bl_char);
	move(x2, y2);
	printf("%c", br_char);
}

void rect_relative(u16 x, u16 y, u16 width, u16 height, char h_char, char v_char, char tl_char, char tr_char, char bl_char, char br_char) {
	rect(x, y, x + width, y + height, h_char, v_char, tl_char, tr_char, bl_char, br_char);
}

void rect_filled(u16 x1, u16 y1, u16 x2, u16 y2, char h_char, char v_char, char tl_char, char tr_char, char bl_char, char br_char, char fill_char) {
	fill(x1, y1, x2, y2, fill_char);
	h_line(x1, y1, x2 - x1, h_char);
	h_line(x1, y2, x2 - x1, h_char);
	v_line(x1, y1, y2 - y1, v_char);
	v_line(x2, y1, y2 - y1, v_char);
	move(x1, y1);
	printf("%c", tl_char);
	move(x2, y1);
	printf("%c", tr_char);
	move(x1, y2);
	printf("%c", bl_char);
	move(x2, y2);
	printf("%c", br_char);
}

void rect_filled_relative(u16 x, u16 y, u16 width, u16 height, char h_char, char v_char, char tl_char, char tr_char, char bl_char, char br_char, char fill_char) {
	rect_filled(x, y, x + width, y + height, h_char, v_char, tl_char, tr_char, bl_char, br_char, fill_char);
}

void line(u16 x1, u16 y1, u16 x2, u16 y2, char fill_char) {
	float lerp_progress = 0, increment = 1.0/distance(x1, y1, x2, y2);
	for (u16 i = 0; i < distance(x1, y1, x2, y2); i++) {
		lerp_progress += increment;
		move(lerp(x1, x2, lerp_progress), lerp(y1, y2, lerp_progress));
		printf("%c", fill_char);
	}
}

void h_line(u16 x, u16 y, u16 length, char fill_char) {
	u16 end_position = y + length;
	move(x, y);
	for (u16 i = y; i < end_position; i++) {
		printf("%c", fill_char);
	}
}

void v_line(u16 x, u16 y, u16 length, char fill_char) {
	u16 end_position = y + length;
	move(x, y);
	for (u16 i = y; i < end_position; i++) {
		printf("%c", fill_char);
		move_down(1);
		move_left(1);
	}
}

void circle(u16 x, u16 y, u16 radius, char line_char) {
	//get diameter in char spaces and then use sin and cos to draw outline points
}

void fill(u16 x1, u16 y1, u16 x2, u16 y2, char fill_char) {
	for (u16 i = y1; i < y2; i++)
	{
		h_line(x1, i, x2-x1, fill_char);
	}
}

void fill_relative(u16 x, u16 y, u16 width, u16 height, char fill_char) {
	fill(x, y, x + width, y + height, fill_char);
}

// UI ELEMENTS

void ui_color(u8* object_color, u8 r, u8 g, u8 b) {
	object_color[0] = r;
	object_color[1] = g;
	object_color[2] = b;
}

void label(u16 x, u16 y, const char* text) {
	move(x, y);
	put(text);
}

void progress_bar(u16 x, u16 y, u16 length, u64 max_value, u64 value, char full_char, char empty_char, const char* prefix, const char* suffix, u8 text_align) {

}

// UI ELEMENTS