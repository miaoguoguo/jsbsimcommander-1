/////////////////////////////////////////////////////////////////////////////
// Name:        TableDlg.h
// Purpose:     Manager of the table
// Author:      Matthew Gong
// Created:     02/26/2006
// Copyright:   (c) Matthew Gong
// Licence:     GPL licence
/////////////////////////////////////////////////////////////////////////////

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
 #pragma interface
#endif

// -*- C++ -*- generated by wxGlade 0.3.5.1 on Wed May 11 08:33:48 2005

#ifndef TABLEDLG_H
#define TABLEDLG_H

#include <wx/wx.h>
#include <wx/image.h>
// begin wxGlade: ::dependencies
#include <wx/notebook.h>
#include <wx/grid.h>
// end wxGlade
#include <vector>
#include "TreeItem.h"
#include "mattplot/plot.h"

class PropertyDialog;

std::vector<double> readNumsfromClipboard();

class TableDialog: public wxDialog {
public:
    // begin wxGlade: TableDialog::ids
    enum{
      DETAIL_ROW = 13000,
      DETAIL_COLUMN,
      DETAIL_TABLE,
      DETAIL_FRAME,
      CHS_ROW,
      CHS_COLUMN,
      CHS_TABLE,
      CHS_FRAME,
      TABLE_VALUE,
      FRAME_VALUE,
      GRID_VALUE,
      APPLY,
      FILL_TABLE,
      REBUILD_TABLE,
      REBUILD_FRAME,
      LINE_ROW,
      LINE_COL,
      DRAW_CURVE,
      ADD_CURVE,
      CLS_CURVE,
      ID_NOTEBOOK
    };
    // end wxGlade

    TableDialog(wxWindow* parent, int id, const wxString& title=_("Table Properties"), const wxPoint& pos=wxDefaultPosition, const wxSize& size=wxSize(620, 680), long style=wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER|wxMAXIMIZE_BOX);

    void Load(TreeItemData_Table * data);
    void Save(TreeItemData_Table * data);

private:
    // begin wxGlade: TableDialog::methods
    void set_properties();
    void do_layout();
    // end wxGlade
    void reinit(void);

protected:
    // begin wxGlade: TableDialog::attributes
    wxStaticBox* sizer_9_staticbox;
  
    wxStaticText* label_name;
    wxTextCtrl* text_ctrl_name;
    
    wxStaticText* label_property_row;
    wxTextCtrl* text_ctrl_property_row;
    wxButton* button_chs_row;
    
    wxButton* button_detail_row;
    
    wxStaticText* label_property_column;
    wxTextCtrl* text_ctrl_property_column;
    wxButton* button_chs_column;
    
    wxButton* button_detail_column;

    wxStaticText* label_property_table;
    wxTextCtrl* text_ctrl_property_table;
    wxButton* button_chs_table;

    wxButton* button_detail_table;

    wxStaticText* label_property_frame;
    wxTextCtrl* text_ctrl_property_frame;
    wxButton* button_chs_frame;

    wxButton* button_detail_frame;
    
    wxStaticText* label_table_value;
    wxComboBox* combo_box_table_value;
    wxStaticText* label_frame_value;
    wxComboBox* combo_box_frame_value;
    wxGrid* grid_value;
    wxButton* button_apply;
    wxButton* button_fill_table;
    wxButton* button_recreate_table;
    wxButton* button_recreate_frame;
    wxPanel* notebook_main_pane_2;
    wxStaticText* label_info2;
    wxPanel* notebook_main_pane_3;
    wxTextCtrl* text_ctrl_content;
    wxPanel* notebook_main_pane_4;
    wxNotebook* notebook_main;
    wxButton* button_ok;
    wxButton* button_cancel;
    // end wxGlade

    PlotCanvas* canvas;
    PlotHandler* handler;
    Table2D value_2d;
    Table3D value_3d;
    Table4D value_4d;
    TreeItemData_Table::type Type;

    void updateGrid1D();
    void updateGrid2D();
    Table2D * cur_table;

    void appendCurve();

    void OnDetailRow(wxCommandEvent & event);
    void OnDetailCol(wxCommandEvent & event);
    void OnDetailTab(wxCommandEvent & event);
    void OnDetailFrm(wxCommandEvent & event);
    void OnChsRow(wxCommandEvent & event);
    void OnChsCol(wxCommandEvent & event);
    void OnChsTab(wxCommandEvent & event);
    void OnChsFrm(wxCommandEvent & event);
    void OnChangeCellValue(wxGridEvent & event);
    void OnLeftClickGrid(wxGridEvent & event);
    int cur_col_no, cur_row_no;
    void OnUpdateGrid(wxCommandEvent & event);
    void OnReadInTablefromClipboard(wxCommandEvent & event);
    void OnRebuildTable(wxCommandEvent & event);
    void OnRebuildFrame(wxCommandEvent & event);
    void OnChangedPage(wxNotebookEvent & event);
    void OnChangingPage(wxNotebookEvent & event);
    
    PropertyDialog * prop_dlg;

    DECLARE_EVENT_TABLE() 
};


class ParameterDialog: public wxDialog {
public:
    // begin wxGlade: ParameterDialog::ids
    enum {
      ADD_STR = 14000,
      ADD_CLIP,
      DEL_ONE
    };
    // end wxGlade

    ParameterDialog(wxWindow* parent, int id, const wxString& title, const wxPoint& pos=wxDefaultPosition, const wxSize& size=wxDefaultSize, long style=wxDEFAULT_DIALOG_STYLE);
    void Load(std::vector<double> list, bool editable=true, bool cancelable=true);
    std::vector<double> Save();

private:
    // begin wxGlade: ParameterDialog::methods
    void set_properties();
    void do_layout();
    // end wxGlade

protected:
    // begin wxGlade: ParameterDialog::attributes
    wxListBox* list_box_parameter;
    wxButton* button_add;
    wxButton* button_stream_add;
    wxButton* button_del;
    wxButton* button_ok;
    wxButton* button_cancel;
    // end wxGlade

    void AddNumber(double);

    void OnAddStr(wxCommandEvent & event);
    void OnAddClip(wxCommandEvent & event);
    void OnDelOne(wxCommandEvent & event);

    DECLARE_EVENT_TABLE() 
};


#endif // TABLEDLG_H
