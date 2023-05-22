#include "Common.h"
#include "../AGE_Frame.h"

void AGE_Frame::ListMapData()
{
    wxCommandEvent E;
    OnMapsRefresh(E);
}

void AGE_Frame::OnMapsRefresh(wxCommandEvent &event)
{
    for (AGETextCtrl *box : uiGroupMaps) box->clear();

    TileWidth->prepend(&dataset->TerrainBlock.TileWidth);
    TileHeight->prepend(&dataset->TerrainBlock.TileHeight);
    ElevHeight->prepend(&dataset->TerrainBlock.ElevHeight);

    if(GenieVersion >= genie::GV_AoKA)
    {
        General_TTKnown[0]->prepend(&dataset->TimeSlice);
        General_TTKnown[1]->prepend(&dataset->UnitKillRate);
        General_TTKnown[2]->prepend(&dataset->UnitKillTotal);
        General_TTKnown[3]->prepend(&dataset->UnitHitPointRate);
        General_TTKnown[4]->prepend(&dataset->UnitHitPointTotal);
        General_TTKnown[5]->prepend(&dataset->RazingKillRate);
        General_TTKnown[6]->prepend(&dataset->RazingKillTotal);
        General_TTKnown[7]->prepend(&dataset->TechTree.TotalUnitTechGroups);
        if(GenieVersion >= genie::GV_SWGB)
        {
            General_SUnknown2->prepend(&dataset->SUnknown2);
            General_SUnknown3->prepend(&dataset->SUnknown3);
            General_SUnknown4->prepend(&dataset->SUnknown4);
            General_SUnknown5->prepend(&dataset->SUnknown5);
            General_SUnknown7->prepend(&dataset->SUnknown7);
            General_SUnknown8->prepend(&dataset->SUnknown8);
        }
    }
    for (AGETextCtrl *box : uiGroupMaps) box->update();
}

void AGE_Frame::CreateGeneralControls()
{
    Tab_General = new ATabPage(TabBar_Main);

    General_Main = new wxBoxSizer(wxVERTICAL);
    General_Scroller = new AScrolled(Tab_General);
    General_ScrollSpace = new wxBoxSizer(wxVERTICAL);

    const wxString SWUNKNOWNSINFO = "Unknowns 2 to 5 are in the beginning of the file,\nright after civilization count (first of the two) and\nbefore terrain tables";
    General_Variables1_Holder = new wxStaticBoxSizer(wxHORIZONTAL, General_Scroller, "Star Wars Unknowns");
    General_SUnknown2_Holder = new wxBoxSizer(wxVERTICAL);
    General_SUnknown2_Text = new SolidText(General_Scroller, " Unkown 2 *");
    General_SUnknown2 = new NumberControl(CLong, General_Scroller, this, &uiGroupMaps);
    General_SUnknown2->SetToolTip(SWUNKNOWNSINFO);
    General_SUnknown3_Holder = new wxBoxSizer(wxVERTICAL);
    General_SUnknown3_Text = new SolidText(General_Scroller, " Unkown 3 *");
    General_SUnknown3 = new NumberControl(CLong, General_Scroller, this, &uiGroupMaps);
    General_SUnknown3->SetToolTip(SWUNKNOWNSINFO);
    General_SUnknown4_Holder = new wxBoxSizer(wxVERTICAL);
    General_SUnknown4_Text = new SolidText(General_Scroller, " Unkown 4 *");
    General_SUnknown4 = new NumberControl(CLong, General_Scroller, this, &uiGroupMaps);
    General_SUnknown4->SetToolTip(SWUNKNOWNSINFO);
    General_SUnknown5_Holder = new wxBoxSizer(wxVERTICAL);
    General_SUnknown5_Text = new SolidText(General_Scroller, " Unkown 5 *");
    General_SUnknown5 = new NumberControl(CLong, General_Scroller, this, &uiGroupMaps);
    General_SUnknown5->SetToolTip(SWUNKNOWNSINFO);
    General_SUnknown7_Holder = new wxBoxSizer(wxVERTICAL);
    General_SUnknown7_Text = new SolidText(General_Scroller, " Unkown 7 *");
    General_SUnknown7 = new NumberControl(CUByte, General_Scroller, this, &uiGroupMaps);
    General_SUnknown7->SetToolTip("In the file this is\nright after civilizations and\nbefore techs");
    General_SUnknown8_Holder = new wxBoxSizer(wxVERTICAL);
    General_SUnknown8_Text = new SolidText(General_Scroller, " Unkown 8 *");
    General_SUnknown8 = new NumberControl(CUByte, General_Scroller, this, &uiGroupMaps);
    General_SUnknown8->SetToolTip("In the file this is\nright after techs and\nbefore technology trees");

    TileWidth_Sizer = new wxBoxSizer(wxVERTICAL);
    TileWidth_Text = new SolidText(General_Scroller, " Map Tile Width");
    TileWidth = new NumberControl(CShort, General_Scroller, this, &uiGroupMaps);
    TileHeight_Sizer = new wxBoxSizer(wxVERTICAL);
    TileHeight_Text = new SolidText(General_Scroller, " Map Tile Height");
    TileHeight = new NumberControl(CShort, General_Scroller, this, &uiGroupMaps);
    ElevHeight_Sizer = new wxBoxSizer(wxVERTICAL);
    ElevHeight_Text = new SolidText(General_Scroller, " Elevation Height");
    ElevHeight = new NumberControl(CShort, General_Scroller, this, &uiGroupMaps);

    General_TerrainRendering_Grid = new wxFlexGridSizer(7, 5, 5);

    TileWidth_Sizer->Add(TileWidth_Text);
    TileHeight_Sizer->Add(TileHeight_Text);
    ElevHeight_Sizer->Add(ElevHeight_Text);
    TileWidth_Sizer->Add(TileWidth);
    TileHeight_Sizer->Add(TileHeight);
    ElevHeight_Sizer->Add(ElevHeight);

    General_TerrainRendering_Grid->Add(TileWidth_Sizer);
    General_TerrainRendering_Grid->Add(TileHeight_Sizer);
    General_TerrainRendering_Grid->Add(ElevHeight_Sizer);

    General_SUnknown7_Holder->Add(General_SUnknown7_Text);
    General_SUnknown7_Holder->Add(General_SUnknown7, 1, wxEXPAND);
    General_SUnknown8_Holder->Add(General_SUnknown8_Text);
    General_SUnknown8_Holder->Add(General_SUnknown8, 1, wxEXPAND);
    General_SUnknown2_Holder->Add(General_SUnknown2_Text);
    General_SUnknown2_Holder->Add(General_SUnknown2, 1, wxEXPAND);
    General_SUnknown3_Holder->Add(General_SUnknown3_Text);
    General_SUnknown3_Holder->Add(General_SUnknown3, 1, wxEXPAND);
    General_SUnknown4_Holder->Add(General_SUnknown4_Text);
    General_SUnknown4_Holder->Add(General_SUnknown4, 1, wxEXPAND);
    General_SUnknown5_Holder->Add(General_SUnknown5_Text);
    General_SUnknown5_Holder->Add(General_SUnknown5, 1, wxEXPAND);
    General_Variables1_Holder->Add(General_SUnknown2_Holder);
    General_Variables1_Holder->Add(General_SUnknown3_Holder, 0, wxLEFT, 5);
    General_Variables1_Holder->Add(General_SUnknown4_Holder, 0, wxLEFT, 5);
    General_Variables1_Holder->Add(General_SUnknown5_Holder, 0, wxLEFT, 5);
    General_Variables1_Holder->Add(General_SUnknown7_Holder, 0, wxLEFT, 5);
    General_Variables1_Holder->Add(General_SUnknown8_Holder, 0, wxLEFT, 5);

    General_ScrollSpace->Add(General_Variables1_Holder);
    General_ScrollSpace->Add(General_TerrainRendering_Grid, 0, wxTOP | wxBOTTOM, 5);

    General_Scroller->SetSizer(General_ScrollSpace);
    General_Scroller->SetScrollRate(0, 15);

    General_Main->Add(General_Scroller, 1, wxEXPAND | wxBOTTOM | wxLEFT | wxRIGHT, 5);

    Tab_General->SetSizer(General_Main);
}

void AGE_Frame::OnRandomMapSearch(wxCommandEvent &event)
{
    How2List = SEARCH;
    ListRandomMaps();
}

wxString AGE_Frame::GetRandomMapName(int index)
{
    if(GenieVersion >= genie::GV_AoK)
    {
        return "Map "+lexical_cast<std::string>(dataset->RandomMaps.Maps[index].MapID);
    }
    wxString Name;
    switch(index)
    {
        case 0: Name = "Small Islands ("; break;
        case 1: Name = "Large Islands ("; break;
        case 2: Name = "Coastal ("; break;
        case 3: Name = "Inland ("; break;
        case 4: Name = "Highland ("; break;
        case 5: Name = "Continental ("; break;
        case 6: Name = "Mediterranean ("; break;
        case 7: Name = "Hill Country ("; break;
        case 8: Name = "Narrows ("; break;
        case 9: Name = "Gigantic ("; break;
        default: Name = "Map (";
    }
    return Name += lexical_cast<std::string>(dataset->RandomMaps.Maps[index].MapID)+")";
}

void AGE_Frame::ListRandomMaps()
{
    InitRandomMaps();
    wxCommandEvent e;
    OnRandomMapSelect(e);
}

void AGE_Frame::InitRandomMaps()
{
    InitSearch(Unknowns_Search->GetValue().MakeLower(), Unknowns_Search_R->GetValue().MakeLower());

    Unknowns_ListV->Sweep();

    for(size_t loop = 0; loop < dataset->RandomMaps.Maps.size(); ++loop)
    {
        wxString Name = FormatInt(loop)+" - "+GetRandomMapName(loop);
        if(SearchMatches(" " + Name.Lower() + " "))
        {
            Unknowns_ListV->names.Add(Name);
            Unknowns_ListV->indexes.push_back(loop);
        }
    }
    RefreshList(Unknowns_ListV, &RandomMapIDs);
}

void AGE_Frame::OnRandomMapSelect(wxCommandEvent &event)
{
    size_t selections = Unknowns_ListV->GetSelectedCount();
    wxBusyCursor WaitCursor;
    getSelectedItems(selections, Unknowns_ListV, RandomMapIDs);
    for (AGETextCtrl *box : uiGroupRandomMap) box->clear();
    genie::MapInfo *map_ptr;
    for (size_t sel = selections; sel-- > 0;)
    {
        map_ptr = &dataset->RandomMaps.Maps[RandomMapIDs[sel]];

        RMS_MapID->prepend(&map_ptr->MapID);
        RMS_LandData[0]->prepend(&map_ptr->BorderSouthWest);
        RMS_LandData[1]->prepend(&map_ptr->BorderNorthWest);
        RMS_LandData[2]->prepend(&map_ptr->BorderNorthEast);
        RMS_LandData[3]->prepend(&map_ptr->BorderSouthEast);
        RMS_LandData[4]->prepend(&map_ptr->BorderUsage);
        RMS_LandData[5]->prepend(&map_ptr->WaterShape);
        RMS_LandData[6]->prepend(&map_ptr->BaseTerrain);
        RMS_LandData[7]->prepend(&map_ptr->LandCoverage);
        RMS_LandData[8]->prepend(&map_ptr->UnusedID);
    }
    SetStatusText(wxString::Format("Selections: %zu    Selected random map: %d",
        selections, selections > 0 ? RandomMapIDs.front() : -1), 0);
    for (AGETextCtrl *box : uiGroupRandomMap) box->update();
    ListMapLands();
    ListMapTerrains();
    ListMapUnits();
    ListMapElevations();
}

void AGE_Frame::OnRandomMapAdd(wxCommandEvent &event)
{
    if(!dataset) return;

    wxBusyCursor WaitCursor;
    AddToList(dataset->RandomMaps.Maps);
    ListRandomMaps();
}

void AGE_Frame::OnRandomMapInsert(wxCommandEvent &event)
{
    size_t selections = Unknowns_ListV->GetSelectedCount();
    if (!selections) return;

    wxBusyCursor WaitCursor;
    InsertToList(dataset->RandomMaps.Maps, RandomMapIDs.front());
    ListRandomMaps();
}

void AGE_Frame::OnRandomMapDelete(wxCommandEvent &event)
{
    size_t selections = Unknowns_ListV->GetSelectedCount();
    if (!selections) return;

    wxBusyCursor WaitCursor;
    DeleteFromList(dataset->RandomMaps.Maps, RandomMapIDs);
    ListRandomMaps();
}

void AGE_Frame::OnRandomMapCopy(wxCommandEvent &event)
{
    size_t selections = Unknowns_ListV->GetSelectedCount();
    if (!selections) return;

    wxBusyCursor WaitCursor;
    CopyFromList(dataset->RandomMaps.Maps, RandomMapIDs, copies.Map);
    Unknowns_Paste->Enable(true);
    Unknowns_PasteInsert->Enable(true);
    Unknowns_ListV->SetFocus();
}

void AGE_Frame::OnRandomMapPaste(wxCommandEvent &event)
{
    size_t selections = Unknowns_ListV->GetSelectedCount();
    if (!selections) return;

    wxBusyCursor WaitCursor;
    PasteToList(dataset->RandomMaps.Maps, RandomMapIDs, copies.Map);
    ListRandomMaps();
}

void AGE_Frame::OnRandomMapPasteInsert(wxCommandEvent &event)
{
    size_t selections = Unknowns_ListV->GetSelectedCount();
    if (!selections) return;

    wxBusyCursor WaitCursor;
    PasteInsertToList(dataset->RandomMaps.Maps, RandomMapIDs.front(), copies.Map);
    ListRandomMaps();
}

void AGE_Frame::OnMapLandSearch(wxCommandEvent &event)
{
    How2List = SEARCH;
    ListMapLands();
}

wxString AGE_Frame::GetMapLandName(int index)
{
    return "Land "+lexical_cast<std::string>(dataset->RandomMaps.Maps[RandomMapIDs.front()].MapLands[index].LandID);
}

void AGE_Frame::ListMapLands()
{
    InitSearch(RMS_Land_Search->GetValue().MakeLower(), RMS_Land_Search_R->GetValue().MakeLower());

    RMS_Land_ListV->Sweep();

    if (dataset->RandomMaps.Maps.size() && RandomMapIDs.size())
    for(size_t loop = 0; loop < dataset->RandomMaps.Maps[RandomMapIDs.front()].MapLands.size(); ++loop)
    {
        wxString Name = FormatInt(loop)+" - "+GetMapLandName(loop);
        if(SearchMatches(" " + Name.Lower() + " "))
        {
            RMS_Land_ListV->names.Add(Name);
            RMS_Land_ListV->indexes.push_back(loop);
        }
    }
    RefreshList(RMS_Land_ListV, &UnknownFSIDs);

    wxCommandEvent e;
    OnMapLandSelect(e);
}

void AGE_Frame::OnMapLandSelect(wxCommandEvent &event)
{
    size_t selections = RMS_Land_ListV->GetSelectedCount();
    wxBusyCursor WaitCursor;
    getSelectedItems(selections, RMS_Land_ListV, UnknownFSIDs);
    for (AGETextCtrl *box : uiGroupRMBase) box->clear();

    genie::MapLand * land_ptr;
    for(size_t sel = selections; sel--> 0;)
    {
        land_ptr = &dataset->RandomMaps.Maps[RandomMapIDs.front()].MapLands[UnknownFSIDs[sel]];

        RMS_Land_LandID->prepend(&land_ptr->LandID);
        RMS_Land_BaseTerrain->prepend(&land_ptr->Terrain);
        RMS_Land_PlayerSpacing->prepend(&land_ptr->LandSpacing);
        RMS_Land_BaseSize->prepend(&land_ptr->BaseSize);
        RMS_Land_Zone->prepend(&land_ptr->Zone);
        RMS_Land_PlacementType->prepend(&land_ptr->PlacementType);
        RMS_Land_X->prepend(&land_ptr->BaseX);
        RMS_Land_Y->prepend(&land_ptr->BaseY);
        RMS_Land_LandProportion->prepend(&land_ptr->LandProportion);
        RMS_Land_ByPlayerFlag->prepend(&land_ptr->ByPlayerFlag);
        RMS_Land_StartAreaRadius->prepend(&land_ptr->StartAreaRadius);
        RMS_Land_TerrainEdgeFade->prepend(&land_ptr->TerrainEdgeFade);
        RMS_Land_Clumpiness->prepend(&land_ptr->Clumpiness);
    }

    for (AGETextCtrl *box : uiGroupRMBase) box->update();
}

void AGE_Frame::OnMapLandAdd(wxCommandEvent &event)
{
    size_t selections = Unknowns_ListV->GetSelectedCount();
    if (!selections) return;

    wxBusyCursor WaitCursor;
    AddToList(dataset->RandomMaps.Maps[RandomMapIDs.front()].MapLands);
    ListMapLands();
}

void AGE_Frame::OnMapLandInsert(wxCommandEvent &event)
{
    size_t selections = RMS_Land_ListV->GetSelectedCount();
    if (!selections) return;

    wxBusyCursor WaitCursor;
    InsertToList(dataset->RandomMaps.Maps[RandomMapIDs.front()].MapLands, UnknownFSIDs.front());
    ListMapLands();
}

void AGE_Frame::OnMapLandDelete(wxCommandEvent &event)
{
    size_t selections = RMS_Land_ListV->GetSelectedCount();
    if (!selections) return;

    wxBusyCursor WaitCursor;
    DeleteFromList(dataset->RandomMaps.Maps[RandomMapIDs.front()].MapLands, UnknownFSIDs);
    ListMapLands();
}

void AGE_Frame::OnMapLandCopy(wxCommandEvent &event)
{
    size_t selections = RMS_Land_ListV->GetSelectedCount();
    if (!selections) return;

    wxBusyCursor WaitCursor;
    CopyFromList(dataset->RandomMaps.Maps[RandomMapIDs.front()].MapLands, UnknownFSIDs, copies.MapLand);
    RMS_Land_Paste->Enable(true);
    RMS_Land_PasteInsert->Enable(true);
    RMS_Land_ListV->SetFocus();
}

void AGE_Frame::OnMapLandPaste(wxCommandEvent &event)
{
    size_t selections = RMS_Land_ListV->GetSelectedCount();
    if (!selections) return;

    wxBusyCursor WaitCursor;
    PasteToList(dataset->RandomMaps.Maps[RandomMapIDs.front()].MapLands, UnknownFSIDs, copies.MapLand);
    ListMapLands();
}

void AGE_Frame::OnMapLandPasteInsert(wxCommandEvent &event)
{
    size_t selections = RMS_Land_ListV->GetSelectedCount();
    if (!selections) return;

    wxBusyCursor WaitCursor;
    PasteInsertToList(dataset->RandomMaps.Maps[RandomMapIDs.front()].MapLands, UnknownFSIDs.front(), copies.MapLand);
    ListMapLands();
}

void AGE_Frame::OnMapLandCopyToMaps(wxCommandEvent &event)
{
    for(size_t loop=1; loop < RandomMapIDs.size(); ++loop)
    {
        dataset->RandomMaps.Maps[RandomMapIDs[loop]].MapLands = dataset->RandomMaps.Maps[RandomMapIDs.front()].MapLands;
    }
}

void AGE_Frame::OnMapTerrainSearch(wxCommandEvent &event)
{
    How2List = SEARCH;
    ListMapTerrains();
}

wxString AGE_Frame::GetMapTerrainName(int Terrain)
{
    wxString Name = FormatInt(Terrain) + " ";
    if(dataset->TerrainBlock.Terrains.size() <= Terrain) return Name + "NULL";
    if(!dataset->TerrainBlock.Terrains[Terrain].Name.empty())
    {
        return Name + dataset->TerrainBlock.Terrains[Terrain].Name;
    }
    return Name + "NULL";
}

void AGE_Frame::ListMapTerrains()
{
    InitSearch(RMS_Terrain_Search->GetValue().MakeLower(), RMS_Terrain_Search_R->GetValue().MakeLower());

    RMS_Terrain_ListV->Sweep();

    if (dataset->RandomMaps.Maps.size() && RandomMapIDs.size())
    for(size_t loop = 0; loop < dataset->RandomMaps.Maps[RandomMapIDs.front()].MapTerrains.size(); ++loop)
    {
        wxString Name = FormatInt(loop)+" - "+GetMapTerrainName(dataset->RandomMaps.Maps[RandomMapIDs.front()].MapTerrains[loop].Terrain);
        if(SearchMatches(" " + Name.Lower() + " "))
        {
            RMS_Terrain_ListV->names.Add(Name);
            RMS_Terrain_ListV->indexes.push_back(loop);
        }
    }
    RefreshList(RMS_Terrain_ListV, &UnknownSSIDs);

    wxCommandEvent e;
    OnMapTerrainSelect(e);
}

void AGE_Frame::OnMapTerrainSelect(wxCommandEvent &event)
{
    size_t selections = RMS_Terrain_ListV->GetSelectedCount();
    wxBusyCursor WaitCursor;
    getSelectedItems(selections, RMS_Terrain_ListV, UnknownSSIDs);
    for (AGETextCtrl *box : uiGroupRMTerrain) box->clear();

    genie::MapTerrain * terrain_ptr;
    for(size_t sel = selections; sel--> 0;)
    {
        terrain_ptr = &dataset->RandomMaps.Maps[RandomMapIDs.front()].MapTerrains[UnknownSSIDs[sel]];

        RMS_TerrainData[0]->prepend(&terrain_ptr->Proportion);
        RMS_TerrainData[1]->prepend(&terrain_ptr->Terrain);
        RMS_TerrainData[2]->prepend(&terrain_ptr->ClumpCount);
        RMS_TerrainData[3]->prepend(&terrain_ptr->EdgeSpacing);
        RMS_TerrainData[4]->prepend(&terrain_ptr->PlacementTerrain);
        RMS_TerrainData[5]->prepend(&terrain_ptr->Clumpiness);
    }

    for (AGETextCtrl *box : uiGroupRMTerrain) box->update();
}

void AGE_Frame::OnMapTerrainAdd(wxCommandEvent &event)
{
    size_t selections = Unknowns_ListV->GetSelectedCount();
    if (!selections) return;

    wxBusyCursor WaitCursor;
    AddToList(dataset->RandomMaps.Maps[RandomMapIDs.front()].MapTerrains);
    ListMapTerrains();
}

void AGE_Frame::OnMapTerrainInsert(wxCommandEvent &event)
{
    size_t selections = RMS_Terrain_ListV->GetSelectedCount();
    if (!selections) return;

    wxBusyCursor WaitCursor;
    InsertToList(dataset->RandomMaps.Maps[RandomMapIDs.front()].MapTerrains, UnknownSSIDs.front());
    ListMapTerrains();
}

void AGE_Frame::OnMapTerrainDelete(wxCommandEvent &event)
{
    size_t selections = RMS_Terrain_ListV->GetSelectedCount();
    if (!selections) return;

    wxBusyCursor WaitCursor;
    DeleteFromList(dataset->RandomMaps.Maps[RandomMapIDs.front()].MapTerrains, UnknownSSIDs);
    ListMapTerrains();
}

void AGE_Frame::OnMapTerrainCopy(wxCommandEvent &event)
{
    size_t selections = RMS_Terrain_ListV->GetSelectedCount();
    if (!selections) return;

    wxBusyCursor WaitCursor;
    CopyFromList(dataset->RandomMaps.Maps[RandomMapIDs.front()].MapTerrains, UnknownSSIDs, copies.MapTerrain);
    RMS_Terrain_Paste->Enable(true);
    RMS_Terrain_PasteInsert->Enable(true);
    RMS_Terrain_ListV->SetFocus();
}

void AGE_Frame::OnMapTerrainPaste(wxCommandEvent &event)
{
    size_t selections = RMS_Terrain_ListV->GetSelectedCount();
    if (!selections) return;

    wxBusyCursor WaitCursor;
    PasteToList(dataset->RandomMaps.Maps[RandomMapIDs.front()].MapTerrains, UnknownSSIDs, copies.MapTerrain);
    ListMapTerrains();
}

void AGE_Frame::OnMapTerrainPasteInsert(wxCommandEvent &event)
{
    size_t selections = RMS_Terrain_ListV->GetSelectedCount();
    if (!selections) return;

    wxBusyCursor WaitCursor;
    PasteInsertToList(dataset->RandomMaps.Maps[RandomMapIDs.front()].MapTerrains, UnknownSSIDs.front(), copies.MapTerrain);
    ListMapTerrains();
}

void AGE_Frame::OnMapTerrainCopyToMaps(wxCommandEvent &event)
{
    for(size_t loop=1; loop < RandomMapIDs.size(); ++loop)
    {
        dataset->RandomMaps.Maps[RandomMapIDs[loop]].MapTerrains = dataset->RandomMaps.Maps[RandomMapIDs.front()].MapTerrains;
    }
}

void AGE_Frame::OnMapUnitSearch(wxCommandEvent &event)
{
    How2List = SEARCH;
    ListMapUnits();
}

void AGE_Frame::ListMapUnits()
{
    InitSearch(RMS_Unit_Search->GetValue().MakeLower(), RMS_Unit_Search_R->GetValue().MakeLower());

    RMS_Unit_ListV->Sweep();

    if (dataset->RandomMaps.Maps.size() && RandomMapIDs.size())
    for(size_t loop = 0; loop < dataset->RandomMaps.Maps[RandomMapIDs.front()].MapUnits.size(); ++loop)
    {
        wxString Name = FormatInt(loop)+" - "+GetUnitLineUnitName(dataset->RandomMaps.Maps[RandomMapIDs.front()].MapUnits[loop].Unit);
        if(SearchMatches(" " + Name.Lower() + " "))
        {
            RMS_Unit_ListV->names.Add(Name);
            RMS_Unit_ListV->indexes.push_back(loop);
        }
    }
    RefreshList(RMS_Unit_ListV, &UnknownTSIDs);

    wxCommandEvent e;
    OnMapUnitSelect(e);
}

void AGE_Frame::OnMapUnitSelect(wxCommandEvent &event)
{
    size_t selections = RMS_Unit_ListV->GetSelectedCount();
    wxBusyCursor WaitCursor;
    getSelectedItems(selections, RMS_Unit_ListV, UnknownTSIDs);
    for (AGETextCtrl *box : uiGroupRMUnit) box->clear();

    genie::MapUnit * object_ptr;
    for(size_t sel = selections; sel--> 0;)
    {
        object_ptr = &dataset->RandomMaps.Maps[RandomMapIDs.front()].MapUnits[UnknownTSIDs[sel]];

        RMS_Unit_Unit->prepend(&object_ptr->Unit);
        RMS_Unit_HostTerrain->prepend(&object_ptr->HostTerrain);
        RMS_Unit_GroupPlacing->prepend(&object_ptr->GroupPlacing);
        RMS_Unit_ScaleFlag->prepend(&object_ptr->ScaleFlag);
        RMS_Unit_ObjectsPerPlayer->prepend(&object_ptr->ObjectsPerGroup);
        RMS_Unit_Fluctuation->prepend(&object_ptr->Fluctuation);
        RMS_Unit_GroupsPerPlayer->prepend(&object_ptr->GroupsPerPlayer);
        RMS_Unit_GroupArea->prepend(&object_ptr->GroupArea);
        RMS_Unit_PlayerID->prepend(&object_ptr->PlayerID);
        RMS_Unit_SetPlaceForAllPlayers->prepend(&object_ptr->SetPlaceForAllPlayers);
        RMS_Unit_MinDistanceToPlayers->prepend(&object_ptr->MinDistanceToPlayers);
        RMS_Unit_MaxDistanceToPlayers->prepend(&object_ptr->MaxDistanceToPlayers);
    }

    for (AGETextCtrl *box : uiGroupRMUnit) box->update();
}

void AGE_Frame::OnMapUnitAdd(wxCommandEvent &event)
{
    size_t selections = Unknowns_ListV->GetSelectedCount();
    if (!selections) return;

    wxBusyCursor WaitCursor;
    AddToList(dataset->RandomMaps.Maps[RandomMapIDs.front()].MapUnits);
    ListMapUnits();
}

void AGE_Frame::OnMapUnitInsert(wxCommandEvent &event)
{
    size_t selections = RMS_Unit_ListV->GetSelectedCount();
    if (!selections) return;

    wxBusyCursor WaitCursor;
    InsertToList(dataset->RandomMaps.Maps[RandomMapIDs.front()].MapUnits, UnknownTSIDs.front());
    ListMapUnits();
}

void AGE_Frame::OnMapUnitDelete(wxCommandEvent &event)
{
    size_t selections = RMS_Unit_ListV->GetSelectedCount();
    if (!selections) return;

    wxBusyCursor WaitCursor;
    DeleteFromList(dataset->RandomMaps.Maps[RandomMapIDs.front()].MapUnits, UnknownTSIDs);
    ListMapUnits();
}

void AGE_Frame::OnMapUnitCopy(wxCommandEvent &event)
{
    size_t selections = RMS_Unit_ListV->GetSelectedCount();
    if (!selections) return;

    wxBusyCursor WaitCursor;
    CopyFromList(dataset->RandomMaps.Maps[RandomMapIDs.front()].MapUnits, UnknownTSIDs, copies.MapUnit);
    RMS_Unit_Paste->Enable(true);
    RMS_Unit_PasteInsert->Enable(true);
    RMS_Unit_ListV->SetFocus();
}

void AGE_Frame::OnMapUnitPaste(wxCommandEvent &event)
{
    size_t selections = RMS_Unit_ListV->GetSelectedCount();
    if (!selections) return;

    wxBusyCursor WaitCursor;
    PasteToList(dataset->RandomMaps.Maps[RandomMapIDs.front()].MapUnits, UnknownTSIDs, copies.MapUnit);
    ListMapUnits();
}

void AGE_Frame::OnMapUnitPasteInsert(wxCommandEvent &event)
{
    size_t selections = RMS_Unit_ListV->GetSelectedCount();
    if (!selections) return;

    wxBusyCursor WaitCursor;
    PasteInsertToList(dataset->RandomMaps.Maps[RandomMapIDs.front()].MapUnits, UnknownTSIDs.front(), copies.MapUnit);
    ListMapUnits();
}

void AGE_Frame::OnMapUnitCopyToMaps(wxCommandEvent &event)
{
    for(size_t loop=1; loop < RandomMapIDs.size(); ++loop)
    {
        dataset->RandomMaps.Maps[RandomMapIDs[loop]].MapUnits = dataset->RandomMaps.Maps[RandomMapIDs.front()].MapUnits;
    }
}

void AGE_Frame::OnMapElevationSearch(wxCommandEvent &event)
{
    How2List = SEARCH;
    ListMapElevations();
}

void AGE_Frame::ListMapElevations()
{
    InitSearch(RMS_Elevation_Search->GetValue().MakeLower(), RMS_Elevation_Search_R->GetValue().MakeLower());

    RMS_Elevation_ListV->Sweep();

    if (dataset->RandomMaps.Maps.size() && RandomMapIDs.size())
    for(size_t loop = 0; loop < dataset->RandomMaps.Maps[RandomMapIDs.front()].MapElevations.size(); ++loop)
    {
        wxString Name = FormatInt(loop)+" - Elevation (useless)";
        if(SearchMatches(" " + Name.Lower() + " "))
        {
            RMS_Elevation_ListV->names.Add(Name);
            RMS_Elevation_ListV->indexes.push_back(loop);
        }
    }
    RefreshList(RMS_Elevation_ListV, &Unknown4SIDs);

    wxCommandEvent e;
    OnMapElevationSelect(e);
}

void AGE_Frame::OnMapElevationSelect(wxCommandEvent &event)
{
    size_t selections = RMS_Elevation_ListV->GetSelectedCount();
    wxBusyCursor WaitCursor;
    getSelectedItems(selections, RMS_Elevation_ListV, Unknown4SIDs);
    for (AGETextCtrl *box : uiGroupRMUnknown) box->clear();

    genie::MapElevation * elevation_ptr;
    for(size_t sel = selections; sel--> 0;)
    {
        elevation_ptr = &dataset->RandomMaps.Maps[RandomMapIDs.front()].MapElevations[Unknown4SIDs[sel]];

        RMS_ElevationData[0]->prepend(&elevation_ptr->Proportion);
        RMS_ElevationData[1]->prepend(&elevation_ptr->Terrain);
        RMS_ElevationData[2]->prepend(&elevation_ptr->ClumpCount);
        RMS_ElevationData[3]->prepend(&elevation_ptr->BaseTerrain);
        RMS_ElevationData[4]->prepend(&elevation_ptr->BaseElevation);
        RMS_ElevationData[5]->prepend(&elevation_ptr->TileSpacing);
    }

    for (AGETextCtrl *box : uiGroupRMUnknown) box->update();
}

void AGE_Frame::OnMapElevationAdd(wxCommandEvent &event)
{
    size_t selections = Unknowns_ListV->GetSelectedCount();
    if (!selections) return;

    wxBusyCursor WaitCursor;
    AddToList(dataset->RandomMaps.Maps[RandomMapIDs.front()].MapElevations);
    ListMapElevations();
}

void AGE_Frame::OnMapElevationInsert(wxCommandEvent &event)
{
    size_t selections = RMS_Elevation_ListV->GetSelectedCount();
    if (!selections) return;

    wxBusyCursor WaitCursor;
    InsertToList(dataset->RandomMaps.Maps[RandomMapIDs.front()].MapElevations, Unknown4SIDs.front());
    ListMapElevations();
}

void AGE_Frame::OnMapElevationDelete(wxCommandEvent &event)
{
    size_t selections = RMS_Elevation_ListV->GetSelectedCount();
    if (!selections) return;

    wxBusyCursor WaitCursor;
    DeleteFromList(dataset->RandomMaps.Maps[RandomMapIDs.front()].MapElevations, Unknown4SIDs);
    ListMapElevations();
}

void AGE_Frame::OnMapElevationCopy(wxCommandEvent &event)
{
    size_t selections = RMS_Elevation_ListV->GetSelectedCount();
    if (!selections) return;

    wxBusyCursor WaitCursor;
    CopyFromList(dataset->RandomMaps.Maps[RandomMapIDs.front()].MapElevations, Unknown4SIDs, copies.MapElevation);
    RMS_Elevation_Paste->Enable(true);
    RMS_Elevation_PasteInsert->Enable(true);
    RMS_Elevation_ListV->SetFocus();
}

void AGE_Frame::OnMapElevationPaste(wxCommandEvent &event)
{
    size_t selections = RMS_Elevation_ListV->GetSelectedCount();
    if (!selections) return;

    wxBusyCursor WaitCursor;
    PasteToList(dataset->RandomMaps.Maps[RandomMapIDs.front()].MapElevations, Unknown4SIDs, copies.MapElevation);
    ListMapElevations();
}

void AGE_Frame::OnMapElevationPasteInsert(wxCommandEvent &event)
{
    size_t selections = RMS_Elevation_ListV->GetSelectedCount();
    if (!selections) return;

    wxBusyCursor WaitCursor;
    PasteInsertToList(dataset->RandomMaps.Maps[RandomMapIDs.front()].MapElevations, Unknown4SIDs.front(), copies.MapElevation);
    ListMapElevations();
}

void AGE_Frame::OnMapElevationCopyToMaps(wxCommandEvent &event)
{
    for(size_t loop=1; loop < RandomMapIDs.size(); ++loop)
    {
        dataset->RandomMaps.Maps[RandomMapIDs[loop]].MapElevations = dataset->RandomMaps.Maps[RandomMapIDs.front()].MapElevations;
    }
}

void AGE_Frame::CreateUnknownControls()
{
    Tab_Unknown = new ATabPage(TabBar_Main);

    Unknown_Main = new wxBoxSizer(wxVERTICAL);
    RMS_Scroller = new AScrolled(Tab_Unknown);
    Unknown_ScrollSpace = new wxBoxSizer(wxVERTICAL);

    Unknowns = new wxStaticBoxSizer(wxHORIZONTAL, Tab_Unknown, "Map Data");
    Unknowns_ListArea = new wxBoxSizer(wxVERTICAL);
    Unknowns_Search = new wxTextCtrl(Tab_Unknown, wxID_ANY);
    Unknowns_Search_R = new wxTextCtrl(Tab_Unknown, wxID_ANY);
    Unknowns_ListV = new ProperList(Tab_Unknown, ASize(200, 220));
    Unknowns_Buttons = new wxGridSizer(3, 0, 0);
    Unknowns_Add = new wxButton(Tab_Unknown, wxID_ANY, "Add", wxDefaultPosition, wxSize(10, -1));
    Unknowns_Insert = new wxButton(Tab_Unknown, wxID_ANY, "Insert New", wxDefaultPosition, wxSize(10, -1));
    Unknowns_Delete = new wxButton(Tab_Unknown, wxID_ANY, "Delete", wxDefaultPosition, wxSize(10, -1));
    Unknowns_Copy = new wxButton(Tab_Unknown, wxID_ANY, "Copy", wxDefaultPosition, wxSize(10, -1));
    Unknowns_Paste = new wxButton(Tab_Unknown, wxID_ANY, "Paste", wxDefaultPosition, wxSize(10, -1));
    Unknowns_PasteInsert = new wxButton(Tab_Unknown, wxID_ANY, "Ins Copies", wxDefaultPosition, wxSize(10, -1));

    RMS_MapID_Holder = new wxBoxSizer(wxVERTICAL);
    RMS_MapID_Text = new SolidText(RMS_Scroller, " Script Number");
    RMS_MapID = new NumberControl(CLong, RMS_Scroller, this, &uiGroupRandomMap, false);
    RMS_LandData_Grid = new wxFlexGridSizer(5, 5, 5);
    for(size_t loop = 0; loop < RMS_LandData.size(); ++loop)
    {
        RMS_LandData_Holder[loop] = new wxBoxSizer(wxVERTICAL);
        RMS_LandData[loop] = new NumberControl(CLong, RMS_Scroller, this, &uiGroupRandomMap);
    }
    wxString MAPEDGEBUFFER = "Map Edge Buffer";
    RMS_LandData_Text[0] = new SolidText(RMS_Scroller, " Border SW *");
    RMS_LandData[0]->SetToolTip(MAPEDGEBUFFER);
    RMS_LandData_Text[1] = new SolidText(RMS_Scroller, " Border NW *");
    RMS_LandData[1]->SetToolTip(MAPEDGEBUFFER);
    RMS_LandData_Text[2] = new SolidText(RMS_Scroller, " Border NE *");
    RMS_LandData[2]->SetToolTip(MAPEDGEBUFFER);
    RMS_LandData_Text[3] = new SolidText(RMS_Scroller, " Border SE *");
    RMS_LandData[3]->SetToolTip(MAPEDGEBUFFER);
    RMS_LandData_Text[4] = new SolidText(RMS_Scroller, " Border Usage % *");
    RMS_LandData[4]->SetToolTip("Fuzzy map edges\n% of border area covered with non-base terrain");
    RMS_LandData_Text[5] = new SolidText(RMS_Scroller, " Water Shape *");
    RMS_LandData[5]->SetToolTip("Land Placement Edge");
    RMS_LandData_Text[6] = new SolidText(RMS_Scroller, " Base Terrain *");
    RMS_LandData[6]->SetToolTip("Used on the borders as well");
    RMS_LandData_Text[7] = new SolidText(RMS_Scroller, " Land Cover % *");
    RMS_LandData[7]->SetToolTip("Can be over 100");
    RMS_LandData_Text[8] = new SolidText(RMS_Scroller, " Unused ID");

    RMSMapLands = new wxStaticBoxSizer(wxHORIZONTAL, RMS_Scroller, "Base Land Data");
    RMS_Land_ListArea = new wxBoxSizer(wxVERTICAL);
    RMS_Land_Search = new wxTextCtrl(RMS_Scroller, wxID_ANY);
    RMS_Land_Search_R = new wxTextCtrl(RMS_Scroller, wxID_ANY);
    RMS_Land_ListV = new ProperList(RMS_Scroller, ASize(140, 100));
    RMS_Land_Buttons = new wxGridSizer(3, 0, 0);
    RMS_Land_Add = new wxButton(RMS_Scroller, wxID_ANY, "Add", wxDefaultPosition, wxSize(10, -1));
    RMS_Land_Insert = new wxButton(RMS_Scroller, wxID_ANY, "Ins New", wxDefaultPosition, wxSize(10, -1));
    RMS_Land_Delete = new wxButton(RMS_Scroller, wxID_ANY, "Delete", wxDefaultPosition, wxSize(10, -1));
    RMS_Land_Copy = new wxButton(RMS_Scroller, wxID_ANY, "Copy", wxDefaultPosition, wxSize(10, -1));
    RMS_Land_Paste = new wxButton(RMS_Scroller, wxID_ANY, "Paste", wxDefaultPosition, wxSize(10, -1));
    RMS_Land_PasteInsert = new wxButton(RMS_Scroller, wxID_ANY, "Ins Copies", wxDefaultPosition, wxSize(10, -1));
    RMS_Land_CopyToMaps = new wxButton(RMS_Scroller, wxID_ANY, "Copy all to selected maps", wxDefaultPosition, wxSize(10, -1));

    RMS_Land_LandID_Grid = new wxFlexGridSizer(4, 5, 5);

    RMS_Land_LandID_Holder = new wxBoxSizer(wxVERTICAL);
    RMS_Land_LandID_Text = new SolidText(RMS_Scroller, " Land ID");
    RMS_Land_LandID = new NumberControl(CLong, RMS_Scroller, this, &uiGroupRMBase, false);
    RMS_Land_BaseTerrain_Holder = new wxBoxSizer(wxVERTICAL);
    RMS_Land_BaseTerrain_Text = new SolidText(RMS_Scroller, " Base Terrain");
    RMS_Land_BaseTerrain = new NumberControl(CUByte, RMS_Scroller, this, &uiGroupRMBase);
    RMS_Land_PlayerSpacing_Holder = new wxBoxSizer(wxVERTICAL);
    RMS_Land_PlayerSpacing_Text = new SolidText(RMS_Scroller, " Land Spacing *");
    RMS_Land_PlayerSpacing = new NumberControl(CLong, RMS_Scroller, this, &uiGroupRMBase);
    RMS_Land_PlayerSpacing->SetToolTip("Non-base terrain (like river) space between players.\nIf too large, they won't be created.");
    RMS_Land_BaseSize_Holder = new wxBoxSizer(wxVERTICAL);
    RMS_Land_BaseSize_Text = new SolidText(RMS_Scroller, " Base Size");
    RMS_Land_BaseSize = new NumberControl(CLong, RMS_Scroller, this, &uiGroupRMBase);

    RMS_Land_Zone_Holder = new wxBoxSizer(wxVERTICAL);
    RMS_Land_Zone_Text = new SolidText(RMS_Scroller, " Zone");
    RMS_Land_Zone = new NumberControl(CUByte, RMS_Scroller, this, &uiGroupRMBase);
    RMS_Land_PlacementType_Holder = new wxBoxSizer(wxVERTICAL);
    RMS_Land_PlacementType_Text = new SolidText(RMS_Scroller, " Placement Type *");
    RMS_Land_PlacementType = new NumberControl(CUByte, RMS_Scroller, this, &uiGroupRMBase);
    RMS_Land_PlacementType->SetToolTip("Base placement\n0   Random\n1   Given\n2   Spaced");

    RMS_Land_X_Holder = new wxBoxSizer(wxVERTICAL);
    RMS_Land_X_Text = new SolidText(RMS_Scroller, " Base X");
    RMS_Land_X = new NumberControl(CLong, RMS_Scroller, this, &uiGroupRMBase);
    RMS_Land_Y_Holder = new wxBoxSizer(wxVERTICAL);
    RMS_Land_Y_Text = new SolidText(RMS_Scroller, " Base Y");
    RMS_Land_Y = new NumberControl(CLong, RMS_Scroller, this, &uiGroupRMBase);

    RMS_Land_LandProportion_Holder = new wxBoxSizer(wxVERTICAL);
    RMS_Land_LandProportion_Text = new SolidText(RMS_Scroller, " Land Proportion");
    RMS_Land_LandProportion = new NumberControl(CUByte, RMS_Scroller, this, &uiGroupRMBase);
    RMS_Land_ByPlayerFlag_Holder = new wxBoxSizer(wxVERTICAL);
    RMS_Land_ByPlayerFlag_Text = new SolidText(RMS_Scroller, " Player Placement *");
    RMS_Land_ByPlayerFlag = new NumberControl(CUByte, RMS_Scroller, this, &uiGroupRMBase);
    RMS_Land_ByPlayerFlag->SetToolTip("0   Not by player\n1   By player, overlap\n2   By player, seperate");

    RMS_Land_StartAreaRadius_Holder = new wxBoxSizer(wxVERTICAL);
    RMS_Land_StartAreaRadius_Text = new SolidText(RMS_Scroller, " Player Base Size *");
    RMS_Land_StartAreaRadius = new NumberControl(CLong, RMS_Scroller, this, &uiGroupRMBase);
    RMS_Land_StartAreaRadius->SetToolTip("This area cannot contain different elevations or terrains\nTerrain edge fading affects this");
    RMS_Land_TerrainEdgeFade_Holder = new wxBoxSizer(wxVERTICAL);
    RMS_Land_TerrainEdgeFade_Text = new SolidText(RMS_Scroller, " Terrain Edge Fade *");
    RMS_Land_TerrainEdgeFade = new NumberControl(CLong, RMS_Scroller, this, &uiGroupRMBase);
    RMS_Land_TerrainEdgeFade->SetToolTip("Used to fuzz edges");
    RMS_Land_Clumpiness_Holder = new wxBoxSizer(wxVERTICAL);
    RMS_Land_Clumpiness_Text = new SolidText(RMS_Scroller, " Clumpiness Factor");
    RMS_Land_Clumpiness = new NumberControl(CLong, RMS_Scroller, this, &uiGroupRMBase);

    RMSTerrain = new wxStaticBoxSizer(wxHORIZONTAL, RMS_Scroller, "Terrains placed on the map");
    RMS_Terrain_ListArea = new wxBoxSizer(wxVERTICAL);
    RMS_Terrain_Search = new wxTextCtrl(RMS_Scroller, wxID_ANY);
    RMS_Terrain_Search_R = new wxTextCtrl(RMS_Scroller, wxID_ANY);
    RMS_Terrain_ListV = new ProperList(RMS_Scroller, ASize(140, 100));
    RMS_Terrain_Buttons = new wxGridSizer(3, 0, 0);
    RMS_Terrain_Add = new wxButton(RMS_Scroller, wxID_ANY, "Add", wxDefaultPosition, wxSize(10, -1));
    RMS_Terrain_Insert = new wxButton(RMS_Scroller, wxID_ANY, "Ins New", wxDefaultPosition, wxSize(10, -1));
    RMS_Terrain_Delete = new wxButton(RMS_Scroller, wxID_ANY, "Delete", wxDefaultPosition, wxSize(10, -1));
    RMS_Terrain_Copy = new wxButton(RMS_Scroller, wxID_ANY, "Copy", wxDefaultPosition, wxSize(10, -1));
    RMS_Terrain_Paste = new wxButton(RMS_Scroller, wxID_ANY, "Paste", wxDefaultPosition, wxSize(10, -1));
    RMS_Terrain_PasteInsert = new wxButton(RMS_Scroller, wxID_ANY, "Ins Copies", wxDefaultPosition, wxSize(10, -1));
    RMS_Terrain_CopyToMaps = new wxButton(RMS_Scroller, wxID_ANY, "Copy all to selected maps", wxDefaultPosition, wxSize(10, -1));

    RMS_TerrainData_Grid = new wxFlexGridSizer(4, 5, 5);
    for(size_t loop = 0; loop < RMS_TerrainData.size(); ++loop)
    {
        RMS_TerrainData_Holder[loop] = new wxBoxSizer(wxVERTICAL);
        RMS_TerrainData[loop] = new NumberControl(CLong, RMS_Scroller, this, &uiGroupRMTerrain, false);
    }
    RMS_TerrainData_Text[0] = new SolidText(RMS_Scroller, " Proportion *");
    RMS_TerrainData[0]->SetToolTip("% of the total map area");
    RMS_TerrainData_Text[1] = new SolidText(RMS_Scroller, " Terrain");
    RMS_TerrainData_Text[2] = new SolidText(RMS_Scroller, " Clump Count *");
    RMS_TerrainData[2]->SetToolTip("Clusters in the map");
    RMS_TerrainData_Text[3] = new SolidText(RMS_Scroller, " Terrain Spacing *");
    RMS_TerrainData[3]->SetToolTip("Minimum distance to another terrain");
    RMS_TerrainData_Text[4] = new SolidText(RMS_Scroller, " Placement Terrain");
    RMS_TerrainData_Text[5] = new SolidText(RMS_Scroller, " Clumpiness Factor");

    RMSUnit = new wxStaticBoxSizer(wxHORIZONTAL, RMS_Scroller, "Units placed on the map (Some may appear anyway)");
    RMS_Unit_ListArea = new wxBoxSizer(wxVERTICAL);
    RMS_Unit_Search = new wxTextCtrl(RMS_Scroller, wxID_ANY);
    RMS_Unit_Search_R = new wxTextCtrl(RMS_Scroller, wxID_ANY);
    RMS_Unit_ListV = new ProperList(RMS_Scroller, ASize(140, 250));
    RMS_Unit_Buttons = new wxGridSizer(3, 0, 0);
    RMS_Unit_Add = new wxButton(RMS_Scroller, wxID_ANY, "Add", wxDefaultPosition, wxSize(10, -1));
    RMS_Unit_Insert = new wxButton(RMS_Scroller, wxID_ANY, "Ins New", wxDefaultPosition, wxSize(10, -1));
    RMS_Unit_Delete = new wxButton(RMS_Scroller, wxID_ANY, "Delete", wxDefaultPosition, wxSize(10, -1));
    RMS_Unit_Copy = new wxButton(RMS_Scroller, wxID_ANY, "Copy", wxDefaultPosition, wxSize(10, -1));
    RMS_Unit_Paste = new wxButton(RMS_Scroller, wxID_ANY, "Paste", wxDefaultPosition, wxSize(10, -1));
    RMS_Unit_PasteInsert = new wxButton(RMS_Scroller, wxID_ANY, "Ins Copies", wxDefaultPosition, wxSize(10, -1));
    RMS_Unit_CopyToMaps = new wxButton(RMS_Scroller, wxID_ANY, "Copy all to selected maps", wxDefaultPosition, wxSize(10, -1));

    RMS_Unit_Unknown1_Grid = new wxFlexGridSizer(4, 5, 5);
    RMS_Unit_Unit_Holder = new wxBoxSizer(wxVERTICAL);
    RMS_Unit_Unit_Text = new SolidText(RMS_Scroller, " Unit");
    RMS_Unit_Unit = new NumberControl(CLong, RMS_Scroller, this, &uiGroupRMUnit, false);
    RMS_Unit_HostTerrain_Holder = new wxBoxSizer(wxVERTICAL);
    RMS_Unit_HostTerrain_Text = new SolidText(RMS_Scroller, " Placement Terrain");
    RMS_Unit_HostTerrain = new NumberControl(CLong, RMS_Scroller, this, &uiGroupRMUnit);
    RMS_Unit_GroupPlacing_Holder = new wxBoxSizer(wxVERTICAL);
    RMS_Unit_GroupPlacing_Text = new SolidText(RMS_Scroller, " Group Mode *");
    RMS_Unit_GroupPlacing = new NumberControl(CUByte, RMS_Scroller, this, &uiGroupRMUnit);
    RMS_Unit_GroupPlacing->SetToolTip("0   Single unit\n1   Place group\n2   Place cluster");
    RMS_Unit_ScaleFlag_Holder = new wxBoxSizer(wxVERTICAL);
    RMS_Unit_ScaleFlag_Text = new SolidText(RMS_Scroller, " Scale by Map Size");
    RMS_Unit_ScaleFlag = new NumberControl(CUByte, RMS_Scroller, this, &uiGroupRMUnit);
    RMS_Unit_ObjectsPerPlayer_Holder = new wxBoxSizer(wxVERTICAL);
    RMS_Unit_ObjectsPerPlayer_Text = new SolidText(RMS_Scroller, " Units per Group");
    RMS_Unit_ObjectsPerPlayer = new NumberControl(CLong, RMS_Scroller, this, &uiGroupRMUnit);
    RMS_Unit_Fluctuation_Holder = new wxBoxSizer(wxVERTICAL);
    RMS_Unit_Fluctuation_Text = new SolidText(RMS_Scroller, " Fluctuation *");
    RMS_Unit_Fluctuation = new NumberControl(CLong, RMS_Scroller, this, &uiGroupRMUnit);
    RMS_Unit_Fluctuation->SetToolTip("Max randomness in the number of units per group");
    RMS_Unit_GroupsPerPlayer_Holder = new wxBoxSizer(wxVERTICAL);
    RMS_Unit_GroupsPerPlayer_Text = new SolidText(RMS_Scroller, " Groups per Player");
    RMS_Unit_GroupsPerPlayer = new NumberControl(CLong, RMS_Scroller, this, &uiGroupRMUnit);
    RMS_Unit_GroupArea_Holder = new wxBoxSizer(wxVERTICAL);
    RMS_Unit_GroupArea_Text = new SolidText(RMS_Scroller, " Group Radius *");
    RMS_Unit_GroupArea = new NumberControl(CLong, RMS_Scroller, this, &uiGroupRMUnit);
    RMS_Unit_GroupArea->SetToolTip("Max distance from the center of the group");
    RMS_Unit_PlayerID_Holder = new wxBoxSizer(wxVERTICAL);
    RMS_Unit_PlayerID_Text = new SolidText(RMS_Scroller, " Player # *");
    RMS_Unit_PlayerID = new NumberControl(CLong, RMS_Scroller, this, &uiGroupRMUnit);
    RMS_Unit_PlayerID->SetToolTip("-1 for every player");
    RMS_Unit_SetPlaceForAllPlayers_Holder = new wxBoxSizer(wxVERTICAL);
    RMS_Unit_SetPlaceForAllPlayers_Text = new SolidText(RMS_Scroller, " Base Land # *");
    RMS_Unit_SetPlaceForAllPlayers = new NumberControl(CLong, RMS_Scroller, this, &uiGroupRMUnit);
    RMS_Unit_SetPlaceForAllPlayers->SetToolTip("0+  Place on all matching lands\n-1   Place anywhere\n-2   Avoid land spots");
    RMS_Unit_MinDistanceToPlayers_Holder = new wxBoxSizer(wxVERTICAL);
    RMS_Unit_MinDistanceToPlayers_Text = new SolidText(RMS_Scroller, " Min Dist to Players");
    RMS_Unit_MinDistanceToPlayers = new NumberControl(CLong, RMS_Scroller, this, &uiGroupRMUnit);
    RMS_Unit_MaxDistanceToPlayers_Holder = new wxBoxSizer(wxVERTICAL);
    RMS_Unit_MaxDistanceToPlayers_Text = new SolidText(RMS_Scroller, " Max Dist to Players *");
    RMS_Unit_MaxDistanceToPlayers = new NumberControl(CLong, RMS_Scroller, this, &uiGroupRMUnit);
    RMS_Unit_MaxDistanceToPlayers->SetToolTip("Don't use 0 here for units that are owned at start.\n0 is okay for other units (gold/bushes/gazelle/etc).\nYou can use -1 as a wildcard for units that are owned at start.");

    RMSUnknown = new wxStaticBoxSizer(wxHORIZONTAL, RMS_Scroller, "Elevations placed on the map (These are ignored)");
    RMS_Elevation_ListArea = new wxBoxSizer(wxVERTICAL);
    RMS_Elevation_Search = new wxTextCtrl(RMS_Scroller, wxID_ANY);
    RMS_Elevation_Search_R = new wxTextCtrl(RMS_Scroller, wxID_ANY);
    RMS_Elevation_ListV = new ProperList(RMS_Scroller, ASize(140, 100));
    RMS_Elevation_Buttons = new wxGridSizer(3, 0, 0);
    RMS_Elevation_Add = new wxButton(RMS_Scroller, wxID_ANY, "Add", wxDefaultPosition, wxSize(10, -1));
    RMS_Elevation_Insert = new wxButton(RMS_Scroller, wxID_ANY, "Ins New", wxDefaultPosition, wxSize(10, -1));
    RMS_Elevation_Delete = new wxButton(RMS_Scroller, wxID_ANY, "Delete", wxDefaultPosition, wxSize(10, -1));
    RMS_Elevation_Copy = new wxButton(RMS_Scroller, wxID_ANY, "Copy", wxDefaultPosition, wxSize(10, -1));
    RMS_Elevation_Paste = new wxButton(RMS_Scroller, wxID_ANY, "Paste", wxDefaultPosition, wxSize(10, -1));
    RMS_Elevation_PasteInsert = new wxButton(RMS_Scroller, wxID_ANY, "Ins Copies", wxDefaultPosition, wxSize(10, -1));
    RMS_Elevation_CopyToMaps = new wxButton(RMS_Scroller, wxID_ANY, "Copy all to selected maps", wxDefaultPosition, wxSize(10, -1));

    RMS_ElevationData_Grid = new wxFlexGridSizer(4, 5, 5);
    for(size_t loop = 0; loop < RMS_ElevationData.size(); ++loop)
    {
        RMS_ElevationData_Holder[loop] = new wxBoxSizer(wxVERTICAL);
        RMS_ElevationData[loop] = new NumberControl(CLong, RMS_Scroller, this, &uiGroupRMUnknown, false);
    }
    RMS_ElevationData_Text[0] = new SolidText(RMS_Scroller, " Proportion *");
    RMS_ElevationData[0]->SetToolTip("% of the total map area");
    RMS_ElevationData_Text[1] = new SolidText(RMS_Scroller, " Terrain");
    RMS_ElevationData_Text[2] = new SolidText(RMS_Scroller, " Clump Count *");
    RMS_ElevationData[2]->SetToolTip("Clusters in the map");
    RMS_ElevationData_Text[3] = new SolidText(RMS_Scroller, " Base Terrain");
    RMS_ElevationData_Text[4] = new SolidText(RMS_Scroller, " Base Elevation");
    RMS_ElevationData_Text[5] = new SolidText(RMS_Scroller, " Tile Spacing");

    Unknowns_Buttons->Add(Unknowns_Add, 1, wxEXPAND);
    Unknowns_Buttons->Add(Unknowns_Delete, 1, wxEXPAND);
    Unknowns_Buttons->Add(Unknowns_Insert, 1, wxEXPAND);
    Unknowns_Buttons->Add(Unknowns_Copy, 1, wxEXPAND);
    Unknowns_Buttons->Add(Unknowns_Paste, 1, wxEXPAND);
    Unknowns_Buttons->Add(Unknowns_PasteInsert, 1, wxEXPAND);

    Unknowns_ListArea->Add(Unknowns_Search, 0, wxEXPAND);
    Unknowns_ListArea->Add(Unknowns_Search_R, 0, wxEXPAND);
    Unknowns_ListArea->Add(Unknowns_ListV, 1, wxEXPAND | wxBOTTOM | wxTOP, 2);
    Unknowns_ListArea->Add(Unknowns_Buttons, 0, wxEXPAND);

    RMS_MapID_Holder->Add(RMS_MapID_Text);
    RMS_MapID_Holder->Add(RMS_MapID);
    RMS_LandData_Grid->Add(RMS_MapID_Holder);
    for(size_t loop = 0; loop < RMS_LandData.size(); ++loop)
    {
        RMS_LandData_Holder[loop]->Add(RMS_LandData_Text[loop]);
        RMS_LandData_Holder[loop]->Add(RMS_LandData[loop]);
        RMS_LandData_Grid->Add(RMS_LandData_Holder[loop]);
    }

    RMS_Land_Buttons->Add(RMS_Land_Add, 1, wxEXPAND);
    RMS_Land_Buttons->Add(RMS_Land_Delete, 1, wxEXPAND);
    RMS_Land_Buttons->Add(RMS_Land_Insert, 1, wxEXPAND);
    RMS_Land_Buttons->Add(RMS_Land_Copy, 1, wxEXPAND);
    RMS_Land_Buttons->Add(RMS_Land_Paste, 1, wxEXPAND);
    RMS_Land_Buttons->Add(RMS_Land_PasteInsert, 1, wxEXPAND);

    RMS_Land_ListArea->Add(RMS_Land_Search, 0, wxEXPAND);
    RMS_Land_ListArea->Add(RMS_Land_Search_R, 0, wxEXPAND);
    RMS_Land_ListArea->Add(RMS_Land_ListV, 1, wxEXPAND | wxBOTTOM | wxTOP, 2);
    RMS_Land_ListArea->Add(RMS_Land_Buttons, 0, wxEXPAND);
    RMS_Land_ListArea->Add(RMS_Land_CopyToMaps, 0, wxEXPAND | wxTOP, 2);

    RMS_Land_LandID_Holder->Add(RMS_Land_LandID_Text);
    RMS_Land_LandID_Holder->Add(RMS_Land_LandID);
    RMS_Land_BaseTerrain_Holder->Add(RMS_Land_BaseTerrain_Text);
    RMS_Land_BaseTerrain_Holder->Add(RMS_Land_BaseTerrain);
    RMS_Land_PlayerSpacing_Holder->Add(RMS_Land_PlayerSpacing_Text);
    RMS_Land_PlayerSpacing_Holder->Add(RMS_Land_PlayerSpacing);
    RMS_Land_BaseSize_Holder->Add(RMS_Land_BaseSize_Text);
    RMS_Land_BaseSize_Holder->Add(RMS_Land_BaseSize);
    RMS_Land_Zone_Holder->Add(RMS_Land_Zone_Text);
    RMS_Land_Zone_Holder->Add(RMS_Land_Zone);
    RMS_Land_PlacementType_Holder->Add(RMS_Land_PlacementType_Text);
    RMS_Land_PlacementType_Holder->Add(RMS_Land_PlacementType);
    RMS_Land_X_Holder->Add(RMS_Land_X_Text);
    RMS_Land_X_Holder->Add(RMS_Land_X);
    RMS_Land_Y_Holder->Add(RMS_Land_Y_Text);
    RMS_Land_Y_Holder->Add(RMS_Land_Y);
    RMS_Land_LandProportion_Holder->Add(RMS_Land_LandProportion_Text);
    RMS_Land_LandProportion_Holder->Add(RMS_Land_LandProportion);
    RMS_Land_ByPlayerFlag_Holder->Add(RMS_Land_ByPlayerFlag_Text);
    RMS_Land_ByPlayerFlag_Holder->Add(RMS_Land_ByPlayerFlag);
    RMS_Land_StartAreaRadius_Holder->Add(RMS_Land_StartAreaRadius_Text);
    RMS_Land_StartAreaRadius_Holder->Add(RMS_Land_StartAreaRadius);
    RMS_Land_TerrainEdgeFade_Holder->Add(RMS_Land_TerrainEdgeFade_Text);
    RMS_Land_TerrainEdgeFade_Holder->Add(RMS_Land_TerrainEdgeFade);
    RMS_Land_Clumpiness_Holder->Add(RMS_Land_Clumpiness_Text);
    RMS_Land_Clumpiness_Holder->Add(RMS_Land_Clumpiness);
    RMS_Land_LandID_Grid->Add(RMS_Land_LandID_Holder);
    RMS_Land_LandID_Grid->Add(RMS_Land_BaseTerrain_Holder);
    RMS_Land_LandID_Grid->Add(RMS_Land_PlayerSpacing_Holder);
    RMS_Land_LandID_Grid->Add(RMS_Land_BaseSize_Holder);
    RMS_Land_LandID_Grid->Add(RMS_Land_Zone_Holder);
    RMS_Land_LandID_Grid->Add(RMS_Land_PlacementType_Holder);
    RMS_Land_LandID_Grid->Add(RMS_Land_X_Holder);
    RMS_Land_LandID_Grid->Add(RMS_Land_Y_Holder);
    RMS_Land_LandID_Grid->Add(RMS_Land_LandProportion_Holder);
    RMS_Land_LandID_Grid->Add(RMS_Land_ByPlayerFlag_Holder);
    RMS_Land_LandID_Grid->Add(RMS_Land_StartAreaRadius_Holder);
    RMS_Land_LandID_Grid->Add(RMS_Land_TerrainEdgeFade_Holder);
    RMS_Land_LandID_Grid->Add(RMS_Land_Clumpiness_Holder);

    RMSMapLands->Add(RMS_Land_ListArea, 1, wxEXPAND);
    RMSMapLands->Add(RMS_Land_LandID_Grid, 3, wxEXPAND | wxLEFT, 5);

    RMS_Terrain_Buttons->Add(RMS_Terrain_Add, 1, wxEXPAND);
    RMS_Terrain_Buttons->Add(RMS_Terrain_Delete, 1, wxEXPAND);
    RMS_Terrain_Buttons->Add(RMS_Terrain_Insert, 1, wxEXPAND);
    RMS_Terrain_Buttons->Add(RMS_Terrain_Copy, 1, wxEXPAND);
    RMS_Terrain_Buttons->Add(RMS_Terrain_Paste, 1, wxEXPAND);
    RMS_Terrain_Buttons->Add(RMS_Terrain_PasteInsert, 1, wxEXPAND);

    RMS_Terrain_ListArea->Add(RMS_Terrain_Search, 0, wxEXPAND);
    RMS_Terrain_ListArea->Add(RMS_Terrain_Search_R, 0, wxEXPAND);
    RMS_Terrain_ListArea->Add(RMS_Terrain_ListV, 1, wxEXPAND | wxBOTTOM | wxTOP, 2);
    RMS_Terrain_ListArea->Add(RMS_Terrain_Buttons, 0, wxEXPAND);
    RMS_Terrain_ListArea->Add(RMS_Terrain_CopyToMaps, 0, wxEXPAND | wxTOP, 2);

    for(size_t loop = 0; loop < RMS_TerrainData.size(); ++loop)
    {
        RMS_TerrainData_Holder[loop]->Add(RMS_TerrainData_Text[loop]);
        RMS_TerrainData_Holder[loop]->Add(RMS_TerrainData[loop]);
        RMS_TerrainData_Grid->Add(RMS_TerrainData_Holder[loop]);
    }

    RMSTerrain->Add(RMS_Terrain_ListArea, 1, wxEXPAND);
    RMSTerrain->Add(RMS_TerrainData_Grid, 3, wxEXPAND | wxLEFT, 5);

    RMS_Unit_Buttons->Add(RMS_Unit_Add, 1, wxEXPAND);
    RMS_Unit_Buttons->Add(RMS_Unit_Delete, 1, wxEXPAND);
    RMS_Unit_Buttons->Add(RMS_Unit_Insert, 1, wxEXPAND);
    RMS_Unit_Buttons->Add(RMS_Unit_Copy, 1, wxEXPAND);
    RMS_Unit_Buttons->Add(RMS_Unit_Paste, 1, wxEXPAND);
    RMS_Unit_Buttons->Add(RMS_Unit_PasteInsert, 1, wxEXPAND);

    RMS_Unit_ListArea->Add(RMS_Unit_Search, 0, wxEXPAND);
    RMS_Unit_ListArea->Add(RMS_Unit_Search_R, 0, wxEXPAND);
    RMS_Unit_ListArea->Add(RMS_Unit_ListV, 1, wxEXPAND | wxBOTTOM | wxTOP, 2);
    RMS_Unit_ListArea->Add(RMS_Unit_Buttons, 0, wxEXPAND);
    RMS_Unit_ListArea->Add(RMS_Unit_CopyToMaps, 0, wxEXPAND | wxTOP, 2);

    RMS_Unit_Unit_Holder->Add(RMS_Unit_Unit_Text);
    RMS_Unit_Unit_Holder->Add(RMS_Unit_Unit);
    RMS_Unit_HostTerrain_Holder->Add(RMS_Unit_HostTerrain_Text);
    RMS_Unit_HostTerrain_Holder->Add(RMS_Unit_HostTerrain);
    RMS_Unit_GroupPlacing_Holder->Add(RMS_Unit_GroupPlacing_Text);
    RMS_Unit_GroupPlacing_Holder->Add(RMS_Unit_GroupPlacing);
    RMS_Unit_ScaleFlag_Holder->Add(RMS_Unit_ScaleFlag_Text);
    RMS_Unit_ScaleFlag_Holder->Add(RMS_Unit_ScaleFlag);
    RMS_Unit_ObjectsPerPlayer_Holder->Add(RMS_Unit_ObjectsPerPlayer_Text);
    RMS_Unit_ObjectsPerPlayer_Holder->Add(RMS_Unit_ObjectsPerPlayer);
    RMS_Unit_Fluctuation_Holder->Add(RMS_Unit_Fluctuation_Text);
    RMS_Unit_Fluctuation_Holder->Add(RMS_Unit_Fluctuation);
    RMS_Unit_GroupsPerPlayer_Holder->Add(RMS_Unit_GroupsPerPlayer_Text);
    RMS_Unit_GroupsPerPlayer_Holder->Add(RMS_Unit_GroupsPerPlayer);
    RMS_Unit_GroupArea_Holder->Add(RMS_Unit_GroupArea_Text);
    RMS_Unit_GroupArea_Holder->Add(RMS_Unit_GroupArea);
    RMS_Unit_PlayerID_Holder->Add(RMS_Unit_PlayerID_Text);
    RMS_Unit_PlayerID_Holder->Add(RMS_Unit_PlayerID);
    RMS_Unit_SetPlaceForAllPlayers_Holder->Add(RMS_Unit_SetPlaceForAllPlayers_Text);
    RMS_Unit_SetPlaceForAllPlayers_Holder->Add(RMS_Unit_SetPlaceForAllPlayers);
    RMS_Unit_MinDistanceToPlayers_Holder->Add(RMS_Unit_MinDistanceToPlayers_Text);
    RMS_Unit_MinDistanceToPlayers_Holder->Add(RMS_Unit_MinDistanceToPlayers);
    RMS_Unit_MaxDistanceToPlayers_Holder->Add(RMS_Unit_MaxDistanceToPlayers_Text);
    RMS_Unit_MaxDistanceToPlayers_Holder->Add(RMS_Unit_MaxDistanceToPlayers);
    RMS_Unit_Unknown1_Grid->Add(RMS_Unit_Unit_Holder);
    RMS_Unit_Unknown1_Grid->Add(RMS_Unit_HostTerrain_Holder);
    RMS_Unit_Unknown1_Grid->Add(RMS_Unit_GroupPlacing_Holder);
    RMS_Unit_Unknown1_Grid->Add(RMS_Unit_ScaleFlag_Holder);
    RMS_Unit_Unknown1_Grid->Add(RMS_Unit_ObjectsPerPlayer_Holder);
    RMS_Unit_Unknown1_Grid->Add(RMS_Unit_Fluctuation_Holder);
    RMS_Unit_Unknown1_Grid->Add(RMS_Unit_GroupsPerPlayer_Holder);
    RMS_Unit_Unknown1_Grid->Add(RMS_Unit_GroupArea_Holder);
    RMS_Unit_Unknown1_Grid->Add(RMS_Unit_PlayerID_Holder);
    RMS_Unit_Unknown1_Grid->Add(RMS_Unit_SetPlaceForAllPlayers_Holder);
    RMS_Unit_Unknown1_Grid->Add(RMS_Unit_MinDistanceToPlayers_Holder);
    RMS_Unit_Unknown1_Grid->Add(RMS_Unit_MaxDistanceToPlayers_Holder);

    RMSUnit->Add(RMS_Unit_ListArea, 1, wxEXPAND);
    RMSUnit->Add(RMS_Unit_Unknown1_Grid, 3, wxEXPAND | wxLEFT, 5);

    RMS_Elevation_Buttons->Add(RMS_Elevation_Add, 1, wxEXPAND);
    RMS_Elevation_Buttons->Add(RMS_Elevation_Delete, 1, wxEXPAND);
    RMS_Elevation_Buttons->Add(RMS_Elevation_Insert, 1, wxEXPAND);
    RMS_Elevation_Buttons->Add(RMS_Elevation_Copy, 1, wxEXPAND);
    RMS_Elevation_Buttons->Add(RMS_Elevation_Paste, 1, wxEXPAND);
    RMS_Elevation_Buttons->Add(RMS_Elevation_PasteInsert, 1, wxEXPAND);

    RMS_Elevation_ListArea->Add(RMS_Elevation_Search, 0, wxEXPAND);
    RMS_Elevation_ListArea->Add(RMS_Elevation_Search_R, 0, wxEXPAND);
    RMS_Elevation_ListArea->Add(RMS_Elevation_ListV, 1, wxEXPAND | wxBOTTOM | wxTOP, 2);
    RMS_Elevation_ListArea->Add(RMS_Elevation_Buttons, 0, wxEXPAND);
    RMS_Elevation_ListArea->Add(RMS_Elevation_CopyToMaps, 0, wxEXPAND | wxTOP, 2);

    for(size_t loop = 0; loop < RMS_ElevationData.size(); ++loop)
    {
        RMS_ElevationData_Holder[loop]->Add(RMS_ElevationData_Text[loop]);
        RMS_ElevationData_Holder[loop]->Add(RMS_ElevationData[loop]);
        RMS_ElevationData_Grid->Add(RMS_ElevationData_Holder[loop]);
    }

    RMSUnknown->Add(RMS_Elevation_ListArea, 1, wxEXPAND);
    RMSUnknown->Add(RMS_ElevationData_Grid, 3, wxEXPAND | wxLEFT, 5);

    Unknown_ScrollSpace->Add(RMS_LandData_Grid, 0, wxEXPAND | wxBOTTOM, 5);
    Unknown_ScrollSpace->Add(RMSMapLands, 0, wxEXPAND | wxBOTTOM, 5);
    Unknown_ScrollSpace->Add(RMSTerrain, 0, wxEXPAND | wxBOTTOM, 5);
    Unknown_ScrollSpace->Add(RMSUnit, 0, wxEXPAND | wxBOTTOM, 5);
    Unknown_ScrollSpace->Add(RMSUnknown, 0, wxEXPAND | wxBOTTOM, 5);

    RMS_Scroller->SetSizer(Unknown_ScrollSpace);
    RMS_Scroller->SetScrollRate(0, 15);

    Unknowns->Add(Unknowns_ListArea, 21, wxEXPAND | wxRIGHT, 5);
    Unknowns->Add(RMS_Scroller, 65, wxEXPAND);

    Unknown_Main->Add(Unknowns, 1, wxEXPAND | wxALL, 5);

    Unknowns_Paste->Enable(false);
    Unknowns_PasteInsert->Enable(false);
    RMS_Land_Paste->Enable(false);
    RMS_Land_PasteInsert->Enable(false);
    RMS_Terrain_Paste->Enable(false);
    RMS_Terrain_PasteInsert->Enable(false);
    RMS_Unit_Paste->Enable(false);
    RMS_Unit_PasteInsert->Enable(false);
    RMS_Elevation_Paste->Enable(false);
    RMS_Elevation_PasteInsert->Enable(false);

    Tab_Unknown->SetSizer(Unknown_Main);

    Unknowns_Search->Bind(wxEVT_TEXT, &AGE_Frame::OnRandomMapSearch, this);
    Unknowns_Search_R->Bind(wxEVT_TEXT, &AGE_Frame::OnRandomMapSearch, this);
    Unknowns_ListV->Bind(wxEVT_LISTBOX, &AGE_Frame::OnRandomMapSelect, this);
    Unknowns_Add->Bind(wxEVT_BUTTON, &AGE_Frame::OnRandomMapAdd, this);
    Unknowns_Insert->Bind(wxEVT_BUTTON, &AGE_Frame::OnRandomMapInsert, this);
    Unknowns_Delete->Bind(wxEVT_BUTTON, &AGE_Frame::OnRandomMapDelete, this);
    Unknowns_Copy->Bind(wxEVT_BUTTON, &AGE_Frame::OnRandomMapCopy, this);
    Unknowns_Paste->Bind(wxEVT_BUTTON, &AGE_Frame::OnRandomMapPaste, this);
    Unknowns_PasteInsert->Bind(wxEVT_BUTTON, &AGE_Frame::OnRandomMapPasteInsert, this);
    RMS_Land_Search->Bind(wxEVT_TEXT, &AGE_Frame::OnMapLandSearch, this);
    RMS_Land_Search_R->Bind(wxEVT_TEXT, &AGE_Frame::OnMapLandSearch, this);
    RMS_Land_ListV->Bind(wxEVT_LISTBOX, &AGE_Frame::OnMapLandSelect, this);
    RMS_Land_Add->Bind(wxEVT_BUTTON, &AGE_Frame::OnMapLandAdd, this);
    RMS_Land_Insert->Bind(wxEVT_BUTTON, &AGE_Frame::OnMapLandInsert, this);
    RMS_Land_Delete->Bind(wxEVT_BUTTON, &AGE_Frame::OnMapLandDelete, this);
    RMS_Land_Copy->Bind(wxEVT_BUTTON, &AGE_Frame::OnMapLandCopy, this);
    RMS_Land_Paste->Bind(wxEVT_BUTTON, &AGE_Frame::OnMapLandPaste, this);
    RMS_Land_PasteInsert->Bind(wxEVT_BUTTON, &AGE_Frame::OnMapLandPasteInsert, this);
    RMS_Land_CopyToMaps->Bind(wxEVT_BUTTON, &AGE_Frame::OnMapLandCopyToMaps, this);
    RMS_Terrain_Search->Bind(wxEVT_TEXT, &AGE_Frame::OnMapTerrainSearch, this);
    RMS_Terrain_Search_R->Bind(wxEVT_TEXT, &AGE_Frame::OnMapTerrainSearch, this);
    RMS_Terrain_ListV->Bind(wxEVT_LISTBOX, &AGE_Frame::OnMapTerrainSelect, this);
    RMS_Terrain_Add->Bind(wxEVT_BUTTON, &AGE_Frame::OnMapTerrainAdd, this);
    RMS_Terrain_Insert->Bind(wxEVT_BUTTON, &AGE_Frame::OnMapTerrainInsert, this);
    RMS_Terrain_Delete->Bind(wxEVT_BUTTON, &AGE_Frame::OnMapTerrainDelete, this);
    RMS_Terrain_Copy->Bind(wxEVT_BUTTON, &AGE_Frame::OnMapTerrainCopy, this);
    RMS_Terrain_Paste->Bind(wxEVT_BUTTON, &AGE_Frame::OnMapTerrainPaste, this);
    RMS_Terrain_PasteInsert->Bind(wxEVT_BUTTON, &AGE_Frame::OnMapTerrainPasteInsert, this);
    RMS_Terrain_CopyToMaps->Bind(wxEVT_BUTTON, &AGE_Frame::OnMapTerrainCopyToMaps, this);
    RMS_Unit_Search->Bind(wxEVT_TEXT, &AGE_Frame::OnMapUnitSearch, this);
    RMS_Unit_Search_R->Bind(wxEVT_TEXT, &AGE_Frame::OnMapUnitSearch, this);
    RMS_Unit_ListV->Bind(wxEVT_LISTBOX, &AGE_Frame::OnMapUnitSelect, this);
    RMS_Unit_Add->Bind(wxEVT_BUTTON, &AGE_Frame::OnMapUnitAdd, this);
    RMS_Unit_Insert->Bind(wxEVT_BUTTON, &AGE_Frame::OnMapUnitInsert, this);
    RMS_Unit_Delete->Bind(wxEVT_BUTTON, &AGE_Frame::OnMapUnitDelete, this);
    RMS_Unit_Copy->Bind(wxEVT_BUTTON, &AGE_Frame::OnMapUnitCopy, this);
    RMS_Unit_Paste->Bind(wxEVT_BUTTON, &AGE_Frame::OnMapUnitPaste, this);
    RMS_Unit_PasteInsert->Bind(wxEVT_BUTTON, &AGE_Frame::OnMapUnitPasteInsert, this);
    RMS_Unit_CopyToMaps->Bind(wxEVT_BUTTON, &AGE_Frame::OnMapUnitCopyToMaps, this);
    RMS_Elevation_Search->Bind(wxEVT_TEXT, &AGE_Frame::OnMapElevationSearch, this);
    RMS_Elevation_Search_R->Bind(wxEVT_TEXT, &AGE_Frame::OnMapElevationSearch, this);
    RMS_Elevation_ListV->Bind(wxEVT_LISTBOX, &AGE_Frame::OnMapElevationSelect, this);
    RMS_Elevation_Add->Bind(wxEVT_BUTTON, &AGE_Frame::OnMapElevationAdd, this);
    RMS_Elevation_Insert->Bind(wxEVT_BUTTON, &AGE_Frame::OnMapElevationInsert, this);
    RMS_Elevation_Delete->Bind(wxEVT_BUTTON, &AGE_Frame::OnMapElevationDelete, this);
    RMS_Elevation_Copy->Bind(wxEVT_BUTTON, &AGE_Frame::OnMapElevationCopy, this);
    RMS_Elevation_Paste->Bind(wxEVT_BUTTON, &AGE_Frame::OnMapElevationPaste, this);
    RMS_Elevation_PasteInsert->Bind(wxEVT_BUTTON, &AGE_Frame::OnMapElevationPasteInsert, this);
    RMS_Elevation_CopyToMaps->Bind(wxEVT_BUTTON, &AGE_Frame::OnMapElevationCopyToMaps, this);

    RMS_MapID->Bind(wxEVT_KILL_FOCUS, [this](wxFocusEvent& event)
    {
        event.Skip();
        if (static_cast<AGETextCtrl*>(event.GetEventObject())->SaveEdits() == 0)
        {
            ListRandomMaps();
        }
    });
    RMS_MapID->Bind(wxEVT_TEXT_ENTER, [this](wxCommandEvent& event)
    {
        static_cast<AGETextCtrl*>(event.GetEventObject())->SaveEdits(true);
        ListRandomMaps();
    });
    RMS_Land_LandID->Bind(wxEVT_KILL_FOCUS, [this](wxFocusEvent& event)
    {
        event.Skip();
        if (static_cast<AGETextCtrl*>(event.GetEventObject())->SaveEdits() == 0)
        {
            ListMapLands();
        }
    });
    RMS_Land_LandID->Bind(wxEVT_TEXT_ENTER, [this](wxCommandEvent& event)
    {
        static_cast<AGETextCtrl*>(event.GetEventObject())->SaveEdits(true);
        ListMapLands();
    });
    RMS_TerrainData[1]->Bind(wxEVT_KILL_FOCUS, [this](wxFocusEvent& event)
    {
        event.Skip();
        if (static_cast<AGETextCtrl*>(event.GetEventObject())->SaveEdits() == 0)
        {
            ListMapTerrains();
        }
    });
    RMS_TerrainData[1]->Bind(wxEVT_TEXT_ENTER, [this](wxCommandEvent& event)
    {
        static_cast<AGETextCtrl*>(event.GetEventObject())->SaveEdits(true);
        ListMapTerrains();
    });
    RMS_ElevationData[1]->Bind(wxEVT_KILL_FOCUS, [this](wxFocusEvent& event)
    {
        event.Skip();
        if (static_cast<AGETextCtrl*>(event.GetEventObject())->SaveEdits() == 0)
        {
            ListMapElevations();
        }
    });
    RMS_ElevationData[1]->Bind(wxEVT_TEXT_ENTER, [this](wxCommandEvent& event)
    {
        static_cast<AGETextCtrl*>(event.GetEventObject())->SaveEdits(true);
        ListMapElevations();
    });
    RMS_Unit_Unit->Bind(wxEVT_KILL_FOCUS, [this](wxFocusEvent& event)
    {
        event.Skip();
        if (static_cast<AGETextCtrl*>(event.GetEventObject())->SaveEdits() == 0)
        {
            ListMapUnits();
        }
    });
    RMS_Unit_Unit->Bind(wxEVT_TEXT_ENTER, [this](wxCommandEvent& event)
    {
        static_cast<AGETextCtrl*>(event.GetEventObject())->SaveEdits(true);
        ListMapUnits();
    });
}
