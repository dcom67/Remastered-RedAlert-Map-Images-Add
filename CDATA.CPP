//
// Copyright 2020 Electronic Arts Inc.
//
// TiberianDawn.DLL and RedAlert.dll and corresponding source code is free 
// software: you can redistribute it and/or modify it under the terms of 
// the GNU General Public License as published by the Free Software Foundation, 
// either version 3 of the License, or (at your option) any later version.

// TiberianDawn.DLL and RedAlert.dll and corresponding source code is distributed 
// in the hope that it will be useful, but with permitted additional restrictions 
// under Section 7 of the GPL. See the GNU General Public License in LICENSE.TXT 
// distributed with this program. You should have received a copy of the 
// GNU General Public License along with permitted additional restrictions 
// with this program. If not, see https://github.com/electronicarts/CnC_Remastered_Collection

/* $Header: /CounterStrike/CDATA.CPP 1     3/03/97 10:24a Joe_bostic $ */
/***********************************************************************************************
 ***              C O N F I D E N T I A L  ---  W E S T W O O D  S T U D I O S               ***
 ***********************************************************************************************
 *                                                                                             *
 *                 Project Name : Command & Conquer                                            *
 *                                                                                             *
 *                    File Name : CDATA.CPP                                                    *
 *                                                                                             *
 *                   Programmer : Joe L. Bostic                                                *
 *                                                                                             *
 *                   Start Date : May 16, 1994                                                 *
 *                                                                                             *
 *                  Last Update : July 6, 1996 [JLB]                                           *
 *                                                                                             *
 *---------------------------------------------------------------------------------------------*
 * Functions:                                                                                  *
 *   TemplateTypeClass::As_Reference -- Fetches a reference to the template specified.         *
 *   TemplateTypeClass::Create_And_Place -- Creates and places a template object on the map.   *
 *   TemplateTypeClass::Create_One_Of -- Creates an object of this template type.              *
 *   TemplateTypeClass::Display -- Displays a generic representation of template.              *
 *   TemplateTypeClass::From_Name -- Determine template from ASCII name.                       *
 *   TemplateTypeClass::Init -- Loads graphic data for templates.                              *
 *   TemplateTypeClass::Land_Type -- Determines land type from template and icon number.       *
 *   TemplateTypeClass::Occupy_List -- Determines occupation list.                             *
 *   TemplateTypeClass::One_Time -- Performs one-time initialization                           *
 *   TemplateTypeClass::Prep_For_Add -- Prepares to add template to scenario.                  *
 *   TemplateTypeClass::TemplateTypeClass -- Constructor for template type objects.            *
 *   TemplateTypeClass::operator delete -- Deletes a template type object.                     *
 *   TemplateTypeClass::operator new -- Allocates a template type from special heap.           *
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#include	"function.h"


static TemplateTypeClass const Empty(
	TEMPLATE_CLEAR1,
	THEATERF_TEMPERATE|THEATERF_SNOW|THEATERF_INTERIOR,
	"CLEAR1",
	TXT_CLEAR
);
static TemplateTypeClass const Clear(
	TEMPLATE_CLEAR1,
	THEATERF_TEMPERATE|THEATERF_SNOW|THEATERF_INTERIOR,
	"CLEAR1",
	TXT_CLEAR
);
static TemplateTypeClass const Road01(
	TEMPLATE_ROAD01,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"D01",
	TXT_ROAD
);
static TemplateTypeClass const Road02(
	TEMPLATE_ROAD02,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"D02",
	TXT_ROAD
);
static TemplateTypeClass const Road03(
	TEMPLATE_ROAD03,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"D03",
	TXT_ROAD
);
static TemplateTypeClass const Road04(
	TEMPLATE_ROAD04,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"D04",
	TXT_ROAD
);
static TemplateTypeClass const Road05(
	TEMPLATE_ROAD05,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"D05",
	TXT_ROAD
);
static TemplateTypeClass const Road06(
	TEMPLATE_ROAD06,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"D06",
	TXT_ROAD
);
static TemplateTypeClass const Road07(
	TEMPLATE_ROAD07,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"D07",
	TXT_ROAD
);
static TemplateTypeClass const Road08(
	TEMPLATE_ROAD08,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"D08",
	TXT_ROAD
);
static TemplateTypeClass const Road09(
	TEMPLATE_ROAD09,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"D09",
	TXT_ROAD
);
static TemplateTypeClass const Road10(
	TEMPLATE_ROAD10,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"D10",
	TXT_ROAD
);
static TemplateTypeClass const Road11(
	TEMPLATE_ROAD11,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"D11",
	TXT_ROAD
);
static TemplateTypeClass const Road12(
	TEMPLATE_ROAD12,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"D12",
	TXT_ROAD
);
static TemplateTypeClass const Road13(
	TEMPLATE_ROAD13,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"D13",
	TXT_ROAD
);
static TemplateTypeClass const Road14(
	TEMPLATE_ROAD14,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"D14",
	TXT_ROAD
);
static TemplateTypeClass const Road15(
	TEMPLATE_ROAD15,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"D15",
	TXT_ROAD
);
static TemplateTypeClass const Road16(
	TEMPLATE_ROAD16,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"D16",
	TXT_ROAD
);
static TemplateTypeClass const Road17(
	TEMPLATE_ROAD17,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"D17",
	TXT_ROAD
);
static TemplateTypeClass const Road18(
	TEMPLATE_ROAD18,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"D18",
	TXT_ROAD
);
static TemplateTypeClass const Road19(
	TEMPLATE_ROAD19,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"D19",
	TXT_ROAD
);
static TemplateTypeClass const Road20(
	TEMPLATE_ROAD20,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"D20",
	TXT_ROAD
);
static TemplateTypeClass const Road21(
	TEMPLATE_ROAD21,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"D21",
	TXT_ROAD
);
static TemplateTypeClass const Road22(
	TEMPLATE_ROAD22,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"D22",
	TXT_ROAD
);
static TemplateTypeClass const Road23(
	TEMPLATE_ROAD23,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"D23",
	TXT_ROAD
);
static TemplateTypeClass const Road24(
	TEMPLATE_ROAD24,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"D24",
	TXT_ROAD
);
static TemplateTypeClass const Road25(
	TEMPLATE_ROAD25,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"D25",
	TXT_ROAD
);
static TemplateTypeClass const Road26(
	TEMPLATE_ROAD26,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"D26",
	TXT_ROAD
);
static TemplateTypeClass const Road27(
	TEMPLATE_ROAD27,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"D27",
	TXT_ROAD
);
static TemplateTypeClass const Road28(
	TEMPLATE_ROAD28,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"D28",
	TXT_ROAD
);
static TemplateTypeClass const Road29(
	TEMPLATE_ROAD29,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"D29",
	TXT_ROAD
);
static TemplateTypeClass const Road30(
	TEMPLATE_ROAD30,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"D30",
	TXT_ROAD
);
static TemplateTypeClass const Road31(
	TEMPLATE_ROAD31,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"D31",
	TXT_ROAD
);
static TemplateTypeClass const Road32(
	TEMPLATE_ROAD32,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"D32",
	TXT_ROAD
);
static TemplateTypeClass const Road33(
	TEMPLATE_ROAD33,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"D33",
	TXT_ROAD
);
static TemplateTypeClass const Road34(
	TEMPLATE_ROAD34,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"D34",
	TXT_ROAD
);
static TemplateTypeClass const Road35(
	TEMPLATE_ROAD35,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"D35",
	TXT_ROAD
);
static TemplateTypeClass const Road36(
	TEMPLATE_ROAD36,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"D36",
	TXT_ROAD
);
static TemplateTypeClass const Road37(
	TEMPLATE_ROAD37,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"D37",
	TXT_ROAD
);
static TemplateTypeClass const Road38(
	TEMPLATE_ROAD38,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"D38",
	TXT_ROAD
);
static TemplateTypeClass const Road39(
	TEMPLATE_ROAD39,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"D39",
	TXT_ROAD
);
static TemplateTypeClass const Road40(
	TEMPLATE_ROAD40,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"D40",
	TXT_ROAD
);
static TemplateTypeClass const Road41(
	TEMPLATE_ROAD41,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"D41",
	TXT_ROAD
);
static TemplateTypeClass const Road42(
	TEMPLATE_ROAD42,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"D42",
	TXT_ROAD
);
static TemplateTypeClass const Road43(
	TEMPLATE_ROAD43,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"D43",
	TXT_ROAD
);
static TemplateTypeClass const Road44(
	TEMPLATE_ROAD44,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"D44",
	TXT_ROAD
);
static TemplateTypeClass const Road45(
	TEMPLATE_ROAD45,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"D45",
	TXT_ROAD
);
static TemplateTypeClass const Water(
	TEMPLATE_WATER,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"W1",
	TXT_WATER
);
static TemplateTypeClass const Water2(
	TEMPLATE_WATER2,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"W2",
	TXT_WATER
);
static TemplateTypeClass const Shore01(
	TEMPLATE_SHORE01,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"SH01",
	TXT_SHORE
);
static TemplateTypeClass const Shore02(
	TEMPLATE_SHORE02,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"SH02",
	TXT_SHORE
);
static TemplateTypeClass const Shore03(
	TEMPLATE_SHORE03,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"SH03",
	TXT_SHORE
);
static TemplateTypeClass const Shore04(
	TEMPLATE_SHORE04,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"SH04",
	TXT_SHORE
);
static TemplateTypeClass const Shore05(
	TEMPLATE_SHORE05,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"SH05",
	TXT_SHORE
);
static TemplateTypeClass const Shore06(
	TEMPLATE_SHORE06,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"SH06",
	TXT_SHORE
);
static TemplateTypeClass const Shore07(
	TEMPLATE_SHORE07,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"SH07",
	TXT_SHORE
);
static TemplateTypeClass const Shore08(
	TEMPLATE_SHORE08,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"SH08",
	TXT_SHORE
);
static TemplateTypeClass const Shore09(
	TEMPLATE_SHORE09,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"SH09",
	TXT_SHORE
);
static TemplateTypeClass const Shore10(
	TEMPLATE_SHORE10,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"SH10",
	TXT_SHORE
);
static TemplateTypeClass const Shore11(
	TEMPLATE_SHORE11,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"SH11",
	TXT_SHORE
);
static TemplateTypeClass const Shore12(
	TEMPLATE_SHORE12,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"SH12",
	TXT_SHORE
);
static TemplateTypeClass const Shore13(
	TEMPLATE_SHORE13,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"SH13",
	TXT_SHORE
);
static TemplateTypeClass const Shore14(
	TEMPLATE_SHORE14,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"SH14",
	TXT_SHORE
);
static TemplateTypeClass const Shore15(
	TEMPLATE_SHORE15,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"SH15",
	TXT_SHORE
);
static TemplateTypeClass const Shore16(
	TEMPLATE_SHORE16,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"SH16",
	TXT_SHORE
);
static TemplateTypeClass const Shore17(
	TEMPLATE_SHORE17,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"SH17",
	TXT_SHORE
);
static TemplateTypeClass const Shore18(
	TEMPLATE_SHORE18,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"SH18",
	TXT_SHORE
);
static TemplateTypeClass const Shore19(
	TEMPLATE_SHORE19,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"SH19",
	TXT_SHORE
);
static TemplateTypeClass const Shore20(
	TEMPLATE_SHORE20,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"SH20",
	TXT_SHORE
);
static TemplateTypeClass const Shore21(
	TEMPLATE_SHORE21,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"SH21",
	TXT_SHORE
);
static TemplateTypeClass const Shore22(
	TEMPLATE_SHORE22,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"SH22",
	TXT_SHORE
);
static TemplateTypeClass const Shore23(
	TEMPLATE_SHORE23,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"SH23",
	TXT_SHORE
);
static TemplateTypeClass const Shore24(
	TEMPLATE_SHORE24,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"SH24",
	TXT_SHORE
);
static TemplateTypeClass const Shore25(
	TEMPLATE_SHORE25,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"SH25",
	TXT_SHORE
);
static TemplateTypeClass const Shore26(
	TEMPLATE_SHORE26,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"SH26",
	TXT_SHORE
);
static TemplateTypeClass const Shore27(
	TEMPLATE_SHORE27,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"SH27",
	TXT_SHORE
);
static TemplateTypeClass const Shore28(
	TEMPLATE_SHORE28,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"SH28",
	TXT_SHORE
);
static TemplateTypeClass const Shore29(
	TEMPLATE_SHORE29,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"SH29",
	TXT_SHORE
);
static TemplateTypeClass const Shore30(
	TEMPLATE_SHORE30,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"SH30",
	TXT_SHORE
);
static TemplateTypeClass const Shore31(
	TEMPLATE_SHORE31,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"SH31",
	TXT_SHORE
);
static TemplateTypeClass const Shore32(
	TEMPLATE_SHORE32,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"SH32",
	TXT_SHORE
);
static TemplateTypeClass const Shore33(
	TEMPLATE_SHORE33,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"SH33",
	TXT_SHORE
);
static TemplateTypeClass const Shore34(
	TEMPLATE_SHORE34,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"SH34",
	TXT_SHORE
);
static TemplateTypeClass const Shore35(
	TEMPLATE_SHORE35,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"SH35",
	TXT_SHORE
);
static TemplateTypeClass const Shore36(
	TEMPLATE_SHORE36,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"SH36",
	TXT_SHORE
);
static TemplateTypeClass const Shore37(
	TEMPLATE_SHORE37,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"SH37",
	TXT_SHORE
);
static TemplateTypeClass const Shore38(
	TEMPLATE_SHORE38,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"SH38",
	TXT_SHORE
);
static TemplateTypeClass const Shore39(
	TEMPLATE_SHORE39,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"SH39",
	TXT_SHORE
);
static TemplateTypeClass const Shore40(
	TEMPLATE_SHORE40,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"SH40",
	TXT_SHORE
);
static TemplateTypeClass const Shore41(
	TEMPLATE_SHORE41,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"SH41",
	TXT_SHORE
);
static TemplateTypeClass const Shore42(
	TEMPLATE_SHORE42,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"SH42",
	TXT_SHORE
);
static TemplateTypeClass const Shore43(
	TEMPLATE_SHORE43,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"SH43",
	TXT_SHORE
);
static TemplateTypeClass const Shore44(
	TEMPLATE_SHORE44,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"SH44",
	TXT_SHORE
);
static TemplateTypeClass const Shore45(
	TEMPLATE_SHORE45,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"SH45",
	TXT_SHORE
);
static TemplateTypeClass const Shore46(
	TEMPLATE_SHORE46,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"SH46",
	TXT_SHORE
);
static TemplateTypeClass const Shore47(
	TEMPLATE_SHORE47,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"SH47",
	TXT_SHORE
);
static TemplateTypeClass const Shore48(
	TEMPLATE_SHORE48,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"SH48",
	TXT_SHORE
);
static TemplateTypeClass const Shore49(
	TEMPLATE_SHORE49,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"SH49",
	TXT_SHORE
);
static TemplateTypeClass const Shore50(
	TEMPLATE_SHORE50,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"SH50",
	TXT_SHORE
);
static TemplateTypeClass const Shore51(
	TEMPLATE_SHORE51,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"SH51",
	TXT_SHORE
);
static TemplateTypeClass const Shore52(
	TEMPLATE_SHORE52,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"SH52",
	TXT_SHORE
);
static TemplateTypeClass const Shore53(
	TEMPLATE_SHORE53,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"SH53",
	TXT_SHORE
);
static TemplateTypeClass const Shore54(
	TEMPLATE_SHORE54,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"SH54",
	TXT_SHORE
);
static TemplateTypeClass const Shore55(
	TEMPLATE_SHORE55,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"SH55",
	TXT_SHORE
);
static TemplateTypeClass const Shore56(
	TEMPLATE_SHORE56,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"SH56",
	TXT_SHORE
);
static TemplateTypeClass const Boulder1(
	TEMPLATE_BOULDER1,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"B1",
	TXT_SLOPE
);
static TemplateTypeClass const Boulder2(
	TEMPLATE_BOULDER2,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"B2",
	TXT_SLOPE
);
static TemplateTypeClass const Boulder3(
	TEMPLATE_BOULDER3,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"B3",
	TXT_SLOPE
);
static TemplateTypeClass const Boulder4(
	TEMPLATE_BOULDER4,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"B4",
	TXT_SLOPE
);
static TemplateTypeClass const Boulder5(
	TEMPLATE_BOULDER5,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"B5",
	TXT_SLOPE
);
static TemplateTypeClass const Boulder6(
	TEMPLATE_BOULDER6,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"B6",
	TXT_SLOPE
);
static TemplateTypeClass const Slope01(
	TEMPLATE_SLOPE01,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"S01",
	TXT_SLOPE
);
static TemplateTypeClass const Slope02(
	TEMPLATE_SLOPE02,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"S02",
	TXT_SLOPE
);
static TemplateTypeClass const Slope03(
	TEMPLATE_SLOPE03,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"S03",
	TXT_SLOPE
);
static TemplateTypeClass const Slope04(
	TEMPLATE_SLOPE04,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"S04",
	TXT_SLOPE
);
static TemplateTypeClass const Slope05(
	TEMPLATE_SLOPE05,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"S05",
	TXT_SLOPE
);
static TemplateTypeClass const Slope06(
	TEMPLATE_SLOPE06,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"S06",
	TXT_SLOPE
);
static TemplateTypeClass const Slope07(
	TEMPLATE_SLOPE07,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"S07",
	TXT_SLOPE
);
static TemplateTypeClass const Slope08(
	TEMPLATE_SLOPE08,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"S08",
	TXT_SLOPE
);
static TemplateTypeClass const Slope09(
	TEMPLATE_SLOPE09,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"S09",
	TXT_SLOPE
);
static TemplateTypeClass const Slope10(
	TEMPLATE_SLOPE10,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"S10",
	TXT_SLOPE
);
static TemplateTypeClass const Slope11(
	TEMPLATE_SLOPE11,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"S11",
	TXT_SLOPE
);
static TemplateTypeClass const Slope12(
	TEMPLATE_SLOPE12,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"S12",
	TXT_SLOPE
);
static TemplateTypeClass const Slope13(
	TEMPLATE_SLOPE13,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"S13",
	TXT_SLOPE
);
static TemplateTypeClass const Slope14(
	TEMPLATE_SLOPE14,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"S14",
	TXT_SLOPE
);
static TemplateTypeClass const Slope15(
	TEMPLATE_SLOPE15,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"S15",
	TXT_SLOPE
);
static TemplateTypeClass const Slope16(
	TEMPLATE_SLOPE16,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"S16",
	TXT_SLOPE
);
static TemplateTypeClass const Slope17(
	TEMPLATE_SLOPE17,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"S17",
	TXT_SLOPE
);
static TemplateTypeClass const Slope18(
	TEMPLATE_SLOPE18,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"S18",
	TXT_SLOPE
);
static TemplateTypeClass const Slope19(
	TEMPLATE_SLOPE19,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"S19",
	TXT_SLOPE
);
static TemplateTypeClass const Slope20(
	TEMPLATE_SLOPE20,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"S20",
	TXT_SLOPE
);
static TemplateTypeClass const Slope21(
	TEMPLATE_SLOPE21,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"S21",
	TXT_SLOPE
);
static TemplateTypeClass const Slope22(
	TEMPLATE_SLOPE22,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"S22",
	TXT_SLOPE
);
static TemplateTypeClass const Slope23(
	TEMPLATE_SLOPE23,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"S23",
	TXT_SLOPE
);
static TemplateTypeClass const Slope24(
	TEMPLATE_SLOPE24,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"S24",
	TXT_SLOPE
);
static TemplateTypeClass const Slope25(
	TEMPLATE_SLOPE25,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"S25",
	TXT_SLOPE
);
static TemplateTypeClass const Slope26(
	TEMPLATE_SLOPE26,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"S26",
	TXT_SLOPE
);
static TemplateTypeClass const Slope27(
	TEMPLATE_SLOPE27,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"S27",
	TXT_SLOPE
);
static TemplateTypeClass const Slope28(
	TEMPLATE_SLOPE28,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"S28",
	TXT_SLOPE
);
static TemplateTypeClass const Slope29(
	TEMPLATE_SLOPE29,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"S29",
	TXT_SLOPE
);
static TemplateTypeClass const Slope30(
	TEMPLATE_SLOPE30,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"S30",
	TXT_SLOPE
);
static TemplateTypeClass const Slope31(
	TEMPLATE_SLOPE31,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"S31",
	TXT_SLOPE
);
static TemplateTypeClass const Slope32(
	TEMPLATE_SLOPE32,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"S32",
	TXT_SLOPE
);
static TemplateTypeClass const Slope33(
	TEMPLATE_SLOPE33,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"S33",
	TXT_SLOPE
);
static TemplateTypeClass const Slope34(
	TEMPLATE_SLOPE34,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"S34",
	TXT_SLOPE
);
static TemplateTypeClass const Slope35(
	TEMPLATE_SLOPE35,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"S35",
	TXT_SLOPE
);
static TemplateTypeClass const Slope36(
	TEMPLATE_SLOPE36,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"S36",
	TXT_SLOPE
);
static TemplateTypeClass const Slope37(
	TEMPLATE_SLOPE37,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"S37",
	TXT_SLOPE
);
static TemplateTypeClass const Slope38(
	TEMPLATE_SLOPE38,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"S38",
	TXT_SLOPE
);
static TemplateTypeClass const Patch01(
	TEMPLATE_PATCH01,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"P01",
	TXT_PATCH
);
static TemplateTypeClass const Patch02(
	TEMPLATE_PATCH02,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"P02",
	TXT_PATCH
);
static TemplateTypeClass const Patch03(
	TEMPLATE_PATCH03,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"P03",
	TXT_PATCH
);
static TemplateTypeClass const Patch04(
	TEMPLATE_PATCH04,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"P04",
	TXT_PATCH
);
static TemplateTypeClass const Patch07(
	TEMPLATE_PATCH07,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"P07",
	TXT_PATCH
);
static TemplateTypeClass const Patch08(
	TEMPLATE_PATCH08,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"P08",
	TXT_PATCH
);
static TemplateTypeClass const Patch13(
	TEMPLATE_PATCH13,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"P13",
	TXT_PATCH
);
static TemplateTypeClass const Patch14(
	TEMPLATE_PATCH14,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"P14",
	TXT_PATCH
);
static TemplateTypeClass const Patch15(
	TEMPLATE_PATCH15,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"P15",
	TXT_PATCH
);
static TemplateTypeClass const River01(
	TEMPLATE_RIVER01,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"RV01",
	TXT_RIVER
);
static TemplateTypeClass const River02(
	TEMPLATE_RIVER02,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"RV02",
	TXT_RIVER
);
static TemplateTypeClass const River03(
	TEMPLATE_RIVER03,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"RV03",
	TXT_RIVER
);
static TemplateTypeClass const River04(
	TEMPLATE_RIVER04,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"RV04",
	TXT_RIVER
);
static TemplateTypeClass const River05(
	TEMPLATE_RIVER05,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"RV05",
	TXT_RIVER
);
static TemplateTypeClass const River06(
	TEMPLATE_RIVER06,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"RV06",
	TXT_RIVER
);
static TemplateTypeClass const River07(
	TEMPLATE_RIVER07,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"RV07",
	TXT_RIVER
);
static TemplateTypeClass const River08(
	TEMPLATE_RIVER08,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"RV08",
	TXT_RIVER
);
static TemplateTypeClass const River09(
	TEMPLATE_RIVER09,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"RV09",
	TXT_RIVER
);
static TemplateTypeClass const River10(
	TEMPLATE_RIVER10,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"RV10",
	TXT_RIVER
);
static TemplateTypeClass const River11(
	TEMPLATE_RIVER11,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"RV11",
	TXT_RIVER
);
static TemplateTypeClass const River12(
	TEMPLATE_RIVER12,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"RV12",
	TXT_RIVER
);
static TemplateTypeClass const River13(
	TEMPLATE_RIVER13,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"RV13",
	TXT_RIVER
);
static TemplateTypeClass const River14(
	TEMPLATE_RIVER14,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"RV14",
	TXT_RIVER
);
static TemplateTypeClass const River15(
	TEMPLATE_RIVER15,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"RV15",
	TXT_RIVER
);
static TemplateTypeClass const Ford1(
	TEMPLATE_FORD1,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"FORD1",
	TXT_RIVER
);
static TemplateTypeClass const Ford2(
	TEMPLATE_FORD2,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"FORD2",
	TXT_RIVER
);
static TemplateTypeClass const Falls1(
	TEMPLATE_FALLS1,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"FALLS1",
	TXT_RIVER
);
static TemplateTypeClass const Falls1a(
	TEMPLATE_FALLS1A,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"FALLS1A",
	TXT_RIVER
);
static TemplateTypeClass const Falls2(
	TEMPLATE_FALLS2,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"FALLS2",
	TXT_RIVER
);
static TemplateTypeClass const Falls2a(
	TEMPLATE_FALLS2A,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"FALLS2A",
	TXT_RIVER
);
static TemplateTypeClass const Bridge1x(
	TEMPLATE_BRIDGE1X,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"BRIDGE1X",
	TXT_BRIDGE
);
static TemplateTypeClass const Bridge1(
	TEMPLATE_BRIDGE1,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"BRIDGE1",
	TXT_BRIDGE
);
static TemplateTypeClass const Bridge1h(
	TEMPLATE_BRIDGE1H,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"BRIDGE1H",
	TXT_BRIDGE
);
static TemplateTypeClass const Bridge1d(
	TEMPLATE_BRIDGE1D,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"BRIDGE1D",
	TXT_BRIDGE
);
static TemplateTypeClass const Bridge2x(
	TEMPLATE_BRIDGE2X,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"BRIDGE2X",
	TXT_BRIDGE
);
static TemplateTypeClass const Bridge2(
	TEMPLATE_BRIDGE2,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"BRIDGE2",
	TXT_BRIDGE
);
static TemplateTypeClass const Bridge2h(
	TEMPLATE_BRIDGE2H,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"BRIDGE2H",
	TXT_BRIDGE
);
static TemplateTypeClass const Bridge2d(
	TEMPLATE_BRIDGE2D,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"BRIDGE2D",
	TXT_BRIDGE
);
static TemplateTypeClass const Bridge1ax(
	TEMPLATE_BRIDGE_1AX,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"BR1X",
	TXT_BRIDGE
);
static TemplateTypeClass const Bridge1a(
	TEMPLATE_BRIDGE_1A,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"BR1A",
	TXT_BRIDGE
);
static TemplateTypeClass const Bridge1b(
	TEMPLATE_BRIDGE_1B,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"BR1B",
	TXT_BRIDGE
);
static TemplateTypeClass const Bridge1c(
	TEMPLATE_BRIDGE_1C,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"BR1C",
	TXT_BRIDGE
);
static TemplateTypeClass const Bridge2ax(
	TEMPLATE_BRIDGE_2AX,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"BR2X",
	TXT_BRIDGE
);
static TemplateTypeClass const Bridge2a(
	TEMPLATE_BRIDGE_2A,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"BR2A",
	TXT_BRIDGE
);
static TemplateTypeClass const Bridge2b(
	TEMPLATE_BRIDGE_2B,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"BR2B",
	TXT_BRIDGE
);
static TemplateTypeClass const Bridge2c(
	TEMPLATE_BRIDGE_2C,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"BR2C",
	TXT_BRIDGE
);
static TemplateTypeClass const Bridge3a(
	TEMPLATE_BRIDGE_3A,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"BR3A",
	TXT_BRIDGE
);
static TemplateTypeClass const Bridge3b(
	TEMPLATE_BRIDGE_3B,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"BR3B",
	TXT_BRIDGE
);
static TemplateTypeClass const Bridge3c(
	TEMPLATE_BRIDGE_3C,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"BR3C",
	TXT_BRIDGE
);
static TemplateTypeClass const Bridge3d(
	TEMPLATE_BRIDGE_3D,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"BR3D",
	TXT_BRIDGE
);
static TemplateTypeClass const Bridge3e(
	TEMPLATE_BRIDGE_3E,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"BR3E",
	TXT_BRIDGE
);
static TemplateTypeClass const Bridge3f(
	TEMPLATE_BRIDGE_3F,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"BR3F",
	TXT_BRIDGE
);
static TemplateTypeClass const ShoreCliff01(
	TEMPLATE_SHORECLIFF01,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"WC01",
	TXT_SHORE
);
static TemplateTypeClass const ShoreCliff02(
	TEMPLATE_SHORECLIFF02,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"WC02",
	TXT_SHORE
);
static TemplateTypeClass const ShoreCliff03(
	TEMPLATE_SHORECLIFF03,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"WC03",
	TXT_SHORE
);
static TemplateTypeClass const ShoreCliff04(
	TEMPLATE_SHORECLIFF04,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"WC04",
	TXT_SHORE
);
static TemplateTypeClass const ShoreCliff05(
	TEMPLATE_SHORECLIFF05,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"WC05",
	TXT_SHORE
);
static TemplateTypeClass const ShoreCliff06(
	TEMPLATE_SHORECLIFF06,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"WC06",
	TXT_SHORE
);
static TemplateTypeClass const ShoreCliff07(
	TEMPLATE_SHORECLIFF07,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"WC07",
	TXT_SHORE
);
static TemplateTypeClass const ShoreCliff08(
	TEMPLATE_SHORECLIFF08,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"WC08",
	TXT_SHORE
);
static TemplateTypeClass const ShoreCliff09(
	TEMPLATE_SHORECLIFF09,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"WC09",
	TXT_SHORE
);
static TemplateTypeClass const ShoreCliff10(
	TEMPLATE_SHORECLIFF10,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"WC10",
	TXT_SHORE
);
static TemplateTypeClass const ShoreCliff11(
	TEMPLATE_SHORECLIFF11,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"WC11",
	TXT_SHORE
);
static TemplateTypeClass const ShoreCliff12(
	TEMPLATE_SHORECLIFF12,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"WC12",
	TXT_SHORE
);
static TemplateTypeClass const ShoreCliff13(
	TEMPLATE_SHORECLIFF13,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"WC13",
	TXT_SHORE
);
static TemplateTypeClass const ShoreCliff14(
	TEMPLATE_SHORECLIFF14,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"WC14",
	TXT_SHORE
);
static TemplateTypeClass const ShoreCliff15(
	TEMPLATE_SHORECLIFF15,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"WC15",
	TXT_SHORE
);
static TemplateTypeClass const ShoreCliff16(
	TEMPLATE_SHORECLIFF16,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"WC16",
	TXT_SHORE
);
static TemplateTypeClass const ShoreCliff17(
	TEMPLATE_SHORECLIFF17,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"WC17",
	TXT_SHORE
);
static TemplateTypeClass const ShoreCliff18(
	TEMPLATE_SHORECLIFF18,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"WC18",
	TXT_SHORE
);
static TemplateTypeClass const ShoreCliff19(
	TEMPLATE_SHORECLIFF19,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"WC19",
	TXT_SHORE
);
static TemplateTypeClass const ShoreCliff20(
	TEMPLATE_SHORECLIFF20,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"WC20",
	TXT_SHORE
);
static TemplateTypeClass const ShoreCliff21(
	TEMPLATE_SHORECLIFF21,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"WC21",
	TXT_SHORE
);
static TemplateTypeClass const ShoreCliff22(
	TEMPLATE_SHORECLIFF22,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"WC22",
	TXT_SHORE
);
static TemplateTypeClass const ShoreCliff23(
	TEMPLATE_SHORECLIFF23,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"WC23",
	TXT_SHORE
);
static TemplateTypeClass const ShoreCliff24(
	TEMPLATE_SHORECLIFF24,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"WC24",
	TXT_SHORE
);
static TemplateTypeClass const ShoreCliff25(
	TEMPLATE_SHORECLIFF25,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"WC25",
	TXT_SHORE
);
static TemplateTypeClass const ShoreCliff26(
	TEMPLATE_SHORECLIFF26,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"WC26",
	TXT_SHORE
);
static TemplateTypeClass const ShoreCliff27(
	TEMPLATE_SHORECLIFF27,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"WC27",
	TXT_SHORE
);
static TemplateTypeClass const ShoreCliff28(
	TEMPLATE_SHORECLIFF28,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"WC28",
	TXT_SHORE
);
static TemplateTypeClass const ShoreCliff29(
	TEMPLATE_SHORECLIFF29,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"WC29",
	TXT_SHORE
);
static TemplateTypeClass const ShoreCliff30(
	TEMPLATE_SHORECLIFF30,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"WC30",
	TXT_SHORE
);
static TemplateTypeClass const ShoreCliff31(
	TEMPLATE_SHORECLIFF31,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"WC31",
	TXT_SHORE
);
static TemplateTypeClass const ShoreCliff32(
	TEMPLATE_SHORECLIFF32,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"WC32",
	TXT_SHORE
);
static TemplateTypeClass const ShoreCliff33(
	TEMPLATE_SHORECLIFF33,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"WC33",
	TXT_SHORE
);
static TemplateTypeClass const ShoreCliff34(
	TEMPLATE_SHORECLIFF34,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"WC34",
	TXT_SHORE
);
static TemplateTypeClass const ShoreCliff35(
	TEMPLATE_SHORECLIFF35,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"WC35",
	TXT_SHORE
);
static TemplateTypeClass const ShoreCliff36(
	TEMPLATE_SHORECLIFF36,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"WC36",
	TXT_SHORE
);
static TemplateTypeClass const ShoreCliff37(
	TEMPLATE_SHORECLIFF37,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"WC37",
	TXT_SHORE
);
static TemplateTypeClass const ShoreCliff38(
	TEMPLATE_SHORECLIFF38,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"WC38",
	TXT_SHORE
);
static TemplateTypeClass const Rough01(
	TEMPLATE_ROUGH01,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"RF01",
	TXT_ROCK
);
static TemplateTypeClass const Rough02(
	TEMPLATE_ROUGH02,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"RF02",
	TXT_ROCK
);
static TemplateTypeClass const Rough03(
	TEMPLATE_ROUGH03,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"RF03",
	TXT_ROCK
);
static TemplateTypeClass const Rough04(
	TEMPLATE_ROUGH04,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"RF04",
	TXT_ROCK
);
static TemplateTypeClass const Rough05(
	TEMPLATE_ROUGH05,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"RF05",
	TXT_ROCK
);
static TemplateTypeClass const Rough06(
	TEMPLATE_ROUGH06,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"RF06",
	TXT_ROCK
);
static TemplateTypeClass const Rough07(
	TEMPLATE_ROUGH07,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"RF07",
	TXT_ROCK
);
static TemplateTypeClass const Rough08(
	TEMPLATE_ROUGH08,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"RF08",
	TXT_ROCK
);
static TemplateTypeClass const Rough09(
	TEMPLATE_ROUGH09,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"RF09",
	TXT_ROCK
);
static TemplateTypeClass const Rough10(
	TEMPLATE_ROUGH10,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"RF10",
	TXT_ROCK
);
static TemplateTypeClass const Rough11(
	TEMPLATE_ROUGH11,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"RF11",
	TXT_ROCK
);
static TemplateTypeClass const RiverCliff01(
	TEMPLATE_RIVERCLIFF01,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"RC01",
	TXT_RIVER
);
static TemplateTypeClass const RiverCliff02(
	TEMPLATE_RIVERCLIFF02,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"RC02",
	TXT_RIVER
);
static TemplateTypeClass const RiverCliff03(
	TEMPLATE_RIVERCLIFF03,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"RC03",
	TXT_RIVER
);
static TemplateTypeClass const RiverCliff04(
	TEMPLATE_RIVERCLIFF04,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"RC04",
	TXT_RIVER
);

static TemplateTypeClass const F01(
	TEMPLATE_F01,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"F01",
	TXT_RIVER
);
static TemplateTypeClass const F02(
	TEMPLATE_F02,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"F02",
	TXT_RIVER
);
static TemplateTypeClass const F03(
	TEMPLATE_F03,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"F03",
	TXT_RIVER
);
static TemplateTypeClass const F04(
	TEMPLATE_F04,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"F04",
	TXT_RIVER
);
static TemplateTypeClass const F05(
	TEMPLATE_F05,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"F05",
	TXT_RIVER
);
static TemplateTypeClass const F06(
	TEMPLATE_F06,
	THEATERF_TEMPERATE|THEATERF_SNOW,
	"F06",
	TXT_RIVER
);

static TemplateTypeClass const ARRO0001(
	TEMPLATE_ARRO0001,
	THEATERF_INTERIOR,
	"ARRO0001",
	TXT_INTERIOR
);
static TemplateTypeClass const ARRO0002(
	TEMPLATE_ARRO0002,
	THEATERF_INTERIOR,
	"ARRO0002",
	TXT_INTERIOR
);
static TemplateTypeClass const ARRO0003(
	TEMPLATE_ARRO0003,
	THEATERF_INTERIOR,
	"ARRO0003",
	TXT_INTERIOR
);
static TemplateTypeClass const ARRO0004(
	TEMPLATE_ARRO0004,
	THEATERF_INTERIOR,
	"ARRO0004",
	TXT_INTERIOR
);
static TemplateTypeClass const ARRO0005(
	TEMPLATE_ARRO0005,
	THEATERF_INTERIOR,
	"ARRO0005",
	TXT_INTERIOR
);
static TemplateTypeClass const ARRO0006(
	TEMPLATE_ARRO0006,
	THEATERF_INTERIOR,
	"ARRO0006",
	TXT_INTERIOR
);
static TemplateTypeClass const ARRO0007(
	TEMPLATE_ARRO0007,
	THEATERF_INTERIOR,
	"ARRO0007",
	TXT_INTERIOR
);
static TemplateTypeClass const ARRO0008(
	TEMPLATE_ARRO0008,
	THEATERF_INTERIOR,
	"ARRO0008",
	TXT_INTERIOR
);
static TemplateTypeClass const ARRO0009(
	TEMPLATE_ARRO0009,
	THEATERF_INTERIOR,
	"ARRO0009",
	TXT_INTERIOR
);
static TemplateTypeClass const ARRO0010(
	TEMPLATE_ARRO0010,
	THEATERF_INTERIOR,
	"ARRO0010",
	TXT_INTERIOR
);
static TemplateTypeClass const ARRO0011(
	TEMPLATE_ARRO0011,
	THEATERF_INTERIOR,
	"ARRO0011",
	TXT_INTERIOR
);
static TemplateTypeClass const ARRO0012(
	TEMPLATE_ARRO0012,
	THEATERF_INTERIOR,
	"ARRO0012",
	TXT_INTERIOR
);
static TemplateTypeClass const ARRO0013(
	TEMPLATE_ARRO0013,
	THEATERF_INTERIOR,
	"ARRO0013",
	TXT_INTERIOR
);
static TemplateTypeClass const ARRO0014(
	TEMPLATE_ARRO0014,
	THEATERF_INTERIOR,
	"ARRO0014",
	TXT_INTERIOR
);
static TemplateTypeClass const ARRO0015(
	TEMPLATE_ARRO0015,
	THEATERF_INTERIOR,
	"ARRO0015",
	TXT_INTERIOR
);
static TemplateTypeClass const FLOR0001(
	TEMPLATE_FLOR0001,
	THEATERF_INTERIOR,
	"FLOR0001",
	TXT_INTERIOR
);
static TemplateTypeClass const FLOR0002(
	TEMPLATE_FLOR0002,
	THEATERF_INTERIOR,
	"FLOR0002",
	TXT_INTERIOR
);
static TemplateTypeClass const FLOR0003(
	TEMPLATE_FLOR0003,
	THEATERF_INTERIOR,
	"FLOR0003",
	TXT_INTERIOR
);
static TemplateTypeClass const FLOR0004(
	TEMPLATE_FLOR0004,
	THEATERF_INTERIOR,
	"FLOR0004",
	TXT_INTERIOR
);
static TemplateTypeClass const FLOR0005(
	TEMPLATE_FLOR0005,
	THEATERF_INTERIOR,
	"FLOR0005",
	TXT_INTERIOR
);
static TemplateTypeClass const FLOR0006(
	TEMPLATE_FLOR0006,
	THEATERF_INTERIOR,
	"FLOR0006",
	TXT_INTERIOR
);
static TemplateTypeClass const FLOR0007(
	TEMPLATE_FLOR0007,
	THEATERF_INTERIOR,
	"FLOR0007",
	TXT_INTERIOR
);
static TemplateTypeClass const GFLR0001(
	TEMPLATE_GFLR0001,
	THEATERF_INTERIOR,
	"GFLR0001",
	TXT_INTERIOR
);
static TemplateTypeClass const GFLR0002(
	TEMPLATE_GFLR0002,
	THEATERF_INTERIOR,
	"GFLR0002",
	TXT_INTERIOR
);
static TemplateTypeClass const GFLR0003(
	TEMPLATE_GFLR0003,
	THEATERF_INTERIOR,
	"GFLR0003",
	TXT_INTERIOR
);
static TemplateTypeClass const GFLR0004(
	TEMPLATE_GFLR0004,
	THEATERF_INTERIOR,
	"GFLR0004",
	TXT_INTERIOR
);
static TemplateTypeClass const GFLR0005(
	TEMPLATE_GFLR0005,
	THEATERF_INTERIOR,
	"GFLR0005",
	TXT_INTERIOR
);
static TemplateTypeClass const GSTR0001(
	TEMPLATE_GSTR0001,
	THEATERF_INTERIOR,
	"GSTR0001",
	TXT_INTERIOR
);
static TemplateTypeClass const GSTR0002(
	TEMPLATE_GSTR0002,
	THEATERF_INTERIOR,
	"GSTR0002",
	TXT_INTERIOR
);
static TemplateTypeClass const GSTR0003(
	TEMPLATE_GSTR0003,
	THEATERF_INTERIOR,
	"GSTR0003",
	TXT_INTERIOR
);
static TemplateTypeClass const GSTR0004(
	TEMPLATE_GSTR0004,
	THEATERF_INTERIOR,
	"GSTR0004",
	TXT_INTERIOR
);
static TemplateTypeClass const GSTR0005(
	TEMPLATE_GSTR0005,
	THEATERF_INTERIOR,
	"GSTR0005",
	TXT_INTERIOR
);
static TemplateTypeClass const GSTR0006(
	TEMPLATE_GSTR0006,
	THEATERF_INTERIOR,
	"GSTR0006",
	TXT_INTERIOR
);
static TemplateTypeClass const GSTR0007(
	TEMPLATE_GSTR0007,
	THEATERF_INTERIOR,
	"GSTR0007",
	TXT_INTERIOR
);
static TemplateTypeClass const GSTR0008(
	TEMPLATE_GSTR0008,
	THEATERF_INTERIOR,
	"GSTR0008",
	TXT_INTERIOR
);
static TemplateTypeClass const GSTR0009(
	TEMPLATE_GSTR0009,
	THEATERF_INTERIOR,
	"GSTR0009",
	TXT_INTERIOR
);
static TemplateTypeClass const GSTR0010(
	TEMPLATE_GSTR0010,
	THEATERF_INTERIOR,
	"GSTR0010",
	TXT_INTERIOR
);
static TemplateTypeClass const GSTR0011(
	TEMPLATE_GSTR0011,
	THEATERF_INTERIOR,
	"GSTR0011",
	TXT_INTERIOR
);
static TemplateTypeClass const LWAL0001(
	TEMPLATE_LWAL0001,
	THEATERF_INTERIOR,
	"LWAL0001",
	TXT_INTERIOR
);
static TemplateTypeClass const LWAL0002(
	TEMPLATE_LWAL0002,
	THEATERF_INTERIOR,
	"LWAL0002",
	TXT_INTERIOR
);
static TemplateTypeClass const LWAL0003(
	TEMPLATE_LWAL0003,
	THEATERF_INTERIOR,
	"LWAL0003",
	TXT_INTERIOR
);
static TemplateTypeClass const LWAL0004(
	TEMPLATE_LWAL0004,
	THEATERF_INTERIOR,
	"LWAL0004",
	TXT_INTERIOR
);
static TemplateTypeClass const LWAL0005(
	TEMPLATE_LWAL0005,
	THEATERF_INTERIOR,
	"LWAL0005",
	TXT_INTERIOR
);
static TemplateTypeClass const LWAL0006(
	TEMPLATE_LWAL0006,
	THEATERF_INTERIOR,
	"LWAL0006",
	TXT_INTERIOR
);
static TemplateTypeClass const LWAL0007(
	TEMPLATE_LWAL0007,
	THEATERF_INTERIOR,
	"LWAL0007",
	TXT_INTERIOR
);
static TemplateTypeClass const LWAL0008(
	TEMPLATE_LWAL0008,
	THEATERF_INTERIOR,
	"LWAL0008",
	TXT_INTERIOR
);
static TemplateTypeClass const LWAL0009(
	TEMPLATE_LWAL0009,
	THEATERF_INTERIOR,
	"LWAL0009",
	TXT_INTERIOR
);
static TemplateTypeClass const LWAL0010(
	TEMPLATE_LWAL0010,
	THEATERF_INTERIOR,
	"LWAL0010",
	TXT_INTERIOR
);
static TemplateTypeClass const LWAL0011(
	TEMPLATE_LWAL0011,
	THEATERF_INTERIOR,
	"LWAL0011",
	TXT_INTERIOR
);
static TemplateTypeClass const LWAL0012(
	TEMPLATE_LWAL0012,
	THEATERF_INTERIOR,
	"LWAL0012",
	TXT_INTERIOR
);
static TemplateTypeClass const LWAL0013(
	TEMPLATE_LWAL0013,
	THEATERF_INTERIOR,
	"LWAL0013",
	TXT_INTERIOR
);
static TemplateTypeClass const LWAL0014(
	TEMPLATE_LWAL0014,
	THEATERF_INTERIOR,
	"LWAL0014",
	TXT_INTERIOR
);
static TemplateTypeClass const LWAL0015(
	TEMPLATE_LWAL0015,
	THEATERF_INTERIOR,
	"LWAL0015",
	TXT_INTERIOR
);
static TemplateTypeClass const LWAL0016(
	TEMPLATE_LWAL0016,
	THEATERF_INTERIOR,
	"LWAL0016",
	TXT_INTERIOR
);
static TemplateTypeClass const LWAL0017(
	TEMPLATE_LWAL0017,
	THEATERF_INTERIOR,
	"LWAL0017",
	TXT_INTERIOR
);
static TemplateTypeClass const LWAL0018(
	TEMPLATE_LWAL0018,
	THEATERF_INTERIOR,
	"LWAL0018",
	TXT_INTERIOR
);
static TemplateTypeClass const LWAL0019(
	TEMPLATE_LWAL0019,
	THEATERF_INTERIOR,
	"LWAL0019",
	TXT_INTERIOR
);
static TemplateTypeClass const LWAL0020(
	TEMPLATE_LWAL0020,
	THEATERF_INTERIOR,
	"LWAL0020",
	TXT_INTERIOR
);
static TemplateTypeClass const LWAL0021(
	TEMPLATE_LWAL0021,
	THEATERF_INTERIOR,
	"LWAL0021",
	TXT_INTERIOR
);
static TemplateTypeClass const LWAL0022(
	TEMPLATE_LWAL0022,
	THEATERF_INTERIOR,
	"LWAL0022",
	TXT_INTERIOR
);
static TemplateTypeClass const LWAL0023(
	TEMPLATE_LWAL0023,
	THEATERF_INTERIOR,
	"LWAL0023",
	TXT_INTERIOR
);
static TemplateTypeClass const LWAL0024(
	TEMPLATE_LWAL0024,
	THEATERF_INTERIOR,
	"LWAL0024",
	TXT_INTERIOR
);
static TemplateTypeClass const LWAL0025(
	TEMPLATE_LWAL0025,
	THEATERF_INTERIOR,
	"LWAL0025",
	TXT_INTERIOR
);
static TemplateTypeClass const LWAL0026(
	TEMPLATE_LWAL0026,
	THEATERF_INTERIOR,
	"LWAL0026",
	TXT_INTERIOR
);
static TemplateTypeClass const LWAL0027(
	TEMPLATE_LWAL0027,
	THEATERF_INTERIOR,
	"LWAL0027",
	TXT_INTERIOR
);
static TemplateTypeClass const STRP0001(
	TEMPLATE_STRP0001,
	THEATERF_INTERIOR,
	"STRP0001",
	TXT_INTERIOR
);
static TemplateTypeClass const STRP0002(
	TEMPLATE_STRP0002,
	THEATERF_INTERIOR,
	"STRP0002",
	TXT_INTERIOR
);
static TemplateTypeClass const STRP0003(
	TEMPLATE_STRP0003,
	THEATERF_INTERIOR,
	"STRP0003",
	TXT_INTERIOR
);
static TemplateTypeClass const STRP0004(
	TEMPLATE_STRP0004,
	THEATERF_INTERIOR,
	"STRP0004",
	TXT_INTERIOR
);
static TemplateTypeClass const STRP0005(
	TEMPLATE_STRP0005,
	THEATERF_INTERIOR,
	"STRP0005",
	TXT_INTERIOR
);
static TemplateTypeClass const STRP0006(
	TEMPLATE_STRP0006,
	THEATERF_INTERIOR,
	"STRP0006",
	TXT_INTERIOR
);
static TemplateTypeClass const STRP0007(
	TEMPLATE_STRP0007,
	THEATERF_INTERIOR,
	"STRP0007",
	TXT_INTERIOR
);
static TemplateTypeClass const STRP0008(
	TEMPLATE_STRP0008,
	THEATERF_INTERIOR,
	"STRP0008",
	TXT_INTERIOR
);
static TemplateTypeClass const STRP0009(
	TEMPLATE_STRP0009,
	THEATERF_INTERIOR,
	"STRP0009",
	TXT_INTERIOR
);
static TemplateTypeClass const STRP0010(
	TEMPLATE_STRP0010,
	THEATERF_INTERIOR,
	"STRP0010",
	TXT_INTERIOR
);
static TemplateTypeClass const STRP0011(
	TEMPLATE_STRP0011,
	THEATERF_INTERIOR,
	"STRP0011",
	TXT_INTERIOR
);
static TemplateTypeClass const WALL0001(
	TEMPLATE_WALL0001,
	THEATERF_INTERIOR,
	"WALL0001",
	TXT_INTERIOR
);
static TemplateTypeClass const WALL0002(
	TEMPLATE_WALL0002,
	THEATERF_INTERIOR,
	"WALL0002",
	TXT_INTERIOR
);
static TemplateTypeClass const WALL0003(
	TEMPLATE_WALL0003,
	THEATERF_INTERIOR,
	"WALL0003",
	TXT_INTERIOR
);
static TemplateTypeClass const WALL0004(
	TEMPLATE_WALL0004,
	THEATERF_INTERIOR,
	"WALL0004",
	TXT_INTERIOR
);
static TemplateTypeClass const WALL0005(
	TEMPLATE_WALL0005,
	THEATERF_INTERIOR,
	"WALL0005",
	TXT_INTERIOR
);
static TemplateTypeClass const WALL0006(
	TEMPLATE_WALL0006,
	THEATERF_INTERIOR,
	"WALL0006",
	TXT_INTERIOR
);
static TemplateTypeClass const WALL0007(
	TEMPLATE_WALL0007,
	THEATERF_INTERIOR,
	"WALL0007",
	TXT_INTERIOR
);
static TemplateTypeClass const WALL0008(
	TEMPLATE_WALL0008,
	THEATERF_INTERIOR,
	"WALL0008",
	TXT_INTERIOR
);
static TemplateTypeClass const WALL0009(
	TEMPLATE_WALL0009,
	THEATERF_INTERIOR,
	"WALL0009",
	TXT_INTERIOR
);
static TemplateTypeClass const WALL0010(
	TEMPLATE_WALL0010,
	THEATERF_INTERIOR,
	"WALL0010",
	TXT_INTERIOR
);
static TemplateTypeClass const WALL0011(
	TEMPLATE_WALL0011,
	THEATERF_INTERIOR,
	"WALL0011",
	TXT_INTERIOR
);
static TemplateTypeClass const WALL0012(
	TEMPLATE_WALL0012,
	THEATERF_INTERIOR,
	"WALL0012",
	TXT_INTERIOR
);
static TemplateTypeClass const WALL0013(
	TEMPLATE_WALL0013,
	THEATERF_INTERIOR,
	"WALL0013",
	TXT_INTERIOR
);
static TemplateTypeClass const WALL0014(
	TEMPLATE_WALL0014,
	THEATERF_INTERIOR,
	"WALL0014",
	TXT_INTERIOR
);
static TemplateTypeClass const WALL0015(
	TEMPLATE_WALL0015,
	THEATERF_INTERIOR,
	"WALL0015",
	TXT_INTERIOR
);
static TemplateTypeClass const WALL0016(
	TEMPLATE_WALL0016,
	THEATERF_INTERIOR,
	"WALL0016",
	TXT_INTERIOR
);
static TemplateTypeClass const WALL0017(
	TEMPLATE_WALL0017,
	THEATERF_INTERIOR,
	"WALL0017",
	TXT_INTERIOR
);
static TemplateTypeClass const WALL0018(
	TEMPLATE_WALL0018,
	THEATERF_INTERIOR,
	"WALL0018",
	TXT_INTERIOR
);
static TemplateTypeClass const WALL0019(
	TEMPLATE_WALL0019,
	THEATERF_INTERIOR,
	"WALL0019",
	TXT_INTERIOR
);
static TemplateTypeClass const WALL0020(
	TEMPLATE_WALL0020,
	THEATERF_INTERIOR,
	"WALL0020",
	TXT_INTERIOR
);
static TemplateTypeClass const WALL0021(
	TEMPLATE_WALL0021,
	THEATERF_INTERIOR,
	"WALL0021",
	TXT_INTERIOR
);
static TemplateTypeClass const WALL0022(
	TEMPLATE_WALL0022,
	THEATERF_INTERIOR,
	"WALL0022",
	TXT_INTERIOR
);
static TemplateTypeClass const WALL0023(
	TEMPLATE_WALL0023,
	THEATERF_INTERIOR,
	"WALL0023",
	TXT_INTERIOR
);
static TemplateTypeClass const WALL0024(
	TEMPLATE_WALL0024,
	THEATERF_INTERIOR,
	"WALL0024",
	TXT_INTERIOR
);
static TemplateTypeClass const WALL0025(
	TEMPLATE_WALL0025,
	THEATERF_INTERIOR,
	"WALL0025",
	TXT_INTERIOR
);
static TemplateTypeClass const WALL0026(
	TEMPLATE_WALL0026,
	THEATERF_INTERIOR,
	"WALL0026",
	TXT_INTERIOR
);
static TemplateTypeClass const WALL0027(
	TEMPLATE_WALL0027,
	THEATERF_INTERIOR,
	"WALL0027",
	TXT_INTERIOR
);
static TemplateTypeClass const WALL0028(
	TEMPLATE_WALL0028,
	THEATERF_INTERIOR,
	"WALL0028",
	TXT_INTERIOR
);
static TemplateTypeClass const WALL0029(
	TEMPLATE_WALL0029,
	THEATERF_INTERIOR,
	"WALL0029",
	TXT_INTERIOR
);
static TemplateTypeClass const WALL0030(
	TEMPLATE_WALL0030,
	THEATERF_INTERIOR,
	"WALL0030",
	TXT_INTERIOR
);
static TemplateTypeClass const WALL0031(
	TEMPLATE_WALL0031,
	THEATERF_INTERIOR,
	"WALL0031",
	TXT_INTERIOR
);
static TemplateTypeClass const WALL0032(
	TEMPLATE_WALL0032,
	THEATERF_INTERIOR,
	"WALL0032",
	TXT_INTERIOR
);
static TemplateTypeClass const WALL0033(
	TEMPLATE_WALL0033,
	THEATERF_INTERIOR,
	"WALL0033",
	TXT_INTERIOR
);
static TemplateTypeClass const WALL0034(
	TEMPLATE_WALL0034,
	THEATERF_INTERIOR,
	"WALL0034",
	TXT_INTERIOR
);
static TemplateTypeClass const WALL0035(
	TEMPLATE_WALL0035,
	THEATERF_INTERIOR,
	"WALL0035",
	TXT_INTERIOR
);
static TemplateTypeClass const WALL0036(
	TEMPLATE_WALL0036,
	THEATERF_INTERIOR,
	"WALL0036",
	TXT_INTERIOR
);
static TemplateTypeClass const WALL0037(
	TEMPLATE_WALL0037,
	THEATERF_INTERIOR,
	"WALL0037",
	TXT_INTERIOR
);
static TemplateTypeClass const WALL0038(
	TEMPLATE_WALL0038,
	THEATERF_INTERIOR,
	"WALL0038",
	TXT_INTERIOR
);
static TemplateTypeClass const WALL0039(
	TEMPLATE_WALL0039,
	THEATERF_INTERIOR,
	"WALL0039",
	TXT_INTERIOR
);
static TemplateTypeClass const WALL0040(
	TEMPLATE_WALL0040,
	THEATERF_INTERIOR,
	"WALL0040",
	TXT_INTERIOR
);
static TemplateTypeClass const WALL0041(
	TEMPLATE_WALL0041,
	THEATERF_INTERIOR,
	"WALL0041",
	TXT_INTERIOR
);
static TemplateTypeClass const WALL0042(
	TEMPLATE_WALL0042,
	THEATERF_INTERIOR,
	"WALL0042",
	TXT_INTERIOR
);
static TemplateTypeClass const WALL0043(
	TEMPLATE_WALL0043,
	THEATERF_INTERIOR,
	"WALL0043",
	TXT_INTERIOR
);
static TemplateTypeClass const WALL0044(
	TEMPLATE_WALL0044,
	THEATERF_INTERIOR,
	"WALL0044",
	TXT_INTERIOR
);
static TemplateTypeClass const WALL0045(
	TEMPLATE_WALL0045,
	THEATERF_INTERIOR,
	"WALL0045",
	TXT_INTERIOR
);
static TemplateTypeClass const WALL0046(
	TEMPLATE_WALL0046,
	THEATERF_INTERIOR,
	"WALL0046",
	TXT_INTERIOR
);
static TemplateTypeClass const WALL0047(
	TEMPLATE_WALL0047,
	THEATERF_INTERIOR,
	"WALL0047",
	TXT_INTERIOR
);
static TemplateTypeClass const WALL0048(
	TEMPLATE_WALL0048,
	THEATERF_INTERIOR,
	"WALL0048",
	TXT_INTERIOR
);
static TemplateTypeClass const WALL0049(
	TEMPLATE_WALL0049,
	THEATERF_INTERIOR,
	"WALL0049",
	TXT_INTERIOR
);

static TemplateTypeClass const Xtra0001(
	TEMPLATE_XTRA0001,
	THEATERF_INTERIOR,
	"XTRA0001",
	TXT_INTERIOR
);
static TemplateTypeClass const Xtra0002(
	TEMPLATE_XTRA0002,
	THEATERF_INTERIOR,
	"XTRA0002",
	TXT_INTERIOR
);
static TemplateTypeClass const Xtra0003(
	TEMPLATE_XTRA0003,
	THEATERF_INTERIOR,
	"XTRA0003",
	TXT_INTERIOR
);
static TemplateTypeClass const Xtra0004(
	TEMPLATE_XTRA0004,
	THEATERF_INTERIOR,
	"XTRA0004",
	TXT_INTERIOR
);
static TemplateTypeClass const Xtra0005(
	TEMPLATE_XTRA0005,
	THEATERF_INTERIOR,
	"XTRA0005",
	TXT_INTERIOR
);
static TemplateTypeClass const Xtra0006(
	TEMPLATE_XTRA0006,
	THEATERF_INTERIOR,
	"XTRA0006",
	TXT_INTERIOR
);
static TemplateTypeClass const Xtra0007(
	TEMPLATE_XTRA0007,
	THEATERF_INTERIOR,
	"XTRA0007",
	TXT_INTERIOR
);
static TemplateTypeClass const Xtra0008(
	TEMPLATE_XTRA0008,
	THEATERF_INTERIOR,
	"XTRA0008",
	TXT_INTERIOR
);
static TemplateTypeClass const Xtra0009(
	TEMPLATE_XTRA0009,
	THEATERF_INTERIOR,
	"XTRA0009",
	TXT_INTERIOR
);
static TemplateTypeClass const Xtra0010(
	TEMPLATE_XTRA0010,
	THEATERF_INTERIOR,
	"XTRA0010",
	TXT_INTERIOR
);
static TemplateTypeClass const Xtra0011(
	TEMPLATE_XTRA0011,
	THEATERF_INTERIOR,
	"XTRA0011",
	TXT_INTERIOR
);
static TemplateTypeClass const Xtra0012(
	TEMPLATE_XTRA0012,
	THEATERF_INTERIOR,
	"XTRA0012",
	TXT_INTERIOR
);
static TemplateTypeClass const Xtra0013(
	TEMPLATE_XTRA0013,
	THEATERF_INTERIOR,
	"XTRA0013",
	TXT_INTERIOR
);
static TemplateTypeClass const Xtra0014(
	TEMPLATE_XTRA0014,
	THEATERF_INTERIOR,
	"XTRA0014",
	TXT_INTERIOR
);
static TemplateTypeClass const Xtra0015(
	TEMPLATE_XTRA0015,
	THEATERF_INTERIOR,
	"XTRA0015",
	TXT_INTERIOR
);
static TemplateTypeClass const Xtra0016(
	TEMPLATE_XTRA0016,
	THEATERF_INTERIOR,
	"XTRA0016",
	TXT_INTERIOR
);

#ifdef FIXIT_ANTS
static TemplateTypeClass const AntHill(
	TEMPLATE_HILL01,
	THEATERF_TEMPERATE,
	"HILL01",
	TXT_ROCK
);
#endif
static TemplateTypeClass const K11(
	TEMPLATE_K11,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"K11",
	TXT_ROCK
);
static TemplateTypeClass const K12(
	TEMPLATE_K12,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"K12",
	TXT_ROCK
);
static TemplateTypeClass const K13(
	TEMPLATE_K13,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"K13",
	TXT_ROCK
);
static TemplateTypeClass const K14(
	TEMPLATE_K14,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"K14",
	TXT_CLEAR
);
static TemplateTypeClass const K21(
	TEMPLATE_K21,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"K21",
	TXT_ROCK
);
static TemplateTypeClass const K22(
	TEMPLATE_K22,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"K22",
	TXT_CLEAR
);
static TemplateTypeClass const K23(
	TEMPLATE_K23,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"K23",
	TXT_CLEAR
);
static TemplateTypeClass const K24(
	TEMPLATE_K24,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"K24",
	TXT_CLEAR
);
static TemplateTypeClass const K31(
	TEMPLATE_K31,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"K31",
	TXT_CLEAR
);
static TemplateTypeClass const K32(
	TEMPLATE_K32,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"K32",
	TXT_CLEAR
);
static TemplateTypeClass const K33(
	TEMPLATE_K33,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"K33",
	TXT_CLEAR
);
static TemplateTypeClass const K34(
	TEMPLATE_K34,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"K34",
	TXT_CLEAR
);
static TemplateTypeClass const K35(
	TEMPLATE_K35,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"K35",
	TXT_CLEAR
);
static TemplateTypeClass const K36(
	TEMPLATE_K36,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"K36",
	TXT_CLEAR
);
static TemplateTypeClass const K41(
	TEMPLATE_K41,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"K41",
	TXT_CLEAR
);
static TemplateTypeClass const K42(
	TEMPLATE_K42,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"K42",
	TXT_CLEAR
);
static TemplateTypeClass const K43(
	TEMPLATE_K43,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"K43",
	TXT_CLEAR
);
static TemplateTypeClass const K44(
	TEMPLATE_K44,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"K44",
	TXT_CLEAR
); 

static TemplateTypeClass const K45(
	TEMPLATE_K45,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"K45",
	TXT_CLEAR
);
static TemplateTypeClass const K46(
	TEMPLATE_K46,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"K46",
	TXT_CLEAR
);
static TemplateTypeClass const K51(
	TEMPLATE_K51,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"K51",
	TXT_CLEAR
);
static TemplateTypeClass const K52(
	TEMPLATE_K52,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"K52",
	TXT_CLEAR
);
static TemplateTypeClass const K53(
	TEMPLATE_K53,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"K53",
	TXT_CLEAR
);
static TemplateTypeClass const K54(
	TEMPLATE_K54,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"K54",
	TXT_CLEAR
);
static TemplateTypeClass const K55(
	TEMPLATE_K55,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"K55",
	TXT_CLEAR
);
static TemplateTypeClass const K56(
	TEMPLATE_K56,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"K56",
	TXT_CLEAR
);
static TemplateTypeClass const K61(
	TEMPLATE_K61,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"K61",
	TXT_CLEAR
);
static TemplateTypeClass const K62(
	TEMPLATE_K62,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"K62",
	TXT_CLEAR
);
static TemplateTypeClass const K63(
	TEMPLATE_K63,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"K63",
	TXT_CLEAR
);
static TemplateTypeClass const K64(
	TEMPLATE_K64,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"K64",
	TXT_CLEAR
);
static TemplateTypeClass const K65(
	TEMPLATE_K65,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"K65",
	TXT_CLEAR
);
static TemplateTypeClass const K66(
	TEMPLATE_K66,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"K66",
	TXT_CLEAR
);

static TemplateTypeClass const M11(
	TEMPLATE_M11,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"M11",
	TXT_CLEAR
);
static TemplateTypeClass const M12(
	TEMPLATE_M12,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"M12",
	TXT_CLEAR
);
static TemplateTypeClass const M13(
	TEMPLATE_M13,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"M13",
	TXT_CLEAR
);
static TemplateTypeClass const M14(
	TEMPLATE_M14,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"M14",
	TXT_CLEAR
);
static TemplateTypeClass const M21(
	TEMPLATE_M21,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"M21",
	TXT_CLEAR
);
static TemplateTypeClass const M22(
	TEMPLATE_M22,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"M22",
	TXT_CLEAR
);
static TemplateTypeClass const M23(
	TEMPLATE_M23,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"M23",
	TXT_CLEAR
);
static TemplateTypeClass const M24(
	TEMPLATE_M24,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"M24",
	TXT_CLEAR
);
static TemplateTypeClass const M31(
	TEMPLATE_M31,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"M31",
	TXT_CLEAR
);
static TemplateTypeClass const M32(
	TEMPLATE_M32,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"M32",
	TXT_CLEAR
);
static TemplateTypeClass const M33(
	TEMPLATE_M33,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"M33",
	TXT_CLEAR
);
static TemplateTypeClass const M34(
	TEMPLATE_M34,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"M34",
	TXT_CLEAR
);
static TemplateTypeClass const M35(
	TEMPLATE_M35,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"M35",
	TXT_CLEAR
);
static TemplateTypeClass const M36(
	TEMPLATE_M36,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"M36",
	TXT_CLEAR
);
static TemplateTypeClass const M41(
	TEMPLATE_M41,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"M41",
	TXT_CLEAR
);
static TemplateTypeClass const M42(
	TEMPLATE_M42,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"M42",
	TXT_CLEAR
);
static TemplateTypeClass const M43(
	TEMPLATE_M43,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"M43",
	TXT_CLEAR
);
static TemplateTypeClass const M44(
	TEMPLATE_M44,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"M44",
	TXT_CLEAR
);
static TemplateTypeClass const M45(
	TEMPLATE_M45,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"M45",
	TXT_CLEAR
);
static TemplateTypeClass const M46(
	TEMPLATE_M46,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"M46",
	TXT_CLEAR
);
static TemplateTypeClass const M51(
	TEMPLATE_M51,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"M51",
	TXT_CLEAR
);
static TemplateTypeClass const M52(
	TEMPLATE_M52,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"M52",
	TXT_CLEAR
);
static TemplateTypeClass const M53(
	TEMPLATE_M53,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"M53",
	TXT_CLEAR
);
static TemplateTypeClass const M54(
	TEMPLATE_M54,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"M54",
	TXT_CLEAR
);
static TemplateTypeClass const M55(
	TEMPLATE_M55,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"M55",
	TXT_CLEAR
);
static TemplateTypeClass const M56(
	TEMPLATE_M56,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"M56",
	TXT_CLEAR
);
static TemplateTypeClass const M61(
	TEMPLATE_M61,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"M61",
	TXT_CLEAR
);
static TemplateTypeClass const M62(
	TEMPLATE_M62,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"M62",
	TXT_CLEAR
);
static TemplateTypeClass const M63(
	TEMPLATE_M63,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"M63",
	TXT_CLEAR
);
static TemplateTypeClass const M64(
	TEMPLATE_M64,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"M64",
	TXT_CLEAR
);
static TemplateTypeClass const M65(
	TEMPLATE_M65,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"M65",
	TXT_CLEAR
);
static TemplateTypeClass const M66(
	TEMPLATE_M66,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"M66",
	TXT_CLEAR
);
static TemplateTypeClass const N11(
	TEMPLATE_N11,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"N11",
	TXT_CLEAR
);
static TemplateTypeClass const N12(
	TEMPLATE_N12,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"N12",
	TXT_CLEAR
);
static TemplateTypeClass const N13(
	TEMPLATE_N13,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"N13",
	TXT_CLEAR
);
static TemplateTypeClass const N14(
	TEMPLATE_N14,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"N14",
	TXT_CLEAR
);
static TemplateTypeClass const N21(
	TEMPLATE_N21,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"N21",
	TXT_CLEAR
);
static TemplateTypeClass const N22(
	TEMPLATE_N22,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"N22",
	TXT_CLEAR
);
static TemplateTypeClass const N23(
	TEMPLATE_N23,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"N23",
	TXT_CLEAR
);
static TemplateTypeClass const N24(
	TEMPLATE_N24,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"N24",
	TXT_CLEAR
);
static TemplateTypeClass const N31(
	TEMPLATE_N31,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"N31",
	TXT_CLEAR
);
static TemplateTypeClass const N32(
	TEMPLATE_N32,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"N32",
	TXT_CLEAR
);
static TemplateTypeClass const N33(
	TEMPLATE_N33,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"N33",
	TXT_CLEAR
);
static TemplateTypeClass const N34(
	TEMPLATE_N34,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"N34",
	TXT_CLEAR
);
static TemplateTypeClass const N35(
	TEMPLATE_N35,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"N35",
	TXT_CLEAR
);
static TemplateTypeClass const N36(
	TEMPLATE_N36,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"N36",
	TXT_CLEAR
);
static TemplateTypeClass const N41(
	TEMPLATE_N41,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"N41",
	TXT_CLEAR
);
static TemplateTypeClass const N42(
	TEMPLATE_N42,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"N42",
	TXT_CLEAR
);
static TemplateTypeClass const N43(
	TEMPLATE_N43,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"N43",
	TXT_CLEAR
);
static TemplateTypeClass const N44(
	TEMPLATE_N44,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"N44",
	TXT_CLEAR
);
static TemplateTypeClass const N45(
	TEMPLATE_N45,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"N45",
	TXT_CLEAR
);
static TemplateTypeClass const N46(
	TEMPLATE_N46,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"N46",
	TXT_CLEAR
);
static TemplateTypeClass const N51(
	TEMPLATE_N51,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"N51",
	TXT_CLEAR
);
static TemplateTypeClass const N52(
	TEMPLATE_N52,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"N52",
	TXT_CLEAR
);
static TemplateTypeClass const N53(
	TEMPLATE_N53,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"N53",
	TXT_CLEAR
);
static TemplateTypeClass const N54(
	TEMPLATE_N54,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"N54",
	TXT_CLEAR
);
static TemplateTypeClass const N55(
	TEMPLATE_N55,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"N55",
	TXT_CLEAR
);
static TemplateTypeClass const N56(
	TEMPLATE_N56,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"N56",
	TXT_CLEAR
);
static TemplateTypeClass const N61(
	TEMPLATE_N61,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"N61",
	TXT_CLEAR
);
static TemplateTypeClass const N62(
	TEMPLATE_N62,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"N62",
	TXT_CLEAR
);
static TemplateTypeClass const N63(
	TEMPLATE_N63,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"N63",
	TXT_CLEAR
);
static TemplateTypeClass const N64(
	TEMPLATE_N64,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"N64",
	TXT_CLEAR
);
static TemplateTypeClass const N65(
	TEMPLATE_N65,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"N65",
	TXT_CLEAR
);
static TemplateTypeClass const N66(
	TEMPLATE_N66,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"N66",
	TXT_CLEAR
);
static TemplateTypeClass const Q11(
	TEMPLATE_Q11,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"Q11",
	TXT_CLEAR
);
static TemplateTypeClass const Q12(
	TEMPLATE_Q12,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"Q12",
	TXT_CLEAR
);
static TemplateTypeClass const Q13(
	TEMPLATE_Q13,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"Q13",
	TXT_CLEAR
);
static TemplateTypeClass const Q14(
	TEMPLATE_Q14,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"Q14",
	TXT_CLEAR
);
static TemplateTypeClass const Q21(
	TEMPLATE_Q21,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"Q21",
	TXT_CLEAR
);
static TemplateTypeClass const Q22(
	TEMPLATE_Q22,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"Q22",
	TXT_CLEAR
);
static TemplateTypeClass const Q23(
	TEMPLATE_Q23,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"Q23",
	TXT_CLEAR
);
static TemplateTypeClass const Q24(
	TEMPLATE_Q24,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"Q24",
	TXT_CLEAR
);
static TemplateTypeClass const Q31(
	TEMPLATE_Q31,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"Q31",
	TXT_CLEAR
);
static TemplateTypeClass const Q32(
	TEMPLATE_Q32,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"Q32",
	TXT_CLEAR
);
static TemplateTypeClass const Q33(
	TEMPLATE_Q33,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"Q33",
	TXT_CLEAR
);
static TemplateTypeClass const Q34(
	TEMPLATE_Q34,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"Q34",
	TXT_CLEAR
);
static TemplateTypeClass const Q35(
	TEMPLATE_Q35,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"Q35",
	TXT_CLEAR
);
static TemplateTypeClass const Q36(
	TEMPLATE_Q36,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"Q36",
	TXT_CLEAR
);
static TemplateTypeClass const Q41(
	TEMPLATE_Q41,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"Q41",
	TXT_CLEAR
);
static TemplateTypeClass const Q42(
	TEMPLATE_Q42,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"Q42",
	TXT_CLEAR
);
static TemplateTypeClass const Q43(
	TEMPLATE_Q43,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"Q43",
	TXT_CLEAR
);
static TemplateTypeClass const Q44(
	TEMPLATE_Q44,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"Q44",
	TXT_CLEAR
);
static TemplateTypeClass const Q45(
	TEMPLATE_Q45,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"Q45",
	TXT_CLEAR
);
static TemplateTypeClass const Q46(
	TEMPLATE_Q46,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"Q46",
	TXT_CLEAR
);
static TemplateTypeClass const Q51(
	TEMPLATE_Q51,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"Q51",
	TXT_CLEAR
);
static TemplateTypeClass const Q52(
	TEMPLATE_Q52,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"Q52",
	TXT_CLEAR
);
static TemplateTypeClass const Q53(
	TEMPLATE_Q53,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"Q53",
	TXT_CLEAR
);
static TemplateTypeClass const Q54(
	TEMPLATE_Q54,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"Q54",
	TXT_CLEAR
);
static TemplateTypeClass const Q55(
	TEMPLATE_Q55,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"Q55",
	TXT_CLEAR
);
static TemplateTypeClass const Q56(
	TEMPLATE_Q56,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"Q56",
	TXT_CLEAR
);
static TemplateTypeClass const Q61(
	TEMPLATE_Q61,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"Q61",
	TXT_CLEAR
);
static TemplateTypeClass const Q62(
	TEMPLATE_Q62,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"Q62",
	TXT_CLEAR
);
static TemplateTypeClass const Q63(
	TEMPLATE_Q63,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"Q63",
	TXT_CLEAR
);
static TemplateTypeClass const Q64(
	TEMPLATE_Q64,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"Q64",
	TXT_CLEAR
);
static TemplateTypeClass const Q65(
	TEMPLATE_Q65,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"Q65",
	TXT_CLEAR
);
static TemplateTypeClass const Q66(
	TEMPLATE_Q66,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"Q66",
	TXT_CLEAR
);
static TemplateTypeClass const R11A(
	TEMPLATE_R11A,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R11A",
	TXT_CLEAR
);
static TemplateTypeClass const R11B(
	TEMPLATE_R11B,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R11B",
	TXT_CLEAR
);
static TemplateTypeClass const R11C(
	TEMPLATE_R11C,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R11C",
	TXT_CLEAR
);
static TemplateTypeClass const R11D(
	TEMPLATE_R11D,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R11D",
	TXT_CLEAR
);
static TemplateTypeClass const R11E(
	TEMPLATE_R11E,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R11E",
	TXT_CLEAR
);
static TemplateTypeClass const R11F(
	TEMPLATE_R11F,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R11F",
	TXT_CLEAR
);
static TemplateTypeClass const R11G(
	TEMPLATE_R11G,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R11G",
	TXT_CLEAR
);
static TemplateTypeClass const R11H(
	TEMPLATE_R11H,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R11H",
	TXT_CLEAR
);
static TemplateTypeClass const R11I(
	TEMPLATE_R11I,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R11I",
	TXT_CLEAR
);
static TemplateTypeClass const R11J(
	TEMPLATE_R11J,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R11J",
	TXT_CLEAR
);
static TemplateTypeClass const R11K(
	TEMPLATE_R11K,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R11K",
	TXT_CLEAR
);
static TemplateTypeClass const R11L(
	TEMPLATE_R11L,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R11L",
	TXT_CLEAR
);
static TemplateTypeClass const R11M(
	TEMPLATE_R11M,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R11M",
	TXT_CLEAR
);
static TemplateTypeClass const R11N(
	TEMPLATE_R11N,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R11N",
	TXT_CLEAR
);
static TemplateTypeClass const R11O(
	TEMPLATE_R11O,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R11O",
	TXT_CLEAR
);
static TemplateTypeClass const R11P(
	TEMPLATE_R11P,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R11P",
	TXT_CLEAR
);
static TemplateTypeClass const R11Q(
	TEMPLATE_R11Q,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R11Q",
	TXT_CLEAR
);
static TemplateTypeClass const R11R(
	TEMPLATE_R11R,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R11R",
	TXT_CLEAR
);
static TemplateTypeClass const R11S(
	TEMPLATE_R11S,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R11S",
	TXT_CLEAR
);
static TemplateTypeClass const R11T(
	TEMPLATE_R11T,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R11T",
	TXT_CLEAR
);
static TemplateTypeClass const R11U(
	TEMPLATE_R11U,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R11U",
	TXT_CLEAR
);
static TemplateTypeClass const R11V(
	TEMPLATE_R11V,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R11V",
	TXT_CLEAR
);
static TemplateTypeClass const R11W(
	TEMPLATE_R11W,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R11W",
	TXT_CLEAR
);
static TemplateTypeClass const R11X(
	TEMPLATE_R11X,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R11X",
	TXT_CLEAR
);
static TemplateTypeClass const R11Y(
	TEMPLATE_R11Y,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R11Y",
	TXT_CLEAR
);
static TemplateTypeClass const R11Z(
	TEMPLATE_R11Z,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R11Z",
	TXT_CLEAR
);
static TemplateTypeClass const R11AA(
	TEMPLATE_R11AA,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R11AA",
	TXT_CLEAR
);
static TemplateTypeClass const R11BB(
	TEMPLATE_R11BB,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R11BB",
	TXT_CLEAR
);
static TemplateTypeClass const R11CC(
	TEMPLATE_R11CC,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R11CC",
	TXT_CLEAR
);
static TemplateTypeClass const R11DD(
	TEMPLATE_R11DD,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R11DD",
	TXT_CLEAR
);
static TemplateTypeClass const R11EE(
	TEMPLATE_R11EE,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R11EE",
	TXT_CLEAR
);
static TemplateTypeClass const R11FF(
	TEMPLATE_R11FF,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R11FF",
	TXT_CLEAR
);
static TemplateTypeClass const R11GG(
	TEMPLATE_R11GG,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R11GG",
	TXT_CLEAR
);
static TemplateTypeClass const R11HH(
	TEMPLATE_R11HH,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R11HH",
	TXT_CLEAR
);
static TemplateTypeClass const R11II(
	TEMPLATE_R11II,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R11II",
	TXT_CLEAR
);
static TemplateTypeClass const R11JJ(
	TEMPLATE_R11JJ,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R11JJ",
	TXT_CLEAR
);
static TemplateTypeClass const R11KK(
	TEMPLATE_R11KK,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R11KK",
	TXT_CLEAR
);
static TemplateTypeClass const R11LL(
	TEMPLATE_R11LL,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R11LL",
	TXT_CLEAR
);
static TemplateTypeClass const R11MM(
	TEMPLATE_R11MM,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R11MM",
	TXT_CLEAR
);
static TemplateTypeClass const R11NN(
	TEMPLATE_R11NN,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R11NN",
	TXT_CLEAR
);
static TemplateTypeClass const R11OO(
	TEMPLATE_R11OO,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R11OO",
	TXT_CLEAR
);
static TemplateTypeClass const R11PP(
	TEMPLATE_R11PP,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R11PP",
	TXT_CLEAR
);
static TemplateTypeClass const R11QQ(
	TEMPLATE_R11QQ,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R11QQ",
	TXT_CLEAR
);
static TemplateTypeClass const R11RR(
	TEMPLATE_R11RR,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R11RR",
	TXT_CLEAR
);
static TemplateTypeClass const R11SS(
	TEMPLATE_R11SS,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R11SS",
	TXT_CLEAR
);
static TemplateTypeClass const R11TT(
	TEMPLATE_R11TT,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R11TT",
	TXT_CLEAR
);
static TemplateTypeClass const R11UU(
	TEMPLATE_R11UU,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R11UU",
	TXT_CLEAR
);
static TemplateTypeClass const R11VV(
	TEMPLATE_R11VV,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R11VV",
	TXT_CLEAR
);
static TemplateTypeClass const R11WW(
	TEMPLATE_R11WW,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R11WW",
	TXT_CLEAR
);
static TemplateTypeClass const R11XX(
	TEMPLATE_R11XX,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R11XX",
	TXT_CLEAR
);
static TemplateTypeClass const R11YY(
	TEMPLATE_R11YY,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R11YY",
	TXT_CLEAR
);
static TemplateTypeClass const R11ZZ(
	TEMPLATE_R11ZZ,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R11ZZ",
	TXT_CLEAR
);
static TemplateTypeClass const R22A(
	TEMPLATE_R22A,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R22A",
	TXT_CLEAR
);
static TemplateTypeClass const R22B(
	TEMPLATE_R22B,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R22B",
	TXT_CLEAR
);
static TemplateTypeClass const R22C(
	TEMPLATE_R22C,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R22C",
	TXT_CLEAR
);
static TemplateTypeClass const R22D(
	TEMPLATE_R22D,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R22D",
	TXT_CLEAR
);
static TemplateTypeClass const R22E(
	TEMPLATE_R22E,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R22E",
	TXT_CLEAR
);
static TemplateTypeClass const R22F(
	TEMPLATE_R22F,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R22F",
	TXT_CLEAR
);
static TemplateTypeClass const R22G(
	TEMPLATE_R22G,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R22G",
	TXT_CLEAR
);
static TemplateTypeClass const R22H(
	TEMPLATE_R22H,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R22H",
	TXT_CLEAR
);
static TemplateTypeClass const R22I(
	TEMPLATE_R22I,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R22I",
	TXT_CLEAR
);
static TemplateTypeClass const R22J(
	TEMPLATE_R22J,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R22J",
	TXT_CLEAR
);
static TemplateTypeClass const R22K(
	TEMPLATE_R22K,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R22K",
	TXT_CLEAR
);
static TemplateTypeClass const R22L(
	TEMPLATE_R22L,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R22L",
	TXT_CLEAR
);
static TemplateTypeClass const R22M(
	TEMPLATE_R22M,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R22M",
	TXT_CLEAR
);
static TemplateTypeClass const R22N(
	TEMPLATE_R22N,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R22N",
	TXT_CLEAR
);
static TemplateTypeClass const R22O(
	TEMPLATE_R22O,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R22O",
	TXT_CLEAR
);
static TemplateTypeClass const R22P(
	TEMPLATE_R22P,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R22P",
	TXT_CLEAR
);
static TemplateTypeClass const R22Q(
	TEMPLATE_R22Q,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R22Q",
	TXT_CLEAR
);
static TemplateTypeClass const R22R(
	TEMPLATE_R22R,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R22R",
	TXT_CLEAR
);
static TemplateTypeClass const R22S(
	TEMPLATE_R22S,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R22S",
	TXT_CLEAR
);
static TemplateTypeClass const R22T(
	TEMPLATE_R22T,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R22T",
	TXT_CLEAR
);
static TemplateTypeClass const R22U(
	TEMPLATE_R22U,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R22U",
	TXT_CLEAR
);
static TemplateTypeClass const R22V(
	TEMPLATE_R22V,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R22V",
	TXT_CLEAR
);
static TemplateTypeClass const R22W(
	TEMPLATE_R22W,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R22W",
	TXT_CLEAR
);
static TemplateTypeClass const R22X(
	TEMPLATE_R22X,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R22X",
	TXT_CLEAR
);
static TemplateTypeClass const R22Y(
	TEMPLATE_R22Y,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R22Y",
	TXT_CLEAR
);
static TemplateTypeClass const R22Z(
	TEMPLATE_R22Z,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R22Z",
	TXT_CLEAR
);
static TemplateTypeClass const R22AA(
	TEMPLATE_R22AA,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R22AA",
	TXT_CLEAR
);
static TemplateTypeClass const R22BB(
	TEMPLATE_R22BB,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R22BB",
	TXT_CLEAR
);
static TemplateTypeClass const R22CC(
	TEMPLATE_R22CC,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R22CC",
	TXT_CLEAR
);
static TemplateTypeClass const R22DD(
	TEMPLATE_R22DD,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R22DD",
	TXT_CLEAR
);
static TemplateTypeClass const R22EE(
	TEMPLATE_R22EE,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R22EE",
	TXT_CLEAR
);
static TemplateTypeClass const R22FF(
	TEMPLATE_R22FF,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R22FF",
	TXT_CLEAR
);
static TemplateTypeClass const R22GG(
	TEMPLATE_R22GG,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R22GG",
	TXT_CLEAR
);
static TemplateTypeClass const R22HH(
	TEMPLATE_R22HH,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R22HH",
	TXT_CLEAR
);
static TemplateTypeClass const R22II(
	TEMPLATE_R22II,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R22II",
	TXT_CLEAR
);
static TemplateTypeClass const R22JJ(
	TEMPLATE_R22JJ,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R22JJ",
	TXT_CLEAR
);
static TemplateTypeClass const R22KK(
	TEMPLATE_R22KK,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R22KK",
	TXT_CLEAR
);
static TemplateTypeClass const R22LL(
	TEMPLATE_R22LL,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R22LL",
	TXT_CLEAR
);
static TemplateTypeClass const R22MM(
	TEMPLATE_R22MM,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R22MM",
	TXT_CLEAR
);
static TemplateTypeClass const R22NN(
	TEMPLATE_R22NN,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R22NN",
	TXT_CLEAR
);
static TemplateTypeClass const R22OO(
	TEMPLATE_R22OO,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R22OO",
	TXT_CLEAR
);
static TemplateTypeClass const R22PP(
	TEMPLATE_R22PP,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R22PP",
	TXT_CLEAR
);
static TemplateTypeClass const R22QQ(
	TEMPLATE_R22QQ,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R22QQ",
	TXT_CLEAR
);
static TemplateTypeClass const R22RR(
	TEMPLATE_R22RR,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R22RR",
	TXT_CLEAR
);
static TemplateTypeClass const R22SS(
	TEMPLATE_R22SS,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R22SS",
	TXT_CLEAR
);
static TemplateTypeClass const R22TT(
	TEMPLATE_R22TT,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R22TT",
	TXT_CLEAR
);
static TemplateTypeClass const R22UU(
	TEMPLATE_R22UU,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R22UU",
	TXT_CLEAR
);
static TemplateTypeClass const R22VV(
	TEMPLATE_R22VV,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R22VV",
	TXT_CLEAR
);
static TemplateTypeClass const R22WW(
	TEMPLATE_R22WW,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R22WW",
	TXT_CLEAR
);
static TemplateTypeClass const R22XX(
	TEMPLATE_R22XX,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R22XX",
	TXT_CLEAR
);
static TemplateTypeClass const R22YY(
	TEMPLATE_R22YY,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R22YY",
	TXT_CLEAR
);
static TemplateTypeClass const R22ZZ(
	TEMPLATE_R22ZZ,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R22ZZ",
	TXT_CLEAR
);
static TemplateTypeClass const R33A(
	TEMPLATE_R33A,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R33A",
	TXT_CLEAR
);
static TemplateTypeClass const R33B(
	TEMPLATE_R33B,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R33B",
	TXT_CLEAR
);
static TemplateTypeClass const R33C(
	TEMPLATE_R33C,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R33C",
	TXT_CLEAR
);
static TemplateTypeClass const R33D(
	TEMPLATE_R33D,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R33D",
	TXT_CLEAR
);
static TemplateTypeClass const R33E(
	TEMPLATE_R33E,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R33E",
	TXT_CLEAR
);
static TemplateTypeClass const R33F(
	TEMPLATE_R33F,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R33F",
	TXT_CLEAR
);
static TemplateTypeClass const R33G(
	TEMPLATE_R33G,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R33G",
	TXT_CLEAR
);
static TemplateTypeClass const R33H(
	TEMPLATE_R33H,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R33H",
	TXT_CLEAR
);
static TemplateTypeClass const R33I(
	TEMPLATE_R33I,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R33I",
	TXT_CLEAR
);
static TemplateTypeClass const R33J(
	TEMPLATE_R33J,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R33J",
	TXT_CLEAR
);
static TemplateTypeClass const R33K(
	TEMPLATE_R33K,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R33K",
	TXT_CLEAR
);
static TemplateTypeClass const R33L(
	TEMPLATE_R33L,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R33L",
	TXT_CLEAR
);
static TemplateTypeClass const R33M(
	TEMPLATE_R33M,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R33M",
	TXT_CLEAR
);
static TemplateTypeClass const R33N(
	TEMPLATE_R33N,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R33N",
	TXT_CLEAR
);
static TemplateTypeClass const R33O(
	TEMPLATE_R33O,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R33O",
	TXT_CLEAR
);
static TemplateTypeClass const R33P(
	TEMPLATE_R33P,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R33P",
	TXT_CLEAR
);
static TemplateTypeClass const R33Q(
	TEMPLATE_R33Q,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R33Q",
	TXT_CLEAR
);
static TemplateTypeClass const R33R(
	TEMPLATE_R33R,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R33R",
	TXT_CLEAR
);
static TemplateTypeClass const R33S(
	TEMPLATE_R33S,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R33S",
	TXT_CLEAR
);
static TemplateTypeClass const R33T(
	TEMPLATE_R33T,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R33T",
	TXT_CLEAR
);
static TemplateTypeClass const R33U(
	TEMPLATE_R33U,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R33U",
	TXT_CLEAR
);
static TemplateTypeClass const R33V(
	TEMPLATE_R33V,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R33V",
	TXT_CLEAR
);
static TemplateTypeClass const R33W(
	TEMPLATE_R33W,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R33W",
	TXT_CLEAR
);
static TemplateTypeClass const R33X(
	TEMPLATE_R33X,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R33X",
	TXT_CLEAR
);
static TemplateTypeClass const R33Y(
	TEMPLATE_R33Y,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R33Y",
	TXT_CLEAR
);
static TemplateTypeClass const R33Z(
	TEMPLATE_R33Z,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R33Z",
	TXT_CLEAR
);
static TemplateTypeClass const R33AA(
	TEMPLATE_R33AA,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R33AA",
	TXT_CLEAR
);
static TemplateTypeClass const R33BB(
	TEMPLATE_R33BB,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R33BB",
	TXT_CLEAR
);
static TemplateTypeClass const R33CC(
	TEMPLATE_R33CC,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R33CC",
	TXT_CLEAR
);
static TemplateTypeClass const R33DD(
	TEMPLATE_R33DD,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R33DD",
	TXT_CLEAR
);
static TemplateTypeClass const R33EE(
	TEMPLATE_R33EE,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R33EE",
	TXT_CLEAR
);
static TemplateTypeClass const R33FF(
	TEMPLATE_R33FF,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R33FF",
	TXT_CLEAR
);
static TemplateTypeClass const R33GG(
	TEMPLATE_R33GG,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R33GG",
	TXT_CLEAR
);
static TemplateTypeClass const R33HH(
	TEMPLATE_R33HH,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R33HH",
	TXT_CLEAR
);
static TemplateTypeClass const R33II(
	TEMPLATE_R33II,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R33II",
	TXT_CLEAR
);
static TemplateTypeClass const R33JJ(
	TEMPLATE_R33JJ,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R33JJ",
	TXT_CLEAR
);
static TemplateTypeClass const R33KK(
	TEMPLATE_R33KK,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R33KK",
	TXT_CLEAR
);
static TemplateTypeClass const R33LL(
	TEMPLATE_R33LL,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R33LL",
	TXT_CLEAR
);
static TemplateTypeClass const R33MM(
	TEMPLATE_R33MM,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R33MM",
	TXT_CLEAR
);
static TemplateTypeClass const R33NN(
	TEMPLATE_R33NN,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R33NN",
	TXT_CLEAR
);
static TemplateTypeClass const R33OO(
	TEMPLATE_R33OO,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R33OO",
	TXT_CLEAR
);
static TemplateTypeClass const R33PP(
	TEMPLATE_R33PP,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R33PP",
	TXT_CLEAR
);
static TemplateTypeClass const R33QQ(
	TEMPLATE_R33QQ,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R33QQ",
	TXT_CLEAR
);
static TemplateTypeClass const R33RR(
	TEMPLATE_R33RR,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R33RR",
	TXT_CLEAR
);
static TemplateTypeClass const R33SS(
	TEMPLATE_R33SS,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R33SS",
	TXT_CLEAR
);
static TemplateTypeClass const R33TT(
	TEMPLATE_R33TT,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R33TT",
	TXT_CLEAR
);
static TemplateTypeClass const R33UU(
	TEMPLATE_R33UU,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R33UU",
	TXT_CLEAR
);
static TemplateTypeClass const R33VV(
	TEMPLATE_R33VV,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R33VV",
	TXT_CLEAR
);
static TemplateTypeClass const R33WW(
	TEMPLATE_R33WW,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R33WW",
	TXT_CLEAR
);
static TemplateTypeClass const R33XX(
	TEMPLATE_R33XX,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R33XX",
	TXT_CLEAR
);
static TemplateTypeClass const R33YY(
	TEMPLATE_R33YY,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R33YY",
	TXT_CLEAR
);
static TemplateTypeClass const R33ZZ(
	TEMPLATE_R33ZZ,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"R33ZZ",
	TXT_CLEAR
);
static TemplateTypeClass const KK22A(
	TEMPLATE_KK22A,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK22A",
	TXT_CLEAR
);
static TemplateTypeClass const KK22B(
	TEMPLATE_KK22B,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK22B",
	TXT_CLEAR
);
static TemplateTypeClass const KK22C(
	TEMPLATE_KK22C,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK22C",
	TXT_CLEAR
);
static TemplateTypeClass const KK22D(
	TEMPLATE_KK22D,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK22D",
	TXT_CLEAR
);
static TemplateTypeClass const KK22E(
	TEMPLATE_KK22E,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK22E",
	TXT_CLEAR
);
static TemplateTypeClass const KK22F(
	TEMPLATE_KK22F,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK22F",
	TXT_CLEAR
);
static TemplateTypeClass const KK22G(
	TEMPLATE_KK22G,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK22G",
	TXT_CLEAR
);
static TemplateTypeClass const KK22H(
	TEMPLATE_KK22H,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK22H",
	TXT_CLEAR
);
static TemplateTypeClass const KK22I(
	TEMPLATE_KK22I,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK22I",
	TXT_CLEAR
);
static TemplateTypeClass const KK22J(
	TEMPLATE_KK22J,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK22J",
	TXT_CLEAR
);
static TemplateTypeClass const KK22K(
	TEMPLATE_KK22K,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK22K",
	TXT_CLEAR
);
static TemplateTypeClass const KK22L(
	TEMPLATE_KK22L,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK22L",
	TXT_CLEAR
);
static TemplateTypeClass const KK22M(
	TEMPLATE_KK22M,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK22M",
	TXT_CLEAR
);
static TemplateTypeClass const KK22N(
	TEMPLATE_KK22N,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK22N",
	TXT_CLEAR
);
static TemplateTypeClass const KK22O(
	TEMPLATE_KK22O,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK22O",
	TXT_CLEAR
);
static TemplateTypeClass const KK22P(
	TEMPLATE_KK22P,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK22P",
	TXT_CLEAR
);
static TemplateTypeClass const KK22Q(
	TEMPLATE_KK22Q,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK22Q",
	TXT_CLEAR
);
static TemplateTypeClass const KK22R(
	TEMPLATE_KK22R,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK22R",
	TXT_CLEAR
);
static TemplateTypeClass const KK22S(
	TEMPLATE_KK22S,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK22S",
	TXT_CLEAR
);
static TemplateTypeClass const KK22T(
	TEMPLATE_KK22T,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK22T",
	TXT_CLEAR
);
static TemplateTypeClass const KK22U(
	TEMPLATE_KK22U,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK22U",
	TXT_CLEAR
);
static TemplateTypeClass const KK22V(
	TEMPLATE_KK22V,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK22V",
	TXT_CLEAR
);
static TemplateTypeClass const KK22W(
	TEMPLATE_KK22W,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK22W",
	TXT_CLEAR
);
static TemplateTypeClass const KK22X(
	TEMPLATE_KK22X,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK22X",
	TXT_CLEAR
);
static TemplateTypeClass const KK22Y(
	TEMPLATE_KK22Y,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK22Y",
	TXT_CLEAR
);
static TemplateTypeClass const KK22Z(
	TEMPLATE_KK22Z,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK22Z",
	TXT_CLEAR
);
static TemplateTypeClass const KK22AA(
	TEMPLATE_KK22AA,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK22AA",
	TXT_CLEAR
);
static TemplateTypeClass const KK22BB(
	TEMPLATE_KK22BB,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK22BB",
	TXT_CLEAR
);
static TemplateTypeClass const KK22CC(
	TEMPLATE_KK22CC,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK22CC",
	TXT_CLEAR
);
static TemplateTypeClass const KK22DD(
	TEMPLATE_KK22DD,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK22DD",
	TXT_CLEAR
);
static TemplateTypeClass const KK22EE(
	TEMPLATE_KK22EE,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK22EE",
	TXT_CLEAR
);
static TemplateTypeClass const KK22FF(
	TEMPLATE_KK22FF,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK22FF",
	TXT_CLEAR
);
static TemplateTypeClass const KK22GG(
	TEMPLATE_KK22GG,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK22GG",
	TXT_CLEAR
);
static TemplateTypeClass const KK22HH(
	TEMPLATE_KK22HH,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK22HH",
	TXT_CLEAR
);
static TemplateTypeClass const KK22II(
	TEMPLATE_KK22II,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK22II",
	TXT_CLEAR
);
static TemplateTypeClass const KK22JJ(
	TEMPLATE_KK22JJ,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK22JJ",
	TXT_CLEAR
);
static TemplateTypeClass const KK22KK(
	TEMPLATE_KK22KK,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK22KK",
	TXT_CLEAR
);
static TemplateTypeClass const KK22LL(
	TEMPLATE_KK22LL,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK22LL",
	TXT_CLEAR
);
static TemplateTypeClass const KK22MM(
	TEMPLATE_KK22MM,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK22MM",
	TXT_CLEAR
);
static TemplateTypeClass const KK22NN(
	TEMPLATE_KK22NN,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK22NN",
	TXT_CLEAR
);
static TemplateTypeClass const KK22OO(
	TEMPLATE_KK22OO,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK22OO",
	TXT_CLEAR
);
static TemplateTypeClass const KK22PP(
	TEMPLATE_KK22PP,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK22PP",
	TXT_CLEAR
);
static TemplateTypeClass const KK22QQ(
	TEMPLATE_KK22QQ,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK22QQ",
	TXT_CLEAR
);
static TemplateTypeClass const KK22RR(
	TEMPLATE_KK22RR,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK22RR",
	TXT_CLEAR
);
static TemplateTypeClass const KK22SS(
	TEMPLATE_KK22SS,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK22SS",
	TXT_CLEAR
);
static TemplateTypeClass const KK22TT(
	TEMPLATE_KK22TT,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK22TT",
	TXT_CLEAR
);
static TemplateTypeClass const KK22UU(
	TEMPLATE_KK22UU,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK22UU",
	TXT_CLEAR
);
static TemplateTypeClass const KK22VV(
	TEMPLATE_KK22VV,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK22VV",
	TXT_CLEAR
);
static TemplateTypeClass const KK22WW(
	TEMPLATE_KK22WW,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK22WW",
	TXT_CLEAR
);
static TemplateTypeClass const KK22XX(
	TEMPLATE_KK22XX,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK22XX",
	TXT_CLEAR
);
static TemplateTypeClass const KK22YY(
	TEMPLATE_KK22YY,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK22YY",
	TXT_CLEAR
);
static TemplateTypeClass const KK22ZZ(
	TEMPLATE_KK22ZZ,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK22ZZ",
	TXT_CLEAR
);
static TemplateTypeClass const KK32A(
	TEMPLATE_KK32A,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK32A",
	TXT_CLEAR
);
static TemplateTypeClass const KK32B(
	TEMPLATE_KK32B,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK32B",
	TXT_CLEAR
);
static TemplateTypeClass const KK32C(
	TEMPLATE_KK32C,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK32C",
	TXT_CLEAR
);
static TemplateTypeClass const KK32D(
	TEMPLATE_KK32D,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK32D",
	TXT_CLEAR
);
static TemplateTypeClass const KK32E(
	TEMPLATE_KK32E,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK32E",
	TXT_CLEAR
);
static TemplateTypeClass const KK32F(
	TEMPLATE_KK32F,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK32F",
	TXT_CLEAR
);
static TemplateTypeClass const KK32G(
	TEMPLATE_KK32G,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK32G",
	TXT_CLEAR
);
static TemplateTypeClass const KK32H(
	TEMPLATE_KK32H,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK32H",
	TXT_CLEAR
);
static TemplateTypeClass const KK32I(
	TEMPLATE_KK32I,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK32I",
	TXT_CLEAR
);
static TemplateTypeClass const KK32J(
	TEMPLATE_KK32J,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK32J",
	TXT_CLEAR
);
static TemplateTypeClass const KK32K(
	TEMPLATE_KK32K,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK32K",
	TXT_CLEAR
);
static TemplateTypeClass const KK32L(
	TEMPLATE_KK32L,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK32L",
	TXT_CLEAR
);
static TemplateTypeClass const KK32M(
	TEMPLATE_KK32M,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK32M",
	TXT_CLEAR
);
static TemplateTypeClass const KK32N(
	TEMPLATE_KK32N,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK32N",
	TXT_CLEAR
);
static TemplateTypeClass const KK32O(
	TEMPLATE_KK32O,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK32O",
	TXT_CLEAR
);
static TemplateTypeClass const KK32P(
	TEMPLATE_KK32P,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK32P",
	TXT_CLEAR
);
static TemplateTypeClass const KK32Q(
	TEMPLATE_KK32Q,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK32Q",
	TXT_CLEAR
);
static TemplateTypeClass const KK32R(
	TEMPLATE_KK32R,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK32R",
	TXT_CLEAR
);
static TemplateTypeClass const KK32S(
	TEMPLATE_KK32S,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK32S",
	TXT_CLEAR
);
static TemplateTypeClass const KK32T(
	TEMPLATE_KK32T,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK32T",
	TXT_CLEAR
);
static TemplateTypeClass const KK32U(
	TEMPLATE_KK32U,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK32U",
	TXT_CLEAR
);
static TemplateTypeClass const KK32V(
	TEMPLATE_KK32V,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK32V",
	TXT_CLEAR
);
static TemplateTypeClass const KK32W(
	TEMPLATE_KK32W,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK32W",
	TXT_CLEAR
);
static TemplateTypeClass const KK32X(
	TEMPLATE_KK32X,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK32X",
	TXT_CLEAR
);
static TemplateTypeClass const KK32Y(
	TEMPLATE_KK32Y,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK32Y",
	TXT_CLEAR
);
static TemplateTypeClass const KK32Z(
	TEMPLATE_KK32Z,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK32Z",
	TXT_CLEAR
);
static TemplateTypeClass const KK32AA(
	TEMPLATE_KK32AA,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK32AA",
	TXT_CLEAR
);
static TemplateTypeClass const KK32BB(
	TEMPLATE_KK32BB,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK32BB",
	TXT_CLEAR
);
static TemplateTypeClass const KK32CC(
	TEMPLATE_KK32CC,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK32CC",
	TXT_CLEAR
);
static TemplateTypeClass const KK32DD(
	TEMPLATE_KK32DD,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK32DD",
	TXT_CLEAR
);
static TemplateTypeClass const KK32EE(
	TEMPLATE_KK32EE,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK32EE",
	TXT_CLEAR
);
static TemplateTypeClass const KK32FF(
	TEMPLATE_KK32FF,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK32FF",
	TXT_CLEAR
);
static TemplateTypeClass const KK32GG(
	TEMPLATE_KK32GG,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK32GG",
	TXT_CLEAR
);
static TemplateTypeClass const KK32HH(
	TEMPLATE_KK32HH,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK32HH",
	TXT_CLEAR
);
static TemplateTypeClass const KK32II(
	TEMPLATE_KK32II,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK32II",
	TXT_CLEAR
);
static TemplateTypeClass const KK32JJ(
	TEMPLATE_KK32JJ,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK32JJ",
	TXT_CLEAR
);
static TemplateTypeClass const KK32KK(
	TEMPLATE_KK32KK,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK32KK",
	TXT_CLEAR
);
static TemplateTypeClass const KK32LL(
	TEMPLATE_KK32LL,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK32LL",
	TXT_CLEAR
);
static TemplateTypeClass const KK32MM(
	TEMPLATE_KK32MM,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK32MM",
	TXT_CLEAR
);
static TemplateTypeClass const KK32NN(
	TEMPLATE_KK32NN,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK32NN",
	TXT_CLEAR
);
static TemplateTypeClass const KK32OO(
	TEMPLATE_KK32OO,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK32OO",
	TXT_CLEAR
);
static TemplateTypeClass const KK32PP(
	TEMPLATE_KK32PP,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK32PP",
	TXT_CLEAR
);
static TemplateTypeClass const KK32QQ(
	TEMPLATE_KK32QQ,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK32QQ",
	TXT_CLEAR
);
static TemplateTypeClass const KK32RR(
	TEMPLATE_KK32RR,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK32RR",
	TXT_CLEAR
);
static TemplateTypeClass const KK32SS(
	TEMPLATE_KK32SS,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK32SS",
	TXT_CLEAR
);
static TemplateTypeClass const KK32TT(
	TEMPLATE_KK32TT,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK32TT",
	TXT_CLEAR
);
static TemplateTypeClass const KK32UU(
	TEMPLATE_KK32UU,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK32UU",
	TXT_CLEAR
);
static TemplateTypeClass const KK32VV(
	TEMPLATE_KK32VV,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK32VV",
	TXT_CLEAR
);
static TemplateTypeClass const KK32WW(
	TEMPLATE_KK32WW,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK32WW",
	TXT_CLEAR
);
static TemplateTypeClass const KK32XX(
	TEMPLATE_KK32XX,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK32XX",
	TXT_CLEAR
);
static TemplateTypeClass const KK32YY(
	TEMPLATE_KK32YY,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK32YY",
	TXT_CLEAR
);
static TemplateTypeClass const KK32ZZ(
	TEMPLATE_KK32ZZ,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK32ZZ",
	TXT_CLEAR
);
static TemplateTypeClass const KK33A(
	TEMPLATE_KK33A,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK33A",
	TXT_CLEAR
);
static TemplateTypeClass const KK33B(
	TEMPLATE_KK33B,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK33B",
	TXT_CLEAR
);
static TemplateTypeClass const KK33C(
	TEMPLATE_KK33C,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK33C",
	TXT_CLEAR
);
static TemplateTypeClass const KK33D(
	TEMPLATE_KK33D,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK33D",
	TXT_CLEAR
);
static TemplateTypeClass const KK33E(
	TEMPLATE_KK33E,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK33E",
	TXT_CLEAR
);
static TemplateTypeClass const KK33F(
	TEMPLATE_KK33F,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK33F",
	TXT_CLEAR
);
static TemplateTypeClass const KK33G(
	TEMPLATE_KK33G,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK33G",
	TXT_CLEAR
);
static TemplateTypeClass const KK33H(
	TEMPLATE_KK33H,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK33H",
	TXT_CLEAR
);
static TemplateTypeClass const KK33I(
	TEMPLATE_KK33I,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK33I",
	TXT_CLEAR
);
static TemplateTypeClass const KK33J(
	TEMPLATE_KK33J,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK33J",
	TXT_CLEAR
);
static TemplateTypeClass const KK33K(
	TEMPLATE_KK33K,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK33K",
	TXT_CLEAR
);
static TemplateTypeClass const KK33L(
	TEMPLATE_KK33L,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK33L",
	TXT_CLEAR
);
static TemplateTypeClass const KK33M(
	TEMPLATE_KK33M,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK33M",
	TXT_CLEAR
);
static TemplateTypeClass const KK33N(
	TEMPLATE_KK33N,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK33N",
	TXT_CLEAR
);
static TemplateTypeClass const KK33O(
	TEMPLATE_KK33O,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK33O",
	TXT_CLEAR
);
static TemplateTypeClass const KK33P(
	TEMPLATE_KK33P,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK33P",
	TXT_CLEAR
);
static TemplateTypeClass const KK33Q(
	TEMPLATE_KK33Q,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK33Q",
	TXT_CLEAR
);
static TemplateTypeClass const KK33R(
	TEMPLATE_KK33R,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK33R",
	TXT_CLEAR
);
static TemplateTypeClass const KK33S(
	TEMPLATE_KK33S,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK33S",
	TXT_CLEAR
);
static TemplateTypeClass const KK33T(
	TEMPLATE_KK33T,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK33T",
	TXT_CLEAR
);
static TemplateTypeClass const KK33U(
	TEMPLATE_KK33U,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK33U",
	TXT_CLEAR
);
static TemplateTypeClass const KK33V(
	TEMPLATE_KK33V,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK33V",
	TXT_CLEAR
);
static TemplateTypeClass const KK33W(
	TEMPLATE_KK33W,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK33W",
	TXT_CLEAR
);
static TemplateTypeClass const KK33X(
	TEMPLATE_KK33X,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK33X",
	TXT_CLEAR
);
static TemplateTypeClass const KK33Y(
	TEMPLATE_KK33Y,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK33Y",
	TXT_CLEAR
);
static TemplateTypeClass const KK33Z(
	TEMPLATE_KK33Z,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK33Z",
	TXT_CLEAR
);
static TemplateTypeClass const KK33AA(
	TEMPLATE_KK33AA,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK33AA",
	TXT_CLEAR
);
static TemplateTypeClass const KK33BB(
	TEMPLATE_KK33BB,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK33BB",
	TXT_CLEAR
);
static TemplateTypeClass const KK33CC(
	TEMPLATE_KK33CC,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK33CC",
	TXT_CLEAR
);
static TemplateTypeClass const KK33DD(
	TEMPLATE_KK33DD,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK33DD",
	TXT_CLEAR
);
static TemplateTypeClass const KK33EE(
	TEMPLATE_KK33EE,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK33EE",
	TXT_CLEAR
);
static TemplateTypeClass const KK33FF(
	TEMPLATE_KK33FF,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK33FF",
	TXT_CLEAR
);
static TemplateTypeClass const KK33GG(
	TEMPLATE_KK33GG,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK33GG",
	TXT_CLEAR
);
static TemplateTypeClass const KK33HH(
	TEMPLATE_KK33HH,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK33HH",
	TXT_CLEAR
);
static TemplateTypeClass const KK33II(
	TEMPLATE_KK33II,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK33II",
	TXT_CLEAR
);
static TemplateTypeClass const KK33JJ(
	TEMPLATE_KK33JJ,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK33JJ",
	TXT_CLEAR
);
static TemplateTypeClass const KK33KK(
	TEMPLATE_KK33KK,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK33KK",
	TXT_CLEAR
);
static TemplateTypeClass const KK33LL(
	TEMPLATE_KK33LL,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK33LL",
	TXT_CLEAR
);
static TemplateTypeClass const KK33MM(
	TEMPLATE_KK33MM,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK33MM",
	TXT_CLEAR
);
static TemplateTypeClass const KK33NN(
	TEMPLATE_KK33NN,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK33NN",
	TXT_CLEAR
);
static TemplateTypeClass const KK33OO(
	TEMPLATE_KK33OO,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK33OO",
	TXT_CLEAR
);
static TemplateTypeClass const KK33PP(
	TEMPLATE_KK33PP,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK33PP",
	TXT_CLEAR
);
static TemplateTypeClass const KK33QQ(
	TEMPLATE_KK33QQ,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK33QQ",
	TXT_CLEAR
);
static TemplateTypeClass const KK33RR(
	TEMPLATE_KK33RR,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK33RR",
	TXT_CLEAR
);
static TemplateTypeClass const KK33SS(
	TEMPLATE_KK33SS,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK33SS",
	TXT_CLEAR
);
static TemplateTypeClass const KK33TT(
	TEMPLATE_KK33TT,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK33TT",
	TXT_CLEAR
);
static TemplateTypeClass const KK33UU(
	TEMPLATE_KK33UU,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK33UU",
	TXT_CLEAR
);
static TemplateTypeClass const KK33VV(
	TEMPLATE_KK33VV,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK33VV",
	TXT_CLEAR
);
static TemplateTypeClass const KK33WW(
	TEMPLATE_KK33WW,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK33WW",
	TXT_CLEAR
);
static TemplateTypeClass const KK33XX(
	TEMPLATE_KK33XX,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK33XX",
	TXT_CLEAR
);
static TemplateTypeClass const KK33YY(
	TEMPLATE_KK33YY,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK33YY",
	TXT_CLEAR
);
static TemplateTypeClass const KK33ZZ(
	TEMPLATE_KK33ZZ,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK33ZZ",
	TXT_CLEAR
);
static TemplateTypeClass const KK41A(
	TEMPLATE_KK41A,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK41A",
	TXT_CLEAR
);
static TemplateTypeClass const KK41B(
	TEMPLATE_KK41B,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK41B",
	TXT_CLEAR
);
static TemplateTypeClass const KK41C(
	TEMPLATE_KK41C,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK41C",
	TXT_CLEAR
);
static TemplateTypeClass const KK41D(
	TEMPLATE_KK41D,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK41D",
	TXT_CLEAR
);
static TemplateTypeClass const KK41E(
	TEMPLATE_KK41E,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK41E",
	TXT_CLEAR
);
static TemplateTypeClass const KK41F(
	TEMPLATE_KK41F,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK41F",
	TXT_CLEAR
);
static TemplateTypeClass const KK41G(
	TEMPLATE_KK41G,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK41G",
	TXT_CLEAR
);
static TemplateTypeClass const KK41H(
	TEMPLATE_KK41H,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK41H",
	TXT_CLEAR
);
static TemplateTypeClass const KK41I(
	TEMPLATE_KK41I,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK41I",
	TXT_CLEAR
);
static TemplateTypeClass const KK41J(
	TEMPLATE_KK41J,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK41J",
	TXT_CLEAR
);
static TemplateTypeClass const KK41K(
	TEMPLATE_KK41K,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK41K",
	TXT_CLEAR
);
static TemplateTypeClass const KK41L(
	TEMPLATE_KK41L,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK41L",
	TXT_CLEAR
);
static TemplateTypeClass const KK41M(
	TEMPLATE_KK41M,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK41M",
	TXT_CLEAR
);
static TemplateTypeClass const KK41N(
	TEMPLATE_KK41N,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK41N",
	TXT_CLEAR
);
static TemplateTypeClass const KK41O(
	TEMPLATE_KK41O,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK41O",
	TXT_CLEAR
);
static TemplateTypeClass const KK41P(
	TEMPLATE_KK41P,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK41P",
	TXT_CLEAR
);
static TemplateTypeClass const KK41Q(
	TEMPLATE_KK41Q,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK41Q",
	TXT_CLEAR
);
static TemplateTypeClass const KK41R(
	TEMPLATE_KK41R,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK41R",
	TXT_CLEAR
);
static TemplateTypeClass const KK41S(
	TEMPLATE_KK41S,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK41S",
	TXT_CLEAR
);
static TemplateTypeClass const KK41T(
	TEMPLATE_KK41T,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK41T",
	TXT_CLEAR
);
static TemplateTypeClass const KK41U(
	TEMPLATE_KK41U,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK41U",
	TXT_CLEAR
);
static TemplateTypeClass const KK41V(
	TEMPLATE_KK41V,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK41V",
	TXT_CLEAR
);
static TemplateTypeClass const KK41W(
	TEMPLATE_KK41W,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK41W",
	TXT_CLEAR
);
static TemplateTypeClass const KK41X(
	TEMPLATE_KK41X,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK41X",
	TXT_CLEAR
);
static TemplateTypeClass const KK41Y(
	TEMPLATE_KK41Y,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK41Y",
	TXT_CLEAR
);
static TemplateTypeClass const KK41Z(
	TEMPLATE_KK41Z,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK41Z",
	TXT_CLEAR
);
static TemplateTypeClass const KK41AA(
	TEMPLATE_KK41AA,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK41AA",
	TXT_CLEAR
);
static TemplateTypeClass const KK41BB(
	TEMPLATE_KK41BB,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK41BB",
	TXT_CLEAR
);
static TemplateTypeClass const KK41CC(
	TEMPLATE_KK41CC,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK41CC",
	TXT_CLEAR
);
static TemplateTypeClass const KK41DD(
	TEMPLATE_KK41DD,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK41DD",
	TXT_CLEAR
);
static TemplateTypeClass const KK41EE(
	TEMPLATE_KK41EE,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK41EE",
	TXT_CLEAR
);
static TemplateTypeClass const KK41FF(
	TEMPLATE_KK41FF,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK41FF",
	TXT_CLEAR
);
static TemplateTypeClass const KK41GG(
	TEMPLATE_KK41GG,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK41GG",
	TXT_CLEAR
);
static TemplateTypeClass const KK41HH(
	TEMPLATE_KK41HH,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK41HH",
	TXT_CLEAR
);
static TemplateTypeClass const KK41II(
	TEMPLATE_KK41II,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK41II",
	TXT_CLEAR
);
static TemplateTypeClass const KK41JJ(
	TEMPLATE_KK41JJ,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK41JJ",
	TXT_CLEAR
);
static TemplateTypeClass const KK41KK(
	TEMPLATE_KK41KK,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK41KK",
	TXT_CLEAR
);
static TemplateTypeClass const KK41LL(
	TEMPLATE_KK41LL,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK41LL",
	TXT_CLEAR
);
static TemplateTypeClass const KK41MM(
	TEMPLATE_KK41MM,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK41MM",
	TXT_CLEAR
);
static TemplateTypeClass const KK41NN(
	TEMPLATE_KK41NN,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK41NN",
	TXT_CLEAR
);
static TemplateTypeClass const KK41OO(
	TEMPLATE_KK41OO,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK41OO",
	TXT_CLEAR
);
static TemplateTypeClass const KK41PP(
	TEMPLATE_KK41PP,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK41PP",
	TXT_CLEAR
);
static TemplateTypeClass const KK41QQ(
	TEMPLATE_KK41QQ,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK41QQ",
	TXT_CLEAR
);
static TemplateTypeClass const KK41RR(
	TEMPLATE_KK41RR,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK41RR",
	TXT_CLEAR
);
static TemplateTypeClass const KK41SS(
	TEMPLATE_KK41SS,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK41SS",
	TXT_CLEAR
);
static TemplateTypeClass const KK41TT(
	TEMPLATE_KK41TT,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK41TT",
	TXT_CLEAR
);
static TemplateTypeClass const KK41UU(
	TEMPLATE_KK41UU,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK41UU",
	TXT_CLEAR
);
static TemplateTypeClass const KK41VV(
	TEMPLATE_KK41VV,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK41VV",
	TXT_CLEAR
);
static TemplateTypeClass const KK41WW(
	TEMPLATE_KK41WW,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK41WW",
	TXT_CLEAR
);
static TemplateTypeClass const KK41XX(
	TEMPLATE_KK41XX,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK41XX",
	TXT_CLEAR
);
static TemplateTypeClass const KK41YY(
	TEMPLATE_KK41YY,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK41YY",
	TXT_CLEAR
);
static TemplateTypeClass const KK41ZZ(
	TEMPLATE_KK41ZZ,
	THEATERF_TEMPERATE | THEATERF_SNOW | THEATERF_INTERIOR,
	"KK41ZZ",
	TXT_CLEAR
);




/***********************************************************************************************
 * TemplateTypeClass::TemplateTypeClass -- Constructor for template type objects.              *
 *                                                                                             *
 *    This is the constructor for the template types.                                          *
 *                                                                                             *
 * INPUT:   see below...                                                                       *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/29/1994 JLB : Created.                                                                 *
 *=============================================================================================*/
	; TemplateTypeClass::TemplateTypeClass(
	TemplateType iconset,
	int theater,
	char const * ininame,
	int fullname) :
		ObjectTypeClass(
			RTTI_TEMPLATETYPE,
			int(iconset),
			false,
			true,
			false,
			false,
			true,
			true,
			false,
			fullname,
			ininame),
	Type(iconset),
	Theater(theater),
	Width(0),
	Height(0)
{
}


/***********************************************************************************************
 * TemplateTypeClass::operator new -- Allocates a template type from special heap.             *
 *                                                                                             *
 *    This allocates a template type object from the special heap used for that purpose.       *
 *                                                                                             *
 * INPUT:   none                                                                               *
 *                                                                                             *
 * OUTPUT:  Returns with a pointer to the newly allocated template type object. If no object   *
 *          could be allocated, then NULL is returned.                                         *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/06/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
void * TemplateTypeClass::operator new(size_t)
{
	return(TemplateTypes.Alloc());
}


/***********************************************************************************************
 * TemplateTypeClass::operator delete -- Deletes a template type object.                       *
 *                                                                                             *
 *    This routine will return a template type object back to the special heap it was          *
 *    allocated from.                                                                          *
 *                                                                                             *
 * INPUT:   ptr   -- Pointer to the template type object to free.                              *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/06/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
void TemplateTypeClass::operator delete(void * ptr)
{
	TemplateTypes.Free((TemplateTypeClass *)ptr);
}


static void _Watcom_Ugh_Hack(void)
{
	(void)new TemplateTypeClass(Road37);			//	TEMPLATE_ROAD37
	(void)new TemplateTypeClass(Road38);			//	TEMPLATE_ROAD38
	(void)new TemplateTypeClass(Road39);			//	TEMPLATE_ROAD39
	(void)new TemplateTypeClass(Road40);			//	TEMPLATE_ROAD40
	(void)new TemplateTypeClass(Road41);			//	TEMPLATE_ROAD41
	(void)new TemplateTypeClass(Road42);			//	TEMPLATE_ROAD42
	(void)new TemplateTypeClass(Road43);			//	TEMPLATE_ROAD43
	(void)new TemplateTypeClass(Rough01);			// TEMPLATE_ROUGH01
	(void)new TemplateTypeClass(Rough02);			// TEMPLATE_ROUGH02
	(void)new TemplateTypeClass(Rough03);			// TEMPLATE_ROUGH03
	(void)new TemplateTypeClass(Rough04);			// TEMPLATE_ROUGH04
	(void)new TemplateTypeClass(Rough05);			// TEMPLATE_ROUGH05
	(void)new TemplateTypeClass(Rough06);			// TEMPLATE_ROUGH06
	(void)new TemplateTypeClass(Rough07);			// TEMPLATE_ROUGH07
	(void)new TemplateTypeClass(Rough08);			// TEMPLATE_ROUGH08
	(void)new TemplateTypeClass(Rough09);			// TEMPLATE_ROUGH09
	(void)new TemplateTypeClass(Rough10);			// TEMPLATE_ROUGH10
	(void)new TemplateTypeClass(Rough11);			// TEMPLATE_ROUGH11
	(void)new TemplateTypeClass(Road44);			//	TEMPLATE_ROAD44
	(void)new TemplateTypeClass(Road45);			//	TEMPLATE_ROAD45
	(void)new TemplateTypeClass(River14);			//	TEMPLATE_RIVER14
	(void)new TemplateTypeClass(River15);			//	TEMPLATE_RIVER15
	(void)new TemplateTypeClass(RiverCliff01);	//	TEMPLATE_RIVERCLIFF01
	(void)new TemplateTypeClass(RiverCliff02);	//	TEMPLATE_RIVERCLIFF02
	(void)new TemplateTypeClass(RiverCliff03);	//	TEMPLATE_RIVERCLIFF03
	(void)new TemplateTypeClass(RiverCliff04);	//	TEMPLATE_RIVERCLIFF04
	(void)new TemplateTypeClass(Bridge1a);			//	TEMPLATE_BRIDGE_1A
	(void)new TemplateTypeClass(Bridge1b);			//	TEMPLATE_BRIDGE_1B
	(void)new TemplateTypeClass(Bridge1c);			//	TEMPLATE_BRIDGE_1C
	(void)new TemplateTypeClass(Bridge2a);			//	TEMPLATE_BRIDGE_2A
	(void)new TemplateTypeClass(Bridge2b);			//	TEMPLATE_BRIDGE_2B
	(void)new TemplateTypeClass(Bridge2c);			//	TEMPLATE_BRIDGE_2C
	(void)new TemplateTypeClass(Bridge3a);			//	TEMPLATE_BRIDGE_3A
	(void)new TemplateTypeClass(Bridge3b);			//	TEMPLATE_BRIDGE_3B
	(void)new TemplateTypeClass(Bridge3c);			//	TEMPLATE_BRIDGE_3C
	(void)new TemplateTypeClass(Bridge3d);			//	TEMPLATE_BRIDGE_3D
	(void)new TemplateTypeClass(Bridge3e);			//	TEMPLATE_BRIDGE_3E
	(void)new TemplateTypeClass(Bridge3f);			//	TEMPLATE_BRIDGE_3F
	(void)new TemplateTypeClass(F01);				//	TEMPLATE_F01
	(void)new TemplateTypeClass(F02);				//	TEMPLATE_F02
	(void)new TemplateTypeClass(F03);				//	TEMPLATE_F03
	(void)new TemplateTypeClass(F04);				//	TEMPLATE_F04
	(void)new TemplateTypeClass(F05);				//	TEMPLATE_F05
	(void)new TemplateTypeClass(F06);				//	TEMPLATE_F06
	(void)new TemplateTypeClass(ARRO0001);			//	TEMPLATE_ARRO0001
	(void)new TemplateTypeClass(ARRO0002);			//	TEMPLATE_ARRO0002
	(void)new TemplateTypeClass(ARRO0003);			//	TEMPLATE_ARRO0003
	(void)new TemplateTypeClass(ARRO0004);			//	TEMPLATE_ARRO0004
	(void)new TemplateTypeClass(ARRO0005);			//	TEMPLATE_ARRO0005
	(void)new TemplateTypeClass(ARRO0006);			//	TEMPLATE_ARRO0006
	(void)new TemplateTypeClass(ARRO0007);			//	TEMPLATE_ARRO0007
	(void)new TemplateTypeClass(ARRO0008);			//	TEMPLATE_ARRO0008
	(void)new TemplateTypeClass(ARRO0009);			//	TEMPLATE_ARRO0009
	(void)new TemplateTypeClass(ARRO0010);			//	TEMPLATE_ARRO0010
	(void)new TemplateTypeClass(ARRO0011);			//	TEMPLATE_ARRO0011
	(void)new TemplateTypeClass(ARRO0012);			//	TEMPLATE_ARRO0012
	(void)new TemplateTypeClass(ARRO0013);			//	TEMPLATE_ARRO0013
	(void)new TemplateTypeClass(ARRO0014);			//	TEMPLATE_ARRO0014
	(void)new TemplateTypeClass(ARRO0015);			//	TEMPLATE_ARRO0015
	(void)new TemplateTypeClass(FLOR0001);			//	TEMPLATE_FLOR0001
	(void)new TemplateTypeClass(FLOR0002);			//	TEMPLATE_FLOR0002
	(void)new TemplateTypeClass(FLOR0003);			//	TEMPLATE_FLOR0003
	(void)new TemplateTypeClass(FLOR0004);			//	TEMPLATE_FLOR0004
	(void)new TemplateTypeClass(FLOR0005);			//	TEMPLATE_FLOR0005
	(void)new TemplateTypeClass(FLOR0006);			//	TEMPLATE_FLOR0006
	(void)new TemplateTypeClass(FLOR0007);			//	TEMPLATE_FLOR0007
	(void)new TemplateTypeClass(GFLR0001);			//	TEMPLATE_GFLR0001
	(void)new TemplateTypeClass(GFLR0002);			//	TEMPLATE_GFLR0002
	(void)new TemplateTypeClass(GFLR0003);			//	TEMPLATE_GFLR0003
	(void)new TemplateTypeClass(GFLR0004);			//	TEMPLATE_GFLR0004
	(void)new TemplateTypeClass(GFLR0005);			//	TEMPLATE_GFLR0005
	(void)new TemplateTypeClass(GSTR0001);			//	TEMPLATE_GSTR0001
	(void)new TemplateTypeClass(GSTR0002);			//	TEMPLATE_GSTR0002
	(void)new TemplateTypeClass(GSTR0003);			//	TEMPLATE_GSTR0003
	(void)new TemplateTypeClass(GSTR0004);			//	TEMPLATE_GSTR0004
	(void)new TemplateTypeClass(GSTR0005);			//	TEMPLATE_GSTR0005
	(void)new TemplateTypeClass(GSTR0006);			//	TEMPLATE_GSTR0006
	(void)new TemplateTypeClass(GSTR0007);			//	TEMPLATE_GSTR0007
	(void)new TemplateTypeClass(GSTR0008);			//	TEMPLATE_GSTR0008
	(void)new TemplateTypeClass(GSTR0009);			//	TEMPLATE_GSTR0009
	(void)new TemplateTypeClass(GSTR0010);			//	TEMPLATE_GSTR0010
	(void)new TemplateTypeClass(GSTR0011);			//	TEMPLATE_GSTR0011
	(void)new TemplateTypeClass(LWAL0001);			//	TEMPLATE_LWAL0001
	(void)new TemplateTypeClass(LWAL0002);			//	TEMPLATE_LWAL0002
	(void)new TemplateTypeClass(LWAL0003);			//	TEMPLATE_LWAL0003
	(void)new TemplateTypeClass(LWAL0004);			//	TEMPLATE_LWAL0004
	(void)new TemplateTypeClass(LWAL0005);			//	TEMPLATE_LWAL0005
	(void)new TemplateTypeClass(LWAL0006);			//	TEMPLATE_LWAL0006
	(void)new TemplateTypeClass(LWAL0007);			//	TEMPLATE_LWAL0007
	(void)new TemplateTypeClass(LWAL0008);			//	TEMPLATE_LWAL0008
	(void)new TemplateTypeClass(LWAL0009);			//	TEMPLATE_LWAL0009
	(void)new TemplateTypeClass(LWAL0010);			//	TEMPLATE_LWAL0010
	(void)new TemplateTypeClass(LWAL0011);			//	TEMPLATE_LWAL0011
	(void)new TemplateTypeClass(LWAL0012);			//	TEMPLATE_LWAL0012
	(void)new TemplateTypeClass(LWAL0013);			//	TEMPLATE_LWAL0013
	(void)new TemplateTypeClass(LWAL0014);			//	TEMPLATE_LWAL0014
	(void)new TemplateTypeClass(LWAL0015);			//	TEMPLATE_LWAL0015
	(void)new TemplateTypeClass(LWAL0016);			//	TEMPLATE_LWAL0016
	(void)new TemplateTypeClass(LWAL0017);			//	TEMPLATE_LWAL0017
	(void)new TemplateTypeClass(LWAL0018);			//	TEMPLATE_LWAL0018
	(void)new TemplateTypeClass(LWAL0019);			//	TEMPLATE_LWAL0019
	(void)new TemplateTypeClass(LWAL0020);			//	TEMPLATE_LWAL0020
	(void)new TemplateTypeClass(LWAL0021);			//	TEMPLATE_LWAL0021
	(void)new TemplateTypeClass(LWAL0022);			//	TEMPLATE_LWAL0022
	(void)new TemplateTypeClass(LWAL0023);			//	TEMPLATE_LWAL0023
	(void)new TemplateTypeClass(LWAL0024);			//	TEMPLATE_LWAL0024
	(void)new TemplateTypeClass(LWAL0025);			//	TEMPLATE_LWAL0025
	(void)new TemplateTypeClass(LWAL0026);			//	TEMPLATE_LWAL0026
	(void)new TemplateTypeClass(LWAL0027);			//	TEMPLATE_LWAL0027
	(void)new TemplateTypeClass(STRP0001);			//	TEMPLATE_STRP0001
	(void)new TemplateTypeClass(STRP0002);			//	TEMPLATE_STRP0002
	(void)new TemplateTypeClass(STRP0003);			//	TEMPLATE_STRP0003
	(void)new TemplateTypeClass(STRP0004);			//	TEMPLATE_STRP0004
	(void)new TemplateTypeClass(STRP0005);			//	TEMPLATE_STRP0005
	(void)new TemplateTypeClass(STRP0006);			//	TEMPLATE_STRP0006
	(void)new TemplateTypeClass(STRP0007);			//	TEMPLATE_STRP0007
	(void)new TemplateTypeClass(STRP0008);			//	TEMPLATE_STRP0008
	(void)new TemplateTypeClass(STRP0009);			//	TEMPLATE_STRP0009
	(void)new TemplateTypeClass(STRP0010);			//	TEMPLATE_STRP0010
	(void)new TemplateTypeClass(STRP0011);			//	TEMPLATE_STRP0011
	(void)new TemplateTypeClass(WALL0001);			//	TEMPLATE_WALL0001
	(void)new TemplateTypeClass(WALL0002);			//	TEMPLATE_WALL0002
	(void)new TemplateTypeClass(WALL0003);			//	TEMPLATE_WALL0003
	(void)new TemplateTypeClass(WALL0004);			//	TEMPLATE_WALL0004
	(void)new TemplateTypeClass(WALL0005);			//	TEMPLATE_WALL0005
	(void)new TemplateTypeClass(WALL0006);			//	TEMPLATE_WALL0006
	(void)new TemplateTypeClass(WALL0007);			//	TEMPLATE_WALL0007
	(void)new TemplateTypeClass(WALL0008);			//	TEMPLATE_WALL0008
	(void)new TemplateTypeClass(WALL0009);			//	TEMPLATE_WALL0009
	(void)new TemplateTypeClass(WALL0010);			//	TEMPLATE_WALL0010
	(void)new TemplateTypeClass(WALL0011);			//	TEMPLATE_WALL0011
	(void)new TemplateTypeClass(WALL0012);			//	TEMPLATE_WALL0012
	(void)new TemplateTypeClass(WALL0013);			//	TEMPLATE_WALL0013
	(void)new TemplateTypeClass(WALL0014);			//	TEMPLATE_WALL0014
	(void)new TemplateTypeClass(WALL0015);			//	TEMPLATE_WALL0015
	(void)new TemplateTypeClass(WALL0016);			//	TEMPLATE_WALL0016
	(void)new TemplateTypeClass(WALL0017);			//	TEMPLATE_WALL0017
	(void)new TemplateTypeClass(WALL0018);			//	TEMPLATE_WALL0018
	(void)new TemplateTypeClass(WALL0019);			//	TEMPLATE_WALL0019
	(void)new TemplateTypeClass(WALL0020);			//	TEMPLATE_WALL0020
	(void)new TemplateTypeClass(WALL0021);			//	TEMPLATE_WALL0021
	(void)new TemplateTypeClass(WALL0022);			//	TEMPLATE_WALL0022
	(void)new TemplateTypeClass(WALL0023);			//	TEMPLATE_WALL0023
	(void)new TemplateTypeClass(WALL0024);			//	TEMPLATE_WALL0024
	(void)new TemplateTypeClass(WALL0025);			//	TEMPLATE_WALL0025
	(void)new TemplateTypeClass(WALL0026);			//	TEMPLATE_WALL0026
	(void)new TemplateTypeClass(WALL0027);			//	TEMPLATE_WALL0027
	(void)new TemplateTypeClass(WALL0028);			//	TEMPLATE_WALL0028
	(void)new TemplateTypeClass(WALL0029);			//	TEMPLATE_WALL0029
	(void)new TemplateTypeClass(WALL0030);			//	TEMPLATE_WALL0030
	(void)new TemplateTypeClass(WALL0031);			//	TEMPLATE_WALL0031
	(void)new TemplateTypeClass(WALL0032);			//	TEMPLATE_WALL0032
	(void)new TemplateTypeClass(WALL0033);			//	TEMPLATE_WALL0033
	(void)new TemplateTypeClass(WALL0034);			//	TEMPLATE_WALL0034
	(void)new TemplateTypeClass(WALL0035);			//	TEMPLATE_WALL0035
	(void)new TemplateTypeClass(WALL0036);			//	TEMPLATE_WALL0036
	(void)new TemplateTypeClass(WALL0037);			//	TEMPLATE_WALL0037
	(void)new TemplateTypeClass(WALL0038);			//	TEMPLATE_WALL0038
	(void)new TemplateTypeClass(WALL0039);			//	TEMPLATE_WALL0039
	(void)new TemplateTypeClass(WALL0040);			//	TEMPLATE_WALL0040
	(void)new TemplateTypeClass(WALL0041);			//	TEMPLATE_WALL0041
	(void)new TemplateTypeClass(WALL0042);			//	TEMPLATE_WALL0042
	(void)new TemplateTypeClass(WALL0043);			//	TEMPLATE_WALL0043
	(void)new TemplateTypeClass(WALL0044);			//	TEMPLATE_WALL0044
	(void)new TemplateTypeClass(WALL0045);			//	TEMPLATE_WALL0045
	(void)new TemplateTypeClass(WALL0046);			//	TEMPLATE_WALL0046
	(void)new TemplateTypeClass(WALL0047);			//	TEMPLATE_WALL0047
	(void)new TemplateTypeClass(WALL0048);			//	TEMPLATE_WALL0048
	(void)new TemplateTypeClass(WALL0049);			//	TEMPLATE_WALL0049
	(void)new TemplateTypeClass(Bridge1h);			//	TEMPLATE_BRIDGE1H
	(void)new TemplateTypeClass(Bridge2h);			//	TEMPLATE_BRIDGE2H

	(void)new TemplateTypeClass(Bridge1ax);		//	TEMPLATE_BRIDGE_1AX
	(void)new TemplateTypeClass(Bridge2ax);		//	TEMPLATE_BRIDGE_2AX
	(void)new TemplateTypeClass(Bridge1x);			//	TEMPLATE_BRIDGE1X
	(void)new TemplateTypeClass(Bridge2x);			//	TEMPLATE_BRIDGE2X

	(void)new TemplateTypeClass(Xtra0001);			//	TEMPLATE_XTRA0001
	(void)new TemplateTypeClass(Xtra0002);			//	TEMPLATE_XTRA0002
	(void)new TemplateTypeClass(Xtra0003);			//	TEMPLATE_XTRA0003
	(void)new TemplateTypeClass(Xtra0004);			//	TEMPLATE_XTRA0004
	(void)new TemplateTypeClass(Xtra0005);			//	TEMPLATE_XTRA0005
	(void)new TemplateTypeClass(Xtra0006);			//	TEMPLATE_XTRA0006
	(void)new TemplateTypeClass(Xtra0007);			//	TEMPLATE_XTRA0007
	(void)new TemplateTypeClass(Xtra0008);			//	TEMPLATE_XTRA0008
	(void)new TemplateTypeClass(Xtra0009);			//	TEMPLATE_XTRA0009
	(void)new TemplateTypeClass(Xtra0010);			//	TEMPLATE_XTRA0010
	(void)new TemplateTypeClass(Xtra0011);			//	TEMPLATE_XTRA0011
	(void)new TemplateTypeClass(Xtra0012);			//	TEMPLATE_XTRA0012
	(void)new TemplateTypeClass(Xtra0013);			//	TEMPLATE_XTRA0013
	(void)new TemplateTypeClass(Xtra0014);			//	TEMPLATE_XTRA0014
	(void)new TemplateTypeClass(Xtra0015);			//	TEMPLATE_XTRA0015
	(void)new TemplateTypeClass(Xtra0016);			//	TEMPLATE_XTRA0016

#ifdef FIXIT_ANTS
	(void)new TemplateTypeClass(AntHill);			//	TEMPLATE_ROAD36
#endif
	(void)new TemplateTypeClass(K11);			    //	TEMPLATE_K11  401
	(void)new TemplateTypeClass(K12);			    //	TEMPLATE_K12  402
	(void)new TemplateTypeClass(K13);			    //	TEMPLATE_K13  403
	(void)new TemplateTypeClass(K14);			    //	TEMPLATE_K14  404
	(void)new TemplateTypeClass(K21);			    //	TEMPLATE_K21  405
	(void)new TemplateTypeClass(K22);			    //	TEMPLATE_K22  406
	(void)new TemplateTypeClass(K23);			    //	TEMPLATE_K23  407
	(void)new TemplateTypeClass(K24);			    //	TEMPLATE_K24  408
	(void)new TemplateTypeClass(K31);			    //	TEMPLATE_K31  409
	(void)new TemplateTypeClass(K32);			    //	TEMPLATE_K32  410
	(void)new TemplateTypeClass(K33);			    //	TEMPLATE_K33  411
	(void)new TemplateTypeClass(K34);			    //	TEMPLATE_K34  412
	(void)new TemplateTypeClass(K35);			    //	TEMPLATE_K35  413
	(void)new TemplateTypeClass(K36);			    //	TEMPLATE_K36  414
	(void)new TemplateTypeClass(K41);			    //	TEMPLATE_K41  415
	(void)new TemplateTypeClass(K42);			    //	TEMPLATE_K42  416
	(void)new TemplateTypeClass(K43);			    //	TEMPLATE_K43  417
	(void)new TemplateTypeClass(K44);			    //	TEMPLATE_K44  418
	(void)new TemplateTypeClass(K45);			    //	TEMPLATE_K45  419
	(void)new TemplateTypeClass(K46);			    //	TEMPLATE_K46  420
	(void)new TemplateTypeClass(K51);			    //	TEMPLATE_K51  421
	(void)new TemplateTypeClass(K52);			    //	TEMPLATE_K52  422
	(void)new TemplateTypeClass(K53);			    //	TEMPLATE_K53  423
	(void)new TemplateTypeClass(K54);			    //	TEMPLATE_K54  424
	(void)new TemplateTypeClass(K55);			    //	TEMPLATE_K55  425
	(void)new TemplateTypeClass(K56);			    //	TEMPLATE_K56  426
	(void)new TemplateTypeClass(K61);			    //	TEMPLATE_K61  427
	(void)new TemplateTypeClass(K62);			    //	TEMPLATE_K62  428
	(void)new TemplateTypeClass(K63);			    //	TEMPLATE_K63  429
	(void)new TemplateTypeClass(K64);			    //	TEMPLATE_K64  430
	(void)new TemplateTypeClass(K65);			    //	TEMPLATE_K65  431
	(void)new TemplateTypeClass(K66);			    //	TEMPLATE_K66  432
	(void)new TemplateTypeClass(M11);			    //	TEMPLATE_M11  433
	(void)new TemplateTypeClass(M12);			    //	TEMPLATE_M12  434
	(void)new TemplateTypeClass(M13);			    //	TEMPLATE_M13  435
	(void)new TemplateTypeClass(M14);			    //	TEMPLATE_M14  436
	(void)new TemplateTypeClass(M21);			    //	TEMPLATE_M21  437
	(void)new TemplateTypeClass(M22);			    //	TEMPLATE_M22  438
	(void)new TemplateTypeClass(M23);			    //	TEMPLATE_M23  439
	(void)new TemplateTypeClass(M24);			    //	TEMPLATE_M24  440
	(void)new TemplateTypeClass(M31);			    //	TEMPLATE_M31  441
	(void)new TemplateTypeClass(M32);			    //	TEMPLATE_M32  442
	(void)new TemplateTypeClass(M33);			    //	TEMPLATE_M33  443
	(void)new TemplateTypeClass(M34);			    //	TEMPLATE_M34  444
	(void)new TemplateTypeClass(M35);			    //	TEMPLATE_M35  445
	(void)new TemplateTypeClass(M36);			    //	TEMPLATE_M36  446
	(void)new TemplateTypeClass(M41);			    //	TEMPLATE_M41  447
	(void)new TemplateTypeClass(M42);			    //	TEMPLATE_M42  448
	(void)new TemplateTypeClass(M43);			    //	TEMPLATE_M43  449
	(void)new TemplateTypeClass(M44);			    //	TEMPLATE_M44  450
	(void)new TemplateTypeClass(M45);			    //	TEMPLATE_M45  451
	(void)new TemplateTypeClass(M46);			    //	TEMPLATE_M46  452
	(void)new TemplateTypeClass(M51);			    //	TEMPLATE_M51  453
	(void)new TemplateTypeClass(M52);			    //	TEMPLATE_M52  454
	(void)new TemplateTypeClass(M53);			    //	TEMPLATE_M53  455
	(void)new TemplateTypeClass(M54);			    //	TEMPLATE_M54  456
	(void)new TemplateTypeClass(M55);			    //	TEMPLATE_M55  457
	(void)new TemplateTypeClass(M56);			    //	TEMPLATE_M56  458
	(void)new TemplateTypeClass(M61);			    //	TEMPLATE_M61  459
	(void)new TemplateTypeClass(M62);			    //	TEMPLATE_M62  460
	(void)new TemplateTypeClass(M63);			    //	TEMPLATE_M63  461
	(void)new TemplateTypeClass(M64);			    //	TEMPLATE_M64  462
	(void)new TemplateTypeClass(M65);			    //	TEMPLATE_M65  463
	(void)new TemplateTypeClass(M66);			    //	TEMPLATE_M66  464
	(void)new TemplateTypeClass(N11);			    //	TEMPLATE_N11  465
	(void)new TemplateTypeClass(N12);			    //	TEMPLATE_N12  466
	(void)new TemplateTypeClass(N13);			    //	TEMPLATE_N13  467
	(void)new TemplateTypeClass(N14);			    //	TEMPLATE_N14  468
	(void)new TemplateTypeClass(N21);			    //	TEMPLATE_N21  469
	(void)new TemplateTypeClass(N22);			    //	TEMPLATE_N22  470
	(void)new TemplateTypeClass(N23);			    //	TEMPLATE_N23  471
	(void)new TemplateTypeClass(N24);			    //	TEMPLATE_N24  472
	(void)new TemplateTypeClass(N31);			    //	TEMPLATE_N31  473
	(void)new TemplateTypeClass(N32);			    //	TEMPLATE_N32  474
	(void)new TemplateTypeClass(N33);			    //	TEMPLATE_N33  475
	(void)new TemplateTypeClass(N34);			    //	TEMPLATE_N34  476
	(void)new TemplateTypeClass(N35);			    //	TEMPLATE_N35  477
	(void)new TemplateTypeClass(N36);			    //	TEMPLATE_N36  478
	(void)new TemplateTypeClass(N41);			    //	TEMPLATE_N41  479
	(void)new TemplateTypeClass(N42);			    //	TEMPLATE_N42  480
	(void)new TemplateTypeClass(N43);			    //	TEMPLATE_N43  481
	(void)new TemplateTypeClass(N44);			    //	TEMPLATE_N44  482
	(void)new TemplateTypeClass(N45);			    //	TEMPLATE_N45  483
	(void)new TemplateTypeClass(N46);			    //	TEMPLATE_N46  484
	(void)new TemplateTypeClass(N51);			    //	TEMPLATE_N51  485
	(void)new TemplateTypeClass(N52);			    //	TEMPLATE_N52  486
	(void)new TemplateTypeClass(N53);			    //	TEMPLATE_N53  487
	(void)new TemplateTypeClass(N54);			    //	TEMPLATE_N54  488
	(void)new TemplateTypeClass(N55);			    //	TEMPLATE_N55  489
	(void)new TemplateTypeClass(N56);			    //	TEMPLATE_N56  490
	(void)new TemplateTypeClass(N61);			    //	TEMPLATE_N61  491
	(void)new TemplateTypeClass(N62);			    //	TEMPLATE_N62  492
	(void)new TemplateTypeClass(N63);			    //	TEMPLATE_N63  493
	(void)new TemplateTypeClass(N64);			    //	TEMPLATE_N64  494
	(void)new TemplateTypeClass(N65);			    //	TEMPLATE_N65  495
	(void)new TemplateTypeClass(N66);			    //	TEMPLATE_N66  496
	(void)new TemplateTypeClass(Q11);			    //	TEMPLATE_Q11  497
	(void)new TemplateTypeClass(Q12);			    //	TEMPLATE_Q12  498
	(void)new TemplateTypeClass(Q13);			    //	TEMPLATE_Q13  499
	(void)new TemplateTypeClass(Q14);			    //	TEMPLATE_Q14  500
	(void)new TemplateTypeClass(Q21);			    //	TEMPLATE_Q21  501
	(void)new TemplateTypeClass(Q22);			    //	TEMPLATE_Q22  502
	(void)new TemplateTypeClass(Q23);			    //	TEMPLATE_Q23  503
	(void)new TemplateTypeClass(Q24);			    //	TEMPLATE_Q24  504
	(void)new TemplateTypeClass(Q31);			    //	TEMPLATE_Q31  505
	(void)new TemplateTypeClass(Q32);			    //	TEMPLATE_Q32  506
	(void)new TemplateTypeClass(Q33);			    //	TEMPLATE_Q33  507
	(void)new TemplateTypeClass(Q34);			    //	TEMPLATE_Q34  508
	(void)new TemplateTypeClass(Q35);			    //	TEMPLATE_Q35  509
	(void)new TemplateTypeClass(Q36);			    //	TEMPLATE_Q36  510
	(void)new TemplateTypeClass(Q41);			    //	TEMPLATE_Q41  511
	(void)new TemplateTypeClass(Q42);			    //	TEMPLATE_Q42  512
	(void)new TemplateTypeClass(Q43);			    //	TEMPLATE_Q43  513
	(void)new TemplateTypeClass(Q44);			    //	TEMPLATE_Q44  514
	(void)new TemplateTypeClass(Q45);			    //	TEMPLATE_Q45  515
	(void)new TemplateTypeClass(Q46);			    //	TEMPLATE_Q46  516
	(void)new TemplateTypeClass(Q51);			    //	TEMPLATE_Q51  517
	(void)new TemplateTypeClass(Q52);			    //	TEMPLATE_Q52  518
	(void)new TemplateTypeClass(Q53);			    //	TEMPLATE_Q53  519
	(void)new TemplateTypeClass(Q54);			    //	TEMPLATE_Q54  520
	(void)new TemplateTypeClass(Q55);			    //	TEMPLATE_Q55  521
	(void)new TemplateTypeClass(Q56);			    //	TEMPLATE_Q56  522
	(void)new TemplateTypeClass(Q61);			    //	TEMPLATE_Q61  523
	(void)new TemplateTypeClass(Q62);			    //	TEMPLATE_Q62  524
	(void)new TemplateTypeClass(Q63);			    //	TEMPLATE_Q63  525
	(void)new TemplateTypeClass(Q64);			    //	TEMPLATE_Q64  526
	(void)new TemplateTypeClass(Q65);			    //	TEMPLATE_Q65  527
	(void)new TemplateTypeClass(Q66);			    //	TEMPLATE_Q66  528
	(void)new TemplateTypeClass(R11A);			    //	TEMPLATE_R11A  //529
	(void)new TemplateTypeClass(R11B);			    //	TEMPLATE_R11B  //530
	(void)new TemplateTypeClass(R11C);			    //	TEMPLATE_R11C  //531
	(void)new TemplateTypeClass(R11D);			    //	TEMPLATE_R11D  //532
	(void)new TemplateTypeClass(R11E);			    //	TEMPLATE_R11E  //533
	(void)new TemplateTypeClass(R11F);			    //	TEMPLATE_R11F  //534
	(void)new TemplateTypeClass(R11G);			    //	TEMPLATE_R11G  //535
	(void)new TemplateTypeClass(R11H);			    //	TEMPLATE_R11H  //536
	(void)new TemplateTypeClass(R11I);			    //	TEMPLATE_R11I  //537
	(void)new TemplateTypeClass(R11J);			    //	TEMPLATE_R11J  //538
	(void)new TemplateTypeClass(R11K);			    //	TEMPLATE_R11K  //539
	(void)new TemplateTypeClass(R11L);			    //	TEMPLATE_R11L  //540
	(void)new TemplateTypeClass(R11M);			    //	TEMPLATE_R11M  //541
	(void)new TemplateTypeClass(R11N);			    //	TEMPLATE_R11N  //542
	(void)new TemplateTypeClass(R11O);			    //	TEMPLATE_R11O  //543
	(void)new TemplateTypeClass(R11P);			    //	TEMPLATE_R11P  //544
	(void)new TemplateTypeClass(R11Q);			    //	TEMPLATE_R11Q  //545
	(void)new TemplateTypeClass(R11R);			    //	TEMPLATE_R11R  //546
	(void)new TemplateTypeClass(R11S);			    //	TEMPLATE_R11S  //547
	(void)new TemplateTypeClass(R11T);			    //	TEMPLATE_R11T  //548
	(void)new TemplateTypeClass(R11U);			    //	TEMPLATE_R11U  //549
	(void)new TemplateTypeClass(R11V);			    //	TEMPLATE_R11V  //550
	(void)new TemplateTypeClass(R11W);			    //	TEMPLATE_R11W  //551
	(void)new TemplateTypeClass(R11X);			    //	TEMPLATE_R11X  //552
	(void)new TemplateTypeClass(R11Y);			    //	TEMPLATE_R11Y  //553
	(void)new TemplateTypeClass(R11Z);			    //	TEMPLATE_R11Z  //554
	(void)new TemplateTypeClass(R11AA);			    //	TEMPLATE_R11AA  //555
	(void)new TemplateTypeClass(R11BB);			    //	TEMPLATE_R11BB  //556
	(void)new TemplateTypeClass(R11CC);			    //	TEMPLATE_R11CC  //557
	(void)new TemplateTypeClass(R11DD);			    //	TEMPLATE_R11DD  //558
	(void)new TemplateTypeClass(R11EE);			    //	TEMPLATE_R11EE  //559
	(void)new TemplateTypeClass(R11FF);			    //	TEMPLATE_R11FF  //560
	(void)new TemplateTypeClass(R11GG);			    //	TEMPLATE_R11GG  //561
	(void)new TemplateTypeClass(R11HH);			    //	TEMPLATE_R11HH  //562
	(void)new TemplateTypeClass(R11II);			    //	TEMPLATE_R11II  //563
	(void)new TemplateTypeClass(R11JJ);			    //	TEMPLATE_R11JJ  //564
	(void)new TemplateTypeClass(R11KK);			    //	TEMPLATE_R11KK  //565
	(void)new TemplateTypeClass(R11LL);			    //	TEMPLATE_R11LL  //566
	(void)new TemplateTypeClass(R11MM);			    //	TEMPLATE_R11MM  //567
	(void)new TemplateTypeClass(R11NN);			    //	TEMPLATE_R11NN  //568
	(void)new TemplateTypeClass(R11OO);			    //	TEMPLATE_R11OO  //569
	(void)new TemplateTypeClass(R11PP);			    //	TEMPLATE_R11PP  //570
	(void)new TemplateTypeClass(R11QQ);			    //	TEMPLATE_R11QQ  //571
	(void)new TemplateTypeClass(R11RR);			    //	TEMPLATE_R11RR  //572
	(void)new TemplateTypeClass(R11SS);			    //	TEMPLATE_R11SS  //573
	(void)new TemplateTypeClass(R11TT);			    //	TEMPLATE_R11TT  //574
	(void)new TemplateTypeClass(R11UU);			    //	TEMPLATE_R11UU  //575
	(void)new TemplateTypeClass(R11VV);			    //	TEMPLATE_R11VV  //576
	(void)new TemplateTypeClass(R11WW);			    //	TEMPLATE_R11WW  //577
	(void)new TemplateTypeClass(R11XX);			    //	TEMPLATE_R11XX  //578
	(void)new TemplateTypeClass(R11YY);			    //	TEMPLATE_R11YY  //579
	(void)new TemplateTypeClass(R11ZZ);			    //	TEMPLATE_R11ZZ  //580
	(void)new TemplateTypeClass(R22A);			    //	TEMPLATE_R22A  //581
	(void)new TemplateTypeClass(R22B);			    //	TEMPLATE_R22B  //582
	(void)new TemplateTypeClass(R22C);			    //	TEMPLATE_R22C  //583
	(void)new TemplateTypeClass(R22D);			    //	TEMPLATE_R22D  //584
	(void)new TemplateTypeClass(R22E);			    //	TEMPLATE_R22E  //585
	(void)new TemplateTypeClass(R22F);			    //	TEMPLATE_R22F  //586
	(void)new TemplateTypeClass(R22G);			    //	TEMPLATE_R22G  //587
	(void)new TemplateTypeClass(R22H);			    //	TEMPLATE_R22H  //588
	(void)new TemplateTypeClass(R22I);			    //	TEMPLATE_R22I  //589
	(void)new TemplateTypeClass(R22J);			    //	TEMPLATE_R22J  //590
	(void)new TemplateTypeClass(R22K);			    //	TEMPLATE_R22K  //591
	(void)new TemplateTypeClass(R22L);			    //	TEMPLATE_R22L  //592
	(void)new TemplateTypeClass(R22M);			    //	TEMPLATE_R22M  //593
	(void)new TemplateTypeClass(R22N);			    //	TEMPLATE_R22N  //594
	(void)new TemplateTypeClass(R22O);			    //	TEMPLATE_R22O  //595
	(void)new TemplateTypeClass(R22P);			    //	TEMPLATE_R22P  //596
	(void)new TemplateTypeClass(R22Q);			    //	TEMPLATE_R22Q  //597
	(void)new TemplateTypeClass(R22R);			    //	TEMPLATE_R22R  //598
	(void)new TemplateTypeClass(R22S);			    //	TEMPLATE_R22S  //599
	(void)new TemplateTypeClass(R22T);			    //	TEMPLATE_R22T  //600
	(void)new TemplateTypeClass(R22U);			    //	TEMPLATE_R22U  //601
	(void)new TemplateTypeClass(R22V);			    //	TEMPLATE_R22V  //602
	(void)new TemplateTypeClass(R22W);			    //	TEMPLATE_R22W  //603
	(void)new TemplateTypeClass(R22X);			    //	TEMPLATE_R22X  //604
	(void)new TemplateTypeClass(R22Y);			    //	TEMPLATE_R22Y  //605
	(void)new TemplateTypeClass(R22Z);			    //	TEMPLATE_R22Z  //606
	(void)new TemplateTypeClass(R22AA);			    //	TEMPLATE_R22AA  //607
	(void)new TemplateTypeClass(R22BB);			    //	TEMPLATE_R22BB  //608
	(void)new TemplateTypeClass(R22CC);			    //	TEMPLATE_R22CC  //609
	(void)new TemplateTypeClass(R22DD);			    //	TEMPLATE_R22DD  //610
	(void)new TemplateTypeClass(R22EE);			    //	TEMPLATE_R22EE  //611
	(void)new TemplateTypeClass(R22FF);			    //	TEMPLATE_R22FF  //612
	(void)new TemplateTypeClass(R22GG);			    //	TEMPLATE_R22GG  //613
	(void)new TemplateTypeClass(R22HH);			    //	TEMPLATE_R22HH  //614
	(void)new TemplateTypeClass(R22II);			    //	TEMPLATE_R22II  //615
	(void)new TemplateTypeClass(R22JJ);			    //	TEMPLATE_R22JJ  //616
	(void)new TemplateTypeClass(R22KK);			    //	TEMPLATE_R22KK  //617
	(void)new TemplateTypeClass(R22LL);			    //	TEMPLATE_R22LL  //618
	(void)new TemplateTypeClass(R22MM);			    //	TEMPLATE_R22MM  //619
	(void)new TemplateTypeClass(R22NN);			    //	TEMPLATE_R22NN  //620
	(void)new TemplateTypeClass(R22OO);			    //	TEMPLATE_R22OO  //621
	(void)new TemplateTypeClass(R22PP);			    //	TEMPLATE_R22PP  //622
	(void)new TemplateTypeClass(R22QQ);			    //	TEMPLATE_R22QQ  //623
	(void)new TemplateTypeClass(R22RR);			    //	TEMPLATE_R22RR  //624
	(void)new TemplateTypeClass(R22SS);			    //	TEMPLATE_R22SS  //625
	(void)new TemplateTypeClass(R22TT);			    //	TEMPLATE_R22TT  //626
	(void)new TemplateTypeClass(R22UU);			    //	TEMPLATE_R22UU  //627
	(void)new TemplateTypeClass(R22VV);			    //	TEMPLATE_R22VV  //628
	(void)new TemplateTypeClass(R22WW);			    //	TEMPLATE_R22WW  //629
	(void)new TemplateTypeClass(R22XX);			    //	TEMPLATE_R22XX  //630
	(void)new TemplateTypeClass(R22YY);			    //	TEMPLATE_R22YY  //631
	(void)new TemplateTypeClass(R22ZZ);			    //	TEMPLATE_R22ZZ  //632
	(void)new TemplateTypeClass(R33A);			    //	TEMPLATE_R33A  //633
	(void)new TemplateTypeClass(R33B);			    //	TEMPLATE_R33B  //634
	(void)new TemplateTypeClass(R33C);			    //	TEMPLATE_R33C  //635
	(void)new TemplateTypeClass(R33D);			    //	TEMPLATE_R33D  //636
	(void)new TemplateTypeClass(R33E);			    //	TEMPLATE_R33E  //637
	(void)new TemplateTypeClass(R33F);			    //	TEMPLATE_R33F  //638
	(void)new TemplateTypeClass(R33G);			    //	TEMPLATE_R33G  //639
	(void)new TemplateTypeClass(R33H);			    //	TEMPLATE_R33H  //640
	(void)new TemplateTypeClass(R33I);			    //	TEMPLATE_R33I  //641
	(void)new TemplateTypeClass(R33J);			    //	TEMPLATE_R33J  //642
	(void)new TemplateTypeClass(R33K);			    //	TEMPLATE_R33K  //643
	(void)new TemplateTypeClass(R33L);			    //	TEMPLATE_R33L  //644
	(void)new TemplateTypeClass(R33M);			    //	TEMPLATE_R33M  //645
	(void)new TemplateTypeClass(R33N);			    //	TEMPLATE_R33N  //646
	(void)new TemplateTypeClass(R33O);			    //	TEMPLATE_R33O  //647
	(void)new TemplateTypeClass(R33P);			    //	TEMPLATE_R33P  //648
	(void)new TemplateTypeClass(R33Q);			    //	TEMPLATE_R33Q  //649
	(void)new TemplateTypeClass(R33R);			    //	TEMPLATE_R33R  //650
	(void)new TemplateTypeClass(R33S);			    //	TEMPLATE_R33S  //651
	(void)new TemplateTypeClass(R33T);			    //	TEMPLATE_R33T  //652
	(void)new TemplateTypeClass(R33U);			    //	TEMPLATE_R33U  //653
	(void)new TemplateTypeClass(R33V);			    //	TEMPLATE_R33V  //654
	(void)new TemplateTypeClass(R33W);			    //	TEMPLATE_R33W  //655
	(void)new TemplateTypeClass(R33X);			    //	TEMPLATE_R33X  //656
	(void)new TemplateTypeClass(R33Y);			    //	TEMPLATE_R33Y  //657
	(void)new TemplateTypeClass(R33Z);			    //	TEMPLATE_R33Z  //658
	(void)new TemplateTypeClass(R33AA);			    //	TEMPLATE_R33AA  //659
	(void)new TemplateTypeClass(R33BB);			    //	TEMPLATE_R33BB  //660
	(void)new TemplateTypeClass(R33CC);			    //	TEMPLATE_R33CC  //661
	(void)new TemplateTypeClass(R33DD);			    //	TEMPLATE_R33DD  //662
	(void)new TemplateTypeClass(R33EE);			    //	TEMPLATE_R33EE  //663
	(void)new TemplateTypeClass(R33FF);			    //	TEMPLATE_R33FF  //664
	(void)new TemplateTypeClass(R33GG);			    //	TEMPLATE_R33GG  //665
	(void)new TemplateTypeClass(R33HH);			    //	TEMPLATE_R33HH  //666
	(void)new TemplateTypeClass(R33II);			    //	TEMPLATE_R33II  //667
	(void)new TemplateTypeClass(R33JJ);			    //	TEMPLATE_R33JJ  //668
	(void)new TemplateTypeClass(R33KK);			    //	TEMPLATE_R33KK  //669
	(void)new TemplateTypeClass(R33LL);			    //	TEMPLATE_R33LL  //670
	(void)new TemplateTypeClass(R33MM);			    //	TEMPLATE_R33MM  //671
	(void)new TemplateTypeClass(R33NN);			    //	TEMPLATE_R33NN  //672
	(void)new TemplateTypeClass(R33OO);			    //	TEMPLATE_R33OO  //673
	(void)new TemplateTypeClass(R33PP);			    //	TEMPLATE_R33PP  //674
	(void)new TemplateTypeClass(R33QQ);			    //	TEMPLATE_R33QQ  //675
	(void)new TemplateTypeClass(R33RR);			    //	TEMPLATE_R33RR  //676
	(void)new TemplateTypeClass(R33SS);			    //	TEMPLATE_R33SS  //677
	(void)new TemplateTypeClass(R33TT);			    //	TEMPLATE_R33TT  //678
	(void)new TemplateTypeClass(R33UU);			    //	TEMPLATE_R33UU  //679
	(void)new TemplateTypeClass(R33VV);			    //	TEMPLATE_R33VV  //680
	(void)new TemplateTypeClass(R33WW);			    //	TEMPLATE_R33WW  //681
	(void)new TemplateTypeClass(R33XX);			    //	TEMPLATE_R33XX  //682
	(void)new TemplateTypeClass(R33YY);			    //	TEMPLATE_R33YY  //683
	(void)new TemplateTypeClass(R33ZZ);			    //	TEMPLATE_R33ZZ  //684
	(void)new TemplateTypeClass(KK22A);			    //	TEMPLATE_KK22A  //685
	(void)new TemplateTypeClass(KK22B);			    //	TEMPLATE_KK22B  //686
	(void)new TemplateTypeClass(KK22C);			    //	TEMPLATE_KK22C  //687
	(void)new TemplateTypeClass(KK22D);			    //	TEMPLATE_KK22D  //688
	(void)new TemplateTypeClass(KK22E);			    //	TEMPLATE_KK22E  //689
	(void)new TemplateTypeClass(KK22F);			    //	TEMPLATE_KK22F  //690
	(void)new TemplateTypeClass(KK22G);			    //	TEMPLATE_KK22G  //691
	(void)new TemplateTypeClass(KK22H);			    //	TEMPLATE_KK22H  //692
	(void)new TemplateTypeClass(KK22I);			    //	TEMPLATE_KK22I  //693
	(void)new TemplateTypeClass(KK22J);			    //	TEMPLATE_KK22J  //694
	(void)new TemplateTypeClass(KK22K);			    //	TEMPLATE_KK22K  //695
	(void)new TemplateTypeClass(KK22L);			    //	TEMPLATE_KK22L  //696
	(void)new TemplateTypeClass(KK22M);			    //	TEMPLATE_KK22M  //697
	(void)new TemplateTypeClass(KK22N);			    //	TEMPLATE_KK22N  //698
	(void)new TemplateTypeClass(KK22O);			    //	TEMPLATE_KK22O  //699
	(void)new TemplateTypeClass(KK22P);			    //	TEMPLATE_KK22P  //700
	(void)new TemplateTypeClass(KK22Q);			    //	TEMPLATE_KK22Q  //701
	(void)new TemplateTypeClass(KK22R);			    //	TEMPLATE_KK22R  //702
	(void)new TemplateTypeClass(KK22S);			    //	TEMPLATE_KK22S  //703
	(void)new TemplateTypeClass(KK22T);			    //	TEMPLATE_KK22T  //704
	(void)new TemplateTypeClass(KK22U);			    //	TEMPLATE_KK22U  //705
	(void)new TemplateTypeClass(KK22V);			    //	TEMPLATE_KK22V  //706
	(void)new TemplateTypeClass(KK22W);			    //	TEMPLATE_KK22W  //707
	(void)new TemplateTypeClass(KK22X);			    //	TEMPLATE_KK22X  //708
	(void)new TemplateTypeClass(KK22Y);			    //	TEMPLATE_KK22Y  //709
	(void)new TemplateTypeClass(KK22Z);			    //	TEMPLATE_KK22Z  //710
	(void)new TemplateTypeClass(KK22AA);			    //	TEMPLATE_KK22AA  //711
	(void)new TemplateTypeClass(KK22BB);			    //	TEMPLATE_KK22BB  //712
	(void)new TemplateTypeClass(KK22CC);			    //	TEMPLATE_KK22CC  //713
	(void)new TemplateTypeClass(KK22DD);			    //	TEMPLATE_KK22DD  //714
	(void)new TemplateTypeClass(KK22EE);			    //	TEMPLATE_KK22EE  //715
	(void)new TemplateTypeClass(KK22FF);			    //	TEMPLATE_KK22FF  //716
	(void)new TemplateTypeClass(KK22GG);			    //	TEMPLATE_KK22GG  //717
	(void)new TemplateTypeClass(KK22HH);			    //	TEMPLATE_KK22HH  //718
	(void)new TemplateTypeClass(KK22II);			    //	TEMPLATE_KK22II  //719
	(void)new TemplateTypeClass(KK22JJ);			    //	TEMPLATE_KK22JJ  //720
	(void)new TemplateTypeClass(KK22KK);			    //	TEMPLATE_KK22KK  //721
	(void)new TemplateTypeClass(KK22LL);			    //	TEMPLATE_KK22LL  //722
	(void)new TemplateTypeClass(KK22MM);			    //	TEMPLATE_KK22MM  //723
	(void)new TemplateTypeClass(KK22NN);			    //	TEMPLATE_KK22NN  //724
	(void)new TemplateTypeClass(KK22OO);			    //	TEMPLATE_KK22OO  //725
	(void)new TemplateTypeClass(KK22PP);			    //	TEMPLATE_KK22PP  //726
	(void)new TemplateTypeClass(KK22QQ);			    //	TEMPLATE_KK22QQ  //727
	(void)new TemplateTypeClass(KK22RR);			    //	TEMPLATE_KK22RR  //728
	(void)new TemplateTypeClass(KK22SS);			    //	TEMPLATE_KK22SS  //729
	(void)new TemplateTypeClass(KK22TT);			    //	TEMPLATE_KK22TT  //730
	(void)new TemplateTypeClass(KK22UU);			    //	TEMPLATE_KK22UU  //731
	(void)new TemplateTypeClass(KK22VV);			    //	TEMPLATE_KK22VV  //732
	(void)new TemplateTypeClass(KK22WW);			    //	TEMPLATE_KK22WW  //733
	(void)new TemplateTypeClass(KK22XX);			    //	TEMPLATE_KK22XX  //734
	(void)new TemplateTypeClass(KK22YY);			    //	TEMPLATE_KK22YY  //735
	(void)new TemplateTypeClass(KK22ZZ);			    //	TEMPLATE_KK22ZZ  //736
	(void)new TemplateTypeClass(KK32A);			    //	TEMPLATE_KK32A  //737
	(void)new TemplateTypeClass(KK32B);			    //	TEMPLATE_KK32B  //738
	(void)new TemplateTypeClass(KK32C);			    //	TEMPLATE_KK32C  //739
	(void)new TemplateTypeClass(KK32D);			    //	TEMPLATE_KK32D  //740
	(void)new TemplateTypeClass(KK32E);			    //	TEMPLATE_KK32E  //741
	(void)new TemplateTypeClass(KK32F);			    //	TEMPLATE_KK32F  //742
	(void)new TemplateTypeClass(KK32G);			    //	TEMPLATE_KK32G  //743
	(void)new TemplateTypeClass(KK32H);			    //	TEMPLATE_KK32H  //744
	(void)new TemplateTypeClass(KK32I);			    //	TEMPLATE_KK32I  //745
	(void)new TemplateTypeClass(KK32J);			    //	TEMPLATE_KK32J  //746
	(void)new TemplateTypeClass(KK32K);			    //	TEMPLATE_KK32K  //747
	(void)new TemplateTypeClass(KK32L);			    //	TEMPLATE_KK32L  //748
	(void)new TemplateTypeClass(KK32M);			    //	TEMPLATE_KK32M  //749
	(void)new TemplateTypeClass(KK32N);			    //	TEMPLATE_KK32N  //750
	(void)new TemplateTypeClass(KK32O);			    //	TEMPLATE_KK32O  //751
	(void)new TemplateTypeClass(KK32P);			    //	TEMPLATE_KK32P  //752
	(void)new TemplateTypeClass(KK32Q);			    //	TEMPLATE_KK32Q  //753
	(void)new TemplateTypeClass(KK32R);			    //	TEMPLATE_KK32R  //754
	(void)new TemplateTypeClass(KK32S);			    //	TEMPLATE_KK32S  //755
	(void)new TemplateTypeClass(KK32T);			    //	TEMPLATE_KK32T  //756
	(void)new TemplateTypeClass(KK32U);			    //	TEMPLATE_KK32U  //757
	(void)new TemplateTypeClass(KK32V);			    //	TEMPLATE_KK32V  //758
	(void)new TemplateTypeClass(KK32W);			    //	TEMPLATE_KK32W  //759
	(void)new TemplateTypeClass(KK32X);			    //	TEMPLATE_KK32X  //760
	(void)new TemplateTypeClass(KK32Y);			    //	TEMPLATE_KK32Y  //761
	(void)new TemplateTypeClass(KK32Z);			    //	TEMPLATE_KK32Z  //762
	(void)new TemplateTypeClass(KK32AA);			    //	TEMPLATE_KK32AA  //763
	(void)new TemplateTypeClass(KK32BB);			    //	TEMPLATE_KK32BB  //764
	(void)new TemplateTypeClass(KK32CC);			    //	TEMPLATE_KK32CC  //765
	(void)new TemplateTypeClass(KK32DD);			    //	TEMPLATE_KK32DD  //766
	(void)new TemplateTypeClass(KK32EE);			    //	TEMPLATE_KK32EE  //767
	(void)new TemplateTypeClass(KK32FF);			    //	TEMPLATE_KK32FF  //768
	(void)new TemplateTypeClass(KK32GG);			    //	TEMPLATE_KK32GG  //769
	(void)new TemplateTypeClass(KK32HH);			    //	TEMPLATE_KK32HH  //770
	(void)new TemplateTypeClass(KK32II);			    //	TEMPLATE_KK32II  //771
	(void)new TemplateTypeClass(KK32JJ);			    //	TEMPLATE_KK32JJ  //772
	(void)new TemplateTypeClass(KK32KK);			    //	TEMPLATE_KK32KK  //773
	(void)new TemplateTypeClass(KK32LL);			    //	TEMPLATE_KK32LL  //774
	(void)new TemplateTypeClass(KK32MM);			    //	TEMPLATE_KK32MM  //775
	(void)new TemplateTypeClass(KK32NN);			    //	TEMPLATE_KK32NN  //776
	(void)new TemplateTypeClass(KK32OO);			    //	TEMPLATE_KK32OO  //777
	(void)new TemplateTypeClass(KK32PP);			    //	TEMPLATE_KK32PP  //778
	(void)new TemplateTypeClass(KK32QQ);			    //	TEMPLATE_KK32QQ  //779
	(void)new TemplateTypeClass(KK32RR);			    //	TEMPLATE_KK32RR  //780
	(void)new TemplateTypeClass(KK32SS);			    //	TEMPLATE_KK32SS  //781
	(void)new TemplateTypeClass(KK32TT);			    //	TEMPLATE_KK32TT  //782
	(void)new TemplateTypeClass(KK32UU);			    //	TEMPLATE_KK32UU  //783
	(void)new TemplateTypeClass(KK32VV);			    //	TEMPLATE_KK32VV  //784
	(void)new TemplateTypeClass(KK32WW);			    //	TEMPLATE_KK32WW  //785
	(void)new TemplateTypeClass(KK32XX);			    //	TEMPLATE_KK32XX  //786
	(void)new TemplateTypeClass(KK32YY);			    //	TEMPLATE_KK32YY  //787
	(void)new TemplateTypeClass(KK32ZZ);			    //	TEMPLATE_KK32ZZ  //788
	(void)new TemplateTypeClass(KK33A);			    //	TEMPLATE_KK33A  //789
	(void)new TemplateTypeClass(KK33B);			    //	TEMPLATE_KK33B  //790
	(void)new TemplateTypeClass(KK33C);			    //	TEMPLATE_KK33C  //791
	(void)new TemplateTypeClass(KK33D);			    //	TEMPLATE_KK33D  //792
	(void)new TemplateTypeClass(KK33E);			    //	TEMPLATE_KK33E  //793
	(void)new TemplateTypeClass(KK33F);			    //	TEMPLATE_KK33F  //794
	(void)new TemplateTypeClass(KK33G);			    //	TEMPLATE_KK33G  //795
	(void)new TemplateTypeClass(KK33H);			    //	TEMPLATE_KK33H  //796
	(void)new TemplateTypeClass(KK33I);			    //	TEMPLATE_KK33I  //797
	(void)new TemplateTypeClass(KK33J);			    //	TEMPLATE_KK33J  //798
	(void)new TemplateTypeClass(KK33K);			    //	TEMPLATE_KK33K  //799
	(void)new TemplateTypeClass(KK33L);			    //	TEMPLATE_KK33L  //800
	(void)new TemplateTypeClass(KK33M);			    //	TEMPLATE_KK33M  //801
	(void)new TemplateTypeClass(KK33N);			    //	TEMPLATE_KK33N  //802
	(void)new TemplateTypeClass(KK33O);			    //	TEMPLATE_KK33O  //803
	(void)new TemplateTypeClass(KK33P);			    //	TEMPLATE_KK33P  //804
	(void)new TemplateTypeClass(KK33Q);			    //	TEMPLATE_KK33Q  //805
	(void)new TemplateTypeClass(KK33R);			    //	TEMPLATE_KK33R  //806
	(void)new TemplateTypeClass(KK33S);			    //	TEMPLATE_KK33S  //807
	(void)new TemplateTypeClass(KK33T);			    //	TEMPLATE_KK33T  //808
	(void)new TemplateTypeClass(KK33U);			    //	TEMPLATE_KK33U  //809
	(void)new TemplateTypeClass(KK33V);			    //	TEMPLATE_KK33V  //810
	(void)new TemplateTypeClass(KK33W);			    //	TEMPLATE_KK33W  //811
	(void)new TemplateTypeClass(KK33X);			    //	TEMPLATE_KK33X  //812
	(void)new TemplateTypeClass(KK33Y);			    //	TEMPLATE_KK33Y  //813
	(void)new TemplateTypeClass(KK33Z);			    //	TEMPLATE_KK33Z  //814
	(void)new TemplateTypeClass(KK33AA);			    //	TEMPLATE_KK33AA  //815
	(void)new TemplateTypeClass(KK33BB);			    //	TEMPLATE_KK33BB  //816
	(void)new TemplateTypeClass(KK33CC);			    //	TEMPLATE_KK33CC  //817
	(void)new TemplateTypeClass(KK33DD);			    //	TEMPLATE_KK33DD  //818
	(void)new TemplateTypeClass(KK33EE);			    //	TEMPLATE_KK33EE  //819
	(void)new TemplateTypeClass(KK33FF);			    //	TEMPLATE_KK33FF  //820
	(void)new TemplateTypeClass(KK33GG);			    //	TEMPLATE_KK33GG  //821
	(void)new TemplateTypeClass(KK33HH);			    //	TEMPLATE_KK33HH  //822
	(void)new TemplateTypeClass(KK33II);			    //	TEMPLATE_KK33II  //823
	(void)new TemplateTypeClass(KK33JJ);			    //	TEMPLATE_KK33JJ  //824
	(void)new TemplateTypeClass(KK33KK);			    //	TEMPLATE_KK33KK  //825
	(void)new TemplateTypeClass(KK33LL);			    //	TEMPLATE_KK33LL  //826
	(void)new TemplateTypeClass(KK33MM);			    //	TEMPLATE_KK33MM  //827
	(void)new TemplateTypeClass(KK33NN);			    //	TEMPLATE_KK33NN  //828
	(void)new TemplateTypeClass(KK33OO);			    //	TEMPLATE_KK33OO  //829
	(void)new TemplateTypeClass(KK33PP);			    //	TEMPLATE_KK33PP  //830
	(void)new TemplateTypeClass(KK33QQ);			    //	TEMPLATE_KK33QQ  //831
	(void)new TemplateTypeClass(KK33RR);			    //	TEMPLATE_KK33RR  //832
	(void)new TemplateTypeClass(KK33SS);			    //	TEMPLATE_KK33SS  //833
	(void)new TemplateTypeClass(KK33TT);			    //	TEMPLATE_KK33TT  //834
	(void)new TemplateTypeClass(KK33UU);			    //	TEMPLATE_KK33UU  //835
	(void)new TemplateTypeClass(KK33VV);			    //	TEMPLATE_KK33VV  //836
	(void)new TemplateTypeClass(KK33WW);			    //	TEMPLATE_KK33WW  //837
	(void)new TemplateTypeClass(KK33XX);			    //	TEMPLATE_KK33XX  //838
	(void)new TemplateTypeClass(KK33YY);			    //	TEMPLATE_KK33YY  //839
	(void)new TemplateTypeClass(KK33ZZ);			    //	TEMPLATE_KK33ZZ  //840
	(void)new TemplateTypeClass(KK41A);			    //	TEMPLATE_KK41A  //841
	(void)new TemplateTypeClass(KK41B);			    //	TEMPLATE_KK41B  //842
	(void)new TemplateTypeClass(KK41C);			    //	TEMPLATE_KK41C  //843
	(void)new TemplateTypeClass(KK41D);			    //	TEMPLATE_KK41D  //844
	(void)new TemplateTypeClass(KK41E);			    //	TEMPLATE_KK41E  //845
	(void)new TemplateTypeClass(KK41F);			    //	TEMPLATE_KK41F  //846
	(void)new TemplateTypeClass(KK41G);			    //	TEMPLATE_KK41G  //847
	(void)new TemplateTypeClass(KK41H);			    //	TEMPLATE_KK41H  //848
	(void)new TemplateTypeClass(KK41I);			    //	TEMPLATE_KK41I  //849
	(void)new TemplateTypeClass(KK41J);			    //	TEMPLATE_KK41J  //850
	(void)new TemplateTypeClass(KK41K);			    //	TEMPLATE_KK41K  //851
	(void)new TemplateTypeClass(KK41L);			    //	TEMPLATE_KK41L  //852
	(void)new TemplateTypeClass(KK41M);			    //	TEMPLATE_KK41M  //853
	(void)new TemplateTypeClass(KK41N);			    //	TEMPLATE_KK41N  //854
	(void)new TemplateTypeClass(KK41O);			    //	TEMPLATE_KK41O  //855
	(void)new TemplateTypeClass(KK41P);			    //	TEMPLATE_KK41P  //856
	(void)new TemplateTypeClass(KK41Q);			    //	TEMPLATE_KK41Q  //857
	(void)new TemplateTypeClass(KK41R);			    //	TEMPLATE_KK41R  //858
	(void)new TemplateTypeClass(KK41S);			    //	TEMPLATE_KK41S  //859
	(void)new TemplateTypeClass(KK41T);			    //	TEMPLATE_KK41T  //860
	(void)new TemplateTypeClass(KK41U);			    //	TEMPLATE_KK41U  //861
	(void)new TemplateTypeClass(KK41V);			    //	TEMPLATE_KK41V  //862
	(void)new TemplateTypeClass(KK41W);			    //	TEMPLATE_KK41W  //863
	(void)new TemplateTypeClass(KK41X);			    //	TEMPLATE_KK41X  //864
	(void)new TemplateTypeClass(KK41Y);			    //	TEMPLATE_KK41Y  //865
	(void)new TemplateTypeClass(KK41Z);			    //	TEMPLATE_KK41Z  //866
	(void)new TemplateTypeClass(KK41AA);			    //	TEMPLATE_KK41AA  //867
	(void)new TemplateTypeClass(KK41BB);			    //	TEMPLATE_KK41BB  //868
	(void)new TemplateTypeClass(KK41CC);			    //	TEMPLATE_KK41CC  //869
	(void)new TemplateTypeClass(KK41DD);			    //	TEMPLATE_KK41DD  //870
	(void)new TemplateTypeClass(KK41EE);			    //	TEMPLATE_KK41EE  //871
	(void)new TemplateTypeClass(KK41FF);			    //	TEMPLATE_KK41FF  //872
	(void)new TemplateTypeClass(KK41GG);			    //	TEMPLATE_KK41GG  //873
	(void)new TemplateTypeClass(KK41HH);			    //	TEMPLATE_KK41HH  //874
	(void)new TemplateTypeClass(KK41II);			    //	TEMPLATE_KK41II  //875
	(void)new TemplateTypeClass(KK41JJ);			    //	TEMPLATE_KK41JJ  //876
	(void)new TemplateTypeClass(KK41KK);			    //	TEMPLATE_KK41KK  //877
	(void)new TemplateTypeClass(KK41LL);			    //	TEMPLATE_KK41LL  //878
	(void)new TemplateTypeClass(KK41MM);			    //	TEMPLATE_KK41MM  //879
	(void)new TemplateTypeClass(KK41NN);			    //	TEMPLATE_KK41NN  //880
	(void)new TemplateTypeClass(KK41OO);			    //	TEMPLATE_KK41OO  //881
	(void)new TemplateTypeClass(KK41PP);			    //	TEMPLATE_KK41PP  //882
	(void)new TemplateTypeClass(KK41QQ);			    //	TEMPLATE_KK41QQ  //883
	(void)new TemplateTypeClass(KK41RR);			    //	TEMPLATE_KK41RR  //884
	(void)new TemplateTypeClass(KK41SS);			    //	TEMPLATE_KK41SS  //885
	(void)new TemplateTypeClass(KK41TT);			    //	TEMPLATE_KK41TT  //886
	(void)new TemplateTypeClass(KK41UU);			    //	TEMPLATE_KK41UU  //887
	(void)new TemplateTypeClass(KK41VV);			    //	TEMPLATE_KK41VV  //888
	(void)new TemplateTypeClass(KK41WW);			    //	TEMPLATE_KK41WW  //889
	(void)new TemplateTypeClass(KK41XX);			    //	TEMPLATE_KK41XX  //890
	(void)new TemplateTypeClass(KK41YY);			    //	TEMPLATE_KK41YY  //891
	(void)new TemplateTypeClass(KK41ZZ);			    //	TEMPLATE_KK41ZZ  //892

	



}







void TemplateTypeClass::Init_Heap(void)
{
	/*
	**	These template type class objects must be allocated in the exact order that they
	**	are specified in the TemplateType enumeration. This is necessary because the heap
	**	allocation block index serves double duty as the type number index.
	*/
	(void)new TemplateTypeClass(Clear);				// TEMPLATE_CLEAR1
	(void)new TemplateTypeClass(Water);				// TEMPLATE_WATER
	(void)new TemplateTypeClass(Water2);			// TEMPLATE_WATER2
	(void)new TemplateTypeClass(Shore01);			// TEMPLATE_SHORE1
	(void)new TemplateTypeClass(Shore02);			// TEMPLATE_SHORE2
	(void)new TemplateTypeClass(Shore03);			// TEMPLATE_SHORE3
	(void)new TemplateTypeClass(Shore04);			// TEMPLATE_SHORE4
	(void)new TemplateTypeClass(Shore05);			// TEMPLATE_SHORE5
	(void)new TemplateTypeClass(Shore06);			// TEMPLATE_SHORE6
	(void)new TemplateTypeClass(Shore07);			// TEMPLATE_SHORE7
	(void)new TemplateTypeClass(Shore08);			// TEMPLATE_SHORE8
	(void)new TemplateTypeClass(Shore09);			// TEMPLATE_SHORE9
	(void)new TemplateTypeClass(Shore10);			// TEMPLATE_SHORE10
	(void)new TemplateTypeClass(Shore11);			//	TEMPLATE_SHORE11
	(void)new TemplateTypeClass(Shore12);			// TEMPLATE_SHORE12
	(void)new TemplateTypeClass(Shore13);			// TEMPLATE_SHORE13
	(void)new TemplateTypeClass(Shore14);			// TEMPLATE_SHORE14
	(void)new TemplateTypeClass(Shore15);			// TEMPLATE_SHORE15
	(void)new TemplateTypeClass(Shore16);			//	TEMPLATE_SHORE16
	(void)new TemplateTypeClass(Shore17);			//	TEMPLATE_SHORE17
	(void)new TemplateTypeClass(Shore18);			//	TEMPLATE_SHORE18
	(void)new TemplateTypeClass(Shore19);			// TEMPLATE_SHORE19
	(void)new TemplateTypeClass(Shore20);			// TEMPLATE_SHORE20
	(void)new TemplateTypeClass(Shore21);			// TEMPLATE_SHORE21
	(void)new TemplateTypeClass(Shore22);			//	TEMPLATE_SHORE22
	(void)new TemplateTypeClass(Shore23);			// TEMPLATE_SHORE23
	(void)new TemplateTypeClass(Shore24);			//	TEMPLATE_SHORE24
	(void)new TemplateTypeClass(Shore25);			//	TEMPLATE_SHORE25
	(void)new TemplateTypeClass(Shore26);			//	TEMPLATE_SHORE26
	(void)new TemplateTypeClass(Shore27);			//	TEMPLATE_SHORE27
	(void)new TemplateTypeClass(Shore28);			//	TEMPLATE_SHORE28
	(void)new TemplateTypeClass(Shore29);			//	TEMPLATE_SHORE29
	(void)new TemplateTypeClass(Shore30);			//	TEMPLATE_SHORE30
	(void)new TemplateTypeClass(Shore31);			//	TEMPLATE_SHORE31
	(void)new TemplateTypeClass(Shore32);			// TEMPLATE_SHORE32
	(void)new TemplateTypeClass(Shore33);			// TEMPLATE_SHORE33
	(void)new TemplateTypeClass(Shore34);			//	TEMPLATE_SHORE34
	(void)new TemplateTypeClass(Shore35);			//	TEMPLATE_SHORE35
	(void)new TemplateTypeClass(Shore36);			//	TEMPLATE_SHORE36
	(void)new TemplateTypeClass(Shore37);			//	TEMPLATE_SHORE37
	(void)new TemplateTypeClass(Shore38);			//	TEMPLATE_SHORE38
	(void)new TemplateTypeClass(Shore39);			//	TEMPLATE_SHORE39
	(void)new TemplateTypeClass(Shore40);			//	TEMPLATE_SHORE40
	(void)new TemplateTypeClass(Shore41);			//	TEMPLATE_SHORE41
	(void)new TemplateTypeClass(Shore42);			//	TEMPLATE_SHORE42
	(void)new TemplateTypeClass(Shore43);			//	TEMPLATE_SHORE43
	(void)new TemplateTypeClass(Shore44);			//	TEMPLATE_SHORE44
	(void)new TemplateTypeClass(Shore45);			//	TEMPLATE_SHORE45
	(void)new TemplateTypeClass(Shore46);			//	TEMPLATE_SHORE46
	(void)new TemplateTypeClass(Shore47);			//	TEMPLATE_SHORE47
	(void)new TemplateTypeClass(Shore48);			//	TEMPLATE_SHORE48
	(void)new TemplateTypeClass(Shore49);			//	TEMPLATE_SHORE49
	(void)new TemplateTypeClass(Shore50);			//	TEMPLATE_SHORE50
	(void)new TemplateTypeClass(Shore51);			//	TEMPLATE_SHORE51
	(void)new TemplateTypeClass(Shore52);			//	TEMPLATE_SHORE52
	(void)new TemplateTypeClass(Shore53);			//	TEMPLATE_SHORE53
	(void)new TemplateTypeClass(Shore54);			//	TEMPLATE_SHORE54
	(void)new TemplateTypeClass(Shore55);			//	TEMPLATE_SHORE55
	(void)new TemplateTypeClass(Shore56);			//	TEMPLATE_SHORE56
	(void)new TemplateTypeClass(ShoreCliff01);	//	TEMPLATE_SHORECLIFF01
	(void)new TemplateTypeClass(ShoreCliff02);	//	TEMPLATE_SHORECLIFF02
	(void)new TemplateTypeClass(ShoreCliff03);	//	TEMPLATE_SHORECLIFF03
	(void)new TemplateTypeClass(ShoreCliff04);	//	TEMPLATE_SHORECLIFF04
	(void)new TemplateTypeClass(ShoreCliff05);	//	TEMPLATE_SHORECLIFF05
	(void)new TemplateTypeClass(ShoreCliff06);	//	TEMPLATE_SHORECLIFF06
	(void)new TemplateTypeClass(ShoreCliff07);	//	TEMPLATE_SHORECLIFF07
	(void)new TemplateTypeClass(ShoreCliff08);	//	TEMPLATE_SHORECLIFF08
	(void)new TemplateTypeClass(ShoreCliff09);	//	TEMPLATE_SHORECLIFF09
	(void)new TemplateTypeClass(ShoreCliff10);	//	TEMPLATE_SHORECLIFF10
	(void)new TemplateTypeClass(ShoreCliff11);	//	TEMPLATE_SHORECLIFF11
	(void)new TemplateTypeClass(ShoreCliff12);	//	TEMPLATE_SHORECLIFF12
	(void)new TemplateTypeClass(ShoreCliff13);	//	TEMPLATE_SHORECLIFF13
	(void)new TemplateTypeClass(ShoreCliff14);	//	TEMPLATE_SHORECLIFF14
	(void)new TemplateTypeClass(ShoreCliff15);	//	TEMPLATE_SHORECLIFF15
	(void)new TemplateTypeClass(ShoreCliff16);	//	TEMPLATE_SHORECLIFF16
	(void)new TemplateTypeClass(ShoreCliff17);	//	TEMPLATE_SHORECLIFF17
	(void)new TemplateTypeClass(ShoreCliff18);	//	TEMPLATE_SHORECLIFF18
	(void)new TemplateTypeClass(ShoreCliff19);	//	TEMPLATE_SHORECLIFF19
	(void)new TemplateTypeClass(ShoreCliff20);	//	TEMPLATE_SHORECLIFF20
	(void)new TemplateTypeClass(ShoreCliff21);	//	TEMPLATE_SHORECLIFF21
	(void)new TemplateTypeClass(ShoreCliff22);	//	TEMPLATE_SHORECLIFF22
	(void)new TemplateTypeClass(ShoreCliff23);	//	TEMPLATE_SHORECLIFF23
	(void)new TemplateTypeClass(ShoreCliff24);	//	TEMPLATE_SHORECLIFF24
	(void)new TemplateTypeClass(ShoreCliff25);	//	TEMPLATE_SHORECLIFF25
	(void)new TemplateTypeClass(ShoreCliff26);	//	TEMPLATE_SHORECLIFF26
	(void)new TemplateTypeClass(ShoreCliff27);	//	TEMPLATE_SHORECLIFF27
	(void)new TemplateTypeClass(ShoreCliff28);	//	TEMPLATE_SHORECLIFF28
	(void)new TemplateTypeClass(ShoreCliff29);	//	TEMPLATE_SHORECLIFF29
	(void)new TemplateTypeClass(ShoreCliff30);	//	TEMPLATE_SHORECLIFF30
	(void)new TemplateTypeClass(ShoreCliff31);	//	TEMPLATE_SHORECLIFF31
	(void)new TemplateTypeClass(ShoreCliff32);	//	TEMPLATE_SHORECLIFF32
	(void)new TemplateTypeClass(ShoreCliff33);	//	TEMPLATE_SHORECLIFF33
	(void)new TemplateTypeClass(ShoreCliff34);	//	TEMPLATE_SHORECLIFF34
	(void)new TemplateTypeClass(ShoreCliff35);	//	TEMPLATE_SHORECLIFF35
	(void)new TemplateTypeClass(ShoreCliff36);	//	TEMPLATE_SHORECLIFF36
	(void)new TemplateTypeClass(ShoreCliff37);	//	TEMPLATE_SHORECLIFF37
	(void)new TemplateTypeClass(ShoreCliff38);	//	TEMPLATE_SHORECLIFF38
	(void)new TemplateTypeClass(Boulder1);			//	TEMPLATE_BOULDER1
	(void)new TemplateTypeClass(Boulder2);			//	TEMPLATE_BOULDER2
	(void)new TemplateTypeClass(Boulder3);			//	TEMPLATE_BOULDER3
	(void)new TemplateTypeClass(Boulder4);			// TEMPLATE_BOULDER4
	(void)new TemplateTypeClass(Boulder5);			//	TEMPLATE_BOULDER5
	(void)new TemplateTypeClass(Boulder6);			//	TEMPLATE_BOULDER6
	(void)new TemplateTypeClass(Patch01);			//	TEMPLATE_PATCH1
	(void)new TemplateTypeClass(Patch02);			//	TEMPLATE_PATCH2
	(void)new TemplateTypeClass(Patch03);			//	TEMPLATE_PATCH3
	(void)new TemplateTypeClass(Patch04);			//	TEMPLATE_PATCH4
	(void)new TemplateTypeClass(Patch07);			//	TEMPLATE_PATCH7
	(void)new TemplateTypeClass(Patch08);			//	TEMPLATE_PATCH8
	(void)new TemplateTypeClass(Patch13);			//	TEMPLATE_PATCH13
	(void)new TemplateTypeClass(Patch14);			//	TEMPLATE_PATCH14
	(void)new TemplateTypeClass(Patch15);			//	TEMPLATE_PATCH15
	(void)new TemplateTypeClass(River01);			//	TEMPLATE_RIVER1
	(void)new TemplateTypeClass(River02);			//	TEMPLATE_RIVER2
	(void)new TemplateTypeClass(River03);			//	TEMPLATE_RIVER3
	(void)new TemplateTypeClass(River04);			//	TEMPLATE_RIVER4
	(void)new TemplateTypeClass(River05);			//	TEMPLATE_RIVER5
	(void)new TemplateTypeClass(River06);			//	TEMPLATE_RIVER6
	(void)new TemplateTypeClass(River07);			//	TEMPLATE_RIVER7
	(void)new TemplateTypeClass(River08);			//	TEMPLATE_RIVER8
	(void)new TemplateTypeClass(River09);			//	TEMPLATE_RIVER9
	(void)new TemplateTypeClass(River10);			//	TEMPLATE_RIVER10
	(void)new TemplateTypeClass(River11);			//	TEMPLATE_RIVER11
	(void)new TemplateTypeClass(River12);			//	TEMPLATE_RIVER12
	(void)new TemplateTypeClass(River13);			//	TEMPLATE_RIVER13
	(void)new TemplateTypeClass(Falls1);			//	TEMPLATE_FALLS1
	(void)new TemplateTypeClass(Falls1a);			//	TEMPLATE_FALLS1A
	(void)new TemplateTypeClass(Falls2);			//	TEMPLATE_FALLS2
	(void)new TemplateTypeClass(Falls2a);			//	TEMPLATE_FALLS2A
	(void)new TemplateTypeClass(Ford1);				//	TEMPLATE_FORD1
	(void)new TemplateTypeClass(Ford2);				//	TEMPLATE_FORD2
	(void)new TemplateTypeClass(Bridge1);			//	TEMPLATE_BRIDGE1
	(void)new TemplateTypeClass(Bridge1d);			//	TEMPLATE_BRIDGE1D
	(void)new TemplateTypeClass(Bridge2);			//	TEMPLATE_BRIDGE2
	(void)new TemplateTypeClass(Bridge2d);			//	TEMPLATE_BRIDGE2D
	(void)new TemplateTypeClass(Slope01);			//	TEMPLATE_SLOPE1
	(void)new TemplateTypeClass(Slope02);			//	TEMPLATE_SLOPE2
	(void)new TemplateTypeClass(Slope03);			//	TEMPLATE_SLOPE3
	(void)new TemplateTypeClass(Slope04);			//	TEMPLATE_SLOPE4
	(void)new TemplateTypeClass(Slope05);			//	TEMPLATE_SLOPE5
	(void)new TemplateTypeClass(Slope06);			//	TEMPLATE_SLOPE6
	(void)new TemplateTypeClass(Slope07);			//	TEMPLATE_SLOPE7
	(void)new TemplateTypeClass(Slope08);			//	TEMPLATE_SLOPE8
	(void)new TemplateTypeClass(Slope09);			//	TEMPLATE_SLOPE9
	(void)new TemplateTypeClass(Slope10);			//	TEMPLATE_SLOPE10
	(void)new TemplateTypeClass(Slope11);			//	TEMPLATE_SLOPE11
	(void)new TemplateTypeClass(Slope12);			//	TEMPLATE_SLOPE12
	(void)new TemplateTypeClass(Slope13);			//	TEMPLATE_SLOPE13
	(void)new TemplateTypeClass(Slope14);			//	TEMPLATE_SLOPE14
	(void)new TemplateTypeClass(Slope15);			//	TEMPLATE_SLOPE15
	(void)new TemplateTypeClass(Slope16);			//	TEMPLATE_SLOPE16
	(void)new TemplateTypeClass(Slope17);			//	TEMPLATE_SLOPE17
	(void)new TemplateTypeClass(Slope18);			//	TEMPLATE_SLOPE18
	(void)new TemplateTypeClass(Slope19);			//	TEMPLATE_SLOPE19
	(void)new TemplateTypeClass(Slope20);			//	TEMPLATE_SLOPE20
	(void)new TemplateTypeClass(Slope21);			//	TEMPLATE_SLOPE21
	(void)new TemplateTypeClass(Slope22);			//	TEMPLATE_SLOPE22
	(void)new TemplateTypeClass(Slope23);			//	TEMPLATE_SLOPE23
	(void)new TemplateTypeClass(Slope24);			//	TEMPLATE_SLOPE24
	(void)new TemplateTypeClass(Slope25);			//	TEMPLATE_SLOPE25
	(void)new TemplateTypeClass(Slope26);			//	TEMPLATE_SLOPE26
	(void)new TemplateTypeClass(Slope27);			//	TEMPLATE_SLOPE27
	(void)new TemplateTypeClass(Slope28);			//	TEMPLATE_SLOPE28
	(void)new TemplateTypeClass(Slope29);			//	TEMPLATE_SLOPE29
	(void)new TemplateTypeClass(Slope30);			//	TEMPLATE_SLOPE30
	(void)new TemplateTypeClass(Slope31);			//	TEMPLATE_SLOPE31
	(void)new TemplateTypeClass(Slope32);			//	TEMPLATE_SLOPE32
	(void)new TemplateTypeClass(Slope33);			//	TEMPLATE_SLOPE33
	(void)new TemplateTypeClass(Slope34);			//	TEMPLATE_SLOPE34
	(void)new TemplateTypeClass(Slope35);			//	TEMPLATE_SLOPE35
	(void)new TemplateTypeClass(Slope36);			//	TEMPLATE_SLOPE36
	(void)new TemplateTypeClass(Slope37);			//	TEMPLATE_SLOPE37
	(void)new TemplateTypeClass(Slope38);			//	TEMPLATE_SLOPE38
	(void)new TemplateTypeClass(Road01);			//	TEMPLATE_ROAD1
	(void)new TemplateTypeClass(Road02);			//	TEMPLATE_ROAD2
	(void)new TemplateTypeClass(Road03);			//	TEMPLATE_ROAD3
	(void)new TemplateTypeClass(Road04);			//	TEMPLATE_ROAD4
	(void)new TemplateTypeClass(Road05);			//	TEMPLATE_ROAD5
	(void)new TemplateTypeClass(Road06);			//	TEMPLATE_ROAD6
	(void)new TemplateTypeClass(Road07);			//	TEMPLATE_ROAD7
	(void)new TemplateTypeClass(Road08);			//	TEMPLATE_ROAD8
	(void)new TemplateTypeClass(Road09);			//	TEMPLATE_ROAD9
	(void)new TemplateTypeClass(Road10);			//	TEMPLATE_ROAD10
	(void)new TemplateTypeClass(Road11);			//	TEMPLATE_ROAD11
	(void)new TemplateTypeClass(Road12);			//	TEMPLATE_ROAD12
	(void)new TemplateTypeClass(Road13);			//	TEMPLATE_ROAD13
	(void)new TemplateTypeClass(Road14);			//	TEMPLATE_ROAD14
	(void)new TemplateTypeClass(Road15);			//	TEMPLATE_ROAD15
	(void)new TemplateTypeClass(Road16);			//	TEMPLATE_ROAD16
	(void)new TemplateTypeClass(Road17);			//	TEMPLATE_ROAD17
	(void)new TemplateTypeClass(Road18);			//	TEMPLATE_ROAD18
	(void)new TemplateTypeClass(Road19);			//	TEMPLATE_ROAD19
	(void)new TemplateTypeClass(Road20);			//	TEMPLATE_ROAD20
	(void)new TemplateTypeClass(Road21);			//	TEMPLATE_ROAD21
	(void)new TemplateTypeClass(Road22);			//	TEMPLATE_ROAD22
	(void)new TemplateTypeClass(Road23);			//	TEMPLATE_ROAD23
	(void)new TemplateTypeClass(Road24);			//	TEMPLATE_ROAD24
	(void)new TemplateTypeClass(Road25);			//	TEMPLATE_ROAD25
	(void)new TemplateTypeClass(Road26);			//	TEMPLATE_ROAD26
	(void)new TemplateTypeClass(Road27);			//	TEMPLATE_ROAD27
	(void)new TemplateTypeClass(Road28);			//	TEMPLATE_ROAD28
	(void)new TemplateTypeClass(Road29);			//	TEMPLATE_ROAD29
	(void)new TemplateTypeClass(Road30);			//	TEMPLATE_ROAD30
	(void)new TemplateTypeClass(Road31);			//	TEMPLATE_ROAD31
	(void)new TemplateTypeClass(Road32);			//	TEMPLATE_ROAD32
	(void)new TemplateTypeClass(Road33);			//	TEMPLATE_ROAD33
	(void)new TemplateTypeClass(Road34);			//	TEMPLATE_ROAD34
	(void)new TemplateTypeClass(Road35);			//	TEMPLATE_ROAD35
	(void)new TemplateTypeClass(Road36);			//	TEMPLATE_ROAD36

	/*
	**	Separate out the list of new operator calls. Watcom bombs
	**	if they are kept together.
	*/
	_Watcom_Ugh_Hack();
}


/***********************************************************************************************
 * TemplateTypeClass::Land_Type -- Determines land type from template and icon number.         *
 *                                                                                             *
 *    This routine will convert the specified icon number into the appropriate land type. The  *
 *    land type can be determined from the embedded colors in the "control template" section   *
 *    of the original art file. This control information is encoded into the icon data file    *
 *    to be retrieved and interpreted as the program sees fit. The engine only recognizes      *
 *    the first 16 colors as control colors, so the control map color value serves as an       *
 *    index into a simple lookup table.                                                        *
 *                                                                                             *
 * INPUT:   icon  -- The icon number within this template that is to be examined and used      *
 *                   to determine the land type.                                               *
 *                                                                                             *
 * OUTPUT:  Returns with the land type that corresponds to the icon number specified.          *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   12/12/1995 JLB : Created.                                                                 *
 *=============================================================================================*/
LandType TemplateTypeClass::Land_Type(int icon) const
{
	IconsetClass const * icontrol = (IconsetClass const *)Get_Image_Data();

	if (icontrol != NULL) {
		unsigned char const * map = icontrol->Control_Map();
		if (map != NULL) {
			static LandType _land[16] = {
				LAND_CLEAR,
				LAND_CLEAR,
				LAND_CLEAR,
				LAND_CLEAR,			// Clear
				LAND_CLEAR,
				LAND_CLEAR,
				LAND_BEACH,			// Beach
				LAND_CLEAR,
				LAND_ROCK,			// Rock
				LAND_ROAD,			// Road
				LAND_WATER,			// Water
				LAND_RIVER,			//	River
				LAND_CLEAR,
				LAND_CLEAR,
				LAND_ROUGH,			// Rough
				LAND_CLEAR,
			};

			return(_land[map[icon % (icontrol->Map_Width() * icontrol->Map_Height())]]);
		}
	}
	return(LAND_CLEAR);
}


/***********************************************************************************************
 * TemplateTypeClass::From_Name -- Determine template from ASCII name.                         *
 *                                                                                             *
 *    This routine is used to determine the template number given only                         *
 *    an ASCII representation. The scenario loader uses this routine                           *
 *    to construct the map from the INI control file.                                          *
 *                                                                                             *
 * INPUT:   name  -- Pointer to the ASCII name of the template.                                *
 *                                                                                             *
 * OUTPUT:  Returns with the template number. If the name had no match,                        *
 *          then returns with TEMPLATE_NONE.                                                   *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   05/23/1994 JLB : Created.                                                                 *
 *=============================================================================================*/
TemplateType TemplateTypeClass::From_Name(char const * name)
{
	if (name != NULL) {
		for (TemplateType index = TEMPLATE_FIRST; index < TEMPLATE_COUNT; index++) {
			if (stricmp(As_Reference(index).IniName, name) == 0) {
				return(index);
			}
		}
	}
	return(TEMPLATE_NONE);
}


/***********************************************************************************************
 * TemplateTypeClass::Occupy_List -- Determines occupation list.                               *
 *                                                                                             *
 *    This routine is used to examine the template map and build an                            *
 *    occupation list. This list is used to render a template cursor as                        *
 *    well as placement of icon numbers.                                                       *
 *                                                                                             *
 * INPUT:   placement   -- Is this for placement legality checking only? The normal condition  *
 *                         is for marking occupation flags.                                    *
 *                                                                                             *
 * OUTPUT:  Returns with a pointer to the template occupation list.                            *
 *                                                                                             *
 * WARNINGS:   The return pointer is valid only until the next time that                       *
 *             this routine is called.                                                         *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   05/23/1994 JLB : Created.                                                                 *
 *   12/12/1995 JLB : Optimized for direct access to iconset data.                             *
 *=============================================================================================*/
short const * TemplateTypeClass::Occupy_List(bool) const
{
	static short _occupy[13*8+5];
	short	* ptr;

	IconsetClass const * iconset = (IconsetClass const *)Get_Image_Data();
	unsigned char const * map = iconset->Map_Data();

	ptr = &_occupy[0];
	for (int index = 0; index < Width * Height; index++) {
		if (*map++ != 0xFF) {
			*ptr++ = (index % Width) + ((index / Width)*MAP_CELL_W);
		}
	}
	*ptr = REFRESH_EOL;

	return((short const *)&_occupy[0]);
}


/***********************************************************************************************
 * TemplateTypeClass::Init -- Loads graphic data for templates.                                *
 *                                                                                             *
 *    This routine loads the template graphic data for all the template                        *
 *    type supported for the specified theater. This routine is called                         *
 *    whenever the theater for the scenario is first determined.                               *
 *                                                                                             *
 * INPUT:   theater  -- The theater that the template data is to be                            *
 *                      loaded for.                                                            *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   This routine goes to disk!                                                      *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   05/23/1994 JLB : Created.                                                                 *
 *   06/02/1994 JLB : Only handles iconset loading now (as it should).                         *
 *=============================================================================================*/
void TemplateTypeClass::Init(TheaterType theater)
{
	char fullname[_MAX_FNAME+_MAX_EXT];	// Fully constructed iconset name.
	void const * ptr;		// Working loaded iconset pointer.

	for (TemplateType index = TEMPLATE_FIRST; index < TEMPLATE_COUNT; index++) {
		TemplateTypeClass	const & tplate = As_Reference(index);

		((void const *&)tplate.ImageData) = NULL;
		if (tplate.Theater & (1<<theater)) {
			_makepath(fullname, NULL, NULL, tplate.IniName, Theaters[theater].Suffix);
			ptr = MFCD::Retrieve(fullname);
			((void const *&)tplate.ImageData) = ptr;

#ifdef WIN32
			Register_Icon_Set((void*)ptr, TRUE);		//Register icon set for video memory caching
#endif

			((unsigned char &)tplate.Width) = Get_IconSet_MapWidth(ptr);
			((unsigned char &)tplate.Height) = Get_IconSet_MapHeight(ptr);
		}
	}
}


#ifdef SCENARIO_EDITOR
/***********************************************************************************************
 * TemplateTypeClass::Display -- Displays a generic representation of template.                *
 *                                                                                             *
 *    This routine is used to display a generic view of the template                           *
 *    object. This is necessary for selection in the scenario editor.                          *
 *                                                                                             *
 * INPUT:   x,y   -- The coordinates to center the display about.                              *
 *                                                                                             *
 *          window-- The window to base the coordinates upon.                                  *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   05/23/1994 JLB : Created.                                                                 *
 *=============================================================================================*/
void TemplateTypeClass::Display(int x, int y, WindowNumberType window, HousesType ) const
{
	int	w,h;
	int	index;
	bool	scale;		// Should the template be half sized?

	w = Bound(Width, 1, 13);
	h = Bound(Height, 1, 8);
	scale = (w > 3 || h > 3);
	if (scale) {
		x -= (w * ICON_PIXEL_W) / 4;
		y -= (h * ICON_PIXEL_H) / 4;
	} else {
		x -= (w * ICON_PIXEL_W) / 2;
		y -= (h * ICON_PIXEL_H) / 2;
	}
	x += WindowList[window][WINDOWX];
	y += WindowList[window][WINDOWY];

	IconsetClass const * iconset = (IconsetClass const *)Get_Image_Data();
	unsigned char const * map = iconset->Map_Data();

	for (index = 0; index < w*h; index++) {
		if (map[index] != 0xFF) {
			HidPage.Draw_Stamp(iconset, index, 0, 0, NULL, WINDOW_MAIN);
			if (scale) {

				HidPage.Scale((*LogicPage), 0, 0,
					x + ((index % w)*(ICON_PIXEL_W/2)),
					y + ((index / w)*(ICON_PIXEL_H/2)),
					ICON_PIXEL_W, ICON_PIXEL_H,
					ICON_PIXEL_W/2, ICON_PIXEL_H/2, (char *)NULL);

			} else {
				HidPage.Blit((*LogicPage), 0, 0, x + ((index % w)*(ICON_PIXEL_W)),
					y + ((index / w)*(ICON_PIXEL_H)), ICON_PIXEL_W, ICON_PIXEL_H);
			}
		}
	}
}


/***********************************************************************************************
 * TemplateTypeClass::Prep_For_Add -- Prepares to add template to scenario.                    *
 *                                                                                             *
 *    This routine prepares a list of template objects so that the                             *
 *    scenario editor can use this list to display a dialog box. The                           *
 *    selection of a template object will allow its placement upon the                         *
 *    map.                                                                                     *
 *                                                                                             *
 * INPUT:   none                                                                               *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   05/23/1994 JLB : Created.                                                                 *
 *   05/28/1994 JLB : Only handles real templates now.                                         *
 *   06/04/1994 JLB : Uses map editing interface functions.                                    *
 *=============================================================================================*/
void TemplateTypeClass::Prep_For_Add(void)
{
	for (TemplateType index = TEMPLATE_CLEAR1; index < TEMPLATE_COUNT; index++) {
		if (As_Reference(index).Get_Image_Data()) {
			Map.Add_To_List(&As_Reference(index));
		}
	}
}
#endif


/***********************************************************************************************
 * TemplateTypeClass::Create_And_Place -- Creates and places a template object on the map.     *
 *                                                                                             *
 *    This support routine is used by the scenario editor to add a template object to the map  *
 *    and to the game.                                                                         *
 *                                                                                             *
 * INPUT:   cell  -- The cell to place the template object.                                    *
 *                                                                                             *
 * OUTPUT:  bool; Was the template object placed successfully?                                 *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   05/28/1994 JLB : Created.                                                                 *
 *=============================================================================================*/
bool TemplateTypeClass::Create_And_Place(CELL cell, HousesType ) const
{
	if (new TemplateClass(Type, cell)) {
		return(true);
	}
	return(false);
}


/***********************************************************************************************
 * TemplateTypeClass::Create_One_Of -- Creates an object of this template type.                *
 *                                                                                             *
 *    This routine will create an object of this type. For certain template objects, such      *
 *    as walls, it is actually created as a building. The "building" wall is converted into    *
 *    a template at the moment of placing down on the map.                                     *
 *                                                                                             *
 * INPUT:   none                                                                               *
 *                                                                                             *
 * OUTPUT:  Returns with a pointer to the appropriate object for this template type.           *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   06/18/1994 JLB : Created.                                                                 *
 *=============================================================================================*/
ObjectClass * TemplateTypeClass::Create_One_Of(HouseClass *) const
{
	return(new TemplateClass(Type, -1));
}


/***********************************************************************************************
 * TemplateTypeClass::One_Time -- Performs one-time initialization                             *
 *                                                                                             *
 * INPUT:   none                                                                               *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   08/12/1994 JLB : Created.                                                                 *
 *=============================================================================================*/
void TemplateTypeClass::One_Time(void)
{
}


/***********************************************************************************************
 * TemplateTypeClass::As_Reference -- Fetches a reference to the template specified.           *
 *                                                                                             *
 *    This will return a reference to the TemplateTypeClass requested.                         *
 *                                                                                             *
 * INPUT:   type  -- The template type to fetch a reference to.                                *
 *                                                                                             *
 * OUTPUT:  Returns with a reference to the template type class specified.                     *
 *                                                                                             *
 * WARNINGS:   Be sure to pass a valid type parameter. This routine doesn't check it for       *
 *             legality.                                                                       *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/03/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
TemplateTypeClass & TemplateTypeClass::As_Reference(TemplateType type)
{
	return(*TemplateTypes.Ptr(type));
}


COORDINATE TemplateTypeClass::Coord_Fixup(COORDINATE coord) const
{
	return Coord_Whole(coord);
}
