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
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void on_calcBtn_clicked();

    void on_loadFile_triggered();

    void on_saveFile_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
