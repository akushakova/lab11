#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QDir>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_calcBtn_clicked()
{
    bool ok;
    int seconds = ui->secValue->text().toInt(&ok);
    if (!ok) {
        QMessageBox::warning(0,",Помилка","Не вдалося зчитати число секунд");
        return;
    }
    if (seconds < 0) {
        QMessageBox::warning(0,",Помилка","Кількість секунд не може бути менша за 0");
        return;
    }
    int minutesTotal = seconds / 60;
    int minutesRemainder = minutesTotal % 60;
    ui->minValue->setText(QString::number(minutesRemainder));
}
void MainWindow::on_loadFile_triggered()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Відкрити файл",
                                                    QDir::currentPath(), "Текстові файли (*.txt);;Усі файли (*)");
    if (!filePath.isEmpty()) {
        QFile file(filePath);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QMessageBox::warning(0, "Error", "Не вдалося відкрити файл");
        }
        else {
            QTextStream in(&file);
            QString sec, min;
            in >> sec >> min;
            ui->secValue->setText(sec);
            ui->minValue->setText(min);
            file.close();
        }
    }
    else {
        QMessageBox::warning(0, "Error", "Файл не знайдено");
    }
}


void MainWindow::on_saveFile_triggered()
{
    QString filePath = QFileDialog::getSaveFileName(this, "Зберегти файл",
                                                    QDir::currentPath(), "Текстові файли (*.txt);;Усі файли (*)");
    if (!filePath.isEmpty()) {
        QFile file(filePath);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QMessageBox::critical(nullptr, "Помилка",
                                  "Не вдалося відкрити файл:\n" + file.errorString());
        }
        else {
            QTextStream out(&file);
            out << ui->secValue->text() << "\n";
            out << ui->minValue->text() << "\n";
            file.close();
        }
    }
    else {
        QMessageBox::warning(0, "Помилка", "Файл не знайдено");
    }
}

