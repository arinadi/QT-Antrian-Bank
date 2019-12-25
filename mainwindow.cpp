#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "vector"
#include "QDebug"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    InitTableCS();
    InitTableTELLER();
}

MainWindow::~MainWindow()
{
    delete ui;
}

// tugas untuk UAS :: 5. procedure
void MainWindow::TotalAntrian()
{
    int cs = ui->spinBoxCs->value()-1;
    int teller = ui->spinBoxTeller->value()-1;
    int total = HitungTotalAntrian(cs,teller);
    ui->lcdNumberTotalAntrian->display(total);
}

// tugas untuk UAS :: 5. function
int MainWindow::HitungTotalAntrian(const int &antrian_cs, const int &antrian_teller)
{
    return antrian_cs+antrian_teller;
}

// CS LOGIC //
void MainWindow::InitTableCS()
{
//    ui->tableWidgetCs->clear();
    QStringList th;
    th << "No Antrian" << "Nama";
    ui->tableWidgetCs->setColumnCount(2);
    ui->tableWidgetCs->setHorizontalHeaderLabels(th);
    qDebug() << th;
}

void MainWindow::AddItemTableCS(const QString &nama, const int &no_antrian)
{
    int rc = ui->tableWidgetCs->rowCount();
    int col = 0;
    ui->tableWidgetCs->setRowCount(rc+1);
    ui->tableWidgetCs->setItem(rc, col, new QTableWidgetItem(QString::number(no_antrian)));
    ui->tableWidgetCs->setItem(rc, col+1, new QTableWidgetItem(nama));
//    qDebug() << nama;
//    qDebug() << no_antrian;
}

void MainWindow::ItemTableCS()
{
    int start = DaftarAntrian.LastCS;
    int end = ui->spinBoxCs->value();
    ui->tableWidgetCs->setRowCount(0);
    // tugas untuk UAS :: 3. traversal (for)
    for (int i=start;i<end;i++) {
        AddItemTableCS(DaftarAntrian.CS[i].name,DaftarAntrian.CS[i].no_antrian);
//        qDebug() << DaftarAntrian.CS[i].name;
//        qDebug() << DaftarAntrian.CS[i].no_antrian;
    }
    TotalAntrian();
}


void MainWindow::on_pushButtonAntriCs_clicked()
{
    int no = ui->spinBoxCs->value();
    QString nama = ui->lineEditCs->text();
    // tugas untuk UAS :: 1. penyeleksian kondisi (if)
    if(nama.length() > 0){
        DaftarAntrian.CS[no].name = nama;
        DaftarAntrian.CS[no].no_antrian= no;
        ui->spinBoxCs->setValue(no+1);
        ui->lineEditCs->clear();
    }
//    qDebug() << DaftarAntrian.CS[no].name;
//    qDebug() << DaftarAntrian.CS[no].no_antrian;
    ItemTableCS();
}

void MainWindow::on_pushButtonLanjutCs1_clicked()
{
    int no = DaftarAntrian.LastCS;
    QString name = DaftarAntrian.CS[no].name;
    if(name.length()>0){
//        qDebug() << name;
//        qDebug() << no;
        ui->labelNameCs1->setText(name);
        ui->lcdNumberCs1->display(no);
        DaftarAntrian.LastCS++;
        ItemTableCS();
    } else {
        ui->labelNameCs1->setText(TextSetting.habis);
        ui->lcdNumberCs1->display("-");
    }
}

void MainWindow::on_pushButtonLanjutCs2_clicked()
{
    int no = DaftarAntrian.LastCS;
    QString name = DaftarAntrian.CS[no].name;
    if(name.length()>0){
//        qDebug() << name;
//        qDebug() << no;
        ui->labelNameCs2->setText(name);
        ui->lcdNumberCs2->display(no);
        DaftarAntrian.LastCS++;
        ItemTableCS();
    } else {
        ui->labelNameCs2->setText(TextSetting.habis);
        ui->lcdNumberCs2->display("-");
    }
}

void MainWindow::on_pushButtonLanjutCs3_clicked()
{
    int no = DaftarAntrian.LastCS;
    QString name = DaftarAntrian.CS[no].name;
    if(name.length()>0){
//        qDebug() << name;
//        qDebug() << no;
        ui->labelNameCs3->setText(name);
        ui->lcdNumberCs3->display(no);
        DaftarAntrian.LastCS++;
        ItemTableCS();
    } else {
        ui->labelNameCs3->setText(TextSetting.habis);
        ui->lcdNumberCs3->display("-");
    }
}

void MainWindow::on_pushButtonIstirahatCs1_clicked()
{
    ui->labelNameCs1->setText(TextSetting.istirahat);
    ui->lcdNumberCs1->display("-");
}

void MainWindow::on_pushButtonIstirahatCs2_clicked()
{
    ui->labelNameCs2->setText(TextSetting.istirahat);
    ui->lcdNumberCs2->display("-");
}

void MainWindow::on_pushButtonIstirahatCs3_clicked()
{
    ui->labelNameCs3->setText(TextSetting.istirahat);
    ui->lcdNumberCs3->display("-");
}



// TELLER LOGIC //
void MainWindow::InitTableTELLER()
{
//    ui->tableWidgetTeller->clear();
    QStringList th;
    th << "No Antrian" << "Nama";
    ui->tableWidgetTeller->setColumnCount(2);
    ui->tableWidgetTeller->setHorizontalHeaderLabels(th);
    qDebug() << th;
}

void MainWindow::AddItemTableTELLER(const QString &nama, const int &no_antrian)
{
    int rc = ui->tableWidgetTeller->rowCount();
    int col = 0;
    ui->tableWidgetTeller->setRowCount(rc+1);
    ui->tableWidgetTeller->setItem(rc, col, new QTableWidgetItem(QString::number(no_antrian)));
    ui->tableWidgetTeller->setItem(rc, col+1, new QTableWidgetItem(nama));
//    qDebug() << nama;
//    qDebug() << no_antrian;
}

void MainWindow::ItemTableTELLER()
{
    int start = DaftarAntrian.LastTELLER;
    int end = ui->spinBoxTeller->value();
    ui->tableWidgetTeller->setRowCount(0);
    int i=start;
    // tugas untuk UAS :: 2. perulangan ( while,repeat)
    while (i<end) {
        AddItemTableTELLER(DaftarAntrian.TELLER[i].name,DaftarAntrian.TELLER[i].no_antrian);
//        qDebug() << DaftarAntrian.TELLER[i].name;
//        qDebug() << DaftarAntrian.TELLER[i].no_antrian;
        i++;
    }
    TotalAntrian();
}


void MainWindow::on_pushButtonAntriTeller_clicked()
{
    int no = ui->spinBoxTeller->value();
    QString nama = ui->lineEditTeller->text();
    if(nama.length() > 0){
        DaftarAntrian.TELLER[no].name = nama;
        DaftarAntrian.TELLER[no].no_antrian= no;
        ui->spinBoxTeller->setValue(no+1);
        ui->lineEditTeller->clear();
    }
//    qDebug() << DaftarAntrian.TELLER[no].name;
//    qDebug() << DaftarAntrian.TELLER[no].no_antrian;
    ItemTableTELLER();
}

void MainWindow::on_pushButtonLanjutTeller1_clicked()
{
    int no = DaftarAntrian.LastTELLER;
    QString name = DaftarAntrian.TELLER[no].name;
    if(name.length()>0){
//        qDebug() << name;
//        qDebug() << no;
        ui->labelNameTeller1->setText(name);
        ui->lcdNumberTeller1->display(no);
        DaftarAntrian.LastTELLER++;
        ItemTableTELLER();
    } else {
        ui->labelNameTeller1->setText(TextSetting.habis);
        ui->lcdNumberTeller1->display("-");
    }
}

void MainWindow::on_pushButtonLanjutTeller2_clicked()
{
    int no = DaftarAntrian.LastTELLER;
    QString name = DaftarAntrian.TELLER[no].name;
    if(name.length()>0){
//        qDebug() << name;
//        qDebug() << no;
        ui->labelNameTeller2->setText(name);
        ui->lcdNumberTeller2->display(no);
        DaftarAntrian.LastTELLER++;
        ItemTableTELLER();
    } else {
        ui->labelNameTeller2->setText(TextSetting.habis);
        ui->lcdNumberTeller2->display("-");
    }
}

void MainWindow::on_pushButtonIstirahatTeller1_clicked()
{
    ui->labelNameTeller1->setText(TextSetting.istirahat);
    ui->lcdNumberTeller1->display("-");
}

void MainWindow::on_pushButtonIstirahatTeller2_clicked()
{
    ui->labelNameTeller2->setText(TextSetting.istirahat);
    ui->lcdNumberTeller2->display("-");
}
