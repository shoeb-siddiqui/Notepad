#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->centralWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{
    file_path = "";
    ui->textEdit->setText("");

}

void MainWindow::on_actionOpen_triggered()
{
    QString file_name = QFileDialog::getOpenFileName(this,"Open the file");
    QFile file(file_name);
    file_path=file_name;

    if(!file.open(QFile::ReadOnly  | QFile::Text)){
        QMessageBox::warning(this,"title","file not opened");
        return;
    }
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();



}

void MainWindow::on_actionSave_triggered()
{

    QFile file(file_path);

    if(!file.open(QFile::WriteOnly  | QFile::Text)){
        QMessageBox::warning(this,"title","file not opened");
        return;
    }
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();

    out<<text;
    file.flush();
    file.close();


}

void MainWindow::on_actionSave_as_triggered()
{
    QString file_name = QFileDialog::getSaveFileName(this,"Open the file");
    QFile file(file_name);
    file_path = file_name;

    if(!file.open(QFile::WriteOnly  | QFile::Text)){
        QMessageBox::warning(this,"title","file not opened");
        return;
    }
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    //    ui->textEdit->setText(text);
    out<<text;
    file.flush();
    file.close();

}

void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();

}

void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();

}

void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();

}

void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();

}

void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();

}

void MainWindow::on_actionNotepad_triggered()
{
    QString about_text;    // creating some text
    about_text ="Auther : somebody\n";
    about_text = "Date : 12/05/2016";
    about_text += "(c) Notepad (R)";
    QMessageBox::about(this,"Notepad",about_text);

}

void MainWindow::on_actionFont_triggered()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok , this);
    if(ok){
        ui->textEdit->setFont(font);

    }else return;




}

void MainWindow::on_actionColor_triggered()
{
    QColor color = QColorDialog::getColor(Qt::white,this,"Choose a color");
    if(color.isValid()){
        ui->textEdit->setTextColor(color);

    }

}

void MainWindow::on_actionBackground_Color_triggered()
{
    QColor color = QColorDialog::getColor(Qt::white,this,"Choose a color");
    if(color.isValid()){
        ui->textEdit->setTextBackgroundColor(color);

    }

}

void MainWindow::on_actionBackgroundcolor_textedit_triggered()
{
    QColor color = QColorDialog::getColor(Qt::white,this,"Choose a color");
    if(color.isValid()){
        ui->textEdit->setPalette(QPalette(color));

    }

}

void MainWindow::on_actionPrint_triggered()
{
    QPrinter printer ;
    printer.setPrinterName("Dezired printer");
    QPrintDialog dialog(&printer ,this);
    if(dialog.exec() == QDialog::Rejected) return;
    ui->textEdit->print(&printer);

}
