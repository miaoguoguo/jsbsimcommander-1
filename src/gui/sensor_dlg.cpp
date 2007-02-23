/////////////////////////////////////////////////////////////////////////////
// Name:        sensor_dlg.cpp
// Purpose:     dialog for FGSensor
// Author:      Jon Berndt
// Created:     07/19/2006
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
// OnCheckboxClip
// OnButtonPressCancel
// OnButtonPressHelp
// OnClickInvertInput
// SensorComponentEditor - Constructor
// set_properties
// SetDataOut
// Show
//
/////////////////////////////////////////////////////////////////////////////

// -*- C++ -*- generated by wxGlade 0.4.1 on Sat Jul 15 08:54:44 2006

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
#include "sensor.h"
#include "sensor_dlg.h"
#include "Property_Diag.h"
#include "MyApp.h"

// All non-MSW platforms use an xpm. MSW uses an .ico file
#if defined(__WXGTK__) || defined(__WXX11__) || defined(__WXMOTIF__) || defined(__WXMAC__) || defined(__WXMGL__)
    #include "pid.xpm"
#endif

SensorComponentEditor::SensorComponentEditor(Sensor *sensor, wxWindow* parent, int id, const wxString& title, const wxPoint& pos, const wxSize& size, long style):
    wxDialog(parent, id, title, pos, size, wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER|wxTHICK_FRAME|wxSTAY_ON_TOP|wxFULL_REPAINT_ON_RESIZE)
{
    // begin wxGlade: SensorComponentEditor::SensorComponentEditor
    notebook_1 = new wxNotebook(this, -1, wxDefaultPosition, wxDefaultSize, wxRAISED_BORDER|wxTAB_TRAVERSAL|wxWS_EX_VALIDATE_RECURSIVELY);
    notebook_1_pane_1 = new wxPanel(notebook_1, -1);
    sizer_clip_staticbox = new wxStaticBox(notebook_1_pane_1, -1, wxT("Clipping"));
    sizer_quantize_staticbox = new wxStaticBox(notebook_1_pane_1, -1, wxT("Quantization Characteristics"));
    sizer_sensor_staticbox = new wxStaticBox(notebook_1_pane_1, -1, wxT("Sensor Properties"));
    sizer_inout_staticbox = new wxStaticBox(notebook_1_pane_1, -1, wxT("Input / Output"));
    sizer_basic_staticbox = new wxStaticBox(notebook_1_pane_1, -1, wxT("Basic Properties"));
    label_name = new wxStaticText(notebook_1_pane_1, -1, wxT("Name:"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT);
    text_ctrl_name = new wxTextCtrl(notebook_1_pane_1, -1, wxT(""), wxDefaultPosition, wxDefaultSize, 0, wxTextValidator(wxFILTER_NONE, &name));
    label_type = new wxStaticText(notebook_1_pane_1, -1, wxT("Type:"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT);
    text_ctrl_type = new wxTextCtrl(notebook_1_pane_1, -1, wxT("Sensor Component"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY);
    label_order = new wxStaticText(notebook_1_pane_1, -1, wxT("Order:"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT);
    text_ctrl_order = new wxTextCtrl(notebook_1_pane_1, -1, wxT(""), wxDefaultPosition, wxDefaultSize, 0, wxTextValidator(wxFILTER_NUMERIC, &order));
    checkbox_clip = new wxCheckBox(notebook_1_pane_1, -1, wxT("Clip"));
    label_clip_min = new wxStaticText(notebook_1_pane_1, -1, wxT("Minimum:"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT);
    text_ctrl_clip_min = new wxTextCtrl(notebook_1_pane_1, -1, wxT(""), wxDefaultPosition, wxDefaultSize, wxTE_READONLY);
    label_clip_max = new wxStaticText(notebook_1_pane_1, -1, wxT("Maximum:"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT);
    text_ctrl_clip_max = new wxTextCtrl(notebook_1_pane_1, -1, wxT(""), wxDefaultPosition, wxDefaultSize, wxTE_READONLY);
    label_2 = new wxStaticText(notebook_1_pane_1, -1, wxT("First Order Lag"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT);
    text_ctrl_lag = new wxTextCtrl(notebook_1_pane_1, -1, wxT("0.0"));
    label_3 = new wxStaticText(notebook_1_pane_1, -1, wxT("Noise"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT);
    const wxString radio_box_noise_type_choices[] = {
        wxT("Absolute"),
        wxT("Percent")
    };
    radio_box_noise_type = new wxRadioBox(notebook_1_pane_1, -1, wxT("Noise Type"), wxDefaultPosition, wxDefaultSize, 2, radio_box_noise_type_choices, 2, wxRA_SPECIFY_COLS);
    label_4 = new wxStaticText(notebook_1_pane_1, -1, wxT("Noise Level (0 ... 1)"));
    text_ctrl_2 = new wxTextCtrl(notebook_1_pane_1, -1, wxT("0.0"));
    label_5 = new wxStaticText(notebook_1_pane_1, -1, wxT("Bias"));
    text_ctrl_4_1 = new wxTextCtrl(notebook_1_pane_1, -1, wxT("0.0"));
    label_7 = new wxStaticText(notebook_1_pane_1, -1, wxT("Drift Rate"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT);
    text_ctrl_4 = new wxTextCtrl(notebook_1_pane_1, -1, wxT("0.0"));
    label_8 = new wxStaticText(notebook_1_pane_1, -1, wxT("Quantization"));
    label_9 = new wxStaticText(notebook_1_pane_1, -1, wxT("Property:"));
    text_ctrl_5 = new wxTextCtrl(notebook_1_pane_1, -1, wxT(""));
    label_12 = new wxStaticText(notebook_1_pane_1, -1, wxT("First Order Lag:"));
    text_ctrl_8 = new wxTextCtrl(notebook_1_pane_1, -1, wxT("0.0"));
    label_13 = new wxStaticText(notebook_1_pane_1, -1, wxT("Bits:"));
    slider_1 = new wxSlider(notebook_1_pane_1, -1, 8, 1, 128);
    label_14 = new wxStaticText(notebook_1_pane_1, -1, wxT("Range:"));
    label_15 = new wxStaticText(notebook_1_pane_1, -1, wxT("Min:"));
    text_ctrl_6 = new wxTextCtrl(notebook_1_pane_1, -1, wxT("0.0"));
    label_16 = new wxStaticText(notebook_1_pane_1, -1, wxT("Max:"));
    text_ctrl_7 = new wxTextCtrl(notebook_1_pane_1, -1, wxT("0.0"));
    label_1 = new wxStaticText(notebook_1_pane_1, -1, wxT("Input Property:"));
    button_invert_input = new wxToggleButton(notebook_1_pane_1, -1, wxT("+"));
    text_ctrl_input_prop = new wxTextCtrl(notebook_1_pane_1, -1, wxT(""));
    label_output_property = new wxStaticText(notebook_1_pane_1, -1, wxT("Output Property:"));
    text_ctrl_output_prop = new wxTextCtrl(notebook_1_pane_1, -1, wxT(""));
    text_ctrl_1 = new wxTextCtrl(notebook_1, -1, wxT(""), wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER|wxTE_PROCESS_TAB|wxTE_MULTILINE|wxTE_WORDWRAP);
    button_OK = new wxButton(this, wxID_OK, wxT("OK"));
    button_Cancel = new wxButton(this, wxID_CANCEL, wxT("Cancel"));
    button_Help = new wxButton(this, -1, wxT("Help"));

    set_properties();
    do_layout();
    // end wxGlade
}


BEGIN_EVENT_TABLE(SensorComponentEditor, wxDialog)
    // begin wxGlade: SensorComponentEditor::event_table
    EVT_CHECKBOX(-1, SensorComponentEditor::OnCheckboxClip)
    EVT_RADIOBOX(-1, SensorComponentEditor::OnCheckBoxNoiseType)
    EVT_COMMAND_SCROLL(-1, SensorComponentEditor::OnBitSliderScroll)
    EVT_COMMAND_SCROLL_ENDSCROLL(-1, SensorComponentEditor::OnBitSliderScroll)
    EVT_COMMAND_SCROLL_THUMBTRACK(-1, SensorComponentEditor::OnBitSliderScroll)
    EVT_COMMAND_SCROLL_PAGEDOWN(-1, SensorComponentEditor::OnBitSliderScroll)
    EVT_COMMAND_SCROLL_PAGEUP(-1, SensorComponentEditor::OnBitSliderScroll)
    EVT_COMMAND_SCROLL_LINEDOWN(-1, SensorComponentEditor::OnBitSliderScroll)
    EVT_COMMAND_SCROLL_TOP(-1, SensorComponentEditor::OnBitSliderScroll)
    EVT_COMMAND_SCROLL_BOTTOM(-1, SensorComponentEditor::OnBitSliderScroll)
    EVT_COMMAND_SCROLL_LINEUP(-1, SensorComponentEditor::OnBitSliderScroll)
    EVT_COMMAND_SCROLL_THUMBRELEASE(-1, SensorComponentEditor::OnBitSliderScroll)
    EVT_TOGGLEBUTTON(-1, SensorComponentEditor::OnClickInvertInput)
    EVT_BUTTON(wxID_OK, SensorComponentEditor::OnButtonPressOK)
    EVT_BUTTON(wxID_CANCEL, SensorComponentEditor::OnButtonPressCancel)
    EVT_BUTTON(-1, SensorComponentEditor::OnButtonPressHelp)
    // end wxGlade
END_EVENT_TABLE();


void SensorComponentEditor::OnCheckboxClip(wxCommandEvent &event)
{
    event.Skip();
}


void SensorComponentEditor::OnCheckBoxNoiseType(wxCommandEvent &event)
{
    event.Skip();
}


void SensorComponentEditor::OnBitSliderScroll(wxScrollEvent &event)
{
    event.Skip();
}


void SensorComponentEditor::OnClickInvertInput(wxCommandEvent &event)
{
    event.Skip();
}


void SensorComponentEditor::OnButtonPressOK(wxCommandEvent &event)
{
  if (notebook_1->Validate()) notebook_1->TransferDataFromWindow();

  event.Skip();
}


void SensorComponentEditor::OnButtonPressCancel(wxCommandEvent &event)
{
    event.Skip();
}


void SensorComponentEditor::OnButtonPressHelp(wxCommandEvent &event)
{
    event.Skip();
}


// wxGlade: add SensorComponentEditor event handlers


void SensorComponentEditor::set_properties()
{
    // begin wxGlade: SensorComponentEditor::set_properties
    SetTitle(wxT("Sensor Component Editor"));
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
    radio_box_noise_type->SetSelection(0);
    slider_1->SetMinSize(wxSize(-1,20));
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


void SensorComponentEditor::do_layout()
{
    // begin wxGlade: SensorComponentEditor::do_layout
    wxFlexGridSizer* grid_sizer_toplevel = new wxFlexGridSizer(2, 1, 5, 0);
    wxBoxSizer* sizer_buttons = new wxBoxSizer(wxHORIZONTAL);
    wxFlexGridSizer* grid_sizer_2 = new wxFlexGridSizer(5, 1, 5, 0);
    wxStaticBoxSizer* sizer_inout = new wxStaticBoxSizer(sizer_inout_staticbox, wxHORIZONTAL);
    wxFlexGridSizer* grid_sizer_inout = new wxFlexGridSizer(2, 2, 5, 5);
    wxFlexGridSizer* grid_sizer_1 = new wxFlexGridSizer(1, 2, 0, 2);
    wxStaticBoxSizer* sizer_sensor = new wxStaticBoxSizer(sizer_sensor_staticbox, wxVERTICAL);
    wxFlexGridSizer* grid_sizer_sensor_props = new wxFlexGridSizer(5, 2, 5, 5);
    wxStaticBoxSizer* sizer_quantize = new wxStaticBoxSizer(sizer_quantize_staticbox, wxVERTICAL);
    wxFlexGridSizer* grid_sizer_3 = new wxFlexGridSizer(4, 2, 5, 5);
    wxBoxSizer* sizer_2 = new wxBoxSizer(wxHORIZONTAL);
    wxFlexGridSizer* grid_sizer_6 = new wxFlexGridSizer(1, 2, 0, 0);
    wxFlexGridSizer* grid_sizer_5 = new wxFlexGridSizer(1, 2, 0, 0);
    wxBoxSizer* sizer_3 = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* sizer_noise_type = new wxBoxSizer(wxVERTICAL);
    wxFlexGridSizer* grid_sizer_4 = new wxFlexGridSizer(1, 2, 0, 5);
    wxStaticBoxSizer* sizer_clip = new wxStaticBoxSizer(sizer_clip_staticbox, wxHORIZONTAL);
    wxFlexGridSizer* grid_sizer_clip = new wxFlexGridSizer(2, 2, 5, 10);
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
    sizer_basic->Add(grid_sizer_basic_interior, 1, wxEXPAND|wxADJUST_MINSIZE, 0);
    grid_sizer_2->Add(sizer_basic, 1, wxEXPAND|wxADJUST_MINSIZE, 0);
    grid_sizer_clip->Add(checkbox_clip, 0, wxALIGN_CENTER_VERTICAL|wxADJUST_MINSIZE, 0);
    sizer_clip_min->Add(label_clip_min, 0, wxLEFT|wxRIGHT|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    sizer_clip_min->Add(text_ctrl_clip_min, 0, wxEXPAND|wxALIGN_CENTER_VERTICAL|wxFIXED_MINSIZE, 0);
    sizer_clip_min->Add(label_clip_max, 0, wxLEFT|wxRIGHT|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    sizer_clip_min->Add(text_ctrl_clip_max, 0, wxEXPAND|wxALIGN_CENTER_VERTICAL|wxFIXED_MINSIZE, 0);
    grid_sizer_clip->Add(sizer_clip_min, 1, wxEXPAND|wxALIGN_CENTER_VERTICAL|wxADJUST_MINSIZE, 0);
    grid_sizer_clip->AddGrowableCol(1);
    sizer_clip->Add(grid_sizer_clip, 1, wxEXPAND|wxADJUST_MINSIZE, 0);
    grid_sizer_2->Add(sizer_clip, 1, wxEXPAND|wxADJUST_MINSIZE, 0);
    grid_sizer_sensor_props->Add(label_2, 0, wxALIGN_CENTER_VERTICAL|wxADJUST_MINSIZE, 0);
    grid_sizer_sensor_props->Add(text_ctrl_lag, 0, wxEXPAND|wxADJUST_MINSIZE, 0);
    grid_sizer_sensor_props->Add(label_3, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxADJUST_MINSIZE, 0);
    sizer_noise_type->Add(radio_box_noise_type, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxADJUST_MINSIZE, 0);
    grid_sizer_4->Add(label_4, 0, wxTOP|wxALIGN_CENTER_VERTICAL|wxADJUST_MINSIZE, 5);
    grid_sizer_4->Add(text_ctrl_2, 0, wxTOP|wxEXPAND|wxADJUST_MINSIZE, 5);
    grid_sizer_4->AddGrowableCol(1);
    sizer_noise_type->Add(grid_sizer_4, 1, wxEXPAND|wxADJUST_MINSIZE, 0);
    grid_sizer_sensor_props->Add(sizer_noise_type, 1, wxEXPAND|wxADJUST_MINSIZE, 0);
    grid_sizer_sensor_props->Add(label_5, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxADJUST_MINSIZE, 0);
    sizer_3->Add(text_ctrl_4_1, 0, wxRIGHT|wxEXPAND|wxADJUST_MINSIZE, 5);
    sizer_3->Add(label_7, 0, wxLEFT|wxRIGHT|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxADJUST_MINSIZE, 5);
    sizer_3->Add(text_ctrl_4, 0, wxLEFT|wxEXPAND|wxADJUST_MINSIZE, 0);
    grid_sizer_sensor_props->Add(sizer_3, 1, wxEXPAND, 0);
    grid_sizer_sensor_props->Add(label_8, 0, wxRIGHT|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxADJUST_MINSIZE, 0);
    grid_sizer_3->Add(label_9, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxADJUST_MINSIZE, 0);
    grid_sizer_3->Add(text_ctrl_5, 0, wxEXPAND|wxADJUST_MINSIZE, 0);
    grid_sizer_3->Add(label_12, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxADJUST_MINSIZE, 0);
    grid_sizer_3->Add(text_ctrl_8, 0, wxEXPAND|wxADJUST_MINSIZE, 0);
    grid_sizer_3->Add(label_13, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxADJUST_MINSIZE, 0);
    grid_sizer_3->Add(slider_1, 0, wxEXPAND|wxADJUST_MINSIZE, 0);
    grid_sizer_3->Add(label_14, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxADJUST_MINSIZE, 0);
    grid_sizer_5->Add(label_15, 0, wxRIGHT|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxADJUST_MINSIZE, 3);
    grid_sizer_5->Add(text_ctrl_6, 0, 0, 0);
    grid_sizer_5->AddGrowableCol(1);
    sizer_2->Add(grid_sizer_5, 1, wxEXPAND, 0);
    grid_sizer_6->Add(label_16, 0, wxRIGHT|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxADJUST_MINSIZE, 3);
    grid_sizer_6->Add(text_ctrl_7, 0, 0, 0);
    grid_sizer_6->AddGrowableCol(1);
    sizer_2->Add(grid_sizer_6, 1, wxEXPAND, 0);
    grid_sizer_3->Add(sizer_2, 1, wxEXPAND, 0);
    grid_sizer_3->AddGrowableCol(1);
    sizer_quantize->Add(grid_sizer_3, 1, wxEXPAND, 0);
    grid_sizer_sensor_props->Add(sizer_quantize, 1, wxEXPAND|wxADJUST_MINSIZE, 1);
    grid_sizer_sensor_props->AddGrowableCol(1);
    sizer_sensor->Add(grid_sizer_sensor_props, 1, wxEXPAND|wxADJUST_MINSIZE, 0);
    grid_sizer_2->Add(sizer_sensor, 1, wxEXPAND|wxADJUST_MINSIZE, 0);
    grid_sizer_inout->Add(label_1, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxADJUST_MINSIZE, 0);
    grid_sizer_1->Add(button_invert_input, 0, wxADJUST_MINSIZE, 0);
    grid_sizer_1->Add(text_ctrl_input_prop, 0, wxEXPAND|wxADJUST_MINSIZE, 0);
    grid_sizer_1->AddGrowableCol(1);
    grid_sizer_inout->Add(grid_sizer_1, 1, wxEXPAND, 0);
    grid_sizer_inout->Add(label_output_property, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxADJUST_MINSIZE, 0);
    grid_sizer_inout->Add(text_ctrl_output_prop, 0, wxEXPAND|wxADJUST_MINSIZE, 0);
    grid_sizer_inout->AddGrowableCol(1);
    sizer_inout->Add(grid_sizer_inout, 1, wxEXPAND, 0);
    grid_sizer_2->Add(sizer_inout, 1, wxEXPAND, 0);
    notebook_1_pane_1->SetAutoLayout(true);
    notebook_1_pane_1->SetSizer(grid_sizer_2);
    grid_sizer_2->Fit(notebook_1_pane_1);
    grid_sizer_2->SetSizeHints(notebook_1_pane_1);
    grid_sizer_2->AddGrowableCol(0);
    notebook_1->AddPage(notebook_1_pane_1, wxT("Properties"));
    notebook_1->AddPage(text_ctrl_1, wxT("Comments"));
    grid_sizer_toplevel->Add(notebook_1, 1, wxEXPAND, 0);
    sizer_buttons->Add(button_OK, 0, wxLEFT|wxRIGHT|wxADJUST_MINSIZE, 5);
    sizer_buttons->Add(button_Cancel, 0, wxLEFT|wxRIGHT, 5);
    sizer_buttons->Add(button_Help, 0, wxLEFT|wxRIGHT|wxADJUST_MINSIZE, 5);
    grid_sizer_toplevel->Add(sizer_buttons, 1, wxALL|wxALIGN_CENTER_HORIZONTAL, 5);
    SetAutoLayout(true);
    SetSizer(grid_sizer_toplevel);
    grid_sizer_toplevel->Fit(this);
    grid_sizer_toplevel->SetSizeHints(this);
    grid_sizer_toplevel->AddGrowableRow(0);
    grid_sizer_toplevel->AddGrowableCol(0);
    Layout();
    Centre();
    // end wxGlade
}

/**
* Show =========================================================================
*/

bool SensorComponentEditor::Show( bool show)
{
  bool tmp = wxDialog::Show(show);

  if (show) notebook_1->InitDialog();

  return tmp;
}

/**
* GetDataIn ====================================================================
*/

void SensorComponentEditor::GetDataIn(Sensor * g)
{
  name     = g->GetName();
  description  = g->GetDescription();
  order    = wxString::Format(wxT("%ld"), g->GetOrder());
  clipable = g->IsClipable();
  clip_max = g->GetClipMax();
  clip_min = g->GetClipMin();

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
  *text_ctrl_1 << g->GetDescription();
}

/**
* SetDataOut ===================================================================
*/

void SensorComponentEditor::SetDataOut(Sensor * g)
{
  g->SetName(name);
//  g->SetDescription(description);

  long int tmpl;
  order.ToLong(&tmpl);
  g->SetOrder(tmpl);
  g->SetClipable(clipable);
  double tmpd;
  g->SetClipMax(clip_max);
  g->SetClipMin(clip_min);

  g->SetDescription(text_ctrl_1->GetValue());

  g->SetInputIsInverted(false);
  if (text_ctrl_input_prop->GetValue() != wxT("NULL")) // true if input prop is present
    if (button_invert_input->GetValue()) // true if inverted
      g->SetInputIsInverted(true);
}
