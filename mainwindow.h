#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //might delete next 2 lines if not valid
public slots:
    void openFile(const QString &fileName);
    //

private slots:
   // void on_pushButton_4_clicked();

    void on_Open_Button_clicked();

    void on_Convert_Button_clicked();

    void on_Save_Button_clicked();

    void on_Save_As_Button_clicked();


    void on_New_Button_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
