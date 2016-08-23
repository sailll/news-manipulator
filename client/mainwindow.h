#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QLabel>
#include <QFile>
#include <QApplication>

class MainWindow : public QMainWindow
{
    Q_OBJECT
private slots:
    void menu_add();
    void menu_exit();
    void menu_undo();
    void menu_find();
    void menu_selectAll();
    void menu_maxWindows();
    void menu_minWindows();

    void c0();
    void c1();
    void c2();
    void c3();
    void c4();
    void c5();
    void c6();
    void c7();
    void c8();
    void c9();

    void b0();
    void b1();
    void b2();
    void b3();
    void b4();
    void b5();
    void b6();
    void b7();
    void b8();
    void b9();
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QMenu *file,*edit,*windows,*history;
    QAction *add,*exit,*undo,*find,*select_all,*max_windows,*min_windows,*last[10];

    QPushButton *topic[10];
    QVBoxLayout *topic_group;

    QPushButton *button[10];
    QVBoxLayout *button_group;

    QTextEdit *LED;

    QLabel *key[5];

    int knn;

    void creatAction();
    void creatMenu();
    void creatTopic();
    void creatButton();
    void creatLED();
    void creatKey();

    void showTopic(int);
    void modifyText(int);

    void upDate();
    void kill();
};

#endif // MAINWINDOW_H
