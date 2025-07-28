#pragma once

enum id {
	ID_MAINWINDOW = wxID_HIGHEST + 1,
	ID_BT1
};

typedef enum IDS {
	ID_1=0,
	ID_2,
	ID_3,
	ID_4,
	ID_5,
	ID_6,
	ID_7,
	ID_8,
	ID_9,
	ID_10
} id_button, id_menu;

//static const btnIDsSz=2;
static id_button btnIDs[]={
	ID_1,
	ID_2
};

static id_menu menIDs[]={
	ID_1,
	ID_2
};
