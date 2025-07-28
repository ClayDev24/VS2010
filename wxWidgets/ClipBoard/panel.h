#pragma once

void LoadPanel() {
	wxPanel *panel = new wxPanel( this, -1 );
	m_textctrl = new wxTextCtrl(panel, ID_Text, "", wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE);

    wxBoxSizer *main_sizer = new wxBoxSizer(wxVERTICAL);
    main_sizer->Add(new wxButton(panel, ID_Write, "Get clipboard text" ), 0, wxALL, 5);
    main_sizer->Add(m_textctrl, 1, wxGROW);
	panel->SetSizer(main_sizer);
}