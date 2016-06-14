#pragma once

/*
// Use this for custom type mappings for Trans2d type 
#define UI_TRANS2D_CLASS_EXTRA \
Trans2d(const cm::M33& f) { x.x=f[0].x;  x.y=f[0].y; \
    y.x=f[1].x;  y.y=f[1].y; \
    pos.x=f[2].x;  pos.y=f[2].y; } \
y.x=rot.col(1)[0];  y.y=rot.col(1)[1]; \
pos.x=p.x;  pos.y=p.y; } \
operator cm::M33() const { cm::M33 f; \
    f[0] = cm::V3(x.x, x.y, 0.0); \
    f[1] = cm::V3(y.x, y.y, 0.0); \
    f[2] = cm::V3(pos.x, pos.y, 1.); return f; }
*/

/* 
// Use this for custom type mappings for the rect type
#define UI_RECT_CLASS_EXTRA \
Rect( const cm::Box& r ) { min = r.min(); max = r.max(); } \
operator cm::Box() const { return cm::Box((cm::V2)min, (cm::V2)max); }
*/