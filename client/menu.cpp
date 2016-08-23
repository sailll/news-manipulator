#include "menu.h"

menu::menu()
{
     creatAction();
     creatMenu();
     creatMenuBar();
}

menu::~menu()
{}

//SLOT函数
void menu::_add()
{}

void menu::_exit()
{}

void menu::_undo()
{}

void menu::_find()
{}
void menu::_selectAll()
{}

void menu::_maxWindows()
{}

void menu::_minWindows()
{}


//菜单制作
void menu::creatAction()
{
    add=new QAction("Add",this);
    connect(add,SIGNAL(triggered()),this,SLOT(_add()));

    exit=new QAction("Exit",this);
    connect(exit,SIGNAL(triggered()),this,SLOT(_exit()));

    undo=new QAction("Undo",this);
    connect(undo,SIGNAL(triggered()),this,SLOT(_undo()));

    find=new QAction("Find",this);
    connect(find,SIGNAL(triggered()),this,SLOT(_find()));

    select_all=new QAction("Select all",this);
    connect(select_all,SIGNAL(triggered()),this,SLOT(_selectAll());

    max_windows=new QAction("Max windows",this);
    connect(max_windows,SIGNAL(triggered()),this,SLOT(_maxWindows()));

    min_windows=new QAction("Min windows",this);
    connect(min_windows,SIGNAL(triggered()),this,SLOT(_minWindows());
}

void menu::creatMenu()
{
    file=new QMenu("File",this);
    file->addAction(add);
    file->addAction(exit);

    edit=new QMenu("Edit",this);
    edit->addAction(undo);
    edit->addAction(find);
    edit->addAction(select_all);

    windows=new QMenu("Windows",this);
    windows->addAction(max_windows);
    windows->addAction(min_windows);
}

void menu::creatMenuBar()
{
    menubar=new QMenuBar;
    menubar->addMenu(file);
    menubar->addMenu(edit);
    menubar->addMenu(windows);
}
