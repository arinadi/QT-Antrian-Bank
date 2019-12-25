#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QString"

// tugas untuk UAS :: 6. structure(record)/type data bentukan
struct DetailPengantri{
    QString name;
    int no_antrian;
};
struct {
    int LastCS = 1;
    // tugas untuk UAS :: 4. array
    DetailPengantri CS[99];
    int LastTELLER = 1;
    DetailPengantri TELLER[99];
} DaftarAntrian;

struct {
    QString habis = "[ Antrian Habis ]";
    QString istirahat = "[ Istirahat ]";
} TextSetting;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    // tugas untuk UAS :: 5. procedure
    void TotalAntrian();
    // tugas untuk UAS :: 5. function
    int HitungTotalAntrian(const int& antrian_cs, const int& antrian_teller);
    //CS Table
    void InitTableCS();
    void AddItemTableCS(const QString& nama, const int& no_antrian);
    void ItemTableCS();
    //CS Table
    void InitTableTELLER();
    void AddItemTableTELLER(const QString& nama, const int& no_antrian);
    void ItemTableTELLER();

private slots:
    //CS Form
    void on_pushButtonAntriCs_clicked();

    //CS Lanjut
    void on_pushButtonLanjutCs1_clicked();
    void on_pushButtonLanjutCs2_clicked();
    void on_pushButtonLanjutCs3_clicked();

    //CS Istirahat
    void on_pushButtonIstirahatCs1_clicked();
    void on_pushButtonIstirahatCs2_clicked();
    void on_pushButtonIstirahatCs3_clicked();

    //Teller Form
    void on_pushButtonAntriTeller_clicked();

    //Teller Lanjut
    void on_pushButtonLanjutTeller1_clicked();
    void on_pushButtonLanjutTeller2_clicked();

    //Teller Istirahat
    void on_pushButtonIstirahatTeller1_clicked();
    void on_pushButtonIstirahatTeller2_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
