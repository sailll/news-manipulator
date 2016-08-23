#ifndef MENU_H
#define MENU_H

#include <QMenu>
#include <QMenuBar>
#include <QAction>

class menu ::MainWindows
{
private slots:
    void _add();
    void _exit();
    void _undo();
    void _find();
    void _selectAll();
    void _maxWindows();
    void _minWindows();
private:
    QMenu *file,*edit,*windows,*history;
    QMenuBar *menubar;
    QAction *add,*exit,*undo,*find,*select_all,*max_windows,*min_windows,*last[10];

    void creatAction();
    void creatMenu();
    void creatMenuBar();
public:
    menu();
    ~menu();
};

#endif // MENU_H
