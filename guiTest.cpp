//
//  guiTest.cpp
//  
//
//  Created by Zaim Zanaruddin on 11/9/16.
//
//

#include <stdio.h>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Menu_Bar.H>





void CB(Fl_Widget* w, void* p) {
       }



Fl_Menu_Item menuitems[] = {
    { "&File", 0, 0, 0, FL_SUBMENU },
    { "&New", FL_ALT + 'n', (Fl_Callback *)CB },
    { "&Open", FL_ALT + 'o', (Fl_Callback *)CB },
    { "&Save", FL_ALT + 's', (Fl_Callback *)CB },
    { "Save As", FL_ALT + 'S', (Fl_Callback *)CB },
    { "&Quit", FL_ALT + 'q', (Fl_Callback *)CB },
    { 0 },
    { "&Edit", 0, 0, 0, FL_SUBMENU },
    { "&Undo", 0, (Fl_Callback *)CB },
    { "Cu&t", 0, (Fl_Callback *)CB },
    { "&Copy", 0, (Fl_Callback *)CB },
    { "&Paste", 0, (Fl_Callback *)CB },
    { 0 },
    { "&Create", 0, 0, 0, FL_SUBMENU },
    { "Order", 0, (Fl_Callback *)CB, 0, FL_MENU_DIVIDER  },
    { "Customer", 0, (Fl_Callback *)CB },
    { "Sales Associate", 0, (Fl_Callback *)CB, 0, FL_MENU_DIVIDER  },
    { "Robot Part", 0, (Fl_Callback *)CB},
    { "Robot Model", 0, (Fl_Callback *)CB },
    { 0 },
    { "&Report", 0, 0, 0, FL_SUBMENU },
    { "Invoice", 0, (Fl_Callback *)CB, 0, FL_MENU_DIVIDER  },
    { "All Orders", 0, (Fl_Callback *)CB },
    { "Orders by Customer", 0, (Fl_Callback *)CB },
    { "Orders by Sales Associate", 0, (Fl_Callback *)CB, 0, FL_MENU_DIVIDER },
    { "All Customers", 0, (Fl_Callback *)CB },
    { "All Sales Associates", 0, (Fl_Callback *)CB, 0, FL_MENU_DIVIDER  },
    { "All Robot Models", 0, (Fl_Callback *)CB },
    { "All Robot Parts", 0, (Fl_Callback *)CB },
    { 0 },
    { "&Help", 0, 0, 0, FL_SUBMENU },
    { "&Manual", 0, (Fl_Callback *)CB},
    { "&About", 0, (Fl_Callback *)CB},
    { 0 },
    { 0 }
};
int main() {
  
    const int X = 1000;
    const int Y = 600;
    const int border =10;
    
    Fl_Menu_Bar *menubar;
    
    Fl_Window *win = new Fl_Window(X,Y, "Robot Shop Manager");
    // Add a new box object to the window
    Fl_Box *box = new Fl_Box(200,100,600,100,"Welcome to Express Robot Shop");
    Fl_Box *box2 = new Fl_Box(100,250,200,100,"Order");
    Fl_Box *box3 = new Fl_Box(300,250,200,100,"Create");
    Fl_Box *box4 = new Fl_Box(500,250,200,100,"View");
    Fl_Box *box5 = new Fl_Box(700,250,200,100,"Exit");


    // Set additional fields on the box to specify its appearance
    box->box(FL_UP_BOX);
    box->labelfont(FL_BOLD+FL_ITALIC);
    box->labelsize(36);
    box->labeltype(FL_SHADOW_LABEL);
    win->resizable(*box);
    
    box2->box(FL_UP_BOX);
    box2->labelfont(FL_BOLD+FL_ITALIC);
    box2->labelsize(36);
    box2->labeltype(FL_SHADOW_LABEL);
    win->resizable(*box2);
    
    box3->box(FL_UP_BOX);
    box3->labelfont(FL_BOLD+FL_ITALIC);
    box3->labelsize(36);
    box3->labeltype(FL_SHADOW_LABEL);
    win->resizable(*box3);
    
    box4->box(FL_UP_BOX);
    box4->labelfont(FL_BOLD+FL_ITALIC);
    box4->labelsize(36);
    box4->labeltype(FL_SHADOW_LABEL);
    win->resizable(*box4);
    
    
    box5->box(FL_UP_BOX);
    box5->labelfont(FL_BOLD+FL_ITALIC);
    box5->labelsize(36);
    box5->labeltype(FL_SHADOW_LABEL);
    win->resizable(*box5);


    // Install menu bar
    menubar = new Fl_Menu_Bar(0, 0, X, 30);
    menubar->menu(menuitems);
    
    
    
    
    
    // Done defining the new Window
    win->end();
    // Make the window visible, passing along any user options
    win->show();
    // Enter the “command loop” waiting for events
    return Fl::run();
}
