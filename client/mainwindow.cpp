#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    knn=5;
    creatAction();
    creatMenu();
    creatTopic();
    this->resize(1000,550);
    creatButton();
    creatLED();
    creatKey();
}
MainWindow::~MainWindow()
{
    kill();
}

//每点一次标题，就全部更新一次
void MainWindow::upDate()
{
    creatAction();
    creatMenu();
    creatTopic();
    this->resize(1000,550);
    creatButton();
    creatLED();
    creatKey();
}
//每点一次标题，就销毁以前的UI
void MainWindow::kill()
{
    for(int i=0;i<10;i++)delete topic[i];
    for(int i=0;i<10;i++)delete button[i];
    delete LED;
    for(int i=0;i<knn;i++)delete key[i];
}
//菜单栏槽函数（自己补充完整）
void MainWindow::menu_add()
{}

void MainWindow::menu_exit()
{QApplication::quit();}

void MainWindow::menu_undo()
{}

void MainWindow::menu_find()
{}
void MainWindow::menu_selectAll()
{}

void MainWindow::menu_maxWindows()
{}

void MainWindow::menu_minWindows()
{}

//标题组槽函数（不用修改），我把十个槽函数转化为一个函数
void MainWindow::c0()
{showTopic(0);}
void MainWindow::c1()
{showTopic(1);}
void MainWindow::c2()
{showTopic(2);}
void MainWindow::c3()
{showTopic(3);}
void MainWindow::c4()
{showTopic(4);}
void MainWindow::c5()
{showTopic(5);}
void MainWindow::c6()
{showTopic(6);}
void MainWindow::c7()
{showTopic(7);}
void MainWindow::c8()
{showTopic(8);}
void MainWindow::c9()
{showTopic(9);}


//标题组函数（自己修改），一共十个按钮，函数参数是标题的序号
void MainWindow::showTopic(int ord)
{

}

//按钮组槽函数（不用修改），原理和标题组一样
void MainWindow::b0()
{modifyText(0);}
void MainWindow::b1()
{modifyText(1);}
void MainWindow::b2()
{modifyText(2);}
void MainWindow::b3()
{modifyText(3);}
void MainWindow::b4()
{modifyText(4);}
void MainWindow::b5()
{modifyText(5);}
void MainWindow::b6()
{modifyText(6);}
void MainWindow::b7()
{modifyText(7);}
void MainWindow::b8()
{modifyText(8);}
void MainWindow::b9()
{modifyText(9);}

//按钮组函数（自己修改）一共十个按钮，函数参数是标题的序号
void MainWindow::modifyText(int ord)
{

}
//菜单制作
void MainWindow::creatAction()
{
    add=new QAction("Add",this);
    connect(add,SIGNAL(triggered()),this,SLOT(menu_add()));

    exit=new QAction("Exit",this);
    connect(exit,SIGNAL(triggered()),this,SLOT(menu_exit()));

    undo=new QAction("Undo",this);
    connect(undo,SIGNAL(triggered()),this,SLOT(menu_undo()));

    find=new QAction("Find",this);
    connect(find,SIGNAL(triggered()),this,SLOT(menu_find()));

    select_all=new QAction("Select all",this);
    connect(select_all,SIGNAL(triggered()),this,SLOT(menu_selectAll()));

    max_windows=new QAction("Max windows",this);
    connect(max_windows,SIGNAL(triggered()),this,SLOT(menu_maxWindows()));

    min_windows=new QAction("Min windows",this);
    connect(min_windows,SIGNAL(triggered()),this,SLOT(menu_minWindows()));
}

void MainWindow::creatMenu()
{
    file=menuBar()->addMenu("File");
    file->addAction(add);
    file->addAction(exit);

    edit=menuBar()->addMenu("Edit");
    edit->addAction(undo);
    edit->addAction(find);
    edit->addAction(select_all);

    windows=menuBar()->addMenu("Windows");
    windows->addAction(max_windows);
    windows->addAction(min_windows);
}

//标题组制作
void MainWindow::creatTopic()
{
    //这里修改标题组的文件存储，要求为txt文件，一行一个标题
    QString filename="in.txt";
    QFile *topicfile=new QFile;
    topicfile->open(QIODevice::ReadOnly|QIODevice::Text);
    QString temp;
    for(int i=0;i<10;i++)
    {
        topic[i]=new QPushButton(this);
        temp=topicfile->readLine();
        topic[i]->setText(temp);
        topic[i]->setGeometry(0,50*i+30,200,50);
        switch (i)
        {
            case 0:
                connect(topic[i],SIGNAL(clicked()),this,SLOT(c0()));
                break;
            case 1:
                connect(topic[i],SIGNAL(clicked()),this,SLOT(c1()));
                break;
            case 2:
                connect(topic[i],SIGNAL(clicked()),this,SLOT(c2()));
                break;
            case 3:
                connect(topic[i],SIGNAL(clicked()),this,SLOT(c3()));
                break;
            case 4:
                connect(topic[i],SIGNAL(clicked()),this,SLOT(c4()));
                break;
            case 5:
                connect(topic[i],SIGNAL(clicked()),this,SLOT(c5()));
                break;
            case 6:
                connect(topic[i],SIGNAL(clicked()),this,SLOT(c6()));
                break;
            case 7:
                connect(topic[i],SIGNAL(clicked()),this,SLOT(c7()));
                break;
            case 8:
                connect(topic[i],SIGNAL(clicked()),this,SLOT(c8()));
                break;
            case 9:
                connect(topic[i],SIGNAL(clicked()),this,SLOT(c9()));
                break;
        }
    }
}

//按钮组制作
void MainWindow::creatButton()
{
    //这里修改按钮组的文件存储，要求为txt文件，一行一个标题
    QString filename="in.txt";
    QFile *buttonfile=new QFile;
    buttonfile->open(QIODevice::ReadOnly|QIODevice::Text);
    QString temp;
    for(int i=0;i<10;i++)
    {
        button[i]=new QPushButton(this);
        temp=buttonfile->readLine();
        button[i]->setText(temp);
        button[i]->setGeometry(800,50*i+30,200,50);
        switch (i)
        {
            case 0:
                connect(button[i],SIGNAL(clicked()),this,SLOT(b0()));
                break;
            case 1:
                connect(button[i],SIGNAL(clicked()),this,SLOT(b1()));
                break;
            case 2:
                connect(button[i],SIGNAL(clicked()),this,SLOT(b2()));
                break;
            case 3:
                connect(button[i],SIGNAL(clicked()),this,SLOT(b3()));
                break;
            case 4:
                connect(button[i],SIGNAL(clicked()),this,SLOT(b4()));
                break;
            case 5:
                connect(button[i],SIGNAL(clicked()),this,SLOT(b5()));
                break;
            case 6:
                connect(button[i],SIGNAL(clicked()),this,SLOT(b6()));
                break;
            case 7:
                connect(button[i],SIGNAL(clicked()),this,SLOT(b7()));
                break;
            case 8:
                connect(button[i],SIGNAL(clicked()),this,SLOT(b8()));
                break;
            case 9:
                connect(button[i],SIGNAL(clicked()),this,SLOT(b9()));
                break;
        }
    }
}

//LED制作
void MainWindow::creatLED()
{
    LED=new QTextEdit(this);
    LED->setGeometry(200,30,600,300);
}
//关键词制作
void MainWindow::creatKey()
{
     //这里修改关键词的文件存储，要求为txt文件，第一行为一个数值，为关键词个数
    //剩下的每行一个关键词
    QString filename="in.txt";
    QFile *keyfile=new QFile;
    keyfile->open(QIODevice::ReadOnly|QIODevice::Text);
    QString temp;
    QString kn=keyfile->readLine();
    if(kn=="3")knn=3;
    if(kn=="4")knn=4;
    if(kn=="5")knn=5;
    for(int i=0;i<knn;i++)
    {
        key[i]=new QLabel(this);
        temp=keyfile->readLine();
        key[i]->setText(temp);
    }
    switch (knn)
    {
        case 3:
            key[0]->setGeometry(300,350,50,20);
            key[1]->setGeometry(500,350,50,20);
            key[2]->setGeometry(400,450,50,20);
            break;
        case 4:
            key[0]->setGeometry(300,350,50,20);
            key[1]->setGeometry(500,350,50,20);
            key[2]->setGeometry(300,450,50,20);
            key[3]->setGeometry(500,450,50,20);
            break;
        case 5:
            key[0]->setGeometry(400,340,50,20);
            key[1]->setGeometry(270,400,50,20);
            key[2]->setGeometry(530,400,50,20);
            key[3]->setGeometry(300,480,50,20);
            key[4]->setGeometry(500,480,50,20);
            break;
    }
}
