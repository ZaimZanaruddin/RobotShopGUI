//
//  main.cpp
//  
//
//  Created by Zaim Zanaruddin on 11/20/16.
//
//

#include "shop.h"
#include "controller.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/fl_Input.H>
#include <FL/fl_Multiline_Input.H>
#include <FL/fl_Button.H>
#include <FL/fl_Return_Button.H>
#include <FL/fl_Widget.H>
#include <FL/fl_Window.H>
#include <FL/fl_Browser.H>
#include <FL/Fl_JPEG_Image.H>
#include <FL/Fl_Shared_Image.H>

using namespace std;

Shop shop{"Robbie Robot Shop"};



//Callback for Parts


void create_headCB(Fl_Widget* w, void* p);
void cancel_headCB(Fl_Widget* w, void* p);
class Head_Dialog;

void create_armCB(Fl_Widget* w, void* p);
void cancel_armCB(Fl_Widget* w, void* p);
class Arm_Dialog;

void create_batteryCB(Fl_Widget* w, void* p);
void cancel_batteryCB(Fl_Widget* w, void* p);
class Battery_Dialog;

void create_locomotorCB(Fl_Widget* w, void* p);
void cancel_locomotorCB(Fl_Widget* w, void* p);
class Locomotor_Dialog;

void create_torsoCB(Fl_Widget* w, void* p);
void cancel_torsoCB(Fl_Widget* w, void* p);
class Torso_Dialog;


//Callback for Models
void create_modelCB(Fl_Widget* w, void* p);
void cancel_modelCB(Fl_Widget* w, void* p);
class Model_Dialog;

void view_modelCB(Fl_Widget* w, void* p);
void cancel_view_modelCB(Fl_Widget* w, void* p);
class View_Model_Dialog;

//Callback for Orders
void create_orderCB(Fl_Widget* w, void* p);
void cancel_orderCB(Fl_Widget* w, void* P);
class Create_Order_Dialog;

class View_Order_Dialog;
void cancel_view_orderCB(Fl_Widget* w, void *p);


//Callback for Customers
void create_customerCB(Fl_Widget* w, void *p);
void cancel_customerCB(Fl_Widget* w, void *p);
class Customer_Dialog;

void view_customerCB(Fl_Widget* w, void *p);
void cancel_view_customerCB(Fl_Widget* w, void *p);
class View_Customer_Dialog;


//Callback for Sales Associates
void create_salesCB(Fl_Widget* w, void *p);
void cancel_salesCB(Fl_Widget* w, void *p);
class Sales_Dialog;

void view_SalesCB(Fl_Widget* w, void *p);
void cancel_view_salesCB(Fl_Widget* w, void *p);
class View_Sales_Dialog;






//widgets
Fl_Window *win;
Head_Dialog *head_dlg;
Arm_Dialog *arm_dlg;
Torso_Dialog *torso_dlg;
Battery_Dialog *battery_dlg;
Locomotor_Dialog *locomotor_dlg;
Model_Dialog *model_dlg;
View_Model_Dialog *view_model_dlg;
Customer_Dialog *customer_dlg;
View_Customer_Dialog *view_customer_dlg;
Sales_Dialog *sales_dlg;
View_Sales_Dialog *view_sales_dlg;
Create_Order_Dialog *create_order_dlg;
View_Order_Dialog *view_order_dlg;
Fl_Menu_Bar *menubar;



class Model_Dialog {
public:
	Model_Dialog() {
		
		dialog = new Fl_Window(400, 550, "Creating a Model");
		
		rp_name = new Fl_Input(120, 10, 250, 25, "Name:");
		rp_name->align(FL_ALIGN_LEFT);
		
		rp_number = new Fl_Input(120, 40, 250, 25, "Part Number:");
		rp_number->align(FL_ALIGN_LEFT);
		
		rp_cost = new Fl_Input(120, 70, 250, 25, "Cost:");
		rp_cost->align(FL_ALIGN_LEFT);
		
		rp_arm = new Fl_Browser(120, 100, 250, 75, "Arm:");
		rp_arm->type(FL_MULTI_BROWSER);
		rp_arm->align(FL_ALIGN_LEFT);
        
        rp_head = new Fl_Browser(120, 180, 250, 75, "Head:");
        rp_head->type(FL_MULTI_BROWSER);
        rp_head->align(FL_ALIGN_LEFT);
        
        rp_battery = new Fl_Browser(120, 260, 250, 75, "Battery:");
        rp_battery->type(FL_MULTI_BROWSER);
        rp_battery->align(FL_ALIGN_LEFT);
        
        rp_locomotor = new Fl_Browser(120, 310, 250, 75, "Locomotor:");
        rp_locomotor->type(FL_MULTI_BROWSER);
        rp_locomotor->align(FL_ALIGN_LEFT);
        
        rp_torso = new Fl_Browser(120, 390, 250, 75, "Torso:");
        rp_torso->type(FL_MULTI_BROWSER);
        rp_torso->align(FL_ALIGN_LEFT);
        
		rp_create = new Fl_Return_Button(145, 500, 120, 25, "Create");
		rp_create->callback((Fl_Callback *)create_modelCB, 0);
		
		rp_cancel = new Fl_Button(270, 500, 60, 25, "Cancel");
		rp_cancel->callback((Fl_Callback *)cancel_modelCB, 0);
		
		dialog->end();
		dialog->set_non_modal();
	}
	
	void show() { dialog->show(); }
	void hide() { dialog->hide(); }
	string name() {return rp_name->value();}
	string part_number() { return rp_number->value(); }
	string weight() { return rp_weight->value(); }
	string cost() { return rp_cost->value(); }
	string description() { return rp_description->value(); }
    int arm() {return rp_arm->value();}
    int battery() {return rp_battery->value();}
    int head() {return rp_head->value();}
    int locomotor() {return rp_locomotor->value();}
    int torso() {return rp_torso->value();}
    
	

	Fl_Window *dialog;
	Fl_Input *rp_name;
	Fl_Browser *rp_arm;
    Fl_Browser *rp_head;
    Fl_Browser *rp_battery;
    Fl_Browser *rp_locomotor;
    Fl_Browser *rp_torso;
	Fl_Input *rp_number;
	Fl_Input *rp_weight;
	Fl_Input *rp_cost;
	Fl_Input *rp_description;
	Fl_Return_Button *rp_create;
	Fl_Button *rp_cancel;
	
	
};

class View_Model_Dialog{
public:
    View_Model_Dialog(){
        
        dialog= new Fl_Window(340, 310, "Models");
        
        
        view = new Fl_Browser(10,10,320,250);
        view->type(FL_MULTI_BROWSER);
        view->align(FL_ALIGN_LEFT);
        
        exit = new Fl_Button(270,270,60,25, "Exit");
        exit ->callback((Fl_Callback *)cancel_view_modelCB, 0);
    
    }
    
    void show(){dialog->show();}
    void hide(){dialog->hide();}
    


    Fl_Window *dialog;
    Fl_Browser *view;
    Fl_Button *exit;
    
    
    
};


class Head_Dialog {
public:
    Head_Dialog() {
		
        dialog = new Fl_Window(340, 240, "Head");
		
        rp_name = new Fl_Input(120, 10, 210, 25, "Name:");
        rp_name->align(FL_ALIGN_LEFT);

        rp_part_number = new Fl_Input(120, 40, 210, 25, "Part Number:");
        rp_part_number->align(FL_ALIGN_LEFT);
        
        
        rp_weight = new Fl_Input(120, 70, 210, 25, "Weight:");
        rp_weight->align(FL_ALIGN_LEFT);
        
        rp_cost = new Fl_Input(120, 100, 210, 25, "Cost:");
        rp_cost->align(FL_ALIGN_LEFT);
        
        rp_description = new Fl_Multiline_Input(120, 130, 210, 75, "Description:");
        rp_description->align(FL_ALIGN_LEFT);
        
        rp_create = new Fl_Return_Button(145, 210, 120, 25, "Create");
        rp_create->callback((Fl_Callback *)create_headCB, 0);
        
        rp_cancel = new Fl_Button(270, 210, 60, 25, "Cancel");
        rp_cancel->callback((Fl_Callback *)cancel_headCB, 0);
        
        dialog->end();
        dialog->set_non_modal();
    }
    
    void show() { dialog->show(); }
    void hide() { dialog->hide(); }
    string name() {return rp_name->value();}
    string part_number() { return rp_part_number->value(); }
    string weight() { return rp_weight->value(); }
    string cost() { return rp_cost->value(); }
    string description() { return rp_description->value(); }
    
    
private:
    Fl_Window *dialog;
    Fl_Input *rp_name;
    Fl_Input *rp_part_number;
    Fl_Input *rp_weight;
    Fl_Input *rp_cost;
    Fl_Input *rp_description;
    Fl_Return_Button *rp_create;
    Fl_Button *rp_cancel;
    
  
};

class Arm_Dialog {
public:
    Arm_Dialog() {
        
        dialog = new Fl_Window(340, 270, "Arm");
        
        rp_name = new Fl_Input(120, 10, 210, 25, "Name:");
        rp_name->align(FL_ALIGN_LEFT);
        
        rp_part_number = new Fl_Input(120, 40, 210, 25, "Part Number:");
        rp_part_number->align(FL_ALIGN_LEFT);
        
        rp_weight = new Fl_Input(120, 70, 210, 25, "Weight:");
        rp_weight->align(FL_ALIGN_LEFT);
        
        rp_cost = new Fl_Input(120, 100, 210, 25, "Cost:");
        rp_cost->align(FL_ALIGN_LEFT);
        
        rp_power = new Fl_Input(120, 130, 210, 25, "Power:");
        rp_power->align(FL_ALIGN_LEFT);
        
        rp_description = new Fl_Multiline_Input(120, 160, 210, 75, "Description:");
        rp_description->align(FL_ALIGN_LEFT);
        
        rp_create = new Fl_Return_Button(145, 240, 120, 25, "Create");
        rp_create->callback((Fl_Callback *)create_armCB, 0);
        
        rp_cancel = new Fl_Button(270, 240, 60, 25, "Cancel");
        rp_cancel->callback((Fl_Callback *)cancel_armCB, 0);
        
        dialog->end();
        dialog->set_non_modal();
    }
    
    void show() { dialog->show(); }
    void hide() { dialog->hide(); }
    void redraw() { dialog->redraw(); }
    string name() {return rp_name->value();}
    string part_number() { return rp_part_number->value(); }
    string weight() { return rp_weight->value(); }
    string cost() { return rp_cost->value(); }
    string power() { return rp_power->value(); }
    string description() { return rp_description->value();}

    
private:
    Fl_Window *dialog;
    Fl_Input *rp_name;
    Fl_Input *rp_part_number;
    Fl_Input *rp_weight;
    Fl_Input *rp_cost;
    Fl_Input *rp_description;
    Fl_Return_Button *rp_create;
    Fl_Button *rp_cancel;
    

    Fl_Input *rp_power;
};

class Battery_Dialog {
public:
    Battery_Dialog() {
        
        dialog = new Fl_Window(340, 270, "Battery");
       
        rp_name = new Fl_Input(120, 10, 210, 25, "Name:");
        rp_name->align(FL_ALIGN_LEFT);
        
        rp_part_number = new Fl_Input(120, 40, 210, 25, "Part Number:");
        rp_part_number->align(FL_ALIGN_LEFT);
        
        
        rp_weight = new Fl_Input(120, 70, 210, 25, "Weight:");
        rp_weight->align(FL_ALIGN_LEFT);
        
        rp_cost = new Fl_Input(120, 100, 210, 25, "Cost:");
        rp_cost->align(FL_ALIGN_LEFT);
        
        rp_energy = new Fl_Input(120, 130, 210, 25, "Energy:");
        rp_energy->align(FL_ALIGN_LEFT);
        
        rp_description = new Fl_Multiline_Input(120, 160, 210, 75, "Description:");
        rp_description->align(FL_ALIGN_LEFT);
        
        rp_create = new Fl_Return_Button(145, 240, 120, 25, "Create");
        rp_create->callback((Fl_Callback *)create_batteryCB, 0);
        
        rp_cancel = new Fl_Button(270, 240, 60, 25, "Cancel");
        rp_cancel->callback((Fl_Callback *)cancel_batteryCB, 0);
        
        dialog->end();
        dialog->set_non_modal();
    }
    
    void show() { dialog->show(); }
    void hide() { dialog->hide(); }
    string name() {return rp_name->value();}
    string part_number() { return rp_part_number->value(); }
    string weight() { return rp_weight->value(); }
    string cost() { return rp_cost->value(); }
    string description() { return rp_description->value(); }
    string energy() { return rp_energy->value(); }
    
private:
    Fl_Window *dialog;
    Fl_Input *rp_name;
    Fl_Input *rp_part_number;
    Fl_Input *rp_weight;
    Fl_Input *rp_cost;
    Fl_Input *rp_description;
    Fl_Return_Button *rp_create;
    Fl_Button *rp_cancel;
    
    Fl_Input *rp_energy;
};

class Locomotor_Dialog {
public:
    Locomotor_Dialog() {
        
        
        dialog = new Fl_Window(340, 300, "Locomotor");
        
        rp_name = new Fl_Input(120, 10, 210, 25, "Name:");
        rp_name->align(FL_ALIGN_LEFT);
        
        rp_part_number = new Fl_Input(120, 40, 210, 25, "Part Number:");
        rp_part_number->align(FL_ALIGN_LEFT);
        
        
        rp_weight = new Fl_Input(120, 70, 210, 25, "Weight:");
        rp_weight->align(FL_ALIGN_LEFT);
        
        rp_cost = new Fl_Input(120, 100, 210, 25, "Cost:");
        rp_cost->align(FL_ALIGN_LEFT);
        
        rp_power = new Fl_Input(120, 130, 210, 25, "Power:");
        rp_power->align(FL_ALIGN_LEFT);
        
        rp_speed = new Fl_Input(120, 160, 210, 25, "Maximum Speed:");
        rp_speed->align(FL_ALIGN_LEFT);
        
        rp_description = new Fl_Multiline_Input(120, 190, 210, 75, "Description:");
        rp_description->align(FL_ALIGN_LEFT);
        
        rp_create = new Fl_Return_Button(145, 270, 120, 25, "Create");
        rp_create->callback((Fl_Callback *)create_locomotorCB, 0);
        
        rp_cancel = new Fl_Button(270, 270, 60, 25, "Cancel");
        rp_cancel->callback((Fl_Callback *)cancel_locomotorCB, 0);
        
        dialog->end();
        dialog->set_non_modal();
    }
    
    void show() { dialog->show(); }
    void hide() { dialog->hide(); }
	string name() {return rp_name ->value(); }
	string description () {return rp_name-> value(); }
    string part_number() { return rp_part_number->value(); }
    string weight() { return rp_weight->value(); }
    string cost() { return rp_cost->value(); }
    string power() { return rp_power->value(); }
    string speed() { return rp_speed->value(); }
    
    
private:
    Fl_Window *dialog;
    Fl_Input *rp_name;
    Fl_Input *rp_part_number;
    Fl_Input *rp_weight;
    Fl_Input *rp_cost;
    Fl_Input *rp_description;
    Fl_Return_Button *rp_create;
    Fl_Button *rp_cancel;
    
   
    Fl_Input *rp_power;
    Fl_Input *rp_speed;
};

class Torso_Dialog {
public:
    Torso_Dialog() {
        
        dialog = new Fl_Window(340, 270, "Torso");
        
        rp_name = new Fl_Input(120, 10, 210, 25, "Name:");
        rp_name->align(FL_ALIGN_LEFT);
        
        
        rp_part_number = new Fl_Input(120, 40, 210, 25, "Part Number:");
        rp_part_number->align(FL_ALIGN_LEFT);
        
    
        rp_weight = new Fl_Input(120, 70, 210, 25, "Weight:");
        rp_weight->align(FL_ALIGN_LEFT);
        
        rp_cost = new Fl_Input(120, 100, 210, 25, "Cost:");
        rp_cost->align(FL_ALIGN_LEFT);
        
        rp_batt_count = new Fl_Input(120, 130, 210, 25, "Battery Count:");
        rp_batt_count->align(FL_ALIGN_LEFT);
        
        rp_description = new Fl_Multiline_Input(120, 160, 210, 75, "Description:");
        rp_description->align(FL_ALIGN_LEFT);
        
        rp_create = new Fl_Return_Button(145, 240, 120, 25, "Create");
        rp_create->callback((Fl_Callback *)create_torsoCB, 0);
        
        rp_cancel = new Fl_Button(270, 240, 60, 25, "Cancel");
        rp_cancel->callback((Fl_Callback *)cancel_torsoCB, 0);
        
        dialog->end();
        dialog->set_non_modal();
    }
    
    void show() { dialog->show(); }
    void hide() { dialog->hide(); }
    string name() { return rp_name -> value();}
    string part_number() { return rp_part_number->value(); }
    string weight() { return rp_weight->value(); }
    string cost() { return rp_cost->value(); }
    string description() { return rp_description->value(); }
    string batt_count() { return rp_batt_count->value(); }
   
    
private:
    Fl_Window *dialog;
    Fl_Input *rp_name;
    Fl_Input *rp_part_number;
    Fl_Input *rp_weight;
    Fl_Input *rp_cost;
    Fl_Input *rp_description;
    Fl_Return_Button *rp_create;
    Fl_Button *rp_cancel;
    
    Fl_Input *rp_batt_count;
};











class Customer_Dialog {
public:
    Customer_Dialog() {
        
        dialog = new Fl_Window(340, 270, "Customer");
        
        bc_name = new Fl_Input(120, 10, 210, 25, "Name:");
        bc_name->align(FL_ALIGN_LEFT);
        
        bc_number = new Fl_Input(120, 40, 210, 25, "ID Number:");
        bc_number->align(FL_ALIGN_LEFT);
        
        bc_phonenumber = new Fl_Input(120, 70, 210, 25, "Phone:");
        bc_phonenumber->align(FL_ALIGN_LEFT);
        
        bc_emailaddress = new Fl_Input(120, 100, 210, 25, "Email:");
        bc_emailaddress->align(FL_ALIGN_LEFT);
        
        rp_create = new Fl_Return_Button(145, 240, 120, 25, "Create");
        rp_create->callback((Fl_Callback *)create_customerCB, 0);
        
        rp_cancel = new Fl_Button(270, 240, 60, 25, "Cancel");
        rp_cancel->callback((Fl_Callback *)cancel_customerCB, 0);
        
        dialog->end();
        dialog->set_non_modal();
    }
    
    void show() {dialog->show();}
    void hide() {dialog->hide();}
    string name() {return bc_name->value();}
   
    string number() {return bc_number->value();}
    

    Fl_Window *dialog;
    Fl_Input *bc_name;
    Fl_Input *bc_number;
    Fl_Input *bc_phonenumber;
    Fl_Input *bc_emailaddress;
    
    Fl_Return_Button *rp_create;
    Fl_Button *rp_cancel;
};



class View_Customer_Dialog{
public:
    View_Customer_Dialog(){
        Fl::check();
        dialog = new Fl_Window(700, 200, "Report All Customers");
        
        customer_browser= new Fl_Browser(80, 30, 600, 100, "Customers");
       customer_browser->align(FL_ALIGN_LEFT);
        
        md_create = new Fl_Button(450, 150, 120, 25, "Exit");
        md_create->callback((Fl_Callback *) cancel_view_customerCB, 0);
    
        
        dialog->end();
        dialog->set_non_modal();
    }
    
    void show() { dialog->show(); }
    void hide() { dialog->hide(); }
    

    Fl_Window *dialog;
    Fl_Browser *customer_browser;
    Fl_Button *md_create;
    

};



//Class Creating Sales Associate
class Sales_Dialog
{
public:
    Sales_Dialog()
    {
        
        dialog = new Fl_Window(340, 270, "Sales Associate");
        
        s_name = new Fl_Input(120, 10, 210, 25, "Name:");
        s_name->align(FL_ALIGN_LEFT);
        
        s_number = new Fl_Input(120, 40, 210, 25, "ID Number:");
        s_number->align(FL_ALIGN_LEFT);
        
        rp_create = new Fl_Return_Button(145, 240, 120, 25, "Create");
        rp_create->callback((Fl_Callback *)create_salesCB, 0);
        
        rp_cancel = new Fl_Button(270, 240, 60, 25, "Cancel");
        rp_cancel->callback((Fl_Callback *)cancel_salesCB, 0);
        
        dialog->end();
        dialog->set_non_modal();
    }
    
    void show() {dialog->show();}
    void hide() {dialog->hide();}
    string name() {return s_name->value();}
    string number() {return s_number->value();}
    
private:
    Fl_Window *dialog;
    Fl_Input *s_name;
    Fl_Input *s_number;

    
    Fl_Return_Button *rp_create;
    Fl_Button *rp_cancel;
};



        
        
        
        
        
        
        
class View_Sales_Dialog{
public:
    View_Sales_Dialog(){
        
        dialog= new Fl_Window(340, 310, "Models");
        
        
        view = new Fl_Browser(10,10,320,250);
        view->type(FL_MULTI_BROWSER);
        view->align(FL_ALIGN_LEFT);
        
        exit = new Fl_Button(270,270,60,25, "Exit");
        exit ->callback((Fl_Callback *)cancel_view_salesCB, 0);
        
    }
    
    void show(){dialog->show();}
    void hide(){dialog->hide();}
    
    
    
    Fl_Window *dialog;
    Fl_Browser *view;
    Fl_Button *exit;
    
    
    
};

class Create_Order_Dialog {
public:
    Create_Order_Dialog() {
        dialog = new Fl_Window(340, 350, "Create Order");
        
        co_number = new Fl_Input(120, 10, 210, 25, "Order Number:");
        co_number->align(FL_ALIGN_LEFT);
        
        co_date = new Fl_Input(120, 40, 210, 25, "Date of Sale:");
        co_date->align(FL_ALIGN_LEFT);
        
        co_model = new Fl_Browser(120, 70, 210, 75, "Model:");
        co_model->type(FL_MULTI_BROWSER);
        co_model->align(FL_ALIGN_LEFT);
        
        co_customer = new Fl_Browser(120, 150, 210, 75, "Customer:");
        co_customer->type(FL_MULTI_BROWSER);
        co_customer->align(FL_ALIGN_LEFT);
        
        co_associate = new Fl_Browser(120, 230, 210, 75, "Sales Associate:");
        co_associate->type(FL_MULTI_BROWSER);
        co_associate->align(FL_ALIGN_LEFT);
        
        co_create = new Fl_Return_Button(145, 310, 120, 25, "Create");
        co_create->callback((Fl_Callback *)create_orderCB, 0);
        
        co_cancel = new Fl_Button(270, 310, 60, 25, "Cancel");
        co_cancel->callback((Fl_Callback *)cancel_orderCB, 0);
        
        dialog->resizable(dialog);
        dialog->set_non_modal();
    }
    
    void show() {dialog->show();}
    void hide() {dialog->hide();}
    string number() {return co_number->value();}
    string date() {return co_date->value();}
    int model() {return co_model->value();}
    int customer() {return co_customer->value();}
    int associate() {return co_associate->value();}
    
    
    Fl_Window *dialog;
    Fl_Input *co_number;
    Fl_Input *co_date;
    Fl_Browser *co_model;
    Fl_Browser *co_customer;
    Fl_Browser *co_associate;
    Fl_Return_Button *co_create;
    Fl_Button *co_cancel;
};

class View_Order_Dialog {
public:
    View_Order_Dialog() {
        dialog = new Fl_Window(340, 310, "View Orders");
        
        order = new Fl_Browser(10, 10, 320, 250);
        order->type(FL_MULTI_BROWSER);
        order->align(FL_ALIGN_LEFT);
        
        exit = new Fl_Button(270, 270, 60, 25, "Exit");
        exit->callback((Fl_Callback *)cancel_view_orderCB, 0);
        
        dialog->end();
        dialog->set_non_modal();
    }
    
    void show() {dialog->show();}
    void hide() {dialog->hide();}
    
    
    Fl_Window *dialog;
    Fl_Browser *order;
    Fl_Button *exit;
};







//
// Callbacks
//
void CB(Fl_Widget* w, void* p) { } // No action


void menu_create_headCB(Fl_Widget* w, void* p) {
    head_dlg->show();
}
void menu_create_armCB(Fl_Widget* w, void* p) {
    arm_dlg->show();
}
void menu_create_batteryCB(Fl_Widget* w, void* p) {
    battery_dlg->show();
}
void menu_create_locomotorCB(Fl_Widget* w, void* p) {
    locomotor_dlg->show();
}
void menu_create_torsoCB(Fl_Widget* w, void* p) {
    torso_dlg->show();
}

void menu_create_customerCB(Fl_Widget *w, void* p)
{
    customer_dlg->show();
}

void menu_create_salesCB(Fl_Widget *w, void* p)
{
    sales_dlg->show();
}

void menu_create_view_modelCB(Fl_Widget *w, void* p)
{
    
    for(int i=0; i<shop.models().size(); i++)
    {
        string model;
        
        model += shop.models()[i].name() +", "+shop.models()[i].part_number()+", "+to_string(shop.models()[i].price());
        
        view_model_dlg->view->add(model.c_str());
        
    }
    view_model_dlg->show();
}

void menu_create_view_customerCB(Fl_Widget *w, void* p)
{
    
    
    for(int i=0; i<shop.customers().size(); i++)
    {
        string model;
        
        model += shop.customers()[i].name() +", "+shop.customers()[i].customer_number();
        
        view_customer_dlg->customer_browser->add(model.c_str());
        
    }
    view_customer_dlg->show();
}

void menu_create_view_salesCB(Fl_Widget *w, void* p)
{
    
    
    
    for(int i=0; i<shop.sales_associates().size(); i++)
    {
        string model;
        
        model += shop.sales_associates()[i].name() +", "+shop.sales_associates()[i].employee_number();
        
        view_sales_dlg->view->add(model.c_str());
        
    }
    view_sales_dlg->show();
}





// Robot Model callback
//
void menu_create_modelCB(Fl_Widget* w, void* p) { //For loop for each of the browser arrays
    
    model_dlg->rp_arm->clear();
    model_dlg->rp_head->clear();
    model_dlg->rp_battery->clear();
    model_dlg->rp_locomotor->clear();
    model_dlg->rp_torso->clear();
    
    for(int i = 0; i < shop.arms().size(); ++i) {
        string arm_string;
        arm_string += shop.arms()[i].name()
        + ", "
        + shop.arms()[i].part_number()
        + ", "
        + to_string(shop.arms()[i].weight())
        + "lbs, $"
        + to_string(shop.arms()[i].cost());
        
        model_dlg->rp_arm->add(arm_string.c_str());
    }
    
    for(int i = 0; i < shop.batteries().size(); ++i) {
        string battery_string;
        battery_string += shop.batteries()[i].name()
        + ", "
        + shop.batteries()[i].part_number()
        + ", "
        + to_string(shop.batteries()[i].weight())
        + "lbs, $"
        + to_string(shop.batteries()[i].cost());
        model_dlg->rp_battery->add(battery_string.c_str());
    }
    
    for(int i = 0; i < shop.heads().size(); ++i) {
        string head_string;
        head_string += shop.heads()[i].name()
        + ", "
        + shop.heads()[i].part_number()
        + ", "
        + to_string(shop.heads()[i].weight())
        + "lbs, $"
        + to_string(shop.heads()[i].cost());
        model_dlg->rp_head->add(head_string.c_str());
    }
    
    for(int i = 0; i < shop.locomotors().size(); ++i) { // Locomotor browser population
        string locomotor_string;
        locomotor_string += shop.locomotors()[i].name()
        + ", "
        + shop.locomotors()[i].part_number()
        + ", "
        + to_string(shop.locomotors()[i].weight())
        + "lbs, $"
        + to_string(shop.locomotors()[i].cost());
        model_dlg->rp_locomotor->add(locomotor_string.c_str());
    }
    
    for(int i = 0; i < shop.torsos().size(); ++i) { // Torso browser population
        string torso_string;
        torso_string += shop.torsos()[i].name()
        + ", "
        + shop.torsos()[i].part_number()
        + ", "
        + to_string(shop.torsos()[i].weight())
        + "lbs, $"
        + to_string(shop.torsos()[i].cost());
        model_dlg->rp_torso->add(torso_string.c_str());
    }
    
    model_dlg->show();
}

void create_modelCB(Fl_Widget* w, void* p) {
    
    shop.create_model(
                      model_dlg->name(),
                      model_dlg->part_number(),
                      stod(model_dlg->cost()),
                      shop.torsos()[model_dlg->torso()],
                      shop.heads()[model_dlg->head()],
                      shop.arms()[model_dlg->arm()],
                      shop.arms()[model_dlg->arm()],
                      shop.locomotors()[model_dlg->locomotor()],
                      shop.batteries()[model_dlg->battery()],
                      shop.batteries()[model_dlg->battery()],
                      shop.batteries()[model_dlg->battery()]
                      );
    
    model_dlg->hide();
}


void menu_view_orderCB(Fl_Widget* w, void* p) {
    view_order_dlg->order->clear();
    for (int i = 0; i < shop.orders().size(); ++i) {
        string order_string;
        order_string += shop.orders()[i].order_number()
        + ", "
        + shop.orders()[i].date_of_sale();
        
        view_order_dlg->order->add(order_string.c_str());
    }
    
    
    
    view_order_dlg->show();
}


void cancel_view_orderCB(Fl_Widget* w, void* p) {
    view_order_dlg->hide();
}











void create_armCB(Fl_Widget* w, void* p) { // Replace with call to model!
	
    shop.create_arm(arm_dlg->name(), arm_dlg->part_number(), stod(arm_dlg->weight()), stod(arm_dlg->cost()), stoi(arm_dlg->power()), arm_dlg->description());
    
    
    arm_dlg->hide();
    

}

void create_headCB(Fl_Widget* w, void* p) { // Replace with call to model!
    
    shop.create_head(head_dlg->name(), head_dlg->part_number(), stod(head_dlg->weight()), stod(head_dlg->cost()), head_dlg->description());
    
    head_dlg->hide();
    
}

void create_batteryCB(Fl_Widget* w, void* p) { // Replace with call to model!
    
    shop.create_battery(battery_dlg->name(), battery_dlg->part_number(), stod(battery_dlg->weight()), stod(battery_dlg->cost()), stoi(battery_dlg->energy()), battery_dlg->description());

    
    battery_dlg->hide();
    
}

void create_locomotorCB(Fl_Widget* w, void* p) { // Replace with call to model!
    
    shop.create_locomotor(locomotor_dlg->name(), locomotor_dlg->part_number(), stod(locomotor_dlg->weight()), stod(locomotor_dlg->cost()), stoi(locomotor_dlg->power()), stod(locomotor_dlg->speed()),locomotor_dlg->description());
    
    
    locomotor_dlg->hide();
    
}

    
void create_torsoCB(Fl_Widget* w, void* p) { // Replace with call to model!
    
    
    shop.create_torso(torso_dlg->name(), torso_dlg->part_number(), stod(torso_dlg->weight()),stod(torso_dlg->cost()), stoi(torso_dlg->batt_count()), torso_dlg->description());
    
    
    torso_dlg->hide();
    
}


void menu_create_orderCB(Fl_Widget* w, void* p) { //For loop for each of the browser arrays
    
    create_order_dlg->co_model->clear();
    create_order_dlg->co_customer->clear();
    create_order_dlg->co_associate->clear();
    
    for(int i = 0; i < shop.models().size(); ++i) { // Model browser population
        string model_string;
        model_string += shop.models()[i].name()
        + ", $"
        + to_string(shop.models()[i].price());
        
        create_order_dlg->co_model->add(model_string.c_str());
    }
    
    for(int i = 0; i < shop.customers().size(); ++i) { // Customers browser population
        string customer_string;
        customer_string += shop.customers()[i].name()
        + ", "
        + shop.customers()[i].customer_number();
        
        create_order_dlg->co_customer->add(customer_string.c_str());
    }
    
    for(int i = 0; i < shop.sales_associates().size(); ++i) { // Sales Associates browser population
        string associates_string;
        associates_string += shop.sales_associates()[i].name()
        + ", "
        + shop.sales_associates()[i].employee_number();
        
        create_order_dlg->co_associate->add(associates_string.c_str());
    }
    
    create_order_dlg->show();
}


void create_orderCB(Fl_Widget* w, void* p) {
    shop.create_order(
                      create_order_dlg->number(),
                      create_order_dlg->date(),
                      shop.models()[create_order_dlg->model()],
                      shop.customers()[create_order_dlg->customer()],
                      shop.sales_associates()[create_order_dlg->associate()]
                      );
    
    create_order_dlg->hide();
}


//Cancel Functions

void cancel_armCB(Fl_Widget* w, void* p)
{
    arm_dlg->hide();
}
void cancel_torsoCB(Fl_Widget* w, void* p)
{
    torso_dlg->hide();
}
void cancel_locomotorCB(Fl_Widget* w, void* p)
{
    locomotor_dlg->hide();
}
void cancel_batteryCB(Fl_Widget* w, void* p)
{
    battery_dlg->hide();
}
void cancel_headCB(Fl_Widget* w, void* p)
{
    head_dlg->hide();
}
void cancel_orderCB(Fl_Widget* w, void* p) {
    create_order_dlg->hide();
}



//Create and Cancel Customer and Sales Associates Callback
void create_customerCB(Fl_Widget* w, void* p)
{
    cout << "### Creating Customer part" << endl;
    cout << "Name : " << customer_dlg->name()<<endl;
    cout << "ID # : " << customer_dlg->number() << endl;

    shop.create_customer(customer_dlg->name(), customer_dlg->number());
    
    customer_dlg->bc_name->cut();
    customer_dlg->bc_number->cut();
    customer_dlg->hide();
}

void cancel_customerCB(Fl_Widget* w, void* p)
{
    customer_dlg->hide();
}

void create_salesCB(Fl_Widget* w, void* p)
{
    cout << "### Creating Sales part" << endl;
    cout << "Name : " << sales_dlg->name()<<endl;
    cout << "ID # : " << sales_dlg->number() << endl;
    
    
    shop.create_sales_associate(sales_dlg->name(), sales_dlg->number());
    
    sales_dlg->hide();
}

void cancel_salesCB(Fl_Widget* w, void* p)
{
    sales_dlg->hide();
}

void cancel_modelCB(Fl_Widget* w, void* p)
{
    model_dlg->hide();
}

void cancel_view_modelCB(Fl_Widget* w, void* p)
{
    view_model_dlg->hide();
}
void cancel_view_customerCB(Fl_Widget* w, void* p)
{
    view_customer_dlg->hide();
}
void cancel_view_salesCB(Fl_Widget* w, void* p)
{
    view_sales_dlg->hide();
}
void menu_create_quitCB(Fl_Widget* w, void* p)
{
    win->hide();
}







Fl_Menu_Item menuitems[] = {
    { "&File", 0, 0, 0, FL_SUBMENU },
    { "&Quit", FL_ALT + 'q', (Fl_Callback *)menu_create_quitCB},
    { 0 },
    { "&Create", 0, 0, 0, FL_SUBMENU },
    { "Order", 0, (Fl_Callback *)menu_create_orderCB},
    { "Customer", 0, (Fl_Callback *)menu_create_customerCB},
    { "Sales Associate", 0, (Fl_Callback *)menu_create_salesCB},
    { "Robot Part", 0, 0, 0, FL_SUBMENU },
    { "Battery", 0, (Fl_Callback *)menu_create_batteryCB},
    { "Head",0,(Fl_Callback *)menu_create_headCB},
    { "Arm",0,(Fl_Callback *)menu_create_armCB},
    { "Torso",0,(Fl_Callback *)menu_create_torsoCB},
    { "Locomotor",0,(Fl_Callback *)menu_create_locomotorCB},
    { 0 },
    { "Robot Model", 0, (Fl_Callback *)menu_create_modelCB},
    { 0 },
    { "&Report", 0, 0, 0, FL_SUBMENU },
    { "All Orders", 0, (Fl_Callback *)menu_view_orderCB},
    { "All Customers", 0, (Fl_Callback *)menu_create_view_customerCB},
    { "All Sales Associates", 0, (Fl_Callback *)menu_create_view_salesCB},
    { "All Robot Models", 0, (Fl_Callback *)menu_create_view_modelCB},
    { 0 },
    { "&Help", 0, 0, 0, FL_SUBMENU },
    { "&Manual", 0, (Fl_Callback *)CB},
    { "&About", 0, (Fl_Callback *)CB},
    { 0 },
    { 0 }
};


int main() {
    
    const int X= 1000;
    const int Y= 600;
   // const int border = 10;
    
	

    
    //Create dialogs
   
    arm_dlg = new Arm_Dialog;
    head_dlg = new Head_Dialog;
    locomotor_dlg = new Locomotor_Dialog;
    torso_dlg = new Torso_Dialog;
    battery_dlg = new Battery_Dialog;
    customer_dlg = new Customer_Dialog;
    sales_dlg = new Sales_Dialog;
    model_dlg =new Model_Dialog;
    view_model_dlg =new View_Model_Dialog;
    view_customer_dlg = new View_Customer_Dialog;
    view_sales_dlg = new View_Sales_Dialog;
    create_order_dlg = new Create_Order_Dialog;
    view_order_dlg = new View_Order_Dialog;
    
    
    //Create a Window
   win = new Fl_Window(X,Y, "Robot Shop Manager");

    
    
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

    
    
    
    //Install Menubar
    menubar = new Fl_Menu_Bar(0,0,X,30);
    menubar->menu(menuitems);
    
    
    win->end();
    win->show();
    return(Fl::run());
    
 
    
}
