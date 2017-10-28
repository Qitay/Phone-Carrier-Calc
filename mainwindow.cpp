#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QfileDialog>
#include <QTextStream>
#include <QMessageBox>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::WyswietlanieOferty(daneofert &x)
{
    QString LinkNazwa;

    //Pozycja1
    LinkNazwa = "<a href=\"" + x.lista.at(0)->website + "\">" + x.lista.at(0)->nazwa + "</a>";
    ui->label_31->setText(x.lista.at(0)->siec);
    ui->label_28->setText(LinkNazwa);
    ui->label_29->setText(QString::number(x.lista.at(0)->CenaSuma,'a',2)+ " zł");
    if(ui->doubleSpinBox_12->value() != 0)
    {
        ui->label_33->setText(QString::number(ui->doubleSpinBox_12->value() - x.lista.at(0)->CenaSuma,'a',2)+ " zł");
    }
    //ui->textBrowser_2->setText(x.lista.at(0)->opis);

    //Pozycja 2
    LinkNazwa = "<a href=\"" + x.lista.at(1)->website + "\">" + x.lista.at(1)->nazwa + "</a>";
    ui->label_74->setText(x.lista.at(1)->siec);
    ui->label_78->setText(LinkNazwa);
    ui->label_76->setText(QString::number(x.lista.at(1)->CenaSuma,'a',2)+ " zł");
    if(ui->doubleSpinBox_12->value() != 0)
    {
        ui->label_77->setText(QString::number(ui->doubleSpinBox_12->value() - x.lista.at(1)->CenaSuma,'a',2)+ " zł");
    }
    //ui->textBrowser_3->setText(x.lista.at(1)->opis);

    //Pozycja 3
    LinkNazwa = "<a href=\"" + x.lista.at(2)->website + "\">" + x.lista.at(2)->nazwa + "</a>";
    ui->label_56->setText(x.lista.at(2)->siec);
    ui->label_60->setText(LinkNazwa);
    ui->label_58->setText(QString::number(x.lista.at(2)->CenaSuma,'a',2)+ " zł");
    if(ui->doubleSpinBox_12->value() != 0)
    {
        ui->label_59->setText(QString::number(ui->doubleSpinBox_12->value() - x.lista.at(2)->CenaSuma,'a',2)+ " zł");
    }
    //ui->textBrowser_4->setText(x.lista.at(2)->opis);

    //Pozycja 4
    LinkNazwa = "<a href=\"" + x.lista.at(3)->website + "\">" + x.lista.at(3)->nazwa + "</a>";
    ui->label_36->setText(x.lista.at(3)->siec);
    ui->label_40->setText(LinkNazwa);
    ui->label_38->setText(QString::number(x.lista.at(3)->CenaSuma,'a',2)+ " zł");
    if(ui->doubleSpinBox_12->value() != 0)
    {
        ui->label_39->setText(QString::number(ui->doubleSpinBox_12->value() - x.lista.at(3)->CenaSuma,'a',2) + " zł");
    }
    //ui->textBrowser_5->setText(x.lista.at(3)->opis);

    //Pozycja 5
    LinkNazwa = "<a href=\"" + x.lista.at(4)->website + "\">" + x.lista.at(4)->nazwa + "</a>";
    ui->label_47->setText(x.lista.at(4)->siec);
    ui->label_51->setText(LinkNazwa);
    ui->label_49->setText(QString::number(x.lista.at(4)->CenaSuma,'a',2)+ " zł");
    if(ui->doubleSpinBox_12->value() != 0)
    {
        ui->label_50->setText(QString::number(ui->doubleSpinBox_12->value() - x.lista.at(4)->CenaSuma,'a',2)+ " zł");
    }
    //ui->textBrowser_6->setText(x.lista.at(4)->opis);




}

void MainWindow::WyswietlanieDanych(danewejsciowe &Input)
{
    ui->doubleSpinBox_5->setValue(Input.iloscSms);
    ui->doubleSpinBox->setValue(Input.iloscSms_Tmobile);
    ui->doubleSpinBox_2->setValue(Input.iloscSms_Orange);
    ui->doubleSpinBox_3->setValue(Input.iloscSms_Play);
    ui->doubleSpinBox_4->setValue(Input.iloscSms_Plus);
    ui->doubleSpinBox_14->setValue(Input.iloscSms_Zagraniczne);
    ui->doubleSpinBox_13->setValue(Input.iloscMms);

    ui->doubleSpinBox_6->setValue(Input.iloscInternetu);

    ui->doubleSpinBox_7->setValue(Input.iloscMinut);
    ui->doubleSpinBox_8->setValue(Input.iloscMinut_Tmobile);
    ui->doubleSpinBox_9->setValue(Input.iloscMinut_Orange);
    ui->doubleSpinBox_10->setValue(Input.iloscMinut_Play);
    ui->doubleSpinBox_11->setValue(Input.iloscMinut_Plus);
    ui->doubleSpinBox_15->setValue(Input.iloscMinut_Zagraniczne);
    ui->doubleSpinBox_16->setValue(Input.iloscMinut_Domowe);

    ui->textBrowser->setText(Input.TekstTaki);
}

void MainWindow::WczytywanieDanych(danewejsciowe &Input)
{
    Input.iloscSms = ui->doubleSpinBox_5->value();
    Input.iloscSms_Tmobile = ui->doubleSpinBox->value();
    Input.iloscSms_Orange = ui->doubleSpinBox_2->value();
    Input.iloscSms_Play = ui->doubleSpinBox_3->value();
    Input.iloscSms_Plus = ui->doubleSpinBox_4->value();
    Input.iloscSms_Zagraniczne = ui->doubleSpinBox_14->value();
    Input.iloscMms = ui->doubleSpinBox_13->value();

    Input.iloscInternetu = ui->doubleSpinBox_6->value();

    Input.iloscMinut = ui->doubleSpinBox_7->value();
    Input.iloscMinut_Tmobile = ui->doubleSpinBox_8->value();
    Input.iloscMinut_Orange = ui->doubleSpinBox_9->value();
    Input.iloscMinut_Play = ui->doubleSpinBox_10->value();
    Input.iloscMinut_Plus = ui->doubleSpinBox_11->value();
    Input.iloscMinut_Zagraniczne = ui->doubleSpinBox_15->value();
    Input.iloscMinut_Domowe = ui->doubleSpinBox_16->value();
}

//Button od wczytywania oferty
void MainWindow::on_pushButton_clicked()
{

    QString filename = QFileDialog::getOpenFileName(
                this,tr("Wybierz Plik"),
                "C://","Plik tekstowy (*.txt);;Wszystkie pliki (*.*)");

    if (!filename.isEmpty())
    {
        Input.reset();
        if (ui->comboBox->findText(filename) == -1)
            ui->comboBox->addItem(filename);
        ui->comboBox->setCurrentIndex(ui->comboBox->findText(filename));
        Input.odczytPliku(filename);

        WyswietlanieDanych(Input);
    }
}

//Przełączanie nazw otwartych plików
void MainWindow::on_comboBox_activated(const QString &arg1)
{
    QString filename = arg1;
    if (!filename.isEmpty())
    {
        Input.reset();
        if (ui->comboBox->findText(filename) == -1)
        {
            ui->comboBox->addItem(filename);
        }
        ui->comboBox->setCurrentIndex(ui->comboBox->findText(filename));
        Input.odczytPliku(filename);
        WyswietlanieDanych(Input);
    }
}

//funcja do sortowania
bool Mniejsze(const oferta *s1, const oferta *s2)
 {
     return s1->CenaSuma < s2->CenaSuma;
 }

//Po kliknieciu przelicz:
void MainWindow::on_pushButton_2_clicked()
{
    WczytywanieDanych(Input);
    daneofert Oferty;
    Oferty.parseXML();

    for(int i=0; i<Oferty.lista.size();i++)
    {
        Oferty.lista.at(i)->ObliczSume(Input);
    }


    qSort(Oferty.lista.begin(),Oferty.lista.end(), Mniejsze);

    for(int i=0; i<Oferty.lista.size();i++)
    {
        qDebug() << Oferty.lista.at(i)->nazwa;
        qDebug() << Oferty.lista.at(i)->ObliczSume(Input);
    }

    WyswietlanieOferty(Oferty);

    if (Input.iloscMinut_Zagraniczne >0 || Input.iloscSms_Zagraniczne > 0)
    {
        QMessageBox msgBox;
          msgBox.addButton(QMessageBox::Ok);
          msgBox.setText("W twoim billingu znajdują się połączenia międzynarodowe. W tej chwili program nie obsługuje takich połączeń, więc są one liczone jak zwykłe połączenia do sieci zewnętrznych.\n\nPrzedstawione ceny mogą być inne niż w rzeczywistości.");
          msgBox.exec();
    }

    ui->tabWidget->setCurrentIndex(2);

}
