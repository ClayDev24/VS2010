#pragma once
#include <vector>
class CFrame;

typedef void (*fPtr)(CFrame*); // no args for this func.
static std::vector<fPtr> vFuncBtn;
static std::vector<fPtr> vFuncMen;

//******************<<_Button Functions_>>*******************
void Btn1Click(CFrame*);
void Btn2Click(CFrame*);
//******************<<_Menu Functions_>>*******************
void Men1Click(CFrame*);
void Men2Click(CFrame*);
void Men3Click(CFrame*);
void Men4Click(CFrame*);
void Men5Click(CFrame*);
void Men6Click(CFrame*);
void Men7Click(CFrame*);
void Men8Click(CFrame*);