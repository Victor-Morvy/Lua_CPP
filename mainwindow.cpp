#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    lua_misc.luaStart();

    ui->label->setText("Resultado !!!!!");

    timer = new QTimer(this);

    connect(timer, &QTimer::timeout, this, QOverload<>::of(&MainWindow::fixedUpdate));

    timer->start(100);

    w_list = ui->listWidget;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateList()
{
    w_list->clear();
    std::map<std::string, std::string>* sm = LuaScriptParser::getHandle()->getStrMap();

    QStringList qsl;

    for(auto lp: *sm)
    {
        std::string sName = lp.first;
        std::string sValue = lp.second;
        QString str = QString(sName.c_str()) + "\t : \t" + QString(sValue.c_str());
        qsl.push_back(str);
    }

    w_list->addItems(qsl);



}

void MainWindow::fixedUpdate()
{
    updateList();

//    w_list->clear();

//    w_list->addItem("Fodase");

//    QStringList strList;

//    strList.push_back("Caralho");
//    strList.push_back("puta");
//    strList.push_back("Ihu");

//    w_list->addItems(strList);
}

int MainWindow::lua_GetString(lua_State *L)
{
    std::string shareName = (std::string(lua_tostring(L, 1)));

    try {
        std::string name = LuaScriptParser::getHandle()->getStrMap()->at(shareName);
        lua_pushstring(L, name.c_str());

    }  catch (...) {
        std::cout << "There no exist any value in " + shareName << std::endl;
    }

    return 1;
}

int MainWindow::lua_SetString(lua_State *L)
{
    std::string shareName = std::string(lua_tostring(L, 1));
    std::string txtValue = std::string(lua_tostring(L, 2));

    LuaScriptParser::getHandle()->setShare(shareName, txtValue);

    return 1;
}


void MainWindow::on_playCodeBtn_clicked()
{
//    lua_misc.playScript("/home/victor/Documentos/LuaPlusQt/luaPlusQt/luatestQt.lua");
    lua_State *L = luaL_newstate();
    luaL_openlibs(L);
    lua_register(L, "GetString", lua_GetString);
    lua_register(L, "SetString", lua_SetString);

    if(luaL_dofile(L, "/home/victor/Documentos/LuaPlusQt/luaPlusQt/luatestQt.lua"))
    {

    }

}


void MainWindow::on_setValBtn_clicked()
{
    std::string shareName = ui->smn->text().toStdString();
    std::string strValue = ui->inptxt->text().toStdString();

    LuaScriptParser::getHandle()->setShare(shareName, strValue);

    ui->label->setText("Valor setado.");
}


void MainWindow::on_getValBtn_clicked()
{
    std::string shareName = ui->smn->text().toStdString();

    std::string strValue = LuaScriptParser::getHandle()->getShare(shareName);

    if(strValue != "")
        ui->label->setText(strValue.c_str());
    else
        ui->label->setText("Não existe!");

//    if(shareName == "string.Test.1")
//        ui->label->setText(QString(lua_misc.getString().c_str()));
//    else if(shareName == "string.Test.2")
//        ui->label->setText(QString(LuaMisc::stringTest2.c_str()));
//    else if(shareName == "string.Test.3")
//        ui->label->setText(QString(LuaMisc::stringTest3.c_str()));
//    else if(shareName == "string.Test.4")
//        ui->label->setText(QString(LuaMisc::stringTest4.c_str()));
//    else
//        ui->label->setText("Error!!! non existe");
}


void MainWindow::on_resetBtn_clicked()
{
    LuaScriptParser::getHandle()->clearMap();
    ui->smn->clear();
    ui->inptxt->clear();
}


void MainWindow::on_updtBtn_clicked()
{
    updateList();
}

