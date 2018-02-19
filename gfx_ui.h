/********************************************************************
 --------------------------------------------------------------------
 --           _,(_)._
 --      ___,(_______).      ____
 --    ,'__.           \    /\___\-.
 --   /,' /             \  /  /     \
 --  | | |              |,'  /       \
 --   \`.|                  /    ___|________
 --    `. :           :    /     gfx_ui
 --      `.            :.,'        A immediate mode 2d graphics manipulation UI
 --        `-.________,-'          Built on top of IMGUI
 --								   © Daniel Berio
 --                                http://www.enist.org
 --								   drand48@gmail.com
 --
 --------------------------------------------------------------------
 ********************************************************************/


#pragma once
#include "imgui.h"
#include "gfx_ui_config.h"
#include <stdlib.h>
#include <vector>
#include <string>
#include <sstream>

namespace ui
{
    enum
    {
        DRAGGER_CIRCLE = 0,
        DRAGGER_SQUARE = 1
    };
    

    struct Trans2d
    {
        Trans2d() {}
        Trans2d( const ImVec2& x, const ImVec2& y, const ImVec2& pos)
        : x(x), y(y), pos(pos) {}
        
#ifdef UI_TRANS2D_CLASS_EXTRA
        UI_TRANS2D_CLASS_EXTRA
#endif
        
        ImVec2 x;
        ImVec2 y;
        ImVec2 pos;
    };
    
    struct Rect
    {
        Rect() {}
        Rect( const ImVec2& min, const ImVec2& max )
        : min(min), max(max) {}
        
#ifdef UI_RECT_CLASS_EXTRA
        UI_RECT_CLASS_EXTRA
#endif
        
        bool contains( const ImVec2& p ) const { return ( p.x >= min.x && p.y >= min.y
                                                 && p.x <= max.x && p.y <= max.y ); }

        ImVec2 min;
        ImVec2 max;
    };
    
    struct Config
    {
        Config()
        {
            rounding = 2.0;
            draggerSize = 4.0;
            lineColor = 0xff666666;
            hoverColor = 0xff0000ff;
            selectedColor = 0xff0044ff;
            color=0xff666666;
            textColor=0xff333333;
        }

        float rounding;
        float draggerSize;
        ImU32 lineColor;
        ImU32 hoverColor;
        ImU32 selectedColor;
        ImU32 color;
        ImU32 textColor;
    };
    
    extern Config config;
    
    /// Returns true if the IMGUI/gfx_ui have focus
    /// Since gfx_ui creates a "full screen" window to handle interactions through IMGUI,
    /// you should use this rather than ImGui::GetIO().WantCaptureMouse to check weather
    /// your application should handle mouse events
    bool hasFocus();
    
    /// Initialization, starts up the font
    /// This function should be called BEFORE the IMGUI texture atlas is created 
    /// And AFTER the default IMGUI texture has been loaded. 
    /// Should find a less restrictive way to handle this.
    void init( float iconSize=20.0, const std::string& iconFontPath="");
    
    /// The UI should be called withing these begin end blocks
    void begin( const std::string& name="gfx_ui" );
    void end();
    
    /// Will return true if the previous widget call has caught an interaction
    bool modified();
    
    bool modifierShift();
    bool modifierAlt();
    
    /// Dragger widget
    ImVec2 dragger( int index, ImVec2 pos, bool selected=false, float size=-1. );

    /// Highlights a dragger
    void highlightDragger( const ImVec2& pos, float size=-1.  );
    
    /// Draw a line from a to b
    void line( const ImVec2& a, const ImVec2& b, ImColor clr=ImColor(ImVec4(-1,-1,-1,1)) );

    // Draw text string
    void text( ImVec2 pos, const std::string& str, ImColor clr=ImColor(ImVec4(-1,-1,-1,1)) );

    /// Angle and length handle widget
    ImVec2 lengthHandle( int index, ImVec2 thetaLen, float startTheta, const ImVec2& pos, const ImVec2& minThetaLen, const ImVec2& maxThetaLen, bool selected=false );

    /// Angle handle widget
    float handle( int index, float ang, const ImVec2& pos, float length, float startTheta=0.0f, float minTheta=0.0f, float maxTheta=0.0f, bool selected=false );

    /// Simple affine transform widget (two axes, centered)
    Trans2d affineSimple( int index, Trans2d m, bool selected=false, float scale=1. );
    
    /// Creates a draggable rect for selection, see demo() for example usage
    Rect selector();

    /// Returns current mouse delta
    ImVec2 dragDelta();
    
    /// Creates a font-icon toolbar (not necessary to call between begin and end)
    int toolbar( const std::string& title, const std::string& items, int selectedItem, bool horizontal=false, bool showAscii=false );
    
    void demo();   
}
