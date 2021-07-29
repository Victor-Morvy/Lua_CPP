#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QTimer>
#include <QListWidget>
#include <QString>

#include "luascriptparser.h"

extern "C"
{
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void fixedUpdate();
//    static int lua_GetString(lua_State *L);
//    static int lua_SetString(lua_State *L);
    std::string getString(std::string shareMem);
    void setString(std::string shareMem, std::string msg);

    static int lua_GetString(lua_State* L);
    static int lua_SetString(lua_State* L);

    void updateList();


    QTimer* timer;
    lua_State *L;
    QListWidget* w_list;
private slots:
    void on_playCodeBtn_clicked();

    void on_setValBtn_clicked();

    void on_getValBtn_clicked();

    void on_resetBtn_clicked();

    void on_updtBtn_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
