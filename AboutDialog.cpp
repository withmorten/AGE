#include "Common.h"
#include "AboutDialog.h"
#include "AppIcon64.xpm"
#include "CustomWidgets.h"

const wxString AboutDialog::AGE_VER = "2022.10.31";

AboutDialog::AboutDialog(wxWindow *parent, const wxFont &font)
    : wxDialog(parent, -1, "About Advanced Genie Editor", wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE | wxNO_DEFAULT)
{
    SetFont(font);
    SolidText *Title = new SolidText(this, "Advanced Genie Editor\nVersion "+AGE_VER+"\nGPLv3 2011 - 2020\n\nDevelopers:\nMikko \"Tapsa\" P, since 2.0b\nApre - genieutils, 2.1a to 3.1\nEstien Nifo aka StSB77, 1.0a to 2.0a\nwithmorten, some additional changes\ngoto-bus-stop, some additional changes");
    wxStaticBitmap *Image = new wxStaticBitmap(this, wxID_ANY, wxBitmap(AppIcon64_xpm));
    SolidText *Credits = new SolidText(this, "Credits:\nYkkrosh - GeniEd 1 source code\nScenario_t_c - GeniEd 2 source code\nAlexandra \"Taichi San\", DarkRain654 - data file research\nDiGiT, JustTesting1234, AOHH - genie file structure\nCysion, Kris, Sarthos - important help\nBF_Tanks - some help\nDonnieboy, Sarn, chab - tooltip texts\ngagman - new icon");
    wxHyperlinkCtrl *AoKHThread = new wxHyperlinkCtrl(this, wxID_ANY, "Age of Kings Heaven AGE forum topic", "http://aok.heavengames.com/cgi-bin/forums/display.cgi?action=st&fn=9&tn=44059&st=recent&f=9,44059,0,365", wxDefaultPosition, wxDefaultSize, wxNO_BORDER | wxHL_CONTEXTMENU | wxHL_ALIGN_LEFT);
    wxHyperlinkCtrl *GitHub = new wxHyperlinkCtrl(this, wxID_ANY, "withmorten/AGE on GitHub", "https://github.com/withmorten/AGE", wxDefaultPosition, wxDefaultSize, wxNO_BORDER | wxHL_CONTEXTMENU | wxHL_ALIGN_LEFT);

    wxBoxSizer *MainRight = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer *MainAbout = new wxBoxSizer(wxVERTICAL);

    MainRight->Add(Title, 1, wxEXPAND);
    MainRight->Add(Image);
    MainAbout->Add(MainRight, 0, wxALL, 10);
    MainAbout->Add(Credits, 0, wxALL - wxUP, 10);
    MainAbout->Add(AoKHThread, 0, wxALL - wxUP, 10);
    MainAbout->Add(GitHub, 0, wxALL - wxUP, 10);

    SetSizerAndFit(MainAbout);
}
