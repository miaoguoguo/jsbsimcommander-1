/////////////////////////////////////////////////////////////////////////////
// Name:        Function_Diag.h
// Purpose:     Manager of the Function item
// Author:      Matthew Gong
// Created:     05/08/2005
// Copyright:   (c) Matthew Gong
// Licence:     GPL licence
/////////////////////////////////////////////////////////////////////////////

#if defined(__GNUG__) && !defined(__APPLE__)
// #pragma interface
#endif

// -*- C++ -*- generated by wxGlade 0.3.5.1 on Sat May  7 21:20:49 2005

#include <wx/wx.h>
#include <wx/image.h>
// begin wxGlade: ::dependencies
// end wxGlade


#ifndef FUNCTION_DIAG_H
#define FUNCTION_DIAG_H

class TreeItemData_function;
class FunctionDialog: public wxDialog {
public:
    // begin wxGlade: FunctionDialog::ids
      enum {
        ID_FUNC_TYPE = 11000
      };
    // end wxGlade

    FunctionDialog(wxWindow* parent, int id, const wxString& title=_("Function or Operator"), const wxPoint& pos=wxDefaultPosition, const wxSize& size=wxSize(480, 210), long style=wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER);
    void Load(const TreeItemData_function * func);
    void Save(TreeItemData_function * func);

private:
    // begin wxGlade: FunctionDialog::methods
    void set_properties();
    void do_layout();
    // end wxGlade

protected:
    // begin wxGlade: FunctionDialog::attributes
    wxStaticText* label_type;
    wxComboBox* combo_box_type;
    wxStaticText* label_name;
    wxTextCtrl* text_ctrl_name;
    wxStaticText* label_dscp;
    wxTextCtrl* text_ctrl_dscp;
    wxButton* button_ok;
    wxButton* button_cancel;
    // end wxGlade

    void OnSelectType(wxCommandEvent & event);

    DECLARE_EVENT_TABLE() 
};


#endif // FUNCTION_DIAG_H
