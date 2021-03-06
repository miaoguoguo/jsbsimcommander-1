/////////////////////////////////////////////////////////////////////////////
// Name:        pid_dlg.cpp
// Purpose:     dialog for FGPID
// Author:      Jon Berndt
// Created:     07/02/2006
// Copyright:   (c) Jon Berndt
// Licence:     GPL licence
//
// Functions:
//
// do_layout
// GetDataIn
// OnButtonPressCancel
// OnButtonPressHelp
// OnButtonPressOK
// OnButtonPressTrigger
// OnCheckboxClip
// OnButtonPressCancel
// OnButtonPressHelp
// OnClickInvertInput
// PIDPropertyDialog - Constructor
// set_properties
// SetDataOut
// Show
//
/////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
// #pragma implementation
#endif

// For compilers that support precompilation, includes "wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include <wx/valtext.h>
#include <wx/valgen.h>

#include "shape.h"
#include "pid.h"
#include "pid_dlg.h"
#include "Property_Diag.h"
#include "MyApp.h"

// All non-MSW platforms use an xpm. MSW uses an .ico file
#if defined(__WXGTK__) || defined(__WXX11__) || defined(__WXMOTIF__) || defined(__WXMAC__) || defined(__WXMGL__)
    #include "pid.xpm"
#endif

/**
* Event Table ==================================================================
*/

BEGIN_EVENT_TABLE(PIDPropertyDialog, wxDialog)
    // begin wxGlade: PIDPropertyDialog::event_table
    EVT_CHECKBOX(-1, PIDPropertyDialog::OnCheckboxClip)
    EVT_TOGGLEBUTTON(-1, PIDPropertyDialog::OnClickInvertInput)
    EVT_BUTTON(wxID_OK, PIDPropertyDialog::OnButtonPressOK)
    EVT_BUTTON(10, PIDPropertyDialog::OnButtonPressTrigger)
    EVT_BUTTON(wxID_CANCEL, PIDPropertyDialog::OnButtonPressCancel)
    EVT_BUTTON(-1, PIDPropertyDialog::OnButtonPressHelp)
    // end wxGlade
END_EVENT_TABLE();

/**
* Constructor ==================================================================
*/

PIDPropertyDialog::PIDPropertyDialog(PID * pid, wxWindow* parent, int id, const wxString& title, const wxPoint& pos, const wxSize& size, long style):
    wxDialog(parent, id, title, pos, size, wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER|wxTHICK_FRAME)
{
    // begin wxGlade: PIDPropertyDialog::PIDPropertyDialog
    notebook_1 = new wxNotebook(this, -1, wxDefaultPosition, wxDefaultSize,wxWS_EX_VALIDATE_RECURSIVELY);
    notebook_1_pane_1 = new wxPanel(notebook_1, -1);
    panel_toplevel = new wxPanel(notebook_1_pane_1, -1, wxDefaultPosition, wxDefaultSize, wxRAISED_BORDER|wxTAB_TRAVERSAL);
    sizer_clip_staticbox = new wxStaticBox(panel_toplevel, -1, wxT("Clipping"));
    sizer_trigger_staticbox = new wxStaticBox(panel_toplevel, -1, wxT("Trigger property"));
    sizer_pid_top_staticbox = new wxStaticBox(panel_toplevel, -1, wxT("PID Control Characteristics"));
    sizer_inout_staticbox = new wxStaticBox(panel_toplevel, -1, wxT("Input / Output"));
    sizer_basic_staticbox = new wxStaticBox(panel_toplevel, -1, wxT("Basic Properties"));
    label_name = new wxStaticText(panel_toplevel, -1, wxT("Name:"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT);
    text_ctrl_name = new wxTextCtrl(panel_toplevel, -1, wxT(""), wxDefaultPosition, wxDefaultSize, 0, wxTextValidator(wxFILTER_NONE, &name));
    label_type = new wxStaticText(panel_toplevel, -1, wxT("Type:"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT);
    text_ctrl_type = new wxTextCtrl(panel_toplevel, -1, wxT("PID Control Component"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY);
    label_order = new wxStaticText(panel_toplevel, -1, wxT("Order:"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT);
    text_ctrl_order = new wxTextCtrl(panel_toplevel, -1, wxT(""), wxDefaultPosition, wxDefaultSize, 0, wxTextValidator(wxFILTER_NUMERIC, &order));
    checkbox_clip = new wxCheckBox(panel_toplevel, -1, wxT("Clip"), wxDefaultPosition, wxDefaultSize, 0, wxGenericValidator(&clipable));
    label_clip_min = new wxStaticText(panel_toplevel, -1, wxT("Minimum:"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT);
    text_ctrl_clip_min = new wxTextCtrl(panel_toplevel, -1, wxT(""), wxDefaultPosition, wxDefaultSize, 0, wxTextValidator(wxFILTER_NUMERIC, &clip_min));
    label_6 = new wxStaticText(panel_toplevel, -1, wxT(""));
    label_clip_max = new wxStaticText(panel_toplevel, -1, wxT("Maximum:"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT);
    text_ctrl_clip_max = new wxTextCtrl(panel_toplevel, -1, wxT(""), wxDefaultPosition, wxDefaultSize, 0, wxTextValidator(wxFILTER_NUMERIC, &clip_max));
    label_kp = new wxStaticText(panel_toplevel, -1, wxT("Kp:"));
    text_ctrl_kp = new wxTextCtrl(panel_toplevel, -1, wxT("0"), wxDefaultPosition, wxDefaultSize, 0, wxTextValidator(wxFILTER_NUMERIC, &kp));
    label_ki = new wxStaticText(panel_toplevel, -1, wxT("Ki:"));
    text_ctrl_ki = new wxTextCtrl(panel_toplevel, -1, wxT("0"), wxDefaultPosition, wxDefaultSize, 0, wxTextValidator(wxFILTER_NUMERIC, &ki));
    label_kd = new wxStaticText(panel_toplevel, -1, wxT("Kd:"));
    text_ctrl_kd = new wxTextCtrl(panel_toplevel, -1, wxT("0"), wxDefaultPosition, wxDefaultSize, 0, wxTextValidator(wxFILTER_NUMERIC, &kd));
    button_trigger = new wxButton(panel_toplevel, 10, wxT("Select Trigger"));
    text_ctrl_trigger_prop = new wxTextCtrl(panel_toplevel, -1, wxT(""), wxDefaultPosition, wxDefaultSize, wxTE_READONLY);
    label_1 = new wxStaticText(panel_toplevel, -1, wxT("Input Property:"));
    button_invert_input = new wxToggleButton(panel_toplevel, -1, wxT("+"));
    text_ctrl_input_prop = new wxTextCtrl(panel_toplevel, -1, wxT(""), wxDefaultPosition, wxDefaultSize, wxTE_READONLY);
    label_output_property = new wxStaticText(panel_toplevel, -1, wxT("Output Property:"));
    text_ctrl_output_prop = new wxTextCtrl(panel_toplevel, -1, wxT(""), wxDefaultPosition, wxDefaultSize, wxTE_READONLY);
    button_OK = new wxButton(this, wxID_OK, wxT("OK"));
    button_Cancel = new wxButton(this, wxID_CANCEL, wxT("Cancel"));
    button_Help = new wxButton(this, -1, wxT("Help"));
    text_ctrl_1 = new wxTextCtrl(notebook_1, -1, wxT(""), wxDefaultPosition, wxDefaultSize, 0, wxTextValidator(wxFILTER_NONE, &description));

    set_properties();
    do_layout();
    // end wxGlade

    GetDataIn(pid);
}

/**
*              ==================================================================
*/

void PIDPropertyDialog::OnCheckboxClip(wxCommandEvent &event)
{
  if ( checkbox_clip->IsChecked() ) {
    text_ctrl_clip_max->Enable(true);
    text_ctrl_clip_max->SetBackgroundColour(*wxWHITE);
    text_ctrl_clip_min->Enable(true);
    text_ctrl_clip_min->SetBackgroundColour(*wxWHITE);
  } else {
    text_ctrl_clip_max->Enable(false);
    text_ctrl_clip_max->SetBackgroundColour(wxSYS_COLOUR_INACTIVECAPTION);
    text_ctrl_clip_min->Enable(false);
    text_ctrl_clip_min->SetBackgroundColour(wxSYS_COLOUR_INACTIVECAPTION);
  }

  event.Skip();
}

/**
*              ==================================================================
*/

void PIDPropertyDialog::OnClickInvertInput(wxCommandEvent &event)
{
  if (button_invert_input->GetValue()) button_invert_input->SetLabel(wxT("-"));
  else button_invert_input->SetLabel(wxT("+"));

  event.Skip();
}

/**
*              ==================================================================
*/

void PIDPropertyDialog::OnButtonPressOK(wxCommandEvent &event)
{
  if (panel_toplevel->Validate())
    panel_toplevel->TransferDataFromWindow();

  event.Skip();
}

/**
*              ==================================================================
*/

void PIDPropertyDialog::OnButtonPressTrigger(wxCommandEvent &event)
{
  if (GetPropertyDialog()->ShowModal() == wxID_OK)
    text_ctrl_trigger_prop->SetValue(GetPropertyDialog()->GetResult());
}

/**
*              ==================================================================
*/

void PIDPropertyDialog::OnButtonPressCancel(wxCommandEvent &event)
{
    event.Skip();
}

/**
*              ==================================================================
*/

void PIDPropertyDialog::OnButtonPressHelp(wxCommandEvent &event)
{
    event.Skip();
}


/**
*              ==================================================================
*/

void PIDPropertyDialog::set_properties()
{
    // begin wxGlade: PIDPropertyDialog::set_properties
    SetTitle(wxT("PID Component Editor"));
    SetSize(wxSize(327, 533));
    wxIcon _icon;
    _icon.CopyFromBitmap(wxBITMAP(pid));
    SetIcon(_icon);
    text_ctrl_name->SetToolTip(wxT("This is the name of the component. It can be a property name, or a human readable name, such as \"Pitch Feedback PID Control\". In the latter case, the name will be converted internally to a property name. In the given example, this will be \"fcs/pitch-feedback-pid-control\"."));
    text_ctrl_name->SetFocus();
    text_ctrl_type->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    text_ctrl_order->SetToolTip(wxT("This number represents the order in which the component will be \"executed\"."));
    label_clip_min->SetMinSize(wxSize(60, -1));
    text_ctrl_clip_min->SetMinSize(wxSize(100,-1));
    text_ctrl_clip_min->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    text_ctrl_clip_min->SetToolTip(wxT("This is the minimum value allowed for the component output. "));
    label_clip_max->SetMinSize(wxSize(60, -1));
    text_ctrl_clip_max->SetMinSize(wxSize(100,-1));
    text_ctrl_clip_max->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    text_ctrl_clip_max->SetToolTip(wxT("This is the maximum value allowed for the component output. "));
    text_ctrl_kp->SetMinSize(wxSize(60, 21));
    text_ctrl_kp->SetToolTip(wxT("Proportional control value"));
    text_ctrl_ki->SetMinSize(wxSize(60, 21));
    text_ctrl_ki->SetToolTip(wxT("Integral control value"));
    text_ctrl_kd->SetMinSize(wxSize(60, -1));
    text_ctrl_kd->SetToolTip(wxT("Derivative control value"));
    button_trigger->SetToolTip(wxT("Clicking this button will bring up the property browser."));
    text_ctrl_trigger_prop->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    text_ctrl_trigger_prop->SetToolTip(wxT("This is the \"trigger\" property. If the value of the trigger property is non-zero, the input to the integrator will stop, to prevent integrator wind-up."));
    button_invert_input->SetMinSize(wxSize(21, 21));
    button_invert_input->SetToolTip(wxT("Depress this button to invert the input property."));
    button_invert_input->Enable(false);
    text_ctrl_input_prop->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    text_ctrl_input_prop->SetToolTip(wxT("This is the input property to the component. This is selected via connecting up the components in the editor."));
    text_ctrl_output_prop->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    text_ctrl_output_prop->SetToolTip(wxT("This is the output property to the component. This is selected via connecting up the components in the editor."));
    button_OK->SetToolTip(wxT("Clicking this button will save the changes made."));
    button_Cancel->SetToolTip(wxT("Clicking on the Cancel button will abandon changes made."));
    // end wxGlade
}

/**
*              ==================================================================
*/

void PIDPropertyDialog::do_layout()
{
    // begin wxGlade: PIDPropertyDialog::do_layout
    wxFlexGridSizer* grid_sizer_2 = new wxFlexGridSizer(2, 1, 5, 0);
    wxBoxSizer* sizer_buttons = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* sizer_1 = new wxBoxSizer(wxHORIZONTAL);
    wxFlexGridSizer* grid_sizer_top_interior = new wxFlexGridSizer(4, 1, 5, 0);
    wxStaticBoxSizer* sizer_inout = new wxStaticBoxSizer(sizer_inout_staticbox, wxHORIZONTAL);
    wxFlexGridSizer* grid_sizer_inout = new wxFlexGridSizer(2, 2, 5, 5);
    wxFlexGridSizer* grid_sizer_1 = new wxFlexGridSizer(1, 2, 0, 2);
    wxStaticBoxSizer* sizer_pid_top = new wxStaticBoxSizer(sizer_pid_top_staticbox, wxHORIZONTAL);
    wxBoxSizer* sizer_pid = new wxBoxSizer(wxVERTICAL);
    wxStaticBoxSizer* sizer_trigger = new wxStaticBoxSizer(sizer_trigger_staticbox, wxHORIZONTAL);
    wxFlexGridSizer* grid_sizer_trigger = new wxFlexGridSizer(1, 2, 0, 5);
    wxFlexGridSizer* grid_sizer_pid = new wxFlexGridSizer(3, 2, 5, 5);
    wxStaticBoxSizer* sizer_clip = new wxStaticBoxSizer(sizer_clip_staticbox, wxHORIZONTAL);
    wxFlexGridSizer* grid_sizer_clip = new wxFlexGridSizer(2, 2, 5, 10);
    wxBoxSizer* sizer_clip_max = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* sizer_clip_min = new wxBoxSizer(wxHORIZONTAL);
    wxStaticBoxSizer* sizer_basic = new wxStaticBoxSizer(sizer_basic_staticbox, wxHORIZONTAL);
    wxFlexGridSizer* grid_sizer_basic_interior = new wxFlexGridSizer(3, 2, 5, 5);
    grid_sizer_basic_interior->Add(label_name, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxADJUST_MINSIZE, 0);
    grid_sizer_basic_interior->Add(text_ctrl_name, 0, wxEXPAND|wxALIGN_CENTER_VERTICAL|wxADJUST_MINSIZE, 0);
    grid_sizer_basic_interior->Add(label_type, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxADJUST_MINSIZE, 0);
    grid_sizer_basic_interior->Add(text_ctrl_type, 0, wxEXPAND|wxALIGN_CENTER_VERTICAL|wxADJUST_MINSIZE, 0);
    grid_sizer_basic_interior->Add(label_order, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxADJUST_MINSIZE, 0);
    grid_sizer_basic_interior->Add(text_ctrl_order, 0, wxEXPAND|wxALIGN_CENTER_VERTICAL|wxFIXED_MINSIZE, 0);
    grid_sizer_basic_interior->AddGrowableCol(1);
    sizer_basic->Add(grid_sizer_basic_interior, 1, wxEXPAND, 0);
    grid_sizer_top_interior->Add(sizer_basic, 1, wxEXPAND, 0);
    grid_sizer_clip->Add(checkbox_clip, 0, wxALIGN_CENTER_VERTICAL|wxADJUST_MINSIZE, 0);
    sizer_clip_min->Add(label_clip_min, 0, wxRIGHT|wxALIGN_CENTER_VERTICAL, 5);
    sizer_clip_min->Add(text_ctrl_clip_min, 0, wxEXPAND|wxALIGN_CENTER_VERTICAL|wxFIXED_MINSIZE, 0);
    grid_sizer_clip->Add(sizer_clip_min, 1, wxEXPAND|wxALIGN_CENTER_VERTICAL, 0);
    grid_sizer_clip->Add(label_6, 0, wxADJUST_MINSIZE, 0);
    sizer_clip_max->Add(label_clip_max, 0, wxRIGHT|wxALIGN_CENTER_VERTICAL, 5);
    sizer_clip_max->Add(text_ctrl_clip_max, 0, wxEXPAND|wxALIGN_CENTER_VERTICAL|wxFIXED_MINSIZE, 0);
    grid_sizer_clip->Add(sizer_clip_max, 1, wxEXPAND|wxALIGN_CENTER_VERTICAL, 0);
    grid_sizer_clip->AddGrowableCol(1);
    sizer_clip->Add(grid_sizer_clip, 1, wxEXPAND, 0);
    grid_sizer_top_interior->Add(sizer_clip, 1, wxEXPAND, 0);
    grid_sizer_pid->Add(label_kp, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 0);
    grid_sizer_pid->Add(text_ctrl_kp, 0, wxADJUST_MINSIZE, 0);
    grid_sizer_pid->Add(label_ki, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxADJUST_MINSIZE, 0);
    grid_sizer_pid->Add(text_ctrl_ki, 0, wxADJUST_MINSIZE, 0);
    grid_sizer_pid->Add(label_kd, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxADJUST_MINSIZE, 0);
    grid_sizer_pid->Add(text_ctrl_kd, 0, wxADJUST_MINSIZE, 0);
    grid_sizer_pid->AddGrowableCol(1);
    sizer_pid->Add(grid_sizer_pid, 1, wxEXPAND, 0);
    grid_sizer_trigger->Add(button_trigger, 0, wxADJUST_MINSIZE, 0);
    grid_sizer_trigger->Add(text_ctrl_trigger_prop, 0, wxEXPAND|wxADJUST_MINSIZE, 0);
    grid_sizer_trigger->AddGrowableCol(1);
    sizer_trigger->Add(grid_sizer_trigger, 1, 0, 0);
    sizer_pid->Add(sizer_trigger, 1, wxTOP|wxEXPAND, 5);
    sizer_pid_top->Add(sizer_pid, 1, wxEXPAND, 0);
    grid_sizer_top_interior->Add(sizer_pid_top, 1, wxEXPAND, 0);
    grid_sizer_inout->Add(label_1, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxADJUST_MINSIZE, 0);
    grid_sizer_1->Add(button_invert_input, 0, wxADJUST_MINSIZE, 0);
    grid_sizer_1->Add(text_ctrl_input_prop, 0, wxEXPAND|wxADJUST_MINSIZE, 0);
    grid_sizer_1->AddGrowableCol(1);
    grid_sizer_inout->Add(grid_sizer_1, 1, wxEXPAND, 0);
    grid_sizer_inout->Add(label_output_property, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxADJUST_MINSIZE, 0);
    grid_sizer_inout->Add(text_ctrl_output_prop, 0, wxEXPAND|wxADJUST_MINSIZE, 0);
    grid_sizer_inout->AddGrowableCol(1);
    sizer_inout->Add(grid_sizer_inout, 1, wxEXPAND, 0);
    grid_sizer_top_interior->Add(sizer_inout, 1, wxEXPAND, 0);
    panel_toplevel->SetAutoLayout(true);
    panel_toplevel->SetSizer(grid_sizer_top_interior);
    grid_sizer_top_interior->Fit(panel_toplevel);
    grid_sizer_top_interior->SetSizeHints(panel_toplevel);
    grid_sizer_top_interior->AddGrowableRow(3);
    grid_sizer_top_interior->AddGrowableCol(0);
    sizer_1->Add(panel_toplevel, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    notebook_1_pane_1->SetAutoLayout(true);
    notebook_1_pane_1->SetSizer(sizer_1);
    sizer_1->Fit(notebook_1_pane_1);
    sizer_1->SetSizeHints(notebook_1_pane_1);
    notebook_1->AddPage(notebook_1_pane_1, wxT("Properties"));
    notebook_1->AddPage(text_ctrl_1, wxT("Comments"));
    grid_sizer_2->Add(notebook_1, 1, wxEXPAND, 0);
    sizer_buttons->Add(button_OK, 0, wxLEFT|wxRIGHT|wxADJUST_MINSIZE, 5);
    sizer_buttons->Add(button_Cancel, 0, wxLEFT|wxRIGHT, 5);
    sizer_buttons->Add(button_Help, 0, wxLEFT|wxRIGHT|wxADJUST_MINSIZE, 5);
    grid_sizer_2->Add(sizer_buttons, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxADJUST_MINSIZE, 5);
    SetAutoLayout(true);
    SetSizer(grid_sizer_2);
    grid_sizer_2->Fit(this);
    grid_sizer_2->SetSizeHints(this);
    grid_sizer_2->AddGrowableRow(0);
    grid_sizer_2->AddGrowableCol(0);
    Layout();
    Centre();
    // end wxGlade
}

/**
* Show =========================================================================
*/

bool PIDPropertyDialog::Show( bool show)
{
  bool tmp = wxDialog::Show(show);

  if (show) notebook_1->InitDialog();

  return tmp;
}

/**
* GetDataIn ====================================================================
*/

void PIDPropertyDialog::GetDataIn(PID * g)
{
  name     = g->GetName();
  description  = g->GetDescription();
  order    = wxString::Format(wxT("%ld"), g->GetOrder());
  clipable = g->IsClipable();
  clip_max = g->GetClipMax();
  clip_min = g->GetClipMin();

  kp = wxString::Format(wxT("%g"), g->GetKp());
  ki = wxString::Format(wxT("%g"), g->GetKi());
  kd = wxString::Format(wxT("%g"), g->GetKd());

  *text_ctrl_order << order;

  if (clipable) {
      text_ctrl_clip_max->Enable(true);
      text_ctrl_clip_max->SetBackgroundColour(*wxWHITE);
      text_ctrl_clip_min->Enable(true);
      text_ctrl_clip_min->SetBackgroundColour(*wxWHITE);
  } else {
      text_ctrl_clip_max->Enable(false);
      text_ctrl_clip_max->SetBackgroundColour(wxSYS_COLOUR_INACTIVECAPTION);
      text_ctrl_clip_min->Enable(false);
      text_ctrl_clip_min->SetBackgroundColour(wxSYS_COLOUR_INACTIVECAPTION);
  }

  wxArrayString inputs = g->GetInputNames();

  *text_ctrl_output_prop << g->GetOutputName();
  if (inputs.GetCount() > 0) {
    if (inputs[0] != wxT("NULL"))
    {
      button_invert_input->Enable();
      if (g->GetInputIsInverted()) {
        button_invert_input->SetValue(true);
        button_invert_input->SetLabel(wxT("-"));
      } else {
        button_invert_input->SetValue(false);
        button_invert_input->SetLabel(wxT("+"));
      }
    }
    *text_ctrl_input_prop << inputs[0];
  }
  *text_ctrl_trigger_prop << g->GetTrigger();
  *text_ctrl_1 << g->GetDescription();
}

/**
* SetDataOut ===================================================================
*/

void PIDPropertyDialog::SetDataOut(PID * g)
{
  g->SetName(name);
  g->SetDescription(description);

  long int tmpl;
  order.ToLong(&tmpl);
  g->SetOrder(tmpl);
  g->SetClipable(clipable);
  double tmpd;
  g->SetClipMax(clip_max);
  g->SetClipMin(clip_min);

  double tmp;
  kp.ToDouble(&tmp);
  g->SetKp(tmp);
  ki.ToDouble(&tmp);
  g->SetKi(tmp);
  kd.ToDouble(&tmp);
  g->SetKd(tmp);

  g->SetTrigger(text_ctrl_trigger_prop->GetValue());
  g->SetDescription(text_ctrl_1->GetValue());

  g->SetInputIsInverted(false);
  if (text_ctrl_input_prop->GetValue() != wxT("NULL")) // true if input prop is present
    if (button_invert_input->GetValue()) // true if inverted
      g->SetInputIsInverted(true);
}
