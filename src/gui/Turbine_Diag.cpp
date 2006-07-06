/////////////////////////////////////////////////////////////////////////////
// Name:        Turbine_Diag.h
// Purpose:     Dialog for Turbine Engine
// Author:      Matthew Gong
// Created:     06/29/2005
// Copyright:   (c) Matthew Gong
// Licence:     GPL licence
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

// -*- C++ -*- generated by wxGlade 0.4cvs on Tue Jun 28 16:57:11 2005

#include <wx/wfstream.h>
#include <wx/txtstrm.h>
#include <wx/filename.h>

#include "Turbine_Diag.h"
#include "TreeItem.h"

#ifndef __WXMSW__
#include "aero_icon.xpm"
#include "fcs_icon.xpm"
#include "mass_icon.xpm"
#include "ap_icon.xpm"
#include "fileheader_icon.xpm"
#include "metrics_icon.xpm"
#include "engine_icon.xpm"
#include "gear_icon.xpm"
#include "output_icon.xpm"
#include "axis.xpm"
#include "operator_abs.xpm"
#include "operator_derivative.xpm"
#include "operator_product.xpm"
#include "operator_acos.xpm"
#include "operator_difference.xpm"
#include "operator_quotient.xpm"
#include "operator_asin.xpm"
#include "operator_func.xpm"
#include "operator_sin.xpm"
#include "operator_atan.xpm"
#include "operator_integral.xpm"
#include "operator_sum.xpm"
#include "operator_cos.xpm"
#include "operator_pow.xpm"
#include "operator_tan.xpm"
#include "property_icon.xpm"
#include "table_icon.xpm"
#include "value_icon.xpm"
#include "rocket_engine.xpm"
#include "piston_engine.xpm"
#include "turbine_engine.xpm"
#include "propeller.xpm"
#include "nozzle.xpm"
#include "direct.xpm"
#include "electric_engine.xpm"
#include "tank.xpm"
#include "operator_le.xpm"
#include "operator_lt.xpm"
#include "operator_gt.xpm"
#include "operator_ge.xpm"
#include "operator_eq.xpm"
#include "operator_ne.xpm"
#include "operator_and.xpm"
#include "operator_or.xpm"
#include "operator_not.xpm"
#include "operator_ifthen.xpm"

#endif

bool newTurbineEngine(const wxString & filename)
{ 
  if (!::wxFileExists(filename))
  {
    wxFileOutputStream os(filename);
    if (!os.Ok())
      return false;
    wxTextOutputStream out(os,wxEOL_UNIX);
    wxString name = filename.AfterLast(wxFileName::GetPathSeparator() );
    name = name.BeforeLast('.');

    out << wxT("<?xml version=\"1.0\"?>\n");

    out << wxT("<turbine_engine name=\"") << name << wxT("\">\n");
    out << wxT("  <milthrust> 20723.10 </milthrust>\n");
    out << wxT("  <maxthrust> 64250.44 </maxthrust>\n");
    out << wxT("  <bypassratio> 0.40 </bypassratio>\n");
    out << wxT("  <tsfc> 0.74 </tsfc>\n");
    out << wxT("  <atsfc> 2.05 </atsfc>\n");
    out << wxT("  <idlen1> 40.00 </idlen1>\n");
    out << wxT("  <idlen2> 53.00 </idlen2>\n");
    out << wxT("  <maxn1> 100.00 </maxn1>\n");
    out << wxT("  <maxn2> 100.00 </maxn2>\n");
    out << wxT("  <augmented> 1 </augmented>\n");
    out << wxT("  <augmethod> 2 </augmethod>\n");
    out << wxT("  <injected> 0 </injected>\n");
    out << wxT("  <function name=\"IdleThrust\">\n");
    out << wxT("      <value>0.02</value>\n");
    out << wxT("  </function>\n");
    out << wxT("  <function name=\"MilThrust\">\n");
    out << wxT("      <value>1</value>\n");
    out << wxT("  </function>\n");
    out << wxT("  <function name=\"AugThrust\">\n");
    out << wxT("      <value>1</value>\n");
    out << wxT("  </function>\n");
    out << wxT("</turbine_engine>\n");
    return true;
  }

  return false;
}

TurbineDialog::TurbineDialog(wxWindow* parent, int id, const wxString& title, const wxPoint& pos, const wxSize& size, long style):
    EngineDialog(parent, id, title, pos, size, style)
{
    // begin wxGlade: TurbineDialog::TurbineDialog
    notebook_1 = new wxNotebook(this, -1, wxDefaultPosition, wxDefaultSize, 0);
    notebook_1_pane_2 = new wxPanel(notebook_1, -1);
    notebook_1_pane_1 = new wxPanel(notebook_1, -1);
    label_name = new wxStaticText(notebook_1_pane_1, -1, _("Name :"));
    text_ctrl_name = new wxTextCtrl(notebook_1_pane_1, -1, wxT(""));
    label_bypass = new wxStaticText(notebook_1_pane_1, -1, _("Bypass Ratio :"));
    text_ctrl_bypass = new wxTextCtrl(notebook_1_pane_1, -1, wxT(""), wxDefaultPosition, wxDefaultSize, 0, wxTextValidator(wxFILTER_NUMERIC));
    label_mil = new wxStaticText(notebook_1_pane_1, -1, _("Milthrust :"));
    text_ctrl_mil = new wxTextCtrl(notebook_1_pane_1, -1, wxT(""), wxDefaultPosition, wxDefaultSize, 0, wxTextValidator(wxFILTER_NUMERIC));
    const wxString force_unit[]={wxT("LBS"), wxT("KG"), wxT("N")};
    combo_box_mil = new wxComboBox(notebook_1_pane_1, -1, wxT("LBS"), wxDefaultPosition, wxDefaultSize, 3, force_unit, wxCB_READONLY|wxCB_SIMPLE);
    label_max = new wxStaticText(notebook_1_pane_1, -1, _("Maxthrust :"));
    text_ctrl_max = new wxTextCtrl(notebook_1_pane_1, -1, wxT(""), wxDefaultPosition, wxDefaultSize, 0, wxTextValidator(wxFILTER_NUMERIC));
    combo_box_max = new wxComboBox(notebook_1_pane_1, -1, wxT("LBS"), wxDefaultPosition, wxDefaultSize, 3, force_unit, wxCB_READONLY|wxCB_SIMPLE);
    label_in1 = new wxStaticText(notebook_1_pane_1, -1, _("IdleN1 :"));
    text_ctrl_in1 = new wxTextCtrl(notebook_1_pane_1, -1, wxT(""), wxDefaultPosition, wxDefaultSize, 0, wxTextValidator(wxFILTER_NUMERIC));
    label_in2 = new wxStaticText(notebook_1_pane_1, -1, _("IdleN2 :"));
    text_ctrl_in2 = new wxTextCtrl(notebook_1_pane_1, -1, wxT(""), wxDefaultPosition, wxDefaultSize, 0, wxTextValidator(wxFILTER_NUMERIC));
    label_mn1 = new wxStaticText(notebook_1_pane_1, -1, _("MaxN1 :"));
    text_ctrl_mn1 = new wxTextCtrl(notebook_1_pane_1, -1, wxT(""));
    label_mn2 = new wxStaticText(notebook_1_pane_1, -1, _("MaxN2 :"));
    text_ctrl_mn2 = new wxTextCtrl(notebook_1_pane_1, -1, wxT(""), wxDefaultPosition, wxDefaultSize, 0, wxTextValidator(wxFILTER_NUMERIC));
    label_tsfc = new wxStaticText(notebook_1_pane_1, -1, _("TSFC :"));
    text_ctrl_tsfc = new wxTextCtrl(notebook_1_pane_1, -1, wxT(""), wxDefaultPosition, wxDefaultSize, 0, wxTextValidator(wxFILTER_NUMERIC));
    label_atsfc = new wxStaticText(notebook_1_pane_1, -1, _("ATSFC :"));
    text_ctrl_atsfc = new wxTextCtrl(notebook_1_pane_1, -1, wxT(""), wxDefaultPosition, wxDefaultSize, 0, wxTextValidator(wxFILTER_NUMERIC));
    tree_ctrl_func = new wxTreeCtrl(notebook_1_pane_2, TREE, wxDefaultPosition, wxDefaultSize, wxTR_HAS_BUTTONS|wxTR_NO_LINES|wxTR_DEFAULT_STYLE|wxSUNKEN_BORDER);
    button_ok = new wxButton(this, wxID_OK, _("OK"));
    button_cancel = new wxButton(this, wxID_CANCEL, _("Cancel"));

    set_properties();
    do_layout();
    // end wxGlade
}


void TurbineDialog::set_properties()
{
    // begin wxGlade: TurbineDialog::set_properties
    text_ctrl_name->SetMinSize(wxSize(150, -1));
    text_ctrl_bypass->SetMinSize(wxSize(150, -1));
    text_ctrl_mil->SetMinSize(wxSize(150,-1));
    text_ctrl_max->SetMinSize(wxSize(150,-1));
    text_ctrl_in1->SetMinSize(wxSize(150,-1));
    text_ctrl_in2->SetMinSize(wxSize(150,-1));
    text_ctrl_mn1->SetMinSize(wxSize(150,-1));
    text_ctrl_mn2->SetMinSize(wxSize(150,-1));
    text_ctrl_tsfc->SetMinSize(wxSize(150,-1));
    text_ctrl_atsfc->SetMinSize(wxSize(150,-1));
    // end wxGlade
}


void TurbineDialog::do_layout()
{
    // begin wxGlade: TurbineDialog::do_layout
    wxBoxSizer* sizer_1 = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* sizer_2 = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* sizer_3 = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* sizer_4 = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* sizer_5 = new wxBoxSizer(wxHORIZONTAL);
    wxFlexGridSizer* grid_sizer_1 = new wxFlexGridSizer(6, 4, 5, 5);
    grid_sizer_1->Add(label_name, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 0);
    grid_sizer_1->Add(text_ctrl_name, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5);
    grid_sizer_1->Add(label_bypass, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 0);
    grid_sizer_1->Add(text_ctrl_bypass, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5);
    grid_sizer_1->Add(label_mil, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 0);
    sizer_4->Add(text_ctrl_mil, 1, 0);
    sizer_4->Add(combo_box_mil, 0, 0);
    grid_sizer_1->Add(sizer_4, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5);
    grid_sizer_1->Add(label_max, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 0);
    sizer_5->Add(text_ctrl_max, 1, 0);
    sizer_5->Add(combo_box_max, 0, 0);
    grid_sizer_1->Add(sizer_5, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5);
    grid_sizer_1->Add(label_in1, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 0);
    grid_sizer_1->Add(text_ctrl_in1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5);
    grid_sizer_1->Add(label_in2, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 0);
    grid_sizer_1->Add(text_ctrl_in2, 0, wxALL|wxALIGN_CENTER_VERTICAL, 6);
    grid_sizer_1->Add(label_mn1, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 0);
    grid_sizer_1->Add(text_ctrl_mn1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5);
    grid_sizer_1->Add(label_mn2, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 0);
    grid_sizer_1->Add(text_ctrl_mn2, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5);
    grid_sizer_1->Add(label_tsfc, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 0);
    grid_sizer_1->Add(text_ctrl_tsfc, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5);
    grid_sizer_1->Add(label_atsfc, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 0);
    grid_sizer_1->Add(text_ctrl_atsfc, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5);
    notebook_1_pane_1->SetAutoLayout(true);
    notebook_1_pane_1->SetSizer(grid_sizer_1);
    grid_sizer_1->Fit(notebook_1_pane_1);
    grid_sizer_1->SetSizeHints(notebook_1_pane_1);
    grid_sizer_1->AddGrowableCol(0);
    grid_sizer_1->AddGrowableCol(2);
    sizer_3->Add(tree_ctrl_func, 1, wxALL|wxEXPAND, 5);
    notebook_1_pane_2->SetAutoLayout(true);
    notebook_1_pane_2->SetSizer(sizer_3);
    sizer_3->Fit(notebook_1_pane_2);
    sizer_3->SetSizeHints(notebook_1_pane_2);
    notebook_1->AddPage(notebook_1_pane_1, _("basic"));
    notebook_1->AddPage(notebook_1_pane_2, _("advance"));
    sizer_1->Add(notebook_1, 1, wxALL|wxEXPAND, 3);
    sizer_2->Add(button_ok, 1, wxLEFT|wxRIGHT, 20);
    sizer_2->Add(button_cancel, 1, wxLEFT|wxRIGHT|wxADJUST_MINSIZE, 20);
    sizer_1->Add(sizer_2, 0, wxTOP|wxBOTTOM|wxEXPAND, 10);
    SetAutoLayout(true);
    SetSizer(sizer_1);
    sizer_1->Fit(this);
    sizer_1->SetSizeHints(this);
    Layout();
    // end wxGlade
}

bool TurbineDialog::Load(const wxString & fn)
{
  filename = fn;

  try
  {
    readXML (filename.c_str(), controls_file_parser);
  }
  catch (...)
  {
    return false;
  }

  JSBSim::Element *document = controls_file_parser.GetDocument();
  if (document->GetName() != std::string("turbine_engine"))
    return false;
  
  JSBSim::Element * tmp;
  
  *text_ctrl_name << document->GetAttributeValue("name");
  
  if ( tmp = document->FindElement("bypassratio"))
  {
    *text_ctrl_bypass << tmp->GetDataAsNumber();
  }

  if ( tmp = document->FindElement("milthrust"))
  {
    *text_ctrl_mil << tmp->GetDataAsNumber();
    wxString unit = tmp->GetAttributeValue("unit");
    combo_box_mil->SetValue(unit);
  }

  if ( tmp = document->FindElement("maxthrust"))
  {
    *text_ctrl_max << tmp->GetDataAsNumber();
    wxString unit = tmp->GetAttributeValue("unit");
    combo_box_max->SetValue(unit);
  }

  if ( tmp = document->FindElement("idlen1"))
  {
    *text_ctrl_in1 << tmp->GetDataAsNumber();
  }

  if ( tmp = document->FindElement("idlen2"))
  {
    *text_ctrl_in2 << tmp->GetDataAsNumber();
  }

  if ( tmp = document->FindElement("maxn1"))
  {
    *text_ctrl_mn1 << tmp->GetDataAsNumber();
  }

  if ( tmp = document->FindElement("maxn2"))
  {
    *text_ctrl_mn2 << tmp->GetDataAsNumber();
  }

  if ( tmp = document->FindElement("tsfc"))
  {
    *text_ctrl_tsfc << tmp->GetDataAsNumber();
  }

  if ( tmp = document->FindElement("atsfc"))
  {
    *text_ctrl_atsfc << tmp->GetDataAsNumber();
  }

  init_tree();
  bool flag = false;
  tmp = document->FindElement("function");
  while (tmp) {
    wxString name = tmp->GetAttributeValue("name");
    if (name == wxT("IdleThrust"))
    {
      flag = true;
      break;
    }
    tmp = document->FindNextElement("function");
  }
  if (flag)
  {
    TreeItemData_function * func = new TreeItemData_function;
    tree_ctrl_func->AppendItem(root, wxT("Function"), 24, 24, func);
    func->Init(tree_ctrl_func);
    func->Load(tmp);  
  }
  else
  {
    TreeItemData_function * func = new TreeItemData_function;
    wxTreeItemId idf = tree_ctrl_func->AppendItem(root, wxT("IdleThrust"), 24, 24, func);
    func->Init(tree_ctrl_func);
    func->Type = TreeItemData_function::eTopLevel;
    func->type = wxT("function");
    func->name = wxT("IdleThrust");
    tree_ctrl_func->SetItemText(idf, func->name);
    tree_ctrl_func->SetItemImage(idf, 24);
    
    TreeItemData_Value * val = new TreeItemData_Value;
    wxTreeItemId idv = tree_ctrl_func->AppendItem(idf, wxT("0.02"), 27, 27, val);
    val->Init(tree_ctrl_func);
    val->value = 0.02;
    tree_ctrl_func->SetItemText(idv, wxString::Format("%g",val->value));
    tree_ctrl_func->SetItemImage(idv, 27);
  }

  flag = false;
  tmp = document->FindElement("function");
  while (tmp) {
    wxString name = tmp->GetAttributeValue("name");
    if (name == wxT("MilThrust"))
    {
      flag = true;
      break;
    }
    tmp = document->FindNextElement("function");
  }
  if (flag)
  {
    TreeItemData_function * func = new TreeItemData_function;
    tree_ctrl_func->AppendItem(root, wxT("Function"), 24, 24, func);
    func->Init(tree_ctrl_func);
    func->Load(tmp);  
  }
  else
  {
    TreeItemData_function * func = new TreeItemData_function;
    wxTreeItemId idf = tree_ctrl_func->AppendItem(root, wxT("MilThrust"), 24, 24, func);
    func->Init(tree_ctrl_func);
    func->Type = TreeItemData_function::eTopLevel;
    func->type = wxT("function");
    func->name = wxT("MilThrust");
    tree_ctrl_func->SetItemText(idf, func->name);
    tree_ctrl_func->SetItemImage(idf, 24);
    
    TreeItemData_Value * val = new TreeItemData_Value;
    wxTreeItemId idv = tree_ctrl_func->AppendItem(idf, wxT("1.0"), 27, 27, val);
    val->Init(tree_ctrl_func);
    val->value = 1.0;
    tree_ctrl_func->SetItemText(idv, wxString::Format("%g",val->value));
    tree_ctrl_func->SetItemImage(idv, 27);
  }

  flag = false;
  tmp = document->FindElement("function");
  while (tmp) {
    wxString name = tmp->GetAttributeValue("name");
    if (name == wxT("AugThrust"))
    {
      flag = true;
      break;
    }
    tmp = document->FindNextElement("function");
  }
  if (flag)
  {
    TreeItemData_function * func = new TreeItemData_function;
    tree_ctrl_func->AppendItem(root, wxT("Function"), 24, 24, func);
    func->Init(tree_ctrl_func);
    func->Load(tmp);  
  }
  else
  {
    TreeItemData_function * func = new TreeItemData_function;
    wxTreeItemId idf = tree_ctrl_func->AppendItem(root, wxT("AugThrust"), 24, 24, func);
    func->Init(tree_ctrl_func);
    func->Type = TreeItemData_function::eTopLevel;
    func->type = wxT("function");
    func->name = wxT("AugThrust");
    tree_ctrl_func->SetItemText(idf, func->name);
    tree_ctrl_func->SetItemImage(idf, 24);
    
    TreeItemData_Value * val = new TreeItemData_Value;
    wxTreeItemId idv = tree_ctrl_func->AppendItem(idf, wxT("1.0"), 27, 27, val);
    val->Init(tree_ctrl_func);
    val->value = 1.0;
    tree_ctrl_func->SetItemText(idv, wxString::Format("%g",val->value));
    tree_ctrl_func->SetItemImage(idv, 27);
  }
  
  tree_ctrl_func->Expand(root);

  return true;
}

bool TurbineDialog::Save(const wxString & fn)
{
  if (!fn.IsEmpty())
  {
    filename = fn;
  }

  wxFileOutputStream os(filename);
  if (!os.Ok())
    return false;
  wxTextOutputStream out(os,wxEOL_UNIX);

  out << wxT("<?xml version=\"1.0\"?>\n");
  out << wxT("<turbine_engine name=\"") << text_ctrl_name->GetValue() << wxT("\">\n");
  
  wxString prefix = wxT("  ");

  out << prefix << wxT("<milthrust unit=\"") << combo_box_mil->GetValue() << wxT("\"> ") << text_ctrl_mil->GetValue() << wxT(" </milthrust>\n");
  out << prefix << wxT("<maxthrust unit=\"") << combo_box_max->GetValue() << wxT("\"> ") << text_ctrl_max->GetValue() << wxT(" </maxthrust>\n");
  out << prefix << wxT("<bypassratio> ") << text_ctrl_bypass->GetValue() << wxT(" </bypassratio>\n");
  out << prefix << wxT("<tsfc> ") << text_ctrl_tsfc->GetValue() << wxT(" </tsfc>\n");
  out << prefix << wxT("<atsfc> ") << text_ctrl_atsfc->GetValue() << wxT(" </atsfc>\n");
  out << prefix << wxT("<idlen1> ") << text_ctrl_in1->GetValue() << wxT(" </idlen1>\n");
  out << prefix << wxT("<idlen2> ") << text_ctrl_in2->GetValue() << wxT(" </idlen2>\n");
  out << prefix << wxT("<maxn1> ") << text_ctrl_mn1->GetValue() << wxT(" </maxn1>\n");
  out << prefix << wxT("<maxn2> ") << text_ctrl_mn2->GetValue() << wxT(" </maxn2>\n");
  out << prefix << wxT("<augmented> 1 </augmented>\n");
  out << prefix << wxT("<augmethod> 2 </augmethod>\n");
  out << prefix << wxT("<injected> 0 </injected>\n");

  wxTreeItemIdValue cookie = (wxTreeItemIdValue)0401317LU;
  for (wxTreeItemId node = tree_ctrl_func->GetFirstChild(root, cookie); node.IsOk(); node = tree_ctrl_func->GetNextChild(root, cookie) )
  {
    TreeItemData_function * tmp = dynamic_cast<TreeItemData_function *>(tree_ctrl_func->GetItemData(node));
    if (tmp && tmp->Type == TreeItemData_function::eTopLevel)
      tmp->Save(out, prefix);
  }

  out << wxT("</turbine_engine>\n");
  os.Close();
  
  return true;
}

void TurbineDialog::init_tree()
{
  tree_item_evt_handler = new TreeItemEvtHandler(tree_ctrl_func);
  tree_ctrl_func->PushEventHandler(tree_item_evt_handler);

  wxBitmap bmp(wxBITMAP(fileheader_icon));
  wxImageList * images = new wxImageList(bmp.GetWidth(), bmp.GetHeight());
  images->Add(bmp); // 0
  images->Add(wxBITMAP(metrics_icon));
  images->Add(wxBITMAP(mass_icon));
  images->Add(wxBITMAP(gear_icon));
  images->Add(wxBITMAP(engine_icon));
  images->Add(wxBITMAP(ap_icon)); // 5
  images->Add(wxBITMAP(fcs_icon));
  images->Add(wxBITMAP(aero_icon));
  images->Add(wxBITMAP(output_icon));
  images->Add(wxBITMAP(axis));
  images->Add(wxBITMAP(operator_product)); //10
  images->Add(wxBITMAP(operator_difference));
  images->Add(wxBITMAP(operator_sum));
  images->Add(wxBITMAP(operator_quotient));
  images->Add(wxBITMAP(operator_pow));
  images->Add(wxBITMAP(operator_abs));   //15
  images->Add(wxBITMAP(operator_sin));
  images->Add(wxBITMAP(operator_cos));
  images->Add(wxBITMAP(operator_tan));
  images->Add(wxBITMAP(operator_asin));
  images->Add(wxBITMAP(operator_acos)); //20
  images->Add(wxBITMAP(operator_atan));
  images->Add(wxBITMAP(operator_derivative));
  images->Add(wxBITMAP(operator_integral));
  images->Add(wxBITMAP(operator_func));
  images->Add(wxBITMAP(property_icon));  //25
  images->Add(wxBITMAP(table_icon));
  images->Add(wxBITMAP(value_icon));
  images->Add(wxBITMAP(piston_engine));
  images->Add(wxBITMAP(turbine_engine));
  images->Add(wxBITMAP(rocket_engine));   //30
  images->Add(wxBITMAP(electric_engine));
  images->Add(wxBITMAP(propeller));
  images->Add(wxBITMAP(nozzle));
  images->Add(wxBITMAP(direct));
  images->Add(wxBITMAP(tank));  //35
  images->Add(wxBITMAP(operator_lt));
  images->Add(wxBITMAP(operator_le));
  images->Add(wxBITMAP(operator_gt));
  images->Add(wxBITMAP(operator_ge));
  images->Add(wxBITMAP(operator_eq));  //40
  images->Add(wxBITMAP(operator_ne));
  images->Add(wxBITMAP(operator_and));
  images->Add(wxBITMAP(operator_or));
  images->Add(wxBITMAP(operator_not));
  images->Add(wxBITMAP(operator_ifthen));  //45

  tree_ctrl_func->AssignImageList(images);
  root = tree_ctrl_func->AddRoot(wxT("Root"), 0, 0, new TreeItemData_func_root);

}
