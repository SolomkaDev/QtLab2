#include "Camera_Catalogy.h"
#include <QtWidgets/QApplication>
#include "Info_Storage.h"

Camera_Catalogy::Camera_Catalogy(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    
    //Подключение кнопок
    connect(ui.pushButton_SaveInfo1, SIGNAL(clicked()), this, SLOT(slot_save1()));
    connect(ui.pushButton_SaveInfo2, SIGNAL(clicked()), this, SLOT(slot_save2()));
    connect(ui.pushButton_ShowInfo1, SIGNAL(clicked()), this, SLOT(slot_show1()));
    connect(ui.pushButton_ShowInfo2, SIGNAL(clicked()), this, SLOT(slot_show2()));
    //Подключение чекбоксов
    connect(ui.checkBox_LensOptions, SIGNAL(stateChanged(int)), this, SLOT(slot_LensOptions()));
    connect(ui.checkBox_IsDigital, SIGNAL(stateChanged(int)), this, SLOT(slot_IsDigital()));
    //Подключение выпадающих списков
    connect(ui.comboBox_Category, SIGNAL(activated(int)), this, SLOT(slot_ChooseCategory()));
    connect(ui.comboBox_Producer, SIGNAL(activated(int)), this, SLOT(slot_ChooseProducer()));

    //Подключение валидатора для первой строки ввода
    QRegExp regExp("[A-Za-z][A-Za-z0-9]+");
    

    //Параметры по умолчанию
    ui.lineEdit_ModelName->setValidator(new QRegExpValidator(regExp));
    ui.lineEdit_ModelName->setText("No more then 30 symbols");
    ui.comboBox_Category->setCurrentIndex(0);
    ui.comboBox_Producer->setCurrentIndex(0);
    ui.doubleSpinBox_CamMatrix->setValue(10.0); //при запуске программы этот пункт не будет видимым, так как камера по умолчанию не цифровая
    ui.lineEdit_Dimensions->setInputMask("00-00-00");
    ui.spinBox_Weight->setValue(30);
    ui.spinBox_Price->setValue(50000);
    //ui.dateEdit->setDate(QDate(2017, 12, 1));
    ui.dateEdit->setDate(QDate::currentDate());
    //Параметры видимости
    ui.checkBox_IsDigital->setChecked(false); //По умолчанию камера будет не цифровой
    ui.checkBox_LensOptions->setChecked(false);
   

    //Условия видимости

    //Условия видимости для чекбокса "Возможности смена объектива"
    if (ui.comboBox_Category->currentIndex() == 2) {
        ui.checkBox_LensOptions->setEnabled(true);
    }
    else {
        ui.checkBox_LensOptions->setEnabled(false);
    }
    //Условие видимости для даблспинбокса
    if (ui.checkBox_IsDigital->isChecked()) {
        ui.doubleSpinBox_CamMatrix->setEnabled(true);
        ui.label_4->setEnabled(true);
    }
    else {
        ui.doubleSpinBox_CamMatrix->setEnabled(false);
        ui.label_4->setEnabled(false);
    }
   

    //Сведения о первом фотоапарате
    Items[0].modul = "KKLg";
    Items[0].category_value = 1;
    Items[0].producer_value = 3;
    Items[0].matrix_px = 10.5;
    Items[0].dimension = "30-30-30";
    Items[0].weight = 300;
    Items[0].price = 15000;
    Items[0].date_release = QDate(2012, 5, 17);
    Items[0].IsDigital = false;
    Items[0].LensOption = false;

    //Сведения о втором фотоапарате
    Items[1].modul = "Jlksg";
    Items[1].category_value = 2;
    Items[1].producer_value = 4;
    Items[1].matrix_px = 17.4;
    Items[1].dimension = "50-20-30";
    Items[1].weight = 300;
    Items[1].price = 15000;
    Items[1].date_release = QDate(2015, 3, 27);
    Items[1].IsDigital = true;
    Items[1].LensOption = true;
    
}

void Camera_Catalogy::slot_save1()
{
    //Считывание текущих записей
    QString Current_Module = ui.lineEdit_ModelName->text();
    int Current_Category = ui.comboBox_Category->currentIndex();
    int Current_Producer = ui.comboBox_Category->currentIndex();
    double Current_PX = ui.doubleSpinBox_CamMatrix->value();
    QString Current_Dimension = ui.lineEdit_Dimensions->text();
    int Current_Weight = ui.spinBox_Weight->value();
    int Current_Price = ui.spinBox_Price->value();
    QDate Current_Date = ui.dateEdit->date();
    bool Current_IsD = ui.checkBox_IsDigital->checkState();
    bool Current_LensOP = ui.checkBox_LensOptions->checkState();
    
    //Присваивание новых значений в первый слот
    Items[0].modul = Current_Module;
    Items[0].category_value = Current_Category;
    Items[0].producer_value = Current_Producer;
    Items[0].matrix_px = Current_PX;
    Items[0].dimension = Current_Dimension;
    Items[0].weight = Current_Weight;
    Items[0].price = Current_Price;
    Items[0].date_release = Current_Date;
    Items[0].IsDigital = Current_IsD;
    Items[0].LensOption = Current_LensOP;


}

void Camera_Catalogy::slot_save2()
{
    //Считывание текущих записей
    QString Current_Module = ui.lineEdit_ModelName->text();
    int Current_Category = ui.comboBox_Category->currentIndex();
    int Current_Producer = ui.comboBox_Category->currentIndex();
    double Current_PX = ui.doubleSpinBox_CamMatrix->value();
    QString Current_Dimension = ui.lineEdit_Dimensions->text();
    int Current_Weight = ui.spinBox_Weight->value();
    int Current_Price = ui.spinBox_Price->value();
    QDate Current_Date = ui.dateEdit->date();
    bool Current_IsD = ui.checkBox_IsDigital->checkState();
    bool Current_LensOP = ui.checkBox_LensOptions->checkState();

    //Присваивание новых значений во второй слот
    Items[1].modul = Current_Module;
    Items[1].category_value = Current_Category;
    Items[1].producer_value = Current_Producer;
    Items[1].matrix_px = Current_PX;
    Items[1].dimension = Current_Dimension;
    Items[1].weight = Current_Weight;
    Items[1].price = Current_Price;
    Items[1].date_release = Current_Date;
    Items[1].IsDigital = Current_IsD;
    Items[1].LensOption = Current_LensOP;


}



void Camera_Catalogy::slot_show1()
{
    //ui.lineEdit_ModelName->setClearButtonEnabled(true);
    

    ui.lineEdit_ModelName->clear();
    ui.lineEdit_Dimensions->clear();

    ui.lineEdit_ModelName->setText(QString(Items[0].modul));
    ui.comboBox_Category->setCurrentIndex(Items[0].category_value);
    ui.comboBox_Producer->setCurrentIndex(Items[0].producer_value);
    ui.doubleSpinBox_CamMatrix->setValue(Items[0].matrix_px);
    ui.lineEdit_Dimensions->setText(QString(Items[0].dimension));
    ui.spinBox_Weight->setValue(Items[0].weight);
    ui.spinBox_Price->setValue(Items[0].price);
    ui.dateEdit->setDate(Items[0].date_release);
    ui.checkBox_IsDigital->setChecked(Items[0].IsDigital);
    ui.checkBox_LensOptions->setChecked(Items[0].LensOption);

    //Условия видимости для чекбокса "Возможности смена объектива"
    int index = Items[0].category_value;

    if (index == 2) {
        ui.checkBox_LensOptions->setEnabled(true);
    }
    else {
        ui.checkBox_LensOptions->setEnabled(false);
    }

    //Условие видимости для даблспинбокса
    if (ui.checkBox_IsDigital->isChecked()) {
        ui.doubleSpinBox_CamMatrix->setEnabled(true);
        ui.label_4->setEnabled(true);
    }
    else {
        ui.doubleSpinBox_CamMatrix->setEnabled(false);
        ui.label_4->setEnabled(false);
    }
    

}

void Camera_Catalogy::slot_show2()
{
    ui.lineEdit_ModelName->clear();
    ui.lineEdit_Dimensions->clear();

    ui.lineEdit_ModelName->setText(QString(Items[1].modul));
    ui.comboBox_Category->setCurrentIndex(Items[1].category_value);
    ui.comboBox_Producer->setCurrentIndex(Items[1].producer_value);
    ui.doubleSpinBox_CamMatrix->setValue(Items[1].matrix_px);
    ui.lineEdit_Dimensions->setText(QString(Items[1].dimension));
    ui.spinBox_Weight->setValue(Items[1].weight);
    ui.spinBox_Price->setValue(Items[1].price);
    ui.dateEdit->setDate(Items[1].date_release);
    ui.checkBox_IsDigital->setChecked(Items[1].IsDigital);
    ui.checkBox_LensOptions->setChecked(Items[1].LensOption);

    //Условия видимости для чекбокса "Возможности смена объектива"
    int index = Items[1].category_value;

    if (index == 2) {
        ui.checkBox_LensOptions->setEnabled(true);
    }
    else {
        ui.checkBox_LensOptions->setEnabled(false);
    }

    //Условие видимости для даблспинбокса
    if (ui.checkBox_IsDigital->isChecked()) {
        ui.doubleSpinBox_CamMatrix->setEnabled(true);
        ui.label_4->setEnabled(true);
    }
    else {
        ui.doubleSpinBox_CamMatrix->setEnabled(false);
        ui.label_4->setEnabled(false);
    }
}

void Camera_Catalogy::slot_LensOptions()
{
    //Оно для галочки существует
}

void Camera_Catalogy::slot_IsDigital()
{
    if (ui.checkBox_IsDigital->isChecked()) {
        ui.doubleSpinBox_CamMatrix->setEnabled(true);
        ui.label_4->setEnabled(true);
    }
    else {
        ui.doubleSpinBox_CamMatrix->setEnabled(false);
        ui.label_4->setEnabled(false);
    }
}

void Camera_Catalogy::slot_ChooseCategory()
{
    //Условия видимости для чекбокса "Возможности смена объектива"

    int index = ui.comboBox_Category->currentIndex();

    if (index == 2) {
        ui.checkBox_LensOptions->setEnabled(true);
    }
    else {
        ui.checkBox_LensOptions->setEnabled(false);
    }
}

void Camera_Catalogy::slot_ChooseProducer()
{
}


